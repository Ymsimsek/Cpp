/*
Operator Overloading: C dilinde bir yapı nesnesi sadece atama operatörünün, sizeof operatörünün, nokta operatörünün ve adres operatörünün operandı olabilirler. Fakat C++ dilinde sınıf ve enum nesnelerinin,
diğer operatörlerin operandı olmaları mümkündür. Bu durumda derleyici bir operatörün operandı olan sınıf nesnesi ifadesini eğer bildirilmiş uygun bir fonksiyon varsa o fonksiyona yapılan çağrıya dönüştürür.
İşte bu mekanizmaya operatör overloading denir. Yani operator overloading, fonksiyon çağrısının bir başka yolu olarak da görülebilir.

-> Bu mekanizma, operatörlerin aritmetik ve pointer türleri için verdiği çağrışımdan sınıf mekanizmaları için de faydalanabilmemizi sağlar. 

-> Bu kurallara uygun olarak yazılmış fonksiyonlara "operator function" denir. Bu fonksiyon öyle bir fonksiyondur ki, bir sınıf nesnesinin bir operatörünün operandı olması durumunda derleyici tarafından
örtülü olarak çağırılabilen fonksiyondur.

-> Operator fonksiyonları, free function veya bir sınıfın non-static member function'u olmak zorundadır.

-> Eğer sezgisel olarak mantıklı ifadeler kullanılacaksa, operator overloading tercih edilmelidir. Örneğin; 
Date myDate{31,12,2023}; 
myDate++;

-> Operator overloading, derleme zamanında yapılır. Run-time'a bir işlem maliyeti yaratmaz.

-> Operator fonksiyonları, keyfi isimlendirilemezler ve "operator" kelimesi kullanılır. "operator" kelimesinden sonra ise hangi operatörü overload ediyorsa o operatörün tokeni kullanılır.(operator+, operator!,.. vs.)

-> Olmayan bir operatör overload edilemez. Yani C++'ın operatör kümesindeki operatörler kullanılabilir.

-> Operator overloading kullanabilmek için operatörün operandlarından en az birinin user-defined type olması gerekir. (Bir sınıf veya enum).

-> Her operatör overload edilemez. Dil kuralları bazı operatörlerin overload edilmesine izin vermez;
- "." operatörü
- "::" operatörü
- "?" operatörü
- "sizeof" operatörü
- "".*" operatörü
- "typeid" operatörü

-> Bazı operatörler yalnızca member operator function olarak tanımlanabilirler.
- Function call operator, "()"
- Subscript operator, "a[b]"
- Assignment operator
- Tür dönüştürme operatörü 
- Arrow operator "->"

-> Bir istisna hariç operatör fonksiyonları default argument mekanizmasından faydalanamazlar.

-> Bu mekanizmada operatör öncelik seviyesi ve yönü değiştirilemez.

-> Bütün operatör fonksiyonları istisnasız bir şekilde isimleriyle çağırılabilirler. 
- a,b class olmask üzere "operator+(a,b)" çağırılabilir ancak tercih edilmeyebilir.

-> Bu mekanizma ile operatörün "artiy"'si değiştirilemez. (Binary/Unary)
- a>b (Binary)
- !a (Unary)

-> Eğer binary operator fonksiyonu, global operator fonksiyonu olarak overload edersek, this pointeri olmadığından ve fonksiyon çağrısına dönüştürülecekse
örneğin, a>b'de operator> çağırılacak ve a ve b operator>() fonksiyonuna argüman olarak geçilecek. Derleyici a>b'yi operator>(a.b) olarak çağırır ve ">" operatörü
tek parametreli olamaz.

-> Member operator function durumunda class'ın this pointeri vardır. a>b ifadesini ele alalım. myClass sınıfına dahil olduğunu varsayalım. Derleyici, "myClass::operator>"
çağrısını yapar. Bu durumda her zaman this pointerii sol operandı olan nesne için kullanılacak. Yani a.operator>(b) şeklinde çağrı yapılır.
- x/y => x.operator/(y)

-> Bu durumda binary operatörü overload eden, sınıfın non-static üye fonksiyonu olan operatör ifadelerinin tek parametre değişkeni olmalıdır.

-> Eğer unary operator overload edilecekse operator fonksiyonunun parametre değişkeni olmaz.
- !x => x.operator!()

Ex:
int main(){
  Nec n1,n2,n3,n4,n5; //Nec bir sınıf
  auto b= n1*n2+n3/n4>n5;
}
//Global Operatör Fonksiyonları:
Nec operator*(const Nec&, const Nec&);
Nec operator/(const Nec&, const Nec&);
Nec operator+(const Nec&, const Nec&);
bool operator>(const Nec&, const Nec&);
//Çağrı:
//operator>(operator+(operator*(n1,n2),operator/(n3,n4)),n5)

Ex:
class Nec{
public:
  Nec operator*(const Nec&)const;
  Nec operator/(const Nec&)const;
  Nec operator+(const Nec&)const;
  Nec operator>(const Nec&)const;
};

int main(){
  Nec n1,n2,n3,n4,n5; 
  auto b= n1*n2+n3/n4>n5;
  bool b2=n1.operator*(n2).operator+(n3.operator/(n4)).operator(n5);
  // b ve b2 aynı
}

-> Bazı operatörlerin binary ve unary görevleri farklıdır.
- "+x", "a+b"
- "-x", "a-b"
- "a*b", "*a"
- "a&b", "&a"

-> Operatör fonksiyonlarının overload edilmesi çok tipik bir durumdur.

-> Member operator functions kullanılırken ve binary opertörler söz konusuysa, her zaman sol operatörde olan nesne için çağırılır. Örneğin myClass+5 legal iken
5+ myClass legal olmaz. Bu sebeple global operatör fonksiyonlarına gereksinim duyarız. 

-> Eğer operandı bir sınıf, diğer operandı ise başka bir sınıf türünden bir ifade varsa ve biz de os ınıfın kodlarını yazan tarafta değilsek, global operatör fonksiyonu
oluşturarak kullanabiliriz.

Ex:
#include <iostream>

class Matrix{
//... Some code
};

std::ostream& operator<<(std::ostream& os, const Matrix&);

int main(){
  using namespace std;
  int ival{10};

  cout<<ival;
  cout.operator<<(ival);
  Matrix m;
  cout<< m<< ival;
}

-> Operatör fonksiyonlarının geri dönüş değeri türü class'ın çevireceği mantıklı türle alakalıdır. Her tür döndürülse syntax hatası olmasa dahi problem domaininde bir karşılığı olmalıdır.

-> Operatör fonksiyonları nesne üzerinde işlem yapmayıp değiştirmeyecekse const ifadesi eklenmelilidir.
Matrix operator*(const Matrix&)const;
Matrix m1,m2;
m1.operator*(m2);

-> Primitive türlerde ifadelerin, value kategorisi ne ise, nadir istisnalar haricinde operator overloading mekanizmasında da sınıf türleri için aynı ifadelerin value kategorisi de eşdeğer olmalıdır.

-> C++20'de "!=" operatörü "==" operatörüyle overload edebiliriz.

-> Özel bazı durumlar söz konusu değilse, binary simetrik operatörler, global operatör fonksiyonu olarak overload edilirler.

-> Prefix ve postfix, increment-decrement operatörleri overload edilirken:
-T& operator++();//Prefix
-T operator++(int);//Postfix
-T& operator--();//Prefix
-T operator--(int);//Postfix

-> Atama operatörünün ürettiği değer, nesneye atanan değerdir. O sebeple, L value expr. ve operator fonksiyonu tanımlanırken "T& operator=" şeklinde yazılır.


Kod örnekleri 18. ve 19. ders videolarında bulunmaktadır.

*/
