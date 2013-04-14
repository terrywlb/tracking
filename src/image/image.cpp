#include "image.h"

/*
Changes
*/
Changes::Changes(int rad, int s)
{
	radius = rad;
	size = s;
	ker = cvCreateStructuringElementEx(radius*2+1, radius*2+1, radius, radius, CV_SHAPE_ELLIPSE);
}

Changes::~Changes()
{
	cvReleaseStructuringElement(&ker);
}

void Changes::Erode(IplImage * from, IplImage * to)
{
	cvErode(from, to, ker, size);
}

void Changes::Dilate(IplImage * from, IplImage * to)
{
	cvDilate(from, to, ker, size);
}


/*
	ThresholdingOp
*/

	