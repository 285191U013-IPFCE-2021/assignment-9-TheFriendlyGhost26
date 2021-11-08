#include "search.h"
#include <stdbool.h>

//Function that searches an array for element x
bool search (int a[], int n, int x) 
{

    if (n == 0)
    {
        return false;
    }

    if (a [n-1] == x)
    {
        return true;
    }
    
    // Recursion
    else 
        return search (a, n-1, x);  
}



