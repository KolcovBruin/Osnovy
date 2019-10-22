#include <stdio.h>
 #define Location_data "/Users/my/Desktop/проекты языка си/Курсач 🥰/Курсач 🥰/Data"
main ()
{
    FILE *file;
    struct food
    {
        char name[20];
        unsigned qty;
        float price;
    };
    struct food shop[10];
    char i=0;
 
    file = fopen(Location_data, "r");
 
    while (fscanf (file, "%s%u%f", shop[i].name, &(shop[i].qty), &(shop[i].price)) != EOF) {
        printf("%s %u %.2f\n", shop[i].name, shop[i].qty, shop[i].price);
        i++;
    }
}
