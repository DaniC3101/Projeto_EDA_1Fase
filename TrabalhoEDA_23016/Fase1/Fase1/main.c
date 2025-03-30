#include "Matriz.h"
#include "Dados.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "portuguese");
	/// <summary>
	/// Função que carrega uma matriz a partir de um ficheiro de texto. 
	/// </summary>
	/// <param name="Matriz.txt">Nome do ficheiro que contém os dados da matriz.</param>
	Matriz* m = CarregarMatriz("Matriz.txt");
	MostrarMatriz(m);


	/// <summary>
	/// Criar a mesma Matriz com as mesmas antenas e chamar os métodos para isso 
	/// </summary>
	//Matriz* m = CriarMatriz(12, 12);
	//CriarAntena(m, 6, 7, 1);
	//CriarAntena(m, 10, 10, 1);
	//CriarAntena(m, 9, 9, 1);
	//CriarAntena(m, 2, 9, 2);
	//CriarAntena(m, 3, 6, 2);
	//CriarAntena(m, 4, 8, 2);
	//CriarAntena(m, 5, 5, 2);
	//MostrarMatriz(m);
}