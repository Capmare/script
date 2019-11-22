#include "udp.h"
int port_table[1500];

int test_ip(int argc, char* argv[],int* port_tableau)
{
   
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, argv[1], &(sa.sin_addr));
    return result;
    
}

void udp(int argc, char* argv[],int* port_table)
{
    
    int client;
    int sending=0;
    int error=0;
    struct sockaddr_in server;
    client = socket(AF_INET, SOCK_DGRAM, 0);
    if(client < 0)
    {
         printf("socket creation error\n");
    }
    fprintf(stderr, "socket created\n");
    while(1){
     fprintf(stdout, "%d packets sends \n",sending);
     fprintf(stdout, "%d unsent packets \n",error);
     fprintf(stdout, "Port:%d \n",port_table[rand() % 1500]=rand()%1500);
     server.sin_family      = AF_INET;            
     server.sin_port        = htons(port_table[rand() % 1500]=rand()%1500);               
     server.sin_addr.s_addr = inet_addr(argv[1]); 
     if (sendto(client, argv[2], (strlen(argv[2])+1), 0,(struct sockaddr *)&server, sizeof(server)) < 0)
     {
       error=error+1;
     }
     sending=sending+1;
     }	
    
}

int main(int argc, char* argv[]){
    if (argv[1]==NULL)
    {
       fprintf(stdout, "no ip chooses \n");
       return 0;
    }
    if (argv[2]==NULL)
    {
       fprintf(stdout, "no message chooses'\n");
       return 0;
    }
    fprintf(stdout, "valid ip test ..\n");
    if (test_ip(argc,argv,port_table)==0)
    {
       fprintf(stdout, "this ip is not valid\n");
       return 0;
    }
    udp(argc,argv,port_table);
    
}
