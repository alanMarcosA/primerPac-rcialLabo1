/*
 * Pedido.c
 *
 *  Created on: 14 oct 2021
 *      Author: alan
 */
#include "Pedido.h"
#define EMPTY 1
#define FULL 0
#define COMPLETED 1
#define PENDING 0
static int findEpedidoById(Epedido* list, int len,int id);
static int searchFreeSpace(Epedido* list, int len);
int initEpedidos(Epedido* list, int len)
{
	int stateInit;
	stateInit=-1;
	if(list != NULL && len > 0){
		for(int i=0 ; i<len; i++){
			list[i].isEmpty=EMPTY;
		}
		stateInit=0;
	}
	return stateInit;
}

int crearPedido(Epedido* list, int len, int id,int idCliente, float kilosTotales){
	int stateAdd;
	int index;
	stateAdd=-1;
	if(list != NULL && len > 0){
		index= searchFreeSpace(list, len);
		if(index != -1){
			list[index].id=id;
			list[index].idCliente=idCliente;
			list[index].kilosTotales=kilosTotales;
			list[index].stado= PENDING;
			list[index].isEmpty=FULL;
			stateAdd=0;
		}
	}
	return stateAdd;
}

static int searchFreeSpace(Epedido* list, int len){
	int index;
	index=-1;
	for(int i=0; i < len; i++){
		if(list[i].isEmpty == EMPTY){
			index= i;
			break;
		}
	}
	return index;
}

int procesarResiduos(Epedido* list, int len, int id,float kilosHDPE,float kilosLDPE, float kilosPP){
	int stateAdd;
	int index;
	stateAdd=-1;
	if(list != NULL && len > 0){
		index= findEpedidoById(list, len, id);
		if(index != -1){
			list[index].stado= COMPLETED;
			list[index].kilosHDPE=kilosHDPE;
			list[index].kilosLDPE=kilosLDPE;
			list[index].kilosPP=kilosPP;
			stateAdd=0;
		}
	}
	return stateAdd;
}

static int findEpedidoById(Epedido* list, int len,int id){
	int index;
	index=-1;
	if(list != NULL && len > 0){
		for(int i=0; i < len; i++){
			if(list[i].id == id && list[i].isEmpty==FULL && list[i].stado==PENDING){
				index= i;
				break;
			}
		}
	}
	return index;
}

int pedidosPendientesPorIdCli(Epedido* list, int len,int idCliente){
	int stateCant;
	stateCant=-1;
	if(list != NULL && len > 0){
		for(int i=0; i < len; i++){
			stateCant=0;
			if(list[i].idCliente == idCliente && list[i].isEmpty==FULL && list[i].stado==PENDING){
				stateCant=stateCant +1;
			}
		}
	}
	return stateCant;
}

int pedidosCompletadosPorIdCli(Epedido* list, int len,int idCliente){
	int stateCant;
	stateCant=-1;
	if(list != NULL && len > 0){
		for(int i=0; i < len; i++){
			stateCant=0;
			if(list[i].idCliente == idCliente && list[i].isEmpty==FULL && list[i].stado==COMPLETED){
				stateCant=stateCant +1;
			}
		}
	}
	return stateCant;
}
