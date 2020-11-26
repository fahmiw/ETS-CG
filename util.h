#include <graphics.h>
#include <stdio.h>
#include "shape.h"

void initCanvas(int width, int height, const char* title){
    initwindow(width, height, title);
}

void circleAnim()
{
    int loop = 250;
    int loop2 = 0;

    while (loop>1){
        lingkaranMidPoint(250, 250, loop, "color", rand()%15);
        swapbuffers();
        loop--;

    }
    while (loop2<250){
        lingkaranMidPoint(250, 250, loop2, "color", 7);
        swapbuffers();
        cleardevice();
        loop2++;
    }
    swapbuffers();
    cleardevice();
}

void clanAnim()
{
    int i, iAkhir, j = 0;
	int rx = 250, ry = 250;
    int loop1 = 150;
        while (loop1 > 1){
                for ( int angle = 0; angle < 120; angle+=5 ) {
                segitigaSisi(250, 192, loop1, angle, 1);
                segitigaSisi(173, 325, loop1, angle, 2);
                segitigaSisi(325, 325, loop1, angle, 3);
                swapbuffers();
                cleardevice();
                loop1--;
        }
    }
    while (j < 7){
       while ( i < 550 ){
            segitigaSisi(rx, ry, i, 0, rand()%15);
            swapbuffers();
            delay(50);
            i+=50;
            iAkhir = i;
        }
        while (loop1 > 1){
                for ( int angle = 0; angle < 360; angle+=5 ) {
                segitigaSisi(rx, ry, loop1, angle, rand()%15);
                swapbuffers();
                cleardevice();
                delay(20);
                loop1--;
            }
        }
        j++;
        i = 0;
        iAkhir = 0;
        loop1 = 150;
        rx = rand()%400;
        ry = rand()%400;
	}

	swapbuffers();
    cleardevice();
    loop1 = 150;
    while (loop1 > 1){
           segitigaSisi(250, 192, loop1, 0, 7);
           segitigaSisi(173, 325, loop1, 0, 7);
           segitigaSisi(325, 325, loop1, 0, 7);
           swapbuffers();

           loop1--;
        }
    swapbuffers();
    cleardevice();
}

void lastAnim(){
    int i = 0, iAkhir = 50, j = 0;
	int rx = 250, ry = 250;
        while ( i < 550 ){
            for ( int angle = 0; angle < 360; angle+=20 ) {
                segitigaSisi(rx, ry, iAkhir, angle, rand()%15);
                swapbuffers();
                delay(150);
            }
            i+=50;
            iAkhir = i;
            rx = rand()%400;
            ry = rand()%400;
            swapbuffers();
            cleardevice();
        }
        i = 0;
        while ( i < 800 ){
            segitigaSisi(250, 250, i, 0, rand()%15);
            swapbuffers();
            cleardevice();
            delay(100);
            i+=50;
        }
    swapbuffers();
    cleardevice();
}


void headerMenu(){
    char choose_char;
    int choose, s;
    printf("Masukan ukuran canvas SxS:");
    scanf("%d", &s);
    initCanvas(s, s, "New Canvas");

    menu:
    printf("PROGRAM CG : FAHMI WIDIANTO\n");
    printf("=======MENU=======\n");
    printf("1. Stroke\n");
    printf("2. Shape\n");
    printf("3. Menampilkan animasi ETS\n");
    printf("Masukan Pilihan : ");
    scanf("%d", &choose);

    if (choose == 1){
        system("cls");
        int num;
        printf("======MENU STROKE======\n");
        printf("1. Menampilkan semua warna\n");
        printf("2. Menampilkan semua tipe\n");

        printf("Masukan nomor pilihan : ");
        scanf("%d", &num);

        if (num == 1){
            int hr = 1, m = 5;

            while (hr < 49){
                    customLine(10+m, 10+m, 490-m, 10+m, "horizontal",  rand() % 15);
                    delay(10);
                    customLine(490-m, 10+m, 490-m, 490-m, "vertikal",  rand() % 15);
                    delay(10);
                    customLine(10+m, 490-m, 490-m, 490-m, "horizontal", rand() % 15);
                    delay(10);
                    customLine(10+m, 10+m, 10+m, 490-m, "vertikal",  rand() % 15);
                    delay(10);

                    m = m + 5;
                    hr++;
                }
            } else if (num == 2) {
                        customLine(10, 20, 490, 20, "horizontal",  rand() % 15);
                        delay(10);
                        customLine(20, 250, 20, 490, "vertikal",  rand() % 15);
                        delay (10);

                        customLine(10, 40, 490, 40, "Hdash",  rand() % 15);
                        delay(10);
                        customLine(40, 250, 40, 490, "Vdash",  rand() % 15);
                        delay(10);

                        customLine(10, 60, 490, 60, "Htebal",  rand() % 15);
                        delay(10);
                        customLine(60, 250, 60, 490, "Vtebal",  rand() % 15);
                        delay(10);
                } else {
                    printf("Pilihan tidak ada\n");
                    exit(1);
                }

                printf("Kembali Ke Menu Utama(Y/N)\n");
                scanf(" %c", &choose_char);
                if(choose_char == 'Y' || choose_char == 'y'){
                    system("cls");
                    cleardevice();
                    goto menu;
                } else {
                    goto esc;
                }

                getch();
                closegraph();

    } else if (choose == 2){
        system("cls");

        int num2;
        printf("======MENU SHAPE======\n");
        printf("1. Persegi\n");
        printf("2. Persegi Panjang\n");
        printf("3. Jajar Genjang\n");
        printf("4. Trapesium\n");
        printf("5. Segitiga siku-siku\n");
        printf("6. Segitiga Sisi\n");
        printf("7. Belah Ketupat\n");
        printf("8. Layang-layang\n");
        printf("9. Ellips\n");
        printf("10. Lingkaran\n");

        printf("Masukan nomor pilihan : ");
        scanf("%d", &num2);
        switch(num2){
            case 1 : {
                persegi(50 , "biasa", rand()%15);
                persegi(100 , "dash", rand()%15);
                persegi(200 , "tebal", rand()%15);
                break;
            }
            case 2 : {
                persegiPanjang(50, 200, 100, 100, "biasa", rand()%15);
                persegiPanjang(120, 270, 170, 170, "dash", rand()%15);
                persegiPanjang(200, 350, 250, 250, "tebal", rand()%15);
                break;
            }
            case 3 : {
                jajarGenjang(50, 200, 100, 100, "biasa", rand()%15);
                jajarGenjang(120, 270, 170, 170, "dash", rand()%15);
                jajarGenjang(200, 350, 250, 250, "tebal", rand()%15);
                break;
            }
            case 4 : {
                Trapesium(50, 200, 100, 100, "biasa", rand()%15);
                Trapesium(120, 270, 170, 170, "dash", rand()%15);
                Trapesium(200, 350, 250, 250, "tebal", rand()%15);
                break;
            }
            case 5 : {
                segitigaSiku(50, 50, 50,  "biasa", rand()%15);
                segitigaSiku(100, 100, 100, "dash", rand()%15);
                segitigaSiku(180, 180, 180, "tebal", rand()%15);
                break;
            }
            case 6 : {
                segitigaSisi(400,200,100,0,1);
                break;
            }
            case 7 : {
                belahKetupat(250, 250, 100, 5);
                break;
            }
            case 8 : {
                layangs(150, 150, 100, 5);
                break;
            }
            case 9 : {
                ellipseMidPoint(50, 100, 250, 250, 90);
                break;
            }
            case 10 : {
                lingkaranMidPoint(250, 250, 200, "biasa", 0);
                break;
            }
        }
        printf("Kembali Ke Menu Utama(Y/N)\n");
        scanf(" %c", &choose_char);
        if(choose_char == 'Y' || choose_char == 'y'){
            system("cls");
            cleardevice();
            goto menu;
        } else {
            goto esc;
        }

        getch();
        closegraph();

    } else if (choose == 3) {

        clanAnim();
        circleAnim();
        lastAnim();

        getch();
        closegraph();
    }else {
            printf("Pilihan tidak ada\n");
            esc:
            exit(1);
    }

}
