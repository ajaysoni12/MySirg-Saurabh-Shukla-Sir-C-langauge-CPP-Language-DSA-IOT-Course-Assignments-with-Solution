#include <stdio.h>
#include <string.h>
struct Student
{
    int rollNo;
    long int contact_info;
    char name[20];
};

void inputStudentData(struct Student stu[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        printf("\nEnter %d student Details:\n", i + 1);
        printf("Enter student rollNo: ");
        scanf("%d", &stu[i].rollNo);
        fflush(stdin); // because buffer is full so next fgets function not take name to we use fflush function
        printf("Enter student Name: ");
        fgets(stu[i].name, sizeof(stu[i].name), stdin);
        printf("Enter student contact number: ");
        scanf("%d", &stu[i].contact_info);
    }
}

void displayStudentData(struct Student stu[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        printf("\n\n%d students details", i + 1);
        printf("\nStudent Roll No: %d", stu[i].rollNo);
        printf("\nStudents name: %s", stu[i].name);
        printf("Students contact number: %d", stu[i].contact_info);
    }
}

int main()
{
    int totalStu;
    printf("How many student information u want to enter: ");
    scanf("%d", &totalStu);
    struct Student stu[totalStu];
    inputStudentData(stu, totalStu);
    displayStudentData(stu, totalStu);
    return 0;
}