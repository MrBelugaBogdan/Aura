#ifndef AURA_H
#define AURA_H

// Оголошуємо функції, щоб файли "бачили" один одного
void print_char(char c, int row, int col, char color);
void clear_screen();
void check_keyboard();

#endif
void print_string(char* str, int row, int col, char color);
void start_shell();
void put_char(char c);
