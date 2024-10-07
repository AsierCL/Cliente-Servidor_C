#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char** argv) {

    char* mensaje = "hola";
    int puerto = 8080;
    struct sockaddr_in servidor_addr, cliente_addr;
    servidor_addr.sin_family = AF_INET;
    servidor_addr.sin_addr.s_addr = htons(INADDR_ANY); // Aceptar conexiones de cualquier IP
    servidor_addr.sin_port = htons(puerto);
    
    int servidor_fd, cliente_fd;
    if(servidor_fd = socket(AF_INET, SOCK_STREAM, 0)<0){
        printf("Error socket");
    }
    if(bind(servidor_fd, (struct sockaddr *)&servidor_addr, sizeof(servidor_addr))<0){
        printf("Error bind\n");
    }
    if(listen(servidor_fd,1)<0){
        printf("Error listen\n");
    }
    
    while(1){
        printf("hola\n");
        socklen_t cliente_len = sizeof(cliente_addr);
        
        if((cliente_fd = accept(servidor_fd, (struct sockaddr *)&cliente_addr, &cliente_len))<0){
            printf("Error accept\n");
            exit (1);
        }
        send(cliente_fd,&mensaje, sizeof(mensaje),0);
        //close(cliente_fd);
    }
}