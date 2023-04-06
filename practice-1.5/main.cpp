#include <opencv2/opencv.hpp>

using namespace cv;

void main() {
	// 데이터 불러오기
	Mat win = imread("../data/practice1/windows.jpg");
	Mat ryan = imread("../data/practice1/ryan.png", IMREAD_UNCHANGED);

	// 라이언 RGBA 채널 분리
	std::vector<Mat> channels;
	split(ryan, channels);

	// 알파채널 분리
	Mat mask = channels[3];

	// 알파채널 제거
	channels.pop_back();

	// 채널 합치기 -> Mat 포멧으로 변경
	Mat color_ryan;
	merge(channels, color_ryan);

	// 복사
	Mat roi = win(Rect(100, 100, ryan.cols, ryan.rows));
	color_ryan.copyTo(roi, mask);

	// 결과 출력
	imshow("win", win);
	waitKey();
}