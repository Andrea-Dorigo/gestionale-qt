#ifndef SMARTP_H
#define SMARTP_H

class SmartP {
public:
  Prodotto* p;
  SmartP(Prodotto* q=nullptr);
  SmartP(const SmartP& s);
  ~SmartP();
  SmartP& operator=(const SmartP& s);
  bool operator==(const SmartP& s);
  Prodotto* operator->() const;
  Prodotto& operator*() const;
};
#endif // SMARTP_H
