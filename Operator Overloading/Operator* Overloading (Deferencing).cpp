/*
-> *p ifadesi L value'dur. Bu sebeple içerik operatörüyle oluşturulan ifade, içerik operatörünün operandı bir sınıf türünden ifadeyse o fonksiyona çağrıya dönüştürülür. 
Bu ifadenin L value expr. olması için fonksiyonun geri dönüş türünün L value ref. olması gerekir. 

-> Sınıfın üye fonksiyonu olarak overload edildiğinde fonksiyonun hiç parametresi olmamalıdır. Çünkü "*ptr" ifadesi "ptr.operator*()" fonksiyonuna çağrılardır.

-> Pointerlar için elde edilen çağrışımın sınıf türleri için de kullanılabilmesi için, intuitive olması için, yine bu operatörü overload eden sınıfın pointer-like
bir sınıf olması gerekir. Yani, ya iterator ya da dinamik ömürlü nesnelerin örneğin hayatını konrol etmek için kullanılacak bir sınıf olması gerekir.

-> Kullanımını görmek için bir pointer-like sınıfını implemente ederek "*" operatörünü overload'una örnek verelim;

#include <iostream>
int g{24};
class myClass{
public:
  int& operator*(){
  std::cout<<"operator* this ="<<this<<'\n';
  return g;
  }
};

int main(){
  using namespace std;
  myClass m;
  cout<<"&m="<< &m<<'\n';
  *m=99;
  cout<<"g="<<g<<'\n';
}

-> Output'ta &m iile operator* this değerleri aynıdır ve g 99'dur.

-> Örnekteki "*m" yerine "m.operator*()=99" yazılsaydı bir değişiklik olmayacaktı.

-> Örnekte "m" bir işaretçi değildir. Bir sınıf türünden değişkendir. Böyle sınıflara pointer-like class denir. 

*/

