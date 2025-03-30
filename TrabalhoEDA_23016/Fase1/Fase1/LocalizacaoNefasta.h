#pragma once
#ifndef LOCALIZACAONEFASTA_H
#define LOCALIZACAONEFASTA_H
typedef struct LocalizaoNefasta
{
	int posNefasta[2];
	struct LocalizaoNefasta* proxNefasta;
}LocalizaoNefasta;
void VerificarNefasta(int posNefastaAntes[], int posNefastaAtual[], int linhas, int colunas);
#endif