#include <stdio.h>
int main()
{
    int year;
    printf("Enter year: ");
    scanf("%d", &year);
    switch (year % 400)
    {
    case 0:
        printf("Yup!, it is leap year!");
        break;
    default:
        switch (year % 100)
        {
        case 0:
            printf("Not a leap year!");
            break;
        default:
            switch (year % 4)
            {
            case 0:
                printf("Leap year");
                break;
            default:
                printf("Not a leap year!");
            }
        }
    }
    return 0;
}