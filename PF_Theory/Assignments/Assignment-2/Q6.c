/*
Name: Iqra Ashraf
Roll No: 24K-0952
Problem No:6
*/

#include<stdio.h>

int matchstickgame(int N){
	if(N<=0 || N%5==0){
		return -1;
	}else{
		return N%5;
	}
	
}

int main() {
	int N;
	printf("Enter the number of matchsticks: ");
	scanf("%d",&N);
	
	matchstickgame(N);
	if(matchstickgame(N)==-1){
		printf("It is impossible for A to win");
	}else{
		printf("A should pick %d matchsticks",matchstickgame(N));
	}
	return 0;
}