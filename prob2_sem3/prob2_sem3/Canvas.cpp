#include "Canvas.h"
#include <iostream>

using namespace std;

Canvas::Canvas(int width, int height) 
{
    this->width = width;
    this->height = height;

    matrix = new char* [height];
    for (int i = 0; i < height; i++) 
    {
        matrix[i] = new char[width];
        for (int j = 0; j < width; j++) 
        {
            matrix[i][j] = ' ';
        }
    }
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) 
{
    for (int i = 0; i < height; i++) 
        for (int j = 0; j < width; j++) 
            if ((i - x) * (i - x) + (j - y) * (j - y) == ray * ray) matrix[i][j] = ch;

}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
    for (int i = x - ray; i <= x + ray; i++) 
    {
        for (int j = y - ray; j <= y + ray; j++)
        {
            if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)
            {
                if (i >= 0 && j >= 0 && i < height && j < width)
                {
                    matrix[i][j] = ch;
                }
            }
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = top; i <= bottom; i++)
    {
        matrix[i][left] = ch;
        matrix[i][right] = ch;
    }
    for (int i = left; i <= right; i++) 
    {
        matrix[top][i] = ch;
        matrix[bottom][i] = ch;
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) 
{
    for (int i = top; i <= bottom; i++)
        for (int j = left; j <= right; j++)
            matrix[i][j] = ch;
}

void Canvas::SetPoint(int x, int y, char ch)
{
    if (x >= 0 && y >= 0 && x < height && y < width) matrix[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (x1 != x2 || y1 != y2) 
    {
        SetPoint(x1, y1, ch);
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

void Canvas::Print() 
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++) cout << matrix[i][j];
        cout << endl;
    }
}

void Canvas::Clear() 
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++) 
        {
            matrix[i][j] = ' ';
        }
    }
}
