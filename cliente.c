#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 27

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <IP> <puerto>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip = argv[1];
    int puerto = atoi(argv[2]);
    int socket_fd;
    struct sockaddr_in servidor_addr;
    char buffer[BUFFER_SIZE+1]; // Aumentamos el tamaño para el terminador nulo.
    int n;

    printf("Tamaño del buffer: %d bytes.\n", BUFFER_SIZE);

    // Crear el socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error al crear el socket");
        exit(EXIT_FAILURE);
    }

    // Configurar la dirección del servidor
    servidor_addr.sin_family = AF_INET;
    servidor_addr.sin_port = htons(puerto);
    inet_pton(AF_INET, ip, &servidor_addr.sin_addr);

    // Conectar al servidor
    if (connect(socket_fd, (struct sockaddr *)&servidor_addr, sizeof(servidor_addr)) < 0) {
        perror("Error al conectar");
        close(socket_fd);
        exit(EXIT_FAILURE);
    }

    

    /*  Ejercicio 1 parte
        sleep(1);  // Esperamos un breve tiempo para que el servidor envie el mensaje.
        n = recv(socket_fd, buffer, BUFFER_SIZE - 1, 0);
        if (n < 0) {
            perror("Error al recibir");
        } else {
            buffer[n] = '\0'; // Asegurar que el buffer sea una cadena
            printf("Mensaje recibido: %s.", buffer);
            printf("\n");
            printf("Número de bytes recibidos: %d\n", n);
        }
    */

    while((n = recv(socket_fd, buffer, BUFFER_SIZE,0))>0){
    
        buffer[n] = '\0'; // Asegurar que el buffer sea una cadena
        printf("Mensaje recibido: %s. ", buffer);
        printf("Número de bytes recibidos: %d\n", n);
    }
    if (n < 0) {
        perror("Error al recibir");
    }

    close(socket_fd); // Cerrar el socket del cliente
    return 0;
}
