#ifndef BITMAPTOOLS_H
#define BITMAPTOOLS_H

#include <iostream>
#include <Windows.h>
#include <vector>
#include "Bitmap.h"

/*
    Clasa BitmapTools - este conceputa sa faca modificari asupra mapu-lui de biti 
    INSA NU direct, adica se copiaza ce este in data_ in aux_vector_ si asupra
    acestuia se realizeaza modificari.

    De ce nu facem modificari asupra lui map-ului de biti/data_ intrucat n-am mai putea
    sa revenim la starea initiala a acestuia.

    Fiind o clasa abstracta / interfata in clasa derivata se vor realiza implementariile
    si vom putea folosi si metodele functiei image.
    Prin urmare daca vrem sa salvam modificarile pe care
    le ofera clasa aceasta putem salva imaginea.

*/

class BitmapTools:public Bitmap
{   
    protected:
        std::vector<unsigned int>   aux_vector_;
        virtual void loadAuxVector(void)=0;

    public:
        
        // Image& to_grayscale(void)const;
        // Image& adjust_brightness(void)const;

        virtual void undo(void)=0;
        virtual void save_changes(void)=0;
        virtual void rotateImage(void)=0;
        virtual void mirrorImage(void)=0;
        virtual void resizeImage(void)=0;

};

#endif // BITMAPTOOLS_H
