#include <opencv2/opencv.hpp>

using namespace cv;

void main() {
	Mat img = imread("../data/practice1/windows.jpg");
	Mat gray, small, smallGray;

	cvtColor(img, gray, COLOR_BGR2GRAY);
	resize(img, small, img.size()/2);
	cvtColor(small, smallGray, COLOR_BGR2GRAY);

	imshow("img", img);
	imshow("gray", gray);
	imshow("small", small);
	imshow("smallGray", smallGray);

	waitKey();
}