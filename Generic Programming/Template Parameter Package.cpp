/*
Template Parametre Paketi (Template Parameter Package): Derleyicinin bu mekanizma kullanıldığında template'de kaç tane parametre olduğunu
kullanım biçiminden anlamasıdır. 
Ex:
template<typename ...TS> // Genel syntax bu şekildedir TS bir isimdir. 
class myClass{};
int main(){
  myClass<int, double, long> a;
}

template<typename ...Args > // Böyle de olabilir
class myClass{};
int main(){
  myClass<int, double> a;
}

->Fonksiyon, sınıf, değişken ve tür eş şablonları bu şekilde kullanılabilir.

Ex:
template<typename ...TS> 
void func();  

int main(){
  func<int>()
  func<int, int>() 
  func<int,int,long>()
}

-> sizeof operatörünün burada kullanımı farklıdır ve ürettiği değer paketteki öğe sayısını bildirir.
Ex:
template<int ... VALS>
class myClass{
public:
  static constexpr auto x = sizeof...(VALS);
};

int main(){
  constexpr auto val= myClass<1,3,7>::x; //Val=3
  constexpr auto val2= myClass<1,3,7,8>::x; //Val=4
}

-> Fonksiyon şablonlarında şablon parametre paketi kullanımı sınıf şablonlarından farklıdır. 
Ex:
template<typename ...Ts> //Template parametre paketi
void func(Ts ...args){ //Fonksiyon parametre paketi, bu şekilde kullanıldığında derleyici, fonksiyon parametrelerini virgüllerle ayrılan 
//bir nesneye dönüştürür. Yani template parametre paketinde kaç parametre varsa bu fonksiyonun da o kadar da parametre değişkeni olduğunu söyler.
}

int main(){
  func(1,2.3,45L); // Fonksiyonun parametre paketinde 3 parametre vardır ve template parametre paketinde de 3 parametre vardır. 
  //Bu örnekte func şunu temsil ediyor: void func<int,double,long>(int,double,long).
}
*/
