#include <iostream>
#include <Windows.h>
#include "Bitmap.h"


unsigned int Bitmap::get_width(void)const           {return width_;}
unsigned int Bitmap::get_height(void)const          {return height_;}
unsigned int Bitmap::get_bytes_per_pixel(void)const {return bytes_per_pixel_;}


Bitmap::Bitmap(void)
{
    width_ = 0;
    height_ = 0;
    row_increment_ = 0;
    bytes_per_pixel_ = 0;
}

Bitmap::Bitmap(int width, int height)
{
    width_ = width;
    height_ = height;
    bytes_per_pixel_ = 3;
    row_increment_ = width_ * bytes_per_pixel_;

    for(int x=0; x<width_*height_*bytes_per_pixel_; x++){
        data_.push_back(0x00);
    }
}

Bitmap::Bitmap(const Bitmap &other)
{
    std::cout << "Constructor copiere";

    for(int y=0;y<other.height_;y++)
        {
            for(int x=0;x<other.width_;x++)
            {
                int coord = y*row_increment_+ x*bytes_per_pixel_;
                int coordOther = y*other.row_increment_ + x*other.bytes_per_pixel_;

                data_[coord] = other.data_[coordOther];
                data_[coord+1] = other.data_[coordOther+1];
                data_[coord+2] = other.data_[coordOther+2];
            }
        }

    width_ = other.width_;
    height_ = other.height_;
    bytes_per_pixel_ = other.bytes_per_pixel_;
    row_increment_ = other.row_increment_;

}


bool Bitmap::operator<=(const Bitmap &other)const
{
     return width_  <= other.width_ &&
            height_ <= other.height_ &&
            bytes_per_pixel_ == other.bytes_per_pixel_;
}

Bitmap& Bitmap::operator=(const Bitmap &other)
{
  
    if(other <= *this)
    {
        for(int y=0;y<other.height_;y++)
        {
            for(int x=0;x<other.width_;x++)
            {
                int coord = y*row_increment_+ x*bytes_per_pixel_;
                int coordOther = y*other.row_increment_ + x*other.bytes_per_pixel_;

                data_[coord] = other.data_[coordOther];
                data_[coord+1] = other.data_[coordOther+1];
                data_[coord+2] = other.data_[coordOther+2];
            }
        }

        width_ = other.width_;
        height_ = other.height_;
        bytes_per_pixel_ = other.bytes_per_pixel_;
        row_increment_ = other.row_increment_;

    }
    else std::cout << "Bitmap-ul atribuit este prea mare!";
         
    return *this;
   
}


void Bitmap::draw(POINT origine, HDC hdc)const
{
    int R, G, B, Dump;
 
    for(int y=0;y<height_;y++)
        for(int x=0;x<width_;x++)
        {
            B = data_[y*row_increment_+bytes_per_pixel_*x];
            G = data_[y*row_increment_+bytes_per_pixel_*x+1];
            R = data_[y*row_increment_+bytes_per_pixel_*x+2];

            SetPixel(hdc, origine.x + x , origine.y + y, RGB(R, G, B));
        }

};


void clear()
{
    ;
}