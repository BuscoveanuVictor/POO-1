#ifndef BITMAP_H
#define BITMAP_H

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <Windows.h>
#include "InterfaceBitmap.h"

/*
    Bitmap - asa cum sugereaza si numele este un map de biti    
    NU ESTE o poza/imagine, in sensul ca, nu exista in "memoria userului" (nu este salvat sau incarcata)
    spre deosebire de clasa image, care face referire la un obiect din memorie
*/


class Bitmap:public InterfaceBitmap
{
    public:
        Bitmap();
        Bitmap(int width, int height, COLORREF color=0x00);
        Bitmap(const Bitmap& other);

        bool operator<=(const Bitmap& other)const;
        bool operator==(const Bitmap& other)const;
        Bitmap& operator=(const Bitmap& other);

        void draw(HDC hdc, POINT origine={0,0})const;
        void clear(void);

        bool is_empty(void)const;
        unsigned int get_width(void)const;
        unsigned int get_height(void)const;
        unsigned int get_bytes_per_pixel(void)const;
        unsigned int get_size_of_data(void)const;

};




#endif // BITMAP_H
