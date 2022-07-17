#include <stdio.h>
int main()
{
    int sub1, sub2, sub3, sub4, sub5;
    printf("Enter 5 subjects marks out of 100: ");
    scanf("%d%d%d%d%d", &sub1, &sub2, &sub3, &sub4, &sub5);
    if (sub1 >= 33 && sub2 >= 33 && sub3 >= 33 && sub4 >= 33 && sub5 >= 33)
        printf("Candidate is Passed!");
    else
        printf("Candidate is Failed!");
    return 0;
}