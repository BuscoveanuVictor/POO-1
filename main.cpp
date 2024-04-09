#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>

#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include "include/Image.h"

// HWND - handler Window 
// HDC  - handler device context 

HWND hImage, hBtn1, hBtn2, hBtn3, Options;


void createControls(HWND hwnd)
{
    hImage = CreateWindow(TEXT("STATIC"), TEXT(""), WS_VISIBLE | WS_CHILD , 20, 20, 200, 200, hwnd, NULL, NULL, NULL);
    hBtn1 = CreateWindow(TEXT("BUTTON"), TEXT("Btn"), WS_VISIBLE | WS_CHILD, 400, 20, 50, 50, hwnd, NULL, NULL, NULL);
    hBtn2 = CreateWindow(TEXT("BUTTON"), TEXT("Btn"), WS_VISIBLE | WS_CHILD, 470, 20, 50, 50, hwnd, NULL, NULL, NULL);
    hBtn3 = CreateWindow(TEXT("BUTTON"), TEXT("Btn"), WS_VISIBLE | WS_CHILD, 540, 20, 50, 50, hwnd, NULL, NULL, NULL);
    //Options = CreateWindow(TEXT("COMBOBOX"), TEXT("Btn"), WS_VISIBLE | WS_CHILD | CBS_DROPDOWN, 540, 80, 50, 50, hwnd, NULL, NULL, NULL);
}

void BitmapWorkPlace(void)
{


}

void ImageWorkPlace(void)
{
    HDC hdc = GetDC(hImage); /// HDC - handle device context
    Image img("D:\\CodeBlocks\\BitmapProject\\images\\aparat_foto.bmp");
    Image img2("D:\\CodeBlocks\\BitmapProject\\images\\atentie.bmp");

    
    hdc << img.to_grayscale();

}

void ToolsWorkPlace(void)
{


}

void workplace()
{


   

   
    

    // Bitmap btm(130,130);

    // btm.draw(hdc);

    //Image img3(150,150);

    // btm.clear();
    // btm = img;
    // // std::cout << btm.get_width();

    // //img2 = img

    // btm.draw(hdc);

    






    //std::cout << (img==img2);

    //img.DrawImage({0,0},hdc);

    //hdc << img3;
    
    //hdc << img2;

    //Image* pImg = img2.convert_to_grayscale();
    //hdc << img2;
      
    //Image img3(img);


}


/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */


    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Code::Blocks Template Windows App"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           800,                 /* The programs width */
           400,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */




LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_MOUSEWHEEL:
           std::cout <<(short) HIWORD(wParam) << '\n';

        break;
        case WM_COMMAND:

            if((HWND)lParam==hBtn1){BitmapWorkPlace();}
            if((HWND)lParam==hBtn2){ImageWorkPlace();}
            if((HWND)lParam==hBtn3){ToolsWorkPlace();}
        break;
        case WM_CREATE:
            createControls(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}







