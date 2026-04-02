#include "../include/aura.h"

void kmain() {
    clear_screen();
    
    // Гарний заголовок зверху
    print_string("--- AuraOS Kernel Loaded Successfully ---", 0, 20, 0x0A);
    
    // Запускаємо командний рядок
    start_shell();
    
    while(1) {
        check_keyboard();
        // Тут ми пізніше зробимо так, щоб символи з клавіатури з'являлися в shell
    }
}
