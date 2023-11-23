/*
-> Copy memberlar bildirildiğinde move member'lar delete edileceğinden taşıma yapılamaz ve class copy-only class haline gelir.

Ex:
class Nec{
public:
  Nec();
  Nec(const Nec&);
  Nec& operator=(const Nec&);
};

*/
