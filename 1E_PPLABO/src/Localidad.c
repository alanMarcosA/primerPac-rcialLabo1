/*
 * Localidad.c
 *
 *  Created on: 14 oct 2021
 *      Author: alan
 */
#include "localidad.h"
#include <stdio.h>
#include <stdlib.h>

#define EMPTY 1
#define FULL 0
static int searchFreeSpace(Elocalidad* list, int len);
int initlocalidad(Elocalidad* list, int len)
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
int agregarElocalidad(Elocalidad* list, int len, int id,char nombre[]){
	int stateAdd;
	int index;
	stateAdd=-1;
	if(list != NULL && len > 0){
		index= searchFreeSpace(list, len);
		if(index != -1){
			list[index].id=id;
			strcpy(list[index].nombre, nombre);
			list[index].isEmpty=FULL;
			stateAdd=0;
		}
	}
	return stateAdd;
}
static int searchFreeSpace(Elocalidad* list, int len){
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
