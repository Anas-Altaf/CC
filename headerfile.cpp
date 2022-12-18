#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<ctime>
#include<string>
#include<conio.h>
#include<iomanip>
#include<cstring>
#include<fstream>
#include"headerfile.hpp"
using namespace std;
const int ROW = 10, COL = 10;
char board[ROW][COL];
const int KEY_UP = 72;
const int KEY_DOWN = 80;
const int KEY_LEFT = 75;
const int KEY_RIGHT = 77;
void FirstBoardGenerator()
{
	SymbolGeneration();
	checker();
	CheckedGenerater();
}
//First Perfect Board Generation Functions
void SymbolGeneration()
{
	srand(time(0));
	for (int i = 0;i<ROW;i++)
	{
		for (int j = 0;j<COL;j++)
		{
			board[i][j] = RandSymbolAssigner();
		}
	}
}
void board10x10()
{
	system("cls");
	//OUTPUT Console Modification
	static CONSOLE_FONT_INFOEX  fontex;
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	fontex.FontWeight = 1000;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);
	//Coloring
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	//Board Printing
	cout << "Here is the Board : " << endl;
	cout << "    1   2   3   4   5   6   7   8   9   10\n";
	cout << "  .---.---.---.---.---.---.---.---.---.---." << endl;
	cout << "  |   |   |   |   |   |   |   |   |   |   |" << endl;
	for (int i = 0;i<ROW;i++)
	{
		if (i == ROW - 1)
			cout << i + 1 << "| ";
		else
			cout << i + 1 << " | ";
		for (int j = 0;j<COL;j++)
		{
			switch (board[i][j])
			{
			case '#':
				SetConsoleTextAttribute(h, 2);
				break;
			case '@':
				SetConsoleTextAttribute(h, 3);
				break;
			case '$':
				SetConsoleTextAttribute(h, 4);
				break;
			case '%':
				SetConsoleTextAttribute(h, 5);
				break;
			case '+':
				SetConsoleTextAttribute(h, 6);
				break;
			case '&':
				SetConsoleTextAttribute(h, 7);
				break;
			case '=':
				SetConsoleTextAttribute(h, 14);
				break;
			}
			cout << board[i][j] << " | ";
		}
		if (i == ROW - 1)
		{
			cout << endl << "  |...|...|...|...|...|...|...|...|...|...|" << endl;
			cout << "    1   2   3   4   5   6   7   8   9   10\n";
		}
		else
		{
			cout << endl << "  |___|___|___|___|___|___|___|___|___|___|";
			cout << endl << "  |   |   |   |   |   |   |   |   |   |   |" << endl;
		}
	}
}
//Give symbol if find Space ' '.
void SymbolGeneration2()
{
	srand(time(0));
	for (int i = 0;i<ROW;i++)
	{
		for (int j = 0;j<COL;j++)
		{
			{
				if (board[i][j] == ' ')
					board[i][j] = RandSymbolAssigner();
			}
		}
	}
}
//startings Matching Checker
void checker()
{
	for (int i = 0;i<ROW;i++)
	{
		for (int j = 0;j<COL;j++)
		{
			if ((board[j][i] == board[j + 1][i] && board[j][i] == board[j + 2][i]) || (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2]))
			{
				board[j + 2][i] = ' ';
				board[i][j + 2] = ' ';
			}
			if ((board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2]) || (board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2]))
			{
				board[i + 2][j + 2] = ' ';
				board[i + 2][j - 2] = ' ';
			}
		}
	}

}
//Rechacking and Assigning in case of Again Space' '. Making Unique Board
void CheckedGenerater()
{
	for (int i = 0;i<ROW;i++)
	{
		for (int j = 0;j<COL;j++)
		{
			while (board[i][j] == ' ')
			{
				SymbolGeneration2();
				checker();
			}

		}
	}
}
//Last Time Checking For a Unique and Perfect Board
void CheckedGenerater2()
{
	for (int i = 0;i<ROW;i++)
	{
		for (int j = 0;j<COL;j++)
		{
			if (board[i][j] == ' ')
			{
				CheckedGenerater();
			}

		}
	}
}
//Symbol Giving
char RandSymbolAssigner()
{
	int value = rand() % 8;
	switch (value)
	{
	case 0: return '@';
	case 1: return '#';
	case 2: return '$';
	case 3: return '%';
	case 4: return '+';
	case 5: return '&';
	case 6: return '=';
	default:return '+';
	}
}
//Ended First Perfect Board Generator
//Swapping And Replacing Symbols
void swap_replace(int &moves, int &scores)
{
	int row = 0, col = 0;
	board10x10();
	while (moves > 0)
	{
		cout << "         ====" << endl;
		cout << "Scores :| " << scores << " |" << endl;
		cout << "         ====" << endl;
		cout << "         ====" << endl;
		cout << "Moves : | " << moves << " |" << endl;
		cout << "         ====" << endl;
		cout << "\nEnter Row Number = ";cin >> row;
		cout << "\nEnter Column Number = ";cin >> col;
		row = row - 1;
		col = col - 1;
		cout << "Press ENTER to Shuffle >> 1 Move will be Decreased\n                  /\\ ";
		cout << "\nEnter Direction <    > ";
		cout << "\n                  \\/ \n";
		int ch = 0;
		{
			char temp = 0;
			ch = _getch();//First Getting Main Value of Keyboard 224 (it took me 2 days to understand)
			ch = _getch();//Now Getting KeyValue of Keyboard
			switch (ch)
			{
				moves--;
			case KEY_UP:
			{
				if (row != 0)
				{
					swap(board[row][col], board[row - 1][col]);
				}
				else
				{
					cout << "\nNot Possible! Upward Try Again!\n";
				}
			}
			break;
			case KEY_RIGHT:
			{
				if (col != COL - 1)
				{
					swap(board[row][col], board[row][col + 1]);
				}
				else
				{
					cout << "\nNot Possible! Right Side Try Again!\n";
				}
			}
			break;
			case KEY_LEFT:
			{
				if (col != 0)
				{
					swap(board[row][col], board[row][col - 1]);
				}
				else
				{
					cout << "\nNot Possible! Left Side Try Again!\n";
				}
			}
			break;
			case KEY_DOWN:
			{
				if (row != ROW - 1)
				{
					swap(board[row][col], board[row + 1][col]);
				}
				else
				{
					cout << "\nNot Possible! Downward Try Again!\n";
				}
			}
			break;
			case 13:
			{
				if (ch == 13)
				{
					//Perfect Board Generator
					FirstBoardGenerator();
				}
			}
			}
		}
		SwapRows(scores);
		board10x10();
	}
}
void SwapRows(int &scores)
{
	int lastRow = 0;
	bool checker = false, chk1, chk2, chk3, chk4;
	while (checker == false)
	{
		chk1 = chk2 = chk3 = chk4 = false;
		//Value will Swap to down in that Row
		for (int i = 0;i < ROW;i++)
		{
			for (int j = 0;j < COL;j++)
			{
				if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2])
				{
					chk1 = true;
					scores += 10;
					lastRow = i;
					while (lastRow != 0)
					{
						board[lastRow][j] = board[lastRow - 1][j];
						board[lastRow][j + 1] = board[lastRow - 1][j + 1];
						board[lastRow][j + 2] = board[lastRow - 1][j + 2];
						--lastRow;
					}
					board[lastRow][j] = RandSymbolAssigner();
					board[lastRow][j + 1] = RandSymbolAssigner();
					board[lastRow][j + 2] = RandSymbolAssigner();
				}
				else if (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j])
				{
					chk2 = true;
					scores += 10;
					lastRow = i / 3;
					while (lastRow > 0)
					{
						board[i][j] = board[i - 3][j];
						board[i + 1][j] = board[i - 2][j];
						board[i + 2][j] = board[i - 1][j];
						--lastRow;
					}
					board[0][j] = RandSymbolAssigner();
					board[1][j] = RandSymbolAssigner();
					board[2][j] = RandSymbolAssigner();
					if (board[i + 2][j] == board[i + 2][j + 1] && board[i + 2][j] == board[i + 2][j + 2])
					{
						scores += 15;
						lastRow = i + 2;
						while (lastRow != 0)
						{
							board[lastRow][j + 1] = board[lastRow - 1][j + 1];
							board[lastRow][j + 2] = board[lastRow - 1][j + 2];
							--lastRow;
						}
						board[lastRow][j + 1] = RandSymbolAssigner();
						board[lastRow][j + 2] = RandSymbolAssigner();
					}
				}
				else if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2])
				{
					chk3 = true;
					scores += 20;
					lastRow = i;
					while (lastRow != 0)
					{
						board[lastRow][j] = board[lastRow - 1][j];
						--lastRow;
					}
					board[lastRow][j] = RandSymbolAssigner();
					lastRow = i + 1;
					while (lastRow != 0)
					{
						board[lastRow][j + 1] = board[lastRow - 1][j + 1];
						--lastRow;
					}
					board[lastRow][j + 1] = RandSymbolAssigner();
					lastRow = i + 2;
					while (lastRow != 0)
					{
						board[lastRow][j + 2] = board[lastRow - 1][j + 2];
						--lastRow;
					}
					board[lastRow][j + 2] = RandSymbolAssigner();
				}
				else if (board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2])
				{
					chk4 = true;
					scores += 20;
					lastRow = i;
					while (lastRow != 0)
					{
						board[lastRow][j] = board[lastRow - 1][j];
						--lastRow;
					}
					board[lastRow][j] = RandSymbolAssigner();
					lastRow = i + 1;
					while (lastRow != 0)
					{
						board[lastRow][j - 1] = board[lastRow - 1][j - 1];
						--lastRow;
					}
					board[lastRow][j - 1] = RandSymbolAssigner();
					lastRow = i + 2;
					while (lastRow != 0)
					{
						board[lastRow][j - 2] = board[lastRow][j - 2];
						--lastRow;
					}
					board[lastRow][j - 2] = RandSymbolAssigner();
				}
			}
		}
		//Checkers using to run condition checker until Any Combination Possible!
		//it will make SwapRows Function Run and Add Scores until until Any Combination Possible!
		if (chk1 == false && chk2 == false && chk3 == false && chk4 == false)
		{
			checker = false;
		}
		else
		{
			checker = true;
		}
	}
}
//Game Runner and Mode Selection
void PlayGame()
{
	int mode, easyScore, hardScore, score;
	char name[50];
	cout << "\nPlease Enter Your Name (Only First Name) Here = ";
	cin >> name;
	cout << "\nModes\n";
	cout << "1- EASY-MODE ->[ Board = 8x8 - Timer = 60 Seconds - Candies = 5 - Moves = 30 ]\n";
	cout << "2- HARD-MODE ->[ Board = 10x10 - Timer = 40 Seconds - Candies = 7 - Moves = 15 ]\n";
	cout << "Select Mode : ";
	cin >> mode;
	switch (mode)
	{
	case 1:	easyScore = EasyMode();
		break;
	case 2:	hardScore = HardMode();
		break;
	default: cout << "\ninvalid Input!\n";
	}
	if (mode == 1)
	{
		cout << "\nYour Total Scores of EASY-MODE = " << easyScore << endl;
		score = easyScore;
	}
	else if (mode == 2)
	{
		cout << "\nYour Total Scores of HARD-MODE = " << hardScore << endl;
		score = hardScore;
	}
	else
	{
		cout << "Invalid Mode Selection !\n";
	}
	scoremanager(name, score);
}
int HardMode()
{
	cout << "\nHard Mode Started!\n";
	int moves = 15, timer = 60, scores = 0;

	while (moves>0)
	{
		swap_replace(moves, scores); break;
	}
	if (moves == 0)
		cout << "\nNo Moves Left ! ;)\n";
	else
		cout << "\nGame Over! ;)!\n";
	return scores;
}
int EasyMode()
{
	FirstBoardGenerator();
	cout << "\nEasy Mode Started!\n";
	return 0;
}
//Startings Output
void GameName()
{
	cout << "==========" << "   " << " =======" << "   " << "=========" << "    " << "========" << "    " << "=======" << "    " << "=========" << endl;
	cout << "    ||   " << "    " << "||     ||" << "  " << "||       " << "    " << "||       " << "   " << "||      " << "   " << "||       " << endl;
	cout << "    ||   " << "    " << "||     ||" << "  " << "||       " << "    " << "||       " << "   " << "||      " << "   " << "||       " << endl;
	cout << "    ||   " << "    " << "||     ||" << "  " << "||=======" << "    " << "||=======" << "   " << "||===== " << "   " << "||====== " << endl;
	cout << "    ||   " << "    " << "||     ||" << "  " << "||       " << "    " << "||       " << "   " << "||      " << "   " << "||       " << endl;
	cout << "    ||   " << "    " << " ======= " << " " << " ||       " << "    " << "||       " << "   " << "=======" << "    " << "=========" << endl;
	cout << endl << endl;
	cout << setw(20) << setfill(' ') << " ======= " << "  " << " ====== " << "  " << " ======" << "  " << " ======= " << "  " << "||      ==" << "   " << " =======" << "   " << " ====== " << endl;
	cout << setw(20) << setfill(' ') << "||     ||" << "  " << "||    ||" << "  " << "||     " << "  " << "||     ||" << "  " << "||     == " << "   " << "||     " << "   " << "||     ||" << endl;
	cout << setw(20) << setfill(' ') << "||     ||" << "  " << "||    ||" << "  " << "||     " << "  " << "||     ||" << "  " << "||  ==   " << "    " << "||     " << "   " << "||     ||" << endl;
	cout << setw(20) << setfill(' ') << "||=====| " << "  " << "||    ||" << "  " << "|======" << "  " << " |=====|" << "  " << " ||==     " << "    " << "|======" << "   " << "||     ||" << endl;
	cout << setw(20) << setfill(' ') << "||     ||" << "  " << "||====  " << "  " << "||     " << "  " << "||     ||" << "  " << "||  ==    " << "   " << "||     " << "   " << " |====| " << endl;
	cout << setw(20) << setfill(' ') << "||     ||" << "  " << "||   || " << "  " << "||     " << "  " << "||     ||" << "  " << "||    ==  " << "   " << "||     " << "   " << "||    ||" << endl;
	cout << setw(20) << setfill(' ') << " =======" << "  " << "||    ||" << "  " << " ======" << "  " << "||     ||" << "  " << "||      ==" << "   " << " =======" << "  " << "||      ||" << endl << endl;
	cout << "<" << setw(100) << setfill('_') << ">" << endl;
}
void SelectOption()
{
	cout << "\n                                      Welcome to Toffee Breaker Saga!" << endl;
	cout << "                                  Select 1-5 from the Menu!" << endl << endl;
	cout << "                                               1.  Play Game!" << endl;
	cout << "                                               2.  Credits" << endl;
	cout << "                                               3.  Instructions/Rules" << endl;
	cout << "                                               4.  High Scores" << endl;
	cout << "                                               5.  Exit" << endl << endl;
}
void Credits()
{
	cout << "\nThis game was created by two STUDENTDS in the \nlast 2 days. Introducing! \n \tMr Anas Altaf and Mr Muhammad Asjad \n\t 22F-3639 and 22F-3711 \n Thanks For Welcoming!";
}
void Instructions()
{
	cout << "\nThe game is played by swiping the toffees(symbols), in any direction (so long as they are not blocked), to create sets of 3 or more matching candies. You can match candies horizontally, vertically, diagonally or even L Shaped if lucky enough. When matched, the Toffees will break into sugar score and shift the toffees above them, allowing you to accomplish different high sugar goals. Match more than 3 candies to get 25 scores. \nYou get Sugar Scores as mentioned below: \nvertical and horizontal matches : 10 sugar score \nDiagonal matches give you : 20 sugar score \nL-Shaped matches (IF YOU LUCKY GET IT EXACT NUMBER of 5) you get: 25 sugar score";
}
void HighScores()
{
	string output1, output2, output3;
	ofstream fout;
	ifstream fin;
	cout << "\nThe High Scores are :" << endl;
	//1st
	fin.open("score1.txt");
	// Execute a loop until EOF (End of File)
	while (getline(fin, output1))
	{
		cout << output1 << endl;
	}
	fin.close();
	//2nd
	fin.open("score2.txt");
	// Execute a loop until EOF (End of File)
	while (getline(fin, output2))
	{
		cout << output2 << endl;
	}
	fin.close();
	//3rd
	fin.open("score3.txt");
	// Execute a loop until EOF (End of File)
	while (getline(fin, output1))
	{
		cout << output3 << endl;
	}
	fin.close();

}
//Score
void scoremanager(char name[], int score)
{
	int scoremax1 = 0, scoremax2 = 0, scoremax3 = 0;
	string name1, name2, name3;
	ofstream fout;
	ifstream fin;
	if (score>scoremax1)
	{
		scoremax3 = scoremax2;
		scoremax2 = scoremax1;
		scoremax1 = score;
		name3 = name2;
		name2 = name1;
		name1 = name;
		//1st
		fout.open("score1.txt");
		fout << name1 << "\t:\t" << scoremax1 << endl;   //write data to the file
		fout.close();
		//2nd
		fout.open("score2.txt");
		fout << name2 << "\t:\t" << scoremax2 << endl;   //write data to the file
		fout.close();
		//3rd
		fout.open("score3.txt");
		fout << name3 << "\t:\t" << scoremax3 << endl;   //write data to the file
		fout.close();
	}
	else if (score>scoremax2)
	{
		scoremax3 = scoremax2;
		scoremax2 = score;
		name3 = name2;
		name2 = name;
		//2nd
		fout.open("score2.txt");
		fout << name2 << "\t:\t" << scoremax2 << endl;   //write data to the file
		fout.close();
		//3rd
		fout.open("score3.txt");
		fout << name3 << "\t:\t" << scoremax3 << endl;   //write data to the file
		fout.close();
	}
	else if (score>scoremax3)
	{
		scoremax3 = score;
		name3 = name;
		//3rd
		fout.open("score3.txt");
		fout << name3 << "\t:\t" << scoremax3 << endl;   //write data to the file
		fout.close();
	}
}
