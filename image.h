#pragma once
#include <cv.h>
// tools for works with image

class Changes
{
public:
	Changes(int rad, int s);
	~Changes();

	void Erode(IplImage * from, IplImage * to);
	void Dilate(IplImage * from, IplImage * to);
private:
	IplConvKernel* ker;
	int radius;
	int size;
};
