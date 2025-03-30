#pragma once
#include "Matriz.h"
#define TAMANHO_NOME_FICHEIRO 50
/// <summary>
/// Função que carrega uma matriz a partir de um ficheiro de texto. 
/// O ficheiro deve conter caracteres que representam antenas, com letras (A-Z) e números (0-9).
/// A função lê as antenas e atribui-lhes frequências, criando as antenas na matriz conforme os dados do ficheiro.
/// </summary>
/// <param name="nomeFicheiro">Nome do ficheiro que contém os dados da matriz.</param>
/// <returns>Retorna um apontador para a matriz carregada, ou NULL em caso de erro.</returns>
Matriz* CarregarMatriz(char nomeFicheiro[TAMANHO_NOME_FICHEIRO]);