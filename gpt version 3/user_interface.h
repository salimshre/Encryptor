#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

void show_main_menu();
void run_cipher_interface();
void show_history_screen();
void show_message_box(const char* message);
void play_success_sound();
void play_error_sound();

#endif // USER_INTERFACE_H