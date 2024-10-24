/*
Name: Iqra Ashraf
Roll No: 24K-0952
Problem No:5
*/

#include <stdio.h>

void horizontalHistogram(int values[],int count) {
    printf("\nHorizontal Histogram:\n");
    for (int i=0; i<count; i++) {
        printf("%d ", values[i]);
        for (int j=0; j<values[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void verticalHistogram(int values[],int count) {
    printf("\nVertical Histogram:\n");
    int max=values[0];
    for (int i=1; i<count; i++) {
        if (values[i]>max) {
            max=values[i];
        }
    }
    for (int i=max; i>0; i--) {
        for (int j=0; j<count; j++) {
            if (values[j]>=i) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");
    for (int i=0; i<count; i++) {
        printf("%d ",values[i]);
    }
    printf("\n");
}

int main() {
    int count;
    printf("Enter the number of values: ");
    scanf("%d",&count);
    
    int values[count];
    printf("Enter %d integers:\n",count);
    for (int i=0; i<count; i++) {
        scanf("%d",&values[i]);
    }

    horizontalHistogram(values,count);
    verticalHistogram(values,count);

    return 0;
}
