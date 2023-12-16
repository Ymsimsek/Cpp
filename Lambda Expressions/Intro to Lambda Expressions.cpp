/*
-> Derleyici lambda ifadelerini gördüğünde bir class definition yapar ve ifadenin kendisini de tanımladığı sınıf türünden bir geçici nesneye
dönüştürür. Lambda expression kullanılan yerde aslında bir PR value türünden nesne, geçici nesne, kullanılmış olur.

-> Derleyiciye sınıf kodu yazdırmanın bir yoludur. 

Genel Syntax:
[ ]() {code} 

[]: Lambda introducer olarak adlandırılır. Derleyici lambda ifadesiyle karşılaştığını bu köşeli parantezden anlar. Duruma göre köşeli parantezin
içi boş bırakılabilindiği gibi içine bir takım ifadeler de yazılabiliyor. İçine yazılan ifadelere lambda captures denir.

(): Derleyicinin yazdığı sınıfa derleyici bir fonksiyon çağrı operatör fonksiyonu da yazar. Bu parantez fonksiyon çağrı operatör fonksiyonun parametre
parantezidir. Bu fonksiyonun parametre değişkenlerine sahip olmasını istersek normal bir fonksiyonda olduğu gibi içine ekleme yapabiliriz. 

{}: Derleyicinin yazacağı fonksiyon çağrı operator fonksiyonunun ana bloğudur.

Ex:
//Aşağıdaki lambda ifadesi karşılığı derleyici şu şekilde bir sınıf tanımı yapıyor, class isimlendirme rastgele yapılıyor.:
class xyz323_95ds{
public:
  void operator()()const{ //Default olarak const tanımlanır.
  
  }  
  
}
int main(){  
  [](){}(); //kod çalışır. en sağdaki parantez fonksiyon çağrı operatörü
  //Görünmese de aslında yapılan çağrı şu şekilde oluyor: xyz323_95ds{}();
}

Specifier Kullanımı: Fonksiyon parametre parantezinden sonra eklenip bazı özellikleri sağlayan specifierler kullanılabilir.C++23 öncesi specifier 
kullanımı olduğunda parametre değişkeni olmasa dahi parametre parantezini koymak zorunluydu. Kullanılabilecek specifierlerden bazıları aşağıdaki
gibidir:

[ ]()constexpr{code}
[ ]()noexcept{code}
[ ]()mutable{code}
[ ]()->type{code}

C++23 ile: []{}(), şeklinde parametre yoksa parametre parantezi yazılmaması syntax hatası değil.

-> Fonksiyon ana bloğu içerisine bir return statement yazılırsa, derleyici yazacağı fonksiyon çağrı operator fonksiyonunun geri dönüş değeri türünü
return ifadesinden çıkarım yoluyla elde eder. 

Ex:
class xyz1231{
public:
  int operator()(int x)const{ //x*x, int olduğu için geri dönüş türü int oldu. int x parametre paranteziyle verildi. const default olarak geldi. 
    return x*x;
  }
}

int main(){
  [](int x){return x*x;}
}

-> auto type deduction'la oluşturulan geçici nesneyi, isimlendirilmiş nesne haline getirebiliriz. Bazı durumlarda, ya bu nesneyi daha sonra kullanmak 
için ya da birden fazla yerde kullanmak için isimlendirme yapabiliriz. 

Ex:
int main(){
  auto f= [](int x){return x*x;} 
  std::cout<< f(2)<<'\n'; //f bir closure object'tir. fonksiyon cağrı operatör fonksiyonu overload edildiği için fonksiyon çağrısı yapabilir. 
}

-> Sıklıkla karşımıza çıkacak biçim lambda ifadesini isimlendirmeden bir fonksiyon şablonuna argüman olarak göndermektir. 

Ex:
template<typename F>
void func(F f){
  auto val = f(12); //Burada da parametre değişkeni olan sınıf nesnesi için fonksiyon çağrı operator fonksiyonu çağırılacak. 

}

int main(){
  func([](int a){return a*a + 34; }); //fonksiyona pr value nesne ile çağrı yapıyoruz. Template argument deduction yapılıyor. Derleyiciye, parametresi
  //bir sınıf türünden olan fonksiyon yazdırmış olup aynı şekilde bir sınıf argümanıyla çağrı yapmış olacağız. 
}

-> Yukarıdaki kodlar inline olarak açılacak ve optimizasyonla çok basit bir assembly koduna dönüştürülecek. 

-> Çoğu algoritma fonksiyonları bir parametrelerine bir callable istiyorlar. Lambda ifadesini callable olarak argüman olarak geçtiğimizde derleyicinin
yazdığı fonksiyonun parametrelerinden birinin  aslında derleyicinin yazdığı sınıf türünden, closure type, olmasını sağlıyoruz.

Ex:
#include "nutility.h" //Kurs amaçları içinde containerlere eleman sağlayıp container içeriklerini hızlıca yazdırabildiğimiz bir başlık dosyası 
#include <algorithm>
#include <vector>
#include <string>

int main(){
  using namespace std;

  vector<string> svec;
  rfill(svec,100,rname); //nutility.h ile geldi, svec'i rastgele 100 stringle dolduruyor.
  print(svec);//nutility.h ile eklendi vector elemanlarını yazdırıyor.

  count_if(svec.begin(),svec.end(),[](const string& s){return s.length()==7;}); //Derleyici svec.begin() ve svec.end() parametrelerini lambda ifadesine gönderiyor.  
  //vector içerisinde uzunluğu 7 olan stringleri sayacak
}

-> Lambda ifadesinin yazıldığı yerde görünür durumda olan statik ömürlü nesneleri doğrudan lambda function içinde kullanabiliriz. Ancak otomatik ömürlü
nesneleri kullanamayız, syntax hatası oluşur. 

Ex:
int main(){

  auto inputC=[](int x){std::cout<<x<<'\n'}; //cout'un global bir değişken olduğuna dikkat edelim. 

  inputC(35); //ekrana 35 basılır. 

}

-> Otomatik ömürlü değişkeni lambda ifadelerinde kullanabilmek için capture clause mekanizmasını kullanabiliriz. Lambda ifadesinin içine otomatik
ömürlü değişkeni yerleştirirsek derleyiciye sınıfa değişken türünden bir veri elemanı koyup onu scope'taki ifadeyle initialize etmesini söyleriz. 
[x] : capture clause, x'in kendisi değil kopyası kullanılacaktır. 

Ex:
int main(){
  int x=5; 
  [x](){};
}

-> Derleyicinin yazdığı fonksiyon bir const üye fonksiyondur yani {} içerisinde yazdığımız ifade ile lambda ifadesindeki otomatik ömürlü değişken 
için kopyalanan veri elemanını specifier kullanmadan değiştiremeyiz. 

Ex:
int main(){
  int x=5; 
  auto f= [x](){++x};//illegal
}

-> mutable specifier ile default olarak const bildirilen lambda ifadesinin function call operator fonksiyonunu derleyicinin const olarak yazmamasını
söyleriz. Böylelikle otomatik ömürlü nesnenin veri elemanı kopyası blok içinde değiştirilebilir hale gelir. 

Ex:
int main(){
  int x=5; 
  auto f= [x]()mutable{++x};//legal
}

Ex:
int main(){
  using namespace std;

  string str{"tamer dundar"};

  auto f = [str]()mutable{str[0]='T';}
}

-> Birden fazla değişken varsa ve kullanılmak isteniyorsa yine capture işleminde değişkenleri virgüllerle ayırarak kullanabiliriz.

Ex:
int main(){
  using namespace std;

  int x{3},y{5},z{9};

  auto f = [x,y,z](int a){return a*(x+y+z);};
}

-> Global veya statik değişkenler, capture edilmeden kullanılmak zorundadır. 

Ex:
int g=5;
int main(){
  using namespace std;

  int x{3},y{5},z{9};

  auto f = [x,y,z,g](int a){return a*(x+y+z+g);}; //Syntax hatası
}

Ex:
int g=5;
int main(){
  using namespace std;

  int x{3},y{5},z{9};

  auto f = [x,y,z](int a){return a*(x+y+z+g);}; //Legal 
}

-> Görünür durumda olan isimlerin hepsini kullanma hakkı elde etmek için lambda ifadesini şu şekilde kullanabiliriz: [=] (capture all by copy) 
Ex:
int main(){
  using namespace std;

  int x{3},y{5},z{9};

  auto f = [=](int a){return a*(x+y+z);}; //Legal 
}

-> Derleyicinin lambda ifadesi için yazdığı sınıfta, sınıfın veri elemanının referans olmasını sağlamak için [] içine & deklaratörü ile otomatik ömürlü
değişkeni yazabiliriz.

Ex:
int main(){
  int a = 67;
  [&a](){++a;}(); //mutable gerek yok sınıf elemanını değil bağlı olduğu eleman değişir. 
  cout<<a; //68
}

Ex:
int main(){
  int a{67},b{23},c{53};
  double d{23.4};

  auto f = [=,&d](){}; //d hariç her değişkeni sınıfın içindeki yerel elemana kopyaladı d'yi referans olarak ekledi.

  //auto f=[&,a](){}; a hariç her öğeyi referansla capture et, a yı elemana kopyala
}

-> Bazı durumlarda geri dönüş değeri türünü derleyiciye çıkarım yaptırmadan kendimizin belirlemesi gerekebilir. Bunun syntax'ı ise :
auto f = [](int x)-> double{return x*x;}; //-> double, trailing return type .

-> Trailing return type kullanmayı zorunlu kılan bazı başka senaryolar da vardır. 
Ex:
int main(){
  auto f = [](int x){
    if(x>10){
      return x*x;   //burada int
    }
    else{
      return x*5.6;  //burada double, ambiguity hatası oluşur. 
    }
  }
}

-> Lambda ifadelerinde derleyiciye yazdırılan function call operator function'u bir function template olarak yazdırabiliriz. Bunu parametre
için auto keyword'ünü kullanarak yapabiliriz.

Ex:
int main(){
  auto f=[](auto x){return x*x;}; //p
}

-> Yazılan sınıf şuna dönüşüyor:
class xyz_231{
public:
  template<typename T>
  auto operator()(T x){
    return x*x;
  }
};

-> Böylece bu fonksiyon istenilen argümanla çağrılabilir.
Ex:
int main(){
  auto f=[](auto x){return x+x;};
  std::string name{"gurkan"};
  auto a1=f(12);
  auto a2=f(3.5);
  auto a3=f(name);

  std::cout<<"a3 = "<<a3;
}

-> C++14 ile lambda ifadelerine auto'yu parametre olarak kullanma geldi.

-> Ayrı değişkenler için ayrı auto bildirimleri aynı tür kullanma zorunluluğu getirmez. 
Ex:
int main(){
  auto f=[](auto x, auto y){};
}

-> Aynı lambda ifadesini özdeş olarak yazsak dahi derleyici ayrı türde bir closure type oluşturur.

Ex:
int main(){
  auto f1=[](){};
  auto f2=[](){};

  constexpr bool b = std::is_same_v<decltype(f1), decltype(f2)>;
  std::cout<<typeid(f1).name<<'\n'; //lambda_1
  std::cout<<typeid(f2).name<<'\n'; //lambda_2

}

-> Closure type'ların copy ctor'u vardır. 
Ex:
int main(){
  auto f1 = [](){};
  auto f2 = f1; //copy ctor ile hayata geldiği için f2 ile f1'in türleri aynı.
}

-> C++20 standartına kadar lambda ifadelerinden elde edilen closure type'ların default ctor'ı deleted statüsündeydi. 
Ex:
int main(){
  auto f1 = [](){ };
  decltype(f1) f2; //C++20 öncesi illegal
}

Stateless Lambda: Sınıfının bir veri elemanı olmadığını ve o sınıf türünden nesnelerin hepsinin aynı değerde olduğunu bildirir. Bir lambdanın
stateless olması demek herhangi bir capture'a sahip olmaması demektir. C++20 ile gelen default ctor'ların olma şartı, lambda'nın stateless olmasıdır. 
Eğer stateless değilse default ctor yine delete edilmiş olur. 

Ex:
int main(){
  auto f1 = [](){};
  auto f2 = f1;
  f1=f2; //C++20 legal
}

-> Derleyici stateless lambdalar için lambdanın closure type türünden, fonksiyon çağrı operatör fonksiyonunun ait olduğu adres türüne bir tür 
dönüştürme operatör fonksiyonu yazabilir.

Ex:
int main(){
  auto f= [](int x){return x*x;};
  int (*fptr)(int) = f; //Bunun legal olmasının sebebi,derleyici tarafından tür dönüştürme operatör fonksiyonunun yazılmasıdır. Lambda stateless olmasa bu olmazdı. 
}

-> Fonksiyon adresi türleri, işaret operatörü, +'nın, operandı olabilirler.

Ex:
int main(){
  char c = 'A';
  +c ;
  int(*f)(int);
  +f; //function pointer
}

Positive Lambda:
int main(){
  auto x = +[](int a){return a*a;}; //Normalde işaret operatörü "+" sınıf tarafından overload edilmese hata durumuna düşer.  
  std::cout<<typeid(x).name<<'\n'; //Lambdaların function pointer türüne dönüşüm yapan fonksiyonları aracılığıyla işaret operatörü "+" kullanılabilir 
  //hale gelecek ve ifade artık function pointer türüne dönüşür. 
}

[](int a){return a*a;} : closure type türünden bir ifade 
+[](int a){return a*a;} : Function Pointer 

-> Tıpkı normal fonksiyonlarda olduğu gibi lambda fonksiyonlarda da fonksiyonun exception throw etmemesini verme garantisi sağlamak istiyorsak, 
"noexcept" specifier'ı kullanılabilir.

Ex:
int main(){
  auto f = [](int x)noexcept{return x*x;};
  
}

->  C++11 ile eğer lambda ifadesinin içinde constexpr'i ihlal etmeyecek bir unsur yok ise default olarak ifade constexpr olarak işlenmesi eklendi.
Ex:
int main(){
  auto f = [](int x){
   // static int ival = 15;, syntax hatası oluşturdu eğer constexpr tanımlanan değişkene lambda eşitlenirken constexpr içinde static değişken tanımlanırsa syntax hatası oluştu.
    return x * ival;};

    constexpr auto val = f(5); //static değişken tanımı dahil edilmezse legal eğer bu ifade çıkartılır ve static eklenirse yine syntax olmaz. 
  }
}

-> C++20 ile artık lambda ifadeleri unevaluated context'te doğrudan kullanılabilir hale geldi.
Ex:
sizeof(decltype([](int x){return x*x;}));
myClass<decltype([](){})> m1;

-> C++20 ile template oluşturulurken non-type parametrede strcutrual type dediğimiz türler template argümanları olabiliyorlar.

Ex:
template<auto x>
class myClass{};

int main(){
  myClass<[]{}> m;
}

template<auto x = []{}>
struct myClass{
  inline static int ival = 5;
};
int main(){
  myClass<> m1;
  m1.ival++;
  m1.ival++;
  m1.ival++;
  myClass<> m2;
  std::cout<<"m1.ival= "<<m1.ival<<" m2.ival= "<<m2.ival; //m1.ival= 8 m2.ival= 5 çünkü m1 ve m2'nin türleri aynı değil. Lambda ifadesi her çağırıldığında farklı tür üretti.
}

Immediatly Invoked Function Expression:
-> C++'da const olmayan değişkenlerde yapılan işlemlerin ardından elde edilen sonucu const değişkenlere doğrudan eşitlemek mümkün değildir.
Bir fonksiyon yardımıyla vs. bu durum legal hale getirilebilir ancak bu sefer de kodu olduğu yerden uzağa taşıyacağı için karmaşıklık ekler.
Bunun önüne immediatly invoked function expression ile geçebiliriz.

Ex:
int main(){
  int a = 5;
  int b = 4;
  //
  const int x = [=](int x){  //Böylece ilk değer veren nesne ile nesne arasındaki mesafe azalmış olur. 
    //code
    return a*b-3+x;
  }(12); //legal
}































*/
