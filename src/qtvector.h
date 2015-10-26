#ifndef QTVECTOR_H_
#define QTVECTOR_H_

#include <initializer_list>
#include <vector>
#include <string>
class QTVector
{
public:
    QTVector(std::initializer_list<double>);
    QTVector(double*, int);
    QTVector(const QTVector&);
    QTVector();
    ~QTVector();
    int dim() const;
    bool is_null() const;
    double& operator[](int);
    double at(int) const;
    double norm2() const;
    int k_successor_of(const QTVector&);
    std::string to_string() const;
private:
    int dim_;
    std::vector<double> values_;
};


#endif
