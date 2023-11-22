/*
Classes: Classes are user-defined types.

  
Class Definition Syntax:

class myClass{
        //class scope
int x; // class member
};


Class Members:

-> Data Members:
- Static Data Members
- Non-Static Data Members

-> Member Functions:
- Static Member Functions
- Non-Static Member Functions

-> Member Types/ Type Members/ Nested Types


Member Selection Operators: ".", "->"


Name Lookup: Bir ismin class scope'ta aranması için 3 tipik senaryo vardır. Bu senaryolara nitelenmiş isim kullanımı denir.

- .x
- ->y
- ::a

Yukarıdaki a,x ve y class scope'ta aranır. 

Kullanım Şekilleri:

- classname.x
- ptr->y
- classname::a 

!!Class member olmadan tanımlanan classlara empty class adı verilir.  

class myClass{
  int mx; //non-static data member
};

Access Control Keywords:
- Public
- Private 
- Protected 

Access kontrol anahtar sözcükleri; üye fonksiyonları, data üyelerini, veya üye türlerini niteleyebilir.

Public Members: Client ve sınıflara açık (herkese).
Private Members: Sadece tanımlandığı sınıfa açık.
Protected Members: Sınıfına ve kalıtım edilen sınıflara açık.

-> Class tanımlanırken default olarak private'dır. Public veya protected member'lar için ek belirtme yapılır. Private kullanmak da dil içinde legaldir.

Ex:
class Data{
public:
  int x;
private:
  int y;
protected:
  int z;
};

-> Struct'lar default olarak public access'e sahiptir. 

-> Bir sınıfın public interface'i sınıfın public öğreleri ve sınıfın başlık dosyasında bildirilen global varlıkları içerir.

-> Public, private ve protected interface'ler birer kapsam belirtmez.

-> Sınıfların üye fonksiyon bildirimlerinde redeclaration yapılamaz. Yeniden bildirilemezler. Function overloading mümkündür.

-> Member'ın private veya public olması overloading'i etkilemez.

Ex:
class Nec{
private:
  int foo(int);
public:
  int foo(float);
};
//in main
  Nec mynec;
  mynec.foo(12); // Access control, overload resolution'dan sonra yapılır. Derleyici private fonksiyonu exact match ile seçer ancak access control ardından izin vermez. Erişim kontrolü hatası oluşur.


-> Bir işlem yapılırken sıralama şu şekilde yapılır: name lookup -> context control -> access control.

-> Üye fonksiyonlarda isim arama yapılırken, nitelenmemiş isim kullanıldığı durumlarda önce blokta, sonra scope'ta ardından globalde aranır.

Ex:
class Nec{
public:
 void foo();
 int x; 
};
//in main
  Nec mynec;
  mynec.Nec::x; // Legaldir ve mynec.x'e eşittir.


-> Üye fonksiyon globalde tanımlanırken "inline" keyword'ü ile tanımlanmalıdır. Sınıfın içerisinde tanımlandığında implicitly inline olur. 

Ex:
class Nec{
public:
  void set(int x, int y){ // implicitly inline
    mx{x};
    my{y};
private:
  int mx,my;
 };

Ex:
class Nec{
public:
  void set(int x, int y);
};

void Nec::set(int x, int y){ // İllegal, inline keyword'ü gerekli
  mx{x};
  my{y};
}

-> inline eklenmesinin sebebi ODR'ı ihlal etmemektir. 

-> constexpr fonksiyon olsaydı, inline'a gerek kalmazdı.

-> non-static member function çağırılırken nesnenin adresi ile çağırıldığı için çağrı yapılırken nesnesiz çağırılamazlar. 

Class Declaration: (Forward Declaration)

-> Sınıf nesnesinin non-static data memberları arttıkça hafızada ayrılan alanları artar. 

-> Sınıf içindeki non-static member functions sınıf nesnesinin kaplayacağı yeri arttırmaz.

-> Class definition proje içinde birden fazla kaynak dosyasında token by token aynı olursa ODR çiğnenmez. Class definition'u başlık dosyasına koyarsak proje içindeki cpp'lerde include edersek ODR doğal olarak çiğnenmez.




*/
