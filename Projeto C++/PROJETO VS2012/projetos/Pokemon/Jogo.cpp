#include "Jogo.h"


void Jogo::controladorTelas()
{
	switch (indiceTela)
	{
	case MENU:
		if(telaMenu -> desenhaInterface())
		{
			//Pergunta pro usuario o sexo e carrega a animacao passando o sexo
			player.setSexo(GAROTA);
			indiceTela = ROTA01; // depois do menu come�a o jogo;
			entrouCenario = true;
		}
		break;

	case CASAANDAR2:
		if(entrouCenario)
		{
			carregarCenario("dados/TileMaps/Pallet.json","TileSetCenario" ,"dados/TileMaps/TileSets/ConfigTileSetCenario.txt",0,0);
			entrouCenario = false;
		}
		if(teclado.pressionou[TECLA_S])
		{
			indiceTela = ROTA01;
			entrouCenario = true;
		}
		break;

	case ROTA01:
		if(entrouCenario)
		{
			carregarCenario("dados/TileMaps/Rota01.json","TileSetCenario" ,"dados/TileMaps/TileSets/ConfigTileSetCenario.txt",0,0);
			entrouCenario = false;
		}		
		if(teclado.pressionou[TECLA_D])
		{
			indiceTela = VERIDIAN;
			entrouCenario = true;
		}
		break;
	case VERIDIAN:
		if(entrouCenario)
		{
			carregarCenario("dados/TileMaps/Viridian.json","TileSetCenario" ,"dados/TileMaps/TileSets/ConfigTileSetCenario.txt",0,0);
			entrouCenario = false;
		}
		break;
	}
	if(!entrouCenario)
	{
		player.atualizar();
		testPlayerMapa();
	}
}

void Jogo::carregarCenario(string json,string nomeTileSet, string caminhoTileSet, int addXCentral, int addYCentral)
{
	mapa.descarregar();
	telaCenario->setJson(json);
	telaCenario->setNomeTileSet(nomeTileSet);
	telaCenario->setCaminhoTileSet(caminhoTileSet);

	telaCenario->carregaMapa(mapa);
	telaCenario->desenhaInterface(player,"Player", addXCentral, addYCentral,mapa);
}

Jogo::Jogo()
{
	indiceTela = MENU;
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
				if(mapa.tileECaminhavel(player.getXcentral() + 1.0, player.getYcentral()))
				{
					player.movePara(player.getXcentral() + 1.0, player.getYcentral());
				}
			}
			else if(teclado.segurando[TECLA_ESQ])
			{
				if(mapa.tileECaminhavel(player.getXcentral() - 1.0, player.getYcentral()))
				{
					player.movePara(player.getXcentral() - 1.0, player.getYcentral());
				}
			}
			else if(teclado.segurando[TECLA_CIMA])
			{
				if(mapa.tileECaminhavel(player.getXcentral(), player.getYcentral() - 1.0))
				{
					player.movePara(player.getXcentral(), player.getYcentral() - 1.0);
				}
			}
			else if(teclado.segurando[TECLA_BAIXO])
			{
				if(mapa.tileECaminhavel(player.getXcentral(), player.getYcentral() + 1.0))
				{
					player.movePara(player.getXcentral(), player.getYcentral() + 1.0);
				}
			}
		}	
	
	switch (indiceTela)
	{
	case CASAANDAR2:
		mapa.setPosCentro(player.getXcentral(), player.getYcentral());
		break;
	case ROTA01:
		mapa.setPosCentro(player.getXcentral(), player.getYcentral()+10);
		break;
	case VERIDIAN:
		mapa.setPosCentro(player.getXcentral()+10, player.getYcentral()+10);
		break;
	default:
		break;
	}
		//	7)	desenhar o tilemap (player eh desenhado junto)
		mapa.desenhar();

}

void Jogo::inicializar()
{
	uniInicializar(600, 400, false);
	telaMenu = new TelaMenu();
	telaCenario = new TelaCenario();
}

void Jogo::finalizar()
{
	telaMenu->~TelaMenu();
	telaCenario->~TelaCenario();
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