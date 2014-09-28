#pragma once
#include "Tela.h"
#include <fstream>

class TelaMenu: public Tela
{
private:
	int controle; // controle de troca das opções de letras maiusculas, minusculas e numeros
	int _x, _y; // posição do retangulo
	int _x2,_y2; //posição do item de navegação dos sexos
	int indiceLinha, indiceColuna; // indice de linha e coluna atual das matrizes
	int totalValoresLinha, totalValoresColuna; // total de valores de colunas e linhas das matrizes, pode variar
	int contadorLetras;
	Sprite letrasMai, letrasMin, numeros, fundoEscolhaSexo, navegacao, opcoes; // sprites
	Texto nome,opcaoF,opcaoM;
	Fonte fonte;
	char nomePersonagem[12];
	char *caracteres;
	int sexo;
	int telaAtual,proximaTela;

public:
	TelaMenu();
	~TelaMenu();

	int controladorTelasIniciais();
	int getSexo();
	string getNome();
	//menus iniciais
	int desenhaInterfaceNome();
	int desenhaInterfaceSexo();
	void controleLetras();
	void controleNumeros();
	void setXYiniciais();
	void setValoresLinhaColuna(int l, int c);
	void setArray_SetValores(int linhas, int colunas, int tipo);
	void inicializaArrayCaracteres(int tipo);
	void carregarSprites();
	void DesenhaTexto(char *texto, float x, float y);

};

