#include "gba.h"

void synch()
{
    while(REG_DISPLAY_VCOUNT >= 160);
    while(REG_DISPLAY_VCOUNT < 160);
}

void drawRect(struct Rect r, uint16 color)
{
    for(int i = 0; i < r.h; i++)
    {
        for(int j = 0; j < r.w; j++)
        {
            SCREENBUFFER[SCREEN_WIDTH * (i + r.y) + (j + r.x)] = color;
        }
    }
}

void initRects()
{
    goal1Top.w = goal1Bot.w = goal2Top.w = goal2Bot.w = 8;
    goal1Top.h = goal1Bot.h = goal2Top.h = goal2Bot.h = 50;

    goal1Top.x = goal1Bot.x = 0;
    goal2Top.x = goal2Bot.x = SCREEN_WIDTH - 8;

    goal1Top.y = goal2Top.y = 0;
    goal1Bot.y = goal2Bot.y = goal1Top.h + 60;
}

int main()
{
    REG_DISPLAY = VIDEOMODE | BGMODE;

    initRects();

    int speedX = 0;
    int speedY = 0;

    return 0;
}