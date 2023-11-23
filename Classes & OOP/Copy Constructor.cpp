/*
Copy Constructor: ( cc, copyctor, cctor)

-> Eğer bir sınıf nesnesi hayata değerini aynı türden bir başka sınıf nesnesinden alarak geliyor ise yapılan fonksiyondur.

-> Bir fonksiyon parametre değişkeni tanım içerisinde kullanılmayacaksa isimlendirilmemelidir. 

-> Bir sınıf nesnesini başka bir sınıf nesnesine eşitlenirken veya bir fonksiyona sınıf nesnesi argüman olarak geçilirken copy ctor çağırılır.

-> Used Declared Copy Ctor:

Nec(const Nec& r){}

Ex: 

class Nec {
  //...  
};

int main(){
  Nec x; //Default ctor 
  Nec n1 = x; //Copy Ctor
  Nec n2(x); //Copy Ctor
  Nec n3{x}; //Copy Ctor
  auto n4=x; //Copy Ctor
  auto n5(x); //Copy Ctor
  auto n6{x}; //Copy Ctor
}

-> Eğer programcı copy ctor'u user-declared yapmazsa derleyici tarafından implicitly declare eder.

-> Derleyicinin implicitly tanımladığı copy ctor, sınıfın non-static, inline ve public olurlar.

Copy Constructor Implicitly Declaration Taslağı:

class A{};
class B{};
class C{};

class myClass{
public:
  myClass(const myClass& other):ax(other.ax),bx(other.bx),cx(other.cx){}
private:
  A ax;
  B bx;
  C cx;
};

-> Bazı durumlarda default copy ctor çağırıldığında kaynak yerine adresi kopyalayıp, kopyalanan nesneyi değiştirme yeteneğine sahip olur bu istenmeyen bir durumdur. Kopya nesne silindiğinde
kopyalanan kaynak da silineceğinden undefined behaviour oluşur.

-> Kaynağı silinen nesnenin destructoru çağırılınca çöp değeri free fonksiyonuna göndereceğinden hata oluşur ve adı double deletion'dur. 

-> Copy ctor yazılırken genelde derleyicinin yazdığı gibi yazılır. Veri yapılarını implemente etmek için kullanılabilir.

*/
