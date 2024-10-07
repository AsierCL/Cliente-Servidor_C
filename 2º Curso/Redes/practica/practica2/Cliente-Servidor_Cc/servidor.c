#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char** argv) {

    if (argc != 2){
        fprintf(stderr, "Uso: %s <puerto>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* mensaje = "hola";
    int puerto = 8080;
    struct sockaddr_in servidor_addr, cliente_addr;
    servidor_addr.sin_family = AF_INET;
    servidor_addr.sin_addr.s_addr = INADDR_ANY; // Aceptar conexiones de cualquier IP
    servidor_addr.sin_port = htons(puerto);
    
    int servidor_fd, cliente_fd;
    servidor_fd = socket(AF_INET, SOCK_STREAM, 0);
    bind(servidor_fd, (struct sockaddr *)&servidor_addr, sizeof(servidor_addr));
    listen(servidor_fd,1);
    
    while(1){
        printf("hola");
        socklen_t cliente_len = sizeof(cliente_addr);
        cliente_fd = accept(servidor_fd, (struct sockaddr *)&servidor_addr, &cliente_len);
        send(cliente_fd,&mensaje, sizeof(mensaje),0);
        //close(cliente_fd);
    }
}