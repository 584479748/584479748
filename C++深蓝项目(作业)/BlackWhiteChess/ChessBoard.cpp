#include "ChessBoard.h"
#include <graphics.h>
#include "Game.h"


ChessBoard::ChessBoard()
{
	
}

ChessBoard::~ChessBoard()
{
	
}

//��������
void ChessBoard::Draw()
{
	//��ջ�ͼ�豸
	cleardevice(); 
	
	int x1,x2,y1,y2;
	
	//����ˮƽ��
	for(int i = 0;i<=Game::_gridCount;++i)
	{
		x1 = Game::_xStart;
		x2 = Game::_winWidth - x1;
		
		y1=y2=Game::_yStart + Game::_gridSize * i;
		
		line(x1,y1,x2,y2);
	}
	
	//���ƴ�ֱ��
	for(int i = 0;i<=Game::_gridCount;++i)
	{
		y1 = Game::_yStart;
		y2 = Game::_winHeight - y1;
		
		x1=x2=Game::_xStart + Game::_gridSize * i;
		
		line(x1,y1,x2,y2);
	}
}
