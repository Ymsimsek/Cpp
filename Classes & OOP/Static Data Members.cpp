/*
-> Static data member'ları "static" anahtar sözcüğüyle bildirilirler. ( static int mx;)

-> Tıpkı global değişkenlerde olduğu gibidir. 
  
-> Header File'da bildirim, cpp'de tanım yapılabilir.

-> Main çağırılmadan hayata gelip mainden sonra giderler.

-> Static data members, class scope'a dahildir.

-> Main veya sınıf dışında kullanabilmek için "::",".","->" operatörleri kullanılır. (myClass::mx)

Ex:
class myClass{
public:
  static int mx;
};

int main(){
  myClass n1,n2;
  n1.mx = 10;   //mx 10 olur
  n2.mx = 56;    //mx 56 olur
  auto p = &n1;
  p-> mx = 854;    //mx 854 olur
}

-> Static array bildiriminde öğe sayısını yazma zorunluluğu yoktur.
static int a[];

-> Sınıfların static data memberları cpp dosyasında tanımlanabilir.

-> Sınıfların static data memberları inline keyword'ü ile tanımlanabilir ve defining declaration olur. Böylelikle header-only libraries oluşturulabilir.

-> C++17 sonrasında inline keyword'ü değişkenler için de kullanılabilir hale gelmiştir.

-> Sınıfların static const ve integer type veri elemanlarına sınıf içinde ilk değer verilebilirler.

-> Sınıfların static veri elemanları const üye fonksiyonları içinde de değiştirilebilirler.

-> Constructor data initializer list static veri elemanlarına ilk değer veremez. 

*/
