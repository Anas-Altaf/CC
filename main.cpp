//Candy Crush Game with Colors and Symbols
#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<ctime>
#include<string>
#include<iomanip>
#include<fstream>
#include<cstring>
#include"headerfile.hpp"
using namespace std;
int main()
{
	//Coloring
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,31);
	int action=1;
	bool exit=true;
	FirstBoardGenerator();
	GameName();
	SelectOption();
	while(action!=0&&action<5)
	{
	cout<<"\nChoose 1-5 to Perform Action : ";
	cin>>action;
		switch(action)
		{
			case 1: PlayGame(); break;
			case 2: Credits(); break;
			case 3: Instructions(); break;
			case 4: HighScores(); break;
			case 5: exit=false; break;
			default: cout<<"\n\aInvalid Input!\n";
		}
	}
	cout<<"\n\aThanks For Playing Game!(^_^)\a\n"<<endl;
	system("pause");
	return 0;
}
