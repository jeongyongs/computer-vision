#include <opencv2/opencv.hpp>

using namespace cv;

void main() {
	Mat win = imread("../data/practice1/windows.jpg");
	Mat ryan = imread("../data/practice1/ryan.bmp");
	Mat bit(ryan.size(), CV_8U, Scalar(255));
	Mat roi = win(Rect(100, 100, ryan.cols, ryan.rows));
	Mat gray, mask;

	cvtColor(ryan, gray, COLOR_BGR2GRAY);
	bitwise_xor(bit, gray, mask);

	ryan.copyTo(roi, mask);

	imshow("win", win);
	imshow("ryan", ryan);
	imshow("bit", bit);
	imshow("gray", gray);
	imshow("mask", mask);

	waitKey();
}