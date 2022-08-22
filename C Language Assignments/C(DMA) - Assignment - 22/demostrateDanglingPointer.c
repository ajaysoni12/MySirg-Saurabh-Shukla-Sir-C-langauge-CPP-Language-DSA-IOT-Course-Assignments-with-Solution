#include<stdio.h>
int main(){
    int *ptr; 
    {
        int x = 5; 
        ptr = &x; 
    }
    // now ptr become dangling pointer becusae ptr contains address of x but x is destroy but ptr contain x address
return 0;
}