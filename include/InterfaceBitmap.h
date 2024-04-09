#ifndef INTERFACEBITMAP_H
#define INTERFACEBITMAP_H

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <Windows.h>


class InterfaceBitmap
{

    protected:
        unsigned int                    width_;
        unsigned int                    height_;
        unsigned int                    bytes_per_pixel_;
        unsigned int                    row_increment_;
        std::vector<unsigned char>      data_;
        std::string                     file_name_;
        
    public:
        
        virtual unsigned int get_width(void)const = 0;
        virtual unsigned int get_height(void)const = 0;
        virtual unsigned int get_bytes_per_pixel(void)const = 0;
        // virtual unsigned int get_size_of_data(void)const = 0;

        virtual void draw(HDC hdc,POINT origine)const=0;
        virtual void clear(void)=0;
       
    protected:


        // virtual unsigned int get_size_bfh(void)const = 0;
        // virtual unsigned int get_size_bih(void)const = 0;

};

#endif // BITMAP_H
