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

public:
	void carregarAnimacao();
	void atualiza();
	void desenha();
	void movimentacao();
	//void desenha() const;
	

	Personagem();
	~Personagem();
};
