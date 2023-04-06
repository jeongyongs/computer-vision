#include <opencv2/opencv.hpp>

using namespace cv;

void main() {
	VideoCapture camera(0), video;
	QRCodeDetector qr;
	Mat cFrame, vFrame, wFrame, sMask, wMask, qrimg;
	std::string data;
	std::vector<Point2f> bbox, v_bbox;

	while (true) {
		camera >> cFrame;
		data = qr.detectAndDecode(cFrame, bbox, qrimg);

		// Detected
		if (data.length() > 0) {

			if (video.isOpened() == false) {
				video.open("../data/practice2/" + data);
				double width = video.get(CAP_PROP_FRAME_WIDTH);
				double height = video.get(CAP_PROP_FRAME_HEIGHT);
				v_bbox.push_back(Point2f(0, 0));
				v_bbox.push_back(Point2f(width, 0));
				v_bbox.push_back(Point2f(width, height));
				v_bbox.push_back(Point2f(0, height));
				sMask = Mat(Size(width, height), CV_8U, Scalar(255));
			}
			Mat H = findHomography(v_bbox, bbox);
			video >> vFrame;
			warpPerspective(vFrame, wFrame, H, cFrame.size());
			warpPerspective(sMask, wMask, H, cFrame.size());
			wFrame.copyTo(cFrame, wMask);
		}

		imshow("cFrame", cFrame);
		waitKey(1);
	}
}