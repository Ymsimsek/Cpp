/*
-> myClass(myClass&& r)

-> Derleyici overload resolutionda çağrının copy ctor'a mı yoksa move ctor'a mı yapıldığını referans değerine bakarak overload yapar. Move ctor çağrısı için R value çağrı yapacaktır. 

-> Move ctor çağrı yapılan nesnenin kaynağını çalar ve nesnenin destructor'u çağırıldığında, destructor'un kaynağı geri vermemesi gerekir. 
Çağrıda "copy ctor" gibi const parametre olduğu için nesne üzerinde değişiklik yapabilir.

-> Elimizde ister sol taraf referansı ister sağ taraf referansı olsun, bir referans değişken varsa o değişkenin oluşturduğu ismin değer kategorisi her zaman L value expression'dur.

-> Eğer sınıfın sadece copy ctor'u varsa ve sınıf nesnesini hayata getirirken eşittirin sağındaki ifade L value de olsa R value de olsa overload olmayacağı için copy ctor çağrılır.
Çünkü const L value referans sola da sağa da bağlanır.
myClass m = L val or R val

Derleyicinin Yazdığı Move Ctor:
myClass(myClass&& other):ax(std::move(other.ax)),bx(std::move(other.bx)),cx(std::move(other.cx)){}

-> Eğer move ctor'u derleyicinin yazmasını sağlarsak derleyicinin yazdığı move ctor, hayata gelecek nesnenin elemanlarına, onu hayata gelecek nesnenin elemanlarına, onu hayata getirecek R value olan nesnenin elemanlarına taşır.

-> std::move(expr) ifadesi L veya R value olan ifadenin R value olarak kullanılabilmesini sağlar. Nesneyi isminde geçtiği gibi "move" etmez. 

Taşınacak Nesne Pointer İçeriyorsa:
-> Move ctor'a değişkenleri 0 ve pointeri nullptr yapan ifade eklenir ve destructor'a:
"if(pointer_name)
  std::free(pointer_name) "
eklenir.

*/
