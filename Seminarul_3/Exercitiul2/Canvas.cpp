#include "Canvas.h"
#include <iostream>
#include <math.h>

using namespace std;

Canvas::Canvas(int width,int height) 
{
	this->Canva = new char [width * height];

	this->width = width;
	this->height = height;

	for (int i = 0; i < this->height; i++)
		for (int j = 0; j < this->width; j++)
			this->Canva[i * this->height + j] = ' ';
}

Canvas::~Canvas()
{
	delete[] this->Canva;

}

void Canvas::Clear()
{
	for (int i = 0; i < this->height; i++)
		for (int j = 0; j < this->width; j++)
			this->Canva[i * this->height + j] = ' ';

}

void Canvas::Print()
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
			cout << this->Canva[i * this->height + j] << " ";

	cout << endl;
	}
}

void Canvas::SetPoint(int x,int y,char ch) {

	 this->Canva[y * this->height + x] = ch;
}

void Canvas::plotLine(int x0, int y0, int x1, int y1, char ch)
{
    if (abs(y1 - y0) < abs(x1 - x0))
    {
        if (x0 > x1)

            plotLineLow(x1, y1, x0, y0, ch);
        else
            plotLineLow(x0, y0, x1, y1, ch);
    }
    else
    
        if (y0 > y1)
            plotLineHigh(x1, y1, x0, y0, ch);
        else
            plotLineHigh(x0, y0, x1, y1, ch);
    
}

void Canvas::plotLineHigh(int x0, int y0, int x1, int y1,char ch)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    int xi = 1;
   
    if (dx < 0)
    {
        xi = -1;
        dx = -dx;
    }
    int  D = (2 * dx) - dy;
    int x = x0;

    for (int y = y0; y <= y1; y++)
    {
        this->Canva[y * this->height + x] = ch;
        if (D > 0)
        {
            x = x + xi;
            D = D + (2 * (dx - dy));
        }
        else
            D = D + 2 * dx;
    }
}

void Canvas::plotLineLow(int x0, int y0, int x1, int y1, char ch)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    int yi = 1;
    if (dy < 0)
    {
        yi = -1;
        dy = -dy;
    }
    int D = (2 * dy) - dx;
    int y = y0;

    for (int x = x0; x <= x1; x++)
    {
        this->Canva[y * this->height + x] = ch;
            if (D > 0)
            {
                y = y + yi;
                D = D + (2 * (dy - dx));
            }
            else
                D = D + 2 * dy;
    }
                   
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    Canvas::plotLine(x1, y1, x2, y2, ch);

}

void Canvas::DrawRect(int x1, int y1, int x2, int y2, char ch)
{
    Canvas::plotLine(x1, y1, x2, y1, ch);
    Canvas::plotLine(x1, y1, x1, y2, ch);
    Canvas::plotLine(x1, y2, x2, y2, ch);
    Canvas::plotLine(x2, y1, x2, y2, ch);

}

void Canvas::FillRect(int x1, int y1, int x2, int y2, char ch)
{
    for (int i = y1 + 1; i < y2; i++)
    {
        Canvas::plotLine(x1, i, x2, i, ch);
  
    }
}

void Canvas::DrawCircle(int x1, int y1, int r, char ch)
{
    for (int i = 1; i < 360; i++)
       if((x1 + r * cos(i)) >= 0 && (y1 + r * sin(i)) >= 0 && (x1 + r * cos(i)) < this->width && (y1 + r * sin(i)) < this->height)
           Canvas::SetPoint(x1 + r * cos(i), y1 + r * sin(i), ch);
}

void Canvas::FillCircle(int x1, int y1, int r, char ch)
{
    /*
    for (int i = 1; i < 360; i++)
        if ((x1 + r * cos(i)) >= 0 && (y1 + r * sin(i)) >= 0 && (x1 + r * cos(i)) < this->width && (y1 + r * sin(i)) < this->height)
            Canvas::plotLine(x1, y1, x1 + r * cos(i), y1 + r * sin(i), ch);

        else if ((x1 + r * cos(i)) < 0 && (y1 + r * sin(i)) >= 0 && (y1 + r * sin(i)) < this->height)
            Canvas::plotLine(x1, y1, 0, y1 + r * sin(i), ch);
        else if ((x1 + r * cos(i)) < 0 && (y1 + r * sin(i)) < 0)
            Canvas::plotLine(x1, y1, 0, 0, ch);
        else if ((x1 + r * cos(i)) >= 0 && (x1 + r * cos(i)) < this->width && (y1 + r * sin(i)) < 0)
            Canvas::plotLine(x1, y1, x1 + r * cos(i), 0, ch);

        else if ((x1 + r * cos(i)) >= this->width && (y1 + r * sin(i)) >= this->height)
            Canvas::plotLine(x1, y1, this->width - 1, this->height - 1, ch);
        else if ((x1 + r * cos(i)) < this->width && (x1 + r * cos(i)) >= 0 && (y1 + r * sin(i)) >= this->height)
            Canvas::plotLine(x1, y1, x1 + r * cos(i), this->height - 1, ch);
        else if ((x1 + r * cos(i)) >= this->width && (y1 + r * sin(i)) < this->height && (y1 + r * sin(i)) >= 0)
            Canvas::plotLine(x1, y1, this->width - 1, y1 + r * sin(i), ch);
            */


    for (int i = x1 - r; i <= x1 + r; i++)
        for (int j = y1 - r; j <= y1 + r; j++)
            if (sqrt((x1 - i) * (x1 - i) + (y1 - j) * (y1 - j)) < r)
                if(i < 0 && j > 0 && j < this->height)
                    Canvas::plotLine(x1, y1, 0, j, ch);
                else if(i < 0 && j < 0)
                    Canvas::plotLine(x1, y1, 0, 0, ch);
                else if (i > 0 && i < this->width && j < 0)
                    Canvas::plotLine(x1, y1, i, 0, ch);

                else if (i < this -> width && j >= this->height)
                    Canvas::plotLine(x1, y1, i, this->height - 1, ch);
                else if (i >= this->width && j >= this->height)
                    Canvas::plotLine(x1, y1, this->width - 1, this->height, ch);
                else if (i >= this->width && j < this->height)
                    Canvas::plotLine(x1, y1, this->width - 1, j, ch);
                else
                 Canvas::plotLine(x1, y1, i, j, ch);
           
}