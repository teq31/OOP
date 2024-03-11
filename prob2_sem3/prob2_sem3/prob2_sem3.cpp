#include "Canvas.h"

int main() 
{
    
    Canvas canvas(20, 20);

    canvas.DrawCircle(10, 10, 5, '*');
    canvas.FillCircle(10, 10, 4, '$');
    canvas.DrawRect(2, 2, 6, 6, '+');
    canvas.FillRect(3, 3, 5, 5, '-');
    canvas.DrawLine(0, 0, 19, 19, '.');

    canvas.Print();

    return 0;
}
