#include <cs50.h>
#include <stdio.h>

long card_number;
double digit_length;
int total = 0;
bool card_check = false;
void get_int_lenght(void);
void get_digit_sum(void);
void check_card(void);

int main(void)
{
    card_number = get_long("Number: ");
    get_int_lenght();
    check_card();
}

//get int length
void get_int_lenght(void)
{
    long j = 1;
    for (digit_length = 0; j < card_number; digit_length++)
    {
        j = j * 10;
    }
    get_digit_sum();

}
//get total card digits
void get_digit_sum(void)
{
    long amount = card_number;
    long second_modulo = 100;
    long first_modulo = 10;
    long second_digit;
    long first_digit;
    int sum;
    int total_first = 0;
    //go through card number from end to get second digits to multiply
    int k;
    for (k = 0; k < digit_length / 2; k++)
    {
        second_digit = card_number % second_modulo;
        //catch numbers start with 0
        if (second_digit < second_modulo / 10)
        {
            second_digit = 0;
        }
        //get the first number
        else
        {
            while (second_digit >= 10)
            {
                second_digit = second_digit / 10;
            }
        }
        sum = second_digit * 2;
        //if number is greater or equal to 10, break in two pieces
        if (sum < 10)
        {
            total = total + sum;
        }
        else
        {
            total = total + ((sum % 100 - sum % 10) / 10) + sum % 10;
        }
        second_modulo = second_modulo * 100;
    }
    //not multipled digits
    for (k = 0; k < digit_length / 2; k++)
    {
        //catch numbers start with 0
        first_digit = card_number % first_modulo;
        if (first_digit < first_modulo / 10)
        {
            first_digit = 0;
        }
        //get the first digit
        else
        {
            while (first_digit >= 10)
            {
                first_digit = first_digit / 10;
            }
        }
        //add digits together and increase modulo to get next digit
        total = total + first_digit;
        first_modulo = first_modulo * 100;
    }
}
//check if the card is valid
void check_card(void)
{
    if ((digit_length < 17 && digit_length > 12) && total % 10 == 0)
    {
        //check visa cards
        long check_visa = card_number;
        while (check_visa >= 10)
        {
            check_visa = check_visa / 10;
        }
        if (check_visa == 4)
        {
            card_check = true;
            printf("VISA\n");
        }
        //check other cards
        long check_others = card_number;
        while (check_others >= 100)
        {
            check_others = check_others / 10;
        }
        //switch case to check multiple cards
        switch (check_others)
        {
            case 34:
                printf("AMEX\n");
                card_check = true;
                break;
            case 37:
                printf("AMEX\n");
                card_check = true;
                break;
            case 51:
                card_check = true;
                printf("MASTERCARD\n");
                break;
            case 52:
                card_check = true;
                printf("MASTERCARD\n");
                break;
            case 53:
                card_check = true;
                printf("MASTERCARD\n");
                break;
            case 54:
                card_check = true;
                printf("MASTERCARD\n");
                break;
            case 55:
                card_check = true;
                printf("MASTERCARD\n");
                break;
            default:
                break;
        }
    }
    //if card doesn't match set it as false
    if (card_check == false)
    {
        printf("INVALID\n");
    }
}