int primeNum(int n)
{
    bool flag = false; 
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            flag = true; 
            break;
        }
    }

    if(flag)
        return 1; // primeNo. 
    else 
        return 0; // noPrimeNo. 

    // if(flag)
    //     cout<<"Prime Number!"; 
    // else 
    //     cout<<"Not Prime Number!"; 
}