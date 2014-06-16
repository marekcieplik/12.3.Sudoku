#include <iostream>
#include <stddef.h>
#include <cstdio>
#include <fstream>

using namespace std;
//TODO Add opportunity sending to program own game boards of sudoku.

/*checkSudoku - sprawdza, czy tablica 9x9 elementow jest wypelnionym poprawnie diagramem gry Sudoku.
Argumenty 
	int *tab - wskaznik na int
Zwraca
	true - funkcja zwroci true dla poprawnie wype³nionej tablicy
	false- gdy tablica nie spelnia zasad gry Sudoku
*/
extern bool checkSudoku(int *tab);

/*tablica do testow, prawidlowo wypelniona*/
static int sudokuCorrect[9][9] =
{
	{ 4, 6, 7, 3, 1, 5, 9, 2, 8 },
	{ 1, 8, 2, 9, 4, 6, 7, 5, 3 },
	{ 5, 3, 9, 2, 7, 8, 1, 4, 6 },
	{ 6, 5, 3, 4, 8, 7, 2, 9, 1 },
	{ 2, 7, 8, 1, 9, 3, 4, 6, 5 },
	{ 9, 4, 1, 5, 6, 2, 8, 3, 7 },
	{ 7, 9, 6, 8, 5, 4, 3, 1, 2 },
	{ 8, 2, 4, 6, 3, 1, 5, 7, 9 },
	{ 3, 1, 5, 7, 2, 9, 6, 8, 4 }
};

static int sudokuNotCorrect14[9][9] = //element rzad 1, kolumna 4 nie pasuje
{
	{ 4, 6, 7, -1, 1, 5, 9, 2, 8 },
	{ 1, 8, 2, 9, 4, 6, 7, 5, 3 },
	{ 5, 3, 9, 2, 7, 8, 1, 4, 6 },
	{ 6, 5, 3, 4, 8, 7, 2, 9, 1 },
	{ 2, 7, 8, 1, 9, 3, 4, 6, 5 },
	{ 9, 4, 1, 5, 6, 2, 8, 3, 7 },
	{ 7, 9, 6, 8, 5, 4, 3, 1, 2 },
	{ 8, 2, 4, 6, 3, 1, 5, 7, 9 },
	{ 3, 1, 5, 7, 2, 9, 6, 8, 4 }
};

int main(int argc, char * argv[])
{
	if (argc > 1){
		cout << endl << "loading sudoku boards from file " << argv[1] << std::endl;
	}else{
		cout << endl << "built-in boards" << std::endl;
	}
	
	cout << endl << "test Correct ";

	int *pSudoku = &sudokuCorrect[0][0];
	
	if (checkSudoku(pSudoku) == true)
	{
		cout << "OK";// Test passed
	}
	else
	{
		cout << "NOK";
	}

	cout << endl << "test 14 ";

	pSudoku = &sudokuNotCorrect14[0][0];

	if (checkSudoku(pSudoku) == false)
	{
		cout << "OK";// Test passed
	}
	else
	{
		cout << "NOK";
	}
	std::cout << std::endl << std::endl << "Press enter to exit...";
	getchar();
	return 0;
}

