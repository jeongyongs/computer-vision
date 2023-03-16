#include <opencv2/opencv.hpp>

using namespace cv;

void main() {
	VideoCapture camera(0);
	QRCodeDetector qr;
	Mat frame, qrimg;
	std::string data;
	std::vector<Point> bbox;

	while (true) {
		camera >> frame;
		data = qr.detectAndDecode(frame, bbox, qrimg);

		// Detected
		if (data.length() > 0) {
			putText(frame, data, bbox[0], FONT_HERSHEY_PLAIN, 2, Scalar(255, 0, 0), 2);
			line(frame, bbox[0], bbox[1], Scalar(0, 255, 0), 2);
			line(frame, bbox[1], bbox[2], Scalar(0, 255, 0), 2);
			line(frame, bbox[2], bbox[3], Scalar(0, 255, 0), 2);
			line(frame, bbox[3], bbox[4], Scalar(0, 255, 0), 2);

			imshow("qrimg", qrimg);
		}

		imshow("frame", frame);
		waitKey(1);
	}
}