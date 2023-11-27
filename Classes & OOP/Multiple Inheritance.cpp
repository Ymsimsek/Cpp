/*
Multiple Inheritance: Bir türetilen sınıfın birden fazla taban sınıfı varsa işleyen mekanizmaya verilen addır. 
  
-> Inheritance bildirilirken: "class Der: public Base1,public Base2;" şekildinde bildirilebilir.

-> Bildirim sırası ctor'ların çağırılacağı sırayı belirler. Aynı isime sahip fonksiyonları olan taban sınıflardan türetilen sınıflarda fonksiyon çağrıları 
çözünürlük operatörü olmadan çağırılırsa ambiguity oluşabilir. Her sınıfın sanal fonksiyonlarını override edebilir. (Gerekli koşullar sağlanırsa)

*/
