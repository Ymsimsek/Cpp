/*
class myClass{
public:
  void foo(int)&; //L Val. Ref. Qualifier
  void bar(int)&&; //R Val. Ref. Qualifier
  void baz()const&; 
  void func()const&&; 
  myClass& operator=(const myClass&)&;
};

-> L value reference qualified olan fonksiyon yalnızca L value sınıf nesneleriyle çağırılabilir. R value ref ile çağırmak syntax hatasıdır.

-> R value reference qualified olan fonksiyon yalnızca R value sınıf nesneleriyle çağırılabilir.

-> Bir sınıf nesnesinin L value veya R value olmasına bağlı olarak iki farklı implementasyon overload kullanılarak verilebilir.

Ex: 
class myClass{
public:
  void foo()&{}
  void foo()&&{}
};

-> Reference qualified fonksiyon ile edilmeyen normal fonksiyon overload edilemez.

-> C++20 ile copy assgn. fonksiyonu da L value qualified olarak default atama yapılabilir hale geldi. Böylelikle R value reference atamaları engellenmiş oldu.

*/
