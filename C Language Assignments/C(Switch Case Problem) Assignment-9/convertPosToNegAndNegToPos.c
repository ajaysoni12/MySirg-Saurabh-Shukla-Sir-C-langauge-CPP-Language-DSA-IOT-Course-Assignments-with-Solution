#include<stdio.h>
int main(){
   int num; 
   printf("Enter a number: "); 
   scanf("%d",&num); 
   switch(num<0)
   {
       case 1: 
          printf("Convert: Negative to Positive:  %d",num*-1); 
          break; 
       default: 
          printf("Convert: Positive to Negative:  %d",num*-1); 
   }
return 0;
}