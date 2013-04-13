#pragma once

#include <cv.h>
#include <highgui.h>
#include <vector>

class CamCapt
{
public:
	CamCapt();
	~CamCapt();

	IplImage * TakeImage(); // image from next cams frame
	IplImage * TakeCopyImage(); // reference from copy of current image
	void RetFrame();
private:
	IplImage * ResieveImageFromCam();
	void RealeseAllImages();

	int camID; // index of camera in your PC
	CvCapture * capt;
	IplImage * image
	std::std::vector<IplImage *> copyArray; // all copyes, which resieved from TakeCopyImage
	                                        // each image from this array will be realese after calling TakeImage	
};