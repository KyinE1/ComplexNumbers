#ifndef COMPLEX_H
#define COMPLEX_H

#include <tuple>

class complex {
	friend std::ostream& operator<<(std::ostream& os, const complex& rhs);
	friend std::istream& operator>>(std::istream&, complex&);
	
	// Operands of the complex number. 
	private:
		double real_part;
		double imaginary_part;
	
	public:
		complex(double = 0.0, double = 0.0);
		std::tuple<double, double> get_complex() const;
		void set_complex(double, double);
		void set_real(double);
		double get_real() const;
		void set_imaginary(double);
		double get_imaginary() const;
		complex operator+(const complex&) const;
	    complex operator*(const complex&) const;
		bool operator==(const complex&) const; 
};

#endif
