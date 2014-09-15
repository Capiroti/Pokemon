#include "Personagem.h"

void Personagem::movimentacao()
{
	if(teclado.segurando[TECLA_DIR])
	{
		sprite.avancarAnimacao();
		this->x += vel;
		sprite.setAnimacao(ANDANDO_DIREITA);
	}
	else if(teclado.segurando[TECLA_ESQ])
	{
		sprite.avancarAnimacao();
		this->x -= vel;
		sprite.setAnimacao(ANDANDO_ESQUERDA);
	}
	else if(teclado.segurando[TECLA_CIMA])
	{
		sprite.avancarAnimacao();
		this->y -= vel;
		sprite.setAnimacao(ANDANDO_ACIMA);
	}
	else if(teclado.segurando[TECLA_BAIXO])
	{
		sprite.avancarAnimacao();
		this->y += vel;
		sprite.setAnimacao(ANDANDO_ABAIXO);
	}
	else sprite.setFrame(FRAME_ANIMACAO_PARADO);
}

void Personagem::carregarAnimacao()
{
	if(sexo == GAROTO)
	{
		animacao.carregar("dados/player.png", 4, 3);
		sprite.setSpriteSheet(&animacao);
		sprite.setVelocidadeAnimacao(3.0f);
	}

	if(sexo == GAROTA)
	{
		animacao.carregar("dados/playar.png", 4, 3);
		sprite.setSpriteSheet(&animacao);
		sprite.setVelocidadeAnimacao(3.0f);
	}
}

void Personagem::desenha() 
{
	sprite.desenhar(x, y);
}

Personagem::Personagem()
{
	x = 300;
	y = 200;
	vel = 0.4;
}

Personagem::~Personagem()
{
}
