#pragma once
#ifndef LISTAANTENA_H
#define LISTAANTENA_H

#include "Antena.h"
typedef struct ListaAntenas
{
	int tamMatriz[2];
	struct Antena* primAntena;
}ListaAntenas;
#endif