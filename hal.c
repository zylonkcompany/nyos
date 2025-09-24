#include <common.h>
#include <log.h>
#include <stdint.h>

static unsigned int *heap_ptr = (unsigned int*)0x100000;
static unsigned char *video = (unsigned char*) 0xB8000;
static int cursor = 0;

static inline uint64_t HalReadTsc(){
    uint32_t lo, hi;
    __asm__ volatile("rdtsc" : "=a"(lo), "=d"(hi));
    return ((uint64_t)hi << 32) | lo;
}

void HalPrintString(const char *msg){
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

void HalPrintStringColor(const char *msg, int color){
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

void HalPanicMessage(const char *msg){
       while(*msg){
        if(*msg == '\n'){         
            cursor = (cursor / SCREEN_WIDTH + 1) * SCREEN_WIDTH; 
            msg++;
            continue;
        }
        video[cursor * 2]     = *msg++;      
        video[cursor * 2 + 1] = VGA_RED;       
        cursor++;
    }

}

void HalSystemDelay(uint32_t ms, uint32_t cpu_freq_mhz){
    uint64_t cycles_to_wait = (uint64_t)cpu_freq_mhz * 1000 * ms;
    uint64_t start = HalReadTsc();
    while(HalReadTsc() - start < cycles_to_wait){
        __asm__ volatile("pause");
    }
}
unsigned int* HalMalloc(unsigned int size){
    unsigned int* allocated = heap_ptr;               
    heap_ptr += (size + sizeof(unsigned int) - 1) / sizeof(unsigned int);
    HalPrintString("Alloc Memory Success!\n");
    return allocated;                                
}

void HalClearInt(){
    __asm__ volatile("cli");
}

void HalStartInt(){
    __asm__ volatile("sti");
}

void HalIdle(){
    for(;;){
        __asm__ volatile ("hlt");
    }
}

