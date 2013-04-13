#include "detect_Utils.h"


// Version 1.0 - very simple. One light
Ker find_Ker(const IplImage img, COLOR clr, int size)
{

	Ker res;
    int x_ = x, i, tmp;
    uchar* line;
    bool flag;
    while(++y < img_cam->height)
    {
        line = (uchar*) (img_cam->imageData + y * img_cam->widthStep);
        flag = false;
        while(!(x > x_))
        {
            if(!predicate(line[3 * x + 0], line[3 * x + 1], line[3 * x + 2])) {x++; flag = true;}
            if(!predicate(line[3 * x_ + 0], line[3 * x_ + 1], line[3 * x_ + 2])) {x_--; flag = true;};
            if (!flag) break;
            else flag = false;
        }
        if(x > x_) break;

        while((x > 0) && predicate(line[3 * x + 0], line[3 * x + 1], line[3 * x + 2]))
            x--;
        if(box.x > x) box.x = x;

        while((x_ < img_cam->width) && predicate(line[3 * x_ + 0], line[3 * x_ + 1], line[3 * x_ + 2]))
            x_++;
        if(box.width < (tmp = x_ - box.x)) box.width = tmp;

        box.height = y - box.y;
    }
}