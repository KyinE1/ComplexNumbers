#include <iostream>
#include <tuple>
#include "complex.h"

/** Constructor.
 * 
 * @param r: Real part.
 * @param i: Imaginary part.
 */
complex::complex(double r, double i) {
	real_part = r;
	imaginary_part = i;
}

/** Output stream.
 * 
 * @param os: Reference to stream insertion operator.
 * @param c: Reference to an object.
 * @return: Reference to the ostream object.
 */
std::ostream& operator<<(std::ostream& os, const complex& c) {	
	double real_part = c.get_real();
	double imaginary_part = c.get_imaginary();
	
	os << '(' << real_part << ", " << imaginary_part << ')';
	
	return os;
}

/** Sets the real and imaginary parts of the complex number.
 * 
 * @param r: Real part.
 * @param i: Imaginary part. 
 */
void complex::set_complex(double r, double i) {
	real_part = r;
	imaginary_part = i;
}

/** Accessor and mutator methods. */
void complex::set_real(double r) {
	real_part = r;
}

double complex::get_real() const {
	return real_part;
}

void complex::set_imaginary(double i) {
	imaginary_part = i;
}

double complex::get_imaginary() const {
	return imaginary_part;
}

/** Returns the tuple of the real and imaginary parts.
 * 
 * @return: The data members after using the compound data type.   
 */
std::tuple<double, double> complex::get_complex() const {
	return std::make_tuple(real_part, imaginary_part);
}

/** Input stream to read the input from the user.
 *
 * @param is: Reference to stream extraction operator.
 * @param c: Reference to an object.	
 * @return reference to the first parameter (istream object).
 */
std::istream& operator>>(std::istream& is, complex& rhs) {
	char ch; 
	
	// Read input of the form (r,i)
	is >> ch;
	is >> rhs.real_part; 		
	is >> ch; 
	is >> rhs.imaginary_part; 
	is >> ch;  
	
	// Return input stream object for operator to correctly cascade.
	return is; 
}

/** Calculate the sum of the complex number's operands. 
 * 
 * @param rhs: Right-hand side of arithmethic expression. 
 * @return the complex object's arithmetic. 
 */
complex complex::operator+(const complex& rhs) const {
	complex result;
	
	result.real_part = this->real_part + rhs.real_part;
	result.imaginary_part = this->imaginary_part + rhs.imaginary_part;
	
	return result;
}

/** Check the equality of the two parts.
 * 
 * @param rhs: 	Right-hand side of arithmethic expression. 
 * @return: True if both data members are equal. 
 */
bool complex::operator==(const complex& rhs) const {
	if (this->real_part == rhs.real_part && this->imaginary_part == rhs.imaginary_part)
		return true;
	
	return false; 
}

/** Calculate the product of the complex number's operands. 
 * 
 * @param rhs: Right-hand side of arithmethic expression. 
 * @return: The result of the calculation.  
 */
complex complex::operator*(const complex& rhs) const {
    complex result;
 
	result.real_part = this->real_part * rhs.real_part - this->imaginary_part * rhs.imaginary_part;
    result.imaginary_part = this->real_part * rhs.imaginary_part + this->imaginary_part * rhs.real_part;
	
    return result;
}
