#include <stdio.h>
#include <string.h>
struct Employee
{
    int id;
    char name[20];
    float salary;
};

void inputUserData(struct Employee users[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        printf("\nEnter %d User Details:\n",i+1);
        printf("Enter User Id: ");
        scanf("%d", &users[i].id);
        fflush(stdin); // because buffer is full so next fgets function not take name to we use fflush function
        printf("Enter User Name: ");
        fgets(users[i].name, sizeof(users[i].name), stdin);
        printf("Enter User salary: ");
        scanf("%f", &users[i].salary);
    }
}

void heighestSalaryEmp(struct Employee users[], int arrLength)
{
    int mxSalaryEmpId = -1;
    int ind = -1;
    for (int i = 0; i < arrLength; i++)
    {
        if (mxSalaryEmpId < users[i].salary)
        {
            mxSalaryEmpId = users[i].salary;
            ind = i;
        }
    }
    printf("\nHeighest Salary Employee id - %d and Employee Name - %s", users[ind].id, users[ind].name);
}

int main()
{
    struct Employee users[10];
    inputUserData(users, 10);
    heighestSalaryEmp(users, 10);
    return 0;
}