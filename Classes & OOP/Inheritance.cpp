/*
Inheritance: Türkçe'ye kalıtım olarak geçen bir kavramdır. Nesne yönelimli programlamanın bir aracı olarak görülse de C++'da bundan fazlasıdır. 

-> Kalıtımda adeta kaynak görevini yüklenen bir sınıf vardır. Biz o sınıftan faydalanarak, o sınıfın public interface'ini kendi interface'ine katan böylece o sınıf türündenmişcesine kendi nesnelerinde kullanılabilecek
bir sınıf oluşturabiliriz. Bu kaynak olarak kullanılan sınıfa "parent class" veya " super class" denilebilir. Aynı özelliklere sahip ancak diğer özellikleri de olan kalıtım yoluyla oluşturulan
sınıf ise "child class" veya "subclass" olarak adlandırılır. 
Örn:
class Animal -> super class
class Zebra -> sub class

-> C++ özelinde parent class'a base class, child class'a ise derived class denir. Bu işe de derivation denir. ( Class x is derived from class y)

-> C++'da 3 ayrı kalıtım biçimi vardır.
- Public Inheritance
- Private Inheritance
- Protected Inheritance

-> Sınıfların kalıtım seviyesi taban sınıftan kalıtılan sınıfların da kalıtımının yapılmasına veya yapılmamasına göre adlandırılır. Eğer birçok türetilmiş sınıf olmasına rağmen sadece base class kalıtılmış ise
one-level, kalıtılan classlar da kalıtım yapılmışsa da multi-level inheritance adı verilir.

-> Bir sınıf, tek bir kalıtım işlemiyle birden fazla sınıfa interface'ini alabiliyorsa buna multiple inheritance denir. Yani birden fazla tavan sınıftan tek kalıtım işleviyle interface almasıdır.

-> Kalıtım yapılabilmesi için base class'ın complete type olması gereklidir. 

-> C++'da kalıtım syntax'ı şöyledir;

class Base{};
class Derived:public Base{};//Public inheritance
class Derived:private Base{};//Private inheritance
class Derived:protected Base{};//Protected inheritance

-> Eğer public, private, protected kelimelerini kullanılmaz ise default kalıtım private olur.

-> Struct'larda ise durum class'ların tam tersi olarak default kalıtım public inheritance olur. 

-> Türemiş sınıftan taban sınıfa olan dönüşümü "up-casting", tabandan türetilmiş sınıfa yapılan dönüşüm ise "down-casting" adını alır. 

-> Parametresi taban sınıftan olan fonksiyona türetilmiş sınıf argüman gönderebilir. 

-> Her ne kadar geçerli olsa da taban sınıfı nesne ile türetilmiş sınıf nesne birbirine atanmamalıdır.
Mercedes m;
Car c;
c=m;// Yapılmamalıdır.

-> Taban ve türemiş sınıfta bildirilen aynı isimli fonksiyonlar overload değillerdir. Taban sınıf ve türemiş sınıftaki isimlerin scope'ları farklıdır.

Ex:                                                                                                                                                                                                                        */
class Car{
public:
  void start();
  void run();
  void stop();
};
class Mercedes: public Car{};
class Audi: public Car{};
void car_game(Car*p);
void car_race(Car& r1, Car& r2);
int main(){
  Mercedes m;
  Audi a;
  car_game(&m);
  car_race(m,a);
}
