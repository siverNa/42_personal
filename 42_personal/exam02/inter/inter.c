#include <unistd.h>

int main(int argc, char *argv[])
{
	int i;
	int j;
	int temp;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		j = 0;
		while (argv[2][j])
		{
			if (argv[1][i] == argv[2][j])
			{	
				temp = i;
				while (argv[1][--temp] && temp >= 0)
				{	
					if (argv[1][temp] == argv[1][i])
						break;
				}
				if (temp < 0)
					write(1, &argv[1][i], 1);
				break;
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}
