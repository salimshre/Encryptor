#include <graphics.h>
#include <conio.h>
#include "userui.h"
#include <iostream>
#include <string>
#include "encryption.h"

using namespace std;

int main(int argc, char const *argv[]) {
    int x, y;

    initwindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Encryption Tool");

    user_interference();

    while (!kbhit()) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            clearmouseclick(WM_LBUTTONDOWN);

            if (x >= 300 && x <= 500 && y >= 180 && y <= 220) {
                run_cipher_interface();
            } else if (x >= 300 && x <= 500 && y >= 280 && y <= 320) {
                outtextxy(100, 500, (char*)"History feature coming soon...");
            } else if (x >= 300 && x <= 500 && y >= 380 && y <= 420) {
                outtextxy(100, 500, (char*)"Exiting...");
                delay(1000);
                closegraph();
                exit(0);
            }

            char coord[50];
            sprintf(coord, "You clicked at: %d, %d", x, y);
            settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
            outtextxy(100, 150, coord);
        }
    }

    getch();
    closegraph();
    return 0;
}

void background_image() {
    readimagefile("background.bmp", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void title() {
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(100, 60, 700, 130);
    settextstyle(SIMPLEX_FONT, HORIZ_DIR, 4);
    outtextxy(300, 60, (char*)"Encryption");
}

void user_interference() {
    background_image();
    title();

    const int BAR_WIDTH = 200, BAR_HEIGHT = 40;
    const int BAR_Y_START = 200, BAR_Y_HISTORY = 300, BAR_Y_EXIT = 400;
    settextstyle(SIMPLEX_FONT, HORIZ_DIR, 4);
    setcolor(WHITE);

    int barLeft = (SCREEN_WIDTH - BAR_WIDTH) / 2;
    int barTop;

    barTop = BAR_Y_START - BAR_HEIGHT/2;
    bar(barLeft, barTop, barLeft + BAR_WIDTH, barTop + BAR_HEIGHT);
    rectangle(barLeft, barTop, barLeft + BAR_WIDTH, barTop + BAR_HEIGHT);
    outtextxy(barLeft + (BAR_WIDTH - textwidth("Start"))/2, barTop + 10, "Start");

    barTop = BAR_Y_HISTORY - BAR_HEIGHT/2;
    bar(barLeft, barTop, barLeft + BAR_WIDTH, barTop + BAR_HEIGHT);
    rectangle(barLeft, barTop, barLeft + BAR_WIDTH, barTop + BAR_HEIGHT);
    outtextxy(barLeft + (BAR_WIDTH - textwidth("History"))/2, barTop + 10, "History");

    barTop = BAR_Y_EXIT - BAR_HEIGHT/2;
    bar(barLeft, barTop, barLeft + BAR_WIDTH, barTop + BAR_HEIGHT);
    rectangle(barLeft, barTop, barLeft + BAR_WIDTH, barTop + BAR_HEIGHT);
    outtextxy(barLeft + (BAR_WIDTH - textwidth("Exit"))/2, barTop + 10, "Exit");
}

void run_cipher_interface() {
    string filename;
    char mode;
    closegraph();

    cout << "Enter the filename: ";
    getline(cin >> ws, filename);
    cout << "Encrypt (e) or Decrypt (d)? ";
    cin >> mode;

    bool success = false;
    if (mode == 'e' || mode == 'E') {
        success = encryptFile(filename, true);
    } else if (mode == 'd' || mode == 'D') {
        success = encryptFile(filename, false);
    } else {
        cerr << "Invalid mode selected." << endl;
    }

    if (success) cout << "Operation completed successfully." << endl;
    else          cerr << "Error: Unable to perform operation." << endl;

    initwindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Encryption Tool");
    user_interference();
}
