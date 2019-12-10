#include <iostream>
#include <fstream>
#include <vector>
#define Location_d "/Users/my/Desktop/проекты языка си/4 ява/4 ява/Data"
#define Location_r "/Users/my/Desktop/проекты языка си/4 ява/4 ява/Res"
using namespace std;
class House
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
    void get()
    {
       cout<<"Адрес: "<<Address<<endl;
        cout<<"Этаж: "<<Floor<<endl;
        cout<<"Кол-во комнат: "<<Number_of_rooms<<endl;
        cout<<"Площадь: "<<Area<<endl;
    }
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
    
    
//    void set_Address()
//    {
//    cin>>Address;
//        cout<<Address;
//    }
//    void set_Floor()
//    {
//        cin>>Floor;
//    }
//    void set_Number_of_rooms()
//    {
//        cin>>Number_of_rooms;
//    }
//    void set_Area()
//    {
//        cin>>Area;
//    }
//    int get_Address()
//    {
//        return Address;
//    }
};



int main(int argc, const char * argv[])
{

    int menu_1=0;
    int cnt=0;
    
    class House Work;
    vector<House> Home;
//    for(int i=0;i<3;i++)
//    {
//    Work.set();
//     Home.push_back(Work);
//    }
    while (menu_1!=2)
    {
    cout<<"Меню:\n  1:Ввести еще одну квартиру \n  2:Перейти в меню поиска"<<endl;
    cin>>menu_1;
    
    switch (menu_1) {
        case 1:
             Work.set();
                Home.push_back(Work);
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
        
        switch (menu_2) {
            case 1:
                 cout<<"Поиск квартир по заданному кол-ву комнат\n"<<"Введите необходимое число комнат"<<endl;
                cin>>N;
                for(int j=0;j<cnt;j++)
                {
                    Work=Home[j];
                 if  ( Work.get_Number_of_rooms()==N)
                 {
                     Work.get();
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
                                                   Work=Home[j];
                                                if  ( Work.get_Number_of_rooms()==N&&Work.get_Floor()<F_2&&Work.get_Floor()>F_1)
                                                {
                                                    Work.get();
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
                                                   Work=Home[j];
                                                if  ( Work.get_Area()>N)
                                                {
                                                    Work.get();
                                                    cout<<endl;
                                                }
                                               }
                                               break;
        }
    }
    cout<<"конец программы"<<endl;
  
  
    
//    class cwc
//    {
//      int c;
//      int d;
//
//      public:
//        cwc (int a) {c=a; d=a;
//             std::cout <<c<< "\n"<<d<<"\n";
//        } /* конструктор №1 */
//
//        cwc (int a, int b) {c=a; d=b; /* конструктор №2 */
//        std::cout <<c<< "\n"<<d<<"\n";
//        }
//    };
//    cwc (5);
//    cwc (100,56);
//    char a,b,c;
//    ifstream f;
//    ofstream f1;
//    char str[40];
//
//    f.open (Location_d);
//    f>>a;
//    f>>b;
//    f>>c;
//    f.close();
//    cout<<"\n Recorded number  A="<<a;
//    b=a+a;
//    cout<<"\n b="<<b;
//
//    f1.open(Location_r);
//    f1<<b;
//    f1.close();
//    cout<<endl;
//
//    // insert code here...

    return 0;
}

