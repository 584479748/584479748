
// ��Ϸ���װ
// ��Ϸ��Game  :  Run()
// ����������ChessBoard   ��Draw() 




#if 1 
#include <iostream>
#include<graphics.h> 

#include<vector> 
using namespace std;

int _gridSize=50;    //���ӵĴ�С
int _gridCount=8;    //���ӵĸ���
int _winWidth=640;   //���ڵĿ�� 
int _winHeigh=480;   //���ڵĸ߶� 
int _pieceSize=_gridSize/2-2;   //���Ӵ�С 

//��ʼλ�õ�x���� 
int _xStart=(_winWidth-_gridSize*_gridCount)/2;

//��ʼλ�õ�y���� 
int _yStart=(_winHeigh-_gridSize*_gridCount)/2; 

//����ö�٣���ʾ���̸����е�����
typedef enum{CP_NOTHING,CP_BLACK,CP_WHITE}CHESS_PIECE;

//������̵ĸ���
vector<vector<CHESS_PIECE> > _layout;

//��� 
CHESS_PIECE _player; 


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


//���̲���
void Layout(); 

//�������� 
void DrawChessBoard();

//��������
void Draw(); 

//������Ϸ 
void Run();

//��ȡ���λ��
bool GetMouseHit(POS& pos); 

//�������� 
void SetPieces(POS pos);


int main()
{
	//��ʼ����ͼ���� 
	initgraph(640,480);
	
	//���ñ�����ɫ 
	setbkcolor(EGERGB(255,110,110));
	
	//�������ɫ 
//	setfillcolor(EGERGB(255,255,255)); 
	
	//�����Բ
//	fillellipse(50,50,25,25); 
	
	//����ǰ����ɫ
//	setcolor(EGERGB(255,255,255));

	//����ֱ��
//	line(10,60,300,60); 

	//�������� 
//	setfont(30,0,"���Ĳ���"); 
	
	//�������
//	outtextxy(10,10,"����");
	
	
	//���̲��� 
	Layout();
	
	//��������
	DrawChessBoard(); 
	
	//�������� 
	Draw();
	
	//����
	Run(); 
	
	getch();
	
	//�رջ�ͼ���� 
	closegraph();
	
	return 0;
}


//��ȡ���λ��
bool GetMouseHit(POS& pos)
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


//������Ϸ 
void Run()
{
	POS pos;
	
	for(;is_run();delay_fps(100))
	{
		//��ȡ���λ��
		while(!GetMouseHit(pos));
		
		
		
		//�������� 
		SetPieces(pos);
		

		//��������
		DrawChessBoard(); 
		
		
		//�������� 
		Draw();
		
	
		delay_fps(100);
	}
}


//��������
void SetPieces(POS pos)
{
	// ������� �����ö�Ӧλ�õ�������ɫ
	_layout[pos.row][pos.col]=_player;
	
	// �л����
	_player=(CHESS_PIECE)(3-_player);
	
 } 


//��������
void Draw()
{
	for(int i=0;i<_gridCount;++i)
	{
		for(int j=0;j<_gridCount;++j)
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
			int x=_xStart+j*_gridSize+ _gridSize/2;
			int y=_yStart+i*_gridSize+ _gridSize/2;
			
			//��������
			fillellipse(x,y,_pieceSize,_pieceSize);
			 
		}
	}
} 


//�������� 
void DrawChessBoard()
{
	//��ջ�ͼ�豸
	cleardevice(); 
	
	int x1,x2,y1,y2;
	
	//����ˮƽ��
	for(int i=0;i<=_gridCount;++i)
	{
		x1=_xStart;
		x2=_winWidth-x1;
		
		y1=y2=_yStart+_gridSize*i;
		
		line(x1,y1,x2,y2);
	} 
	
	int x3,x4,y3,y4;
	
	//���ƴ�ֱ��
	for(int j=0;j<=_gridCount;++j)
	{
		y3=_yStart;
		y4=_winHeigh-y3;
		
		x3=x4=_xStart+_gridSize*j;
		
		line(x3,y3,x4,y4);
	} 
 }


//���̲���
void Layout()
{
	//�����������ڴ�
	_layout.resize(_gridCount);
	
	for(int i=0;i<_gridCount;++i)
	{
		_layout[i].resize(_gridCount);
	}
	
	//��ʼ�����̸��ӵ����� 
	for(int i=0;i<_gridCount;++i)
	{
		for(int j=0;j<_gridCount;++j)
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

#endif


