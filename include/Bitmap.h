#ifndef BITMAP_H
#define BITMAP_H

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <Windows.h>
#include "InterfaceBitmap.h"


class Bitmap:public InterfaceBitmap
{

    public:
        Bitmap();
        Bitmap(int width, int height);
        Bitmap(const Bitmap &other);

        bool operator<=(const Bitmap &other)const;
        Bitmap& operator=(const Bitmap &other);

        
        //Bitmap(int width, int height, unsigned color);
      

        void draw(POINT origine, HDC hdc)const;
        // void clear(void);
        unsigned int get_width(void)const;
        unsigned int get_height(void)const;
        unsigned int get_bytes_per_pixel(void)const;
        unsigned int get_size_of_data(void)const;

};

#endif // BITMAP_H
