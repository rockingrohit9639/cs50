#include<stdio.h>
#include<cs50.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int main(int argc, char *key[])

{

// Vaildate key

    int no[26] = {0};

    string k = key[1];

    if (argc != 2)

    {

        printf("Enter a key.\n");

        return 1;

    }

    int len = strlen(key[1]);

    if (len != 26)

    {

        printf("Key must contain 26 characters.\n");

        return 1;

    }

    for (int x = 0; x < len; x++)

    {

        if (islower(k[x]) || isupper(k[x]))

        {

            no[tolower(k[x]) - 97] ++;

            if (no[tolower(k[x]) - 97] > 1)

            {

                printf("Key must have no repeated characters.\n");

                return 1;

            }

        }

        else

        {

            printf("Key needs to contain only letters.");

            return 1;

        }

    }

// Get input

    string i = get_string("plaintext: ");

// Encypt input

    char output[strlen(i)];

    for (int x = 0; x < strlen(i); x++)

        if (islower(i[x]))

        {

            output[x] = tolower(k[i[x] - 97]);

        }

        else if (isupper(i[x]))

        {

            output[x] = toupper(k[i[x] - 65]);

        }

        else

        {

            output[x] = i[x];

        }

// Print output

    printf("ciphertext: %s\n", output);

    return 0;

}
