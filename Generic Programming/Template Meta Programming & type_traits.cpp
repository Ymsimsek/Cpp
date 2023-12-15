/*

Meta Functions: Compile Time'da bir tür bilgisi veya bir değer hesaplanmasına yönelik tipik olarak bir sınıf şeklinde ifade edilen fonksiyonlardır.

Ex:
template<typename T, T v>
struct IntegralConstant{
  static constexpr T value = v;
  using value_type= T;
  using type = IntegralConstant;
  constexpr operator value_type()const noexcept{return value}
  constexpr value_type operator()()const noexcept{return value} //parametresi olmayan fonksiyon çağrı operatör fonksiyonu
};

using TrueType= IntegralConstant<bool,true>;
using FalseType= IntegralConstant<bool,false>;

template <typename T>
struct IsPointer : FalseType{};

template <typename T>
struct IsPointer<T *> : TrueType{};

template<typename T>
void func(T x){
  static_assert(IsPointer<T>::value,"Only Pointers are Allowed"); //Bu yolla istenilen tür olmaması durumunda syntax hatası durumuna getirebiliriz.
}

int main(){
  IntegralConstant<int,5>::value x; //x=5
  IntegralConstant<bool,true>::value y; //y=true
  IntegralConstant<bool,true>::value_type z; //z=bool
  IntegralConstant<int,4>::type m; //m=IntegralConstant<int,4>
  constexpr auto val = IntegralConstant<int,4>{} + IntegralConstant<int,3>{}; //val =7 (int) 
  constexpr auto val2 = IntegralConstant<int,5>{}(); //val2=5 (int) 
  func(12); // Only Pointers are Allowed, hata
  int zx{789};
  func(&x); // Geçerli 
}

-> Yukarıdaki kodda sadece istenilen türün, fonksiyon çağrısında kullanılabileceği kalanlarının ise syntax hatasına düşeceği garantilenmiştir.
Her defasına bu kodu yazmaya gerek yoktur, type_traits başlık dosyasında mevcuttur.

Ex:
#include <type_traits>
template<typename T>
void func(T x){
  static_assert(std::is_pointer_v<T>);  //Bizden tür alıp bool değer verir.
}

Type Transformation Meta Function:
Ex: Tür değiştiren mekanizmaya örnek referansı remove ediyor. 
#include <type_traits>
template<typename T>
struct RemoveReference{
  using type = T;
};

template<typename T>
struct RemoveReference<T&>{
  using type T;
};

template<typename T>
struct RemoveReference&&{
  using type T;
};

template <typename T>
using RemoveReference_t= typename RemoveReference<T>::type;

int main(){
  // RemoveReference_t<int&&>  çıktı olarak int verir. 
}

Ex:
#include<iostream>
#include<type_traits>
void bar(std::true_type){
  std::cout<<"implementation for l values\n";
}
void bar(std::false_type){
  std::cout<<"implementation for r values\n";
}
template<typename T>
void func(T&&){
  bar(std::is_lvalue_reference<T>{});
}

int main(){
  func(12);
  int x{21};
  func(x);
}

Ex: Tam sayı türler için ayrı diğer türler için ayrı implementasyon sağlayabildiğimiz program:
template <typename T>
void func_impl(T, std::true_type){
  std::cout<<"tam sayı turler icin\n";
}
template <typename T>
void func_impl(T, std::false_type){
  std::cout<<"tam sayı olmayan turler icin\n";
}

template<typename T>
void func(T x){
  func_impl(x,std::is_integral<T>{}); //Tam sayı mı değil mi? 
}
int main(){
  func(12);
  func(5L);
  func(1.2);
}























*/
