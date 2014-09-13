#pragma once
#include <string>
#include <iostream>
#include "libunicornio.h"

using namespace std;

class Pessoa
{
protected:
	string nome;
	int idade;
	char sexo;
	float x, y, vel;
	Sprite sprite;
	SpriteSheet animacao;

public:
	Pessoa();
	~Pessoa();

	//GETTERS E SETTERS
	string getNome();
	Sprite* getSprite();
	int getIdade();
	char getSexo();
	float getX();
	float getY();
	float getVel();

	void setNome(string nome);
	void setIdade(int idade);
	void setSexo(char sexo);
	void setX(float pX);
	void setY(float pY);
	void setVel(float pvel);
	//--------------------

	void Falar();
	void Andar();
	//virtual void desenha() const = 0;
};

