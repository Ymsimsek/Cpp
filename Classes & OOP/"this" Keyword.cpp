/*
"this" anahtar sözcüğü sadece sınıfın non-static üye fonksiyonları içerisinde kullanılır. Haricinde kullanım syntax hatası oluşturur.
"this" aynı zamanda bir pointer'dır. "this" hangi nesne için kullanılırsa o nesnenin adresini içerir. 

Ex:
class myClass{
public:
  void foo(){
    std::cout<<this<<'\n';
};
//in main
myClass m;
std::cout<<&m<<'\n';
m.foo();// output olarak m'nin adresi ve this'in değeri basılır. İkisinin değerinin de aynı olduğu görülür.

-> "this" pointer'ının oluşturduğu ifade PR value'dur. 

-> Non-static üye fonksiyon içerisinde "*this" kullanılırsa nesnenin kendisini belirtir.

-> "this" global fonksiyonu member function  içinde çağırırken nesneyi argüman geçmek için de kullanılabilir.

Ex:
void gfunc1(myClass* p){}
void gfunc2(myClass& r){}

void myClass::foo(){
  gfunc1(this);
  gfunc2(*this);
}

-> Bir üye fonksiyon içinde aslında fonksiyonun gizli parametre değişkeni bir adres veya bir pointer ve onu bir global fonksiyona göndereceksek
yani bu nesne hangi nesne için çağırıldıysa o nesnenin adresi veya kendisini global fonksiyona göndereceksek "this" kullanılır. 
Ya da üye fonksiyon nesnenin adresi veya kendisini döndürecekse "this" kullanılır. 

Ex:
class myClass{
public:
  int foo(){
    return *this;
  }
  int baz(){
    return *this;
  }
};
//in main

myClass m;
m.foo().baz();

*/

