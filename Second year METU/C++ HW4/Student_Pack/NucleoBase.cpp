#include "NucleoBase.h"

NucleoBase :: NucleoBase(string rna, NucleoBase* prev) {
  RNA = rna;
  prevNuc = prev;
}

NucleoBase :: NucleoBase(const NucleoBase& rhs) {
  RNA = rhs.RNA;
	prevNuc = new NucleoBase(RNA, rhs.prevNuc);
}

NucleoBase :: ~NucleoBase() {
  RNA = "";
  delete prevNuc; 
}

NucleoBase* NucleoBase :: GetLast() {
  NucleoBase* last = prevNuc;
  while (last->prevNuc) {
    last = prevNuc;
  }
  return last;
}

std :: ostream& operator<<(ostream& os, const NucleoBase& nucleoBase) {
  NucleoBase* last = nucleoBase.prevNuc;
  os << nucleoBase.RNA;
  while (last) {
    os << last->RNA;
    last = last->prevNuc;
  }
  return os;
}