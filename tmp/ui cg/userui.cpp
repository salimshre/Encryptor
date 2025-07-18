#include <graphics.h>
#include <conio.h>
#include "userui.h"


int main(int argc, char const *argv[]) {
    // int gd = DETECT, gm;
    // initgraph(&gd, &gm, (char*)"hello");
    // circle(320, 240, 200); //unnecessary drawing.
    // checklist for

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

 /*       // Reset to default font for other elements
        settextstyle(SIMPLEX_FONT, HORIZ_DIR, 4);
        setcolor(WHITE);

        // Start
        line(300, 200, 500, 200);
        outtextxy(360, 180, "Start");

        // History
        line(300, 300, 500, 300);
        outtextxy(340, 280, "History");

        // Exit
        line(300, 400, 500, 400);
        outtextxy(370, 380, "Exit");

*/
        // Define constants for bar dimensions and positions
const int BAR_WIDTH = 200;      // Width of each bar
const int BAR_HEIGHT = 40;      // Height of each bar
const int BAR_Y_START = 200;    // Y-coordinate for "Start" bar
const int BAR_Y_HISTORY = 300;  // Y-coordinate for "History" bar
const int BAR_Y_EXIT = 400;     // Y-coordinate for "Exit" bar

// Set text style first (to calculate text width/height)
settextstyle(SIMPLEX_FONT, HORIZ_DIR, 4);
setcolor(WHITE);

// Draw "Start" bar with border
int barLeft = (800 - BAR_WIDTH) / 2;  // Horizontally centered: (800-200)/2 = 300
int barTop = BAR_Y_START - BAR_HEIGHT/2; // Centered vertically at 200
bar(barLeft, barTop, barLeft + BAR_WIDTH, barTop + BAR_HEIGHT); // Fill bar
rectangle(barLeft, barTop, barLeft + BAR_WIDTH, barTop + BAR_HEIGHT); // Border
outtextxy(barLeft + (BAR_WIDTH - textwidth("Start"))/2, barTop + 10, "Start"); // Center text

// Draw "History" bar with border
barTop = BAR_Y_HISTORY - BAR_HEIGHT/2;
bar(barLeft, barTop, barLeft + BAR_WIDTH, barTop + BAR_HEIGHT);
rectangle(barLeft, barTop, barLeft + BAR_WIDTH, barTop + BAR_HEIGHT);
outtextxy(barLeft + (BAR_WIDTH - textwidth("History"))/2, barTop + 10, "History");

// Draw "Exit" bar with border
barTop = BAR_Y_EXIT - BAR_HEIGHT/2;
bar(barLeft, barTop, barLeft + BAR_WIDTH, barTop + BAR_HEIGHT);
rectangle(barLeft, barTop, barLeft + BAR_WIDTH, barTop + BAR_HEIGHT);
outtextxy(barLeft + (BAR_WIDTH - textwidth("Exit"))/2, barTop + 10, "Exit");

        
}
