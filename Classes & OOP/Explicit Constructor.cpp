/*
-> "explicit" anahtar kelimesi kullanılarak tanımlanan ctorlardır. Ctor'ların implicit dönüşüm yapamayacağını, sadece belirterek yapılan dönüşümlere izin verileceğini söyler.
İstenmeden yapılan implicit conversionları engeller. 

-> Bir sınıfın (özellikle tek parametreli) ctorlarını aksi yönde karar almayı gerektirecek makul bir neden olmadıkça explicit yapmalıyız. Böylelikle istenmeyen tür dönüşümleri engellenmiş olur.

Ex:

class myClass{
public:
  myClass();
  explicit myClass(int);
};

-> "explicit" ve "static" kelimeleri bildirimde kullanılır tanımlamada kullanılmaz. 

Ex:
class myClass{
public:
  explicit void foo(); //Doğru kullanım
  static void func(); //Doğru kullanım
};
//Global scope
explicit void foo(){ // Yanlış Kullanım
//... 
} 

-> Explicit kelimesi kullanıldığında copy init yapılması syntax hatası olur.
Ex:
myClass m1(19); // Direct Init
myClass m2{35}; // Direct List Init
myClass m3 = 57; // Copy Init

Ex:
unique_ptr<int> p1 {new int}; // Geçerli
unique_ptr<int> p2 (new int); // Geçerli
unique_ptr<int> p3 = new int; // Geçersiz 

-> Copy init söz konusuysa ve overload yapılacaksa, overload resolution'a derleyici, explicit keyword'ü ile tanımlanan fonksiyonu dahil etmez. 

-> Explicit ve conversion ctor her zaman tek parametre ile kullanılmak zorunda değillerdir. 

*/ 
