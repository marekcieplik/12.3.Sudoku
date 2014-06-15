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
bool checkSudoku(int *tab){

		
	bool isCorrectFillIn = true; 	//true: if the numbers are not repeated in any row and column, but also in a small square	
	
	for (int i = 0; i < 9; i++){	//check range elements of table
		for (int j = 0; j < 9; j++){
			if (	( 1 > *(tab+j + 9*i) ) 
			   ||	( 9 < *(tab+j + 9*i) )
			   ||	(nullptr == tab) 
			//   ||	(null == *(tab+j + 9*i) )
				)
			{
				return isCorrectFillIn = false;				 
			}	
		}
	}
	
	bool answer[10] = {false};			//number from sudoku board will be an index of answer table
	
	for (int i = 0; i < 9; i++){		//checking rows		
		for (int z = 1; z < 10; z++){	//clear answer table
			answer[z] = false;
		}				
		for (int j = 0; j < 9; j++){	//put true in answer[*(tab+j)]
			answer[*(tab+j + 9*i)] = true;
		}
		for (int z = 1; z < 10; z++){	//checking if is any false in
			if (false == answer[z]){
				return isCorrectFillIn = false;
			}	
		}
	}
	for (int i = 0; i < 9; i++){		//checking col
		for (int z = 1; z < 10; z++){	//clear answer table
			answer[z] = false;
		}
		for (int j = 0; j < 9; j++){		//put true in answer[*(tab+j)]. after these loop in answer table should has only true value
			answer[*(tab+9*j + i)] = true;	//e.g. for *(tab+9*j + i)==4, in answe[4] set true;
		}
		for (int z = 1; z < 10; z++){		//checking if is any false in
			if (false == answer[z]){
				return isCorrectFillIn = false;
			}
		}
	}
	
	int x , y ; 						//coordinates of first element of small squares in sudoku are:
	for (x = 0; x < 9 ; x+=3){			//x = 0,  3,  6; y = 0, 27, 54;
		for (y = 0; y < 81; y +=27){	//x+y =  0, 27, 54,  3, 30, 57,   6,  33,  60
			for (int z = 1; z < 10; z++){		//clear answer table
				answer[z] = false;
			}
			//check a small square
			for( int i = 0; i < 3; i ++){		
				for ( int j = 0; j < 3; j++){
					answer[*(tab + 9*i +j + x+y)] = true;
				} //j					
			}	//i
			//checking if is any false in
			for (int z = 1; z < 10; z++){		
				if (false == answer[z]){
					return isCorrectFillIn = false;
				}
			}
		}// y
	}// x
	return isCorrectFillIn;
}//checkSudoku

/*tablica do testow, prawidlowo wypelniona*/
static int sudokuCorrect[9][9] =
{
	{ 0, 6, 7, 3, 1, 5, 9, 2, 8 },
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

