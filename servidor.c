#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER 1014

int main(int argc, char** argv) {

    int puerto = 8080;
    int servidor_fd, cliente_fd;
    struct sockaddr_in servidor_addr, cliente_addr;
    socklen_t cliente_len = sizeof(cliente_addr);
    char buffer[BUFFER];

    char *mensaje1 = "HOLAAAAA. Primer mensaje.";
    char *mensaje2 = "ADIOSSSSS. Segundo mensaje.";
    
    
    // Crear el socket
    if((servidor_fd = socket(AF_INET, SOCK_STREAM, 0))<0){
        printf("Error socket");
    }
    // Configuración de la dirección del servidor.
    servidor_addr.sin_family = AF_INET;
    servidor_addr.sin_addr.s_addr = htons(INADDR_ANY); // Aceptar conexiones de cualquier IP
    servidor_addr.sin_port = htons(puerto);

    // Enlazar el socket
    if(bind(servidor_fd, (struct sockaddr *)&servidor_addr, sizeof(servidor_addr))<0){
        printf("Error al enlazar el socket.\n");
        //close(servidor_fd);
        exit(1);
    }
    if(listen(servidor_fd,1)<0){
        printf("Error al escuchar.\n");
        //close(servidor_fd);
        exit(1);
    }

    printf("Esperando conexiones...\n");

    /* Ejecicio 1 parte c*/
        if((cliente_fd = accept(servidor_fd, (struct sockaddr *)&cliente_addr, &cliente_len))<0){
            printf("Error al aceptar la conexión.\n");
        }
        printf("Conexión aceptada de %s:%d\n", inet_ntoa(cliente_addr.sin_addr), ntohs(cliente_addr.sin_port));
        send(cliente_fd,mensaje1, strlen(mensaje1),0);
        send(cliente_fd, mensaje2, strlen(mensaje2),0);
        printf("Mensajes enviados.\n");

    // while(1){
    //     if((cliente_fd = accept(servidor_fd, (struct sockaddr *)&cliente_addr, &cliente_len))<0){
    //         printf("Error al aceptar la conexión.\n");
    //     }
    //     printf("Conexión aceptada de %s:%d\n", inet_ntoa(cliente_addr.sin_addr), ntohs(cliente_addr.sin_port));
    
    //     send(cliente_fd,mensaje1, strlen(mensaje1),0);
    //     send(cliente_fd, mensaje2, strlen(mensaje2),0);
    //     printf("Mensajes enviados.\n");
    // }
    //close(servidor_fd);


    return 0;
}