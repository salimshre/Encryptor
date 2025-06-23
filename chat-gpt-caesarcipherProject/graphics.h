#ifndef GRAPHICS_H
#define GRAPHICS_H

// Include your real WinBGIm or BGI library here.
// This is a placeholder!

int initwindow(int w, int h, const char* title);
void closegraph();

void readimagefile(const char* filename, int left, int top, int right, int bottom);
void bar(int left, int top, int right, int bottom);
void rectangle(int left, int top, int right, int bottom);
void setcolor(int color);
void setfillstyle(int pattern, int color);
void settextstyle(int font, int direction, int size);
void outtextxy(int x, int y, char* text);
int textwidth(const char* text);

bool ismouseclick(int event);
void getmouseclick(int event, int& x, int& y);
void clearmouseclick(int event);
void delay(int ms);
int kbhit();
char getch();

enum { WHITE=15, LIGHTGRAY=7, DEFAULT_FONT=0, HORIZ_DIR=1, SIMPLEX_FONT=0, SOLID_FILL=1 };
enum { WM_LBUTTONDOWN=0x0201 };

#endif // GRAPHICS_H


/* You don’t write the code for these, 
they are just declared here so you can use them in userui.cpp */