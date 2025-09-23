#ifndef LOG_H
#define LOG_H

#define SCREEN_WIDTH 80
#define VGA_BLACK   0x0
#define VGA_BLUE    0x1
#define VGA_GREEN   0x2
#define VGA_CYAN    0x3
#define VGA_RED     0x4
#define VGA_MAGENTA 0x5
#define VGA_BROWN   0x6
#define VGA_LIGHT_GREY 0x7
#define VGA_DARK_GREY  0x8
#define VGA_LIGHT_BLUE 0x9
#define VGA_LIGHT_GREEN 0xA
#define VGA_LIGHT_CYAN  0xB
#define VGA_LIGHT_RED   0xC
#define VGA_PINK        0xD
#define VGA_YELLOW      0xE
#define VGA_WHITE       0xF

VOID HalPrintString(const char *msg);
VOID HalPrintStringColor(const char *msg, int color);
VOID HalPanic_msg(const char *msg);
#endif
