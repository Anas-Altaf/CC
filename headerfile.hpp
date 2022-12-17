#ifndef headerfile
#define headerfile
//Main Array
const int ROW = 10, COL = 10;
//First Perfect Board 
void FirstBoardGenerator(char board[][COL]);
char RandSymbolAssigner();
void SymbolGeneration(char board[][COL]);
void checker(char board[][COL]);
void SymbolGeneration2(char board[][COL]);
void CheckedGenerater(char board[][COL]);
//Board
void board10x10(char board[][COL]);
//Modes
int EasyMode(char board[][COL]);
int HardMode(char board[][COL]);
//Further Working
void swapper(int row, int col, char board[][COL]);
void GameName();
void SelectOption();
void Credits();
void HighScores();
void Instructions();
void swap_replace(int &moves, int &scores, char board[][COL]);
void Instructions();
void PlayGame(char board[][COL]);
#endif // !headerfile
