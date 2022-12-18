#ifndef headerfile
#define headerfile
//First Perfect Board 
char RandSymbolAssigner();//Returns Random Symbol
void checker();//Checks Combinations and assign space
void SymbolGeneration_a();//Give Symbol Using RandSymbolAssigner()
void SymbolGeneration_b();//Gives Symbol if Space Found
void CheckedGenerater_a();//Again Checks Space and Assign Symbol
void CheckedGenerater_b();//if Found Symbol Again Run Generator_a()
void FirstBoardGenerator();//Perfect Board Generator
//Board
void board10x10();
//Modes
int EasyMode();//For Easy Mode
int HardMode();//For Easy Mode
//Further Working
void SwapRows(int &scores);//Swapper
void swap_replace(int &moves, int &scores);//Main Game Running and Scoring
void PlayGame();//Option -1
void GameName();
void SelectOption();//Option Selecter at Start
void Credits();
int scoremanager(string name, int score);//Score and Names Storing with Conditions
void HighScores();//Score Display
void Instructions();//
//Easy Mode
//First Perfect Board 
//First Perfect Board 
char RandSymbolAssigner2nd();//Returns Random Symbol
void checker2nd();//Checks Combinations and assign space
void SymbolGeneration_a_2nd();//Give Symbol Using RandSymbolAssigner()
void SymbolGeneration_b_2nd();//Gives Symbol if Space Found
void CheckedGenerater_a_2nd();//Again Checks Space and Assign Symbol
void CheckedGenerater_b_2nd();//if Found Symbol Again Run Generator_a_2nd()
void FirstBoardGenerator2nd();//Perfect Board Generator
//Board
void board8x8();
//Further Working
void SwapRows2nd(int &scores);
void swap_replace2nd(int &moves, int &scores);


#endif // !headerfile
