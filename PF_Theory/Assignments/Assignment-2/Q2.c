/*
Name: Iqra Ashraf
Roll No: 24K-0952
Problem No:2
*/

#include<stdio.h>
#include<string.h>

int main(){
    char slogans[10][100];
    int slogansNum;
    printf("Enter the number of slogans: ");
    scanf("%d",&slogansNum);
    
    getchar();
    
    int i;
    for(i=0;i<slogansNum;i++){
        printf("Enter slogan %d: ",i+1);
        fgets(slogans[i],100,stdin);
        
        int length=strlen(slogans[i]);
        if(length>0 && slogans[i][length-1]=='\n'){
            slogans[i][length-1]='\0';
        }
    }
    int ASCIIvalue=128;
    int frequency[ASCIIvalue];
    int m;
    int j;
    for(i=0;i<slogansNum;i++){
        for(m=0;m<ASCIIvalue;m++){
            frequency[m] = 0;
        }
        for (j=0;slogans[i][j]!='\0';j++){
            frequency[slogans[i][j]]++;
        }
        printf("Frequency for \"%s\": {", slogans[i]);
        for (j=0; j<ASCIIvalue;j++){
            if (frequency[j]>0){
                printf("'%c': %d",j,frequency[j]);
                if (j<ASCIIvalue-1){
                    printf(", ");
                }
            }
        }
        printf("}\n");
    }

    return 0;
}
