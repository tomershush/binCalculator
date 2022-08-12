#include "binNum.h"

// Testing main.

int main()
{
	binNum testNum("11001");

	std::cout << "Binary: " << testNum.getBinaryVal() 
		<< " Decimal: " << testNum.convertToDec() 
		<< " Length: " << testNum.getBitLength();

	return 0;
}