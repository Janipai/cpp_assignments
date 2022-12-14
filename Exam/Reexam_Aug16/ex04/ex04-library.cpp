#include <iostream>
#include "ex04-library.h"

using namespace std;

// Exercise 4(a)
template <class C>
Monoid<C>::~Monoid(void){
    if(m1 != nullptr) delete m1;
    if(m2 != nullptr) delete m2;
}

// Exercise 4(b)
template <class C>
int Monoid<C>::constants(void){
    // Put your code here
}

// Exercise 4(c)
template <class C>
void Monoid<C>::commute(void){
    // Put your code here
}

// Exercise 4(d)
template <class C>
void Monoid<C>::associate_left(void){
    // Put your code here
}

// Exercise 4(e)
template <class C>
void Monoid<C>::associate_right(void){
    // Put your code here
}

// Some code follows...
// You don't need to understand it
// but it could give you some hints












































// Do not modify what follows

template <class C>
Monoid<C>::Monoid(C constant){
    this->constant = constant;
    m1 = nullptr;
    m2 = nullptr;
}

template <class C>
Monoid<C>::Monoid(Monoid<C> & m1, Monoid<C> & m2){
    this->m1 = new Monoid<C>(m1);
    this->m2 = new Monoid<C>(m2);
}

template <class C>
Monoid<C>::Monoid(Monoid & m){
    if (m.m1 == nullptr){
        constant = m.constant;
        m1 = nullptr;
        m2 = nullptr;
        return;
    }
    m1 = new Monoid(* m.m1);
    m2 = new Monoid(* m.m2);
}

template <class C>
Monoid<C> & Monoid<C>::operator=(Monoid<C> & m){
    constant = m.constant;
    if (m.m1 == nullptr){
        m1 = nullptr;
        m2 = nullptr;
        return * this;
    }
    m1 = new Monoid(* m.m1);
    m2 = new Monoid(* m.m2);
    return * this;
}

template <class C>
Monoid<C> & Monoid<C>::operator*(Monoid<C> & m){
    Monoid<C> * m1 = new Monoid<C>(* this,m);
    return * m1;
}

template <class C>
C Monoid<C>::eval(C (*f)(C,C)){
    if (m1 == nullptr) return constant;
    else return f(m1->eval(f),m2->eval(f));
}

template <class C>
void Monoid<C>::print(void){
    if (m1 == nullptr) cout << constant ;
    else {
        cout << "( ";
        m1->print();
        cout << " * " ;
        m2->print();
        cout << " )";
    }
}

template class Monoid<string>;
template class Monoid<int>;
