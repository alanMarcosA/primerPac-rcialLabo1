/*
 * informes.c
 *
 *  Created on: 14 oct 2021
 *      Author: alan
 */
#include "informes.h"
#include <stdio.h>
#include <stdlib.h>
#define EMPTY 1
#define FULL 0
#define COMPLETED 1
#define PENDING 0
int imprimirClientes(Ecliente* list, int len, Epedido* listP, int lenP){
	int statePrint;
	int cantPedidos;
	statePrint=-1;
	if(list != NULL && len > 0){
		printf("ID \t NombreEmpresa \t CUIT \t Dirreccion \t localidad \t cantPedidos \n");
		for(int i=0; i<len ;i++){
			if(list[i].isEmpty==FULL){
				cantPedidos = pedidosPendientesPorIdCli(listP, lenP, list[i].id);
				printf("\%d \t \%s \t \%d \t \%s \t \%d \t \%d \n",list[i].id, list[i].nombreEmpresa,list[i].cuit,list[i].dirreccion,list[i].idLocalidad,cantPedidos);
			}
			statePrint=0;
		}
	}
	return statePrint;
}
int imprimirPedidosPendentes(Epedido* list, int lenP, Ecliente* listC, int lenC){
	int statePrint;
	int idCliente;
	int indexC;
	statePrint=-1;
	if(list != NULL && lenP > 0){
		statePrint=0;
		printf("CUIT Cliente \t  DireccionCliente \t cantKilos \n");
		for(int i=0; i<lenP;i++){
			if(list[i].isEmpty==FULL && list[i].stado==PENDING){
				idCliente=list[i].idCliente;
				indexC=findEclienteById(listC, lenC, idCliente);
				printf("\%d \t \%s \t \%f \n",listC[indexC].cuit, listC[indexC].dirreccion, list[i].kilosTotales);
			}
		}
	}
	return statePrint;
}

int imprimirPedidosProcesados(Epedido* list, int lenP, Ecliente* listC, int lenC){
	int statePrint;
	int idCliente;
	int indexC;
	statePrint=-1;
	if(list != NULL && lenP > 0){
		statePrint=0;
		printf("CUIT Cliente \t  DireccionCliente \t kilosHDPE \t kilosLDPE \t kilosPP \n");
		for(int i=0; i<lenP;i++){
			if(list[i].isEmpty==FULL && list[i].stado==COMPLETED){
				idCliente=list[i].idCliente;
				indexC=findEclienteById(listC, lenC, idCliente);
				printf("\%d \t \%s \t \%f \t \%f \t \%f \n",listC[indexC].cuit, listC[indexC].dirreccion, list[i].kilosHDPE, list[i].kilosLDPE, list[i].kilosPP);
			}
		}
	}
	return statePrint;
}

int cantidadPedidosPorLocalidad(Epedido* listP, int lenP, Ecliente* listC, int lenC){
	int stateLoc;
	stateLoc=-1;

	return stateLoc;
}

int clienteConMasPendientes(Ecliente* list, int len, Epedido* listP, int lenP){
	int stateCant;
	int idConMasPedidos;
	int maxPedidos;
	int pedidosAux;
	maxPedidos=-1;
	stateCant=-1;
	if(list != NULL && len > 0){

		for(int i=0; i<len ;i++){
			if(list[i].isEmpty==FULL){
				pedidosAux = pedidosPendientesPorIdCli(listP, len, list[i].id);
				if(pedidosAux>maxPedidos){
					maxPedidos=pedidosAux;
					idConMasPedidos=i;
				}
			}

			stateCant=0;
		}
		printf("el cliente con mas pedidos pendientes es %d %s \n", list[idConMasPedidos].id, list[idConMasPedidos].nombreEmpresa);
	}
	return stateCant;
}

int clienteConMasCompletados(Ecliente* list, int len, Epedido* listP, int lenP){
	int stateCant;
	int idConMasPedidos;
	int maxPedidos;
	int pedidosAux;
	maxPedidos=-1;
	stateCant=-1;
	if(list != NULL && len > 0){

		for(int i=0; i<len ;i++){
			if(list[i].isEmpty==FULL){
				pedidosAux = pedidosCompletadosPorIdCli(listP, len, list[i].id);
				if(pedidosAux>maxPedidos){
					maxPedidos=pedidosAux;
					idConMasPedidos=i;
				}
			}

			stateCant=0;
		}
		printf("el cliente con mas pedidos Completados es %d %s \n", list[idConMasPedidos].id, list[idConMasPedidos].nombreEmpresa);
	}
	return stateCant;
}
int clienteConMasPedidos(Ecliente* list, int len, Epedido* listP, int lenP){
	int stateCant;
	int idConMasPedidos;
	int maxPedidos;
	int pedidosAux;
	maxPedidos=-1;
	stateCant=-1;
	if(list != NULL && len > 0){

		for(int i=0; i<len ;i++){
			if(list[i].isEmpty==FULL){
				pedidosAux = pedidosCompletadosPorIdCli(listP, len, list[i].id) + pedidosPendientesPorIdCli(listP, len, list[i].id);
				if(pedidosAux>maxPedidos){
					maxPedidos=pedidosAux;
					idConMasPedidos=i;
				}
			}

			stateCant=0;
		}
		printf("el cliente con mas pedidos es %d %s \n", list[idConMasPedidos].id, list[idConMasPedidos].nombreEmpresa);
	}
	return stateCant;
}
