#pragma once
#include <stdio.h>
#include "Matriz.h"
#include <ctype.h>  
#pragma warning (disable: 4996)
#define TAMANHO_NOME_FICHEIRO 50

/// <summary>
/// Função que carrega uma matriz a partir de um ficheiro de texto. 
/// O ficheiro deve conter caracteres que representam antenas, com letras (A-Z) e números (0-9).
/// A função lê as antenas e atribui-lhes frequências, criando as antenas na matriz conforme os dados do ficheiro.
/// </summary>
/// <param name="nomeFicheiro">Nome do ficheiro que contém os dados da matriz.</param>
/// <returns>Retorna um apontador para a matriz carregada, ou NULL em caso de erro.</returns>
Matriz* CarregarMatriz(char nomeFicheiro[TAMANHO_NOME_FICHEIRO])
{
	int linha = 0, coluna = 0;
	char caractere;

	// Abre o ficheiro para leitura
	FILE* txtApontador = fopen(nomeFicheiro, "r");
	if (txtApontador == NULL)
	{
		return NULL;  // Caso o ficheiro não seja encontrado, retorna NULL
	}

	int tempColuna = 0;
	// Conta o número de linhas e colunas no ficheiro
	while ((caractere = fgetc(txtApontador)) != EOF)
	{
		if (caractere == '\n')
		{
			linha++;  // Conta uma nova linha
			if (tempColuna > coluna) coluna = tempColuna;  // Atualiza o número de colunas, se necessário
			tempColuna = 0;  // Contador para 0
		}
		else
		{
			tempColuna++;  // Incrementa o contador de colunas
		}
	}

	// Volta ao início do ficheiro para processá-lo novamente
	rewind(txtApontador);

	// Cria a matriz com o número de linhas e colunas determinadas
	Matriz* matriz = CriarMatriz(linha, coluna);
	if (matriz == NULL)
	{
		fclose(txtApontador);  // Fecha o ficheiro antes de retornar NULL
		return NULL;
	}

	// Inicia o mapa de frequências
	double mapaFrequencias[36];
	for (int i = 0; i < 36; i++)
	{
		mapaFrequencias[i] = -1;  // Inicia todas as frequências como não atribuídas
	}
	int proximaFrequencia = 1;  // A frequência que será atribuída à próxima antena

	linha = 0;
	int colAtual = 0;

	// Lê o ficheiro para processar as antenas
	while ((caractere = fgetc(txtApontador)) != EOF)
	{
		if (caractere == '\n')
		{
			linha++;  // Avança para a próxima linha
			colAtual = 0;  // Colunas para 0
		}
		else
		{
			// Verifica se o carácter é uma letra ou número válido
			if ((caractere >= 'A' && caractere <= 'Z') || (caractere >= '0' && caractere <= '9'))
			{
				int indice;
				// Atribui um índice baseado no carácter lido (A-Z ou 0-9)
				if (caractere >= 'A' && caractere <= 'Z')
				{
					indice = caractere - 'A';
				}
				else
				{
					indice = caractere - '0' + 26;
				}

				// Verifica se a frequência para o índice já foi atribuída, caso contrário atribui uma nova frequência
				if (mapaFrequencias[indice] == -1)
				{
					mapaFrequencias[indice] = (double)proximaFrequencia;
					proximaFrequencia++;  // Incrementa a próxima frequência a ser atribuída
				}

				// Ajusta a linha para corresponder à posição correta na matriz
				int linhaAjustada = linha - 1;

				if (linhaAjustada >= 0)
				{
					// Cria uma nova antena e adiciona à matriz
					Antena* novaAntena = CriarAntena(matriz, linhaAjustada + 1, colAtual + 1, mapaFrequencias[indice]);
					if (novaAntena)
					{
						AdiconarAntenaMatriz(matriz, novaAntena);  // Adiciona a antena à matriz
					}
				}
			}
			colAtual++;  // Avança para a próxima coluna
		}
	}

	fclose(txtApontador);  // Fecha o ficheiro após a leitura
	return matriz;  // Retorna a matriz carregada
}
