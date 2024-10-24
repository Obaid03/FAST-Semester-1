/*
Name: Iqra Ashraf
Roll No: 24K-0952
Problem: 10

In this problem, a star pattern is being printed with the length of each traingle being N-1 lines and an additional line in the middle of the pattern which contains the maximum number of stars. the pattern is being printed in total three sections, including upper, middle, and lower.
*/
#include<stdio.h>

void printStar(int N);//defining a function

int main() {//start main
    int N;//prompt user for a number input
    printf("Enter a number: ");
    scanf("%d",&N);

    if (N%2 == 0) {//check whether the number is odd
        printf("Invalid Number.");
        return 1;
    }
    printStar(N);//calling function
    
    return 0;
}//end main

void printStar(int N){
	
    int i,j,m;
    int k=N+N-2;
    int l=0;
    //printing upper triangle
    for(i=0;i<N-1;i++){
    	for(j=k; j>0; j--){
    		printf(" ");
		}
		printf("*");
		for(j=l-1; j>0; j--){
			printf(" ");
			if(j==1){
				printf("*");
			}
		}
    	printf("\n");
    	k--;
    	l+=2;
	}
	//printing middle section
		for(j=0;j<N;j++){
			printf("*");
		}
		for(j=l-1;j>0;j--){
			printf(" ");
		}
		for(j=0;j<N;j++){
			printf("*");
		}
		printf("\n");
		k=0;
		int q=N+N+l-3;
		for(i=0;i<N-1;i++){
			for(j=k+1;j>0;j--){
				printf(" ");
			}
			printf("*");
			for(j=q-2;j>0;j--){
				printf(" ");
			}
			printf("*");
			printf("\n");
			k++;
			q-=2;
		}
		//printing lower two triangles
		int n=N-2;
		int o=1;
		int p=k;
		for(i=0;i<N-1;i++){
			for(j=k-1;j>0;j--){
				printf(" ");
			}
			printf("*");
			for(j=n;j>0;j--){
				printf(" ");
				if(j==1){
					printf("*");
				}
			}
			for(j=o;j>0;j--){
				printf(" ");
			}
			if(i==N-2){
				printf("  ");
			}
			printf("*");
			for(j=p-1;j>0;j--){
				printf(" ");
				if(j==1){
					printf("*");
				}
		}	
			printf("\n");
			k--;
			n--;
			o+=4;
			p--;
		}
}