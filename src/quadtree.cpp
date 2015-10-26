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
    set_value(qv);
}

QuadTree::~QuadTree()
{
    for(int i = 0; i < dim_; i++)
        if(children_[i] not_eq nullptr)
            delete children_[i];
    delete children_;
}

void QuadTree::set_value(const QTVector& qv)
{
    value_ = QTVector{qv};
}

QTVector QuadTree::get_value() const
{
    return value_;
}

void QuadTree::insert(const QTVector& qv)
{
    if(value_.is_null()) {
        set_value(qv);
    } else {
        int k = qv.k_successor_of(value_);
        if(children_[k] == nullptr) {
            children_[k] = new QuadTree{dim_, qv};
        } else {
            children_[k]->insert(qv);
        }
    }
}

int QuadTree::children_count() const
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
