#pragma once
#include "Tela.h"

class TelaMenu: public Tela
{
public:
	TelaMenu();
	~TelaMenu();
	int desenhaInterface();
	void controleLetras();
	void controleNumeros();
private:
	int controle; // controle de troca das op��es de letras maiusculas, minusculas e numeros
	int _x, _y; // posi��o do retangulo
	int indiceLinha, indiceColuna; // indice de linha e coluna da matriz
	int xNome;
	int totalValoresLinha, totalValoresColuna;
	Sprite background, letras, numeros;
	Texto nome;
	Fonte fonte;
	char nomePersonagem[7];
};

