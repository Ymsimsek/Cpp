/*

Pack Expansion: Derleyicinin belirli bağlamlar içerisinde argümanları virgüllerle ayrılmış listeye dönüştürmesidir.
Ex:
template <typename ...Ts>
void func(Ts ...args){
  foo(args...); //derleyici pack expansion'u aşağıdaki argümanların sıralı listesine dönüştürecek: foo(p1,p2,p3,p4)
} //Böylece üretilen kodda foo fonksiyonuna argüman olarak func argümanlarını gönderir
int main(){
  func(2,5,3.4,"ali");
}

Ex:
template <typename ...Ts>
void func(Ts ...args){
  foo(bar(args...)); //foo(bar(p1),bar(p2),...)
  }
int main(){
  func(2,5,3.4,"ali");
}


-> Tür parametre paketlerine de uygulanabilir. 

-> Fonksiyonun tüm parametrelerini değişken sayıda olsa dahi yine değişken sayıda olabilecek fonksiyona perfect forward etmek istersek:
Ex:
template <typename ...Ts>
void func(Ts&&...args);

template<typename ...Ts>
void foo(Ts&& ...args ){
  func(std::forward<Ts>(args)...); //func(std::forward<int>(p1),std::forward<int>(p2),std::forward<int>(p3));
  
}

int main(){
  int ival{};
  double dval;
  func(12,dval,ival)
}

-> Diziye ilk değer verirken kullanılabilir:
Ex:
template <typename ...Ts>
void func(Ts ... params){
  int a[]={params ...}; //int a[]={p1,p2,p3,p4}
}
int main(){
  func(1,5,7,9);
}

-> Kalıtımda kullanılabilir:
Ex:
class A{
public:
  void fa();
};
class B{
public:
  void fb();
};
class C{
public:
  void fc();
};
template<typename ...Ts>
class myClass : public Ts...{
};
int main(){
  myClass<A,B,C> m1; //Multiple inheritance yolu ile A,B,C'nin myClass sınıfından public inheritance yolu ile kalıtım yapılacak.
  m1.fa();
  m1.fb();
  m1.fc();
}

Ex:Ex:
class A{
public:
  void foo(int);
};
class B{
public:
  void foo(double);
};
class C{
public:
  void foo(long);
};
template<typename ...Ts>
class myClass : public Ts...{
  using Ts::foo...; //ambiguity'i kaldırıp her sınıf için bu fonksiyonu çağırmaya yarar.
};
int main(){
  myClass<A,B,C> m1; //Multiple inheritance yolu ile A,B,C'nin myClass sınıfından public inheritance yolu ile kalıtım yapılacak.
  m1.foo(12);
}

-> Recursive instantiation: Öyle bir yapıdır ki,  derleyici, fonksiyon template'inden argüman sayısı kadar instantiation yapacaktır.
Ex:
template<typename T, typename ...Ts>
void print(const T& t, const Ts ...args){
  print(args...); //3 kez çağrı yaptırılır. Base case olarak ayrı bir fonksiyon veya template yazılabilir.
}

int main(){
  print(1,2.3,"ali",4.5f)
}

Ex:
//Unary Right Fold:
template<typename ...Ts>
auto sum(Ts ...args){
  return (args+...); // p1+(p2+(p3+p4))
}

//Unary Left Fold:
template<typename ...Ts>
auto sum(Ts ...args){
  return (...+args);  //((p1+p2)+p3)+p4
}

int main(){
  sum(1,3,4,6);
}

*Variadic Templates*
    ->Recursive function instantiation
        ->static if
    -> init list

    -> Fold expression
        ->unary right fold
        ->unary left fold
        ->binary right fold
        ->binary left fold









*/
