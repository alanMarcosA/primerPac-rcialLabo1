/*
 ============================================================================
 Name        : 1E_PPLABO.c
 Author      : Aspi Alan Marcos
 Version     :
 Copyright   : div E
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "Pedido.h"
#include "Localidad.h"
#include "informes.h"
#include "UtnInputs.h"
#define TAMCLI 100
#define TAMPED 1000
#define TAMLOC 10
int main(void) {
	setbuf(stdout, NULL);
	Ecliente clientes[TAMCLI];
	Epedido pedidos[TAMPED];
	Elocalidad localidades[TAMLOC];
	initEclientes(clientes, TAMCLI);
	initEpedidos(pedidos, TAMPED);
	int opcion;
	int res;
	int id;
	char dirreccion[51];
	char localidad[51];

	//precargar datos
	agregarElocalidad(localidades, TAMLOC, 1, "caba");
	agregarElocalidad(localidades, TAMLOC, 1, "tres de febrero");
	agregarEcliente(clientes, TAMCLI, 1, "Fanta", 12345678, "mouse 123", 1);
	agregarEcliente(clientes, TAMCLI, 2, "DELL", 1010101010, "calle 2", 2);
	agregarEcliente(clientes, TAMCLI, 3, "USB", 4024039211, "alfajor 2424", 1);
	crearPedido(pedidos, TAMPED, 1, 2, 4);
	crearPedido(pedidos, TAMPED, 1, 1, 10);
	crearPedido(pedidos, TAMPED, 1, 1, 20);
	//crearPedido(list, len, id, idCliente, kilosTotales)
	do{
	    printf("1. Alta de Cliente\n");
	    printf("2. Modificar datos del Cliente\n");
	    printf("3. Baja de Cliente\n");
	    printf("4. Crear pedido de recoleccion\n");
	    printf("5. Procesar residuos\n");
	    printf("6. Imprimir Clientes\n");
	    printf("7. Imprimir pedidos pendientes\n");
	    printf("8. Imprimir pedidos procesados\n");
	    printf("9. cantidad de pedidos pendientes por localidad\n");
	    printf("10. Imprimir el promedio de kilos de PP por Cliente\n");
	    printf("11. Salir\n");
	    res = utn_getInt(&opcion, "Elija una opcion del Menu\n", "ingrese la opcion de nuevo", 0, 100, 3);
	    if(res!=-1){
	    	int codeError;
			int codeError1;
			int codeError2;
			int codeError3;
	    	switch (opcion) {
	    				case 1:
	    					printf("disculpe las molestias, esta opcion esta actualmente fuerte de servicio");
	    					printf("PD: AAAIIIUUUUUUDAAA!!!!");
	    					break;
	    				case 2:
	    					//imprimirClientes(clientes, TAMCLI, pedidos, TAMPED);
	    					codeError1 = utn_getInt(&id, "ingrese el id a modificar", "vuelva a ingresar el id", -1, 1000, 3);
	    					codeError2 = utn_getText(dirreccion, TAMCLI, "ingrese la dirrecion", "vuelva a ingresar la dirrecion", 3);
	    					codeError3 = utn_getText(localidad, TAMCLI, "ingrese la localidad", "vuelva a ingresar la localidad", 3);
	    					if(codeError1!=-1&&codeError2!=-1&&codeError3!=-1){
	    						codeError1=modificarEcliente(clientes, TAMCLI, id, dirreccion, localidad);
	    						if(codeError1==-1){
	    							printf("ocurrio un error al cargar los datos, revise el ID ingresado");
	    						}
	    					}
	    					else{
	    						printf("hubo un erro en la entrada de los datos");
	    					}
	    					break;
	    				case 3:
    						codeError = utn_getInt(&id, "ingrese el id del cliente a eliminar", "vuelva a ingresar el id", -1, 1000, 3);
    						if(codeError==0){
    							utn_getInt(&res, "esta seguro que desea eliminar 1-Si   2.No", "seguro?", 0, 3, 3);
    							if(res==1){
									eliminarEcliente(clientes, TAMCLI, id);
									if(codeError1==-1){
										printf("ocurrio un error al eliminar el cliente, verifique el ID");
									}

    							}
    						}
	    					break;
	    				case 4:
	    					printf("disculpe las molestias, esta opcion esta actualmente fuera de servicio");
	    					printf("PD: AAAIIIUUUUUUDAAA!!!!");
	    					break;
	    				case 5:

	    					break;
	    				case 6:
	    					imprimirClientes(clientes, TAMCLI, pedidos, TAMPED);
	    					break;
	    				case 7:
	    					imprimirPedidosPendentes(pedidos, TAMPED, clientes, TAMCLI);
	    					break;
	    				case 8:
	    					imprimirPedidosProcesados(pedidos, TAMPED, clientes, TAMCLI);
	    					break;
	    				case 9:

	    					break;
	    				case 10:

	    					break;
	    				case 11:

	    					break;

	    				default:
	    					break;
	    			}
	    }

	}while(opcion!=11);
	return EXIT_SUCCESS;
}
