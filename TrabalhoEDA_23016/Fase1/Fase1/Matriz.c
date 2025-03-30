#include <stdio.h>
#include <stdlib.h>
#include "Matriz.h"

/// <summary>
/// Cria uma nova matriz com o n�mero de linhas e colunas especificados.
/// Aloca mem�ria para a estrutura da matriz e para a lista de antenas.
/// </summary>
/// <param name="linhas">N�mero de linhas da matriz.</param>
/// <param name="colunas">N�mero de colunas da matriz.</param>
/// <returns>Retorna um apontador para a estrutura da matriz criada.</returns>
Matriz* CriarMatriz(int linhas, int colunas)
{
	Matriz* m;
	m = (Matriz*)malloc(sizeof(Matriz));
	m->tamMatriz[0] = linhas;
	m->tamMatriz[1] = colunas;
	m->listaAntenas = (ListaAntenas*)malloc(sizeof(ListaAntenas));
	m->listaAntenas->tamMatriz[0] = linhas;
	m->listaAntenas->tamMatriz[1] = colunas;
	m->listaAntenas->primAntena = NULL;
	return m;
}

/// <summary>
/// Cria uma nova antena numa posi��o espec�fica na matriz e a adiciona � lista de antenas.
/// Verifica tamb�m a posi��o da antena na lista de antenas j� existentes.
/// </summary>
/// <param name="m">Apontador para a estrutura da matriz.</param>
/// <param name="linha">Linha onde a antena ser� colocada.</param>
/// <param name="coluna">Coluna onde a antena ser� colocada.</param>
/// <param name="frequencia">Frequ�ncia da antena.</param>
/// <returns>Retorna um apontador para a antena criada.</returns>
Antena* CriarAntena(Matriz* m, int linha, int coluna, double frequencia)
{
	Antena* auxAntena;
	auxAntena = AdicionarAntena(linha, coluna, frequencia);
	AdiconarAntenaMatriz(m, auxAntena);
	VerificarAntenaAnterior(m->listaAntenas->primAntena, auxAntena, m->listaAntenas->tamMatriz[0], m->listaAntenas->tamMatriz[1]);

	return auxAntena;
}

/// <summary>
/// Elimina uma antena de uma posi��o espec�fica na matriz.
/// </summary>
/// <param name="m">Apontador para a estrutura da matriz.</param>
/// <param name="linha">Linha da antena a ser eliminada.</param>
/// <param name="coluna">Coluna da antena a ser eliminada.</param>
/// <returns>Retorna um apontador para a antena eliminada.</returns>
Antena* EliminarAntena(Matriz* m, int linha, int coluna)
{
	Antena* auxAntena = m->listaAntenas->primAntena;
	ApagarAntena(auxAntena, linha, coluna);
}

/// <summary>
/// Adiciona uma antena � lista de antenas de uma matriz.
/// Se a lista estiver vazia, a antena ser� a primeira da lista.
/// Caso contr�rio, a antena ser� adicionada ao final da lista.
/// </summary>
/// <param name="m">Apontador para a estrutura da matriz.</param>
/// <param name="antena">Apontador para a antena a ser adicionada.</param>
void AdiconarAntenaMatriz(Matriz* m, Antena* antena)
{
	if (m->listaAntenas->primAntena != NULL)
	{
		Antena* auxAntena = m->listaAntenas->primAntena;
		while (auxAntena->proxAntena != NULL)
		{
			auxAntena = auxAntena->proxAntena;
		}
		auxAntena->proxAntena = antena;
		antena->proxAntena = NULL;
	}
	else
	{
		m->listaAntenas->primAntena = antena;
		antena->proxAntena = NULL;
	}
}

/// <summary>
/// Mostra a matriz no terminal, representando as antenas e as zonas de interfer�ncia.
/// Utiliza caracteres para indicar a presen�a de antenas e zonas de interfer�ncia.
/// </summary>
/// <param name="m">Apontador para a estrutura da matriz.</param>
void MostrarMatriz(Matriz* m)
{
	for (int i = 1; i <= m->tamMatriz[0]; i++)
	{
		for (int j = 1; j <= m->tamMatriz[1]; j++)
		{
			Antena* auxAntena = m->listaAntenas->primAntena;
			char ponto = '.';
			while (auxAntena)
			{
				if (auxAntena->posAntena[0] == i && auxAntena->posAntena[1] == j)
				{
					ponto = 'A' + (auxAntena->frequencia - 1);
					break;
				}
				if (auxAntena->listaNefasta)
				{
					LocalizaoNefasta* nefasta = auxAntena->listaNefasta->locNefasta;
					while (nefasta)
					{
						if (nefasta->posNefasta[0] == i && nefasta->posNefasta[1] == j)
						{
							ponto = '#';
							break;
						}
						nefasta = nefasta->proxNefasta;
					}
					if (ponto == '#')
					{
						break;
					}
				}
				auxAntena = auxAntena->proxAntena;
			}
			printf("%c", ponto);
		}
		printf("\n");
	}
	printf("\nInforma��es das antenas:\n");
	Antena* auxAntena = m->listaAntenas->primAntena;
	int antennaCount = 1;

	while (auxAntena)
	{
		printf("\nAntena %d\n", antennaCount);
		printf("(x,y): (%d,%d)\n", auxAntena->posAntena[0], auxAntena->posAntena[1]);

		printf("Localiza��es Nefastas: ");
		if (auxAntena->listaNefasta && auxAntena->listaNefasta->locNefasta)
		{
			LocalizaoNefasta* nefasta = auxAntena->listaNefasta->locNefasta;
			while (nefasta)
			{
				printf("(%d,%d) ", nefasta->posNefasta[0], nefasta->posNefasta[1]);
				nefasta = nefasta->proxNefasta;
			}
		}
		else
		{
			printf("Nenhuma");
		}

		printf("\nFrequencia: %d\n", auxAntena->frequencia);

		auxAntena = auxAntena->proxAntena;
		antennaCount++;
	}
}
