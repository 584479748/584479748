#include <iostream>
#include <graphics.h>
#include "Game.h" 

int main(int argc, char** argv) {
	
	initgraph(Game::_winWidth,Game::_winHeight);
	
	//���ñ���ɫ 
	setbkcolor(EGERGB(40,150,170));
	
	Game game;
	
	//��Ϸ���� 
	game.Run();
	
	getch();
	
	closegraph();
	
	return 0;
}
