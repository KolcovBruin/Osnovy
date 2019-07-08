#include <iostream>
#include <stdio.h>
#include <td/telegram/td_json_client.h>
#include <unistd.h>
#include <stdlib.h>
#include <cstdlib>
int i;
 char a;
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
    const double WAIT_TIMEOUT = 10.0;  // seconds
    while (true) {
        const char *sender = "{\"@type\":\"sendMessage\",\"chat_id\":111111111,\"input_message_content\":{\"@type\":\"inputMessageText\",\"text\":{\"@type\":\"formattedText\",\"text\":\"1\"}}}";
        const char *result = td_json_client_receive(client, WAIT_TIMEOUT); //возврат данных от телеги
        if (result != nullptr)  //результат не ноль
        {
            std::cout << result << std::endl;  //вывод приходящих данных
            
            a=*(result+20);   //буква из Last Message
            if (a=='L')   //проверка на посл сообщение
            {
                a=*(result+163);  //"is_outgoing":true проверяем true/false
            
            if (a=='f')   //проверка
            {
                char *forsnd=(char*)malloc(164);
                memcpy(forsnd,sender,164);
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
                cnt=579;
                while (cnt<582)
                {
                
                a=*(result+cnt);
                b=(float)(a-'0');
                sum=sum+b;
                  c1=(char)(sum+'0');
                    
                cnt+=2;
                }
               //внесение изменений в отправляемую строку
                
                memcpy((forsnd+135),&c1,sizeof(char));
                td_json_client_send(client,forsnd);
                //
               // *(sender+157)=sum;
                free(forsnd);
                sum=0;
            }
            }
        }
        
    }
    td_json_client_destroy(client);
}
