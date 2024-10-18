# Informe Tarea

### 1.c

        Si es posible que el servidor envíe dos mensajes seguidos; tambien es posible que el cliente reciba estos mensajes con una única sentencia revc().
        
        El servidor se configuró para enviar dos mensajes consecutivos usando un única función send(), despues de aceptar la conexión del cliente.

        Por otro lado, en cliente.c, fue modificado para esperar un breve tiempo después de establecer la conexión, empleando la función sleep(1); asegurando que el servidor tenga tiempo para enviar ambos mensajes antes de que el cliente intente recibirlos. Posteriormente empleamos una única llamada a recv() para recibir ambos mensajes, si estos están disponibles en el buffer.

        El resultado obtenido con la espera: 

### 1.d

### 3

Cuando el servidor recibe una conexión, empieza a procesar las líneas del cliente1. Si mientras el cliente1 está enviando información, el servidor recibe una conexión de un cliente2, el servidor prioriza el cliente1, y no empieza a procesar la información que envia cliente2 hasta que termina con el primero.
