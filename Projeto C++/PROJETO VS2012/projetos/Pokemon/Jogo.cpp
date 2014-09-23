#include "Jogo.h"


void Jogo::controladorTelas()
{
	switch (tela)
	{
	case MENU:
		if(((TelaMenu*)te) -> desenhaInterface())
		{
			//Pergunta pro usuario o sexo e carrega a animacao passando o sexo
			player.setSexo(GAROTA);
			tela = CASAANDAR2; // depois do menu começa o jogo;
			entrouCenario = true;
		}
		break;

	case CASAANDAR2:
		if(entrouCenario)
		{
			mapa->carregar("dados/tilemaps/casaPersonagem.json");
			//mapa->carregarConfigTileSet("TileSetCasa" ,"dados/tilemaps/Tilesets/configCasa.txt");
			player.carregarAnimacao(mapa->getObjeto("Player"));
			mapa->setPosCentro(player.getXcentral(), player.getYcentral());
			entrouCenario = false;
		}
		if(teclado.pressionou[TECLA_S])
		{
			tela = ROTA01;
			mapa->descarregar();
			entrouCenario = true;
		}
		player.atualizar();
		testPlayerMapa();
		break;

	case ROTA01:
		if(entrouCenario)
		{
			mapa->carregar("dados/tilemaps/Rota01.json");
			mapa->carregarConfigTileSet("TileSetRotas" ,"dados/tilemaps/Tilesets/configRota01.txt");
			player.atualizarAnimacao(mapa->getObjeto("Player"));
			mapa->setPosCentro(player.getXcentral(), player.getYcentral()+10);
			
			entrouCenario = false;
		}
		if(teclado.pressionou[TECLA_D])
		{
			tela = VERIDIAN;
			mapa->descarregar();
			entrouCenario = true;
		}
		player.atualizar();
		testPlayerMapa();
		break;
	case VERIDIAN:
		if(entrouCenario)
		{
			mapa->carregar("dados/tilemaps/viridian.json");
			//mapa->carregarConfigTileSet("TileSetCasa" ,"dados/tilemaps/Tilesets/configCasa.txt");
			player.atualizarAnimacao(mapa->getObjeto("Player"));
			mapa->setPosCentro(player.getXcentral(), player.getYcentral()+10);
			entrouCenario = false;
		}
		player.atualizar();
		testPlayerMapa();
		break;
	}
}

Jogo::Jogo()
{
	mapa = new TileMap();
	tela = MENU;
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
	
	switch (tela)
	{
	case CASAANDAR2:
		mapa->setPosCentro(player.getXcentral(), player.getYcentral());
		break;
	case ROTA01:
		mapa->setPosCentro(player.getXcentral(), player.getYcentral()+10);
		break;
	case VERIDIAN:
		mapa->setPosCentro(player.getXcentral()+10, player.getYcentral()+10);
		break;
	default:
		break;
	}
		//	7)	desenhar o tilemap (player eh desenhado junto)
		mapa->desenhar();

}

void Jogo::inicializar()
{
	uniInicializar(600, 400, false);
	te = new TelaMenu();

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