#ifndef CONTAINER_H
#define CONTAINER_H

template <class T>
class Container {
  friend class iterator;
  friend class const_iterator;
  private:
    class nodo {
      nodo(const T&, nodo* =nullptr, nodo* =nullptr);
      ~nodo();
      T info;
      nodo* prev;
      nodo* next;
    };
    nodo* first;
    nodo* last;
    unsigned int size;
    static nodo* copy(nodo*, nodo*, nodo*&);
    static bool isEqual(nodo*, nodo*);
    static bool isMinor(nodo*, nodo*);
    static bool isGreater(nodo*, nodo*);
    static bool isMinorEqual(nodo*, nodo*);
    static bool isGreaterEqual(nodo*, nodo*);
  public:
    class iterator {
      friend class Container;
      private:
        nodo* p;
        iterator(nodo* =nullptr);
      public:
        // iterator();
        T& operator*() const;
        T* operator->() const;
        iterator operator+(int) const;
        iterator operator-(int) const;
        iterator& operator++();
        iterator operator++(int);
        iterator& operator--();
        iterator operator--(int);
        bool operator!=(const iterator&) const;
        bool operator==(const iterator&) const;
        bool operator<(const iterator&) const;
        bool operator>(const iterator&) const;
        bool operator<=(const iterator&) const;
        bool operator>=(const iterator&) const;
    };
    class const_iterator {
      friend class Container;
      private:
        const nodo* p;
        const_iterator(const nodo* =nullptr);
      public:
        // const_iterator();
        const_iterator(const iterator&);
        const T& operator*() const;
        const T* operator->() const;
        const_iterator operator+(int) const;
        const_iterator operator-(int) const;
        const_iterator& operator++();
        const_iterator operator++(int);
        const_iterator& operator--();
        const_iterator operator--(int);
        bool operator!=(const const_iterator&) const;
        bool operator==(const const_iterator&) const;
        bool operator<(const const_iterator&) const;
        bool operator>(const const_iterator&) const;
        bool operator<=(const const_iterator&) const;
        bool operator>=(const const_iterator&) const;
    };
    Container(nodo* =nullptr, nodo* =nullptr, unsigned int =0);
    Container(const Container&);
    ~Container();
    Container& operator=(const Container&);
    bool operator!=(const Container&) const;
    bool operator==(const Container&) const;
    bool operator<(const Container&) const;
    bool operator>(const Container&) const;
    bool operator<=(const Container&) const;
    bool operator>=(const Container&) const;
    unsigned int getSize() const;
    bool empty() const;
    void clear();
    void push_front(const T&);
    void push_back(const T&);
    void pop_front();
    void pop_back();
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    iterator insert(iterator, const T&);
    iterator erase(iterator);
    bool search(const T&, iterator&) const;
};

/* metodi Container::nodo */

template<class T>
Container<T>::nodo::nodo(const T& t, nodo* precedente, nodo* successivo)
  : info(t)
  , prev(precedente)
  , next(successivo)
  {}

template<class T>
Container<T>::nodo::~nodo() {
  if(next) delete next;
}

/* metodi Container::iterator */

template <class T>
Container<T>::iterator::iterator(nodo* n)
  : p(n)
  {}

template <class T>
T& Container<T>::iterator::operator*() const {
  return p->info;
}

template <class T>
T* Container<T>::iterator::operator->() const {
  return &(p->info);
}

template <class T>
typename Container<T>::iterator Container<T>::iterator::operator+(int i) const {
  iterator aux(p);
  while(i > 0) {
    aux.p = aux.p->next;
    i--;
  }
  return aux;
}

template <class T>
typename Container<T>::iterator Container<T>::iterator::operator-(int i) const {
  iterator aux(p);
  while(i > 0) {
    aux.p = aux.p->prev;
    i--;
  }
  return aux;
}

template <class T>
typename Container<T>::iterator& Container<T>::iterator::operator++() {
  if(this->p) p = p->next;
  return *this;
}

template <class T>
typename Container<T>::iterator Container<T>::iterator::operator++(int) {
  iterator aux(*this);
  if(this->p) p = p->next;
  return aux;
}

template <class T>
typename Container<T>::iterator& Container<T>::iterator::operator--() {
  if(p) p = p->prev;
  else p = last;
  return *this;
}

template <class T>
typename Container<T>::iterator Container<T>::iterator::operator--(int) {
  iterator aux(p);
  if(p) p = p->prev;
  else p = last;
  return aux;
}

template <class T>
bool Container<T>::iterator::operator!=(const iterator& it) const {
  return !(p == it.p);
}

template <class T>
bool Container<T>::iterator::operator==(const iterator& it) const {
  return p == it.p;
}

template <class T>
bool Container<T>::iterator::operator<(const iterator& it) const {
  return p->info < it.p;
}

template <class T>
bool Container<T>::iterator::operator>(const iterator& it) const {
  return p->info > it.p;
}

template <class T>
bool Container<T>::iterator::operator<=(const iterator& it) const {
  return p->info <= it.p;
  // return (p->info < it.p) || (p->info == it.p);
}

template <class T>
bool Container<T>::iterator::operator>=(const iterator& it) const {
  return p->info >= it.p;
  // return (p->info > it.p) || (p->info == it.p);
}

/* metodi Container::const_iterator */

template<class T>
Container<T>::const_iterator::const_iterator(const nodo* n)
  : p(n)
  {}

template <class T>
Container<T>::const_iterator::const_iterator(const iterator& it)
  : p(it.p)
  {}

template <class T>
const T& Container<T>::const_iterator::operator*() const {
  return p->info;
}

template <class T>
const T* Container<T>::const_iterator::operator->() const {
  return &(p->info);
}

template <class T>
typename Container<T>::const_iterator Container<T>::const_iterator::operator+(int i) const {
  const_iterator aux(p);
  while(i > 0) {
    aux.p = aux.p->next;
    i--;
  }
  return aux;
}

template <class T>
typename Container<T>::const_iterator Container<T>::const_iterator::operator-(int i) const {
  const_iterator aux(p);
  while(i > 0) {
    aux.p = aux.p->prev;
    i--;
  }
  return aux;
}

template <class T>
typename Container<T>::const_iterator& Container<T>::const_iterator::operator++() {
  if(this->p) p = p->next;
  return *this;
}

template <class T>
typename Container<T>::const_iterator Container<T>::const_iterator::operator++(int) {
  const_iterator aux(*this);
  if(this->p) p = p->next;
  return aux;
}

template <class T>
typename Container<T>::const_iterator& Container<T>::const_iterator::operator--() {
  if(p) p = p->prev;
  else p = last;
  return *this;
}

template <class T>
typename Container<T>::const_iterator Container<T>::const_iterator::operator--(int) {
  const_iterator aux(p);
  if(p) p = p->prev;
  else p = last;
  return aux;
}

template <class T>
bool Container<T>::const_iterator::operator!=(const const_iterator& it) const {
  return !(p == it.p);
}

template <class T>
bool Container<T>::const_iterator::operator==(const const_iterator& it) const {
  return p == it.p;
}

template <class T>
bool Container<T>::const_iterator::operator<(const const_iterator& it) const {
  return p < it.p;
}

template <class T>
bool Container<T>::const_iterator::operator>(const const_iterator& it) const {
  return p > it.p;
}

template <class T>
bool Container<T>::const_iterator::operator<=(const const_iterator& it) const {
  return p <= it.p;
  // return (p < it.p) || (p == it.p);
}

template <class T>
bool Container<T>::const_iterator::operator>=(const const_iterator& it) const {
  return p >= it.p;
  // return (p > it.p) || (p == it.p);
}

/* metodi Container */

template<class T>
typename Container<T>::nodo* Container<T>::copy(nodo* primo, nodo* precedente, nodo*& ultimo) {
  if(!primo) {
    ultimo = nullptr;
    return nullptr;
  }
  nodo* n = new nodo(primo->info, precedente, nullptr);
  n->next = copy(primo->next, n, ultimo);
  if(primo->next == nullptr) ultimo = n;
  return n;
}

template<class T>
bool Container<T>::isEqual(nodo* n1, nodo* n2) {
  if(!n1 && !n2) return true;
  if(!n1 || !n2) return false;
  return (n1->info == n2->info) && isEqual(n1->next, n2->next);
}

template<class T>
bool Container<T>::isMinor(nodo* n1, nodo* n2) {
    if(!n2) return false;
    if(!n1) return true;
    return (n1->info < n2->info) ||
            ((n1->info == n2->info) && isMinor(n1->next, n2->next));
}

template<class T>
bool Container<T>::isGreater(nodo* n1, nodo* n2) {
    if(!n1) return false;
    if(!n2) return true;
    return (n1->info > n2->info) ||
            ((n1->info == n2->info) && isGreater(n1->next, n2->next));
}

template<class T>
bool Container<T>::isMinorEqual(nodo* n1, nodo* n2) {
    if(!n2 && !n1) return true;
    if(!n2) return false;
    if(!n1) return true;
    return ((n1->info < n2->info) || (n1->info == n2->info)) &&
            isMinorEqual(n1->next, n2->next);
}

template<class T>
bool Container<T>::isGreaterEqual(nodo* n1, nodo* n2) {
    if(!n1 && !n2) return true;
    if(!n1) return false;
    if(!n2) return true;
    return ((n1->info > n2->info) || (n1->info == n2->info)) &&
            isGreaterEqual(n1->next, n2->next);
}

template<class T>
Container<T>::Container(nodo* primo, nodo* ultimo, unsigned int dimensione)
  : first(primo)
  , last(ultimo)
  , size(dimensione)
  {}

template<class T>
Container<T>::Container(const Container& c)
  : first(copia(c.first, nullptr, last))
  , size(c.size)
  {}

template<class T>
Container<T>::~Container() {
  if(first) delete first;
}

template<class T>
Container<T>& Container<T>::operator=(const Container& c) {
  if(this != &c) {
    if(first) delete first;
    first = copy(c.first, nullptr, last);
    size = c.size;
  }
  return *this;
}

template<class T>
bool Container<T>::operator!=(const Container& c) const
{
    return !(Container<T>::isEqual(first, c.first));
}

template<class T>
bool Container<T>::operator==(const Container& c) const
{
    return Container<T>::isEqual(first, c.first);
}

template<class T>
bool Container<T>::operator<(const Container& c) const {
    return Container<T>::isMinor(first, c.first);
}

template<class T>
bool Container<T>::operator>(const Container& c) const {
    return Container<T>::isGreater(first, c.first);
}

template<class T>
bool Container<T>::operator<=(const Container& c) const {
    return Container<T>::isMinorEqual(first, c.first);
}

template<class T>
bool Container<T>::operator>=(const Container& c) const {
    return Container<T>::isGreaterEqual(first, c.first);
}

template<class T>
unsigned int Container<T>::getSize() const {
  return size;
}

template<class T>
bool Container<T>::empty() const {
  return !first;
}

template<class T>
void Container<T>::clear() {
  if(first) delete first;
  first = nullptr;
  last = nullptr;
  size = 0;
}

template<class T>
void Container<T>::push_front(const T& t) {
  if(!first) {
    first = new nodo(t);
    last = new nodo(t);
  }
  else {
    first->prev = new nodo(t, nullptr, first);
    first = first->prev;
  }
  size++;
}

template<class T>
void Container<T>::push_back(const T& t) {
  if(!first) { // !first => !last
    first = new nodo(t);
    last = new nodo(t);
  }
  else {
    last->next = new nodo(t, last, nullptr);
    last = last->next;
  }
  size++;
}

template<class T>
void Container<T>::pop_front() {
  if(!empty()) {
    nodo* temp = first;
    if(first == last) {
      first = nullptr;
      last = nullptr;
    }
    else {
      first = first->next;
      first->prev = nullptr;
      temp->next = nullptr;
    }
    delete temp;
    size--;
  }
}

template<class T>
void Container<T>::pop_back() {
  if(!empty()) {
    nodo* temp = last;
    if(last == first) {
      last = nullptr;
      first = nullptr;
    }
    else {
      last = last->prev;
      last->next = nullptr;
      temp->prev = nullptr;
    }
    delete temp;
    size--;
  }
}

template<class T>
typename Container<T>::iterator Container<T>::begin() {
  iterator it(first);
  return it;
}

template<class T>
typename Container<T>::iterator Container<T>::end() {
  iterator it;
  return it;
}

template<class T>
typename Container<T>::const_iterator Container<T>::begin() const {
  const_iterator cit(first);
  return cit;
}

template<class T>
typename Container<T>::const_iterator Container<T>::end() const {
  const_iterator cit;
  return cit;
}
// inserimento di nodo in pos. antecedente a quella di it
template<class T>
typename Container<T>::iterator Container<T>::insert(iterator it, const T& t) {
  nodo* n = nullptr;
  if(it.p) {
    n = new nodo(t, it.p->prev, it.p);
    if(first != it.p) it.p->prev->next = n;
    else first = n;
    it.p->prev = n;
  }
  else { // it si trova a past-the-end
    n = new nodo(t, last, nullptr);
    if(last) last->next = n;
    if(first == last) first = n;
    last = n;
  }
  size++;
  return iterator(n);
}

template<class T>
typename Container<T>::iterator Container<T>::erase(iterator it) {
  iterator aux;
  if(it.p == first && it.p == last) { // it.p == nodo unico
    aux = iterator();
    first = nullptr;
  }
  else if(it.p == first) { // it.p == primo nodo
    first = first->next;
    aux = iterator(first);
    first->prev->next = nullptr;
  }
  else if(it.p == last) { // it.p == ultimo nodo
    aux = iterator();
    last = last->prev;
    last->next = nullptr;
  }
  else { // it.p == nodo in centro
    aux = iterator(it.p->next);
    it.p->prev->next = it.p->next;
    it.p->next->prev = it.p->prev;
  }
  it.p->next = nullptr;
  delete it.p;
  size--;
  return aux;
}

template<class T>
bool Container<T>::search(const T& t, iterator& it) const {
  bool trovato = false;
  for(auto cit = begin(); cit != end() && !trovato; cit++) {
    if(*cit == t) { // utilizzo operator== della classe T
      trovato = true;
      it.p = const_cast<nodo*>(cit.p);
    }
  }
  return trovato;
}

#endif // CONTAINER_H
