#include <iostream>
#include <fstream>
#include <vector>
#define Location_d "/Users/my/Desktop/проекты языка си/4 ява/4 ява/Data"
#define Location_r "/Users/my/Desktop/проекты языка си/4 ява/4 ява/Res"
using namespace std;
class House //описывает, то что мы можем выполнять с конкретными объектами
{
//private:
 
       string Address;
       int Floor;
       int Number_of_rooms;
       int Area;
   
public:
    void set()
    {
        cout<<"Введите Адрес "<<endl;
         cin>>Address;
        cout<<"Введите Этаж"<<endl;
         cin>>Floor;
        cout<<"Введите Кол-во комнат"<<endl;
         cin>>Number_of_rooms;
        cout<<"Введите Площадь"<<endl;
         cin>>Area;
    }
    void show() 
    {
       cout<<"Адрес: "<<Address<<endl;
        cout<<"Этаж: "<<Floor<<endl;
        cout<<"Кол-во комнат: "<<Number_of_rooms<<endl;
        cout<<"Площадь: "<<Area<<endl;
    }
    //несколько get чтобы, когда нам нужно вызвать одну переменную, мы не вызывали сразу все
    int get_Floor()
    {
        return Floor;
    }
    int get_Number_of_rooms()
    {
        return Number_of_rooms;
    }
    int get_Area()
    {
        return Area;
    }
    

};



int main(int argc, const char * argv[])
{

    int menu_1=0;
    int cnt=0;
    
    class House **Work;//объект
     Work=new House* [1];
    while (menu_1!=2)
    {
    cout<<"Меню:\n  1:Ввести еще одну квартиру \n  2:Перейти в меню поиска"<<endl;
    cin>>menu_1;
       //
        
    switch (menu_1) {
        case 1:
           
           
            
            Work[0]=new House[cnt+1];
            for(int i=0;i<cnt;i++)
                       {
                           Work[0][i]=Work[1][i];

                       }
            Work[1]=new House[cnt+1];

            Work[0][cnt].set();
            for(int i=0;i<cnt+1;i++)
            {
            Work[1][i]=Work[0][i];
            }
            
      
            cnt++;
            break;
    }
        
    }

    int menu_2=0;
    int N;
    int F_1; //для этажей
    int F_2;
    while (menu_2!=5)
    {
        cout<<"Меню:\n    1:Поиск квартир по заданному кол-ву комнат\n    2:Поиск квартир по заданному кол-ву комнат и расположенных между заданными этажами\n    3:Поиск квартир больше заданной площади\n    5:выход "<<endl;
        cin>>menu_2;
        int cnt_1;
        switch (menu_2) {
            case 1:
                 cout<<"Поиск квартир по заданному кол-ву комнат\n"<<"Введите необходимое число комнат"<<endl;
                cin>>N;
                for(int j=0;j<cnt;j++)
                {

                 if  ( Work[0][j].get_Number_of_rooms()==N)
                 {
                     
                     Work[0][j].get();
                     cout<<endl;
                 }
                }
                break;


                case 2:
                                cout<<"Поиск квартир по заданному кол-ву комнат и расположенных между заданными этажами\n"<<"Введите необходимое число комнат"<<endl;
                                               cin>>N;
                cout<<"Введите мин этаж"<<endl;

                                                cin>>F_1;
                 cout<<"Введите макс этаж"<<endl;
                                                cin>>F_2;
                                               for(int j=0;j<cnt;j++)
                                               {
                                                if  ( Work[0][j].get_Number_of_rooms()==N&&Work[0][j].get_Floor()<F_2&&Work[0][j].get_Floor()>F_1)
                                                {
                                                    Work[0][j].get();
                                                    cout<<endl;
                                                }
                                               }
                                               break;

                case 3:
                                 cout<<"Поиск квартир больше заданной площади\n"<<"Введите необходимую площадь"<<endl;
                                               cin>>N;
                cout<<"Квартиры превосходящие заданную площадь"<<endl;
                                               for(int j=0;j<cnt;j++)
                                               {
                                                if  ( Work[0][j].get_Area()>N)
                                                {
                                                    Work[0][j].get();
                                                    cout<<endl;
                                                }
                                               }
                                               break;
        }
    }
    cout<<"конец программы"<<endl;
    return 0;
}

