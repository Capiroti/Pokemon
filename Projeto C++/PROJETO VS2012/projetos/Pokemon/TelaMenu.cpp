#include "TelaMenu.h"

void TelaMenu::desenha() 
{
	
	recursos.carregarSpriteSheet("fundo", "dados/menu.jpg", 1,1);
	fundo.setSpriteSheet(recursos.getSpriteSheet("fundo"));
	fundo.desenhar(res_x/2, res_y/2);
}

TelaMenu::TelaMenu()
{

}


TelaMenu::~TelaMenu()
{
}
