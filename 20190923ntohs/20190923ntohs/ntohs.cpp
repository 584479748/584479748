#include<stdio.h>
#include<tchar.h>
#include<iomanip>
#include<iostream>

using namespace std;

//#pragma comment(lib,"ws2_32.lib")//�˵���-->Project-->Settings-->Link��ǩҳ-->Object/library modules-->����ws2_32.lib
#include "winsock2.h"
//#pragma comment(lib,"ws2_32.lib")

int main(int argc, char* argv[])
{
	int iNumh = 0x12345678;
	int iNums = ntohs(iNumh);
	cout << "iNumh=" << iNumh << endl;
	cout << "iNumh=" << iNumh << endl;
	cout << "iNumh=" << hex << iNumh << "and iNumh's addr=" << &iNumh << endl;
	cout << "iNumh=" << hex << iNumh << "and iNumh's addr=" << &iNumh << endl;
	system("pause");

	return 0;
}