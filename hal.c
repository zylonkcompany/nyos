#include <common.h>
#include <log.h>
#include <stdint.h>

static unsigned int *heap_ptr = (unsigned int*)0x100000;
static unsigned char *video = (unsigned char*) 0xB8000;
static int cursor = 0;

VOID HalPrintString(const char *msg){
    while(*msg){
        if(*msg == '\n'){         
            cursor = (cursor / SCREEN_WIDTH + 1) * SCREEN_WIDTH; 
            msg++;
            continue;
        }
        video[cursor * 2]     = *msg++;        
        video[cursor * 2 + 1] = VGA_GREEN;   
        cursor++;
    }
}

VOID HalPrintStringColor(const char *msg, int color){
    while(*msg){
        if(*msg == '\n'){         
            cursor = (cursor / SCREEN_WIDTH + 1) * SCREEN_WIDTH; 
            msg++;
            continue;
        }
        video[cursor * 2]     = *msg++;      
        video[cursor * 2 + 1] = color;       
        cursor++;
    }
}


VOID HalSystemDelay(int ms){
    for(int i = 0; i < ms * 1000; i++){
        __asm__ volatile("pause");
    }
}

unsigned int* HalMalloc(unsigned int size){
    unsigned int* allocated = heap_ptr;               
    heap_ptr += (size + sizeof(unsigned int) - 1) / sizeof(unsigned int);
    HalPrintString("Alloc Memory Success!\n");
    return allocated;                                
}

VOID HalClearInt(){
    __asm__ volatile("cli");
}

VOID HalStartInt(){
    __asm__ volatile("sti");
}

VOID HalIdle(){
    for(;;){
        __asm__ volatile ("hlt");
    }
}

