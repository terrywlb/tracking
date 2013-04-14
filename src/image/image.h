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

class ThresholdingOp
{
public:
	ThresholdingOp();
	~ThresholdingOp();

	void Threshold(IplImage * from, IplImage * to);

private:
	int max_BINARY_value;// = 255
	int threshold_value;// = 0;
	int threshold_type;// = 3;
/* 	 0: Binary
     1: Binary Inverted
     2: Threshold Truncated
     3: Threshold to Zero
     4: Threshold to Zero Inverted
*/
	int max_value;// = 255;
	int max_type;// = 4;
};