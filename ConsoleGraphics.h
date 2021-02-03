#ifndef CPU_V_17_CONSOLEGRAPHICS_H
#define CPU_V_17_CONSOLEGRAPHICS_H
#include <math.h>
#include "Config.h"


struct Screen
{
    int screen[MAXLENGTH][MAXHEIGHT];
    int xmax;
    int ymax;
};

Screen Window = {};                                         // Structure containing window pixels data

int SetWindow(int xmax, int ymax)
{
    if ((xmax > MAXLENGTH) || (ymax > MAXHEIGHT))
    {
        printf("Window oversize\n");
        return 0;
    }

    Window.xmax = xmax;
    Window.ymax = ymax;
    for (int i = 0; i < xmax; i++)
        for (int j = 0; j < ymax; j++)
            Window.screen[i][j] = 0;

    return 1;
}

int Pixel (int x, int y, int value){
    if ((x >= Window.xmax) || (y >= Window.ymax) || (x < 0) || (y < 0))
    {
        printf ("Invalid values\n");
        return 0;
    }

    Window.screen[2*x][y] = value;
    Window.screen[2*x + 1][y] = value;
    return 1;
}

int Rectangle(int x1, int y1, int x2, int y2, int value)
{
    if ((x1 >= Window.xmax) || (y1 >= Window.ymax) || (x1 < 0) || (y1 < 0) || (x2 >= Window.xmax) || (y2 >= Window.ymax) || (x2 < 0) || (y2 < 0) || (x1 > x2) || (y1 > y2))
    {
        printf ("Invalid values\n");
        return 0;
    }

    for (int i = x1; i <= x2; i++)
    {
        Pixel(i, y1, value);
        Pixel(i, y2, value);
    }

    for (int i = y1; i <= y2; i++)
    {
        Pixel(x1, i, value);
        Pixel(x2, i, value);
    }

    return 1;
}

int Circle(int x, int y, int r, int value)
{
    if (((x + r) >= Window.xmax) || ((y + r) >= Window.ymax) || ((x - r) < 0) || ((y - r) < 0) || (r < 0))
    {
        printf ("Invalid values\n");
        return 0;
    }

    int temp = 0;
    int tempx = 0;
    int tempy = 0;
    for (double i = (M_PI / 100); i <= (M_PI / 4); i += (M_PI / 100))
    {
        tempx = (int)(x + r * sin(i));
        tempy = (int)(y + r * cos(i));
        Pixel(tempx, tempy, value);

        tempx = (int)(x - r * sin(i));
        tempy = (int)(y + r * cos(i));
        Pixel(tempx, tempy, value);

        tempx = (int)(x + r * sin(i));
        tempy = (int)(y - r * cos(i));
        Pixel(tempx, tempy, value);

        tempx = (int)(x - r * sin(i));
        tempy = (int)(y - r * cos(i));
        Pixel(tempx, tempy, value);

        tempx = (int)(x + r * cos(i));
        tempy = (int)(y + r * sin(i));
        Pixel(tempx, tempy, value);

        tempx = (int)(x - r * cos(i));
        tempy = (int)(y + r * sin(i));
        Pixel(tempx, tempy, value);

        tempx = (int)(x + r * cos(i));
        tempy = (int)(y - r * sin(i));
        Pixel(tempx, tempy, value);

        tempx = (int)(x - r * cos(i));
        tempy = (int)(y - r * sin(i));
        Pixel(tempx, tempy, value);
    }

    return 1;
}

int Vline (int x, int y1, int y2, int value)
{
    for (int i = y1; i <= y2; i++)
        Pixel(x, i, value);
    return 1;
}

int Hline (int x1, int x2, int y, int value)
{
    for (int i = x1; i <= x2; i++)
        Pixel(i, y, value);
    return 1;
}

int Line (int x1, int y1, int x2, int y2, int value)
{

    if (y2 > y1) {
        double k = 1. * (y2 - y1) / (x2 - x1);
        if ((x2 - x1) >= (y2 - y1))
            for (int i = x1; i <= x2; i++)
                Pixel(i, (y1 + ((int) (k * (i - x1)))), value);
        else
            for (int i = y1; i <= y2; i++)
                Pixel((x1 + ((int) (1. * (i - y1) / k))), i, value);
    }
        else
        {
            double k = 1. * (y2 - y1) / (x2 - x1);
            if ((x2 - x1) >= (y1 - y2))
                for (int i = x1; i <= x2; i++)
                    Pixel(i, (y1 + ((int) (k * (i - x1)))), value);
            else
                for (int i = y1; i >= y2; i--)
                    Pixel((x1 + ((int) (1. * (i - y1) / k))), i, value);
        }
    return 1;
}

int Draw()
{
    for (int i = 0; i < Window.ymax; i++)
    {
        for (int j = 0; j < Window.xmax; j++)
        {
            printf("%c", Window.screen[j][i]);
        }
        printf("\n");
    }
    return 1;
}

void WindowClear()
{
    for (int i = 0; i < Window.xmax; i++)
        for (int j = 0; j < Window.ymax; j++)
            Pixel(i, j, 0);
}

void PartClear(int x1, int y1, int x2, int y2)
{
    for (int i = x1; i < x2; i++)
        for (int j = y1; j < y2; j++)
            Pixel(i, j, 0);
}

#endif //CPU_V_17_CONSOLEGRAPHICS_H