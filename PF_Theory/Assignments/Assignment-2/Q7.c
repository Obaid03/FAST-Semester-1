/*
Name: Iqra Ashraf
Roll No: 24K-0952
Problem: 7
*/

#include <stdio.h>
#include <string.h>

void inputArray(char arr[6][5]) {
    int i;
	int j;
    for (i=0; i<4; i++) {
        for (j=0; j<5; j++) {
            printf("Enter character [%d][%d]: ",i,j);
            scanf(" %c",&arr[i][j]);
        }
}
    arr[4][0] = '0';
    arr[4][1] = '9'; 
    arr[4][2] = '5';
    arr[4][3] = '2';
    arr[4][4] = 'i';
}

int findString(char arr[6][5],char str[]) {
    int length=strlen(str);
    int i;
	int j;
	int k;
    for (i=0; i<6; i++) {
        for (j=0; j<=5-length; j++) {
            int found=1;
            for (k=0; k<length; k++) {
                if (arr[i][j+k] != str[k]) {
                    found=0;
                    break;
                }
            }
            if(found){
            	return 1;
			}
        }
    }
    for (j=0; j<5; j++) {
        for (i=0; i<=6-length; i++) {
            int found=1;
            for (k=0; k<length; k++) {
                if (arr[i+k][j] != str[k]) {
                    found=0;
                    break;
                }
            }
            if(found){
            	return 1;
			}
        }
    }

    return 0;
}

int main() {
    char arr[6][5];
    int score=0;
    char findStr[20];

        inputArray(arr);
        int i;
        int j;
        for (i=0; i<6; i++) {
        	printf("|");
            for (j=0; j<5; j++) {
                printf("%c|",arr[i][j]);
            }
            printf("\n");
        }
       while(1){
        printf("Find string or Enter 'x' to stop: ");
        scanf("%s",findStr);

        if (strcmp(findStr,"x")==0) {
            break;
        }
        if(findString(arr,findStr)) {
            printf("%s is present\n",findStr);
            score++;
        } else {
            printf("%s is not present\n",findStr);
            score--;
        }
        printf("Score: %d\n",score);
    }printf("Total Score: %d",score);

    return 0;
}
