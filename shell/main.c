// shell/main.c - Командна оболонка AuraOS

#include "../include/aura.h"

void start_shell() {
    print_string("AuraOS 1 > ", 1, 0, 0x0E); // Жовте запрошення на новому рядку
}

// Допоміжна функція для друку цілих рядів (додай її в drivers/screen.c пізніше)
void print_string(char* str, int row, int col, char color) {
    for (int i = 0; str[i] != '\0'; i++) {
        print_char(str[i], row, col + i, color);
    }
}
