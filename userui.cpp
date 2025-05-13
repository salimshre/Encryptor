#include <graphics.h>
#include <conio.h>

int main(int argc, char const *argv[]) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"hello");
    circle(320, 240, 200);

    



    int x, y;

    // Initialize graphics window
    initwindow(800, 600, "Mouse Coordinate Tester");

    // Instructions
    outtextxy(100, 100, "Click anywhere in the window to get an coordinates...");
    outtextxy(100, 120, "Press any key to stop.");

    // Wait for mouse click
    while (!kbhit()) { //this looop continues untill the key is pressed.
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y); // Get mouse click coordinates
            clearmouseclick(WM_LBUTTONDOWN);     // Clear the click event
            // Display coordinates
            char coord[50];
            sprintf(coord, "You clicked at: %d, %d", x, y);
            outtextxy(100, 150, coord);
        }
    }



    

    getch();
    closegraph();
    return 0;
}