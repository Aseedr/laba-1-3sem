#include "laba1.h"

void func_r(FILE *file, char *str)
{
	FILE *file_write = 0;
	file_write = fopen("vivod.txt", "w");

	int stop = 0, i = 0, flag = 0, z = 0;
	while(str[i])
	{
		i++; stop++;
	};
	
	char *st; int start, kol, j;
	st = (char *)calloc(N, sizeof(char));
	__fpurge(stdin);

	while(fgets(st, N, file))
	{
		__fpurge(stdin);
		start = 0; kol = 0;
		for(i = 0; i < N; i++)
		{
			if(st[i] == ' ')
			{	
				flag = 0;
				for(j = 0; j < stop; j++)
				{
					for(z = start; z < i; z++)
					{
						if(st[z] == str[j])
						{
							flag++;
							break;
						}
					}
				}
				if(flag == stop)
					kol++;
				do
				{
					i++;
					start = i;
				}while(st[i] == ' ');
			}
			if(st[i] == '\n')
			{
				flag = 0;
				for(j = 0; j < stop; j++)
				{
					for(z = start; z < i; z++)
					{
						if(st[z] == str[j])
						{
							flag++;
							break;
						}
					}
				}
				if(flag == stop)
					kol++;
				break;
			}
		}
		fprintf(file_write, "%d\n", kol);
		free(st);
		st = (char *)calloc(N, sizeof(char));
	};
	free(st);
	fclose(file_write);
	return;
}
