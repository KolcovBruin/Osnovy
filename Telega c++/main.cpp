#include <iostream>
#include <stdio.h>
#include <td/telegram/td_json_client.h>
#include <unistd.h>
#include <stdlib.h>
#include <cstdlib>
//https://tdlib.github.io/td/build.html для компиляции библиотеки

//https://core.telegram.org/tdlib/docs/annotated.html. самая полезная страницы для познания tdlib!!!!!!
//бот написан очень сыро, можно очень многое оптимизировать, ввести функции и тп, но сил нет, все желающим разобраться желаю удачи
int rezf;//результат умножения на случай отсутствия сложения
int br;//лишняя переменная, лень чистить
int cntn2;//счетчик колва разрядов
int cntn1;//счетчик колва разрядов для другого числа
int cntn3=0;//счетчик колва разрядов для еще какогото числа
int k;//запоминает колво символов для отступа
float rez1;//резу для умножений
int rez2;//колво символов для умножений
int cntn=0;//счетчик числа разрядов гдето
int x=1;//множетель на разряды
int j;//чиклы
int i;//циклы
 char a;//переменная в которую загоняли кучу раз разные значения из разынх строк
char znak;//действие арифметическое
int cnt;
float b;//число для вывода в отправляемое сообщение
float sum;//результат действий для вывода в отпр сообщение
char c1;//переменная для вставки в отпр строку
char *c;
int main()
{
    td_json_client_execute(nullptr, "{\"@type\":\"setLogVerbosityLevel\", \"new_verbosity_level\":0}");//какаято фигня для задание параметров в библиотеку
    void *client = td_json_client_create();//чтото для задания клиента
   // std::cout << << std::endl;
    //tdlib infa
    //Параметры для библиотеки
    td_json_client_send(client, "{\"@type\": \"setTdlibParameters\",\"parameters\":{\"database_directory\": \"tdlib\",\"use_message_database\": false,\"use_secret_chats\": true,\"api_id\":704839,\"api_hash\": \"f8503bbd9f7218c07a0d046a3dd9334d\", \"system_language_code\": \"ru\",\"device_model\": \"Desktop\",\"system_version\": \"Linux\",\"application_version\": \"1.0\",\"enable_storage_optimizer\": true}}");
    //key
    //Ключ, нужен библиотеки не важно занчение
  td_json_client_send(client, "{\"@type\": \"checkDatabaseEncryptionKey\", \"key\":\"111111\"}");
    //proxy
    //Прокси, Привет Роскомнадзор
    td_json_client_send(client, "{\"@type\":\"addProxy\",\"type\":{\"@type\":\"proxyTypeSocks5\"},\"server\":\"95.216.224.183\", \"port\":1080,\"enable\":true}");
   // std::cout << "yyyy";
   // sleep(3);
    //token
    //Токен, для определения бота к которому подключаться, записывается в библиотеку, перезаписать не получится программой, только если в файл
  td_json_client_send(client, "{\"@type\": \"checkAuthenticationBotToken\", \"token\":     \"111111\"}");
   
    
    
   // sleep(10);
    //Строка для теста json-язык текста, который умеет читать тдлиб и телеграм. Английский чиается адекватно, русский в кодировки аски
    std::cout <<"{\"@type\":\"sendMessage\",\"chat_id\":247504167,\"input_message_content\":{\"@type\":\"inputMessageText\",\"text\":{\"@type\":\"formattedText\",\"text\":\"инструкции к применению:\n Ниже перечислены все функции калькулятора.\nЭтот перечень поможет Вам использовать калькулятор онлайн для решения своих задач в бизнесе, работе и учёбе.\nВыполняемые операции:\n + сложение\n - вычитание\n * умножение\n / деление.\"}}}" << std::endl;
    //Тайм аут, хех
    const double WAIT_TIMEOUT = 10.0;  // seconds
    while (true) {
        //строка для отправки, занесена сюда для дальнейших изменений, замены id chat и текста в строке
        const char *sender = "{\"@type\":\"sendMessage\",\"chat_id\":247504167,\"input_message_content\":{\"@type\":\"inputMessageText\",\"text\":{\"@type\":\"formattedText\",\"text\":\"1\"}}}";
        //строка для отправки кнопок, таже причина
        const char *knpki ="{\"@type\":\"sendMessage\",\"chat_id\":247504167,\"input_message_content\":{\"@type\":\"inputMessageText\",\"text\":{\"@type\":\"formattedText\",\"text\":\"Hello,World\"}},\"reply_markup\": {\"@type\": \"replyMarkupShowKeyboard\", \"rows\":[ [{\"@type\": \"keyboardButton\", \"text\":\"options\", \"type\": {\"@type\": \"keyboardButtonTypeText\"}}],[{\"@type\": \"keyboardButton\", \"text\":\"donation\", \"type\": {\"@type\": \"keyboardButtonTypeText\"}}]]}}" ;
        //строка отправки других кнопок
        const char *reznaknopki ="{\"@type\":\"sendMessage\",\"chat_id\":247504167,\"input_message_content\":{\"@type\":\"inputMessageText\",\"text\":{\"@type\":\"formattedText\",\"text\":\"Инструкции к применению:\nНиже перечислены все функции калькулятора.\nЭтот перечень поможет Вам использовать калькулятор онлайн для решения своих задач в бизнесе, работе и учёбе.\nВыполняемые операции:\n + сложение\n - вычитание\n * умножение\n / деление.\"}}}";
        //Текст реакции на кнопку donation
        const char *donation ="{\"@type\":\"sendMessage\",\"chat_id\":247504167,\"input_message_content\":{\"@type\":\"inputMessageText\",\"text\":{\"@type\":\"formattedText\",\"text\":\"Мы Вас любим и ценим 😱❤️😱\"}}}";
        const char *result = td_json_client_receive(client, WAIT_TIMEOUT); //возврат данных от телеги
       
        if (result != nullptr)  //результат не ноль
        {
            std::cout << result << std::endl;  //вывод приходящих данных
            
            a=*(result+20);   //буква из Last Message
            if (a=='L')   //проверка на посл сообщение
            {
                a=*(result+164);  //"is_outgoing":true проверяем true/false
            
            if (a=='f')   //проверка
            {
                //td_json_client_send(client,"{\"@type\":\"sendMessage\",\"chat_id\":247504167,\"input_message_content\":{\"@type\":\"inputMessageText\",\"text\":{\"@type\":\"formattedText\",\"text\":\"1\"}},\"reply_markup\": {\"@type\": \"replyMarkupShowKeyboard\", \"rows\":[ [{\"@type\": \"keyboardButton\", \"text\":\"options\", \"type\": {\"@type\": \"keyboardButtonTypeText\"}}],[{\"@type\": \"keyboardButton\", \"text\":\"menu\", \"type\": {\"@type\": \"keyboardButtonTypeText\"}}]]}}");
                //внесение в память строк, тк строки в char, а чар можно только читать по адресу и нельзя менять || \0 для заполнения пустых клеток, тк иначе конфликт некоторых других значений с нужными
                char *forresult=(char*)malloc(800);
                 memset(forresult,'\0',800);
                memcpy(forresult,result,800);
                char *forsnd=(char*)malloc(200);
                memcpy(forsnd,sender,200);
                char *math=(char*)malloc(300);
                memset(math,'\0',300);
                char *knopki=(char*)malloc(800);
              //  memset(knopki,'\0',800);
                memcpy(knopki,knpki,800);
                char *rezalt=(char*)malloc(800);
                memcpy(rezalt,reznaknopki,800);
                char *don=(char*)malloc(800);
                memcpy(don,donation,800);
                //нахождение места записи chat id
                for(i=0;i>=0;i++)
                {
                    a=*(result+i);
                    if (a=='c')
                    {
                        a=*(result+i+1);
                        if(a=='h')
                        {
                            for(i=i;i>=0;i++)
                            {
                                a=*(result+i);
                                if(a==':')
                                {
                                    for(i=i;i>=0;i++)
                                    {
                                        a=*(result+i+1);
                                        if (a!=',')
                                        {
                                            //запись id в нужные строки
                                            memcpy((forsnd+i-9),&a,sizeof(char));
                                            memcpy((knopki+i-9),&a,sizeof(char));
                                            memcpy((rezalt+i-9),&a,sizeof(char));
                                           memcpy((don+i-9),&a,sizeof(char));
                                            
                                        }
                                        else
                                        {
                                            //выход из циклов for
                                            i=-10;
                                        }
                                    }
                                }
                            }
                        }
                        
                    }
                }
                //поиск места с текстом получаемого сообщения
                for(i=0;i>=0;i++)
                {
                    a=*(forresult+i);
                    if(a=='m')
                    {
                        a=*(forresult+i+1);
                        if(a=='a')
                        {
                        for(i=i;i>=0;i++)
                        {
                            a=*(forresult+i);
                            if(a==':')
                            {
                                for(i=i;i>=0;i++)
                                {
                                    //проверка строки для реакции на команду /start
                                    a=*(forresult+i+3);
                                    if(a=='s')
                                    {
                                        a=*(forresult+i+4);
                                        if(a=='t')
                                        {
                                            td_json_client_send(client,knopki);
                                             std::cout << knopki << std::endl;
                                             goto end;
                                            break;
                                           
                                        }
                                    }
                                    //проверка строки для реакции на кнопку option
                                    a = *(forresult + i + 2);
                                    if (a == 'o')
                                    {
                                        a = *(forresult + i + 3);
                                        if (a == 'p')
                                        {
                                            a = *(forresult + i + 4);
                                            if (a == 't')
                                            {
                                                td_json_client_send(client,rezalt);
                                               goto end;
                                                break;
                                            }
                                            
                                            
                                        }
                                    }
                                     //проверка строки для реакции на кнопку donation
                                    a = *(forresult + i + 2);
                                    if (a == 'd')
                                    {
                                        a = *(forresult + i + 3);
                                        if (a == 'o')
                                        {
                                            a = *(forresult + i + 4);
                                            if (a == 'n')
                                            {
                                                td_json_client_send(client,don);
                                                 goto end;
                                                break;
                                            }
                                            
                                            
                                        }
                                    }
                                    a=*(forresult+i);
                                    //на запятой заканчивается текст сообщения
                                    if (a!=',')
                                    {
                                        //умножение
                                        if (a=='*')
                                        {
                                            b=0;
                                            x=1;
                                            j=i;
                                            a=*(forresult+j-1);
                                            while (a>='0'&&a<='9')
                                            {
                                                 j--;
                                                a=*(forresult+j-1);
                                               
                                            }
                                            //определение колва цыфр слева от *
                                            cntn1=i-j;
                                            //Вычесление значения числа слева от *
                                            for(j=i-cntn1;j<i;j++)
                                            {
                                                a=*(forresult+j);
                                                if (a>='0'&&a<='9')
                                                {
                                                    b*=x;
                                                    b+=(float)(a-'0');
                                                    std::cout <<b<< std::endl;
                                                    x=10;
                                                }
                                                else break;
                                            }
                                            rez1=b;
                                            std::cout <<rez1<< std::endl;
                                            //колво символов слева от *
                                            rez2=cntn1;
                                            b=0;
                                            x=1;
                                            //тоже самое справа
                                            for (j=i;j>0;j++)
                                            {
                                                
                                                a=*(forresult+j+1);
                                                if (a>='0'&&a<='9')
                                                {
                                                    
                                                    b*=x;
                                                    b+=(float)(a-'0');
                                                    x=10;
                                                }
                                                else break;
                                            }
                                            //результат умножения
                                            rez1*=b;
                                            rezf=rez1;
                                          
                                            cntn2=j-i;
                                            rez2+=cntn2;
                                          
                                            x=1;
                                            //запись результата в строку принятого сообщения, так надо, Пример: 12+5*4=12+20, Для правильного порядка действий, чтобы по итогу остались только минусы и плюсы
                                             while ((int)(rez1/x)>=1)
                                             { x*=10;
                                                 cntn++;
                                             }
                                            k=j+cntn-rez2-1;
                                            //j=i-cntn1;
                                            for (j=i-cntn1-1;j<(i-cntn1+cntn)-1;j++)
                                            {
                                                 x/=10;
                                                c1=(char)(rez1/x)+'0';
                                                std::cout <<c1<< std::endl;
                                                memcpy(forresult+j+1,&c1,sizeof(char));
                                                rez1=rez1-int(rez1/x)*x;
                                            }
                                            for (j=j+1;j<=1000;j++)
                                            {
                                                memcpy(forresult+j,forresult+i+cntn2+1,sizeof(char));
                                                i++;
                                            }
                                            br=1;
                                            i=580;
                                        }
                                        a=*(forresult+i);
                                        //деление это * копи паст
                                            if (a=='/')
                                            {
                                                b=0;
                                                x=1;
                                                j=i;
                                                a=*(forresult+j-1);
                                                while (a>='0'&&a<='9')
                                                {
                                                    j--;
                                                    a=*(forresult+j-1);
                                                    
                                                }
                                                cntn1=i-j;
                                                for(j=i-cntn1;j<i;j++)
                                                {
                                                    a=*(forresult+j);
                                                    if (a>='0'&&a<='9')
                                                    {
                                                        b*=x;
                                                        b+=(float)(a-'0');
                                                        std::cout <<b<< std::endl;
                                                        x=10;
                                                    }
                                                    else break;
                                                }
                                                rez1=b;
                                                std::cout <<rez1<< std::endl;
                                                rez2=cntn1;
                                                b=0;
                                                x=1;
                                                
                                                for (j=i;j>0;j++)
                                                {
                                                    
                                                    a=*(forresult+j+1);
                                                    if (a>='0'&&a<='9')
                                                    {
                                                        
                                                        b*=x;
                                                        b+=(float)(a-'0');
                                                        x=10;
                                                    }
                                                    else break;
                                                }
                                                rez1/=b;
                                                rezf=rez1;
                                                std::cout <<rez1<< std::endl;
                                                cntn2=j-i;
                                                rez2+=cntn2;
                                                
                                                x=1;
                                                while ((int)(rez1/x)>=1)
                                                { x*=10;
                                                    cntn++;
                                                }
                                                k=j+cntn-rez2-1;
                                               
                                                for (j=i-cntn1-1;j<(i-cntn1+cntn)-1;j++)
                                                {
                                                    x/=10;
                                                    c1=(char)(rez1/x)+'0';
                                                    std::cout <<c1<< std::endl;
                                                    memcpy(forresult+j+1,&c1,sizeof(char));
                                                    rez1=rez1-int(rez1/x)*x;
                                                }
                                                for (j=j+1;j<=1000;j++)
                                                {
                                                    memcpy(forresult+j,forresult+i+cntn2+1,sizeof(char));
                                                    i++;
                                                }
                                                std::cout <<forresult<< std::endl;
                                                br=1;
                                                i=580;
                                        }
                                        
                                        
                                       // здесь обнуление всех параметров которые нужны чтобы принять сразу сл сообщение и выдать правильный результат
                                        b=0;
                                        x=1;
                                        j=0;
                                        rez2=0;
                                        cntn=0;
                                        cntn1=0;
                                        cntn2=0;
                                        //rezf=rez1;
                                        rez1=0;
                                        }
                                    else
                                    {
                                        //Выполнение +/- после очистки всей строки от *&/
                                        j=580;
                                        while (j>0)
                                        {
                                            a=*(forresult+j);
                                            if (a!=',')
                                            {
                                                //Переведение чар в флоат(для этого есть функции встроенных библиотек) было реализовано руками для общего понимания, можно не разбирать это
                                                    while (j>0)
                                                    {
                                                         a=*(forresult+j);
                                                         j++;
                                                        if (a>='0'&&a<='9')
                                                        {
                                                   
                                                    b*=x;
                                                    b+=(float)(a-'0');
                                                    x=10;
                                                    }
                                                       
                                                        else
                                                        {
                                                            i=j;
                                                            break;
                                                        }
                                                        
                                                }
                                               //логично
                                                if (a=='+')
                                                {
                                                    cntn3++;
                                                    znak=a;
                                                    sum+=b;
                                                    b=0;
                                                    
                                                }
                                                //проверка что это второе слагаемое а не вычитаемое
                                               else if (znak=='+')
                                                {
                                                    sum+=b;
                                                    b=0;
                                                    znak='0';
                                                }
                                                if (a=='-')
                                                {
                                                    znak=a;
                                                    sum+=b;
                                                    b=0;
                                                }
                                                //тоже самое
                                                else if (znak=='-')
                                                {
                                                    cntn3++;
                                                    sum-=b;
                                                    b=0;
                                                    znak='0';
                                                }
                                            }
                                            else
                                            {
                                                std::cout <<sum<< std::endl;
                                               // sleep(3);
                                                //выход из циклов
                                                j=-10;
                                            }
                                            
                                        }
                                        //не знаю зачем, но работает не трошь
                                        j=-10;
                                        
                                    }
                                    //лишняя переменная
                                    br=0;
                                   
                                    
                                }
                                x=1;
                                //вывод результирующий строки
                                if (cntn3==0)  sum=rezf;
                                       while ((int)(sum/x)>=1)
                                        {
                                            x*=10;
                                            cntn++;
                                        }
                                    //x=0;
                                    for (j=0;j<139+cntn;j++)
                                    {
                                        if (j<=134)
                                        {
                                            memcpy(math+j,forsnd+j,sizeof(char));
                                        }
                                        else if ((j>134)&&(j<=134+cntn))
                                        {
                                            x/=10;
                                            c1=(char)(sum/x)+'0';
                                            memcpy(math+j,&c1,sizeof(char));
                                            sum=sum-int(sum/x)*x;
                                        }
                                        else
                                        {
                                            memcpy(math+j,forsnd+(j-cntn+1),sizeof(char));
                                        }
                                    }
                                    
                                
                                sum=0;
                                x=1;
                                
                                
                            }
                                
                          }
                        }
                    }
                }
                
               
                td_json_client_send(client,math);
            end:
                cntn=0;
                x=1;
                cntn3=0;
                //
               // *(sender+157)=sum;
                // memset(forresult,'5',800);
               // memset(math,'5',300);
                free(forsnd);
                free(math);
                free(forresult);
                free(knopki);
                free (rezalt);
                free (don);
                i=0;
                j=0;
                 std::cout <<"finish"<< std::endl;
                //sum=0;
            }
            }
        }
        
    }
    td_json_client_destroy(client);
}
