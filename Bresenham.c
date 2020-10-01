#include<graphics.h>
#include<stdio.h>

#define Round(a) ((int)(a+0.5))

void bresenham(int x0,int y0,int x1,int y1){
    int dx = abs(x1-x0), dy = abs(y1-y0);
    int pk = 2*dy-dx;
    int x = x0,y= y0;
    putpixel(x,y,RED);
    for(int i = 0;i < dx;i++){
        if(pk < 0){
            putpixel(x,y,RED);
            pk += 2*dy;
        }else{
            y++;
            putpixel(x,y,RED);
            pk += 2*(dy - dx);
        }
        x++;
    }
}

void main(){
    int gd = DETECT,gm;
    initgraph(&gd,&gm,NULL);
    bresenham(0,0,400,400);
    delay(5000);
    closegraph();
}

