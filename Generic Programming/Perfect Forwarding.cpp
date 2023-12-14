/*
-> Generic programlamlamanın en önemli araçlarından birisidir. Bir fonksiyon aracılığıyla fonksiyona girilen argümanların const ve referans
durumlarını koruyarak başka bir fonksiyona gönderilmesi başarıyla yapıldığında buna perfect forwarding denir.

ex.
class myClass{};

void foo(myClass&){
  std::cout<<"myClass&\n";
}

void foo(const myClass&){
  std::cout<<"const myClass&\n";
}

void foo(myClass&&){
  std::cout<<"myClass&&\n";
}

template <typename T>
void call_foo(T&& x){
  foo(std::forward<T>(x)); //forward, çağrıda kullanılan ifadenin referans değeri ve const'luk değerini değiştirmeden argüman olarak kullanılabilir.
}

int main(){
  myClass m;
  const myClass cm;

  foo(m);
  call_foo(m);
  foo(cm);
  call_foo(cm);
  foo(myClass{});
  call_foo(myClass{});
  
}

-> STL kapların isimlerinde "emplace" sözcüğü geçen ekleme fonksiyonlarında bu mekanizma görülebilir  | emplace_back : Argümanları alıp containere
eklerken containerin ctor'una, gelen argümanları forward eder. Perfect forwarding'in en tipik örneklerindendir.

Perfect Forwarding Ex: 
template <typename T>
void foo(T&&);

template<typename T>
void call_foo(T&& x){
  foo(std::forward<T>(x));
}

