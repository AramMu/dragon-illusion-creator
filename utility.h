#ifndef UTILITY_H
#define UTILITY_H
#include <opencv2/imgproc.hpp>
#include "segment.h"

class Utility {
public:
    static void cutLines (const cv::Mat& mask, const cv::Mat& input, cv::Mat& output);

    static std::vector <std::vector <cv::Point> > getSegments (const cv::Mat& mask, const std::vector<Segment>& segmentsInput, const cv::Point& center);
private:
    Utility();
    Utility(const Utility&);
    Utility& operator = (const Utility&);
};

#endif // UTILITY_H
