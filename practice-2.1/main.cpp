#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

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
			cout << "data: " << data << endl;
			for (int i = 0; i < bbox.size(); i++)
				cout << bbox[i].x << ", " << bbox[i].y << endl;
			imshow("qrimg", qrimg);
		}

		imshow("frame", frame);
		waitKey(1);
	}
}