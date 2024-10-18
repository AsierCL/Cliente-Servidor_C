# Informe Tarea

### 1.c
        Si es posible que el servidor envíe dos mensajes seguidos; tambien es posible que el cliente reciba estos mensajes con una única sentencia revc(), mediante un bucle while.
        En el caso del servidor, dentro del bucle infinito agregamos dos sendas funciones send() y entre ellas declaramos un nuevo mensaje.
        Por otro lado, en cliente.c, agregamos un bucle while que se ejecutará mientras el servidor envíe dados, este bucle imprimirá el mensaje recivido y consigo el número de bytes del mensaje.

### 1.d

### 3