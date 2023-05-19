#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_if_palindrome(int num)
{
	char str[20];
	int num_length = 0, i = 0;

	while (num)
	{
		str[i] = num % 10 + '0';
		num /= 10;
		i++;
	}
	str[i] = '\0';
	i = 0;
	num_length = strlen(str) - 1;
	while (i < num_length)
	{
		if (str[i] != str[num_length])
		{
			return (0);
		}
		i++;
		num_length--;
	}
	return (1);
}

int main(void)
{
	unsigned int num1 = 100, num2 = 100, palindrome = 0, check, prod;
	while (num1 < 1000)
	{
		while (num2 < 1000)
		{
			prod = num1 * num2;
			check = check_if_palindrome(prod);
			if (check == 1)
			{
				if (prod > palindrome)
				{
					palindrome = prod;
					printf("palindrome -> %d: multiple of -> \
%d x %d\n", palindrome, num1, num2);
				}
			}
			num2++;
		}
		num1++;
		num2 = 100;
	}
	printf("largest palindrome -> %d\n", palindrome);
}
