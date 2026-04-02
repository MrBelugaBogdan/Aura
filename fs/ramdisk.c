#include "../include/aura.h"

char secret_data[100] = "AuraOS_Root_Access_Granted_2026";
int access_level = 0;

void read_secret() {
    if (access_level == 1) {
        print_string("\nSystem Secret: ", 0, 0, 0x0A);
        print_string(secret_data, 0, 0, 0x07);
    } else {
        print_string("\nAccess Denied! Need 'login' first.", 0, 0, 0x0C);
    }
}
