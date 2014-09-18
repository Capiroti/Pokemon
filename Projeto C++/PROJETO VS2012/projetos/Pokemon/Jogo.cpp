#include "Jogo.h"

void Jogo::controladorTelas()
{
	switch (tela)
	{
	case INICIAL:
		
		menu1.desenha();
		if(teclado.pressionou[TECLA_A]) tela = MENU;
		break;

	case MENU:
		//Pergunta pro usuario o sexo e carrega a animacao passando o sexo
		player.setSexo(GAROTA);
		mapa->carregar("dados/tilemaps/rota01.json");
		mapa->carregarConfigTileSet("TileSetRotas" ,"dados/tilemaps/Tilesets/configRota01.txt");
		player.carregarAnimacao(mapa->getObjeto("Player"));
		tela = JOGANDO; // depois do menu começa o jogo;
		break;

	case JOGANDO:
		player.atualizar();
		testPlayerMapa();
		break;
	}
}

Jogo::Jogo()
{
	tela = INICIAL;
	mapa = new TileMap();
	
}

Jogo::~Jogo()
{
}

void Jogo::testPlayerMapa()
{
	if(!player.estaMovendo())
		{
			if(teclado.segurando[TECLA_DIR])
			{
				if(mapa->tileECaminhavel(player.getXcentral() + 1.0, player.getYcentral()))
				{
					player.movePara(player.getXcentral() + 1.0, player.getYcentral());
				}
			}
			else if(teclado.segurando[TECLA_ESQ])
			{
				if(mapa->tileECaminhavel(player.getXcentral() - 1.0, player.getYcentral()))
				{
					player.movePara(player.getXcentral() - 1.0, player.getYcentral());
				}
			}
			else if(teclado.segurando[TECLA_CIMA])
			{
				if(mapa->tileECaminhavel(player.getXcentral(), player.getYcentral() - 1.0))
				{
					player.movePara(player.getXcentral(), player.getYcentral() - 1.0);
				}
			}
			else if(teclado.segurando[TECLA_BAIXO])
			{
				if(mapa->tileECaminhavel(player.getXcentral(), player.getYcentral() + 1.0))
				{
					player.movePara(player.getXcentral(), player.getYcentral() + 1.0);
				}
			}
		}

		//	6)	centraliza o mapa na posicao do player
	
		mapa->setPosCentro(player.getXcentral(), player.getYcentral()+10);
		
		//	7)	desenhar o tilemap (player eh desenhado junto)
		mapa->desenhar();

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
		uniDepurar("X",player.getXcentral());
		uniDepurar("Y", player.getYcentral());
		uniDepurar("x", player.getX());
		uniDepurar("y", player.getY());
	
		uniTerminarFrame();
	}
}