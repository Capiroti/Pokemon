#include "Pessoa.h"

Sprite* Pessoa::getSprite()
{
	return &sprite;
}

Pessoa::Pessoa()
{
}

Pessoa::~Pessoa()
{
}

//GETTERS E SETTERS
string Pessoa::getNome(){return this->nome;}
int Pessoa::getIdade(){return this->idade;}
char Pessoa::getSexo(){return this->sexo;}
float Pessoa::getX(){return this->x;}
float Pessoa::getY(){return this->y;}
float Pessoa::getVel(){return this->vel;}

void Pessoa::setNome(string nome){this->nome = nome;}
void Pessoa::setIdade(int idade){this->idade = idade;}
void Pessoa::setSexo(char sexo){this->sexo = sexo;}
void Pessoa::setX(float pX){x = pX;}
void Pessoa::setY(float pY){y = pY;}
void Pessoa::setVel(float pVel){vel = pVel;}
//--------------------
	 
void Pessoa::Falar()
{
	cout << "Estou Falando!!!" << endl;
}

void Pessoa::Andar()
{
	cout << "Estou Andando!!!" << endl;
}

