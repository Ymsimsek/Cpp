/*
-> "()" operatörünü overload eden operator fonksiyonu"operator()"'dır.

-> İsmiyle çağrılabilir. Üye fonksiyon olmak zorundadır.

-> Varsayılan argüman alabilirler ve overload edilebilirler.

Ex:
class myClass{
public:
  void operator()(){
    std::cout<<this<<'\n';
  }
};

int main(){
  myClass m;
  std::cout<<&m<<'\n';
  m(); // ya da m.operator()();
}

Ex:
class myClass{
public:
  void operator()(int);
  void operator()(int,int);
  void operator()(double);
  void operator()(const char*);
};
int main(){
  myClass m;
  m(59);
  m("m");
}

-> Function call operator function, sınıfın üye fonksiyonu olduğu için sınıfın veri üyelerini kullanabilir. Sınıfın veri üyelerini kullandığında, aynı sınıfın farklı nesnelerinin veri üyelerinin değerleri farklı olabilir. 
Dolayısıyla, her sınıf nesnesi aynı fonksiyon çağrı operatörünün operandı olacak fakat kullandıkları veriler farklı olabilecektir.
*/
