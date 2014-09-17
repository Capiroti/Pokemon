#pragma once
#include "Pessoa.h"
#include "libunicornio.h"

#define GAROTO 0
#define GAROTA 1

#define ANDANDO_ABAIXO 0
#define ANDANDO_ACIMA 1
#define ANDANDO_DIREITA 2
#define ANDANDO_ESQUERDA 3
#define FRAME_ANIMACAO_PARADO 1

class Personagem : public Pessoa
{
private:
	bool movendo;
	float oldX, oldY, nextX, nextY, interpolador;
	ObjetoTile* objeto;

public:
	void carregarAnimacao(ObjetoTile* obj);
	void atualizar();
	void movePara(float x, float y);

	bool estaMovendo();

	float getXcentral();
	float getYcentral();

	Personagem();
	~Personagem();
};
