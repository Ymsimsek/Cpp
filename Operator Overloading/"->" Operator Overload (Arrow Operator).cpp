/*
-> Ok operatörü binary operatörüdür. Her ne kadar ok operatörü binary olsa da C++ kurallarına göre unary operatörmüş gibi overload edilir. 

-> Index operatör fonksiyonu, ok operatör fonksiyonu, atama operatör fonksiyonu, tür dönüştürme operatör fonksiyonları, fonksiyon çağırma operatör fonksiyonları global olarak overload edilemezler. 

-> Ok operator overload fonksiyonunun parametre değişkeni olmaz.

-> P, bşr sınıf nesnesi olsun. Bu sınıf için ok operatörü overload edilmiş olsun. Derleyici "p->x" ifadesi için "p.operator->()->x" ifadesini üretir. Bu ifadenin legal olabilmesi için operatör fonksiyonunun 
geri dönüş değerinin pointer olması gerekir. 

Ex:
class myClass{
public:
  void foo();
  void bar(int);
};

class pointerLike{
public:
  pointerLike(myClass*);
  myClass* operator -> ();
};

int main(){
  pointerLike p = new myClass; 
  p->foo();      // p.operator->()->foo();
  p->bar(12);    // p.operator->()->bar(12);
}

-> Bir sınıf nesnesi, ok operatörünün operandı olduğunda ok operatörünün operandı olan sınıf nesnesini "*this" olarak kullanıp, sınıfın ok operatör fonksiyonuna çağrıya dönüştürüyor ancak fonksiyon çağrı ifadesini
okun sol operandı yapıyor. Yani ok yerinde duruyor gibi gözüküyor. 

Ex:
struct A{
  void foo();
};

struct B{
  A* operator->();
};

struct C{
  B operator->();
};

struct D{
  C operator->();
};

int main(){
  D dx;
  dx ->foo();
}

*/
