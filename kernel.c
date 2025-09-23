#include <common.h>
#include <log.h>

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
    HalIdle();
}
