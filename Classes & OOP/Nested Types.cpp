/*
Nested Types: "class" kelimesiyle tanımladığımız sınıfların içerisinde tanımladığımız, class, enum, typedef vs. gibi belirtebildiğimiz tür içi tür anlamına gelen kavramdır.

-> Sınıf tanımlarının içerisinde başka bir sınıf, enum türleri, typedef bildirimleri ve C++20 ile eklenen "using value_typedef=int" gibi using bildirimi ile yapılabilen tür bildirimleri nested types'dır.

-> Nested Türlerin scope'u, class scope'tur. Bildirim ve çağrılar çözünürlük operatörü yardımıyla yapılabilir.

Ex:
class myClass{ //enclosing class
public:  
  typedef int value_type;
  using value_type1=int;
  enum color {Blue, Red, Green};
  class Nec{}; //Nested Class
};

int main(){
  myClass::value_type x;
  myClass::color myColor;
  myClass::Red;
}

-> Enclosing class'lar, nested class'ların private bölümlerine erişemezler. 

*/
