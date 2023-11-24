/*
Non-static member fonksiyonlarına çağrı yapmak için bir nesneye ihtiyaç vardır. Ancak static member fonksiyonları nesne tanımlanmadan da çağırılabilir.
Tıpkı global fonksiyon gibidirler ancak class scope'ta yer alırlar. Name lookup'ta class scope'tan başlanır. Sınıfların static üye fonksiyonları yine sınıfın prive bölümüne erişebilirler.

-> Sınıfların static üye fonksiyonları const niteleyicisi ile nitelenmezler. 
static void foo()const{} //Geçersiz

-> Static üye fonksiyonlar içerisinde "this" kelimesi kullanılamaz. 

-> Sınıfların statik üye fonksiyonlarında non-static veri elemanları kullanılamaz.

-> Sınıfın static üye fonksiyonları ile factory function oluşturularak sınıfın private bölümündeki ctor'lara çağrı yapabilir ve aynı parametrelerle istenilen ctor'larına çağrı yapabiliriz.

Ex:
class Complex{
public:
  static Complex create_polar(double theta, double r){
    return Complex(theta,r,0);
  }
  static Complex create_cartesian(double r, double i){
    return Complex(r,i);
  }
private:
  Complex(double,double); //cartesian
  Complex(double,double,int); //polar
};

int main(){
  auto c1= Complex::create_cartesian(3.5,1.2);
  auto c2= Complex::create_polar(.5,45);
}

*/
