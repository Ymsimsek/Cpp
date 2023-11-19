/*

enum Color{Blue,Black,White,Purple};// enum is a type. "Blue", "Black", "White", "Purple" are constants and have their int values as "Blue" is "0", "Black" is "1" etc. 

-> If we want to change value we can simply make the statement { Blue =200 ; } and its value will be changed. 

-> enum does not allow implicit conversion from arithmetic types. 

color mycolor;
mycolor = 3; //Error and illegal. 

-> Each enum has an underlying type. 

-> Enumaratörler int sınırını aşmadığı takdirde int türü seçilir. Eğer sayı aşılırsa int yerine long vs. seçilebilir. 

Modern C++ öncesi enum'un istenmeyen özellikleri: 
1. Compiler'dan compiler'a underlying type değeri değişir. (sizeof fonksiyonu çalışmaz). Enum türleri başlık dosyalarında incomplete type olarak kullanılamazlar. 
2. enum türlerinden tam sayı türlerine dönüşüm olmamasına rağmen tanımlanan değişken türüne dönüşebilir.
3. enumaratörlerin ayrıca scope'ları yoktur. 

Example: 
  
//traffic_light.h
enum trafficLight{Red, Yellow, Green};

//screen.h
enum screenColor{Magenta,White,Black, Red};

-> Yukarıdaki örnek syntax hatası verir. C++ 11 ile bundan dönüldü ve scoped enums dile eklendi. (Kapsamlandırılmış enum)

Scoped Enums: 
Scoped enums ile birlikte underlying type'ın belirlenebilme şansı verildi. Örtülü dönüşüm iptal edildi.
enum class kalıbıyla farklı enum'larda aynı enumaratörlerin kullanılabilme özgürlüğü getirildi. 

-> enum class bir class değildir. 

Ex:
enum class trafficLight{Red, Green, Yellow};

-> Bunlara ek olarak C++ 11 ile unscoped enum'lara da underlying type belirleme özelliği getirildi. 

Ex.
enum Pos:long {On, Off, Hold}; 

-> Eğer underlyingtype belirtilmezse default olarak int türü seçilir. 

*/ 
