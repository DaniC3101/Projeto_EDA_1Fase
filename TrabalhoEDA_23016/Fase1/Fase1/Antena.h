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
/// Adiciona uma nova antena numa posição específica da matriz.
/// A antena recebe a posição, a frequência e um apontador para a próxima antena (inicialmente NULL).
/// </summary>
/// <param name="linha">Linha onde a antena será colocada.</param>
/// <param name="coluna">Coluna onde a antena será colocada.</param>
/// <param name="frequencia">Frequência da antena.</param>
/// <returns>Retorna um apontador para a antena criada.</returns>
Antena* AdicionarAntena(int linha, int coluna, int frequencia);
/// <summary>
/// Verifica se uma antena com a mesma frequência já existe na lista de antenas.
/// Se encontrar, verifica se há interferência (zona nefasta) entre as antenas.
/// </summary>
/// <param name="listaAntena">Apontador para a lista de antenas.</param>
/// <param name="antenaAtual">Apontador para a antena que está a ser verificada.</param>
/// <param name="linhas">Número de linhas da matriz.</param>
/// <param name="colunas">Número de colunas da matriz.</param>
/// <returns>Retorna 0.</returns>
int VerificarAntenaAnterior(Antena* listaAntena, Antena* auxAntenaAtual, int linhas, int colunas);
/// <summary>
/// Insere uma posição de interferência (zona nefasta) para uma antena.
/// Adiciona a posição à lista de zonas nefastas de ambas as antenas envolvidas.
/// </summary>
/// <param name="auxAntenaAnterior">Posição da antena anterior.</param>
/// <param name="auxAntenaAntes">Apontador para a antena anterior.</param>
/// <param name="auxAntenaAtual">Posição da antena atual.</param>
/// <param name="AntenaAtual">Apontador para a antena atual.</param>
void InserirNefasta(int* auxAntenaAnterior, Antena* auxAntenaAntes, int* auxAntenaAtual, Antena* AntenaAtual);
/// <summary>
/// Marca as zonas de interferência (zonas nefastas) entre duas antenas.
/// A interferência ocorre se as antenas partilharem a mesma frequência e estiverem na mesma área.
/// </summary>
/// <param name="antenaAnterior">Apontador para a antena anterior.</param>
/// <param name="antenaAtual">Apontador para a antena atual.</param>
/// <param name="auxAntenaAnterior">Posição da antena anterior.</param>
/// <param name="auxAntenaAtual">Posição da antena atual.</param>
void NefastaAntena(Antena* antenaAnterior, Antena* antenaAtual, int* auxAntenaAnterior, int* auxAntenaAtual);
/// <summary>
/// Apaga uma antena da lista de antenas, procurando pela sua posição na matriz.
/// Caso a antena seja encontrada, ela é removida da lista.
/// </summary>
/// <param name="listaAntena">Apontador para a lista de antenas.</param>
/// <param name="linha">Linha da antena a ser apagada.</param>
/// <param name="coluna">Coluna da antena a ser apagada.</param>
void ApagarAntena(Antena* listaAntenas,int linha, int coluna);
#endif