#include<graphics.h>
#include<conio.h>
#include<stdio.h>
void window_to_viewport(int W_xmax, int W_ymax, int W_xmin, int W_ymin, int V_xmax,
                        int V_ymax, int V_xmin, int V_ymin, int x1, int y1,
                        int x2, int y2, int x3, int y3){

    float sx, sy;
    //Window
    rectangle(W_xmin, W_ymin, W_xmax, W_ymax);
    outtextxy(W_xmin, W_ymin - 10, "Window");

    // viewport
    rectangle (V_xmin, V_ymin, V_xmax, V_ymax);
    outtextxy (V_xmin, V_ymin - 10, "Viewport");

    // calculatng Sx and Sy
    sx = (float) (V_xmax - V_xmin) / (W_xmax - W_xmin);
    sy = (float) (V_ymax - V_ymin) / (W_ymax - W_ymin);

    x1 = V_xmin + (float) ((x1 - W_xmin) * sx);
    x2 = V_xmin + (float) ((x2 - W_xmin) * sx);
    x3 = V_xmin + (float) ((x3 - W_xmin) * sx);
    y1 = V_ymin + (float) ((y1 - W_ymin) * sy);
    y2 = V_ymin + (float) ((y2 - W_ymin) * sy);
    y3 = V_ymin + (float) ((y3 - W_ymin) * sy);
    // drawing triangle
    line (x1, y1, x2, y2);
    line (x1, y1, x3, y3);
    line (x2, y2, x3, y3);

}
int main()
{
    initwindow(800, 600, "The Window");

    int x1=200, y1=100, x2=100, y2=200, x3=300, y3=200;
    int W_xmax=750, W_ymax=550, W_xmin=10, W_ymin=10;
    int V_xmax=700, V_ymax=500, V_xmin=350, V_ymin=30;

    //drawing a triangle
    line (x1, y1, x2, y2);
    line (x1, y1, x3, y3);
    line (x2, y2, x3, y3);
    window_to_viewport(W_xmax, W_ymax, W_xmin, W_ymin, V_xmax, V_ymax, V_xmin, V_ymin, x1, y1, x2, y2, x3, y3);

    getch ();
}

