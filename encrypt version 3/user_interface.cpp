#include "user_interface.h"
#include "core/encryption.h"
#include "core/history.h"
#include "ui/helpers.h"
#include "ui/animations.h"
#include <graphics.h>
#include <windows.h>
#include <conio.h>

using namespace encryption;
using namespace encryption::ui;

void show_message_box(const char* message) {
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(150, 500, 650, 540);
    rectangle(150, 500, 650, 540);
    outtextxy(160, 510, (char*)message);
}

void play_success_sound() {
    PlaySound("success.wav", NULL, SND_FILENAME | SND_ASYNC);
}

void play_error_sound() {
    PlaySound("error.wav", NULL, SND_FILENAME | SND_ASYNC);
}

void show_main_menu() {
    cleardevice();
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
                run_cipher_interface();
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

void run_cipher_interface() {
    cleardevice();
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    outtextxy(200, 100, (char*)"Select the file to encrypt/decrypt:");

    std::string filename = openFileDialog();
    if (filename.empty()) {
        show_message_box("No file selected. Returning...");
        delay(1000);
        show_main_menu();
        return;
    }

    FILE* f = fopen(filename.c_str(), "rb");
    if (!f) {
        play_error_sound();
        show_message_box("File not found or inaccessible.");
        delay(1500);
        show_main_menu();
        return;
    }
    fclose(f);

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

    show_loading_animation("Processing...");

    bool success = false;
    const int shift = 3;

    if (mode == 'e') {
        success = encryption::processFile(filename, true, shift);
        if (success) encryption::Logger::log("Encrypted", filename);
    } else {
        success = encryption::processFile(filename, false, shift);
        if (success) encryption::Logger::log("Decrypted", filename);
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

    FILE* f = fopen("history.txt", "r");
    if (!f) {
        outtextxy(100, 80, (char*)"No history available.");
        outtextxy(100, SCREEN_HEIGHT - 30, (char*)"Press any key to return.");
        getch();
        show_main_menu();
        return;
    }

    char line[256];
    int y = 80;
    while (fgets(line, sizeof(line), f) && y < SCREEN_HEIGHT - 50) {
        outtextxy(100, y, line);
        y += 20;
    }
    fclose(f);
    outtextxy(100, SCREEN_HEIGHT - 30, (char*)"Press any key to return to menu.");
    getch();
    show_main_menu();
}
