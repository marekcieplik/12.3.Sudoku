#include <iostream>
#include <fstream>
#include <cstdlib>
int getDigit( char c){
	return (c - '0');
}

bool isDigit( char c){
	if ( 	(c >= '1') 
		&& 	(c <= '9')
		)
		return true;
	else return false;
}

bool getboard(int * tab, std::string fileName){
	std::cout << std::endl << "from function: " << fileName;
	std::string line;
    int number_line=1;

    std::fstream file;
    file.open(fileName, std::ios::in);

    if(file.good()==false) {
    	std::cout<<"Can not open the file!";
    }

	int x = 0, y = 0;
    while (getline(file, line))
    {
         int i = 0;
        while (line[i]){			
			if (isDigit( line[i] ) ) {
				*( tab + x + 9 * y) = getDigit( line[i] );
				x++; 
				if (x==9){
					x = 0;
					y++;
					if (y==9){
						file.close();
						return true;
					}
				}
			}
			i++;
        }
        number_line++;
    }
    file.close();
	return false;
}
