/*
Name: Iqra Ashraf
Roll No: 24K-0952
Problem No:3
*/

#include<stdio.h>
#include<string.h>

int wordCompress(char wordInput[], char wordCompressed[]) {
    int compressedIndex=0;
    int countRemoved=0;
    int i;
    for (i=0;wordInput[i]!='\0';i++){
        if (i==0 || wordInput[i]!=wordInput[i-1]){
            wordCompressed[compressedIndex++]=wordInput[i];
        }else{
        	countRemoved++;
		}
    }
    wordCompressed[compressedIndex]='\0';
    return countRemoved;
}

int main(){
	char words[10][100];
    int wordsNum;
    printf("Enter the number of words: ");
    scanf("%d",&wordsNum);
    
    getchar();
    
    int i;
    for(i=0;i<wordsNum;i++){
        printf("Enter word %d: ",i+1);
        fgets(words[i],100,stdin);
        
        int length=strlen(words[i]);
        if(length>0 && words[i][length-1]=='\n'){
            words[i][length-1]='\0';
        }
    }
     printf("[");
	 for(i=0;i<wordsNum;i++) {
        char wordCompressed[100];
        int countRemoved=wordCompress(words[i], wordCompressed);
        printf("%s",wordCompressed);
        printf(" (removed: %d),",countRemoved);
    }
    printf("]");

}