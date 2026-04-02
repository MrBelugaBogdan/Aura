#ifndef AURA_H
#define AURA_H

// --- Екран та друк ---
void print_char(char c, int row, int col, char color);
void print_string(char* str, int row, int col, char color);
void put_char(char c);
void clear_screen();
extern int cursor_y;
extern int cursor_x;

// --- Залізо (Порти та Клавіатура) ---
unsigned char inb(unsigned short port);
void check_keyboard();

// --- Ядро та Shell ---
void start_shell();
void shell_input(char c);
void execute_command(char* cmd);
int compare_strings(char* s1, char* s2);

// --- Безпека та RAM-диск ---
void read_secret();
extern int access_level;

#endif
