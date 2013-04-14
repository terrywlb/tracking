#include "detect_Utils.h"
#include <iostream>

bool colorFunc(int red, int green, int blue, COLOR clr, int clrVal)
{
    switch (clr)
    {
        case RED : if (red >= clrVal) return true;
        case GREEN : if (green >= clrVal) return true;
        case BLUE : if (blue >= clrVal) return true; 
    }
    return false;
}

// Version 1.0 - very simple. One light
Ker find_Ker(const IplImage * img, COLOR clr, int colorVal)
{

	Ker res;
    int xL, xH, y, i, tmp;
    xH = img->width;
    uchar* line;
    bool flag;

    flag = false;
    for (y = 0; y < img->height; ++y)
    {
        if(flag) break;
        line = (uchar*) (img->imageData + y * img->widthStep);
        for (xL = 0; xL < img->width; ++xL)
        {
            if(colorFunc(line[3 * xL + 2], line[3 * xL + 1], line[3 * xL + 0], clr, colorVal))
            {
                flag = true;
                break;
            }
            if(flag) break;
        }
    }
    res.yL = y;
    res.yH = y;
    res.xL = xL;
    res.xH = xL;

    while(++y < img->height)
    {
        line = (uchar*) (img->imageData + y * img->widthStep);
        flag = false;
        while(!(xL > xH))
        {
            if(!colorFunc(line[3 * xL + 2], line[3 * xL + 1], line[3 * xL + 0], clr, colorVal)) {xL++; flag = true;}
            if(!colorFunc(line[3 * xH + 2], line[3 * xH + 1], line[3 * xH + 0], clr, colorVal)) {xH--; flag = true;}
            if (!flag) break;
            else flag = false;
        }
        if(xL > xH) break;

        while((xL > 0) && colorFunc(line[3 * xL + 2], line[3 * xL + 1], line[3 * xL + 0], clr, colorVal))
            xL--;
        res.xL = (res.xL > xL)?xL:res.xL;

        while((xH < img->width) && colorFunc(line[3 * xH + 2], line[3 * xH + 1], line[3 * xH + 0], clr, colorVal))
            xH++;
        res.xH = (res.xH < xH)?xL:res.xL;

        res.yH = y;
    }
    return res;
}

void print_rect(IplImage * img, const Rect * rectangle, const CvScalar * lineClr)
{
    CvPoint points[] = {cvPoint(rectangle->xL, rectangle->yL), 
                        cvPoint(rectangle->xL, rectangle->yH), 
                        cvPoint(rectangle->xH, rectangle->yH), 
                        cvPoint(rectangle->xH, rectangle->yL)};
    cvLine( img, points[0], points[1], *lineClr, 1, 8);
    cvLine( img, points[1], points[2], *lineClr, 1, 8);
    cvLine( img, points[2], points[3], *lineClr, 1, 8);
    cvLine( img, points[3], points[0], *lineClr, 1, 8);
}