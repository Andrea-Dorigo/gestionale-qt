#ifndef SMARTP_H
#define SMARTP_H

#include <typeinfo>

template<class T>
class SmartP {
public:
    T* p;
    SmartP(T* q = nullptr);
    SmartP(const SmartP&);
    ~SmartP();
    SmartP& operator=(const SmartP&);
    bool operator==(const SmartP&) const;
    T* operator->() const;
    T& operator*() const;
};

template<class T>
SmartP<T>::SmartP(T* q)
    : p(q!=nullptr ? q->clone() : nullptr)
{}

template<class T>
SmartP<T>::SmartP(const SmartP& s)
    : p(s.p!=nullptr ? (s.p)->clone() : nullptr)
{}

template<class T>
SmartP<T>::~SmartP() {
    if(p) delete p;
}

template<class T>
SmartP<T>& SmartP<T>::operator=(const SmartP& s) {
    if(this != &s) {
        if(p) delete p;
        p = (s.p!=nullptr ? (s.p)->clone() : nullptr);
    }
    return *this;
}

template<class T>
bool SmartP<T>::operator==(const SmartP& s) const {
    return typeid(*p) == typeid(*s.p) && *p == *(s.p);
}

template<class T>
T* SmartP<T>::operator->() const {
    return p;
}

template<class T>
T& SmartP<T>::operator*() const {
    return *p;
}

#endif // SMARTP_H
