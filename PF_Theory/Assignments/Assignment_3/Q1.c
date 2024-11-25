#include <stdio.h>
#include <string.h>

struct Employee{
    int employeeCode;
    char employeeName[50];
    int dateOfJoining[3];
};

void assignEmployee(struct Employee* emp){
    printf("Enter Employee Code: ");
    scanf("%d",&emp->employeeCode);
    printf("Enter Employee Name: ");
    scanf(" %[^\n]",emp->employeeName);
    printf("Enter Date of Joining (dd mm yyyy): ");
    scanf("%d %d %d",&emp->dateOfJoining[0],&emp->dateOfJoining[1],&emp->dateOfJoining[2]);
}

void checkTenure(struct Employee employees[],int n){
    int currentDate[3];
	int count=0;

    printf("Enter Current Date (dd mm yyyy): ");
    scanf("%d %d %d",&currentDate[0],&currentDate[1],&currentDate[2]);

    printf("Employees with tenure greater than 3 years:\n");
    printf("Code\tName\t\tDate of Joining\n");
    printf("-----------------------------------------\n");
    
    int i;
    for(i=0; i<n; i++) {
        int years=currentDate[2]-employees[i].dateOfJoining[2];
        int months=currentDate[1]-employees[i].dateOfJoining[1];
        int days=currentDate[0]-employees[i].dateOfJoining[0];

        if(months<0 || (months==0 && days<0)){
            years--;
        }

        if(years>3){
            printf("%d\t%s\t\t%d-%d-%d\n",
                   employees[i].employeeCode,
                   employees[i].employeeName,
                   employees[i].dateOfJoining[0],
                   employees[i].dateOfJoining[1],
                   employees[i].dateOfJoining[2]);
            count++;
        }
    }

    printf("\nTotal Employees with tenure greater than 3 years: %d\n",count);
}

int main(){
    struct Employee employees[4];
    
    int i;
    for(i=0; i<4; i++){
        printf("Enter details for Employee %d\n",i+1);
        assignEmployee(&employees[i]);
    }

    checkTenure(employees,4);

    return 0;
}
