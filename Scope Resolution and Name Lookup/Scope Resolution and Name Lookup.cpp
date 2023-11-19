/* 
Scope Resolution Operator (::)

-> C++'da bir fonksiyona, sınıfa, değişkene vs. erişim sağlanırken şu sıra takip edilir. 
Name Lookup -> Context Control -> Access Control

Unary Scope Resolution Operator: 

Kullanım Şekli:  (::g)

Programda kullanılan ifadenin name lookup aşamasında kod bloğu kapsamında değil global kapsamda temsil edildiğini ve 
çağrı sırasında global kapsamdaki ifadenin çağrılmasında görev alır. Unary(Tekil) kapsam çözünürlük operatörü
globaldeki fonksiyonları çağırmada da kullanılabilir. 

Ex:
#include <iostream>
int g{56};
int main(){
  int g{10};
  std::cout<<"g="<<g<<'\n';// main bloğunun kapsamındaki g
  std::cout<<"g="<<::g<<'\n';// global bloktaki g
}
->Output:
g=10
g=56

Ex:
void func(int x){
  int func{40};
  //...
  ::func(func);// Recursive Call 
}

Binary Scope Resolution Operator: (x::y)

-> Çözünürlük operatörü binary olarak kullanıldığında soldaki ifade, class ismi, namespace ismi, veya enum type dahi olabilir. (enum modern C++'da)

-> Eğer bir isim identifier olmadan kullanılırsa unqualified name olur. 

Ex: a, b, ..

-> Eğer bir isim başka bir isimle nitelenirse qualified name olur.

Ex: x::a, ::b, x.y, c->y


