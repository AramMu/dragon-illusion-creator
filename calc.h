#ifndef CALC_H
#define CALC_H
#include <opencv2/imgproc.hpp>


class Calc {
public:
    static double sqr (double x);
    static int sqr (int x);
    static long long sqr (long long x);
    static double distance (const cv::Point& p1, const cv::Point& p2);
private:
    Calc();
    Calc(const Calc&);
    Calc& operator = (const Calc&);
};

inline
double Calc::sqr (double x) {
    return x*x;
}
inline
int Calc::sqr (int x) {
    return x*x;
}
inline
long long Calc::sqr (long long x) {
    return x*x;
}

inline
double Calc::distance (const cv::Point& p1, const cv::Point& p2) {
    return std::sqrt(sqr (p1.x - p2.x) + sqr(p1.y - p2.y));
}


#endif // CALC_H
