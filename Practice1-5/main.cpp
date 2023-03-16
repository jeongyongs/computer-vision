#include <opencv2/opencv.hpp>

using namespace cv;

void main() {
	// ������ �ҷ�����
	Mat win = imread("../data/windows.jpg");
	Mat ryan = imread("../data/ryan.png", IMREAD_UNCHANGED);

	// ���̾� RGBA ä�� �и�
	std::vector<Mat> channels;
	split(ryan, channels);

	// ����ä�� �и�
	Mat mask = channels[3];

	// ����ä�� ����
	channels.pop_back();

	// ä�� ��ġ�� -> Mat �������� ����
	Mat color_ryan;
	merge(channels, color_ryan);

	// ����
	Mat roi = win(Rect(100, 100, ryan.cols, ryan.rows));
	color_ryan.copyTo(roi, mask);

	// ��� ���
	imshow("win", win);
	waitKey();
}