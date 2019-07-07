#include <iostream>
#include <td/telegram/td_json_client.h>
#include <unistd.h>
//const char *a = {"@type":"updateNewMessage","message":{"@type":"message","id":150994944,"sender_user_id":247504167,"chat_id":247504167,"is_outgoing":false,"can_be_edited":false,"can_be_forwarded":true,"can_be_deleted_only_for_self":true,"can_be_deleted_for_all_users":true,"is_channel_post":false,"contains_unread_mention":false,"date":1562433488,"edit_date":0,"reply_to_message_id":0,"ttl":0,"ttl_expires_in":0.000000,"via_bot_user_id":0,"author_signature":"","views":0,"media_album_id":"0","content":{"@type":"messageText","text":{"@type":"formattedText","text":"1","entities":[]}}}};
int main()
{
    td_json_client_execute(nullptr, "{\"@type\":\"setLogVerbosityLevel\", \"new_verbosity_level\":0}");
    void *client = td_json_client_create();
    std::cout << "{\"@type\":\"addProxy\",\"type\":{\"@type\":\"proxyTypeMtproto\",\"secret\":\"ddfb175d6d7f820cdc73ab11edbdcdbd74\"},\"server\":\"   ru.tgproxy.today\", \"port\":8080}"<< std::endl;
    td_json_client_send(client, "{\"@type\": \"setTdlibParameters\",\"parameters\":{\"database_directory\": \"tdlib\",\"use_message_database\": true,\"use_secret_chats\": true,\"api_id\":704839,\"api_hash\": \"f8503bbd9f7218c07a0d046a3dd9334d\", \"system_language_code\": \"ru\",\"device_model\": \"Desktop\",\"system_version\": \"Linux\",\"application_version\": \"1.0\",\"enable_storage_optimizer\": true}}");
    
  td_json_client_send(client, "{\"@type\": \"checkDatabaseEncryptionKey\", \"key\":                   \"862204240:AAHFzvfzbI7cqO3StzUoSoEdFp0f6imLXvE\"}");
    td_json_client_send(client, "{\"@type\":\"disableProxy\"}");
    std::cout << "xxxx";
    //sleep(5);
    td_json_client_send(client, "{\"@type\":\"addProxy\",\"type\":{\"@type\":\"proxyTypeSocks5\"},\"server\":\"45.77.138.197\", \"port\":31762,\"enable\":true}");
    //"{\"@type\":\"addProxy\",\"type\":{\"@type\":\"proxyTypeMtproto\",\"secret\":\"ddfb175d6d7f820cdc73ab11edbdcdbd74\"},\"server\":\"   195.19.203.74\", \"port\":8080,\"enable\":true}"
    std::cout << "yyyy";
    //td_json_client_send(client, "{\"@type\":\"enableProxy\", \"proxy_id\":4}");
   // sleep(3);
   //td_json_client_send(client, "{\"@type\":\"connectionStateConnectingToProxy\", \"get_id\":3}");
  td_json_client_send(client, "{\"@type\": \"checkAuthenticationBotToken\", \"token\":     \"862204240:AAHFzvfzbI7cqO3StzUoSoEdFp0f6imLXvE\"}");
    const double WAIT_TIMEOUT = 10.0;  // seconds
    while (true) {
       // a=td_json_client_receive(client, WAIT_TIMEOUT);
        const char *result = td_json_client_receive(client, WAIT_TIMEOUT);
        if (result != nullptr)
        {
            std::cout << result << std::endl;
            if (strcmp(result,"{\"@type\":\"updateChatLastMessage\",\"chat_id\":247504167,\"last_message\":{\"@type\":\"message\",\"id\":153092096,\"sender_user_id\":247504167,\"chat_id\":247504167,\"is_outgoing\":false,\"can_be_edited\":false,\"can_be_forwarded\":true,\"can_be_deleted_only_for_self\":true,\"can_be_deleted_for_all_users\":true,\"is_channel_post\":false,\"contains_unread_mention\":false,\"date\":1562439657,\"edit_date\":0,\"reply_to_message_id\":0,\"ttl\":0,\"ttl_expires_in\":0.000000,\"via_bot_user_id\":0,\"author_signature\":\"\",\"views\":0,\"media_album_id\":\"0\",\"content\":{\"@type\":\"messageText\",\"text\":{\"@type\":\"formattedText\",\"text\":\"1\",\"entities\":[]}}},\"order\":\"0\"}")==0)
            {
           //standart
                 td_json_client_send(client,"{\"@type\":     \"sendMessage\",\"chat_id\":247504167,\"input_message_content\":{\"@type\":\"inputMessageText\",\"text\":{\"@type\":\"formattedText\",\"text\":\"12\"}}}");
            
            }
           /* if (result==a)
           {
              td_json_client_send(client,"{\"@type\":   \"sendMessage\",\"chat_id\":769409260,\"input_message_content\":{\"@type\":\"inputMessageText\",\"text\":{\"@type\":\"formattedText\",\"text\":\"21\"}}}");
           }*/
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
