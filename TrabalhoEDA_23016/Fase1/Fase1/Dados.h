#pragma once
#include "Matriz.h"
#define TAMANHO_NOME_FICHEIRO 50
/// <summary>
/// Fun��o que carrega uma matriz a partir de um ficheiro de texto. 
/// O ficheiro deve conter caracteres que representam antenas, com letras (A-Z) e n�meros (0-9).
/// A fun��o l� as antenas e atribui-lhes frequ�ncias, criando as antenas na matriz conforme os dados do ficheiro.
/// </summary>
/// <param name="nomeFicheiro">Nome do ficheiro que cont�m os dados da matriz.</param>
/// <returns>Retorna um apontador para a matriz carregada, ou NULL em caso de erro.</returns>
Matriz* CarregarMatriz(char nomeFicheiro[TAMANHO_NOME_FICHEIRO]);