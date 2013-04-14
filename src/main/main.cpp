#include <cv.h>
#include <highgui.h>
#include <iostream>

#include "detect_Utils.h"
#include "camCapt.h"
#include "image.h"

/*
Detect light segment on picture.  
*/

int main( int argc, char* argv[] )
{  
    CamCapt camera;
    Changes change(4, 4);
    cvNamedWindow("original",CV_WINDOW_AUTOSIZE);

    IplImage * img;
    IplImage * imgCh = 0;
    Ker lightKernel;
    CvScalar color = CV_RGB(200, 4, 4);
    while(true)
    {
        img = camera.TakeImage();
        imgCh = cvCloneImage(img);
        change.Erode(img, imgCh);
        lightKernel = find_Ker(imgCh, BLUE, 100);
        print_rect(imgCh, &lightKernel, &color);
        cvShowImage("original",imgCh);
        char c = cvWaitKey(33); // Ждём
        if(c == 27) break; // Если Esc - выходим
    }
    cvReleaseImage(&img);
    cvReleaseImage(&imgCh);
    return 0;
}