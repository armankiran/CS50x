#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool only_digits(string s);
char rotate(string p, int k);



int main(int argc, string argv[])
{
    //check the args
    if (argv[2])
    {
        //more than 1 arg
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (!argv[1])
    {
        //no arg
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (only_digits(argv[1]))
    {
        //key is not digit
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        //get the key
        int key = atoi(argv[1]);
        string plain_text = get_string("plaintext: ");
        rotate(plain_text, key);
        return 0;
    }
}

bool only_digits(string s)
{
    //check if the string is a single digit
    if (strlen(s) > 0 && isdigit(*s))
    {
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            if (!isdigit(s[i]))
            {
                return 1;
            }
        }
    }
    return 0;
}

char rotate(string p, int k)
{
    //go through the string and replace
    int c;
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        //is alpha
        if (isalpha(p[i]))
        {
            //is uppercase
            if (isupper(p[i]))
            {
                c = p[i] - 65;
                c = ((c + k) % 26) + 65;
                p[i] = c;
            }
            //is lowercase
            else if (islower(p[i]))
            {
                c = p[i] - 97;
                c = ((c + k) % 26) + 97;
                p[i] = c;
            }
        }
    }
    printf("ciphertext: %s\n", p);
    return 0;
}