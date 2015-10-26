#include "qtvector.h"
#include <initializer_list>
#include <cmath>
#include <string>

QTVector::QTVector(std::initializer_list<double> l)
{
    dim_ = l.size();
    values_ = std::vector<double>(l);
}

QTVector::QTVector(double *array, int size)
{
    dim_ = size;
    values_.reserve(size);
    for(int i = 0; i < size; i++)
        values_[i] = array[i];
}

double QTVector::norm2() const
{
    double sum = 0;
    for(auto v : values_)
        sum += v*v;
    return sqrt(sum);
}

QTVector::QTVector(const QTVector& other)
{
    dim_ = other.dim();
    values_.resize(other.dim());
    for(int i = 0; i < other.dim(); i++) {
        values_[i] = other.at(i);
    }
}

QTVector::QTVector()
{
    dim_ = 0;
}

QTVector::~QTVector()
{

}

bool QTVector::isNull() const
{
    return dim_ == 0;    
}

double& QTVector::operator[](int n)
{
    return values_[n];
}

int QTVector::dim() const
{
    return dim_;
}

double QTVector::at(int n) const
{
    return values_.at(n);
}

std::string QTVector::toString() const
{
	string res{"{"};
	for(auto v : values_) {
		res += v;
		res += " "
	}
	res += "}";
	return res;
}
