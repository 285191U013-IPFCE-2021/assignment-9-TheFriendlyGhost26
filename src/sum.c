#include "sum.h"

//Function that returns the sum of all array elements with recursion
int sum(int a[], int n)
{
    int res; //result

    //Recursion
    if (n > 0) 
    {
        res = a[n-1] + sum(a, n-1);    
    }
    
    else 
    {
        return 0;
    }
    return res;
}