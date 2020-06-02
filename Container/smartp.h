#ifndef SMARTP_H
#define SMARTP_H

class SmartP {
public:
  Prodotto* p;
  SmartP(Prodotto* q);
  SmartP(const SmartP& s);
  SmartP& operator=(const SmartP& s);
  ~SmartP();
  Prodotto* operator->() const;
  Prodotto& operator*() const;
};
#endif // SMARTP_H
