

int	ft_view(char *output)
{
	int	i;
	int	c;
	int	v;

	i = 0;
	v = i;
	c = 1;
	while (output[i] != '\0')
	{
		if (output[i] > output[v])
		{
			v = i;
			c++;
		}
		i++;
	}
	return (c);
}