#include <stdio.h>
#include <stdlib.h>
#include "LocalizacaoNefasta.h"

/// <summary>
/// Verifica se existe uma interfer�ncia (zona nefasta) entre duas posi��es especificadas
/// nas vari�veis `posNefastaAntes` e `posNefastaAtual`. A interfer�ncia � calculada com base
/// na diferen�a das posi��es e ajusta as posi��es de forma a garantir que a zona nefasta seja criada
/// corretamente. Caso a nova posi��o ultrapasse os limites da matriz, a posi��o � anulada.
/// </summary>
/// <param name="posNefastaAntes">Posi��o da antena ou local antes da interfer�ncia.</param>
/// <param name="posNefastaAtual">Posi��o da antena ou local ap�s a interfer�ncia.</param>
/// <param name="linhas">N�mero total de linhas na matriz.</param>
/// <param name="colunas">N�mero total de colunas na matriz.</param>
void VerificarNefasta(int posNefastaAntes[], int posNefastaAtual[], int linhas, int colunas)
{
	int xNovo = 0, yNovo = 0;

	// Calcula a diferen�a entre as posi��es ao longo do eixo X e Y
	xNovo = Abs(posNefastaAntes[0] - posNefastaAtual[0]);
	yNovo = Abs(posNefastaAntes[1] - posNefastaAtual[1]);

	// Verifica se a diferen�a nas posi��es � suficiente para se considerar uma zona nefasta
	if ((xNovo + yNovo >= 2) && (posNefastaAntes[0] + xNovo == posNefastaAtual[0]))
	{
		// Ajusta a posi��o no eixo X
		posNefastaAntes[0] = posNefastaAntes[0] - xNovo;
		posNefastaAtual[0] = posNefastaAtual[0] + xNovo;

		// Ajusta a posi��o no eixo Y, dependendo da dire��o da interfer�ncia
		if (posNefastaAntes[1] + yNovo == posNefastaAtual[1])
		{
			posNefastaAntes[1] = posNefastaAntes[1] - yNovo;
			posNefastaAtual[1] = posNefastaAtual[1] + yNovo;
		}
		else
		{
			posNefastaAntes[1] = posNefastaAntes[1] + yNovo;
			posNefastaAtual[1] = posNefastaAtual[1] - yNovo;
		}
	}
	else
	{
		// Ajusta a posi��o no eixo X em caso de diferen�a n�o suficiente
		posNefastaAntes[0] = posNefastaAntes[0] + xNovo;
		posNefastaAtual[0] = posNefastaAtual[0] - xNovo;

		// Ajusta a posi��o no eixo Y
		if (posNefastaAntes[1] + yNovo == posNefastaAtual[1])
		{
			posNefastaAntes[1] = posNefastaAntes[1] - yNovo;
			posNefastaAtual[1] = posNefastaAtual[1] + yNovo;
		}
		else
		{
			posNefastaAntes[1] = posNefastaAntes[1] + yNovo;
			posNefastaAtual[1] = posNefastaAtual[1] - yNovo;
		}
	}

	// Verifica se as novas posi��es ultrapassam os limites da matriz
	if (posNefastaAntes[0] > linhas || posNefastaAntes[1] > colunas)
	{
		// Anula a posi��o, caso ela ultrapasse o limite
		posNefastaAntes[0] = NULL;
		posNefastaAntes[1] = NULL;
	}
	if (posNefastaAtual[0] > linhas || posNefastaAtual[1] > colunas)
	{
		// Anula a posi��o, caso ela ultrapasse o limite
		posNefastaAtual[0] = NULL;
		posNefastaAtual[1] = NULL;
	}
}

/// <summary>
/// Fun��o auxiliar que retorna o valor absoluto de um n�mero inteiro.
/// </summary>
/// <param name="n">N�mero inteiro a ser verificado.</param>
/// <returns>Retorna o valor absoluto de `n`.</returns>
int Abs(int n)
{
	if (n < 0) return -n;  // Se `n` for negativo, retorna o valor positivo
	return n;               // Caso contr�rio, retorna `n` tal como est�
}
