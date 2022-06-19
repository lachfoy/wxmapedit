#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include <wx/wx.h>

class ImageLoader
{
public:
    static wxImage loadImage(const char* path);
};

#endif