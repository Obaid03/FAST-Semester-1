/*
Name: Iqra Ashraf
Roll No: 24K-0952
Problem No:4
*/

#include <stdio.h>
#include <string.h>

void sortTransaction(char sorted[]) {
    int length=strlen(sorted);
    int i;
    int j;
    for (i=0; i<length-1; i++) {
        for (j=i; j<length; j++) {
            if (sorted[i]>sorted[j]) {
                char temp=sorted[i];
                sorted[i]=sorted[j];
                sorted[j]=temp;
            }
        }
    }
}

void groupTransactions(char transactions[][100],int size) {
    int grouped[100]={0};
    char sortedTransaction[100][100];
    int i;
    for (i=0; i<size; i++) {
        strcpy(sortedTransaction[i],transactions[i]);
        sortTransaction(sortedTransaction[i]);
    }
    int i;
    int j;
    for (i=0; i<size; i++) {
        if(!grouped[i]) {
            printf("Group: %s",transactions[i]);
            grouped[i]=1;

            for (j=i+1; j<size; j++) {
                if (strcmp(sortedTransaction[i],sortedTransaction[j])==0) {
                    printf(", %s",transactions[j]);
                    grouped[j]=1;
                }
            }
            printf("\n");
        }
    }
}

int main() {
    char transactions[10][100];
    int transactionsNum;

    printf("Enter the number of transactions: ");
    scanf("%d",&transactionsNum);
    getchar();
    printf("Input transactions\n[ ");
    int i;
    int j;
    for (i=0; i<transactionsNum; i++) {
        if (i==transactionsNum-1) {
            printf("Transaction %d: ",i+1);
            fgets(transactions[i], 100, stdin);
            transactions[i][strcspn(transactions[i],"\n")]=0;
            printf("]\n");
            break;    
        }
        printf("Transaction %d: ",i+1);
        fgets(transactions[i],100,stdin);
        for (j=0; transactions[i][j]!='\0'; j++) {
        	 if (transactions[i][j]=='\n') {
        	 	 transactions[i][j]='\0';
                 break;
        }
    }
    }

    groupTransactions(transactions,transactionsNum);

    return 0;
}
