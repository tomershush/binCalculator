#pragma once
#include <iostream>

#define NEG_BIT_POS 0
#define ZERO_BIT '0'
#define ONE_BIT '1'
#define POWER_TWO 2

#define ASCII_ZERO '0'

/*
A class representing a binary number.
First digit is removed and used to determine 
whether the number is negative or positive
using the negative variable.

List of operations:
1) Conversion to decimal number.
*/

class binNum
{
private:
	std::string binaryVal;
	bool negative;	// Acts as one's complement.

public:
	binNum(std::string binaryNum);
	int convertToDec() const;

	// Getters.
	int getBitLength() const;
	std::string getBinaryVal() const;
};

