#include "gmock/gmock.h"

int main(int argc, char** argv) {
   testing::InitGoogleMock(&argc, argv);
   return RUN_ALL_TESTS();
}

/**How launch Google Mock with this files?
Two steeps:
1. build static library gmock-1.7.0 in Dev-C++ 
2. make new project with several options (e.g. see below)

AD 1. e.g.
	 	New Project with name e.g. gmocklib
		Add files 	gmock-1.7.0\src\gmock-all.cc
					gmock-1.7.0\gtest\src\gtest-all.cc
		Project's configuration Alt+P
					General	: Type: Win32 Static Lib
					Files	: gmock-all.cc, gtest-all.cc;
					Compiler: Code Generation: Language standard (-std): GNU C++11
					Parameters: C++ compiler:
						-isystem D:\tools\gmock-1.7.0\gtest\include -ID:\tools\gmock-1.7.0\gtest -isystem D:\tools\gmock-1.7.0\include -ID:\tools\gmock-1.7.0 -pthread 
			
AD 2. e.g.	
	 	New Project with name e.g. Sudoku_Test
		Add files:
					main_Test.cpp 		//with main function (e.g. copy main function with includes from this file)
					sudoku_Test.cpp 	//in which you can write tests. 
										//Don't forget add function declaration which will be tested.
										//e.g. extern bool checkSudoku(int *tab);
					checkFunction.cpp 	//in whitch file contains your function.
		Project's configuration Alt+P
					General	: Type: Win32 Console
					Files	: as above
					Compiler: Code Generation: Language standard (-std): GNU C++11
					Parameters: Linker:
						libGmock/gmocklib.a  //this is static library named as above
					Directories:	Include Directories:
							..\gmock-1.7.0\gtest\include
							..\gmock-1.7.0\include
*/
