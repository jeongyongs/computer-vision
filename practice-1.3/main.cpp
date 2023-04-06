#include <opencv2/opencv.hpp>

using namespace cv;

void main() {
	Mat win = imread("../data/practice1/windows.jpg");
	Mat ryan = imread("../data/practice1/ryan.bmp");
	Mat roi = win(Rect(100, 100, ryan.cols, ryan.rows));

	ryan.copyTo(roi);

	imshow("win", win);
	imshow("ryan", ryan);
	imshow("roi", roi);

	waitKey();
}