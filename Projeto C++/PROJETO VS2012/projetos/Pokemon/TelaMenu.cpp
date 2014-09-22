#include "TelaMenu.h"

char maiusculas[4][7] = {{'A','B','C','D','E', 'F','.'},
							{'G','H', 'I', 'J', 'K', 'L',','},
							{'M','N','O','P','Q','R','S'},
							{'T','U','V','W','X','Y','Z'}};

TelaMenu::TelaMenu()
{
	fonte.carregar("dados/mono.ttf");
	nome.setFonte(&fonte);
	nome.setCor(0,0,0);

	//posição inicial do retangulo
	_x = 80; 
	_y = 200;

	xNome = 250;

	//total de valores das matrizes de letras
	totalValoresLinha = 4; //linhas
	totalValoresColuna = 7; //colunas

	indiceLinha=0;
	indiceColuna=0;

	controle = 5;

	int contadorLetras=0;

	recursos.carregarSpriteSheet("fundo","dados/Menu/menu.jpg",1,1);
	background.setSpriteSheet(recursos.getSpriteSheet("fundo"));

	recursos.carregarSpriteSheet("menu1","dados/Menu/letras.jpg",1,1);
	letras.setSpriteSheet(recursos.getSpriteSheet("menu1"));
	
	recursos.carregarSpriteSheet("menu2","dados/Menu/numeros.jpg",1,1);
	numeros.setSpriteSheet(recursos.getSpriteSheet("menu2"));	
}

TelaMenu::~TelaMenu()
{
}

void TelaMenu::controleLetras()
{
	if(teclado.pressionou[TECLA_DIR])
	{
		indiceColuna = (indiceColuna+1)%totalValoresColuna;
		if(_x==140)
			_x+=80;

		else if(_x==280)
		{
			if(_y>=200 && _y<=240)
				_x+=110;
			else
				_x+=30;
		}
		else if(_x==310)
			_x-=230;
		else if(_x==390)
			_x-=310;
		else
			_x+=30;
	}

	else if(teclado.pressionou[TECLA_ESQ])
	{
		indiceColuna--;
		if(indiceColuna<0)
			indiceColuna = totalValoresColuna;
		if(_x==80)
		{
			if(_y<=240)
				_x+=310;
			else 
				_x+=230;	
		}
		else if(_x==220)
			_x-=80;
		else if(_x==390)
			_x-=110;
		else
			_x-=30;
	}

	else if(teclado.pressionou[TECLA_CIMA])
	{
		indiceLinha--;
		if(indiceLinha<0)
			indiceLinha=totalValoresLinha;

		if(_y==200)
			_y+=120;
		else if(_y==280)
		{
			if(_x!=310)
				_y-=40;
		}
		else 
			_y-=40;
	}

	else if(teclado.pressionou[TECLA_BAIXO])
	{
		indiceLinha = (indiceLinha+1)%totalValoresLinha;

		if(_y==240)
		{
			if(_x!=390)
				_y+=40;
		}
		else if(_y==320)
		{
			if(_x==310)
				_y-=40;
			else
				_y-=120;
		}
		else 
			_y+=40;

	}
}

void TelaMenu::controleNumeros()
{
	if(teclado.pressionou[TECLA_DIR])
	{
		if(_x==300)
		{
			if(_y!=280)
				_x-=220;
			else
				_x+=55;
		}
		else if(_x==355)
			_x-=275;
		else 
			_x+=55;
	}	

	else if(teclado.pressionou[TECLA_ESQ])
	{
		if(_x==80)
		{
			if(_y!=280)
				_x+=220;
			else
				_x+=275;
		}
		else
			_x-=55;
	}

	else if(teclado.pressionou[TECLA_BAIXO])
	{
		if(_y==280)
		{
			if(_x!=355)
				_y+=40;
		}
		else if(_y==320)
			_y-=120;
		else
			_y+=40;
	}

	else if(teclado.pressionou[TECLA_CIMA])
	{
		if(_y==200)
			_y+=120;
		else if(_y==280)
		{
			if(_x!=355)
				_y-=40;
		}
		else
			_y-=40;
	}
}

int TelaMenu::desenhaInterface()
{
	int contadorLetras=0;

	if(teclado.pressionou[TECLA_F1])
		controle = 1; //letras
	else if(teclado.pressionou[TECLA_F2])
		controle = 2;//numeros
	else if(teclado.pressionou[TECLA_F3])
		controle =5;//fundo

	background.desenhar(res_x/2, res_y/2);

	switch(controle)
	{
	case 1:
		letras.desenhar(300,280);
		controleLetras();
		break;
	case 2:
		numeros.desenhar(300,280);
		controleNumeros();
		break;
	case 5:
		controleLetras();
		break;
	}

	//if(teclado.pressionou[TECLA_ENTER])
	//{
	//	nomePersonagem[contadorLetras]=maiusculas[indiceLinha][indiceColuna];
	//	contadorLetras++;
	//	//nome.setTexto(to_string());
	//}

	//nome.desenhar(xNome,140);
	//xNome+=20;

	uniDesenharRetangulo(_x, _y, 25, 35, 255, 0, 0, 255);

	if(mouse.pressionou[BOTAO_DIR])
		return 1;
	else
		return 0;

}
