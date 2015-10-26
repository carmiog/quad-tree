#include "quadtree.h"
#include "qtvector.h"
#include "utils.h"
QuadTree::QuadTree(int dim)
{
    dim_ = dim*4;
    children_ = new QuadTree*[dim_];
    for(int i = 0; i < dim_; i++)
        children_[i] = nullptr;
}


QuadTree::QuadTree(int dim, const QTVector& qv)
{
    dim_ = pow2(dim);
    children_ = new QuadTree*[dim];
    for(int i = 0; i < dim_; i++)
        children_[i] = nullptr;
    setValue(qv);
}

QuadTree::~QuadTree()
{
    for(int i = 0; i < dim_; i++)
        if(children_[i] not_eq nullptr)
            delete children_[i];
    delete children_;
}

void QuadTree::setValue(const QTVector& qv)
{
    value_ = QTVector{qv};
}

QTVector QuadTree::getValue() const
{
    return value_;
}

void QuadTree::insert(const QTVector& qv)
{
    if(value_.isNull()) {
        setValue(qv);
    } else {
        int k = getSuccessorValue(qv, value_);
        if(children_[k] == nullptr) {
            children_[k] = new QuadTree{dim_, qv};
        } else {
            children_[k]->insert(qv);
        }
    }
}

int QuadTree::childrenCount() const
{
    int res = 0;
    for(int i = 0; i < dim_; i++)
        if(children_[i] not_eq nullptr)
            res++;
    return res;
}

int QuadTree::dim() const
{
    return dim_;
}
int getSuccessorValue(const QTVector& x, const QTVector& y)
{
    int k = (x.at(0) > y.at(0)) ? 1 : 0; 
    for(int i = 1; i < x.dim(); i++)
        if(x.at(i) > y.at(i))
            k += 2 << (i-1);
    return k;
}
