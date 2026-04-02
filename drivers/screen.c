#include "../include/aura.h"

int cursor_x = 0;
int cursor_y = 0;

void print_char(char c, int row, int col, char color) {
    char* video_memory = (char*)0xb8000;
    int offset = (row * 80 + col) * 2;
    video_memory[offset] = c;
    video_memory[offset + 1] = color;
}

void print_string(char* str, int row, int col, char color) {
    for (int i = 0; str[i] != '\0'; i++) {
        print_char(str[i], row, col + i, color);
    }
}

void put_char(char c) {
    if (c == '\n') {
        cursor_x = 0;
        cursor_y++;
    } else if (c == '\b') { // Backspace
        if (cursor_x > 0) cursor_x--;
        print_char(' ', cursor_y, cursor_x, 0x07);
    } else {
        print_char(c, cursor_y, cursor_x, 0x0F);
        cursor_x++;
        if (cursor_x >= 80) {
            cursor_x = 0;
            cursor_y++;
        }
    }
}

void clear_screen() {
    for (int i = 0; i < 80 * 25; i++) {
        print_char(' ', i / 80, i % 80, 0x07);
    }
    cursor_x = 0;
    cursor_y = 0;
}

int compare_strings(char* s1, char* s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) return 0;
        i++;
    }
    return (s1[i] == s2[i]);
}
