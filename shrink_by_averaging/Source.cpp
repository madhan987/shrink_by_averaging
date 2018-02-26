
//shrink the image by averaging pixels
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
	//Reading an image
	Mat image = imread("C:\\Users\\HP\\Pictures\\Download\\p3.png");

	Mat grey_image(image.rows, image.cols, CV_8UC1);

	Mat shrink_image1(image.rows/2, image.cols/2, CV_8UC3);

	Mat shrink_image2(image.rows / 2, image.cols / 2, CV_8UC1);

	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols;j++)
		{
			grey_image.at<uchar>(i, j) = (image.at<Vec3b>(i, j)[0] + image.at<Vec3b>(i, j)[1] + image.at<Vec3b>(i, j)[2]) / 3;
		}
	}



	int l = 0, m = 0;

	for (int i = 0;i < (image.rows-1);i+=2)
	{
		m = 0;
		for (int j = 0;j < (image.cols-1);j+=2)
		{
				shrink_image1.at<Vec3b>(l, m) = ((image.at<Vec3b>(i, j) + image.at<Vec3b>(i + 1, j))/2 + (image.at<Vec3b>(i, j+1) + image.at<Vec3b>(i+1, j+1)) / 2)/2;
				m++;
		}
		l++;
	}
	l = 0;
	for (int i = 0;i < (image.rows - 1);i+=2)
	
	{
		m = 0;
		for (int j = 0;j < (image.cols - 1);j+=2)
		{
			shrink_image2.at<uchar>(l, m) = ((grey_image.at<uchar>(i, j) + grey_image.at<uchar>(i + 1, j)) / 2 + (grey_image.at<uchar>(i, j + 1)) / 2) / 2;
			m++;
		}
		l++;
	}

	cout << image.cols << ":" << image.rows << endl;
	imshow("1", image);
	imshow("2", grey_image);
	imshow("3", shrink_image1);
	imshow("4", shrink_image2);
	waitKey(0);
	return 1;
}