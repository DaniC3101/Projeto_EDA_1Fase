#pragma once
#ifndef MATRIZ_H
#define MATRIZ_H
#pragma once
#include "ListaAntenas.h"

typedef struct
{
	int tamMatriz[2];
	struct ListaAntenas* listaAntenas;
}Matriz;

/// <summary>
/// Cria uma nova matriz com o número de linhas e colunas especificados.
/// Aloca memória para a estrutura da matriz e para a lista de antenas.
/// </summary>
/// <param name="linhas">Número de linhas da matriz.</param>
/// <param name="colunas">Número de colunas da matriz.</param>
/// <returns>Retorna um apontador para a estrutura da matriz criada.</returns>
Matriz* CriarMatriz(int linhas, int colunas);
/// <summary>
/// Cria uma nova antena numa posição específica na matriz e a adiciona à lista de antenas.
/// Verifica também a posição da antena na lista de antenas já existentes.
/// </summary>
/// <param name="m">Apontador para a estrutura da matriz.</param>
/// <param name="linha">Linha onde a antena será colocada.</param>
/// <param name="coluna">Coluna onde a antena será colocada.</param>
/// <param name="frequencia">Frequência da antena.</param>
/// <returns>Retorna um apontador para a antena criada.</returns>
Antena* CriarAntena(Matriz* m, int linha, int coluna, double frequencia);
/// <summary>
/// Adiciona uma antena à lista de antenas de uma matriz.
/// Se a lista estiver vazia, a antena será a primeira da lista.
/// Caso contrário, a antena será adicionada ao final da lista.
/// </summary>
/// <param name="m">Apontador para a estrutura da matriz.</param>
/// <param name="antena">Apontador para a antena a ser adicionada.</param>
void AdiconarAntenaMatriz(Matriz* m, Antena* antena);
/// <summary>
/// Mostra a matriz no terminal, representando as antenas e as zonas de interferência.
/// Utiliza caracteres para indicar a presença de antenas e zonas de interferência.
/// </summary>
/// <param name="m">Apontador para a estrutura da matriz.</param>
void MostrarMatriz(Matriz* m);
/// <summary>
/// Elimina uma antena de uma posição específica na matriz.
/// </summary>
/// <param name="m">Apontador para a estrutura da matriz.</param>
/// <param name="linha">Linha da antena a ser eliminada.</param>
/// <param name="coluna">Coluna da antena a ser eliminada.</param>
/// <returns>Retorna um apontador para a antena eliminada.</returns>
Antena*	EliminarAntena(Matriz* m, int linha, int coluna);
#endif
