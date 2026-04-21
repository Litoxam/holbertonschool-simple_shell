/**
* _atoi - convert a string to an integer
* @s: pointer to string - string to convert
* Return: integer
*/

int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	unsigned int dest = 0;
	int started = 0;

	while (s[i] != '\0')
	{

		if ((s[i] == '-') && started == 0)
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			dest = dest * 10 + (s[i] - '0');
		} else if (started)
		{
			break;
		}
		i++;
	}
	return (dest * sign);
}
