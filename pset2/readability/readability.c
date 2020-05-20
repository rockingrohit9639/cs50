#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<math.h>
int main(void)
{
    int letters = 0, words = 1, sentence = 0, i;
    string str = get_string("Enter the paragraph : ");

    for (i = 0; i < strlen(str); i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            letters++;
        }
        else if (str[i] == ' ' || str[i] == '\t')
        {
            words++;
        }
        else if (str[i] == '.' || str[i] == '!' || str[i] == '?')
        {
            sentence++;
        }

    }

    float grade = 0.0588 * (100 * (float) letters / (float) words) - 0.296 * (100 * (float) sentence / (float) words) - 15.8;
    if (grade < 16 && grade >= 0)
    {
        printf("Grade %i\n", (int) round(grade));
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}
