#include <stdio.h>
int main () {
    int decimalNumber;
    printf("please input a decimal number to be converted to hexadecimal and binary:");
    scanf("%d", &decimalNumber);
    char binary[500],hexadecimal[100];
    int i = 0,j = 0;
    int temp = decimalNumber;
    
    if(temp == 0){
        printf("Hexadecimal = 0\n");
        printf("Binary = 0\n");
        return 0;
    }
    while(temp > 0){
        int remainder = temp % 16;
        if(remainder < 10){
            hexadecimal[i] = remainder + '0';
        }
        else{
            hexadecimal[i] = remainder - 10 + 'A';
        }
        temp /= 16;
        i++;
    }
    temp = decimalNumber;
    while(temp > 0){
        int remainder = temp % 2;
        if(remainder == 1){
            binary[j] = '1';
        }
        else{
            binary[j] = '0';
        }
        temp /= 2;
        j++;
    }
    printf("hexadecimal conversion = ");
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
