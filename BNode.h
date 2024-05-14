#ifndef BNode_h
#define BNode_h
using namespace std;
#include <bits/stdc++.h>
template<class T>
struct Bnode
{
    T data;
    Bnode<T> *parent;
    Bnode<T> *left;
    Bnode<T> *right;
};

#endif