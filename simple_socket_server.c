    /*
        C socket server example
    */

    #include<stdio.h>
    #include<string.h>    //strlen
    #include<sys/socket.h>
    #include<arpa/inet.h> //inet_addr
    #include<unistd.h>    //write
    // #include <json.h>   //import JSON

int main(int argc , char *argv[])
{
    int socket_desc , client_sock , c , read_size;
    struct sockaddr_in server , client;
    char client_message[2000];
    char server_message[2000] = "OK";


            //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");

        //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );

        //Bind
            // setsockopt(mysocket, SOL_SOCKET, SO_REUSEADDR, &value, sizeof(value)
    if( bind(socket_desc,(struct sockaddr *)&server, sizeof(struct sockaddr)) < 0)
    {
            //print the error message
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");

        //Listen

    listen(socket_desc , 3);

        //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);

        //accept connection from an incoming client
    for(;;){
        client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
        if (client_sock < 0)
        {
            perror("accept failed");
            return 1;
        }
        puts("Connection accepted");

        //Receive a message from client
        read_size = read(client_sock , client_message , sizeof(client_message));
        while( read_size > 0 )
        {
            //Send the message back to client
            puts("Client Said : ");
            puts(client_message);
            for (int i=0; i<5; i++){
                write(client_sock , server_message , strlen(server_message));
                memset( &client_message, 0, sizeof(client_message));
                read_size = 0;
                delay(1000);
            }
        }

        if(read_size == 0)
        {
            puts("Client disconnected");
            fflush(stdout);
            shutdown(socket_desc, 1);
            // close(socket_desc);
        }
        else if(read_size == -1)
        {
            perror("recv failed");
        }
    }

    return 0;
}

// char * jsonFormatting(char * paket){
//     struct json_object *jobj;
//     char *val = "{tarif : }"
// }