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
