/*
Mutator - Setter Functions:
- void func(T*);
- void foo(T&);

Accessor - Getter Functions:
- void funcs(const T*);
- void foos(const T&);

-> Non-static member functions için de mutator ve acccessor functions gereklidir. Bir non-static member function bildirilirken
görünmeyen nesnenin adresini tutan parametre bulunur. Bu sebeple aslında setter function'dur.

-> Mutator functions sadece data member'ları değil class'ın state'ini de değiştirebilir.

const Member Functions:

class Nec{
public:
  void foo(); //non-const member function
  void bar()const; //const member function
};

-> Const member functions sınıfın non-static veri elemanlarına atama yapamazlar.

Ex:
class myClass{
public:
  void foo()const{
    auto b{mx}; //legal
    myClass m;  //legal
    m.mx{89};   //legal
  }
private:
  int mx;
};

-> const üye fonksiyon içinde non-const üye fonksiyon çağırılırsa cont T*'dan T*'a dönüşüme zorlanmış olur ve syntax hatası olur. ( Hata aynı nesne içerisinde olur. Farklı nesne tanımlanırsa olmaz.) 

Ex:
void foo()const{
  void bar(); // illegal
}
void bar(){
  void foo(); // legal
}
Ex:
void foo()const{
  myClass m;
  m.bar(); // legal
}

-> const üye fonksiyon içerisinde başka bir const üye fonksiyon çağırmakta bir sorun yoktur.

-> const tanımlanan nesnenin const olmayan üye fonksiyonu çağırması hatadır. const T*'dan T*'a dönüşümü zorlar.

Ex:
class myClass{
public:  
  void foo()const;
  void bar();
};
int main(){
  const myClass m;
  m.foo();  // legal
  m.bar();  // illegal
}

-> const sınıf nesneleri için sadece sınıfın const üye fonksiyonlarını çağırabiliriz.

-> Eğer bir sınıfın veri elemanının değişmesi onun problem domainindeki algılanan değeriyle alakalı değilse const üye fonksiyonda çağırıp değiştirmemizde semantik açıdan bir hata değildir ancak syntax açısından 
hatadır. Bu hatayı aşmamızı sağlayan araç "mutable" keyword'üdür. 

Ex:
class Fighter{
public:
  void foo()const{
    ++debug_call_count;
  }
private:
  int m_age; //cannot be called
  int m_power; //cannot be called
  mutable int debug_call_count; //can be called
};

*/
