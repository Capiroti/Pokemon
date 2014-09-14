#include "Jogo.h"

void Jogo::controladorTelas()
{
	switch (tela)
	{
	case MENU:
		//Pergunta pro usuario o sexo e carrega a animacao passando o sexo
		player.setSexo(GAROTA);
		player.carregarAnimacao();
		tela = JOGANDO; // depois do menu começa o jogo;
		break;

	case JOGANDO:
		player.desenha();
		player.movimentacao();
		break;
	}
}

Jogo::Jogo()
{
	tela = MENU;
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false);

	
}

void Jogo::finalizar()
{
	

	uniFinalizar();
}

void Jogo::executar()
{
	while(!teclado.soltou[TECLA_ESC] && !aplicacao.sair)
	{
		uniIniciarFrame();
		controladorTelas();
		uniTerminarFrame();
	}
}