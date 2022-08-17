#include "binNum.h"

/*
* Constructor of binNum.
* Removes the first digit of the binary number
* and uses it to determine the value put in the 
* negative variable.
*/
binNum::binNum(std::string binaryNum)
{
	binaryVal = binaryNum.substr(1);

	negative = (binaryNum[NEG_BIT_POS] == ONE_BIT);
}

/*
* A function that converts the binary number
* to a decimal value.
* Input: None.
* Output: (int) Decimal value of the number.
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

/*
* Overloaded = operator, allows for deep copying 
* of another instance of the binNum class.
*/
binNum& binNum::operator=(const binNum& otherBin)
{
	this->binaryVal = otherBin.binaryVal;
	this->negative = otherBin.negative;

	return *this;
}

/*
* Overloaded = operator, allows changing an existing
* binNum instance based on a string representing a
* binary value.
*/
binNum& binNum::operator=(const std::string binValue)
{
	binNum temp(binValue);

	this->binaryVal = temp.binaryVal;
	this->negative = temp.negative;

	return *this;
}

/*
* Overloaded + operator to allow addition of binary numbers.
* Performs addition between 2 instances of the binNum class.
*/
binNum& binNum::operator+(const binNum& otherBin)
{
	int bitSum, shortIndex, longIndex = 0;
	int carry = 0;
	std::string newVal, longerNum, shorterNum;
	
	// First, determining which number is longer.
	if (this->getBitLength() > otherBin.getBitLength())
	{
		longerNum = this->getBinaryVal();
		shorterNum = otherBin.getBinaryVal();
	}
	else
	{
		longerNum = otherBin.getBinaryVal();
		shorterNum = this->getBinaryVal();
	}

	for (int i = 0; i < shorterNum.length(); i++)	// Looping through the bits of each number.
	{
		// Calculating the final bit index (Little endian) of each number.
		longIndex = longerNum.length() - i - 1;
		shortIndex = shorterNum.length() - i - 1;
		
		// Calculating the sum of the 2 current bits from the numbers with
		// the added carry (Overflow from previous operation).
		bitSum = longerNum[longIndex] + shorterNum[shortIndex] - ASCII_ZERO * 2 + carry;

		switch (bitSum)	// Checking the sum and adjusting the bits accordingly.
		{
		case 1:
			longerNum[longIndex] = ONE_BIT;
			carry = 0;
			break;

		case 2:
			longerNum[longIndex] = ZERO_BIT;
			carry = 1;
			break;

		case 3:
			longerNum[longIndex] = ONE_BIT;
			carry = 1;
			break;

		default:
			break;
		}
	}

	
	// Determine if the numbers are same length.

	if (longerNum.length() == shorterNum.length())
	{
		longIndex = 0;
		longerNum = ZERO_BIT + longerNum;	// Adding padding in case the length is equal (Allowing to add the big endian in case of overflow).
	}
	else
		// If the length is not equal, adding the overflow to the least signifacnt bit that was not affected by the operation.
		longIndex = longerNum.length() - shorterNum.length() - 1;

	// In case of overflow from the operation, add it to the longer number.
	if (carry)
	{
		bitSum = longerNum[longIndex] - ASCII_ZERO + carry;	

		
		if (bitSum == carry)
			longerNum[longIndex] = ONE_BIT;
		else
		{
			longerNum[longIndex] = ZERO_BIT;
			longerNum = ONE_BIT + longerNum;
		}
	}
		
	// Add padding (Causes the number to be positive, first bit is used to determine negativity).
	*this = '0' + longerNum;

	return *this;

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
