#include "utility.h"

void Utility::cutLines (const cv::Mat& mask, const cv::Mat& input, cv::Mat& output) {
    assert (mask.size() == input.size() && input.size() == output.size());
    assert (mask.type() == CV_8UC1 && input.type() == CV_8UC3 && output.type() == CV_8UC3);
    for (int i = 0; i < mask.rows; ++i) {
        for (int j = 0; j < mask.cols; ++j) {
            if (mask.at<uchar>(i,j) == 0) {
                output.at<cv::Vec3b> (i, j) = input.at<cv::Vec3b>(i,j);
            }
        }
    }
}

std::vector <std::vector <cv::Point> > Utility::getSegments (
        const cv::Mat& mask, const std::vector<Segment>& segmentsInput, const cv::Point& center)
{
    for (int i = 0; i < segmentsInput.size(); ++i) {
        assert (segmentsInput[i].p1 == center);
    }

    std::vector<Segment> segments = segmentsInput;
    std::sort (segments.begin(), segments.end(), Segment::CompAngle());
    std::vector <std::vector <cv::Point> > res(segments.size());
    std::vector <double> angles(segments.size());
    for (int i = 0; i < angles.size(); ++i) {
        angles[i] = segments[i].angle();
    }
    for (int i = 0; i < mask.rows; ++i) {
        for (int j = 0; j < mask.cols; ++j) {
            if (cv::Point(j,i) == center) continue;
            if (!mask.at<uchar>(i,j)) continue;

            double ang = Segment(center, cv::Point(j,i)).angle();
            if (ang < angles[0] || ang > angles.back()) {
                res.back().push_back(cv::Point(j,i));
                continue;
            }
            for (int k = 0; k < angles.size()-1; ++k) {
                if (ang > angles[k] && ang < angles[k+1]) {
                    res[k].push_back (cv::Point(j,i));
                    break;
                }
            }
        }
    }
    return res;
}
