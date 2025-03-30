#pragma once
#ifndef ANTENA_H
#define ANTENA_H

#include "ListaNefastas.h"

typedef struct
{
	int posAntena[2];
	int frequencia;
	struct Antena* proxAntena;
	struct ListaNefastas* listaNefasta;
}Antena;
/// <summary>
/// Adiciona uma nova antena numa posi��o espec�fica da matriz.
/// A antena recebe a posi��o, a frequ�ncia e um apontador para a pr�xima antena (inicialmente NULL).
/// </summary>
/// <param name="linha">Linha onde a antena ser� colocada.</param>
/// <param name="coluna">Coluna onde a antena ser� colocada.</param>
/// <param name="frequencia">Frequ�ncia da antena.</param>
/// <returns>Retorna um apontador para a antena criada.</returns>
Antena* AdicionarAntena(int linha, int coluna, int frequencia);
/// <summary>
/// Verifica se uma antena com a mesma frequ�ncia j� existe na lista de antenas.
/// Se encontrar, verifica se h� interfer�ncia (zona nefasta) entre as antenas.
/// </summary>
/// <param name="listaAntena">Apontador para a lista de antenas.</param>
/// <param name="antenaAtual">Apontador para a antena que est� a ser verificada.</param>
/// <param name="linhas">N�mero de linhas da matriz.</param>
/// <param name="colunas">N�mero de colunas da matriz.</param>
/// <returns>Retorna 0.</returns>
int VerificarAntenaAnterior(Antena* listaAntena, Antena* auxAntenaAtual, int linhas, int colunas);
/// <summary>
/// Insere uma posi��o de interfer�ncia (zona nefasta) para uma antena.
/// Adiciona a posi��o � lista de zonas nefastas de ambas as antenas envolvidas.
/// </summary>
/// <param name="auxAntenaAnterior">Posi��o da antena anterior.</param>
/// <param name="auxAntenaAntes">Apontador para a antena anterior.</param>
/// <param name="auxAntenaAtual">Posi��o da antena atual.</param>
/// <param name="AntenaAtual">Apontador para a antena atual.</param>
void InserirNefasta(int* auxAntenaAnterior, Antena* auxAntenaAntes, int* auxAntenaAtual, Antena* AntenaAtual);
/// <summary>
/// Marca as zonas de interfer�ncia (zonas nefastas) entre duas antenas.
/// A interfer�ncia ocorre se as antenas partilharem a mesma frequ�ncia e estiverem na mesma �rea.
/// </summary>
/// <param name="antenaAnterior">Apontador para a antena anterior.</param>
/// <param name="antenaAtual">Apontador para a antena atual.</param>
/// <param name="auxAntenaAnterior">Posi��o da antena anterior.</param>
/// <param name="auxAntenaAtual">Posi��o da antena atual.</param>
void NefastaAntena(Antena* antenaAnterior, Antena* antenaAtual, int* auxAntenaAnterior, int* auxAntenaAtual);
/// <summary>
/// Apaga uma antena da lista de antenas, procurando pela sua posi��o na matriz.
/// Caso a antena seja encontrada, ela � removida da lista.
/// </summary>
/// <param name="listaAntena">Apontador para a lista de antenas.</param>
/// <param name="linha">Linha da antena a ser apagada.</param>
/// <param name="coluna">Coluna da antena a ser apagada.</param>
void ApagarAntena(Antena* listaAntenas,int linha, int coluna);
#endif