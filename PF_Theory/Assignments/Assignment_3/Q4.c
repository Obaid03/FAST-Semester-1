#include <stdio.h>
#include <stdlib.h>

#define MINRATING 1
#define MAXRATING 10

typedef struct{
    int* ratings;
    int totalScore;
} Employee;

void inputEmployees(Employee* employees, int numEmployees, int numPeriods){
	int i,j;
    for(i=0; i<numEmployees; i++) {
        printf("Enter ratings for Employee %d (between %d-%d):\n",i+1,MINRATING,MAXRATING);
        employees[i].ratings=(int*)malloc(numPeriods*sizeof(int));

        for(j=0; j<numPeriods; j++) {
            do{
                printf("  Period %d: ",j+1);
                scanf("%d",&employees[i].ratings[j]);

                if(employees[i].ratings[j]<MINRATING || employees[i].ratings[j]>MAXRATING){
                    printf("Invalid rating! Please enter a rating between %d and %d.\n",MINRATING,MAXRATING);
                }
            }while(employees[i].ratings[j]<MINRATING || employees[i].ratings[j]>MAXRATING);
        }
    }
}

void displayPerformance(Employee* employees,int numEmployees,int numPeriods) {
    printf("Performance Ratings:\n");
    int i,j;
    for(i=0; i<numEmployees; i++){
        printf("Employee %d: ",i+1);
        for(j=0; j<numPeriods; j++) {
            printf("%d ",employees[i].ratings[j]);
        }
        printf("\n");
    }
}

int findEmployeeOfTheYear(Employee* employees,int numEmployees,int numPeriods){
    int highestIndex=0;
    double highestAvg=0.0;
    
    int i,j;
    for(i=0; i<numEmployees; i++) {
        double total=0.0;
        for(j=0; j<numPeriods; j++) {
            total+=employees[i].ratings[j];
        }
        double avg=total/numPeriods;
        if(avg>highestAvg){
            highestAvg=avg;
            highestIndex=i;
        }
    }
    return highestIndex;
}

int findHighestRatedPeriod(Employee* employees,int numEmployees,int numPeriods) {
    int highestPeriod=0;
    double highestAvg=0.0;
    
    int i,j;
    for(j=0; j<numPeriods; j++) {
        double total=0.0;
        for(i=0; i<numEmployees; i++) {
            total+=employees[i].ratings[j];
        }
        double avg=total/numEmployees;
        if(avg>highestAvg){
            highestAvg=avg;
            highestPeriod=j;
        }
    }
    return highestPeriod;
}

int findWorstPerformingEmployee(Employee* employees,int numEmployees,int numPeriods) {
    int worstIndex=0;
    double lowestAvg=10.0;
    
    int i,j;
    for(i=0; i<numEmployees; i++){
        double total=0.0;
        for(j=0; j<numPeriods; j++) {
            total+=employees[i].ratings[j];
        }
        double avg=total/numPeriods;
        if(avg<lowestAvg){
            lowestAvg=avg;
            worstIndex=i;
        }
    }
    return worstIndex;
}

void freeMemory(Employee* employees,int numEmployees) {
	int i;
    for (i=0; i<numEmployees; i++) {
        free(employees[i].ratings);
    }
}

int main(){
    int numEmployees,numPeriods;

    printf("Enter the number of employees: ");
    scanf("%d",&numEmployees);

    printf("Enter the number of evaluation periods: ");
    scanf("%d",&numPeriods);

    Employee* employees=(Employee*)malloc(numEmployees * sizeof(Employee));

    inputEmployees(employees,numEmployees,numPeriods);
    displayPerformance(employees,numEmployees,numPeriods);

    int bestEmployee=findEmployeeOfTheYear(employees,numEmployees,numPeriods);
    printf("\nEmployee of the Year: Employee %d\n",bestEmployee+1);

    int bestPeriod=findHighestRatedPeriod(employees,numEmployees,numPeriods);
    printf("Highest Rated Evaluation Period: Period %d\n",bestPeriod+1);

    int worstEmployee=findWorstPerformingEmployee(employees,numEmployees,numPeriods);
    printf("Worst Performing Employee: Employee %d\n",worstEmployee+1);

    freeMemory(employees,numEmployees);

    free(employees);
    return 0;
}
