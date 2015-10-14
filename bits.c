// Data Lab


/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
    
    //Create a bit counter and a integer that tests for an x of 0.
    //Create an int that is either all 1's or 0's based on signed bit.
    //Use that mask to switch bits of x or not depending on signed bit.
    //Test smaller and smaller bit ranges until a bit with the number 1
    //is reached. At this point add the bit spot to mainCounter. Once all
    //bits are counted, shift x by mainCounter plus the extra one bits spot
    //and have a final count. Use a to test if x is all zeros and then finally,
    //add mainCounter, not a and 3 to get the total amount of bits needed.
    int a;
    int mainCounter;
    int whichSign = x >> 31;
    x = (whichSign & (~x)) | (~whichSign & x);
    a = !(x ^ 0);
    mainCounter = (!!(x >> 16)) << 4;
    mainCounter |= (!!(x >> (mainCounter + 8))) << 3;
    mainCounter |= (!!(x >> (mainCounter + 4))) << 2;
    mainCounter |= (!!(x >> (mainCounter + 2))) << 1;
    mainCounter |= x >> (mainCounter + 1);
    return mainCounter + (~a) + 3;
}



/*
 * sm2tc - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: sm2tc(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int sm2tc(int x) {
    
    //Create two variables, one that will be all zeros, but possibly a 1
    //for the sign bit, and one that will be either all
    //1's or all 0's depending on the sign bit of x.
    //Add zerosPlusBit, the exclusive or of the signed int and x and the signed int and 1 to
    //get the correct signed bit plus the necessary filler 1 bits and finally the plus 1 provided
    //by sign & 1.
    int zerosPlusBit = 0;
    int sign = x;
    sign = sign >> 31;
    zerosPlusBit = sign << 31;
    return zerosPlusBit + (x ^ sign) + (sign & 1);
}


/*
 * isNonNegative - return 1 if x >= 0, return 0 otherwise
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
    
    //Bitwise not x so that if x is negative the sign bit is 0 and vice versa.
    //Arithmetically right shift the integer by 31 to get either all 1's or all 0's.
    //If x is negative, all 0's & 0x1 will result in a return of 0 showing
    //that the function is negative. And vice versa if x is positive.
    return ((~x) >> 31) & 0x1;
}




/*
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x18765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int rotateRight(int x, int n) {
    
    //First makes a mask of all zeros.
    //Then creates a left shift mask with value 33 and not n.
    //Shift x left lshift times and x right n times to get right
    //and left masks.
    //Get a second mask using lshift and 1 and & that with right to
    //get working left and rights to use as final result.
    int firstMask = (~!n) + 1;
    int lshift = ~n + 33;
    int left = x << lshift;
    int right = x >> n;
    int secondMask = ~0 << lshift;
    right &= ~secondMask;
    return (x & firstMask) | (~mask & (left|right));
}




/*
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
    
    //Function shifts x n times but also uses mask and operation integers to add any extra bits.
    //The mask int has 1 bits from the least significant bit all the way to the nth bit.
    //The operation int then either becomes the same as mask if x >> 31 produces all 1's or it becomes
    //all 0's if the sign bit of x is 0.
    //This result is then added to x before x is finally shifted right by n to get the correct value.
    int mask = (1 << n) + ~0;
    int operation = (x >> 31) & mask;
    return (x + operation) >> n;
}

    

/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
    
    //First make a mask that is 32 bits of 5's so that every even bit is a one.
    //Then, or operate on x and the mask to make all bits of result one for each one bit in mask or x.
    //Bitwise not the result so that if there is a one bit left, the function returns zero showing that
    //every odd bit was not a one.
    int mask = (((0x55 << 8) + 0x55) << 16) + ((0x55 << 8) + 0x55)
    int result = x | mask;
    return !(~result);
}



/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
    
    //First & the two ints to get the bits that are both one.
    //Then not both and & the opposites to get all the spots that have ones in either.
    //Finally, & b (ones in all one spots) and the not of a (the spots in x that are zeros) to get
    //the bits that are Xor of each other in x and y.
    int a = x & y;
    int b = ~(~x & ~Y);
    return b & ~a;

}

    
    
/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x) {
    
    //This function has two sides that are compared with the and operator.
    //The right side makes sure x is not zero.
    //The left side tests for Tmin because if you added Tmin to itself,
    //it would result in signed overflow and the result would be zero.
    //Therefore making the left side true and making result a 1.
    int result = !(x + x) & !!(x);
    return result;
}







