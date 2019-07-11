#include <iostream>
#include <stdio.h>
#include <td/telegram/td_json_client.h>
#include <unistd.h>
#include <stdlib.h>
#include <cstdlib>
int br;
int cntn2;
int cntn1;
int k;
float rez1;
int rez2;
int cntn=0;
int x=1;
int j;
int i;
 char a;
char znak;
int cnt;
float b;
float sum;
char c1;
char *c;
int main()
{
    td_json_client_execute(nullptr, "{\"@type\":\"setLogVerbosityLevel\", \"new_verbosity_level\":0}");
    void *client = td_json_client_create();
   // std::cout << << std::endl;
    //tdlib infa
    td_json_client_send(client, "{\"@type\": \"setTdlibParameters\",\"parameters\":{\"database_directory\": \"tdlib\",\"use_message_database\": false,\"use_secret_chats\": true,\"api_id\":704839,\"api_hash\": \"f8503bbd9f7218c07a0d046a3dd9334d\", \"system_language_code\": \"ru\",\"device_model\": \"Desktop\",\"system_version\": \"Linux\",\"application_version\": \"1.0\",\"enable_storage_optimizer\": true}}");
    //key
  td_json_client_send(client, "{\"@type\": \"checkDatabaseEncryptionKey\", \"key\":\"862204240:AAHFzvfzbI7cqO3StzUoSoEdFp0f6imLXvE\"}");
    //proxy
    td_json_client_send(client, "{\"@type\":\"addProxy\",\"type\":{\"@type\":\"proxyTypeSocks5\"},\"server\":\"45.77.66.109\", \"port\":33042,\"enable\":true}");
   // std::cout << "yyyy";
   // sleep(3);
    //token
  td_json_client_send(client, "{\"@type\": \"checkAuthenticationBotToken\", \"token\":     \"862204240:AAHFzvfzbI7cqO3StzUoSoEdFp0f6imLXvE\"}");
    td_json_client_send(client," {\"type\": \"sendMessage\",\"reply_markup_\": {\"replyMarkupShowKeyboard\": {\"keyboardButton\":{\"text\":\"knopka\", \"type\":\"keyboardButtonTypeText\"}}, \"one_time\":true}}");
    std::cout << " {\"type\": \"sendMessage\",\"reply_markup_\": {\"replyMarkupShowKeyboard\": {\"keyboardButton\":{\"text\":\"knopka\", \"type\":\"keyboardButtonTypeText\"}}, \"one_time\":true}}}" << std::endl;
    
    const double WAIT_TIMEOUT = 10.0;  // seconds
    while (true) {
        const char *sender = "{\"@type\":\"sendMessage\",\"chat_id\":111111111,\"input_message_content\":{\"@type\":\"inputMessageText\",\"text\":{\"@type\":\"formattedText\",\"text\":\"1\"}}}";
     //   const char  *senderstart="{\"@type\":\"sendMessage\",\"chat_id\":111111111,\"input_message_content\":{\"@type\":\"inputMessageText\",\"text\":{\"@type\":\"formattedText\",\"text\":\"";
  //      const char *senderfinish="\"}}}";
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
                char *forresult=(char*)malloc(800);
                 memset(forresult,'\0',800);
                memcpy(forresult,result,800);
                char *forsnd=(char*)malloc(200);
                memcpy(forsnd,sender,200);
                char *math=(char*)malloc(300);
                memset(math,'\0',300);
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
                                            
                                            memcpy((forsnd+i-9),&a,sizeof(char));
                                           
                                            
                                        }
                                        else
                                        {
                                            i=-10;
                                        }
                                    }
                                }
                            }
                        }
                        
                    }
                }
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
                                    a=*(forresult+i);
                                    if (a!=',')
                                    {
                                        
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
                                            rez1*=b;
                                            std::cout <<rez1<< std::endl;
                                            cntn2=j-i;
                                            rez2+=cntn2;
                                            //delete stroka
                                            x=1;
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
                                               std::cout <<forresult<< std::endl;
                                                //sleep(1);
                                            }
                                            for (j=j+1;j<=1000;j++)
                                            {
                                                memcpy(forresult+j,forresult+i+cntn2+1,sizeof(char));
                                                i++;
                                                std::cout <<forresult<< std::endl;
                                                //sleep(2);
                                            }
                                            br=1;
                                            i=580;
                                        }
                                        
                                            std::cout <<forresult<< std::endl;
                                           // sleep(2);
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
                                                std::cout <<rez1<< std::endl;
                                                cntn2=j-i;
                                                rez2+=cntn2;
                                                //delete stroka
                                                x=1;
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
                                                    std::cout <<forresult<< std::endl;
                                                    //sleep(1);
                                                }
                                                for (j=j+1;j<=1000;j++)
                                                {
                                                    memcpy(forresult+j,forresult+i+cntn2+1,sizeof(char));
                                                    i++;
                                                    std::cout <<forresult<< std::endl;
                                                    //sleep(2);
                                                }
                                                std::cout <<forresult<< std::endl;
                                                
                                            
                                           /* if (znak=='+')
                                            {
                                                sum+=b;
                                                znak='0';
                                                std::cout <<sum<< std::endl;
                                                
                                            }*/
                                                br=1;
                                                i=580;
                                        }
                                        
                                        
                                        
                                        b=0;
                                        x=1;
                                        j=0;
                                        rez2=0;
                                        cntn=0;
                                        cntn1=0;
                                        cntn2=0;
                                        rez1=0;
                                        //i=580;
                                        /*if (a=='/')
                                        {
                                            znak=a;
                                            x=1;
                                            sum+=b;
                                            b=0;
                                        }*/
                                        /*if (a>='0'&&a<='9')
                                        {
                                            b*=x;
                                            b+=(float)(a-'0');
                                            x=10;
                                        }*/
                                        }
                                    else
                                    {
                                        j=580;
                                        while (j>0)
                                        {
                                            a=*(forresult+j);
                                            if (a!=',')
                                            {
                                               // a=*(forresult+i);
                                                //x=1;
                                                
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
                                               
                                                if (a=='+')
                                                {
                                                    znak=a;
                                                    sum+=b;
                                                    b=0;
                                                }
                                                
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
                                                
                                                else if (znak=='-')
                                                {
                                                    sum-=b;
                                                    b=0;
                                                    znak='0';
                                                }
                                            }
                                            else
                                            {
                                                std::cout <<sum<< std::endl;
                                               // sleep(3);
                                                j=-10;
                                            }
                                            
                                        }
                                        j=-10;
                                        i=-10;
                                    }
                                    br=0;
                                   
                                    
                                }
                                x=1;
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
                                
                                        //i=-10;
                            }
                                
                          }
                        }
                    }
                }
                
               /* cnt=579;
                while (cnt<582)
                {
                
                a=*(result+cnt);
                b=(float)(a-'0');
                sum=sum+b;
                  c1=(char)(sum+'0');
                    
                cnt+=2;
                }*/
               //внесение изменений в отправляемую строку
                
                //memcpy((forsnd+135),&c1,sizeof(char));
                td_json_client_send(client,math);
                cntn=0;
                x=1;
                //
               // *(sender+157)=sum;
                free(forsnd);
                free(math);
                free(forresult);
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
