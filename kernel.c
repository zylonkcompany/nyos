
#include <common.h>
#include <log.h>

VOID delay(int ms){
    for(int i = 0; i < ms * 1000; i++){
        __asm__ volatile("pause");
    }
}

unsigned int* kmalloc(unsigned int addr){
    unsigned int *heap_ptr = (unsigned int*)0x100000;
    heap_ptr += addr / sizeof(unsigned int);
    unsigned int* allocated = heap_ptr;
    log("Alloc Memory Sucess!\n");
    return allocated;
}

int init(){
    __asm__ volatile("cli");
    log("Preparing the system...\n");
    delay(16);
    log("Initializing...\n");
    kmalloc(0x200000);
    delay(16);
    log("Hello! Welcome to NyOS\n");
  
    return SUCESS;
}

int kmain(){
    init();
    for(;;){
       hlt;
    }
}