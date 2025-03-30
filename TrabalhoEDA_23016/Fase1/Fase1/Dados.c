#pragma once
#include <stdio.h>
#include "Matriz.h"
#include <ctype.h>  
#pragma warning (disable: 4996)
#define TAMANHO_NOME_FICHEIRO 50

/// <summary>
/// Fun��o que carrega uma matriz a partir de um ficheiro de texto. 
/// O ficheiro deve conter caracteres que representam antenas, com letras (A-Z) e n�meros (0-9).
/// A fun��o l� as antenas e atribui-lhes frequ�ncias, criando as antenas na matriz conforme os dados do ficheiro.
/// </summary>
/// <param name="nomeFicheiro">Nome do ficheiro que cont�m os dados da matriz.</param>
/// <returns>Retorna um apontador para a matriz carregada, ou NULL em caso de erro.</returns>
Matriz* CarregarMatriz(char nomeFicheiro[TAMANHO_NOME_FICHEIRO])
{
	int linha = 0, coluna = 0;
	char caractere;

	// Abre o ficheiro para leitura
	FILE* txtApontador = fopen(nomeFicheiro, "r");
	if (txtApontador == NULL)
	{
		return NULL;  // Caso o ficheiro n�o seja encontrado, retorna NULL
	}

	int tempColuna = 0;
	// Conta o n�mero de linhas e colunas no ficheiro
	while ((caractere = fgetc(txtApontador)) != EOF)
	{
		if (caractere == '\n')
		{
			linha++;  // Conta uma nova linha
			if (tempColuna > coluna) coluna = tempColuna;  // Atualiza o n�mero de colunas, se necess�rio
			tempColuna = 0;  // Contador para 0
		}
		else
		{
			tempColuna++;  // Incrementa o contador de colunas
		}
	}

	// Volta ao in�cio do ficheiro para process�-lo novamente
	rewind(txtApontador);

	// Cria a matriz com o n�mero de linhas e colunas determinadas
	Matriz* matriz = CriarMatriz(linha, coluna);
	if (matriz == NULL)
	{
		fclose(txtApontador);  // Fecha o ficheiro antes de retornar NULL
		return NULL;
	}

	// Inicia o mapa de frequ�ncias
	double mapaFrequencias[36];
	for (int i = 0; i < 36; i++)
	{
		mapaFrequencias[i] = -1;  // Inicia todas as frequ�ncias como n�o atribu�das
	}
	int proximaFrequencia = 1;  // A frequ�ncia que ser� atribu�da � pr�xima antena

	linha = 0;
	int colAtual = 0;

	// L� o ficheiro para processar as antenas
	while ((caractere = fgetc(txtApontador)) != EOF)
	{
		if (caractere == '\n')
		{
			linha++;  // Avan�a para a pr�xima linha
			colAtual = 0;  // Colunas para 0
		}
		else
		{
			// Verifica se o car�cter � uma letra ou n�mero v�lido
			if ((caractere >= 'A' && caractere <= 'Z') || (caractere >= '0' && caractere <= '9'))
			{
				int indice;
				// Atribui um �ndice baseado no car�cter lido (A-Z ou 0-9)
				if (caractere >= 'A' && caractere <= 'Z')
				{
					indice = caractere - 'A';
				}
				else
				{
					indice = caractere - '0' + 26;
				}

				// Verifica se a frequ�ncia para o �ndice j� foi atribu�da, caso contr�rio atribui uma nova frequ�ncia
				if (mapaFrequencias[indice] == -1)
				{
					mapaFrequencias[indice] = (double)proximaFrequencia;
					proximaFrequencia++;  // Incrementa a pr�xima frequ�ncia a ser atribu�da
				}

				// Ajusta a linha para corresponder � posi��o correta na matriz
				int linhaAjustada = linha - 1;

				if (linhaAjustada >= 0)
				{
					// Cria uma nova antena e adiciona � matriz
					Antena* novaAntena = CriarAntena(matriz, linhaAjustada + 1, colAtual + 1, mapaFrequencias[indice]);
					if (novaAntena)
					{
						AdiconarAntenaMatriz(matriz, novaAntena);  // Adiciona a antena � matriz
					}
				}
			}
			colAtual++;  // Avan�a para a pr�xima coluna
		}
	}

	fclose(txtApontador);  // Fecha o ficheiro ap�s a leitura
	return matriz;  // Retorna a matriz carregada
}
