#include <graphics.h>
#include <conio.h>

int main(void)
{   
    initgraph(1920,1080,0);
    setbkcolor(WHITE);
    cleardevice();
    setorigin(960,540);
    setcolor(BLUE);
    double x=0,y=0;
    moveto(-100,-100);
    lineto(-100,-100);
    getch();
    closegraph();

    return 0;
}