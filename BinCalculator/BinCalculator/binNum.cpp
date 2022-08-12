#include "binNum.h"

/*
Constructor of binNum.
Removes the first digit of the binary number
and uses it to determine the value put in the 
negative variable.
*/
binNum::binNum(std::string binaryNum)
{
	binaryVal = binaryNum.substr(1);

	negative = (binaryNum[NEG_BIT_POS] == ONE_BIT);
}

/*
A function that converts the binary number
to a decimal value.
Input: None.
Output: (int) Decimal value of the number.
*/
int binNum::convertToDec() const
{
	int decVal = 0;

	for (int i = 0; i < binaryVal.length(); i++)
	{
		decVal = decVal * POWER_TWO + (binaryVal[i] - ASCII_ZERO);
	}

	if (negative)
		decVal = -(decVal);

	return decVal;
}


// Getters.
int binNum::getBitLength() const
{
	return binaryVal.length();
}

std::string binNum::getBinaryVal() const
{
	return binaryVal;
}
