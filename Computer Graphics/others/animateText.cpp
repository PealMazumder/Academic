#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int main()
{
    initwindow(500, 500);

    for(int i=1;i<450;i++){
        cleardevice();
        if(i & 1)
            moveto(250+i,200+5);
        else moveto(250+i,200);
        setcolor(WHITE);
        outtext("PEAL");

        if(i & 1)
            moveto(250-i,200+5);
        else moveto(250-i, 200);
        setcolor(RED);
        outtext("PEAL");

        if(i & 1)
            moveto(250+5,200+i);
        else moveto(250, 200+i);
        setcolor(GREEN);
        outtext("PEAL");

        if(i & 1)
            moveto(250+5,200-i);
        else moveto(250,200-i);
        setcolor(YELLOW);
        outtext("PEAL");

        delay(100);
    }
    getch();
    closegraph();
    return 0;
}
