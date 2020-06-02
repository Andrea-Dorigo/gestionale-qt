#ifndef SMARTP_H
#define SMARTP_H

template<class T>
class SmartP {
  public:
    T* p;
    SmartP(T* q=nullptr);
    SmartP(const SmartP& s);
    ~SmartP();
    SmartP& operator=(const SmartP& s);
    bool operator==(const SmartP& s) const;
    T* operator->() const;
    T& operator*() const;
};

#endif // SMARTP_H
