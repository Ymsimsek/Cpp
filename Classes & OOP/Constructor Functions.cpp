/*
-> Sınıfın non-static member fonksiyonlarıdır. Fonksiyonun ismi sınıf ismiyle aynı olmalıdır. Geri dönüş değeri kavramı yoktur.
Constructor fonksiyonlar static fonksiyon olamaz ve const member function da olamazlar.

-> Sınıfta birden fazla ctor olabilir ve overload edilebilirler. 

-> Public olmak zorunda değildir ancak client ctor'u çağırmak isterse access control hatası verir.

Gösterim ve Kullanımı:

class myClass{
public:
  myClass();
};

int main(){
  myclass m;
}

-> ctor'lar, ".", "->" operatörleriyle çağırılamazlar. 

Default Ctor: ( Varsayılan Kurucu İşlev)
Parametresi olmayan ya da tüm parametreleri default argüman alan ctorlardır.

Ex:
class myClass{
public:
  myClass();
};

// veya

class myClass{
public:
  myClass(int=6); //int=6 default argüman
};

*/
