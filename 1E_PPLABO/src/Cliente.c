/*
 * Cliente.c
 *
 *  Created on: 14 oct 2021
 *      Author: alan
 */
#include "Cliente.h"
#define EMPTY 1
#define FULL 0
static int searchFreeSpace(Ecliente* list, int len);


int initEclientes(Ecliente* list, int len)
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

int agregarEcliente(Ecliente* list, int len, int id,char nombreEmpresa[], int cuit, char dirreccion[], char localidad[]){
	int stateAdd;
	int index;
	stateAdd=-1;
	if(list != NULL && len > 0){
		index= searchFreeSpace(list, len);
		if(index != -1){
			list[index].id=id;
			strcpy(list[index].nombreEmpresa, nombreEmpresa);
			strcpy(list[index].dirreccion, dirreccion);
			strcpy(list[index].localidad, localidad);
			list[index].cuit=cuit;
			list[index].isEmpty=FULL;
			stateAdd=0;
		}
	}
	return stateAdd;
}
static int searchFreeSpace(Ecliente* list, int len){
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

int findEclienteById(Ecliente* list, int len,int id){
	int index;
	index=-1;
	if(list != NULL && len > 0){
		for(int i=0; i < len; i++){
			if(list[i].id == id && list[i].isEmpty==FULL){
				index= i;
				break;
			}
		}
	}
	return index;
}
int modificarEcliente(Ecliente* list, int len, int id,char dirreccion[], char localidad[]){
	int stateMod;
		int index;
		stateMod=-1;
		if(list != NULL && len > 0){
			index= findEclienteById(list, len, id);
			if(index != -1){
				strcpy(list[index].dirreccion, dirreccion);
				strcpy(list[index].localidad, localidad);
				stateMod=0;
			}
		}
		return stateMod;
}

int eliminarEcliente(Ecliente* list, int len, int id){
	int stateDelete;
		int index;
		stateDelete=-1;
		if(list != NULL && len > 0){
			index= findEclienteById(list, len, id);
			if(index != -1){
				list[index].isEmpty=EMPTY;
				stateDelete=0;
			}
		}
		return stateDelete;
}
