/*
ADL: Bir fonksiyona nitelenmemiş bir isimle çağrı yapıldığında eğer fonksiyonlara gönderilen argümanlardan biri bir namespace içinde tanımlanan 
türe ilişkinse söz konusu fonksiyon ismi o namespace içinde de aranır. 

Ex:
namespace nec{
  class Erg{};
  void foo();
  void bar(int);
  void baz(Erg);
}
int main(){
  nec::Erg e;
  bar(12);//Hata
  baz(e);//Geçerli ADL
}

*/
