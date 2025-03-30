#include <stdio.h>
#include <stdlib.h>
#include "LocalizacaoNefasta.h"

/// <summary>
/// Verifica se existe uma interferência (zona nefasta) entre duas posições especificadas
/// nas variáveis `posNefastaAntes` e `posNefastaAtual`. A interferência é calculada com base
/// na diferença das posições e ajusta as posições de forma a garantir que a zona nefasta seja criada
/// corretamente. Caso a nova posição ultrapasse os limites da matriz, a posição é anulada.
/// </summary>
/// <param name="posNefastaAntes">Posição da antena ou local antes da interferência.</param>
/// <param name="posNefastaAtual">Posição da antena ou local após a interferência.</param>
/// <param name="linhas">Número total de linhas na matriz.</param>
/// <param name="colunas">Número total de colunas na matriz.</param>
void VerificarNefasta(int posNefastaAntes[], int posNefastaAtual[], int linhas, int colunas)
{
	int xNovo = 0, yNovo = 0;

	// Calcula a diferença entre as posições ao longo do eixo X e Y
	xNovo = Abs(posNefastaAntes[0] - posNefastaAtual[0]);
	yNovo = Abs(posNefastaAntes[1] - posNefastaAtual[1]);

	// Verifica se a diferença nas posições é suficiente para se considerar uma zona nefasta
	if ((xNovo + yNovo >= 2) && (posNefastaAntes[0] + xNovo == posNefastaAtual[0]))
	{
		// Ajusta a posição no eixo X
		posNefastaAntes[0] = posNefastaAntes[0] - xNovo;
		posNefastaAtual[0] = posNefastaAtual[0] + xNovo;

		// Ajusta a posição no eixo Y, dependendo da direção da interferência
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
		// Ajusta a posição no eixo X em caso de diferença não suficiente
		posNefastaAntes[0] = posNefastaAntes[0] + xNovo;
		posNefastaAtual[0] = posNefastaAtual[0] - xNovo;

		// Ajusta a posição no eixo Y
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

	// Verifica se as novas posições ultrapassam os limites da matriz
	if (posNefastaAntes[0] > linhas || posNefastaAntes[1] > colunas)
	{
		// Anula a posição, caso ela ultrapasse o limite
		posNefastaAntes[0] = NULL;
		posNefastaAntes[1] = NULL;
	}
	if (posNefastaAtual[0] > linhas || posNefastaAtual[1] > colunas)
	{
		// Anula a posição, caso ela ultrapasse o limite
		posNefastaAtual[0] = NULL;
		posNefastaAtual[1] = NULL;
	}
}

/// <summary>
/// Função auxiliar que retorna o valor absoluto de um número inteiro.
/// </summary>
/// <param name="n">Número inteiro a ser verificado.</param>
/// <returns>Retorna o valor absoluto de `n`.</returns>
int Abs(int n)
{
	if (n < 0) return -n;  // Se `n` for negativo, retorna o valor positivo
	return n;               // Caso contrário, retorna `n` tal como está
}
