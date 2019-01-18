#include "Layout.h"

#include "Game.h"
#include <graphics.h>

Layout::Layout()
{
	//�����������ڴ�
	_layout.resize(Game::_gridCount); 
	
	for(int i = 0;i<Game::_gridCount;++i)
	{
		_layout[i].resize(Game::_gridCount); 
	}
	
	//��ʼ�����̸��ӵ����� 
	for(int i = 0;i<Game::_gridCount;++i)
	{
		for(int j = 0;j<Game::_gridCount;++j)
		{
			_layout[i][j] = CP_NOTHING;
		}
	}
	
	//���ö�Ӧ��λ��Ϊ����
	_layout[3][3] = _layout[4][4] = CP_WHITE;
	
	//���ö�Ӧ��λ��Ϊ����
	_layout[3][4] = _layout[4][3] = CP_BLACK;
	
	//�������
	_player = CP_BLACK; 
	
	GetAllMaybePos();
}


Layout::~Layout()
{
}

//�������� 
void Layout::Draw()
{
	
	int x,y;
	
	for(int i = 0;i<Game::_gridCount;++i)
	{
		for(int j = 0;j<Game::_gridCount;++j)
		{
			//����Ǻ��� 
			if(_layout[i][j] == CP_BLACK) 
			{
				//�������ɫΪ��ɫ 
				setfillcolor(EGERGB(0,0,0));
			}
			else if(_layout[i][j] == CP_WHITE)
			{//����ǰ��� 
				//�������ɫΪ��ɫ 
				setfillcolor(EGERGB(255,255,255));
			} 
			else
			{
				continue;
			}
			
			//Բ�ĵ�����
			x = Game::_xStart + j * Game::_gridSize + Game::_gridSize/2; 
			y = Game::_yStart + i * Game::_gridSize + Game::_gridSize/2; 
			
			//��������
			fillellipse(x,y,Game::_pieceSize,Game::_pieceSize); 
		}
	}
	
	setfillcolor(EGERGB(255, 255, 0));
	for (int i = 0; i<_allMaybePos.size(); ++i)
	{
		//����Բ�ĵ�λ�� 
		y = Game::_yStart + _allMaybePos[i].row * Game::_gridSize + Game::_gridSize / 2;
		x = Game::_xStart + _allMaybePos[i].col * Game::_gridSize + Game::_gridSize / 2;

		//�������п������ӵ�λ��
		fillellipse(x, y, 5, 5);
	}


}

//��������
void Layout::SetPieces(POS pos)
{
	//������ң����ö�Ӧλ�õ�������ɫ
	_layout[pos.row][pos.col] = _player; 
	
	//�л����
	_player = (CHESS_PIECE)(3 - _player);
	
}

/*
�ж϶�Ӧ��λ���Ƿ������� (���ӻ����)
*/
bool Layout::IsHasPieces(POS pos)
{
	return _layout[pos.row][pos.col] == CP_NOTHING ? false : true;
}

/*
�ж�λ���Ƿ�Ϸ�
*/
bool Layout::IsLegalPos(POS pos)
{
	if (pos.row >= 0 && pos.row < Game::_gridCount &&
		pos.col >= 0 && pos.col < Game::_gridCount)
	{
		return true;
	}
	else
	{
		return false;
	}
}





/*
�����������ж�������posλ���Ƿ���һ��������λ��
������	��IsMaybePos
����	��pos�����жϵ�λ��
���	��bret��Ϊ��posλ�ÿ����ӣ�Ϊ��posλ�ò�������
�ⲿ���ݣ�_layout, _player
�ⲿ������
����	����һ��
ʱ��	��2017-12-26
�汾	��ver 0.1
-----------
�޸�	��
�汾	��
*/
bool Layout::IsMaybePos(POS pos)
{
	bool bret = false;
	POS nextPos;

	for (int row = -1; row <= 1; ++row)
	{
		for (int col = -1; col <= 1; ++col)
		{
			//�������Լ���λ�� 
			if (row == 0 && col == 0)
			{
				continue;
			}

			//������һ���жϵ�λ�� ��8�������е�һ���� 
			nextPos.row = pos.row + row;
			nextPos.col = pos.col + col;

			//���λ�úϷ������Ҳ����жԷ������� 
			if (IsLegalPos(nextPos) && _layout[nextPos.row][nextPos.col] == (CHESS_PIECE)(3 - _player))
			{
				for (nextPos.row += row, nextPos.col += col;
					IsLegalPos(nextPos);
					nextPos.row += row, nextPos.col += col)
				{
					//����ǶԷ������ӣ������ 
					if (_layout[nextPos.row][nextPos.col] ==
						(CHESS_PIECE)(3 - _player))
					{
						continue;
					}
					else if (_layout[nextPos.row][nextPos.col] == _player)
					{//����Ǽ����������򷵻� 
					
					
						return true;
					}
					else
					{//��������������ѭ�� 
						break;
					}
				}
			}

		}
	}
	return false;
}



/*
��ȡ���п������ӵ�λ��
*/
void Layout::GetAllMaybePos()
{
	//������� 
	_allMaybePos.clear();

	POS pos;

	for (pos.row = 0; pos.row < Game::_gridCount; ++pos.row)
	{
		for (pos.col = 0; pos.col < Game::_gridCount; ++pos.col)
		{
			if (!IsHasPieces(pos) && IsMaybePos(pos))
			{
				//�������� 
				_allMaybePos.push_back(pos);
			}
		}
	}

}


