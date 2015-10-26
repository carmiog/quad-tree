#ifndef QUADTREE_H_
#define QUADTREE_H_

#include "qtvector.h"
class QuadTree
{
public:
    QuadTree(int);
    QuadTree(int, const QTVector&);
    ~QuadTree();
    void set_value(const QTVector&);
    QTVector get_value() const;
    void insert(const QTVector&);
    int children_count() const;
    int dim() const;
private:
    int dim_;
    QTVector value_;
    QuadTree **children_;
};
#endif
