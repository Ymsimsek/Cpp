/*
Delegating Constructor: Overload edilen ctorların ortak bir kodu olunca eski C++'da ctor'ların ortak kodu bir fonksiyon şeklinde tanımlanıp ctorlar bu fonksiyonu çağırıyordu.
Bunun yerine artık recursive olmamak kaydıyla ctorlar kendi görevini başka ctorlara delege edebilir. Delegating ctor olan yerde initializer list kullanılamaz.

myClass(int x):myClass(x,x,x){} //Delegating Constructor

myClass(int x, int y, int z):mx(x),my(y),mz(z){}
int mx{},my{},mz{};

*/
