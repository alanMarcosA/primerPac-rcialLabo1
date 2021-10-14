/*
 * UtnInputs.h
 *
 *  Created on: 14 oct 2021
 *      Author: alan
 */
#include <string.h>
#ifndef UTNINPUTS_H_
#define UTNINPUTS_H_
int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getText(char pResultado[], int len, char* mensaje, char* mensajeError, int reintentos);
int esTexto(char cadena[]);



#endif /* UTNINPUTS_H_ */
