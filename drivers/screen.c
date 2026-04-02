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
