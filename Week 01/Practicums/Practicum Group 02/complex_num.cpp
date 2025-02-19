#include <iostream>

struct ComplexNumber
{
	double re = 0.0;
	double im = 0.0;
};

ComplexNumber init(double re, double im)
{
	return { re, im };
}

void print(const ComplexNumber& complex)
{
	std::cout << complex.re << " + " << complex.im << "i" << std::endl;
}

ComplexNumber conjugate(const ComplexNumber& complex)
{
	return { complex.re, -complex.im };
}

ComplexNumber add(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
	return { lhs.re + rhs.re, lhs.im + rhs.im };
}

ComplexNumber subtract(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
	return { lhs.re - rhs.re, lhs.im - rhs.im };
}

ComplexNumber multiply(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
	double re = lhs.re * rhs.re - lhs.im * rhs.im;
	double im = lhs.re * rhs.im + lhs.im * rhs.re;
	return { re, im };
}

ComplexNumber divide(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
    double denominator = rhs.re * rhs.re + rhs.im * rhs.im;
    std::cout << denominator << std::endl;
    if (denominator == 0)
    {
        std::cerr << "Division by zero" << std::endl;
        return { 0, 0 };
    }

    ComplexNumber numerator = multiply(lhs, conjugate(rhs));

    return { numerator.re / denominator, numerator.im / denominator };
}

int main()
{
    ComplexNumber a = init(4, 3);
    ComplexNumber b = init(2, -1);

    std::cout << "a = "; print(a);
    std::cout << "b = "; print(b);

    ComplexNumber sum = add(a, b);
    std::cout << "a + b = "; print(sum);

    ComplexNumber difference = subtract(a, b);
    std::cout << "a - b = "; print(difference);

    ComplexNumber product = multiply(a, b);
    std::cout << "a * b = "; print(product);

    ComplexNumber quotient = divide(a, b);
    std::cout << "a / b = "; print(quotient);

    return 0;
}
