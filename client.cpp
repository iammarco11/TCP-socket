#include<stdlib.h>
#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<iostream>
#include <arpa/inet.h>

using namespace std;

int main()
{
    int net_socket;
    net_socket = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9090);
    if (net_socket<0)
    {   cout<<"failure"<<endl;
        exit(1);
    }
    cout<<"Socket created successfully"<<endl;

    if (inet_pton(AF_INET,"0.0.0.0",&addr.sin_port)<=0)
    {
        cout<<"Invalid address"<<endl;
        return -1;
    }
    cout<<"Valid address"<<endl;

    int connect(int net_socket,)
    
}