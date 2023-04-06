#include <opencv2/opencv.hpp>

using namespace cv;

void main() {
	VideoCapture camera(0), video;
	QRCodeDetector qr;
	Mat cFrame, vFrame, qrimg;
	std::string data;
	std::vector<Point> bbox;

	while (true) {
		camera >> cFrame;
		data = qr.detectAndDecode(cFrame, bbox, qrimg);

		// Detected
		if (data.length() > 0) {

			if (video.isOpened() == false)
				video.open("../data/practice2/" + data);

			video >> vFrame;
			imshow("vFrame", vFrame);

			putText(cFrame, data, bbox[0], FONT_HERSHEY_PLAIN, 2, Scalar(0, 0, 255), 2);
			line(cFrame, bbox[0], bbox[1], Scalar(0, 0, 255), 2);
			line(cFrame, bbox[1], bbox[2], Scalar(0, 0, 255), 2);
			line(cFrame, bbox[2], bbox[3], Scalar(0, 0, 255), 2);
			line(cFrame, bbox[3], bbox[0], Scalar(0, 0, 255), 2);

			imshow("qrimg", qrimg);
		}

		imshow("cFrame", cFrame);
		waitKey(1);
	}
}