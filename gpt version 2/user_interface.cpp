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
    //closegraph();

    string filename;
    char mode;
    cout << "Enter the filename: ";
    getline(cin >> ws, filename);

    ifstream test(filename);
    if (!test) {
        play_error_sound();
        cout << "File not found." << endl;
        getch();
        //initwindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Encryption Tool");
        show_main_menu(); // return to menu
        return;
    }

    cout << "Encrypt (e) or Decrypt (d)? ";
    cin >> mode;

    bool success = false;
    if (mode == 'e' || mode == 'E') {
        success = encryptFile(filename, true);
        if (success) logHistory("Encrypted", filename);
    } else if (mode == 'd' || mode == 'D') {
        success = encryptFile(filename, false);
        if (success) logHistory("Decrypted", filename);
    } else {
        cout << "Invalid option." << endl;
    }

    if (success) {
        cout << "Operation successful." << endl;
        play_success_sound();
    } else {
        cout << "Operation failed." << endl;
        play_error_sound();
    }

    getch(); //wait for key press
    show_main_menu();  // 🔁 Return to main menu
    //initwindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Encryption Tool");
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
    show_main_menu();  // 🔁 Return to main menu    
}

void play_success_sound() {
    PlaySound("success.wav", NULL, SND_FILENAME | SND_ASYNC);
}

void play_error_sound() {
    PlaySound("error.wav", NULL, SND_FILENAME | SND_ASYNC);
}