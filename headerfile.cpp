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
const int KEY_UP = 72;
const int KEY_DOWN = 80;
const int KEY_LEFT = 75;
const int KEY_RIGHT = 77;
void FirstBoardGenerator(char board[][COL])
{
	SymbolGeneration(board);
	checker(board);
	CheckedGenerater(board);
}
//First Perfect Board Generation Functions
void SymbolGeneration(char board[][COL])
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
void board10x10(char board[][COL])
{
	system("cls");
	static CONSOLE_FONT_INFOEX  fontex;
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	fontex.FontWeight = 700;
	fontex.dwFontSize.X = 20;
	fontex.dwFontSize.Y = 20;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
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
			cout << endl << "  |...|...|...|...|...|...|...|...|...|...|" << endl;
		else
		{
			cout << endl << "  |___|___|___|___|___|___|___|___|___|___|";
			cout << endl << "  |   |   |   |   |   |   |   |   |   |   |" << endl;
		}
	}
}
void SymbolGeneration2(char board[][COL])
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
void checker(char board[][COL])
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
void CheckedGenerater(char board[][COL])
{
	for (int i = 0;i<ROW;i++)
	{
		for (int j = 0;j<COL;j++)
		{
			while (board[i][j] == ' ')
			{
				SymbolGeneration2(board);
				checker(board);
			}

		}
	}
}
void CheckedGenerater2(char board[][COL])
{
	for (int i = 0;i<ROW;i++)
	{
		for (int j = 0;j<COL;j++)
		{
			if (board[i][j] == ' ')
			{
				CheckedGenerater(board);
			}

		}
	}
}
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
void swap_replace(int &moves, int &scores, char board[][COL])
{
	int row, col;
	bool swapdone = true;
	while (moves > 0)
	{
		board10x10(board);
		cout << "\nEnter Row Number = ";cin >> row;
		cout << "\nEnter Column Number = ";cin >> col;
		row = row - 1;
		col = col - 1;
		swapper(row,col,board);
		board10x10(board);
		--moves;
		int lastRow = 0;
		for (int i = 0;i < ROW;i++)
		{
			for (int j = 0;j < COL;j++)
			{
				if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2])
				{
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
					scores += 20;
					lastRow = i;
					while (lastRow != 0)
					{
						board[lastRow][j] = board[lastRow-1][j];
						--lastRow;
					}
					board[lastRow][j] = RandSymbolAssigner();
					lastRow = i + 1;
					while (lastRow != 0)
					{
						board[lastRow][j + 1] = board[lastRow-1][j + 1];
						--lastRow;
					}
					board[lastRow][j + 1] = RandSymbolAssigner();
					lastRow = i + 2;
					while (lastRow != 0)
					{
						board[lastRow][j + 2] = board[lastRow-1][j + 2];
						--lastRow;
					}
					board[lastRow][j + 2] = RandSymbolAssigner();
				}
				else if (board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2])
				{
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
						board[lastRow][j - 1] = board[lastRow-1][j - 1];
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
	}
}
//Game Runner
void PlayGame(char board[][COL])
{
	int mode, easyScore, hardScore;
	string name;
	cout << "\nPlease Enter Your First Name Here = ";
	cin >> name;
	cout << "\nModes\n";
	cout << "1- EASY-MODE ->[ Board = 8x8 - Timer = 60 Seconds - Candies = 5 - Moves = 30 ]\n";
	cout << "2- HARD-MODE ->[ Board = 10x10 - Timer = 40 Seconds - Candies = 7 - Moves = 15 ]\n";
	cout << "Select Mode : ";
	cin >> mode;
	switch (mode)
	{
	case 1:	easyScore = EasyMode(board);
		break;
	case 2:	hardScore = HardMode(board);
		break;
	default: cout << "\ninvalid Input!\n";
	}
	if (mode == 1)
		cout << "\nYour Total Scores of EASY-MODE = " << easyScore << endl;
	else if (mode == 2)
		cout << "\nYour Total Scores of HARD-MODE = " << hardScore << endl;
	else
	{
		cout << "Invalid Mode Selection !\n";
	}
}
void swapper(int row,int col,char board[][COL])
{
	int keyinput=0;
	cout << "\n                  /\\ ";
	cout << "\nEnter Direction <    > ";
	cout << "\n                  \\/ " << endl;
	switch (keyinput = getch())
	{
	case KEY_UP:
	{
		cout << "KEY_UP";
		if (row != 0)
		{
			if ((board[row][col] == board[row - 1][col + 1] && board[row][col] == board[row - 1][col + 2]) || (board[row][col] == board[row - 1][col + 1] && board[row][col] == board[row - 1][col - 1]) || (board[row][col] == board[row - 1][col - 1] && board[row][col] == board[row - 1][col - 2]) || (board[row][col] == board[row - 2][col] && board[row][col] == board[row - 3][col]))
			{
				char temp = board[row][col];
				board[row][col] = board[row - 1][col];
				board[row - 1][col] = temp;
			}
			else if ((board[row - 1][col] == board[row][col + 1] && board[row - 1][col] == board[row][col + 2]) || (board[row - 1][col] == board[row][col - 1] && board[row - 1][col] == board[row][col - 2]) || (board[row - 1][col] == board[row + 1][col] && board[row - 1][col] == board[row + 2][col]) || (board[row - 1][col] == board[row][col - 1] && board[row - 1][col] == board[row][col + 1]))
			{
				char temp = board[row][col];
				board[row][col] = board[row - 1][col];
				board[row - 1][col] = temp;
			}
			else
			{
				char temp = board[row][col];
				board[row][col] = board[row - 1][col];
				board[row - 1][col] = temp;
			}
		}
		else
		{
			cout << "\nNot Possible! Try Again!\n";
		}
	}
	break;
	case KEY_RIGHT:
	{
		cout << "KEY_RIGHT";
		if (col != COL - 1)
		{
			if ((board[row][col] == board[row - 1][col + 1] && board[row][col] == board[row - 2][col + 1]) || (board[row][col] == board[row][col + 2] && board[row][col] == board[row][col + 3]) || (board[row][col] == board[row + 1][col + 1] && board[row][col] == board[row + 2][col + 1]) || (board[row][col] == board[row - 1][col + 1] && board[row][col] == board[row + 1][col + 1]))
			{
				char temp = board[row][col];
				board[row][col] = board[row][col + 1];
				board[row][col + 1] = temp;
			}
			else if ((board[row][col + 1] == board[row][col - 1] && board[row][col + 1] == board[row][col - 2]) || (board[row][col + 1] == board[row - 1][col] && board[row][col + 1] == board[row - 2][col]) || (board[row][col + 1] == board[row + 1][col] && board[row][col + 1] == board[row + 2][col]) || (board[row][col + 1] == board[row][col] && board[row][col + 1] == board[row][col + 2]))
			{
				char temp = board[row][col];
				board[row][col] = board[row][col + 1];
				board[row][col + 1] = temp;
			}
			else
			{
				char temp = board[row][col];
				board[row][col] = board[row][col + 1];
				board[row][col + 1] = temp;
			}
		}
		else
		{
			cout << "\nNot Possible! Try Again!\n";
		}
	}
	break;
	case KEY_LEFT:
	{
		cout << "KEY_LEFT";
		if (col != 0)
		{
			if ((board[row][col] == board[row][col - 2] && board[row][col] == board[row][col - 3]) || (board[row][col] == board[row + 1][col - 1] && board[row][col] == board[row + 2][col - 1]) || (board[row][col] == board[row - 1][col - 1] && board[row][col] == board[row - 2][col - 1]) || (board[row][col] == board[row - 1][col - 1] && board[row][col] == board[row + 1][col - 1]))
			{
				char temp = board[row][col];
				board[row][col] = board[row][col - 1];
				board[row][col - 1] = temp;
			}
			else if ((board[row][col - 1] == board[row][col + 1] && board[row][col - 1] == board[row][col + 2]) || (board[row][col - 1] == board[row - 1][col] && board[row][col - 1] == board[row - 2][col]) || (board[row][col - 1] == board[row + 1][col] && board[row][col - 1] == board[row + 2][col]) || (board[row][col - 1] == board[row][col] && board[row][col - 1] == board[row][col + 1]))
			{
				char temp = board[row][col];
				board[row][col] = board[row][col - 1];
				board[row][col - 1] = temp;
			}
			else
			{
				char temp = board[row][col];
				board[row][col] = board[row][col - 1];
				board[row][col - 1] = temp;
			}
		}
		else
		{
			cout << "\nNot Possible! Try Again!\n";
		}
	}
	break;
	case KEY_DOWN:
	{
		cout << "KEY_DOWN";
		if (row != ROW - 1)
		{
			if ((board[row][col] == board[row + 2][col] && board[row][col] == board[row + 3][col]) || (board[row][col] == board[row + 1][col + 1] && board[row][col] == board[row + 1][col + 2]) || (board[row][col] == board[row + 1][col - 1] && board[row][col] == board[row + 1][col - 2]) || (board[row][col] == board[row + 1][col + 1] && board[row][col] == board[row + 1][col - 1]))
			{
				char temp = board[row][col];
				board[row][col] = board[row - 1][col];
				board[row - 1][col] = temp;
			}
			else if ((board[row + 1][col] == board[row - 1][col] && board[row + 1][col] == board[row - 2][col]) || (board[row + 1][col] == board[row][col - 1] && board[row + 1][col] == board[row][col - 2]) || (board[row + 1][col] == board[row][col + 1] && board[row + 1][col] == board[row][col + 2]) || (board[row + 1][col] == board[row][col - 1] && board[row + 1][col] == board[row][col + 1]))
			{
				char temp = board[row][col];
				board[row][col] = board[row - 1][col];
				board[row - 1][col] = temp;
			}
			else
			{
				char temp = board[row][col];
				board[row][col] = board[row - 1][col];
				board[row - 1][col] = temp;
			}
		}
		else
		{
			cout << "\nNot Possible! Try Again!\n";
		}
	}
	break;
	}
	keyinput = 0;
}
int HardMode(char board[][COL])
{
	cout << "\nHard Mode Started!\n";
	int moves = 15, timer = 60, scores = 0;
	
	while (moves>0)
	{
		cout << "         ====" << endl;
		cout << "Scores :| " << scores << " |" << endl;
		cout << "         ====" << endl;
		cout << "         ====" << endl;
		cout << "Moves : | " << moves << " |" << endl;
		cout << "         ====" << endl;
		swap_replace(moves, scores, board); break;
	}
	if (moves == 0)
		cout << "\nNo Moves Left ! ;)\n";
	else
		cout << "\nGame Over! ;)!\n";
	return scores;
}
int EasyMode(char board[][COL])
{
	FirstBoardGenerator(board);
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
	cout << "\nThe High Scores are as Under: 450 " << endl;

}
