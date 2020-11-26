#include <graphics.h>
#include <stdio.h>

void customLine(int xa, int ya, int xb, int yb, const char* tipe, int color){
    float x, y, dx, dy, steps;
    int i;
    int loop = 1;

    dx = (float)(xb - xa);
    dy = (float)(yb - ya);
    if(dx>=dy)
           {
        steps = dx;
    }
    else
           {
        steps = dy;
    }
    dx = dx/steps;
    dy = dy/steps;
    x = xa;
    y = ya;
    i = 1;

	if (tipe == "horizontal" || tipe == "Horizontal"){
            while(i<= steps)
            {
                putpixel(x, y, color);
                x += dx;
                y += dy;
                i=i+1;
            }
     } else if (tipe == "vertikal" || tipe == "Vertikal"){
            while(i<= steps)
            {
                putpixel(x, y, color);
                x += dx;
                y += dy;
                i=i+1;
            }
     } else if (tipe == "Hdash" || tipe == "HDash"){
            while(i<= steps)
            {
                int *x_new = new int (x);
                if ( *x_new % 5 == 0){
                    int solid = x;
                    for (int i=0;i<5;i++){
                        putpixel(solid, y, color);
                        solid++;
                    }
                }
                if (*x_new % 25 == 0){
                    int blank = x;
                    for (int i=0;i<20;i++){
                        putpixel(blank, y, 0);
                        blank++;
                    }
                }
                x += dx;
                y += dy;
                i=i+1;
            }
     } else if (tipe == "Vdash" || tipe == "VDash"){
             while(i<= steps)
            {
                int *y_new = new int (y);
                if (*y_new % 5 == 0){
                    int solid = y;
                    for (int i=0;i<5;i++){
                        putpixel(x, solid, color);
                        solid++;
                    }
                }
                if (*y_new % 25 == 0){
                    int blank = y;
                    for (int i=0;i<20;i++){
                        putpixel(x, blank, 0);
                        blank++;
                    }
                }
                x += dx;
                y += dy;
                i=i+1;
            }
     }else if (tipe == "Htebal" || tipe == "HTebal"){
         while (loop < 5){
            customLine(xa,ya++,xb,yb++,"horizontal", color);
            loop++;
         }
     } else if (tipe == "Vtebal" || tipe == "VTebal"){
         while (loop < 5){
            customLine(xa++,ya,xb++,yb,"vertikal", color);
            loop++;
         }
     }
}

