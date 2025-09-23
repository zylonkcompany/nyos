#include <common.h>
#include <log.h>
#include <stddef.h>

#define SYSTEM_RESERVED_MEM 0x200000

#define SYSTEM_RESERVED_MEM 0x200000


int init(){
    HalClearInt();
    HalPrintString("Preparing the system...\n");
    HalPrintString("Initializing...\n");
    int *sys_res = HalMalloc(SYSTEM_RESERVED_MEM);
    if(sys_res == NULL){
        HalPanicMessage("Fault in alloc system reserved memory!\n");
        return ERROR;
    }
  
    return SUCCESS;
}

int kmain(){
    if(init() != SUCCESS){
        HalPanicMessage("System Fault!\n");
        HalIdle();
        return ERROR;
    }
    HalPrintString("Hello! Welcome to NyOS\n");

    HalIdle();
}
