/*
-> Friend bildirimi sınıf haricindeki bazı kodların, sınıfın private bölümüne erişebileceğini söyler. ADL (Argument Dependent Lookup) ile de ilgilidir. 

-> Friend bildirimi free function'a yapılabilir.
Ex:
class myClass{
public: 
  friend void ff(myClass);
private:
  int mx;
  void foo();
};

void ff(myClass m){
  m.foo();
  myClass myc;
  myc.mx=5;
}

-> Friend bildirimi sınıfın public veya private bölümünde yapılabilir. Anlamsal açıdan bir fark yoktur.

-> Sınıf, kendi üye fonksiyonuna "friend" statüsü veremez.

-> friend bildirimi kullanılarak sınıf içinde fonksiyon tanımı yapılabilir ancak sınıfın üye fonksiyonu olmaz buna hidden friend denir.

Ex:
friend int bar(myClass, int x){
  return x*x;
}

-> Bir sınıf başka bir sınıfın üye fonksiyonlarına friend bildirimi yapabilir. Bu bildirimin yapılabilmesi için üye fonksiyonuna friend'lik verilen sınıfın
complete type olması gereklidir. Sınıfların ctor'larına da friend'lik verilebilir.

Ex:
class Erg{
public:
void foo(int);
Erg();
Erg(int);
};

class Nec{
private:
  friend void Erg::foo(int);
  friend Erg::Erg(int);
  friend Erg::Erg();
  int mx;
};

void Erg::foo(int){
  Nec necx;
  necx.mx =x;
}

-> Bir sınıf başka bir sınıfa friend'lik verebilir. Friend bildirimine konu olan sınıf incomplete type olabilir.

Ex:
class Nec{
  friend class Erg;
  int mx;  
};
class Erg{
public:
  void foo(Nec nec){
    Nec.mx=20;
  }           
  void bar(){
    Nec* p = new Nec;
    auto val=p->mx;
  }
};

-> Friend bildirimleri geçişken değildir. A, B'ye, B de C'ye friend'lik verse dahi, C, A'nın private bölümüne erişemez. 

-> Bazen ihtiyaç olsa da bir sınıf kendi seçilmiş private öğeleri için bir başka koda friend'lik veremezç ( Private'da 5 öğe olduğunu ve bizim yalnızca 1'ini değiştirmek istediğimizi varsayalım.)

*/
