/*
	account.cpp
	Date Written: 3/3
	Created by: Kyin Edwards
*/

#include <iostream>
#include <tuple>
#include "complex.h"

/*
	Constructor. 
	
	@param r used for the assignment of the real_part. 
		
	@param i used for the assignment of the imaginary_part. 
*/
complex::complex(double r, double i) {
	real_part = r;
	imaginary_part = i;
}

/*
	Used for the output stream.
	
	@param os used as the reference to the stream insertion operator. 
		
	@param c used as a reference to an object. 
	
	@return reference to the first parameter (ostream object).
*/
std::ostream& operator<<(std::ostream& os, const complex& c) {	
	double real_part = c.get_real();
	double imaginary_part = c.get_imaginary();
	
	os << '(' << real_part << ", " << imaginary_part << ')';
	
	return os;
}

/*
	Set the function parameters to the real and imaginary parts.   
	
	@param r set to the real_part. 
		
	@param i set to the imaginary_part. 
*/
void complex::set_complex(double r, double i) {
	real_part = r;
	imaginary_part = i;
}

/*
	Assign the real_part data member to the function parameter.  
	
	@param r for the assignment of the real_part. 
		
	@param i for the assignment of the imaginary_part. 
*/
void complex::set_real(double r) {
	real_part = r;
}

/*
	Return the real_part data member's value. 
	
	@return: Returns the data member's value. 
*/
double complex::get_real() const {
	return real_part;
}

/*
	Assign the imaginary_part data member to the function parameter.   
		
	@param i for the assignment of the imaginary_part. 
*/
void complex::set_imaginary(double i) {
	imaginary_part = i;
}

/*
	Return the imaginary_part data member's value. 
	
	@return the data member's value. 
*/
double complex::get_imaginary() const {
	return imaginary_part;
}

/*
	Return the tuple of the real_part and imaginary_part.  
	
	@return the data members after using the compound data type for two variables. 
*/
std::tuple<double, double> complex::get_complex() const {
	return std::make_tuple(real_part, imaginary_part);
}

/*
	Input stream to read the input from the user as an ordered pair.
	
	@param is reference to the stream extraction operator. 
		
	@param c reference to an object. 
	
	@return reference to the first parameter (istream object).
*/
std::istream& operator>>(std::istream& is, complex& rhs) {
	char ch; 
	
	// Read input of the form (r,i)
	is >> ch; // For reading the '(' character.
	is >> rhs.real_part; // Input real_part.
	is >> ch; // For reading the comma.
	is >> rhs.imaginary_part; // Input imaginary_part.
	is >> ch; // For reading the ')' character. 
	
	// Return input stream object for operator to correctly cascade.
	return is; 
}

/*
	Calculate the sum of the complex number's operands. 
	
	@param rhs reference to a complex operand for the right side of the arithmethic expression. 
	
	@return the complex object's arithmetic. 
*/
complex complex::operator+(const complex& rhs) const {
	complex result;
	
	result.real_part = this->real_part + rhs.real_part;
	result.imaginary_part = this->imaginary_part + rhs.imaginary_part;
	
	return result;
}

/*
	Check the equality of the two parts of the complex number. 
	
	@param rhs reference to a complex operand for the right side of the arithmethic expression. 
	
	@return true if both the data members and references to the real and imaginary_parts are equal. 
*/
bool complex::operator==(const complex& rhs) const {
	
	if (this->real_part == rhs.real_part && this->imaginary_part == rhs.imaginary_part)
		return true;
	
	return false; 
}

/*
	Calculate the product of the complex number's operands. 
	
	@param rhs reference to a complex operand for the right side of the arithmethic expression. 
	
	@return the complex object's arithmetic.  
*/
complex complex::operator*(const complex& rhs) const {
    complex result;   // Temporary object to hold the result.
 
	// The this pointer isn't needed as they are implicit.
	result.real_part = this->real_part * rhs.real_part - this->imaginary_part * rhs.imaginary_part;
    result.imaginary_part = this->real_part * rhs.imaginary_part + this->imaginary_part * rhs.real_part;
	
    return result;
}