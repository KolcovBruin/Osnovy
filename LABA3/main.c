#include <stdio.h>
// определение символических констант
#define YES 1
#define NO 0
int main( void )
{
    
    int a;//счетчик букв в слове
    int o;//максимальое количество букв в слове
    int c;//введенный символ
    int flag;//флажок
    int found ;//флажок №2
    a=0;//начальное значение
    flag = NO;//начальное положение плажка
    o=0;//начальное
    found=NO;
    printf("Vvedide predlogenie");//вывод подсказки
    while( (c = getchar()) != EOF )
    {
        if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && (c != ' ' && c != '.' && c != ',' && c != '\n' && c != '\0' && c != '\t')) // проверка на не слово
        {
            found = YES;
         //   a=0;
        }
        /*if (c==' ')
        {found =NO;
            //a=0;
        }*/
        if( (c == ' ' || c == '.' || c == '\n' ||c == ','||c== EOF) && found != YES )//проверка на разделители
        {
            if( flag == YES )//проверка положения флажка
            {
                if(a  > o)//сравнение значения количества символов в слове и максимального значения
                {
                    o=a;//присваивание максимального значения
                }
                flag = NO;
                a=0;
            }
            found=NO;
            a=0;//обнуление значениячия числа символов
        }
        else if (c==' ')
        {found =NO;
            a=0;
        }
        
        
        //изменение положения флажка
        else {
           // if (found == YES)
           /* {
                found =NO;
                a=0;
            }*/
           
            a++;//подсчет символов
                flag = YES; }
        //изменение положения флажка
}
    printf("Kolichestvo simvolov v samom dlinnom slove = %d\n", o);
    return 0;
}

