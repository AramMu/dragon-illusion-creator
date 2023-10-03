#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "edgedetector.h"
#include "segment.h"
#include "utility.h"
using namespace std;

const cv::Vec3b lineColor(255,255,255);
const cv::Vec3b centerColor(0,0,255);

cv::Point center(-1,-1);
std::vector <cv::Point> endPoints;
std::vector <Segment> segments;
cv::Mat resultImg;

void addPointCallback (int event, int x, int y, int, void*) {
    if (event != CV_EVENT_LBUTTONDOWN) return;
    //std::cout << "Callback called" << std::endl;
    if (center.x<0) {
        center = cv::Point(x,y);
        cv::circle(resultImg, center, 4, centerColor, -1);
        //std::cout << "Center called" << std::endl;
        cv::imshow("Input", resultImg);
        return;
    }
    if (center == cv::Point(x,y)) return;
    Segment s(center, cv::Point(x,y));
    s.extendEnd(1000);
    segments.push_back(s);
    cv::line (resultImg, s.p1, s.p2, lineColor, 2);
    cv::circle (resultImg, center, 4, centerColor, -1);
    cv::imshow("Input", resultImg);
}


int main() {
    resultImg = cv::imread("Data/input.png");
    cv::Mat input = resultImg.clone();
    cv::namedWindow("Input");
    const cv::Vec3b white(255,255,255);
    const cv::Vec3b red(0,0,255);
    /*
    Segment s(cv::Point (114,75), cv::Point(96, 273));
    cv::line(input, s.p1, s.p2, red, 5);
    s.extendBegin(200);
    cv::line(input, s.p1, s.p2, white, 1);
    cv::imshow("Input", input);
    */
    cv::imshow("Input",resultImg);
    cv::setMouseCallback("Input", &addPointCallback);
    /*
    while (true) {
        int key = cv::waitKey(0);
        switch (key) {
        case 'e':
            break;
        }
    }
    */
    cv::waitKey(0);
    cv::Mat mask = cv::imread("Data/mask.png", cv::IMREAD_GRAYSCALE);
    Utility::cutLines(mask, input, resultImg);
    std::vector <std::vector <cv::Point> > res = Utility::getSegments(mask, segments, center);
    cv::Mat output (mask.size(), CV_8UC3);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            output.at<cv::Vec3b> (res[i][j]) = cv::Vec3b((i+1)*50, (i+1)*50, (i+1)*50);
        }
    }
    cv::imshow("Input", resultImg);
    cv::imshow("Output",output);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}

