#include "miTFTP.h"

int Trabajando(Direccion cliente);

int main(){

    int udp_socket = crearSocket();
    //se crean los argumentos para una estructura
    Direccion dir_envio=(Direccion)malloc(sizeof(struct datos_dir));
    Direccion dir_recibe=(Direccion)malloc(sizeof(struct datos_dir));

    struct sockaddr_in *local_servidor=crearLocal(8080);
    struct sockaddr_in *cliente=crearCliente(); 

    int lbind=crearBind(udp_socket,local_servidor);

    dir_envio->udp_socket=udp_socket;
    dir_envio->dir=cliente;

    dir_recibe->udp_socket=udp_socket;
    dir_recibe->dir=cliente;

    int Trabajando(cliente);

    return 0;
}

int Trabajando(Direccion cliente){
    unsigned char* paquete;

    //el servidor estara trabajando recibiendo peticiones,
    //cuando reciba una pedende de lo que sea se pondra a
    //mandar paquetes(peticion de lectura)
    //recibir paquetes(peticion de escritura)
    //mandar mensaje de error(ya sea que no exista o un error distinto)
    while(1){
        
        //El paquete estara en memoria dinamica
        paquete=EsperandoPeticiones(cliente);

        //Dependiendo de la peticion la direccion 'cliente'
        //se le manda para que se le mande respuesta por esa direccion
        //en esta seccion puede ir hilos en el caso de atender a mas cliente
        ProcesarPaqueteRecibido(paquete,cliente);

    }
}
