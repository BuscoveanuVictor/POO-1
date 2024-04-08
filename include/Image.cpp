#include <iostream>
#include <Windows.h>
#include "Image.h"


Image::Image(std::string FileName)
{
     
    FILE* pFile = fopen(&FileName[0],"rb");
    std::vector<unsigned char> buffer_;


    if(pFile == NULL)
    {
        std::cout << "A aparut o eroare la incarcarea fisierului " << file_name_ << std::endl;
        delete this; return;
    }
   
    /**citeste datele pentru header File
    //============================================================
    **/

    fseek(pFile,0,SEEK_SET);

    fread(&Bfh.TypeOfFile, sizeof(unsigned short), 1, pFile);

    fread (&Bfh.LengthOfFile, sizeof(unsigned int), 1, pFile);
    
    fseek(pFile,10,SEEK_SET);

    fread (&Bfh.OffsetBMP, sizeof(unsigned int), 1, pFile);
  
    /**citeste datele pentru header Info
    //============================================================
    **/

    fseek(pFile,14,SEEK_SET);

    fread (&Bih.SizeOfHeader , sizeof(unsigned int) , 1 , pFile);

    fread(&Bih.Width, sizeof(unsigned int),1 , pFile);
    width_ = Bih.Width;
   
    fread (&Bih.Height,sizeof(unsigned int), 1 , pFile);
    height_ = Bih.Height;

    fread (&Bih.NoOfPlanes, sizeof(unsigned short), 1 , pFile);

    fread (&Bih.NoOfBitsPerPixel, sizeof(unsigned short), 1 , pFile);
    bytes_per_pixel_ = Bih.NoOfBitsPerPixel/8;

    row_increment_ = width_ * bytes_per_pixel_;

    buffer_.reserve(row_increment_ * height_+1);

    // pozitionezi pointerul fisierului unde incepe imaginea(pixelii)
    fseek (pFile , Bfh.OffsetBMP , SEEK_SET );

    fread(&buffer_[0], sizeof(unsigned char), (Bfh.LengthOfFile-Bfh.OffsetBMP), pFile);

    if (ferror(pFile)) {std::cout << "Imaginea nu a fost copiata in memorie!\n" ; delete this; return;}

    /// Incarcand data cu push_back, ordinea introducerii culorii va fi B G R (RGB invers)
    /// de aceea la afisare ordinea va fi B, G, R
    for(int y=1; y<=height_; y++){
        for(int x=0; x<width_; x++){
            data_.push_back(buffer_[(height_-y)*row_increment_+bytes_per_pixel_*x]);
            data_.push_back(buffer_[(height_-y)*row_increment_+bytes_per_pixel_*x+1]);
            data_.push_back(buffer_[(height_-y)*row_increment_+bytes_per_pixel_*x+2]);
            if (bytes_per_pixel_==3) buffer_.push_back(0xff);
            else
               data_.push_back(buffer_[(height_-y)*row_increment_+bytes_per_pixel_*x+3]);
        }
    }

    fclose(pFile);

}

Image::Image(const Image& other)
{
    Bfh = other.Bfh;
    Bih = other.Bih;

    width_ = other.width_;
    height_ = other.height_;
    row_increment_ = other.row_increment_;
    bytes_per_pixel_ = other.bytes_per_pixel_;
    data_ = other.data_;
}


Image& Image::operator=(const Image& other)
{
    if(other <= *this)
    {
        Bfh = other.Bfh;
        Bih = other.Bih;
        (*this).Bitmap::operator=(other);
    }else std::cout<<"Imaginea atribuita este prea mare!";

    return *this;
}

HDC operator<<(const HDC hdc, const Image& img)
{
    img.draw({0,0},hdc);
    return hdc;
}




// Bitmap* Image::convert_to_grayscale(void)const
// {
//         unsigned char cTag[4];
//         int shift = (bytes_per_pixel_==4)?(1):(0);
//         int unsigned media;

//         //Image auxImage(*this);

//         cTag[0]=0; //Dump (daca bytes per pixel este 3)

//         for(int i=0; i<width_*height_; i++){
//             for(int j=shift; j<bytes_per_pixel_; j++)
//                 cTag[j] = data_[j+i*bytes_per_pixel_];
        
//             media=static_cast<unsigned char>
//             (static_cast<int>(cTag[0]+cTag[1]+cTag[2]+cTag[3])/bytes_per_pixel_);

//             for(int j=shift; j<bytes_per_pixel_; j++)
//                // auxImage.data_[j+i*bytes_per_pixel_]=media;
//         }

//         //return &auxImage;
// }


