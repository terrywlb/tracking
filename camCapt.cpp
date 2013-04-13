#include "camCapt.h"

CamCapt::CamCapt()
{
	camID = 0;
	capt = cvCreateCameraCapture(camID);
}

CamCapt::~CamCapt()
{
	cvReleaseImage(capt);
	RealeseAllImages();
}

IplImage * CamCapt::ResieveImageFromCam()
{
	return cvCreateCameraCapture(camID);
}

void CamCapt::RealeseAllImages()
{
	cvReleaseImage(&image);
	for (int i = 0; i < copyArray.size; ++i)
		cvReleaseImage(&copyArray[i]);
}

IplImage * CamCapt::TakeImage()
{
	RealeseAllImages();
	IplImage = cvQueryFrame(capt);
}

IplImage * CamCapt::TakeCopyImage();
{
	// appand at the end of array
	copyArray[] = cvCloneImage(image);
}