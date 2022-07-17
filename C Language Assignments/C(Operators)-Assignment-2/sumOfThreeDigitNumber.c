int main()
{
    int num;
    printf("Enter a number ");
    scanf("%d", &num);
    int digitSum = num%10; 
    num = num/10; 
    digitSum+=num%10; 
    num = num/10; 
    digitSum+=num%10; 
    printf("Sum of digit is: %d",digitSum); 
    return 0;
}