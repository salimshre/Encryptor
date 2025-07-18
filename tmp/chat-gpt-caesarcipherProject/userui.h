#ifndef USERUI_H
#define USERUI_H

#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

void background_image();
void title();
void user_interference();
void run_cipher_interface();

#ifndef ENCRYPTION_H
#include "encryption.h"
#endif

#endif // USERUI_H
