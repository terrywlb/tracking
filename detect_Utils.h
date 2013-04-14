#pragma once

#include <cv.h>
#include <highgui.h>

enum COLOR {RED, GREEN, BLUE};

struct Rect
{
	int xL, xH, yL, yH;
};

struct Ker : Rect
{
	int size;
	COLOR clr;
	int clr_val;
};

//find maximum of clr value in img.
Ker find_Ker(const IplImage * img, COLOR clr, int colorVal);
bool colorFunc(int red, int green, int blue, COLOR clr, int clrVal);
void print_rect(IplImage * img, const Rect * rectangle, const CvScalar * lineClr);