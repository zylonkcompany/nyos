#include <common.h>
#include <log.h>

<<<<<<< Updated upstream
VOID delay(int ms){
    for(int i = 0; i < ms * 1000; i++){
        __asm__ volatile("pause");
    }
}

unsigned int *heap_ptr = (unsigned int*)0x100000;

unsigned int* kmalloc(unsigned int size){
    unsigned int* allocated = heap_ptr;               
    heap_ptr += (size + sizeof(unsigned int) - 1) / sizeof(unsigned int);
    log("Alloc Memory Success!\n");
    return allocated;                                
}

=======
>>>>>>> Stashed changes
int init(){
    HalClearInt();
    HalPrintString("Preparing the system...\n");
    HalSystemDelay(16);
    HalPrintString("Initializing...\n");
    void *sys_res = HalMalloc(0x200000);
    HalSystemDelay(16);
    HalPrintString("Hello! Welcome to NyOS\n");
  
    return SUCCESS;
}

void kmain(){
    init();
<<<<<<< Updated upstream
    for(;;){
       hlt;
    }
}
=======
    HalIdle();
}
>>>>>>> Stashed changes
