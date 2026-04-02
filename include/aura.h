#ifndef AURA_H
#define AURA_H

// Налаштування екрана та друку
void print_char(char c, int row, int col, char color);
void print_string(char* str, int row, int col, char color);
void put_char(char c);
void clear_screen();
extern int cursor_y; 

// Робота з залізом (Клавіатура)
void check_keyboard();
unsigned char inb(unsigned short port);

// Логіка системи (Shell)
void start_shell();
void shell_input(char c);
int compare_strings(char* s1, char* s2);

#endif
