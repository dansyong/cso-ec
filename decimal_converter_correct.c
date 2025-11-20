#include <stdio.h>

int main () {
    int decimalNumber;
    printf("Please input a POSITIVE decimal number to be converted to hexadecimal and binary:");
    scanf("%d", &decimalNumber);
    char binary[500],hexadecimal[100];
    int i = 0,j = 0;
    int temp = decimalNumber;
    
    if (temp == 0) {
        printf("Hexadecimal = 0\n");
        printf("Binary = 0\n");
        return 0;
    }
    
    while (temp > 0) {
        int remainder = temp % 16;
        // In the wrong version, the remainder is changed to 'remainder <= 10' which is a logic error。
        // Only 0-9 should be handled this way.
        if (remainder < 10) { 
            hexadecimal[i] = remainder + '0';
        } else {
            hexadecimal[i] = remainder - 10 + 'A';
        }
        temp /= 16;
        i++;
    }
    
    // In the error version, the line 'temp = decimalNumber;' was deleted here, causing incorrect results for binary conversion.
    temp = decimalNumber; 
    
    while (temp > 0) {
        int remainder = temp % 2;
        if (remainder == 1) {
            binary[j] = '1';
        } else {
            binary[j] = '0';
        }
        temp /= 2;
        // In the error version, the line 'j++;' was deleted here, causing an infinite loop.
        j++; 
    }
    
    printf("hexadecimal conversion = ");
    // In the incorrect version, the loop starts with 'int k = i' and the condition is 'k >= 0' (logical error).
    // The correct start is i-1, and it ends at k >= 0 (i.e., index 0).
    for(int k = i -1; k >=0; k --){
        printf("%c",hexadecimal[k]);
    }
    printf("\n");
    
    printf("binary conversion = ");
    for(int k = j -1; k >=0; k--){
        printf("%c",binary[k]);
    }
    printf("\n");
    return 0;
}