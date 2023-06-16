/*
1. Bit Operations:
https://1.bp.blogspot.com/-Tfj_D_f_AF0/VZO5QIIGAUI/AAAAAAAAAmI/5Rw6uIU3EiI/s1600/DS1307%2BTime%2BKeeper%2BRegister.PNG

DS1307 has its time registers in BCD format as shown in the image found in the above link, so 
a. Write a function to Set, clear and toggle bit of an 8-bit number

Concepts to be used.
- Operators
*/
#include <stdio.h>
void set_bit(unsigned char *num, int bit_position) {
    *num |= (1 << bit_position);
}
void clear_bit(unsigned char *num, int bit_position) {
    *num &= ~(1 << bit_position);
}
void toggle_bit(unsigned char *num, int bit_position) {
    *num ^= (1 << bit_position);
}

int main() {

    unsigned char num = 0b01010101; // 8-bit number
    printf("Initial number: 0x%02X\n", num);

    set_bit(&num, 3);
    printf("After setting bit 3: 0x%02X\n", num);

    clear_bit(&num, 5);
    printf("After clearing bit 5: 0x%02X\n", num);

    toggle_bit(&num, 2);
    printf("After toggling bit 2: 0x%02X\n", num);

    return 0;
}
