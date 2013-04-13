#ifndef _DETECT_UTILS_H_
#define _DETECT_UTILS_H_

#include <cv.h>
#include <highgui.h>

enum COLOR = {RED, GREEN, BLUE};

struct Rect
{
	int left_edg, right_edg, top_edg, bot_edg;
	int clr_val;
};

struct Ker : Rect
{
	int size;
	COLOR clr;

};

//find maximum of clr value in img.
Ker find_Ker(const IplImage img, COLOR clr, int size);

#endif