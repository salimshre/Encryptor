#include <graphics.h>
#include <conio.h>
#include "userui.h"


int main(int argc, char const *argv[]) {
    // int gd = DETECT, gm;
    // initgraph(&gd, &gm, (char*)"hello");
    // circle(320, 240, 200); //unnecessary drawing.


    int x, y;
    // Initialize graphics window
    initwindow(800, 600, "Encryption Tool");

    // Draw UI elements
    user_interference();

    // Instructions
    outtextxy(100, 100, (char*) "Click anywhere in the window to get an coordinates...");
    outtextxy(100, 120, (char*) "Press any key to stop.");

    // Wait for mouse click
    while (!kbhit()) { //this looop continues untill the key is pressed.
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y); // Get mouse click coordinates
            clearmouseclick(WM_LBUTTONDOWN);     // Clear the click event
            // Display coordinates
            char coord[50];
            sprintf(coord, "You clicked at: %d, %d", x, y);
            
            settextstyle(DEFAULT_FONT, HORIZ_DIR, 1); //explicitly set the font size before drawing

            outtextxy(100, 150, coord);
        }
    }

    
    

    getch();
    closegraph();
    return 0;
    //test
}

void background_image(){
        readimagefile("background.bmp",0,0,SCREEN_WIDTH, SCREEN_HEIGHT); //screen width will cover an full screen.
    }

void title(){
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(100,60,700,130); // fill rectange on a screen
        settextstyle(SIMPLEX_FONT, HORIZ_DIR, 4); //font size is 7
        outtextxy(300, 60, (char*)"Encryption");
}

void user_interference() {
        background_image();
        title();

        // Reset to default font for other elements
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 1); 

        setcolor(WHITE);
        rectangle(327, 181, 838, 605);

        
        
}
