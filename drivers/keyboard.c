// drivers/keyboard.c - Перший драйвер AuraOS

#include "../include/aura.h"

// Функція читання з порту (спілкування з залізом)
unsigned char inb(unsigned short port) {
    unsigned char ret;
    asm volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

// Головна функція опитування клавіатури
void check_keyboard() {
    // 0x64 - це порт статусу клавіатури в ПК
    if (inb(0x64) & 0x01) {
        unsigned char scancode = inb(0x60); // Отримуємо код натиснутої клавіші
        
        // Якщо натиснуто клавішу 'Q' (скан-код 0x10), виводимо щось
        if (scancode == 0x10) {
            // Тут пізніше додамо вивід на екран
        }
    }
}
