#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - program that generates random valid
 * passwords for the program 101-crackme
 * Return: Always 0 (Success)
 */

int main(void)
{
    char password[94];
    int index = 0, sum = 0, diff_half1, diff_half2;

    srand(time(0));

    while (sum < 2772)
    {
        password[index] = 33 + rand() % 94;
        sum += password[index];
        index++;
    }
    password[index] = '\0';

    if (sum != 2772)
    {
        diff_half1 = (2772 - sum) / 2;
        diff_half2 = (2772 - sum) / 2;

        if ((2772 - sum) % 2 != 0)
        {
            diff_half1++;
        }

        for (index = 0; password[index]; index++)
        {
            if (password[index] >= (33 + diff_half1))
            {
                password[index] -= diff_half1;
                break;
            }
        }

        for (index = 0; password[index]; index++)
        {
            if (password[index] >= (33 + diff_half2))
            {
                password[index] -= diff_half2;
                break;
            }
        }
    }

    printf("%s\n", password);
    return (0);
}
