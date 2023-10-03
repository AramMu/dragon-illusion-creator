#include "edgedetector.h"

/*
int maxDistance (const cv::Mat& input, int y, int x) {
    for (int i = y-1; i <= y+1; ++i) {
        for (int j = x-1; j <= x+1; ++j) {
            if (i < 0 || j < 0 || i >= input.rows || j >= input.cols) {
                continue;
            }
            if (i == y && j == x) {
                continue;
            }
            if (distance (input.at<cv::Vec3b>(i,j), input.at<cv::Vec3b>(y,x)))
        }
    }
}
*/
void EdgeDetector::getBoundaries(const cv::Mat& input, cv::Mat& output) {

}


void EdgeDetector::getAllEdges (const cv::Mat& input, cv::Mat& output) {
    cv::Canny(input, output, 0,1523);
}
