/*
2. BCD to Decimal:
https://1.bp.blogspot.com/-Tfj_D_f_AF0/VZO5QIIGAUI/AAAAAAAAAmI/5Rw6uIU3EiI/s1600/DS1307%2BTime%2BKeeper%2BRegister.PNG

DS1307 has its time registers in BCD format as shown in the image found in the above link, To set the time we need to convert the decimal number to BCD format, hence, write a fucntion to convert decimal to BCD

Concepts to be used.
- Operators
- Preprocessor
*/

#include <stdio.h>
#define DEC_TO_BCD(dec) (((dec / 10) << 4) | (dec % 10))

void decimal_to_bcd(unsigned char *bcd, unsigned char decimal) {
    *bcd = DEC_TO_BCD(decimal);
}


int main() {
    unsigned char decimal = 45;  
    unsigned char bcd;
    printf("Decimal number: %d\n", decimal);
    decimal_to_bcd(&bcd, decimal);
    printf("BCD number: 0x%02X\n", bcd);

    return 0;
}
