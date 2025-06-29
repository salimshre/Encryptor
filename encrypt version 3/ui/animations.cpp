#include "animations.h"
#include <graphics.h>
#include <cstring>
#include <windows.h>

namespace encryption {
namespace ui {

void show_loading_animation(const char* message) {
    int x = 200, y = 350;
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

    const int dotCount = 3;
    int frame = 0;

    bar(x, y, x + 400, y + 40);
    outtextxy(x, y, (char*)message);

    for (int i = 0; i < 15; ++i) {
        char dots[10] = { 0 };
        for (int d = 0; d <= frame % (dotCount + 1); ++d) {
            dots[d] = '.';
        }
        outtextxy(x + strlen(message) * 8, y, dots);
        delay(100);
        frame++;
    }

    bar(x, y, x + 400, y + 40);
}

} // namespace ui
} // namespace encryption