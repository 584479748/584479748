#include"Game.h"
#include<graphics.h>


int Game::_gridSize=50;    //���ӵĴ�С
int Game::_gridCount=8;    //���ӵĸ���
int Game::_winWidth=640;   //���ڵĿ�� 
int Game::_winHeigh=480;   //���ڵĸ߶� 
int Game::_pieceSize=_gridSize/2-2;   //���Ӵ�С 

//��ʼλ�õ�x���� 
int Game::_xStart=(_winWidth-_gridSize*_gridCount)/2;

//��ʼλ�õ�y���� 
int Game::_yStart=(_winHeigh-_gridSize*_gridCount)/2; 



Game::Game()
{
	
}


Game::~Game()
{
	
}


//��Ϸ���� 
void Game::Run()
{
	//�������� 
    _cb.Draw();
    
    //��������
	_layout.Draw();
	
	POS pos;
	
	for(;is_run();delay_fps(100))
	{
		//��ȡ���λ��
		while(!GetMouseHit(pos));
		
		//�������� 
		_layout.SetPieces(pos);

		//��������
		_cb.Draw(); 
		
		//�������� 
		_layout.Draw();
		
	
		delay_fps(100);
	}
 
    
    
} 

//��ȡ���λ��
bool Game::GetMouseHit(POS& pos)
{
	mouse_msg msg=getmouse();
	
	if(msg.is_left()&&msg.is_down())
	{
		if(msg.x-_xStart>0 && msg.y-_yStart>0)
		{
			pos.row=(msg.y-_yStart)/_gridSize;
			
			pos.col=(msg.x-_xStart)/_gridSize;
			
			if(pos.row>=0 && pos.row<_gridCount && 
			    pos.col>=0 && pos.col<_gridCount)
			{
				return true;
			}
		}
	}
	return false;
}























