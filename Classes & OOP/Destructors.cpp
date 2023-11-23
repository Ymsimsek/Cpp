/*
-> Bir sınıf nesnesinin life span'inin bitmesini sağlayan fonksiyondur. İsmi sınıf ismiyle aynı olmak zorunda ve ismi "~" işaretiyle başlamalıdır. 
dtor şeklinde kısaltılabilir. Non-static member function olmak zorundadır. 

-> dtor, free function olamaz.

-> dtor, const member function olamaz.

-> Geri dönüş değerine sahip değildir.

-> Bir sınıfın destructor'u parametresiz olmalıdır ve overload yapılamaz. 

-> Sadece özel bir senaryoda bir sınıfın dtor'u ismiyle çağrılabilir. (Placement new ifadeleri)

-> Dtor ve Default Ctor sınıfın special member functions kategorisindedir.

*/
