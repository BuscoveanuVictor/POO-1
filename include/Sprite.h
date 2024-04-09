#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>
#include <Windows.h>
#include "Image.h"
#include "BitmapTools.h"


class Sprite:public Image, public BitmapTools
{   
    protected:
        void loadAuxVector(void);

    public:
     
        void undo(void);
        void save_changes(void);
        void rotateImage(void);
        void mirrorImage(void);
        void resizeImage(void);

};

#endif // SPRITE_H
