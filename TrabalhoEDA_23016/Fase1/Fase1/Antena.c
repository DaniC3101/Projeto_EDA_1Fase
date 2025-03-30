#include <stdio.h>
#include <stdlib.h>
#include "Antena.h"

/// <summary>
/// Adiciona uma nova antena numa posição específica da matriz.
/// A antena recebe a posição, a frequência e um apontador para a próxima antena (inicialmente NULL).
/// </summary>
/// <param name="linha">Linha onde a antena será colocada.</param>
/// <param name="coluna">Coluna onde a antena será colocada.</param>
/// <param name="frequencia">Frequência da antena.</param>
/// <returns>Retorna um apontador para a antena criada.</returns>
Antena* AdicionarAntena(int linha, int coluna, int frequencia)
{
	Antena* antena = (Antena*)malloc(sizeof(Antena));
	antena->posAntena[0] = linha;
	antena->posAntena[1] = coluna;
	antena->frequencia = frequencia;
	antena->proxAntena = NULL;
	antena->listaNefasta = NULL;
	return antena;
}

/// <summary>
/// Apaga uma antena da lista de antenas, procurando pela sua posição na matriz.
/// Caso a antena seja encontrada, ela é removida da lista.
/// </summary>
/// <param name="listaAntena">Apontador para a lista de antenas.</param>
/// <param name="linha">Linha da antena a ser apagada.</param>
/// <param name="coluna">Coluna da antena a ser apagada.</param>
void ApagarAntena(Antena* listaAntena, int linha, int coluna)
{
	Antena* auxAntena = listaAntena;

	while (auxAntena != NULL)
	{
		Antena* aa = auxAntena->proxAntena;
		if ((aa->posAntena[0] == linha) && (aa->posAntena[1] == coluna))
		{
			auxAntena->proxAntena = NULL;
		}
		auxAntena = auxAntena->proxAntena;
	}
}

/// <summary>
/// Verifica se uma antena com a mesma frequência já existe na lista de antenas.
/// Se encontrar, verifica se há interferência (zona nefasta) entre as antenas.
/// </summary>
/// <param name="listaAntena">Apontador para a lista de antenas.</param>
/// <param name="antenaAtual">Apontador para a antena que está a ser verificada.</param>
/// <param name="linhas">Número de linhas da matriz.</param>
/// <param name="colunas">Número de colunas da matriz.</param>
/// <returns>Retorna 0.</returns>
int VerificarAntenaAnterior(Antena* listaAntena, Antena* antenaAtual, int linhas, int colunas)
{
	Antena* auxAntenaAntes = listaAntena;

	while (auxAntenaAntes != antenaAtual)
	{
		int auxAntenaAnterior[2] = { auxAntenaAntes->posAntena[0], auxAntenaAntes->posAntena[1] };
		int auxAntenaAtual[2] = { antenaAtual->posAntena[0], antenaAtual->posAntena[1] };
		if (auxAntenaAntes->frequencia == antenaAtual->frequencia)
		{
			VerificarNefasta(auxAntenaAnterior, auxAntenaAtual, linhas, colunas);
			NefastaAntena(auxAntenaAntes, antenaAtual, auxAntenaAnterior, auxAntenaAtual);
		}
		auxAntenaAntes = auxAntenaAntes->proxAntena;
	}
	return 0;
}

/// <summary>
/// Marca as zonas de interferência (zonas nefastas) entre duas antenas.
/// A interferência ocorre se as antenas partilharem a mesma frequência e estiverem na mesma área.
/// </summary>
/// <param name="antenaAnterior">Apontador para a antena anterior.</param>
/// <param name="antenaAtual">Apontador para a antena atual.</param>
/// <param name="auxAntenaAnterior">Posição da antena anterior.</param>
/// <param name="auxAntenaAtual">Posição da antena atual.</param>
void NefastaAntena(Antena* antenaAnterior, Antena* antenaAtual, int* auxAntenaAnterior, int* auxAntenaAtual)
{
	Antena* auxAntenaAntes = antenaAnterior;

	while (auxAntenaAntes != antenaAtual)
	{
		if ((auxAntenaAnterior[0] == auxAntenaAntes->posAntena[0] && auxAntenaAnterior[1] == auxAntenaAntes->posAntena[1]))
		{
			auxAntenaAnterior[0] = -1;
		}
		if ((auxAntenaAtual[0] == auxAntenaAntes->posAntena[0] && auxAntenaAtual[1] == auxAntenaAntes->posAntena[1]))
		{
			auxAntenaAtual = -1;
		}
		auxAntenaAntes = auxAntenaAntes->proxAntena;
	}
	InserirNefasta(auxAntenaAnterior, antenaAnterior, auxAntenaAtual, antenaAtual);
}

/// <summary>
/// Insere uma posição de interferência (zona nefasta) para uma antena.
/// Adiciona a posição à lista de zonas nefastas de ambas as antenas envolvidas.
/// </summary>
/// <param name="auxAntenaAnterior">Posição da antena anterior.</param>
/// <param name="auxAntenaAntes">Apontador para a antena anterior.</param>
/// <param name="auxAntenaAtual">Posição da antena atual.</param>
/// <param name="AntenaAtual">Apontador para a antena atual.</param>
void InserirNefasta(int* auxAntenaAnterior, Antena* auxAntenaAntes, int* auxAntenaAtual, Antena* AntenaAtual)
{
	if (auxAntenaAntes != NULL && auxAntenaAnterior[0] != -1 && auxAntenaAnterior[0] != 0 && auxAntenaAnterior[1] != 0)
	{
		LocalizaoNefasta* novaPosicao = (LocalizaoNefasta*)malloc(sizeof(LocalizaoNefasta));
		novaPosicao->posNefasta[0] = auxAntenaAnterior[0];
		novaPosicao->posNefasta[1] = auxAntenaAnterior[1];
		novaPosicao->proxNefasta = NULL;
		if (auxAntenaAntes->listaNefasta == NULL)
		{
			auxAntenaAntes->listaNefasta = (LocalizaoNefasta*)malloc(sizeof(LocalizaoNefasta));
			auxAntenaAntes->listaNefasta->locNefasta = novaPosicao;
		}
		else
		{
			LocalizaoNefasta* temp = auxAntenaAntes->listaNefasta->locNefasta;
			while (temp->proxNefasta != NULL)
			{
				temp = temp->proxNefasta;
			}
			temp->proxNefasta = novaPosicao;
		}
	}
	if (auxAntenaAtual[0] != -1 && auxAntenaAtual[0] != 0 && auxAntenaAtual[1] != 0)
	{
		LocalizaoNefasta* novaPosicao = (LocalizaoNefasta*)malloc(sizeof(LocalizaoNefasta));
		novaPosicao->posNefasta[0] = auxAntenaAtual[0];
		novaPosicao->posNefasta[1] = auxAntenaAtual[1];
		novaPosicao->proxNefasta = NULL;

		if (AntenaAtual->listaNefasta == NULL)
		{
			AntenaAtual->listaNefasta = (ListaNefastas*)malloc(sizeof(ListaNefastas));
			AntenaAtual->listaNefasta->locNefasta = novaPosicao;
		}
		else
		{
			LocalizaoNefasta* temp = AntenaAtual->listaNefasta->locNefasta;
			while (temp->proxNefasta != NULL)
			{
				temp = temp->proxNefasta;
			}
			temp->proxNefasta = novaPosicao;
		}
	}
}
