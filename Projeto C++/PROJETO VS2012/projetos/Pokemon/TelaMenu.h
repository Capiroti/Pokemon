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
	void setXYiniciais();
	void DesenhaTexto(char *texto, float x, float y, float distancia);
private:
	int controle; // controle de troca das opções de letras maiusculas, minusculas e numeros
	int _x, _y; // posição do retangulo
	int indiceLinha, indiceColuna; // indice de linha e coluna da matriz
	int totalValoresLinha, totalValoresColuna;
	Sprite background, letras, numeros;
	Texto nome;
	Fonte fonte;
	char nomePersonagem[8];
};

