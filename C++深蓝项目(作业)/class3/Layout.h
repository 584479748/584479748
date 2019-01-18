#ifndef LAYOUT_H
#define LAYOUT_H

#include<vector> 
using namespace std;


//����ö�٣���ʾ���̸����е�����
typedef enum{CP_NOTHING,CP_BLACK,CP_WHITE}CHESS_PIECE;



//�������λ�õĽṹ��
struct POS
{
	int row;    // ��
	int col;    // �� 
	
	//����������
	bool operator==(const POS& pos)
	{
		return row==pos.row&&col==pos.col;
	}	
};



/*
��Ϸ���岼���� 
*/

class Layout
{
	public:
		Layout();
		~Layout();
		void Draw(); // �������� 
		void SetPieces(POS pos);//�������� 
	protected:
		vector<vector<CHESS_PIECE> > _layout; //������̵ĸ���

		CHESS_PIECE _player; 	//��� 
 
};

#endif


















