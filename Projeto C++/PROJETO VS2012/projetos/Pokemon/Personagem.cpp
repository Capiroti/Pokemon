#include "Personagem.h"

void Personagem::atualizar()
{
	if(movendo)
	{
		if(nextX - oldX > 0.0)
		{
			sprite.setAnimacao(ANDANDO_DIREITA);
		}
		else if(nextX - oldX < 0.0)
		{
			sprite.setAnimacao(ANDANDO_ESQUERDA);
		}
		else if(nextY - oldY > 0.0)
		{
			sprite.setAnimacao(ANDANDO_ABAIXO);
		}
		else if(nextY - oldY < 0.0)
		{
			sprite.setAnimacao(ANDANDO_ACIMA);
		}

		float x1 = oldX + (nextX - oldX)*interpolador;
		float y1 = oldY + (nextY - oldY)*interpolador;

		interpolador += vel*deltaTempo;
		if(interpolador >= 1.0)
		{
			interpolador = 0.0f;
			x1 = nextX;
			y1 = nextY;
			oldX = nextX;
			oldY = nextY;
			movendo = false;
		}
		objeto->setPosCentro(x1, y1);

		sprite.avancarAnimacao();
	}
	else
	{
		sprite.setFrame(FRAME_ANIMACAO_PARADO);
	}
}

void Personagem::carregarAnimacao(ObjetoTile* obj)
{
	if(!this->spritesCarregados)
	{
		if(this->sexo == GAROTO)
			animacao.carregar("dados/player.png", 4, 3);
		else if(this->sexo == GAROTA)
			animacao.carregar("dados/playar.png", 4, 3);
			
		this->sprite.setSpriteSheet(&animacao);
		this->sprite.setVelocidadeAnimacao(3.0f);
		
		this->spritesCarregados = true;
	}
	//setando o objeto que criei no tiled pro objeto que ganha o sprite
	this->objeto = obj;
	obj->setSprite(&sprite);

	//setando valores iniciais
	movendo = false;
	oldX = obj->getXCentro();
	oldY = obj->getYCentro();
	nextX = 0;
	nextY = 0;							
	interpolador = 0.0f;
	vel = 1.5;
}

void Personagem::atualizarAnimacao(ObjetoTile* obj)
{
	//setando o objeto que criei no tiled pro objeto que ganha o sprite
	this->objeto = obj;
	obj->setSprite(&sprite);

	//setando valores iniciais
	movendo = false;
	oldX = obj->getXCentro();
	oldY = obj->getYCentro();
	nextX = 0;
	nextY = 0;							
	interpolador = 0.0f;
	vel = 1.0;
}

void Personagem::movePara(float x, float y)
{
	nextX = x;
	nextY = y;
	movendo = true;
}

float Personagem::getXcentral(){return objeto->getXCentro();}

float Personagem::getYcentral(){return objeto->getYCentro();}

bool Personagem::estaMovendo(){return movendo;}

bool Personagem::getSpritesCarregados(){ return this->spritesCarregados;}

void Personagem::setSpritesCarregados(bool spritesCarregados){ this->spritesCarregados = spritesCarregados;}

Personagem::Personagem()
{
	vel = 0.4;
}

Personagem::~Personagem()
{
}
