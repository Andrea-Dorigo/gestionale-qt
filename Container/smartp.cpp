#include "smartp.h"

SmartP::SmartP(Prodotto* q)
  : p(q ? q->clone() : nullptr)
  {}
