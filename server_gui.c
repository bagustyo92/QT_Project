
#include<stdio.h>
#include<stdlib.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include "server_gui.h"
#include "elm-enco.h"
#include "lcd_i2c.h"
#include "usb-printer.h"

char pesan;
long time_reboot;
struct Server server;

//=============Make thread for running enco purchasedebit============

int reader_start(int package){
    server.run= TRUE;
    mutex_reader = g_mutex_new();
    cond_reader = g_cond_new();

    READERthread = g_thread_create(READERthread(package), NULL, TRUE, NULL);

    g_mutex_lock (mutex_reader);
    g_cond_wait (cond_reader, mutex_reader);
    g_mutex_unlock (mutex_reader);

    return 1;

}

int reader_stop(int package)
{
    server.run= FALSE;
    g_thread_join(READERthread(package));

    g_mutex_free(mutex_reader);
    g_cond_free(cond_reader);
    return 1;
}

void reader_thread(int package){
    enco_purchase_debit(package)

    g_mutex_lock(mutex_reader);
    g_cond_broadcast(cond_reader);
    g_mutex_unlock(mutex_reader);
}

//=============END Make thread for running enco purchasedebit============



//=============Declaration Thread for start and stop=================

int server_start(int){
    server.run= TRUE;
    mutexelm1 = g_mutex_new();
    condelm1 = g_cond_new();

    SERVERThread = g_thread_create(server_thread, NULL, TRUE, NULL);

    g_mutex_lock (mutexelm1);
    g_cond_wait (condelm1, mutexelm1);
    g_mutex_unlock (mutexelm1);

    return 1;

}

int server_stop(void)
{
    server.run= FALSE;
    g_thread_join(SERVERThread);

    g_mutex_free(mutexelm1);
    g_cond_free(condelm1);
    return 1;
}

//============= END Declaration Thread for start and stop=================



//=============Name of thread who start or stop======================

void* server_thread(void *data)
{

    int socket_desc , client_sock , c , read_size;
    char client_message[2000];
    char server_message[2000] = "OK";
    //    char *server_message = "OK";
    char server_message2[2000] = "CANCELING FROM SERVER";
    char pesan_client;
    struct sockaddr_in server , client;


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
    //char text[60];
    g_mutex_lock(mutexelm1);
    g_cond_broadcast(condelm1);
    g_mutex_unlock(mutexelm1);

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
        //        data = respon(&pesan);
        while( read_size > 0 )
        {
            //Send the message back to client
            puts("Client Said : ");


            puts(client_message);
            write(client_sock , server_message , strlen(server_message));

            int paket1, paket2, paket3, cancel;
            paket1 = strcmp(client_message, "1");
            paket2 = strcmp(client_message, "2");
            paket3 = strcmp(client_message, "3");
            cancel = strcmp(client_message, "cancel");

            //            if(paket1 == 0 && cancel == 0 || paket2 == 0 && cancel == 0 || paket2 == 0 && cancel == 0 ){
            //                break;
            //            }
//            if(cancel == 0){
//                puts ("CANCEL");
//                write(client_sock , server_message , strlen(server_message));
//                break;
//            }
            if (paket1 == 0){
                if (cancel == 0){
                    puts ("CANCELING CHOOSING PACKAGE");
                    write(client_sock , server_message2 , strlen(server_message));
                    break;    
                }
                puts("PAKET1\n");

                //STARTING THREAD FOR SCAN CARD
                server_start(1);
                server_stop(1);

                // enco_purchase_debit(1);
//                printer();
                write(client_sock , info , strlen(info));

            }else if(paket2 == 0){
                if (cancel == 0){
                    puts ("CANCELING CHOOSING PACKAGE");
                    write(client_sock , server_message2 , strlen(server_message));
                    break;    
                }
                puts("PAKET2\n");
                // enco_purchase_debit(2);

                //STARTING THREAD FOR SCAN CARD
                server_start(2);
                server_stop(2);
                
                write(client_sock , info , strlen(info));
//                printer();
            }else if(paket3 == 0){
                if (cancel == 0){
                    puts ("CANCELING CHOOSING PACKAGE");
                    write(client_sock , server_message2 , strlen(server_message));
                    break;    
                }
                puts("PAKET3\n");
                
                //STARTING THREAD FOR SCAN CARD
                server_start(3);
                server_stop(3);
                
                // enco_purchase_debit(3);
                write(client_sock , info , strlen(info));
//                printer();
            }

            memset( &client_message, 0, sizeof(client_message));
            read_size = 0;
        }

    }

    sleep(2);
    ///	bank_sam_init();
    sleep(2);
}
//=============END Name of thread who start or stop======================