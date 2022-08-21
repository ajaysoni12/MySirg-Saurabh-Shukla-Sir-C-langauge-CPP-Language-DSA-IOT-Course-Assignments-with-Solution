#include <stdio.h>
struct studentMarks
{
    int rollNo;
    char name[20];
    int chem_marks, phy_marks, maths_marks;
};

void inputStuMark(struct studentMarks student[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        printf("\n\nEnter %d Student details: ", i+1);
        printf("\nEnter rollNo: ");
        scanf("%d", &student[i].rollNo);
        fflush(stdin); 
        printf("Enter Name of student: ");
        fgets(student[i].name, 20, stdin);
        printf("Enter chemistry, physics and maths marks(out of 100): ");
        scanf("%d%d%d", &student[i].chem_marks, &student[i].phy_marks, &student[i].maths_marks);
    }
}

void studentPercentage(struct studentMarks student[], int arrlength)
{
    for(int i=0; i<arrlength; i++)
    {
        printf("\n\n%d student Details: ", i+1); 
        printf("\nRollNo - %d", student[i].rollNo);  
        printf("\nName: %s", student[i].name); 
        printf("chem_marks - %d, phy_marks - %d, math_marks - %d", student[i].chem_marks, student[i].phy_marks,student[i].maths_marks); 
        float average = (student[i].chem_marks + student[i].maths_marks + student[i].phy_marks)/3.0f;
        printf("\nAverage of marks: %.2f",average); 
    }
}

int main()
{
    struct studentMarks student[5];
    inputStuMark(student, 5);
    studentPercentage(student, 5); 
    return 0;
}