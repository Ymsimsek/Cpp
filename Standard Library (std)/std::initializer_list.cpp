/*
"#include <initializer_list>" ile programa eklenebilir ancak çoğu standart kütüphane ile eklenir. 

-> std::initializer_list<int> x{1,3,5,7,9}; şeklinde eleman oluşturulabilir.

-> x.size() // dizi boyutu

-> x.begin() // dizinin başlangıcının adresi

-> x.end() //dizinin bittiği yerin adresini döndürür.

-> Bir diziye hazır sıralı elemanları eklemek istediğimizde bunu parametresi std::initializer_list olan fonksiyon çağrılarıyla yapabiliriz.

Ex:
vector ivec {4,1,4,2,3};
ivec.insert(ivec.end(),{10,20,30,40});

*/
