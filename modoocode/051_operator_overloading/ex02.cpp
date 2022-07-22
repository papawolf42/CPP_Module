// 증감연산자
#include <iostream>

class Complex
{
	private:
	double _real, _img;

	public:
	Complex(double real, double img) : _real(real), _img(img) {}

	Complex operator+(const Complex& c) const;
	Complex operator-(const Complex& c) const;
	Complex operator*(const Complex& c) const;
	Complex operator/(const Complex& c) const;

	Complex& operator=(const Complex& c);

	Complex& operator+=(const Complex& c);
	Complex& operator-=(const Complex& c);
	Complex& operator*=(const Complex& c);
	Complex& operator/=(const Complex& c);

	void println()
	{
		std::cout << "( " << _real << " , " << _img << " ) " << std::endl;
	}
};

Complex Complex::operator+(const Complex&c) const
{
	Complex temp(_real + c._real, _img + c._img);
	return temp;
}

Complex Complex::operator-(const Complex&c) const
{
	Complex temp(_real - c._real, _img - c._img);
	return temp;
}

Complex Complex::operator*(const Complex&c) const
{
	Complex temp(_real * c._real - _img * c._img, _real * c._img + _img * c._real);
	return temp;
}

Complex Complex::operator/(const Complex&c) const
{
	Complex temp((_real * c._real + _img * c._img) / (c._real * c._real + c._img * c._img),
    (_img * c._real - _real * c._img) / (c._real * c._real + c._img * c._img));
	return temp;
}

Complex& Complex::operator=(const Complex& c)
{
	this->_img = c._img;
	this->_real = c._real;
	return (*this);
}

Complex& Complex::operator+=(const Complex& c)
{
	(*this) = (*this) + c;
	return (*this);	
}

Complex& Complex::operator-=(const Complex& c)
{
	(*this) = (*this) - c;
	return (*this);	
}

Complex& Complex::operator*=(const Complex& c)
{
	(*this) = (*this) * c;
	return (*this);	
}

Complex& Complex::operator/=(const Complex& c)
{
	(*this) = (*this) / c;
	return (*this);	
}


int main()
{
	Complex a(1.0, 2.0);
	Complex b(3.0, -2.0);

	a += b;

	a.println();
	b.println();
}
