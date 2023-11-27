/*
-> Nokta operatörü, ok operatörü ve çözünürlük operatörünün solundaki isim türetilmiş sınıf nesnesiyse sağ operand olan isim önce türemiş sınıfın kapsamında orada bulunamazsa taban sınıf kapsamında aranır.

Ex:
class Base{
public:
  void foo();
};
class Der:public Base{
  void foo(int);
};
int main(){
  Der myDer;
  myDer.foo(); //Overload yok Der'deki foo çağırılır.
}

-> Eğer türetilmiş sınıfın function overload'a tabi olmasını istiyorsak using keyword'ünü ve Base sınıfını çözünürlük operandının sol operandı, overload edilmesi istenen fonksiyonun da sağ operandı olarak kullanabiliriz.

Ex:
class Base{
public:
  void foo(int);
  void foo(double);
};

class Der:public Base{
public:
  using Base::foo;
  void foo(long);
};
int main(){
  Der myDer;
  myDer.foo(1.2); //Base::foo(double)
  myDer.foo(1);// Base::foo(int)
  myDer.foo(12L); //Base::foo(long)
}

-> A sınıfı bir base class olsun, B sınıfı A'dan, C sınıfı da B'den türetilmiş olsun. C sınıfı açısından B'yi kast ettiğimizde "Direct Base Class" A'yı kast ettiğimizde  "Indirect Base Class" terimleri kullanılır.

-> İsim arama kuralları gereği, bir isim önce blokta sonra kapsayan blokta ardından türemiş sınıf tanımında sonra taban sınıf tanımında ve son olarak namespace'de yapılır.

-> Der bir türetilmiş sınıf olsun. Bir Der nesnesi hayata geldiğinde:
1. Önce Der içindeki Base class hayata gelir.
2. Sonra bildirim sırasıyla member object'ler hayata gelir.
3. Ardından akış Ders sınıfının ctor'unun ana bloğuna girer. Yani program akışı Der sınıfının ctor'unun ana bloğuna girmişse taban sınıf ve memberlar hayata gelmiş durumdadır.

-> Yine en son hayata gelen nesne ilk hayatı sona erecek olan nesnedir.

-> Eğer sınıfın special member function'unu derleyici implicitly declared edip default ederse fakat yazacağı koda da syntax hatası olursa default etmesi gereken ctor'u delete eder.

-> Eğer türemiş sınıfın ctor'unu biz yazarsak, taban sınıfın istenilen ctor'una çağrı yapmak için ctor initializer list ile taban sınıfın ctor'una çağrı yapmalıyız.

Ex:
#include <iostream>

class Base{ 
public:
  Base(double d){
    std::cout<<"Base (double d) d = " << d << '\n';
  }
  Base (int x, int y){
    std::cout<<"Base (int x, int y) x = " << x << "y = " << y<< '\n'; 
  }
};
class Der:public Base{
public:
  Der():Base{10,20}{
      std::cout<<"der def. ctor\n";
  }
  Der(double dval): Base(dval){}
};
int main(){
  Der myDer{2.3};
}

-> ctor initializer list ile yalnızca doğrudan taban sınıfa çağrı yapabiliriz. 

-> Eğer türemiş sınıf için copy ctor yazılıyorsa, türemiş sınıf nesnesi içindeki taban sınıf nesnesinin de yine copy ctor ile hayata gelmesi isteniyorsa copy ctor'da init listinde base class'ın copy ctor'una çağrı yapılmalıdır.

-> Tıpkı copy ctor'da olduğu gibi eğer türemiş nesne kullanıcı tarafından tanımlanıyorsa ve init list'de taban sınıfın move ctor'u çağırılmazsa, derleyici taban sınıfın default ctor'unu çağırır.

-> Bu kural move assgn. ve copy assgn.'da geçerlidir. Eğer türemiş sınıfta assgnment fonk. kullanıcı tarafından yazılmışsa bu sefer fonksiyon bloğu içinde "operator="  fonksiyonu ile base class'ın assgn. func.'ları dahil edilmelidir.

*/
  
