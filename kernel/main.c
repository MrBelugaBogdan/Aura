#include "../include/aura.h"

void kmain() {
    clear_screen();
    print_string("--- AuraOS Core Initialized ---", 0, 25, 0x0B);
    cursor_y = 1;
    start_shell();
    
    while(1) {
        check_keyboard();
    }
}
