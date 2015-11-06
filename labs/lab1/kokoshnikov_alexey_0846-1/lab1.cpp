#include "lab1.h"

using namespace cv;

void pipeline_lab1()
{
    //matrix
    Mat image;
    Mat gray;
    Mat thresholds;
    Mat thresholds_invert;
    Mat distances;
    Mat mat_of_distances;
    Mat sum[3];
    Mat chanels[3];
    // tmp var
    double avg[3];
    int n;
    int start_rect_i;
    int start_rect_j;
    int end_rect_i;
    int end_rect_j;
    double dist;
    double tmp_top;
    double tmp_but;

    //init
    image = imread("C:\\openCV_SC\\road.png", CV_LOAD_IMAGE_COLOR);
    gray = Mat(image.rows, image.cols, CV_8UC1);
    thresholds = Mat(image.rows, image.cols, CV_8UC1);
    thresholds_invert = Mat(image.rows, image.cols, CV_8UC1);
    distances = Mat(image.rows, image.cols, CV_8UC3);
    mat_of_distances = Mat(image.rows, image.cols, CV_32F);
    sum[0] = Mat(image.rows + 1, image.cols + 1, CV_64F);
    sum[1] = Mat(image.rows + 1, image.cols + 1, CV_64F);
    sum[2] = Mat(image.rows + 1, image.cols + 1, CV_64F);

    namedWindow("input");
    namedWindow("current");
    
    imshow("input", image);

    //pipeline
        cvtColor(image, gray, CV_RGB2GRAY);
        imshow("current", gray);
        waitKey(0);

        Canny(gray, thresholds, 100, 200);
        bitwise_not(thresholds, thresholds_invert);
        imshow("current", thresholds_invert);
        waitKey(0);

        distanceTransform(thresholds_invert, mat_of_distances, CV_DIST_L2, 3);
        imshow("current", mat_of_distances);
        waitKey(0);

        for (int k = 0; k < 3; k++)
        {
            split(image, chanels);
            integral(chanels[k], sum[k], CV_64F);
        }

        for (int i = 0; i < mat_of_distances.rows; i++)
            for (int j = 0; j < mat_of_distances.cols; j++)
            {
                dist = mat_of_distances.at<float>(i, j) / 2;
                start_rect_i = MAX((i - dist), 0);
                start_rect_j = MAX((j - dist), 0);
                end_rect_i = MIN((i + dist), (mat_of_distances.rows - 1));
                end_rect_j = MIN((j + dist), (mat_of_distances.cols - 1));
                n = (end_rect_i - start_rect_i) * (end_rect_j - start_rect_j);
                for (int k = 0; k < 3; k++)
                {
                    if (n != 0)
                    {
                        tmp_top = sum[k].at<double>(start_rect_i, end_rect_j) + sum[k].at<double>(end_rect_i, start_rect_j);
                        tmp_but = sum[k].at<double>(end_rect_i, end_rect_j) + sum[k].at<double>(start_rect_i, start_rect_j);
                        avg[k] = (tmp_but - tmp_top)/n;
                    }
                    else
                    {
                        avg[k] = chanels[k].at<unsigned char>(i, j);
                    }

                    distances.at<Vec3b>(i, j)[k] = avg[k];
                }
            }

        imshow("current", distances);
        waitKey(0);

    //free
    destroyAllWindows();

    return;
}