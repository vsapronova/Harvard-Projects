#include <math.h>
#include <stdio.h>
#include <cs50.h>

int count_coins(int change);

int main(void)
{
    float change_float;
    do 
    {
         change_float = get_float("Change: ");  
    }while(change_float <= 0);
    int change = round(change_float * 100);
    
    int coins = count_coins(change);
    printf("%i\n", coins);
    
}

int count_coins(int change)
{
    int coins = 0;
    while(!(change < 25))
    {
        change -= 25;
        coins++;    
    }
    if(change == 0)
    {
        return coins;
    }
    while(!(change < 10))
    {
        change -= 10;
        coins++;
    }
    if(change == 0)
    {
        return coins;
    }
    while(!(change < 5))
    {
        change -= 5;
        coins++;
    }
    if(change == 0)
    {
        return coins;
    }
    while(change != 0)
    {
        change -= 1;
        coins++;
    }
    return coins;
}


