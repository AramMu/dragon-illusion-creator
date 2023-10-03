#ifndef SEGMENT_H
#define SEGMENT_H
#include <opencv2/imgproc.hpp>

class Segment {
public:
    Segment();
    Segment(const cv::Point& p1, const cv::Point& p2);
    Segment(const Segment& s);
    void extendEnd(double length);
    void extendBegin(double length);
    double angle() const;
    class CompAngle {
    public:
        bool operator () (const Segment& s1, const Segment& s2) const;
    };

//private:
    cv::Point p1;
    cv::Point p2;
};

#endif // SEGMENT_H
