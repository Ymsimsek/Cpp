/*
-> "using" kelimesi kullanım alanlarından biri de taban sınıftaki bir ismi türetilen sınıfta görünür kılmaktır. 

Ex:
class Base{
public:  
  void func(int);
  void func(long);
};
class Der:public Base{
public:
  using Base::func;
  void func(double);
};
int main(){
  Der myDer;
  myDer.func(12); //void func(int) çağırılır.
}

-> Protected fonksiyonları client çağıramaz. Çünkü sınıfın protected bölümü türetilmiş sınıfın protected bölümüne eklenir. Türetilmiş sınıfın interface'ine taban sınıfın protected 
kısımındaki üyeyi katmak istersek using bildirimini kullanabiliriz. (örn. using Base::func;)

-> Using bildirimleriyle base sınıfın ctor'larını türetilmiş sınıf için de kullanabiliriz (Inherited Ctor). Ancak protected bölümünde bildirilen ctor'lar için geçerli değildir.(C++11)

*/ 
