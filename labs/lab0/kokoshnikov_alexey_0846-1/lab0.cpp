#include "lab0.h"

using namespace cv;

void pipeline_lab0()
{
    Mat image;
    Mat gray;
    Mat thresholds;
    Mat _thresholds;
    Mat distances;
    //init
    image = imread("C:\\openCV_SC\\road.png", CV_LOAD_IMAGE_COLOR);
    gray = Mat(image.rows, image.cols, CV_8UC1);
    thresholds = Mat(image.rows, image.cols, CV_8UC1);
    _thresholds = Mat(image.rows, image.cols, CV_8UC1);
    distances = Mat(image.rows, image.cols, CV_32F);

    cvNamedWindow("input");
    cvNamedWindow("current");
    
    imshow("input", image);

    //pipeline
    cvtColor(image, gray, CV_RGB2GRAY);
    imshow("current", gray);
    cvWaitKey(0);

    Canny(gray, thresholds, 10, 100);
    imshow("current", thresholds);
    cvWaitKey(0);

    bitwise_not(thresholds, _thresholds);
    imshow("current", _thresholds);
    cvWaitKey(0);

    distanceTransform(_thresholds, distances, CV_DIST_L2, 3);
    normalize(distances, distances, 0, 1., NORM_MINMAX);
    imshow("current", distances);
    cvWaitKey(0);


    //free
    cvDestroyAllWindows();
    return;
}