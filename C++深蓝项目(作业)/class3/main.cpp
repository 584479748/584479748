#include<iostream>
#include<graphics.h>
#include"Game.h"

/* run this program using the console pauser or add 
your own getch, system("pause") or input loop */
int main(int argc,char ** argv)
{
	initgraph(Game::_winWidth,Game::_winHeigh);
	
	//���ñ���ɫ
	setbkcolor(EGERGB(40,150,170));
	 
	Game game;
	
	
	//��Ϸ���� 
	game.Run();
	
	getch();
	
	
	closegraph();
	
	return 0;
} 
