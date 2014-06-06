#include <iostream>
#include <cstdio>

using namespace std;
/*checkSudoku - sprawdza, czy tablica 9x9 elementow jest wypelnionym poprawnie diagramem gry Sudoku.
Argumenty 
	int *tab - wskaznik na int
Zwraca
	true - funkcja zwroci true dla poprawnie wype³nionej tablicy
	false- gdy tablica nie spelnia zasad gry Sudoku
*/
bool checkSudoku(int *tab);
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
	{ 4, 6, 7, 1, 1, 5, 9, 2, 8 },
	{ 1, 8, 2, 9, 4, 6, 7, 5, 3 },
	{ 5, 3, 9, 2, 7, 8, 1, 4, 6 },
	{ 6, 5, 3, 4, 8, 7, 2, 9, 1 },
	{ 2, 7, 8, 1, 9, 3, 4, 6, 5 },
	{ 9, 4, 1, 5, 6, 2, 8, 3, 7 },
	{ 7, 9, 6, 8, 5, 4, 3, 1, 2 },
	{ 8, 2, 4, 6, 3, 1, 5, 7, 9 },
	{ 3, 1, 5, 7, 2, 9, 6, 8, 4 }
};

int main()
{
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
bool checkSudoku(int *tab)
{
	bool isCorrect = true; //true: if the numbers are not repeated in any row and column, but also in a small square	
	bool answer[10];//number from sudoku board is an index of answer table
	//chacking rows
	for (int i = 0; i < 9; i++){
		//clear answer table
		for (int z = 1; z < 10; z++) answer[z] = false;
		
		//put true in answer[*(tab+j)]
		for (int j = 0; j < 9; j++){
			if (true == answer[*(tab+j + 9*i)]){
				isCorrect = false;
			}else{
				answer[*(tab+j + 9*i)] = true;
			}			
		}
	}

	//chacking col
	for (int i = 0; i < 9; i++){
		//clear answer table
		for (int z = 1; z < 10; z++) answer[z] = false;
		
		//put true in answer[*(tab+j)]
		for (int j = 0; j < 9; j++){
			if (true == answer[*(tab+9*j + i)]){
				isCorrect = false;
			}else{
				answer[*(tab+9*j + i)] = true;
			}
		}
	}
	
	int x , y ;
	for (x = 0; x < 9 ; x+=3){
		for (y = 0; y < 81; y +=27){
			//clear answer table
			for (int z = 1; z < 10; z++) answer[z] = false;
			
			//check a small square			
			for( int i = 0; i < 3; i ++){
				for ( int j = 0; j < 3; j++){
					if (true == answer[*(tab + 9*i +j + x+y)]){
						isCorrect = false;
					}else{
						answer[*(tab + 9*i +j + x+y)] = true;
					}
				}//j
			}//i
		}
	}
	return isCorrect;
}
