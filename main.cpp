#include <iostream>
#include <stdio.h>
#include <td/telegram/td_json_client.h>
#include <unistd.h>
#include <stdlib.h>
#include <cstdlib>
//const char *a = {"@type":"updateNewMessage","message":{"@type":"message","id":150994944,"sender_user_id":247504167,"chat_id":247504167,"is_outgoing":false,"can_be_edited":false,"can_be_forwarded":true,"can_be_deleted_only_for_self":true,"can_be_deleted_for_all_users":true,"is_channel_post":false,"contains_unread_mention":false,"date":1562433488,"edit_date":0,"reply_to_message_id":0,"ttl":0,"ttl_expires_in":0.000000,"via_bot_user_id":0,"author_signature":"","views":0,"media_album_id":"0","content":{"@type":"messageText","text":{"@type":"formattedText","text":"1","entities":[]}}}};
//const char *sender;
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
  td_json_client_send(client, "{\"@type\": \"checkDatabaseEncryptionKey\", \"key\":                   \"862204240:AAHFzvfzbI7cqO3StzUoSoEdFp0f6imLXvE\"}");
    //proxy
    td_json_client_send(client, "{\"@type\":\"addProxy\",\"type\":{\"@type\":\"proxyTypeSocks5\"},\"server\":\"45.77.66.109\", \"port\":33042,\"enable\":true}");
   // std::cout << "yyyy";
   // sleep(3);
    //token
  td_json_client_send(client, "{\"@type\": \"checkAuthenticationBotToken\", \"token\":     \"862204240:AAHFzvfzbI7cqO3StzUoSoEdFp0f6imLXvE\"}");
    const double WAIT_TIMEOUT = 10.0;  // seconds
    while (true) {
        const char *sender = "{\"@type\":\"sendMessage\",\"chat_id\":247504167,\"input_message_content\":{\"@type\":\"inputMessageText\",\"text\":{\"@type\":\"formattedText\",\"text\":\"1\"}}}";
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
                cnt=579;
                while (cnt<582)
                {
                
                a=*(result+cnt);
                b=(float)(a-'0');
                sum=sum+b;
                  c1=(char)(sum+'0');
                    
                cnt+=2;
                }
               
                char *forsnd=(char*)malloc(164);
                memcpy(forsnd,sender,164);
                memcpy((forsnd+135),&c1,sizeof(char));
                td_json_client_send(client,forsnd);
                //
               // *(sender+157)=sum;
                free(forsnd);
                sum=0;
            }
            }
            
            
            
            
           // std::cout << sender << std::endl;
            //"{\"@type\":     \"sendMessage\",\"chat_id\":247504167,\"input_message_content\":{\"@type\":\"inputMessageText\",\"text\":{\"@type\":\"formattedText\",\"text\":\"12\"}}}";
         //  const char* a;  const char *result = td_json_client_receive(client, WAIT_TIMEOUT);   a=result; //strcmp(result,"{\"@type\":\"updateChatLastMessage\",\"chat_id\":247504167,\"last_message\":{\"@type\":\"message\",\"id\":153092096,\"sender_user_id\":247504167,\"chat_id\":247504167,\"is_outgoing\":false,\"can_be_edited\":false,\"can_be_forwarded\":true,\"can_be_deleted_only_for_self\":true,\"can_be_deleted_for_all_users\":true,\"is_channel_post\":false,\"contains_unread_mention\":false,\"date\":1562439657,\"edit_date\":0,\"reply_to_message_id\":0,\"ttl\":0,\"ttl_expires_in\":0.000000,\"via_bot_user_id\":0,\"author_signature\":\"\",\"views\":0,\"media_album_id\":\"0\",\"content\":{\"@type\":\"messageText\",\"text\":{\"@type\":\"formattedText\",\"text\":\"1\",\"entities\":[]}}},\"order\":\"0\"}");
            //287309824
           /* if (strcmp(result,"{\"@type\":\"updateChatLastMessage\",\"chat_id\":247504167,\"last_message\":{\"@type\":\"message\",\"id\":153092096,\"sender_user_id\":247504167,\"chat_id\":247504167,\"is_outgoing\":false,\"can_be_edited\":false,\"can_be_forwarded\":true,\"can_be_deleted_only_for_self\":true,\"can_be_deleted_for_all_users\":true,\"is_channel_post\":false,\"contains_unread_mention\":false,\"date\":1562439657,\"edit_date\":0,\"reply_to_message_id\":0,\"ttl\":0,\"ttl_expires_in\":0.000000,\"via_bot_user_id\":0,\"author_signature\":\"\",\"views\":0,\"media_album_id\":\"0\",\"content\":{\"@type\":\"messageText\",\"text\":{\"@type\":\"formattedText\",\"text\":\"1\",\"entities\":[]}}},\"order\":\"0\"}")==0)
            {
           //standart
                 td_json_client_send(client,"{\"@type\":     \"sendMessage\",\"chat_id\":247504167,\"input_message_content\":{\"@type\":\"inputMessageText\",\"text\":{\"@type\":\"formattedText\",\"text\":\"12\"}}}");
            
            }*/
           /* if (result==a)
           {
              td_json_client_send(client,"{\"@type\":   \"sendMessage\",\"chat_id\":769409260,\"input_message_content\":{\"@type\":\"inputMessageText\",\"text\":{\"@type\":\"formattedText\",\"text\":\"21\"}}}");
           }*/
        }
        else
        {
           // td_json_client_send(client,sender);
        }
       
        /*      else
       {
           //xx
            td_json_client_send(client,"{\"@type\":   \"sendMessage\",\"chat_id\":769409260,\"input_message_content\":{\"@type\":\"inputMessageText\",\"text\":{\"@type\":\"formattedText\",\"text\":\"21\"}}}");
           //standart
        td_json_client_send(client,"{\"@type\":     \"sendMessage\",\"chat_id\":247504167,\"input_message_content\":{\"@type\":\"inputMessageText\",\"text\":{\"@type\":\"formattedText\",\"text\":\"12\"}}}");
           //koly
         td_json_client_send(client,"{\"@type\":     \"sendMessage\",\"chat_id\":404608177,\"input_message_content\":{\"@type\":\"inputMessageText\",\"text\":{\"@type\":\"formattedText\",\"text\":\"31\"}}}");
           //max
         td_json_client_send(client,"{\"@type\":     \"sendMessage\",\"chat_id\":494816052,\"input_message_content\":{\"@type\":\"inputMessageText\",\"text\":{\"@type\":\"formattedText\",\"text\":\"13\"}}}");
        }*/
    }
    td_json_client_destroy(client);
}
