#include "../include/aura.h"

char command_buffer[80];
int buffer_ptr = 0;

void execute_command(char* cmd) {
    if (compare_strings(cmd, "help")) {
        print_string("\nCommands: help, cls, ver, sysinfo", 0, 0, 0x07);
    } 
    else if (compare_strings(cmd, "cls")) {
        clear_screen();
        cursor_y = 0; // Повертаємо курсор вгору
    } 
    else if (compare_strings(cmd, "ver")) {
        print_string("\nAuraOS Kernel v0.1.0 (Stable Edition)", 0, 0, 0x03);
    }
    else if (compare_strings(cmd, "sysinfo")) {
        print_string("\nCPU: x86 Mode | RAM: 640KB Base | Arch: Monolithic", 0, 0, 0x0B);
    }
    else {
        print_string("\nUnknown command. Type 'help'.", 0, 0, 0x0C); // Червона помилка
    }
    
    print_string("\nAuraOS > ", 0, 0, 0x0E);
}

// Додаємо символ у буфер
void shell_input(char c) {
    if (c == '\n') {
        command_buffer[buffer_ptr] = '\0'; // Закриваємо рядок
        execute_command(command_buffer);
        buffer_ptr = 0; // Очищуємо буфер для нової команди
    } else if (c == '\b' && buffer_ptr > 0) { // Backspace
        buffer_ptr--;
    } else {
        command_buffer[buffer_ptr++] = c;
        put_char(c);
    }
}
