#pragma warning(disable:4996)
#include <stdio.h>
#define YES 1
#define NO 0
#define MAXLINE 1000

int main(void)
{
	char buffer[MAXLINE];
	gets(buffer);

	char c; // текущий символ
	int flag = NO; // признак слова
	int found = NO; // определение слова

	char* j = buffer; // позиция начала слова
	char* in_ptr = buffer; // (i) - позиция текущего символа
	char* out_ptr = buffer; // (pos) - позиция символа выхода
	char* word_ptr = buffer; // (start) - позиция начала слова

	do
	{
		c = *in_ptr; // взять текущий символ из буфера
		if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && (c != ' ' && c != '.' && c != ',' && c != '\n' && c != '\0' && c != '\t')) // проверка на не слово
		{
			found = YES;
		}
		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0')
		{
			// найден разделитель
			if (flag == YES)
			{
				for (j = word_ptr; j < in_ptr - 1; j++)
				{
					int c1 = *j;
					int c2 = *(j + 1);
					if ((c1 - 'A' == c2 - 'A' || c1 - 'a' == c2 - 'a' || c1 - 'a' == c2 - 'A' || c1 - 'A' == c2 - 'a') && (found != YES))
					{// проверка на: 1)заглавные буквы и условие задачи. 2) условие является ли слово "словом".
						for (j = word_ptr; j < in_ptr; j++)
							printf("%c", *j);
						break;
					}
				}
			}
			flag = NO;
			found = NO;
			printf("%c", *in_ptr); //пробелы для "нормальных слов" (по условию задачи)
		}
		else
		{
			if (flag == NO) // найдена буква
				word_ptr = in_ptr; // запомнить позицию начала слова
			flag = YES; //признак слова
		}
		in_ptr++; //переход к следующей ячейке буфера
	} while (c != '\0');
	return 0;
}
