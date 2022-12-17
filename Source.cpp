#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<stdlib.h>
#include<ctime>
#include<string>
#include<conio.h>
#include<iomanip>
#include"headerfile.hpp"
using namespace std;
int main()
{
	char board[ROW][COL];
	//Coloring
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 1);
	int action=1;
	bool exit=true;
	FirstBoardGenerator(board);
	GameName();
	SelectOption();
	while(action!=0&&action<5)
	{
	cout<<"\nChoose 1-5 to Perform Action : ";
	cin>>action;
		switch(action)
		{
			case 1: PlayGame(board); break;
			case 2: Credits(); break;
			case 3: Instructions(); break;
			case 4: HighScores(); break;
			case 5: exit=false; break;
			default: cout<<"\nInvalid Input!\n";
		}
	}
	cout<<"\nThanks For Playing Game!(^_^)\n"<<endl;
	system("pause");
	return 0;
}
