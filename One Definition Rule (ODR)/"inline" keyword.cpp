/* 
Inline Expansion: 

Derleyicinin fonksiyonların kodlarını görmesi gerekir. Eğer program içinde 
tüm statement ve fonksiyon adları belirli ise derleyici, koddaki satırların konumlarını değiştirerek
performans artırmak için optimizasyon yapar. Bu optimizasyona verilen ad inline expansion'dur. 
Her derleyicinin inline expansion performansı farklı olabilir. Recursive yapının derinliği de 
bir faktör olarak bu optimizasyona etki yapabilir. 
*/


//"inline" Keyword Kullanımı:

inline int foo(int x, int y){
  // some code 
  return x*y-3;
}

/*
-> inline anahtar sözcüğü kullanılınca derleyicinin inline expand etme zorulunluluğu yoktur.

-> Eğer bir fonksiyon inline olarak tanımlanırsa ODR'ı ihlal etmeme garantisi verir.

-> Tüm fonksiyonlar inline keyworwdü ile tanımlanırsa tüm kod header file içinde tutulabilir ve cpp'ye gerek kalmaz.

-> Dezavantajı tüm kodun ifşa edilmesidir. 

-> Runtime'da linker farklı inline fonksiyonları tek adreste ilişkilendirir ve çağırıldığında o adrese gider.

-> static ve inline tanımlanan aynı fonksiyonların adresleri aynı değildir.

-> Inline expansion yapılması arzu edilirse header dosyalara inline anahtar sözcüğüyle tanım yapılabilir. 

Ex:
//ahmet.cpp
inline int foo(int x, int y){
  return x+y-5;}
//tunahan.cpp
inline int foo(int x, int y){
  return x+y-5;} // token by token aynı tanım yapıldığı için ODR ihlal edilmemiştir. Eğer bir token'ı dahi farklı olsa ODR ihlali olurdu.

-> Statik ömürlü global değişken ve statik ömürlü sınıfların statik veri elemanları kullanılarak header file yapılamıyordu ancak
C++17 sonrasında inline ile tanım yapıldığında ODR ihlal edilmez. Eskiden header only library için inline fonksiyonlarda yerel değişken olarak kullanım vardı

Ex:
inline int g{15};//C++ 17




