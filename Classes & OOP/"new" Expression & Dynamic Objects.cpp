/*
New Expressions: Yalın bir nesne oluştururken new ifadesinden sonra gelen tür bir sınıf türüyse derleyici "void* operator new(std::size_t)" çağrısını yapar ve operator new fonksiyonuna
çağrılan nesnenin değeri kadar byte'lık yer ayırıyor onun adresi void* olarak döner. Ancak başarısız olursa exception throw eder. 

Kullanım Şekli:
  new myClass;
  new int;
  new double;

-> "new myClass;" çağrısından sonra derleyici "operator new" fonksiyonunu çağırır. Türün sizeof değerini argüman olarak fonksiyona gönderir. Yer ayırma başarılı olduğunda elde edilen bellek bloğunun adresi döndürülür.

-> Memory Leak: Fonksiyonun işi bittikten sonra elde ettiği bellek alanının geri verilmemesi durumudur.

-> Resource Leak: Örneğin bir nesne yaratıldıktan ve kullanıldıktan sonra destructor'un çağırılmayıp kaynakların geri verilmemesidir. 

Dinamik Nesnelerin Hayata Getirilişi ve Kullanımı:

-> new ifadesi kullanılarak dinamik nesne hayata getirilir.

Ex:
#include <iostream>
class myClass{
public:
  myClass(){
    std::cout<<"Default Ctor this= "<<this<<'\n';
  }
  ~myClass(){
    std::cout<<"Destructor this= "<<this<<'\n';
  }
  void foo(){}
  void bar(){}
};

int main(){
  myClass* p = new myClass;
  std::cout<<"p= "<<p<<'\n';

  (*p).foo(); //Bazı durumlar harici çok tercih edilmez.
  (*p).bar(); //Bazı durumlar harici çok tercih edilmez.

  p->foo();
  p->bar(); //nesne kullanımı
}

-> Nesnenin default ctor'u çağırılması için:
  myClass* p1 = new myClass;
  myClass* p2 = new myClass();
  myClass* p3 = new myClass{};

-> Parametreli ctor'a çağrı yapılacaksa: (class tanımında "myClass(int x, int y){}" ctor olduğunu varsayalım)
  myClass* p2 = new myClass(2,6);
  myClass* p3 = new myClass{5,7};

-> "delete p" ifadesi kullanıldığında derleyici delete operatörünün operandı olan pointer'ı kullanarak sınıfın destructor'unu çağırır. Destructor allocate edilen bellek bloğunu "void operator delete (void*)" fonksiyonunu kullanarak geri verir.

-> Artık üretimde new expression'u ile dinamik class kullanmak yerine smart pointerler kullanılır.

Array "new" Expression: new int[expression], şeklinde kullanılabilir. Expression'un değeri neyse o kadar sayıda nesneye sahip bir dinamik dizi oluşturulur.

Ex:
std::cout<<"Kaç tam sayı"
std::size_t n;
std::cin>>n;
int* p = new int[n];

for(std::size_t i{};i<n;i++)
  p[i]=i

delete[] p; // array delete

Ex:
myClass* p = new myClass[10];
delete[] p;

*/
