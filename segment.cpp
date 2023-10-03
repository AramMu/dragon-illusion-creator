#include "segment.h"
#include "calc.h"

Segment::Segment() {}

Segment::Segment(const cv::Point& p1, const cv::Point& p2) :
    p1(p1), p2(p2)
{
    assert (p1 != p2);
}
Segment::Segment(const Segment& s) :
    p1(s.p1), p2(s.p2)
{}


void Segment::extendEnd(double length) {
    assert (p1 != p2);
    double rad = Calc::distance(p1,p2);
    double xDif = (p2.x - p1.x)/rad * length;
    double yDif = (p2.y - p1.y)/rad * length;
    p2.x += xDif;
    p2.y += yDif;
}

void Segment::extendBegin(double length) {
    std::swap(p1, p2);
    extendEnd (length);
    std::swap(p1, p2);
}

double Segment::angle() const {
    double ang = std::atan2(p2.y-p1.y, p2.x-p1.x);
    if (ang < 0) {
        ang += 6.283;
    }
    return ang;
}

bool Segment::CompAngle::operator () (const Segment& s1, const Segment& s2) const {
    double ang1 = s1.angle();
    double ang2 = s2.angle();
    return ang1 < ang2;
}

