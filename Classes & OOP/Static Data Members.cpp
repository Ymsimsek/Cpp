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

*/
