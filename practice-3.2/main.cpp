#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

const string dataPath = "../data/Practice3/3-2/";
const string queryFileName = "query.jpg";
vector<string> targetFileNames = {};

Mat calcHist(Mat& input) {
	Mat output(1, 256, CV_32F, Scalar(0));

	for (int i = 0; i < input.rows; i++) {
		for (int j = 0; j < input.cols; j++) {
			output.at<float>(input.at<unsigned char>(i, j))++;
		}
	}
	output = output / (input.rows * input.cols); // <---> output /= input.total();

	return output;
}

double calcDistance(Mat& query, Mat& target) { // same dimension
	double distance = 0.0;

	for (int i = 0; i < query.cols; i++) {
		distance += (query.at<float>(i) - target.at<float>(i))*(query.at<float>(i) - target.at<float>(i));
	}

	return distance;
}

void main() {
	Mat queryImg = imread(dataPath + queryFileName, IMREAD_GRAYSCALE);
	Mat queryVector = calcHist(queryImg);

	for (int i = 1; i <= 50; i++) {
		targetFileNames.push_back(to_string(i));
	}

	for (int i = 0; i < targetFileNames.size(); i++) {
		Mat targetImg = imread(dataPath + targetFileNames[i] + ".jpg", IMREAD_GRAYSCALE);
		Mat targetVector = calcHist(targetImg);

		cout << fixed;
		cout.precision(20);
		cout << i+1 << ".jpg - " << calcDistance(queryVector, targetVector) << endl;
	}
}
