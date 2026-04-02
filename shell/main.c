#include "../include/aura.h"

char command_buffer[80];
int buffer_ptr = 0;

void start_shell() {
    print_string("\nAuraOS > ", cursor_y, 0, 0x0E);
    cursor_x = 9;
}

void execute_command(char* cmd) {
    cursor_y++;
    cursor_x = 0;

    if (compare_strings(cmd, "help")) {
        print_string("Commands: help, cls, ver, login, secret, logout", cursor_y++, 0, 0x07);
    } 
    else if (compare_strings(cmd, "cls")) {
        clear_screen();
    } 
    else if (compare_strings(cmd, "ver")) {
        print_string("AuraOS v0.1.0 (Kernel x86)", cursor_y++, 0, 0x03);
    }
    else if (compare_strings(cmd, "login")) {
        access_level = 1;
        print_string("Logged in as Root.", cursor_y++, 0, 0x0A);
    }
    else if (compare_strings(cmd, "secret")) {
        read_secret();
        cursor_y++;
    }
    else if (compare_strings(cmd, "logout")) {
        access_level = 0;
        print_string("Logged out.", cursor_y++, 0, 0x07);
    }
    else {
        print_string("Unknown command.", cursor_y++, 0, 0x0C);
    }
    
    start_shell();
}

void shell_input(char c) {
    if (c == '\n') {
        command_buffer[buffer_ptr] = '\0';
        execute_command(command_buffer);
        buffer_ptr = 0;
    } else if (c == '\b' && buffer_ptr > 0) {
        buffer_ptr--;
        put_char('\b');
    } else if (buffer_ptr < 79) {
        command_buffer[buffer_ptr++] = c;
        put_char(c);
    }
}
