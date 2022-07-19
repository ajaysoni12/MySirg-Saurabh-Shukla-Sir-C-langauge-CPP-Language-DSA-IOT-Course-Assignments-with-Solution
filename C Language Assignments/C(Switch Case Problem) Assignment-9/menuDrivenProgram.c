#include <stdio.h>
#include<stdlib.h>
int main()
{
    while (1)
    {
        int choice;
        printf("1 - Additions\n");
        printf("2 - Substraction\n");
        printf("3 - Multiplication\n");
        printf("4 - Division\n");
        printf("5 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        int x, y;
        switch (choice)
        {
        case 1:
            printf("Enter two number: ");
            scanf("%d%d", &x, &y);
            printf("Addition of %d and %d is %d\n", x, y, x + y);
            break;
        case 2:
            printf("Enter two number: ");
            scanf("%d%d", &x, &y);
            printf("Substraction of %d and %d is %d\n", x, y, x - y);
            break;
        case 3:
            printf("Enter two number: ");
            scanf("%d%d", &x, &y);
            printf("Multiplication of %d and %d is %d\n", x, y, x * y);
            break;
        case 4:
            printf("Enter two number: ");
            scanf("%d%d", &x, &y);
            printf("Division(Quotiont) of %d and %d is %d\n", x, y, x / y);
            break;
        case 5:
            printf("Thanku!\n");
            exit(0);
        default:
            printf("Enter right choice!\nTry agian!\n");
        }
    }

    return 0;
}