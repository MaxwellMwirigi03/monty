/*
 * File: int_to_string.c
 * Auth: Maxwell Mwirigi
 */

#include <stdlib.h>

char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
		       char *buff, int buff_size);

/*Gets a character pointer to new string containing int*/
char *get_int(int num)
{
	unsigned int temp;
	int lenghth = 0;
	long num_l = 0;
	char *ret;

	temp = _abs(num);
	lenghth = get_numbase_len(temp, 10);

	if (num < 0 || num_l < 0)
		lenghth++; /* negative sign */
	ret = malloc(lenghth + 1); /* create new string */
	if (!ret)
		return (NULL);

	fill_numbase_buff(temp, 10, ret, lenghth);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/*Gets the absolute value of an integer*/
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/*Gets the length of buffer needed for an unsigned int*/
int get_numbase_len(unsigned int num, unsigned int base)
{
	int Leng = 1; /* all numbers contain atleast one digit */

	while (num > base - 1)
	{
		Leng++;
		num /= base;
	}
	return (Leng);
}

/*Fills buffer with correct numbers up to base 36*/
void fill_numbase_buff(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
	int remn, bs = buff_size - 1;

	buff[buff_size] = '\0';
	while (bs >= 0)
	{
		remn = num % base;
		if (remn > 9) /* return lowercase ascii val representation */
			buff[bs] = remn + 87; /* 10 will be a, 11 = b, ... */
		else
			buff[bs] = remn + '0';
		num /= base;
		bs--;
	}
}
