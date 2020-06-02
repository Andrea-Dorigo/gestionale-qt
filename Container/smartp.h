#ifndef SMARTP_H
#define SMARTP_H

template<class T>
class SmartP {
  /* Aggiungere la seguente riga per renderlo utilizzabile da tutti i tipi:
     template<class T>
     prima della dichiarazione della classe e della implementazione dei metodi.
     Successivamente, sostituire le istanze di T con T
  */
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
