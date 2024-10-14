#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>

#define BUFFER 1014

int main(int argc, char** argv) {

    int puerto = 8080;
    int servidor_fd, cliente_fd, n;
    struct sockaddr_in servidor_addr, cliente_addr;
    socklen_t cliente_len = sizeof(cliente_addr);
    char buffer[BUFFER];
    
    
    
    if((servidor_fd = socket(AF_INET, SOCK_STREAM, 0))<0){
        printf("Error socket");
    }
    servidor_addr.sin_family = AF_INET;
    servidor_addr.sin_addr.s_addr = htons(INADDR_ANY); // Aceptar conexiones de cualquier IP
    servidor_addr.sin_port = htons(puerto);

    if(bind(servidor_fd, (struct sockaddr *)&servidor_addr, sizeof(servidor_addr))<0){
        printf("Error bind\n");
        //close(servidor_fd);
        exit(1);
    }
    if(listen(servidor_fd,1)<0){
        printf("Error listen\n");
        //close(servidor_fd);
        exit(1);
    }
    
    while((n = recv(servidor_fd, buffer, BUFFER,0))>0){

        if(n<0){
            perror("Error al recibir.\n");
        }else{
            buffer[n] = '\0';
            printf("Mensaje recibido: %s", buffer);
            for(int i = 0;buffer[i] != '\0'; i++ ){
                buffer[i]=toupper(buffer[i]);
            }
            if((cliente_fd = accept(servidor_fd, (struct sockaddr *)&cliente_addr, &cliente_len))<0){
            printf("Error accept\n");
            }
            printf("Conexión aceptada de %s:%d\n", inet_ntoa(cliente_addr.sin_addr), ntohs(cliente_addr.sin_port));
            

        // parte c
            send(cliente_fd,buffer, strlen(buffer),0);
        }
    }

    //close(servidor_fd);
    return 0;
}