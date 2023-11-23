/*
Copy Elision: Kopyalamanın elimine edilmesi durumudur. Normalde contexte bir kopyalama yapılması gerekirken örneğin sınıfın kopyalayan kurucu işlevinin çağırılması gerekirken kopyalamanın yapılmamasıdır.
Kopyalama yerine taşıma yapıldığı anlamına gelmez. Copy elision denildiğinde kastedilen ne copy ctor ne de move ctor'un çağırılmamasıdır. 

Ex:
void foo(myClass x){
  std::cout<< "foo()\n";
}
int main(){
  foo(myClass{});
}

-> Yukarıdaki örnekte myClass nesnesinin yukarıda tanımlandığını varsayalım. Normalde derleyici geçici nesne için default ctor'u çağırılmalı, fonksiyonun parametre değişkeni (call by value)
değerini "foo(myClass{});" ifadesinden değerlendirdiği için move ctor çağırılmalı move ctor yoksa da copy ctor çağırılmalıydı. Ancak program çağırıldığında bir kez default ctor ve destructor çağırılıyor. 
Örnekte standartı C++11 standartına düşürüldüğünde değişim olmuyor. Eski C++'da bu bir compiler optimizasyon durumuydu.

-> Kodu C++17 öncesinde optimizasyon kapalı iken çalıştırdığımızda gerçekten de move ctor veya copy ctor'un çağırıldığını görebilirdik.

-> Bir fonksiyon parametresini sınıf türünden yaparsak ve fonksiyonu sınıf türünden PR value expression ile çağırırsak bu durumda, C++17 öncesinde derleyiciler tipik olarak optimizasyon yaparak önce geçici 
nesneyi oluşturup anlamsız bir şekilde onu parametreye kopyalamak yerine doğrudan parametre değişkeni olarak oluşturuyordu. Ancak C++17 öncesinde bu durum mecburi değildi. Sınıfın copy ctor'u delete edildiğinde bu 
durum syntax hatası oluşturuyordu. 

-> C++17 ve sonrasında, copy ctor delete edilmiş olsa dahi syntax hatası olmadığını görüyor. C++17 yeni bir tanım getirdi. C++17 öncesi PR value olan sınıf nesneleri doğrudan nesne statüsündeydi. Yani derleyici
ilgili ctor'u çağırmak zorundaydı. C++17'de yapılan değişikliğe göre PR value expression olan ifadeler doğrudan bir sınıf nesnesi değil ve sınıf nesnesi olabilmesi için bazı senaryoların gerçekleşmesi gereklidir.
Bu senaryoların "temporary materialization" denir.

Ex:
int main(){
  foo(myClass{myClass{myClass{}}});
}

-> Yukarıdaki myClass argümanlarının hiçbiri birer nesne değildir. Ancak hedeflerini bulduklarında birer nesne olacaklardır. Hedeflerini bulmaları için;
- Bir nesneye ilk değer verilebilirler.
- Bir atama yapılabilir.
- Bir referansa bağlanabilir.

-> Yukarıdaki örnekte temporary materialization yapılmadığı için yine bir kez default ctor ve destructor çağırılacaktır. 

*/
