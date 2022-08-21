#include <stdio.h>
struct Employee
{
    int id;
    char name[20];
    float salary;
};

void displayUserData(struct Employee user1)
{
    printf("\nUser1 Id: %d", user1.id);
    printf("\nUser Name: %s", user1.name);
    printf("User salary: %.2f", user1.salary);
}

void inputUserData(struct Employee *user1)
{
    printf("Enter Id: ");
    scanf("%d", &user1->id);
    fflush(stdin); // because buffer is full so next fgets function not take name to we use fflush function
    printf("Enter User Name: ");
    fgets(user1->name, sizeof(user1->name), stdin);
    printf("Enter User salary: ");
    scanf("%f", &user1->salary);
}
int main()
{
    struct Employee user1;
    inputUserData(&user1);
    displayUserData(user1);
    return 0;
}