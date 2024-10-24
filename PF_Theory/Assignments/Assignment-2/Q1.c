/*
Name: Iqra Ashraf
Roll No: 24K-0952
Problem No:1
*/

#include<stdio.h>

int main(){
	
	int arr[5];
	int i;
	for(i=0;i<5;i++){
	printf("Element %d: ",i);
	scanf("%d",&arr[i]);
	if(arr[i]>999){
		printf("Invalid Input");
		return 0;
	}
    }
	int smallest,secondSmallest=arr[0];
	for(i=0;i<5;i++){
		if(arr[i]<smallest){
			secondSmallest=smallest;
			smallest=arr[i];
		}
		else if(arr[i]>smallest && arr[i]<secondSmallest){
			secondSmallest=arr[i];
		}
	}
	printf("The second smallest element in the array is: %d",secondSmallest);
	return 0;
}