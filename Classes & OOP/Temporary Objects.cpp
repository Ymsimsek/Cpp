/*
Temporary Objects:Sadece bir fonksiyon gibi belirli scope içinde kullanılıp scope hayatı sona erince nesnenin de hayatının sona ereceği durumlarda kullanılan terimdir.

Ex:
class myClass{
/..
};
void foo(myClass){}
int main(){
  myClass(); // Temporary
  myClass{}; // Temporary
  myClass{12}; // Temporary
  myClass(25); // Temporary
  foo(myClass); // Temporary
  foo(myClass(12)); // Temporary
}

Ex:
int main(){
  myClass m;
  foo(m); //Not Temporary
}

-> Mandatory copy elision'un (C++ 17) faydalarını kullanmamızı sağlar.

-> Runtime açısından bakıldığında ortada bir nesne vardır ancak kaynak kodda nesnenin ismi yoktur.

-> Temporary object PR value category'dedir.

Ex:
int main(){
  myClass&= myClass{}; // Geçersiz, L value R value'ya bağlanmaz
}

Ex:
int main(){
  const myClass& r = myClass{}; // Geçerli const L value R value'ya bağlanabilir.
  myClass&& r = myClass{}; // Geçerli
}

Ex:
void foo(myClass);
void bar(myClass&);
void baz(const myClass&);
void func(myClass&&);

int main(){
  foo(myClass{}); // Geçerli Call by value
  bar(myClass{}); // L-Value referansa R value bağlanmamalı
  baz(myClass{}); //Geçerli
  func(myClass{});  // Geçerli
}

Life Extensions:

-> Const L value veya R value bir nesneye binding yapılması durumunda geçici nesnenin hayatı refereansın scope'u bitene kadar hayatta kalır. 

-> Geri dönüş türü sınıf değerinde olan fonksiyona yapılan çağrı ifadesi PR value expressiondur.

Ex: 
myClass foo(){
  return myClass{};
}
int main(){
  const myClass& r= foo(); // life extension
 }

*/
