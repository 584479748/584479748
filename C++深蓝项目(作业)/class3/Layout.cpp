#include"Layout.h"
#include"Game.h" 
#include<graphics.h>


Layout::Layout()
{

	//�����������ڴ�
	_layout.resize(Game::_gridCount);
	
	for(int i=0;i<Game::_gridCount;++i)
	{
		_layout[i].resize(Game::_gridCount);
	}
	
	//��ʼ�����̸��ӵ����� 
	for(int i=0;i<Game::_gridCount;++i)
	{
		for(int j=0;j<Game::_gridCount;++j)
		{
			_layout[i][j]=CP_NOTHING; 
		}
	}
	//���ö�Ӧ��λ��Ϊ����
	_layout[3][3]=_layout[4][4]=CP_WHITE;
	
	//���ö�Ӧ��λ��Ϊ���� 
	_layout[3][4]=_layout[4][3]=CP_BLACK;
	
	//�������
	_player=CP_BLACK; 
	

}


Layout::~Layout()
{
	
}

// �������� 
void Layout::Draw()
{
	for(int i=0;i<Game::_gridCount;++i)
	{
		for(int j=0;j<Game::_gridCount;++j)
		{
			//����Ǻ��� 
			if(_layout[i][j]==CP_BLACK)
			{
				//�������ɫΪ��ɫ 
				setfillcolor(EGERGB(0,0,0));
			}
			else if(_layout[i][j]==CP_WHITE) 
			{
				//����ǰ���
				//�������ɫΪ��ɫ
				setfillcolor(EGERGB(255,255,255));
			}
			else
			{
				continue;
			}
			
			//Բ�ĵ�����
			int x=Game::_xStart+j*Game::_gridSize+Game::_gridSize/2;
			int y=Game::_yStart+i*Game::_gridSize+Game::_gridSize/2;
			
			//��������
			fillellipse(x,y,Game::_pieceSize,Game::_pieceSize);
			 
		}
	}

} 

//��������
void Layout::SetPieces(POS pos)
{
	// ������� �����ö�Ӧλ�õ�������ɫ
	_layout[pos.row][pos.col]=_player;
	
	// �л����
	_player=(CHESS_PIECE)(3-_player);
	
} 




