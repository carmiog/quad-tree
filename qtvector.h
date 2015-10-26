#ifndef QTVECTOR_H_
#define QTVECTOR_H_

#include <initializer_list>
#include <vector>
class QTVector
{
public:
    QTVector(std::initializer_list<double>);
    QTVector(const QTVector&);
    QTVector();
    ~QTVector();
    int dim() const;
    bool isNull() const;
    double& operator[](int);
    double at(int) const;
private:
    int dim_;
    std::vector<double> values_;
};


#endif
