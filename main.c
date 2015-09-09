#include "laba1.h"

void main(int argc, char *argv[])
{
	if(argc > 1)
	{
		FILE *file = 0;
		int opt = 0, flag = 0, sh = 0, ob = 0;
		int longIndex = 0;
		char *str = 0;
		str = (char *)calloc(N, sizeof(char));
		opt = getopt_long(argc, argv, optString, longOpts, &longIndex);
		while(opt != -1) 
		{	
			flag++;
			switch(opt)
			{
			case 'h': 
				puts("--file -f	Имя вашего файла");
				puts("--string -s	Символы для поиска");
				return;
			case 'f': 
				sh++;
				if (!file)
					file = fopen(optarg, "r");
				else
				{
					puts("Файл уже используется");
					break;
				}
				if (!file)
				{
					puts("Ошибка файла");
					return;
				}
				break;
			case 's': 
				ob++;
				strcpy(str, optarg);
				break;
			}
			opt = getopt_long(argc, argv, optString, longOpts, &longIndex);
			if (flag == 2)
			{
				if (sh == 1 && ob == 1)
					opt == -1;
				else
				{
					puts("Отсуствуют параметры для выполнеия программы!");
					puts("Введите --help для настойки");
					free(str);
					return;
				}
			}
		}
	func_r(file, str);
	fclose(file);
	free(str);
	}
	else 
	{
		puts("Отсуствуют параметры для выполнеия программы!");
		puts("Введите --help для настойки");
	}
	return;
}
