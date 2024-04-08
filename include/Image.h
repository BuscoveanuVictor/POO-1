#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <Windows.h>
#include "Bitmap.h"


class Image:public Bitmap
{

    public:
        Image(std::string FileName);
        Image(const Image& other);

        Image& operator=(const Image& other);

        Bitmap* convert_to_grayscale(void)const;

        friend HDC operator<<(const HDC hdc, const Image& img);
    private:
        
        unsigned int get_size_bfh(void)const;
        unsigned int get_size_bih(void)const;
        
        struct FileHeader{
            unsigned short      TypeOfFile;
            unsigned int        LengthOfFile;
            unsigned short      Reserved1;
            unsigned short      Reserved2;
            unsigned int        OffsetBMP;

            unsigned int struct_size() const
            {
                    return sizeof(TypeOfFile   ) +
                        sizeof(LengthOfFile ) +
                        sizeof(Reserved1    ) +
                        sizeof(Reserved2    ) +
                        sizeof(OffsetBMP    ) ;
            }

            FileHeader& operator=(const FileHeader& other)
            {
                TypeOfFile = other.TypeOfFile;
                LengthOfFile = other.LengthOfFile;
                Reserved1 = other.Reserved1;
                Reserved2 = other.Reserved2;
                OffsetBMP = other.OffsetBMP;

                return *this;
            }


        }Bfh; 


        struct InfoHeader{
            unsigned int        SizeOfHeader;
            unsigned int        Width;
            unsigned int        Height;
            unsigned short      NoOfPlanes;
            unsigned short      NoOfBitsPerPixel;

            unsigned int struct_size() const
            {
                    return sizeof(SizeOfHeader     ) +
                        sizeof(Width            ) +
                        sizeof(Height           ) +
                        sizeof(NoOfPlanes       ) +
                        sizeof(NoOfBitsPerPixel ) ;
            }
            InfoHeader& operator=(const InfoHeader& other)
            {
                SizeOfHeader = other.SizeOfHeader;
                Width = other.Width;
                Height = other.Height;
                NoOfBitsPerPixel = other.NoOfBitsPerPixel;
                NoOfPlanes = other.NoOfPlanes;
                return *this;
            }

        }Bih; 

};

#endif // IMAGE_H
