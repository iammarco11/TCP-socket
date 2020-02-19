#include<stdio.h>
#include<iostream>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string>

using namespace std;

int main()
{   char buffer[1024];
    int opt=1;
    int net_socket,server,new_socket;
    
    net_socket = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9090);
    int addrlen = sizeof(addr);
    int bind_var;

    if (setsockopt(net_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,&opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 

    if (net_socket<0)
    {   cout<<"failure"<<endl;
        exit(1);
    }
    cout<<"Socket created successfully"<<endl;
    bind_var = bind(net_socket,(struct sockaddr*)&addr,addrlen);
    if (bind_var<0) 
    {
        perror("bind failed. Error");
        exit(1);
    }
    cout<<"Bind Successful"<<endl;

    if (listen(net_socket,3)<0)
    {
        perror("listening failed. Error");
        exit(1);
    }
    cout<<"listening"<<endl;
    if ((new_socket = accept(server,(struct sockaddr*)&addr,(socklen_t*)&addrlen))<0)
    {
         cout<<"Server not accepting the incoming calls"<<endl;
    }
    cin.getline(buffer,1024);
    send(net_socket,buffer,1024,0);
}
