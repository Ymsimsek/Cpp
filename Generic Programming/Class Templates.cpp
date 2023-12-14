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









*/


