#include <stdio.h>
#include <string.h>
int main()
{
    int flag = 0, i;
    char a[3][2][20] = {
        {"Ajay", "123"},
        {"Soni", "456"},
        {"Silent", "123"}};

    char userName[] = "Silent";
    char passWord[] = "456";

    for (i = 0; i < 3; i++)
    {
        if (strcmp(userName, a[i][0]) == 0 && strcmp(passWord, a[i][1])==0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("Username or Password doesn't match!");
    else 
        printf("Login Successfull!");
    return 0;
}