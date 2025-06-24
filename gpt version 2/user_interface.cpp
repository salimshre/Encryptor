#include "user_interface.h"
#include "encryption.h"
#include "history.h"
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <fstream>
using namespace std;

void show_message_box(const char* message) {
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(150, 500, 650, 540);
    rectangle(150, 500, 650, 540);
    outtextxy(160, 510, (char*)message);
}

std::string get_text_input(int x, int y, int maxLength = 100) {
    std::string input;
    char ch;

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, BLACK);
    bar(x - 2, y - 2, x + 400, y + 30); // input box background

    while (true) {
        ch = getch();

        if (ch == 13) break; // Enter key
        else if (ch == 8 && !input.empty()) { // Backspace
            input.pop_back();
        } else if (isprint(ch) && input.length() < maxLength) {
            input += ch;
        }

        // Redraw input
        bar(x, y, x + 400, y + 30);  // clear input area
        outtextxy(x, y, (char*)input.c_str());
    }

    return input;
}

void show_main_menu() {
    cleardevice();  // Clear screen once
    readimagefile("background.bmp", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    setbkcolor(BLACK);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    outtextxy(300, 100, (char*)"Encryption Tool");

    bar(300, 180, 500, 220); rectangle(300, 180, 500, 220); outtextxy(340, 190, (char*)"Start");
    bar(300, 280, 500, 320); rectangle(300, 280, 500, 320); outtextxy(340, 290, (char*)"History");
    bar(300, 380, 500, 420); rectangle(300, 380, 500, 420); outtextxy(340, 390, (char*)"Exit");

    int x, y;
    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            clearmouseclick(WM_LBUTTONDOWN);

            if (x >= 300 && x <= 500 && y >= 180 && y <= 220) {
                run_cipher_interface("");
                return;
            } else if (x >= 300 && x <= 500 && y >= 280 && y <= 320) {
                show_history_screen();
                return;
            } else if (x >= 300 && x <= 500 && y >= 380 && y <= 420) {
                show_message_box("Exiting...");
                delay(1000);
                return;
            }
        }
    }
}

void run_cipher_interface(const string& unused) {
    cleardevice();
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    outtextxy(200, 100, (char*)"Enter the filename:");

    string filename = get_text_input(200, 150);

    ifstream test(filename);
    if (!test) {
        play_error_sound();
        show_message_box("File not found. Press any key...");
        getch();
        show_main_menu();
        return;
    }

    // Draw Encrypt and Decrypt buttons
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(200, 220, (char*)"Choose operation:");

    bar(200, 260, 400, 300); rectangle(200, 260, 400, 300); outtextxy(250, 270, (char*)"Encrypt");
    bar(420, 260, 620, 300); rectangle(420, 260, 620, 300); outtextxy(470, 270, (char*)"Decrypt");

    int x, y;
    char mode = 0;
    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            clearmouseclick(WM_LBUTTONDOWN);

            if (x >= 200 && x <= 400 && y >= 260 && y <= 300) {
                mode = 'e';
                break;
            } else if (x >= 420 && x <= 620 && y >= 260 && y <= 300) {
                mode = 'd';
                break;
            }
        }
    }

    bool success = false;
    if (mode == 'e') {
        success = encryptFile(filename, true);
        if (success) logHistory("Encrypted", filename);
    } else {
        success = encryptFile(filename, false);
        if (success) logHistory("Decrypted", filename);
    }

    if (success) {
        show_message_box("Operation successful! Press any key...");
        play_success_sound();
    } else {
        show_message_box("Operation failed. Press any key...");
        play_error_sound();
    }

    getch();
    show_main_menu();
}

void show_history_screen() {
    cleardevice();
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(300, 30, (char*)"History Log");

    ifstream infile("history.txt");
    string line;
    int y = 80;
    while (getline(infile, line) && y < SCREEN_HEIGHT - 50) {
        outtextxy(100, y, (char*)line.c_str());
        y += 20;
    }
    outtextxy(100, SCREEN_HEIGHT - 30, (char*)"Press any key to return to menu.");
    getch();
    show_main_menu();
}

void play_success_sound() {
    PlaySound("success.wav", NULL, SND_FILENAME | SND_ASYNC);
}

void play_error_sound() {
    PlaySound("error.wav", NULL, SND_FILENAME | SND_ASYNC);
}
