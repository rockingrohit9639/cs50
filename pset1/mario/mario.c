#include<cs50.h>
#include<stdio.h>
#include<stdio.h>
void half_pyramid(int n);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0 || height > 8);
    half_pyramid(height);
}
void half_pyramid(int n)
{
    int spaces;
    int dashes;
    for (int i = 2; i <= n + 1; i++)
    {
        for (spaces = (n - i); spaces >= 0; spaces--)
        {
            printf(" ");
        }
        for (dashes = 1; dashes < i; dashes++)
        {
            printf("#");
        }
        printf("\n");
    }
}
