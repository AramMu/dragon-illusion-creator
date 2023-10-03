#ifndef EDGEDETECTOR_H
#define EDGEDETECTOR_H
#include <opencv2/imgproc.hpp>

class EdgeDetector {
public:
    static void getBoundaries(const cv::Mat& input, cv::Mat& output);
    static void getAllEdges (const cv::Mat& input, cv::Mat& output);

private:
    EdgeDetector();
    EdgeDetector(const EdgeDetector&);
    EdgeDetector& operator = (const EdgeDetector&);
};

#endif // EDGEDETECTOR_H
