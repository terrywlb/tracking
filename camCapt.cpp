#include "camCapt.h"

CamCapt::CamCapt()
{
	camID = 0;
	capture = cvCreateCameraCapture(camID);
	image =  NULL;
}

CamCapt::~CamCapt()
{
	cvReleaseCapture(&capture);
	RealeseAllImages();
}

IplImage * CamCapt::ResieveImageFromCam()
{
	return cvQueryFrame(capture);
}

void CamCapt::RealeseAllImages()
{
	while(!copyArray.empty())
	{
		cvReleaseImage(&(copyArray.top()));
		copyArray.pop();
	}
}

IplImage * CamCapt::TakeImage()
{
	RealeseAllImages();
	return image = ResieveImageFromCam();
}

IplImage * CamCapt::TakeCopyImage()
{
	copyArray.push(cvCloneImage(image));
	return copyArray.top();
}