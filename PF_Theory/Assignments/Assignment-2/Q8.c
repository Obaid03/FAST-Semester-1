/*
Name: Iqra Ashraf
Roll No: 24K-0952
Problem: 8
*/

#include <stdio.h>

int BINtoDEC(int num);

int DECtoBIN(int num);
void DECtoHEX(int num);
void HEXtoDEC(char hexNum[]);
void BINtoHEX(int num);
void HEXtoBIN(char hexNum[]);

int main() {
    int type,num;
    char hexNum[20];

    while (1) {
        printf("1. Binary to Decimal\n");
        printf("2. Decimal to Binary\n");
        printf("3. Decimal to Hexadecimal\n");
        printf("4. Hexadecimal to Decimal\n");
        printf("5. Binary to Hexadecimal\n");
        printf("6. Hexadecimal to Binary\n");
        printf("7. Exit\n");
        printf("Enter the type of conversion: ");
        scanf("%d",&type);

        switch(type){
            case 1:
                printf("Enter a binary number: ");
                scanf("%d",&num);
                printf("Decimal Number: %d\n",BINtoDEC(num));
                break;
            case 2:
                printf("Enter a decimal number: ");
                scanf("%d",&num);
                printf("Binary Number: %d\n",DECtoBIN(num));
                break;
            case 3:
                printf("Enter a decimal number: ");
                scanf("%d",&num);
                DECtoHEX(num);
                break;
            case 4:
                printf("Enter a hexadecimal number: ");
                scanf("%s",hexNum);
                HEXtoDEC(hexNum);
                break;
            case 5:
                printf("Enter a binary number: ");
                scanf("%d",&num);
                BINtoHEX(num);
                break;
            case 6:
                printf("Enter a hexadecimal number: ");
                scanf("%s",hexNum);
                HEXtoBIN(hexNum);
                break;
            case 7:
                printf("Exiting the program.");
                return 0;
            default:
                printf("Input invalid. Please try again:(");
        }
    }
    return 0;
}

int BINtoDEC(int num) {
    int decimal=0,base=1,digit;
    while (num>0) {
        digit=num%10;
        num=num/10;
        decimal+=digit*base;
        base*=2;
    }
    return decimal;
}

int DECtoBIN(int num) {
    int binary=0,base=1;
    while (num>0) {
        binary+=(num%2)*base;
        num/=2;
        base*=10;
    }
    return binary;
}

void DECtoHEX(int num) {
    char hex[20];
    int i=0;
    int j;
    while (num!=0) {
        int temp=num%16;
        if (temp<10){
        	hex[i]=temp+48;
		}else{
			hex[i]=temp+55;
		}
        num/=16;
        i++;
    }
    hex[i]='\0';
    
    for (j=0; j<i/2; j++) {
        char temp=hex[j];
        hex[j]=hex[i-j-1];
        hex[i-j-1]=temp;
    }

    printf("Hexadecimal Number: %s\n",hex);
}

void HEXtoDEC(char hexNum[]) {
    int decimal=0,base=1,length=0;
    while (hexNum[length] != '\0') {
        length++;
    }
    int i;
    for (i= length-1; i>=0; i--) {
        if (hexNum[i]>='0' && hexNum[i]<='9') {
            decimal+=(hexNum[i]-48)*base;
        } else if (hexNum[i]>='A' && hexNum[i]<='F') {
            decimal+=(hexNum[i]-55)*base;
        } else {
            printf("Input invalid.\n");
            return;
        }
        base*=16;
    }
    printf("Decimal number: %d\n", decimal);
}

void BINtoHEX(int num) {
    int decimal=BINtoDEC(num);
    DECtoHEX(decimal);
}

// Function to convert hexadecimal to binary
void HEXtoBIN(char hexNum[]) {
	int decimal=0,base=1,length=0;
    while (hexNum[length]!='\0') {
        length++;
    }
    int i;
    int j;
    for (i=length-1; i>=0; i--){
        if (hexNum[i]>='0' && hexNum[i]<='9') {
            decimal+=(hexNum[i]-48)*base;
        } else if(hexNum[i]>='A' && hexNum[i]<='F') {
            decimal+=(hexNum[i]-55)*base;
        } else{
            printf("Input invalid.\n");
            return;
        }
        base *= 16;
    }
    char binary[60];
    int index=0;

    if (decimal==0) {
        printf("Binary Number: 0\n");
        return;
    }
    while(decimal>0) {
        binary[index++]=(decimal%2)+'0';
        decimal/=2;
    }
    binary[index]='\0';
    for (j=0; j<index/2; j++) {
        char temp=binary[j];
        binary[j]=binary[index-j-1];
        binary[index-j-1] = temp;
    }
    printf("Binary Number: %s\n", binary);
}
