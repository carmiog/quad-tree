#ifndef QUADTREE_H_
#define QUADTREE_H_

#include "qtvector.h"
class QuadTree
{
public:
    QuadTree(int);
    QuadTree(int, const QTVector&);
    ~QuadTree();
    void setValue(const QTVector&);
    QTVector getValue() const;
    void insert(const QTVector&);
    int childrenCount() const;
    int dim() const;
private:
    int dim_;
    QTVector value_;
    QuadTree **children_;
};

int getSuccessorValue(const QTVector&, const QTVector&);
#endif
