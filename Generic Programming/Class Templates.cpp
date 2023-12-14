/* 
-> Sınıf şablonunun intantiation'undan bir class kodu elde edilir. Bir sınıf şablonu oluşturarak bir sınıftan farklı kodlar oluşturulabilir.
  
-> Tıpkı fonksiyon şablonlarında olduğu gibi birden çok parametre alabilir ve bu parametreler, type, non-tpe, veya template parametreleri 
olabilir. 

-> Derleyicinin sınıf kodunu nasıl yazacağını gösteren meta code'lardır. Template'in kendisi bir sınıf değildir ancak oluşturulan 
specialization bir sınıftır. 

Ex:
template <typename T>
class myClass{

};

template <typename T>
class Nec{

};

int main(){
  //Nec<myClass<int>>           LEGAL
  //myClass<Nec<myClass<int>>>  LEGAL
  //std::vector<vector<int>>    LEGAL
  myClass<int> x;
  myClass<int>* p{x};
  myClass<int>&r{x};
  void foo(const std::vector<int>&);
  std::vector<double> bar();
}

-> Forward declare edilebilirler:
template<typename>
class myClass;

-> Aynı tür template'in farklı tür argümanlarıyla oluşturulan ifadeler aynı türden değildir.

Ex:
template <typename T>
class myClass{

};
int main(){
  myClass<double> dm;
  myClass<int> im; //double açılımından farklı bir türde
}

-> Her ne kadar implicit type conversion olsa da specializationlar arasında conversion olmaz. Ancak bu legal hale gelebilir. Non-type 
parametre için de aynı kural geçerlidir.

Ex:
template<int>
class myClass{

};
int main(){
  myClass<5> x;
  myClass<6> y;
  // y=x; illegal
}

Ex: 
std::vector<double> dvec(100);
std::vector<int> ivec(100);
//dvec=ivec illegal


-> Sınıf şablonlarında syntax hatası yaratacak olan fonksiyonlarda ancak fonksiyon çağırıldığında kodu yazılır ve syntax hatası oluşur.

Ex:
template<int>
class myClass{
public:
  void foo(T x){
    ++x;
  }
};
class Nec{};

int main(){
  myClass<Nec> m;
  Nec mynec; // syntax hatası yok
}

Ex:
template<int>
class myClass{
public:
  void foo(T x){
    ++x;
  }
};
class Nec{};

int main(){
  myClass<Nec> m;
  Nec mynec; 
  m.foo(mynec); //hata, operator++
}

-> Sınıf şablonu içerisinde bildirilen fonksiyon hem sınıf şablonu içerisinde hem aynı başlık dosyasında hem de include edilen başka bir başlık dosyasında
tanımlanabilir. Ancak syntax farklıdır.

Ex:
template<typename T>
class myClass{
public:
  T bar(T);
  void foo(T,T)
};

template<typename T>
myClass<T>::bar(T){ //Syntax bu şekildedir.
}
template<typename T>
myClass<T>::foo(T,T){ //Syntax bu şekildedir
}

-> Sınıfın bir üye fonksiyonu template olabilir. 

Ex:
class myClass{
public:
  template<typename T>
  void func(T x);
};
int main(){
  myClass m;
  m.func(1);
  m.func(1.3);
  m.func<float>(1);
}

-> Sınıf içinde sınıf ismini açılımıyla yazma zorunluluğu yoktur.
Ex:
template <typename T>
class Nec{
public:
  Nec func(Nec x){
    return x;
  }
};

-> Sınıf şablonunun üye fonksiyonu template olarak bildirilmedikçe template olmaz. 
template <typename T>
class myClass{
public:
  void func(T x);//template değil
};

std::pair : İki farklı türden öğeyi bir araya paketler. Utility başlık dosyasında tanımlanan sınıf şablonudur. 
Ex:
template<typename T, typename U>
struct Pair{
  T first;
  U second;
};

Ex:
std::pair<int,double>foo();
auto p=foo();

Ex:
int main(){
std::pair<double,double>pd{2.3,5.6};
std::pair<int,int>pd{2,56};
}

Ex:
int main(){
std::pair p1{4,5.6}; //CTAD, Class Template Argument Deduction
}

Default Argument:

template<typename T = int, typename U = double>
class Nec{};
template<typename T, typename U = T>
class myClass{};

Explicit Specializetion:
->Derleyiciye bizim derleyicinin oluşturucağı specialization için farklı bir specialization dikte edilebilir
buna explicit specialization denir. Özel durumlar için özel specialization oluşturmaya yarar. 
Ex:
template<typename T>
class Nec{
public:
  Nec(){
    std::cout<<"primary template type t:"<<typeid(T).name<<'\n';
  }
};
template<>
class Nec<int> {  //explicit specialization
public:
  Nec(){
    std::cout<<"expclicit template type t:"<<typeid(T).name<<'\n';
  }
 };

 int main(){
   Nec<int> n1;
   Nec<double>n2;
   Nec<int*> n3;
   Nec<Nec<float>> n4; 
 }

-> Explicit specialization için interface ayrı olmak zorunda değildir. 

-> Template'de sınıf forward declaration yapıldığında specialization yapmak syntax hatası oluşturur. 

-> Fonksiyon çağrılarında da explicit specialization kullanılabilir ancak hali hazırda overload mekanizması kullanıldığı için çoğu zaman
gerek duyulmaz.
ex.
template<typename T>
void func(T){
 std::cout<<1;
}
template<>
void func(int*){
 std::cout<<2;
}
template<typename T>
void func(T*){
  std::cout<<3;
}
int main(){
  int* p = nullptr;
  func(p);//3 yazılır.
}

ex.
template<typename T>
void func(T){
 std::cout<<1;
}
template<typename T>
void func(T*){
 std::cout<<2;
}
template<>
void func(int*){
  std::cout<<3;
}
int main(){
  int* p = nullptr;
  func(p);//3 yazılır.
}

Partial Specialization: Specializationlar kümesinde bir alt kümeye uyan yani tek bir specialization'a uymayan  bir alternatif kod üreten 
specialization tekniğidir. 
Ex:
template<typename T>
struct myClass{
public:
  myClass(){
    std::cout<<"primary template type T:"<<typeid(T).name()<<'\n';
  }
};

template <typename T>
struct myClass<T*>{
  myClass(){
    std::cout<<"partial spec.\n"
  }
};

int main(){
  myClass<int> m1;
  myClass<double> m2;
  myClass<void> m3;
  myClass<int*> m4;
  myClass<double**> m5;
}

-> Partial specialization'lar function template'de yoktur sadece class template'de mevcuttur. 



*/


