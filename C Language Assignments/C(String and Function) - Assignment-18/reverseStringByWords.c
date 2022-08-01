#include <stdio.h>
#include <string.h>

void strRevByWords(char str[])
{
    int strLength = strlen(str); // str string length - 17 
    
    int arr[strLength]; // create 17 length arr array for store reverse word string 

    int arrInd = 0; // index of arr array 

    int i = strLength-1; // length - 15  for accessing last index but before null character

    int j,k; // extra variable for looping pupose

    str[strLength-1] = ' '; // for maintain space (change null to space) 

    while(i>=0) 
    {
        for(j=i-1; str[j]!=' ' && j>=0; j--); // check it is contain space or less than 0

        for(k=j+1; k<=i; k++)
            arr[arrInd++] = str[k]; // copy words in arr string 

        i = j;  // update i
    }
    arr[strLength-1] = '\0';  // maintain null character in last index for exit loop 
    
    for(int i=0; arr[i]; i++) // just copy array 
        str[i] = arr[i]; 
    
}

int main()
{
    char str[100];

    printf("Enter first string: ");
    fgets(str, 100, stdin);

    strRevByWords(str);
    printf("\nReverse string by words: %s", str);

    return 0;
}