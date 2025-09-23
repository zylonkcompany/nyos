#include <common.h>
#include <log.h>
#include <stddef.h>

int init(){
    HalClearInt();
    HalPrintString("Preparing the system...\n");
    HalPrintString("Initializing...\n");
    int *sys_res = HalMalloc(0x200000);
    if(*sys_res == NULL){
        HalPanicMessage("Fault in alloc system reserved memory!\n");
        return ERROR;
    }
  
    return SUCCESS;
}

void kmain(){
    if(init() != SUCCESS){
        HalPanicMessage("System Fault!\n");
        HalIdle();
        return ERROR;
    }
    HalPrintString("Hello! Welcome to NyOS\n");

    HalIdle();
}
