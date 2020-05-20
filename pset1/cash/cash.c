#include <cs50.h>
#include <stdio.h>
#include<math.h>
int main(void)
{
    float change;
    do
    {
        change = get_float("change owed = ");
    }
    while (change < 0);

    int coins = 0;
    int amt = round(change * 100);
    while (amt >= 25)
    {
        coins ++;
        amt -= 25;
    }

    while (amt >= 10)
    {
        coins ++;
        amt -= 10;
    }

    while (amt >= 5)
    {
        coins ++;
        amt -= 5;
    }

    while (amt >= 1)
    {
        coins ++;
        amt -= 1;
    }
    printf("%i\n", coins);
}
