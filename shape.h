#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include "stroke.h"

#define SIN(x) sin(x * 3.141592653589 / 180)
#define COS(x) cos(x * 3.141592653589 / 180)

void persegi(int sisi, const char* tipe, int color){

    if (tipe == "biasa" || tipe == "Biasa"){
        customLine(sisi, sisi, sisi, 2*sisi, "vertikal", color);
        customLine(sisi, sisi, 2*sisi, sisi, "horizontal", color);
        customLine(2*sisi, sisi, 2*sisi, 2*sisi, "vertikal", color);
        customLine(sisi, 2*sisi, 2*sisi, 2*sisi, "horizontal", color);
    }
    if (tipe == "dash" || tipe == "Dash"){
        customLine(sisi, sisi, sisi, 2*sisi, "VDash", color);
        customLine(sisi, sisi, 2*sisi, sisi, "HDash", color);
        customLine(2*sisi, sisi, 2*sisi, 2*sisi, "VDash", color);
        customLine(sisi, 2*sisi, 2*sisi, 2*sisi, "HDash", color);
    }
    if (tipe == "tebal" || tipe == "Tebal"){
        customLine(sisi, sisi, sisi, 2*sisi, "VTebal", color);
        customLine(sisi, sisi, 2*sisi, sisi, "HTebal", color);
        customLine(2*sisi, sisi, 2*sisi, 2*sisi, "VTebal", color);
        customLine(sisi, 2*sisi, 2*sisi, 2*sisi, "HTebal", color);
    }
}

void  persegiPanjang(int left, int top, int right, int bottom, const char* tipe, int color){
    if (tipe == "biasa" || tipe == "Biasa"){
        customLine(left, left, left, bottom,  "vertikal", color);
        customLine(left, left, top, left,  "horizontal", color);
        customLine(top, left, top, bottom,  "vertikal", color);
        customLine(left, bottom, top, bottom,  "horizontal", color);
    }
    if (tipe == "dash" || tipe == "Dash"){
        customLine(left, left, left, bottom,  "VDash", color);
        customLine(left, left, top, left,  "HDash", color);
        customLine(top, left, top, bottom,  "VDash", color);
        customLine(left, bottom, top, bottom,  "HDash", color);
    }
    if (tipe == "tebal" || tipe == "Tebal"){
        customLine(left, left, left, bottom,  "VTebal", color);
        customLine(left, left, top, left,  "HTebal", color);
        customLine(top, left, top, bottom,  "VTebal", color);
        customLine(left, bottom, top, bottom,  "HTebal", color);
    }

}

void jajarGenjang(int left, int top, int right, int bottom, const char* tipe, int color){
    if (tipe == "biasa" || tipe == "Biasa"){
        customLine(left, left, left+20, bottom,  "vertikal", color);
        customLine(left, left, top, left,  "horizontal", color);
        customLine(top, left, top+20, right,  "vertikal", color);
        customLine(left+20, bottom, top+20, right,  "horizontal", color);
    }
    if (tipe == "dash" || tipe == "Dash"){
        customLine(left, left, left+20, bottom,  "VDash", color);
        customLine(left, left, top, left,  "HDash", color);
        customLine(top, left, top+20, right,  "VDash", color);
        customLine(left+20, bottom, top+20, right,  "HDash", color);
    }
    if (tipe == "tebal" || tipe == "Tebal"){
        customLine(left, left, left+20, bottom,  "VTebal", color);
        customLine(left, left, top, left,  "HTebal", color);
        customLine(top, left, top+20, right,  "VTebal", color);
        customLine(left+20, bottom, top+20, right,  "HTebal", color);
    }
}

void Trapesium(int left, int top, int right, int bottom, const char* tipe, int color){
    void segitigaSiku(int, int, int, const char* , int );
    int tinggi = bottom - left;
    if (tipe == "biasa" || tipe == "Biasa"){
        persegiPanjang(left, top, right, bottom, "biasa", color);
        customLine(top, left, top, right,  "vertikal",0);
        segitigaSiku(top-tinggi, bottom, tinggi, "biasa", color);
        customLine(top-(tinggi/2), left, top-tinggi, bottom, "vertikal", 0);
        customLine(top-(tinggi/2), left, top, left, "horizontal", 0);

        customLine(left, left, left, right,  "vertikal",0);
        segitigaSiku(left, bottom, tinggi, "biasa", color);
        customLine(left+(tinggi/2), left, bottom, bottom, "vertikal", 0);
        customLine(left-(tinggi/2), left, left+(tinggi/2), left, "horizontal", 0);
    }
    if (tipe == "dash" || tipe == "Dash"){
        persegiPanjang(left, top, right, bottom, "dash", color);
        customLine(top, left, top, right,  "Vdash",0);
        segitigaSiku(top-tinggi, bottom, tinggi, "dash", color);
        customLine(top-(tinggi/2), left, top-tinggi, bottom, "Vtebal", 0);
        customLine(top-(tinggi/2), left, top, left, "Hdash", 0);
    }
    if (tipe == "tebal" || tipe == "Tebal"){
        persegiPanjang(left, top, right, bottom, "tebal", color);
        customLine(top, left, top, right,  "Vtebal",0);
        segitigaSiku(top-tinggi, bottom, tinggi, "tebal", color);
        customLine(top-(tinggi/2), left, top-tinggi, bottom, "Vtebal", 0);
        customLine(top-(tinggi/2), left+5, top-tinggi, bottom, "Vtebal", 0);
        customLine(top-(tinggi/2), left, top, left, "Htebal", 0);
    }

}

void segitigaSiku(int xa, int ya, int sisi, const char* tipe, int color){

    if (tipe == "biasa" || tipe == "Biasa"){
        customLine((xa+(sisi/2)), ya-sisi, xa, ya, "vertikal", color);
        customLine((xa+(sisi/2)), ya-sisi, xa+sisi, ya, "vertikal", color);
        customLine(xa, ya, xa+sisi, ya, "horizontal", color);
    }
    if (tipe == "dash" || tipe == "Dash"){
        customLine((xa+(sisi/2)), ya-(sisi*0.86), xa, ya, "VDash", color);
        customLine((xa+(sisi/2)), ya-(sisi*0.86), xa+sisi, ya, "VDash", color);
        customLine(xa, ya, xa+sisi, ya, "HDash", color);
    }
    if (tipe == "tebal" || tipe == "Tebal"){
        customLine((xa+(sisi/2)), ya-(sisi*0.86), xa, ya, "VTebal", color);
        customLine((xa+(sisi/2)), ya-(sisi*0.86), xa+sisi, ya, "VTebal", color);
        customLine(xa, ya, xa+sisi, ya, "HTebal", color);
    }

}


void lingkaranMidPoint(int xa, int ya, int rad, const char* tipe, int color){
    int x = 0;
     int y = rad;
     int p = 1 - rad;
     void lingkaranPlotPoints (int, int, int, int, const char*, int);
     while (x < y) {
      x++;
      if (p < 0){
       p += 2 * x + 1;
      }
      else {
       y--;
       p += 2 * (x - y) + 1;
      }
      lingkaranPlotPoints (xa, ya, x, y, tipe, color);
     }
}

void lingkaranPlotPoints (int xa, int ya, int x, int y, const char* tipe, int color)
{
        // 8 Titik Simetri
        if (tipe == "biasa" || tipe == ""){
                putpixel (xa + x, ya - y,1);
                putpixel (xa + y, ya - x,2);

                putpixel (xa + y, ya + x,3);
                putpixel (xa + x, ya + y,4);

                putpixel (xa - x, ya + y,5);
                putpixel (xa - y, ya + x,6);

                putpixel (xa - y, ya - x,7);
                putpixel (xa - x, ya - y,9);
        } else if (tipe == "color"){

                putpixel (xa + x, ya - y,color);
                putpixel (xa + y, ya - x,color);

                putpixel (xa + y, ya + x,color);
                putpixel (xa + x, ya + y,color);

                putpixel (xa - x, ya + y,color);
                putpixel (xa - y, ya + x,color);

                putpixel (xa - y, ya - x,color);
                putpixel (xa - x, ya - y,color);

        } else if (tipe == "dash" || tipe == "Dash"){
            int x1 = xa + x;
            int y1 = ya - y;

            putpixel (xa + x, ya - y,1);
            if (x1 % 10 == 0){
                putpixel (xa + x, ya - y,0);
            }

            putpixel (xa + y, ya - x,2);
            if (x1 % 10 == 0){
                putpixel (xa + y, ya - x,0);
            }

            putpixel (xa + y, ya + x,3);
            if (x1 % 10 == 0){
                putpixel (xa + y, ya + x,0);
            }
            putpixel (xa + x, ya + y,4);
            if (x1 % 10 == 0){
                putpixel (xa + x, ya + y,0);
            }

            putpixel (xa - x, ya + y,5);
            if (x1 % 10 == 0){
                putpixel (xa - x, ya + y,0);
            }

            putpixel (xa - y, ya + x,6);
            if (x1 % 10 == 0){
                putpixel (xa - y, ya + x,0);
            }

            putpixel (xa - y, ya - x,7);
            if (x1 % 10 == 0){
                putpixel (xa - y, ya - x,0);
            }
            putpixel (xa - x, ya - y,9);
            if (x1 % 10 == 0){
                putpixel (xa - x, ya - y,0);
            }
        } else if (tipe == "titik" || tipe == "Titik"){
            int x1 = xa + x;
            int y1 = ya - y;

            putpixel (xa + x, ya - y,1);
            if (x1 % 2 == 0){
                putpixel (xa + x, ya - y,0);
            }

            putpixel (xa + y, ya - x,2);
            if (x1 % 2 == 0){
                putpixel (xa + y, ya - x,0);
            }

            putpixel (xa + y, ya + x,3);
            if (x1 % 2 == 0){
                putpixel (xa + y, ya + x,0);
            }
            putpixel (xa + x, ya + y,4);
            if (x1 % 2 == 0){
                putpixel (xa + x, ya + y,0);
            }

            putpixel (xa - x, ya + y,5);
            if (x1 % 2 == 0){
                putpixel (xa - x, ya + y,0);
            }

            putpixel (xa - y, ya + x,6);
            if (x1 % 2 == 0){
                putpixel (xa - y, ya + x,0);
            }

            putpixel (xa - y, ya - x,7);
            if (x1 % 2 == 0){
                putpixel (xa - y, ya - x,0);
            }
            putpixel (xa - x, ya - y,9);
            if (x1 % 2 == 0){
                putpixel (xa - x, ya - y,0);
            }
        } else if ( tipe == "tebal" || tipe == "Tebal"){
            int loop = 0;
            while (loop < 5){
                    putpixel (xa + x, ya - y,1);
                    putpixel (xa + y, ya - x,2);

                    putpixel (xa + y, ya + x,3);
                    putpixel (xa + x, ya + y,4);

                    putpixel (xa - x, ya + y,5);
                    putpixel (xa - y, ya + x,6);

                    putpixel (xa - y, ya - x,7);
                    putpixel (xa - x, ya - y,9);
                    x-=1;
                    y-=1;
            loop++;
         }
        }
}
void segitigaSisi ( int xCenter, int yCenter, int sisi, int angle, int color)
{
    void rotasi ( int* , int*, int , int , int );
	int xa, ya, xb, xc, yb, yc;

	double t = sisi / 2 * sqrt(3);

	ya = yCenter - ( (int) ceil(t * 2 / 3) );
	xa = xCenter;

	xb = xCenter + ( sisi / 2 );
	yb = yCenter + ( (int) ceil(t / 3) );

	xc = xCenter - ( sisi / 2 );
	yc = yb;

	rotasi ( &xa, &ya, xCenter, yCenter, angle );
	rotasi ( &xb, &yb, xCenter, yCenter, angle );
	rotasi ( &xc, &yc, xCenter, yCenter, angle );

    customLine(xa, ya, xb, yb, "vertikal", color);
    customLine(xb, yb, xa, ya, "vertikal", color);
    customLine(xc, yc, xb, yb, "horizontal", color);
    customLine(xb, yb, xc, yc, "horizontal", color);
    customLine(xc, yc, xa, ya, "vertikal", color);
    customLine(xa, ya, xc, yc, "vertikal", color);

}
void segitigaSikuScale ( int xCenter, int yCenter, int sisi, int angle, int color)
{
    void rotasi ( int* , int*, int , int , int );
    void scale (int *, int *, int , int , int , int );
	int xa, ya, xb, xc, yb, yc;

	double t = sisi / 2 * sqrt(3);

	ya = yCenter - ( (int) ceil(t * 2 / 3) );
	xa = xCenter;

	xb = xCenter + ( sisi / 2 );
	yb = yCenter + ( (int) ceil(t / 3) );

	xc = xCenter - ( sisi / 2 );
	yc = yb;

	rotasi ( &xa, &ya, xCenter, yCenter, angle );
	rotasi ( &xb, &yb, xCenter, yCenter, angle );
	rotasi ( &xc, &yc, xCenter, yCenter, angle );
	scale ( &xa, &ya, xCenter, yCenter, 2, 2 );

	customLine(xa, ya, xb, yb, "vertikal", color);
    customLine(xb, yb, xa, ya, "vertikal", color);
    customLine(xc, yc, xb, yb, "horizontal", color);
    customLine(xb, yb, xc, yc, "horizontal", color);
    customLine(xc, yc, xa, ya, "vertikal", color);
    customLine(xa, ya, xc, yc, "vertikal", color);

}

void translasi( int *x, int *y, int dx, int dy )
{
	*x += dx;
	*y += dy;
}

void rotasi ( int *x, int *y, int xPivot, int yPivot, int angle )
{
	int xShifted = *x - xPivot;
    int yShifted = *y - yPivot;


 	double xTemp = xPivot + (xShifted * COS(angle) - yShifted * SIN(angle));
 	double yTemp = yPivot + (xShifted * SIN(angle) + yShifted * COS(angle));

	if( fmod(xTemp, 1) >= 0.5 ){
		*x = ceil(xTemp);
	}else{
		*x = floor(xTemp);
	}

	if( fmod(yTemp, 1) >= 0.5 ){
		*y = ceil(yTemp);
	}else{
		*y = floor(yTemp);
	}
}

void scale (int *x, int *y, int xPivot, int yPivot, int sx, int sy)
{
	int xShifted = *x - xPivot;
    int yShifted = *y - yPivot;

    *x = xPivot + (xShifted * sx);
    *y = yPivot + (yShifted * sy);
}


void belahKetupat(int xa, int ya, int sisi, int color){
    double t = sisi / 2 * sqrt(3);
    int yPus = ya - ( (int) (sisi / 2 * sqrt(3) / 3) + 1);

    segitigaSisi( xa, ya - ( (int) (sisi / 2 * sqrt(3) / 3) + 1), sisi, 0 , color);
    segitigaSisi( xa, ya + ( (int) (sisi / 2 * sqrt(3) / 3) + 1), sisi, 180 , color);
    customLine(xa - ( sisi / 2 ), yPus + ( (int) ceil(t / 3) ), xa + ( sisi / 2 ), yPus + ( (int) ceil(t / 3) ), "horizontal", 0);
}

void layangs(int xa, int ya, int sisi, int color){
    double t = sisi / 2 * sqrt(3);
    int yPus = ya - ( (int) (sisi / 2 * sqrt(3) / 3) + 1);

    segitigaSisi ( xa, ya - ( (int) (sisi / 2 * sqrt(3) / 3) + 1), sisi, 0 , color);
	segitigaSikuScale ( xa, ya + ( (int) (sisi / 2 * sqrt(3) / 3) + 1), sisi, 180 , color);
	customLine(xa - ( sisi / 2 ), yPus + ( (int) ceil(t / 3) ), xa + ( sisi / 2 ), yPus + ( (int) ceil(t / 3) ), "horizontal", 0);
}


void ellipsePlotPoints ( int xCenter, int yCenter, int x, int y, int angle )
{
	int xTemp, yTemp;

	xTemp = xCenter + x;
	yTemp = yCenter + y;
	rotasi ( &xTemp, &yTemp, xCenter, yCenter, angle );
	putpixel(xTemp, yTemp,2);

	xTemp = xCenter - x;
	yTemp = yCenter + y;
	rotasi ( &xTemp, &yTemp, xCenter, yCenter, angle );
	putpixel(xTemp, yTemp,2);

	xTemp = xCenter + x;
	yTemp = yCenter - y;
	rotasi ( &xTemp, &yTemp, xCenter, yCenter, angle );
	putpixel(xTemp, yTemp,2);

	xTemp = xCenter - x;
	yTemp = yCenter - y;
	rotasi ( &xTemp, &yTemp, xCenter, yCenter, angle );
	putpixel(xTemp, yTemp,2);
}

void ellipseMidPoint(int rx, int ry, int xc, int yc, int angle){

    float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;

    // Inisiasi decision parameter region 1
    d1 = (ry * ry)
         - (rx * rx * ry)
         + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    // Region 1
    while (dx < dy) {
        if (d1 < 0) {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
        ellipsePlotPoints(xc, yc, x, y, angle);
    }

    // Decision parameter region 2
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5)))
         + ((rx * rx) * ((y - 1) * (y - 1)))
         - (rx * rx * ry * ry);

    // Plotting points region 2
    while (y >= 0) {
        ellipsePlotPoints(xc, yc, x, y, angle);

        if (d2 > 0) {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        }
        else {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }
}



