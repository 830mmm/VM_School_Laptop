/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 2021314533 최민준
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2020 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
  	//just change the sign bit (MSB) to 0. If number is NaN, return 0th argument of this function.
	unsigned isSpecial;
	isSpecial = 0x7FC00000 & uf;
	if (isSpecial == 0x7FC00000 && (uf & 0x007FFFFF) != 0x0) {
		return uf;
	}
	else return (uf & 0x7FFFFFFF);
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
	// maintain signBit, return argument if NaN/inf
	// return 0 if uf == 0, exp++ if exp != 0, frac * 2 if denormalized
	// perform frac overflow
	int signBit, exp, frac;
	unsigned res;
	signBit = (uf >> 31) & 0x1;
	exp = (uf & 0x7F800000u) >> 23;
	frac = (uf & 0x007FFFFFu);
	
	if (exp == 0xFF) {
		return uf; // when argument is NaN or infinity
	}
	else if ((uf << 1) == 0x0) {
		return uf;
	}
	else if (uf == 0) {
		return 0;
	}
	if(exp != 0x0) exp = (exp + 0x01) & 0xFF; // normal value
	else { frac = (frac << 1) ; } // denormalized value
	if ( frac >> 23 ) {
		exp = (exp + 0x01) & 0xFF;
		frac = frac & 0x7FFFFF;
	}
	res = (signBit << 31) + ((exp << 23) & 0x7FFFFFFF) + frac;
	return res;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
	//Performs arithmatic shift first, and then replace unnecessary '1' bits
	//using appropriately made sequence of bits.
	int cloneN, filter, nFilter;
	filter = (0x7F << 16) + (0xFF << 8) + 0xFF;
	filter = (filter << 8) + 0xFF; // 0x7FFFFFFF
	x = x >> n;
	cloneN = (n << 1) + (~n); // cloneN = cloneN - 1
	filter = filter << !n; // if n == 0, delete MSB(=0) in order not to change the initial value 
	filter = filter >> cloneN;
	x = x & filter;
	return x;
}
/* 
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateLeft(int x, int n) {
	//first copy the n bytes from left of x to rotateBits
	//then perform arithmatic left shift by (32-n).
	//remove unnecessary '1' bits with rotateFilter
	int filter, nSub1, rotateBits, rotateFilter;
	filter = (0x80 << 16) ;
	filter = (filter << 8); //0x80000000
	filter = filter << !n;
	nSub1 = (n << 1) + (~n); // nSub1 = n - 1
	filter = filter >> nSub1;
	rotateBits = x & filter;
	x = x << n;
	rotateBits = rotateBits >> ( (0x01 << 5) + ( ~n + 1 ) );
	rotateFilter = (0x01 << n);
	rotateFilter = (rotateFilter << 1 ) + (~rotateFilter); // rotateFilter -= 1
	rotateBits = rotateFilter & rotateBits;
	x = x | rotateBits;
	return x;
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
	//First perform left shift and only get the corresponding chunk of bits with &operator
	//And then erases that part of bits in x, replace them with the extracted bits using |operator.
	int nMul8 = n << 3;
	int mMul8 = m << 3;
    int a = x & ( 0xFF << nMul8 );
	int b = x & ( 0xFF << mMul8 );
	a = (a >> nMul8) & 0xFF;
	b = (b >> mMul8) & 0xFF;
	x = x & ~( ( 0xFF << nMul8 ) | ( 0xFF << mMul8 ) );
	x = x | (a << mMul8);
	x = x | (b << nMul8);
	return x;
}
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
	//Use property of xor operator!
	int equivBit;
	equivBit = (x & ( (0xFF << 8) + 0xFF ) ) ^ (x >> 16);
	equivBit = (equivBit & 0xFF) ^ (equivBit >> 8);
	equivBit = (equivBit & 0xF) ^ (equivBit >> 4);
	equivBit = (equivBit & 0x3) ^ (equivBit >> 2);
	equivBit = (equivBit & 0x1) ^ (equivBit >> 1);
	return (equivBit & 0x1);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
	//Checks the odd bits if they are 1, twice with filter(practically 0xAAAA)
	//and then checks two things : 
	//(1) if the filtered integers are same (2) if they are the same as 0xAAAA meaning all odd bits are 1
	int isSame, isOdd1, leftX_filtered, rightX_filtered, tempX, filter;
	filter = (0xAA << 8) + 0xAA;
	tempX = x;
	rightX_filtered = tempX	& filter;
	tempX = tempX >> 16;
	leftX_filtered = tempX & filter;
	isSame = leftX_filtered ^ rightX_filtered; // first check if left and right are the same
	isOdd1 = (leftX_filtered ^ filter); //check if it is the case of true 
	return !(isSame + isOdd1);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
	// first calculates y - x in ySubx
	// if x < 0 and y >= 0 then return 1 (meaning trueDueToSign == 1)
	// if x and y have same sign bit, no overflow so if ySubx >= 0, return 1
	// if x >= 0 and y < 0, overflow may happen => if ySubx >= 0, return 0 (isYSignEqualySubx)
	int ySubx, trueDueToSign, isNegative, isPositive,isYSignEqualySubx;
	ySubx = y + (~x + 1); // if this value is nonnegative, should return 1 (unless overflow occurs)
	trueDueToSign = ( x & (~y) ) >> 16;
	trueDueToSign = (trueDueToSign >> 15) & 0x1; // 1 if x < 0 and y >= 0, 0 otherwise
	isNegative = ySubx >> 16;
	isPositive = !(( isNegative >> 15 ) & 0x1);
	isYSignEqualySubx = ( (y >> 16 >> 15) & 0x1 ) & ( isPositive ) & !( (x >> 16 >> 15) & 0x1); // if y<0, x>0 and ySubx = y - x > 0 === overflow (1)
	return (trueDueToSign | ( (isPositive) & (!isYSignEqualySubx)) );
}
/* 
 * rempwr2 - Compute x%(2^n), for 0 <= n <= 30
 *   Negative arguments should yield negative remainders
 *   Examples: rempwr2(15,2) = 3, rempwr2(-35,3) = -3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int rempwr2(int x, int n) {
	//description
	int isNegative, retVal, xDivN, isDivisible;
	isNegative = (x >> 16 >> 15) & 0x1; // 0x1 if Negative, 0x0 if non-negative
	isDivisible = !(x & ( ~((~0x0) << n) ) ); // 1 if divisible, 0 else
	xDivN = x >> n;
	xDivN = xDivN + ( isNegative & !isDivisible & 0x1 ); // add 1 if negative and non-divisible 
	retVal = x + ( ~( ( xDivN ) << n ) + 1 );
	return retVal;
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
	// We can truncate (ignore) the Mantissa while converting.
	// So we return (0x1 * 2^n) + (frac / 2^23 * 2^exp) for normal cases.
	// 
	int retVal, exp;
	if ( (uf & 0x7FFC0000u) == 0x7FFC0000u) {
		return 0x80000000u; // overflow case
	}
	exp = (uf & 0x7F800000u) >> 16 >> 7;
	exp = exp - (0x7F); // subtract bias (127, for single precision)
	if (exp >= 32) {
		return 0x80000000u; // overflow case
	}
	if (exp >= 0) {
		retVal = 0x1 << exp;
		if (exp >= 23) {retVal += (uf & 0x007FFFFF) << (exp - 23);}
		else retVal += (uf & 0x007FFFFF) >> (23 - exp); 
	}
	else {retVal = 0;} // denormalized cases + small normal cases (values below 1)
	if ( (uf >> 16 >> 15) & 0x1 ) {
		retVal = ~retVal + 1; // change the sign if float value is negative
	}
	return retVal;
}
