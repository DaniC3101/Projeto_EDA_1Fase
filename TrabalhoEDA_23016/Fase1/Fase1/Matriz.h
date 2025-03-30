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
/// Cria uma nova matriz com o n�mero de linhas e colunas especificados.
/// Aloca mem�ria para a estrutura da matriz e para a lista de antenas.
/// </summary>
/// <param name="linhas">N�mero de linhas da matriz.</param>
/// <param name="colunas">N�mero de colunas da matriz.</param>
/// <returns>Retorna um apontador para a estrutura da matriz criada.</returns>
Matriz* CriarMatriz(int linhas, int colunas);
/// <summary>
/// Cria uma nova antena numa posi��o espec�fica na matriz e a adiciona � lista de antenas.
/// Verifica tamb�m a posi��o da antena na lista de antenas j� existentes.
/// </summary>
/// <param name="m">Apontador para a estrutura da matriz.</param>
/// <param name="linha">Linha onde a antena ser� colocada.</param>
/// <param name="coluna">Coluna onde a antena ser� colocada.</param>
/// <param name="frequencia">Frequ�ncia da antena.</param>
/// <returns>Retorna um apontador para a antena criada.</returns>
Antena* CriarAntena(Matriz* m, int linha, int coluna, double frequencia);
/// <summary>
/// Adiciona uma antena � lista de antenas de uma matriz.
/// Se a lista estiver vazia, a antena ser� a primeira da lista.
/// Caso contr�rio, a antena ser� adicionada ao final da lista.
/// </summary>
/// <param name="m">Apontador para a estrutura da matriz.</param>
/// <param name="antena">Apontador para a antena a ser adicionada.</param>
void AdiconarAntenaMatriz(Matriz* m, Antena* antena);
/// <summary>
/// Mostra a matriz no terminal, representando as antenas e as zonas de interfer�ncia.
/// Utiliza caracteres para indicar a presen�a de antenas e zonas de interfer�ncia.
/// </summary>
/// <param name="m">Apontador para a estrutura da matriz.</param>
void MostrarMatriz(Matriz* m);
/// <summary>
/// Elimina uma antena de uma posi��o espec�fica na matriz.
/// </summary>
/// <param name="m">Apontador para a estrutura da matriz.</param>
/// <param name="linha">Linha da antena a ser eliminada.</param>
/// <param name="coluna">Coluna da antena a ser eliminada.</param>
/// <returns>Retorna um apontador para a antena eliminada.</returns>
Antena*	EliminarAntena(Matriz* m, int linha, int coluna);
#endif
