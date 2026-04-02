// drivers/screen.c - Вивід тексту AuraOS

void print_char(char c, int row, int col, char color) {
    // Рахуємо позицію: 80 стовпчиків у ряду, кожен символ займає 2 байти
    char* video_memory = (char*)0xb8000;
    int offset = (row * 80 + col) * 2;
    
    video_memory[offset] = c;
    video_memory[offset + 1] = color;
}

void clear_screen() {
    for (int i = 0; i < 80 * 25; i++) {
        print_char(' ', i / 80, i % 80, 0x07);
    }
}
int cursor_x = 0;
int cursor_y = 1; // Починаємо з другого рядка, бо перший — заголовок

void put_char(char c) {
    if (c == '\n') { // Перехід на новий рядок
        cursor_x = 0;
        cursor_y++;
    } else {
        print_char(c, cursor_y, cursor_x, 0x0F); // Білий текст
        cursor_x++;
        if (cursor_x >= 80) { // Якщо рядок закінчився
            cursor_x = 0;
            cursor_y++;
        }
    }
}
int compare_strings(char* s1, char* s2) {
    int i = 0;
    while (s1[i] == s2[i]) {
        if (s1[i] == '\0') return 1;
        i++;
    }
    return 0;
}
