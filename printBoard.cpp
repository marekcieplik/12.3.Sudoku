#include <iostream>
void printBoard( int * tam){
	std::cout << "\n+";
	for (int t = 0; t < 30; t++){
		if ( (t+1) % 10 == 0 )
			std::cout << "+";
		else
			std::cout << "-";
	}
	std::cout << std::endl;	

	for (int i = 0; i < 9; i++){
		std::cout << "|";
		for (int j = 0; j < 9; j++){
			std::cout << " " << *( tam + j + 9 * i);
			if (*( tam + j + 9 * i) > 0) std::cout << " ";
			if ( ( ( j + 1 ) % 3 == 0) && (( i + 1 ) % 3 == 0)){ std::cout << "|";}
			else if (( j + 1 ) % 3 == 0){std::cout << "|";}
			//else {	std::cout << " ";}
		}
		std::cout << std::endl;
		if ( (i + 1 ) % 3 == 0){
			std::cout << "+";
			for (int t = 0; t < 30; t++){
				if ( (t+1) % 10 == 0 )
					std::cout << "+";
				else
					std::cout << "-";
			}
			std::cout << std::endl;	
		}
	}
}
