#include "user_interface.h"

int main() {
    initwindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Encryption Tool");
    show_main_menu();
    closegraph();
    return 0;
}