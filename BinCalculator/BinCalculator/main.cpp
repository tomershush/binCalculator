#include "binNum.h"

// Testing main.

int main()
{
	binNum testNum("011");
	binNum testNum2("001");
	

	std::cout << "Binary: " << testNum2.getBinaryVal() 
		<< " Decimal: " << testNum2.convertToDec() 
		<< " Length: " << testNum2.getBitLength()
		<< " Addition: " << (testNum + testNum2).getBinaryVal();

	//printf("\nTestNum addr: %p TestNum2 addr: %p", &testNum, &testNum2);

	return 0;
}