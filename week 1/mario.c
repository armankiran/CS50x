

#include <cs50.h>
#include <stdio.h>

int height = 0;
void build_triangle();

int main(void)
{
    //get user input between from 1 trough 8
    do
    {
        height = get_int("Height?: ");
    }
    while (height < 1 || height > 8);
    build_triangle();
}

void build_triangle(void)
{
    //calculates spaces and blocks based on variable 'i'
    for (int i = 0; i < height; i++)
    {
        //print spaces
        for (int j = 1; j < height - i; j++)
        {
            printf(" ");
        }
        //print blocks
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}