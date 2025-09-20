#include <common.h>
#include <log.h>

unsigned char *video = (unsigned char*) 0xB8000;
int cursor = 0;


#define SCREEN_WIDTH 80
VOID log(const char *msg){
    while(*msg){
        if(*msg == '\n'){         
            cursor = (cursor / SCREEN_WIDTH + 1) * SCREEN_WIDTH;  // próximo início de linha
            msg++;
            continue;
        }
        video[cursor * 2]     = *msg++;        // caractere
        video[cursor * 2 + 1] = VGA_GREEN;     // cor
        cursor++;
    }
}

VOID log_color(const char *msg, int color){
    while(*msg){
        if(*msg == '\n'){         
            cursor = (cursor / SCREEN_WIDTH + 1) * SCREEN_WIDTH;  // próximo início de linha
            msg++;
            continue;
        }
        video[cursor * 2]     = *msg++;      
        video[cursor * 2 + 1] = color;       
        cursor++;
    }
}
