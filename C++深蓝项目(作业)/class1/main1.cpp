/*

#include <iostream>
#include<graphics.h> 

// run this program using the console pauser or add your own getch, system("pause") or input loop 

int main(int argc, char** argv)
{
	//��ʼ����ͼ���� 
	initgraph(640,480);
	
	getch();
	
	//�رջ�ͼ���� 
	closegraph();
	return 0;
}

*/




#if 1 
#include <iostream>
#include<graphics.h> 

int _gridSize=50;    //���ӵĴ�С
int _gridCount=8;    //���ӵĸ���
int _winWidth=640;   
int _winHeigh=480;


int _xStart=(_winWidth-_gridSize*_gridCount)/2;
int _yStart=(_winHeigh-_gridSize*_gridCount)/2; 

int main()
{
	
	//��ʼ����ͼ���� 
	initgraph(640,480);
	
	//���ñ�����ɫ 
	setbkcolor(EGERGB(255,110,110));
	
	// ����ǰ����ɫ
	setcolor(EGERGB(255,255,255));
	
	setfont(30,0,"���Ĳ���"); 
	
	//�������
	outtextxy(10,10,"����");
	

	
	//����ֱ��
//	line(10,60,300,60); 
	
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
	
	getch();
	
	//�رջ�ͼ���� 
	closegraph();
	
	return 0;
}

#endif


