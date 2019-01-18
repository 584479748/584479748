#ifndef GAME_H
#define GAME_H

#include"ChessBoard.h"
#include"Layout.h"


/* 
��Ϸ�� 
*/

class Game
{
	public:
		Game();
		~Game();
		
		void Run();   //��Ϸ���� 
	protected:
		ChessBoard _cb; //���̶��� 
		Layout _layout;//���̵Ĳ��ֶ���	
		
	public:	
		static int _gridSize;     //���ӵĴ�С
		static int _gridCount;    //���ӵĸ���
		static int _winWidth;    //���ڵĿ�� 
		static int _winHeigh;    //���ڵĸ߶� 
		static int _pieceSize;  //���Ӵ�С 
		static int _xStart;     //��ʼλ�õ�x���� 
		static int _yStart;    //��ʼλ�õ�y���� 
	protected:
		bool GetMouseHit(POS& pos); //��ȡ���λ��
	 
		
};




#endif
