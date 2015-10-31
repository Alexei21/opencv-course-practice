//opencv
/*#include <cv.h>
#include <highgui.h>
#include <ml.h>
#include <cxcore.h>
#include <types_c.h>
#include <opencv2/legacy/legacy.hpp>*/

#include "lab1.h"

#  pragma comment(lib, "opencv_core2410d.lib")
#  pragma comment(lib, "opencv_highgui2410d.lib")
#  pragma comment(lib, "opencv_imgproc2410d.lib")
#  pragma comment(lib, "opencv_video2410d.lib")
#  pragma comment(lib, "opencv_ml2410d.lib")

#  pragma comment(lib, "opencv_calib3d2410d.lib")
#  pragma comment(lib, "opencv_objdetect2410d.lib")
#  pragma comment(lib, "opencv_features2d2410d.lib")
#  pragma comment(lib, "opencv_contrib2410d.lib")
#  pragma comment(lib, "opencv_ts2410d.lib")
#  pragma comment(lib, "opencv_legacy2410d.lib")
#  pragma comment(lib, "opencv_flann2410d.lib")
#  pragma comment(lib, "opencv_gpu2410d.lib")

using namespace cv; 

int main()
{
    pipeline_lab1();
    return 0;
}