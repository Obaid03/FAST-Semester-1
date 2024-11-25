#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateEmail(char* email) {
    if (email==NULL || strlen(email)==0) {
        return 0;
    }

    int atCount=0;
    int dotCount=0;
    
    int i;
    for(i=0; i<strlen(email); i++) {
        if(email[i]=='@'){
            atCount++;
        }
        if(email[i]=='.'){
            if (atCount>0){
                dotCount++;
            }
        }
    }
    
    if(atCount==1 && dotCount>=1){
        return 1;
    }

    return 0;
}

int main(){
    char *email;
    int len=100;
    
    email=(char *)malloc(len * sizeof(char));

    if(email==NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter an email address: ");
    fgets(email,len,stdin); 

    email[strcspn(email,"\n")]='\0';

    if(validateEmail(email)){
        printf("Valid Email\n");
    }else{
        printf("Invalid Email\n");
    }

    free(email);

    return 0;
}
