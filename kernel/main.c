// AuraOS Kernel Core
void kmain() {
    char* video = (char*)0xb8000;
    video[0] = 'A'; video[1] = 0x07; // Виведе букву A
    while(1);
}
