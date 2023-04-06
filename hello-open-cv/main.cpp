#include <opencv2/opencv.hpp>

using namespace cv;

void main() {
	Mat img = imread("../data/practice1/windows.jpg");
	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	imshow("img", img);
	imshow("gray", gray);
	waitKey();
}