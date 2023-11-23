/*
-> Copy Assignment bir special member function'dur. Operatör atama fonksiyonu kullanılır. "operator="

-> Sınıfın, non-static, inline, public üye fonksiyonu olmalıdır.

-> Bir sınıf nesnesi bir operatörün operandı olduğunda derleyici, bir fonksiyon çağrısını dönüştürüyorsa bu mekanizmada kullanılan fonksiyonları keyfi isimlendiremeyiz. 
İsimleri "operator" kelimesini ve hangi operatörün operandı olduğunda o sözcük çağırılacaksa o operatörün tokeni tarafından isim oluşturulur.

-> Copy assignment fonksiyonunun geri dönüş değeri vardır ve tanımlanırken sınıf türünden referans kullanılır. (Örn. myClass&)

-> C++'da atama operatörleri L value expression oluşturur.

-> Derleyicinin yazdığı atama operatör fonksiyonu geri dönüş değeri "myClass&" ve "*this"dir.

-> a=b gibi bir atama yapıldığında a ve b sınıf nesne değilse;
a.operator=(b) gerçekleşir. Bu ifade de atama yapılmış "a"nın kendisidir.
Diyelim ki foo() isimli bir fonksiyon varsa;

  "a.operator=(b).foo()" şeklinde çağrı yapılır ve

  a.operator=(b);
  a.foo();

  ifadesine eşittir. 

-> Copy assignment'in parametresi aynen copy ctor'da olduğu gibi "const myClass& other" şeklindedir.

-> Sonuç olarak derleyicinin yazdığı copy assignment taslağı şu şekildedir:

public:
  myClass& operator=(const myClass& other){
    //..
    ax=other.ax;
    bx=other.bx;
    cx=other.cx;
    return *this;
  }
private:
  A ax;
  B bx;
  C cx;

-> Cctor'da olduğu gibi derleyicinin yazdığı copy assignment fonksiyonunun da undefined behaviour oluşturacağı senaryolar vardır ve pointer kullanılırken karşılaşılma olasılığı yüksektir.

Destructor -> Releases Sources
Copy Ctor -> Deep Copy
Copy Assignment -> Deep Copy and Release Sources

-> Self assignment (x=x) bir sınıf nesnesi için yapılırsa copy assignment devreye girer ve x'in memory'sini free yapar ve sonuç olarak adresi dangling pointer haline gelir, undefined behaviour oluşur. Önlem olarak;
if(this==&other)
  return *this;
ifadesi kullanılırsa self assignment'da oluşan hata giderilmiş olur. 

Self assignment yaşanabilecek senaryolardan biri:

void foo(T& t, const T* p){
  t=*p
}
void foo(T* p1, T* p2){
  *p1=*p2;
}

*/

