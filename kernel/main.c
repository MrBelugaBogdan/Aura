#include "../include/aura.h"

void kmain() {
    clear_screen();
    
    // Виводимо назву системи
    print_char('A', 0, 0, 0x0B);
    print_char('u', 0, 1, 0x0B);
    print_char('r', 0, 2, 0x0B);
    print_char('a', 0, 3, 0x0B);
    
    while(1) {
        check_keyboard(); // Система постійно стежить за клавіатурою
    }
}
