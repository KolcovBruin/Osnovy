#include <stdio.h> // необходимо для корректного вызова
//функций ввода/вывода
int main( void ) // главная функция main не принимает данных от операционной системы, возвращает статус завершения
{  // начало тела программы
    // описание переменных
    float V; //объём бассейна
    float v1;//скорость вытекания воды
    float v2;//скорость поступления воды
    //v1>v2 v2-?
    float t;//время вытекания всей воды
    // ввод исходных данных
    // вывод на экран подсказки: V =
    printf("V = ");
    // ввод с клавиатуры значения переменной V
    scanf("%f", &V);
    // вывод на экран подсказки: v1 =
    printf("v1 = ");
    // ввод с клавиатуры значения переменной v1
    scanf("%f", &v1);
    // вывод на экран подсказки: t =
    printf("t = ");
    // ввод с клавиатуры значения переменной t
    scanf("%f", &t);
    // решение задачи
    v2=-V/t+v1;//вычисление скорости поступления воды
    // вывод результатов
    // вывод на экран значения переменной v2
    printf("speed = %f\n", v2);
    // программа возвращается  признак корректного
    // завершения
    return 0;
} // конец тела программы