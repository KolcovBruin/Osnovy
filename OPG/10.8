#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NO 0
#define YES 1

int main(void)
{
	int flag, flagRazdel, dlinaStr, strcnt, i;
	char** arr, * str, c;
	FILE* input, * output;

	// открытие файлов и проверка на ошибки
	if ((input = fopen("text.txt", "r")) == NULL || (output = fopen("result.txt", "w")) == NULL)
	{
		printf("Something went wrong\n");
		return -1;
	}
	arr = NULL;	// массив строк пустой
	str = NULL;		// текущая строка пустая
	flag = NO;		// опускаем флаг строки
	flagRazdel = NO;		// опускаем флаг пробела
	dlinaStr = 0;		// обнуляем длину строки
	strcnt = 0;		// обнуляем счетчик строк

	// повторяем пока не дойдем до конца файла
	do {
		c = fgetc(input);	// берем текущий символ из файла

		// если конец строки
		if (c == '\n' || c == EOF)
		{
			str = (char*)realloc(str, (dlinaStr + 2) * sizeof(char));	// выделяем память
			str[dlinaStr++] = '\n';	// записываем символ перевода строки
			str[dlinaStr] = '\0';		// записываем символ конца строки
			flag = YES;	// поднимаем флаг
			// проходим по всем сохраненным строкам
			for (i = 0; i < strcnt; i++)
			{
				// если текущая строка совпадает с уже найденной строкой
				if (strcmp(str, arr[i]) == 0)
				{
					flag = NO;	// опускаем флаг
					break;	// выходим из цикла
				}
			}

			// если флаг остался поднят
			if (flag == YES)
			{
				arr = (char**)realloc(arr, (strcnt + 1) * sizeof(char*));	// выделяем память в массиве строк
				arr[strcnt++] = str;		// записываем туда текущую строку
			}
			// если флаг был опущен
			else
			{
				free(str);	// удаляем текущую строку
			}

			str = NULL;		// строка пустая
			flagRazdel = NO;		// опускаем флаг разделителя
			flag = NO;		// опускаем флаг строки
			dlinaStr = 0;// обнуляем длину текущей строки
		}
		// если нашли пробел или табуляцию
		else if (c == ' ' || c == '\t')
		{
			// если строка началась и это первый разделитель
			if (flagRazdel == NO && flag == YES)
			{
				str = (char*)realloc(str, (dlinaStr + 1) * sizeof(char));		// выделяем память в строке
				str[dlinaStr++] = ' ';	// записываем в строку пробел
				flagRazdel = YES;// поднимаем флаг разделителя
			}
		}
		// иначе
		else
		{
			str = (char*)realloc(str, (dlinaStr + 1) * sizeof(char));	// выделяем память в строке
			str[dlinaStr++] = c;	// записываем в нее текущий символ
			flag = YES;		// поднимаем флаг строки
			flagRazdel = NO;		// опускаем флаг разделителя
		}
	} while (c != EOF);
	fclose(input);	// закрываем входной файл

	// проходим по всем сохраненным строкам
	for (i = 0; i < strcnt; i++)
	{
		fputs(arr[i], output);	// выводим строку в файл
		free(arr[i]);		// освобождаем выделенную память
	}
	fclose(output);	// закрываем выходной файл
	free(arr);	// освобождаем память
	system("pause");
	return 0;
}
