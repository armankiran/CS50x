#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //get string from user and print
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}