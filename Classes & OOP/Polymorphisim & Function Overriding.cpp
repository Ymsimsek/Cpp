/*
Bir taban sınıfının fonksiyonları:
1. Türemiş sınıflara hem bir interface hem de implementation veren.
2. Türemiş sınıflara hem bir interface hem de default implementation veren.
3. Türemiş sınıflara yalnızca bir interface veren ve implementation vermeyen olmak üzere üç şekilde olabilir.

-> Eğer 2. veya 3. kategorideki fonksiyonlar mevcutsa yani türetilmiş nesnenin fonksiyonun taban sınıfın fonksiyonunun yerine tercih edilmesine "Function Overriding" denir. 

-> Bir sınıfın 2. kategoriden en az bir fonksiyonu varsa böyle sınıflara "Polymorphic Class" denir. (Çok biçimli sınıf)

-> Bir sınıfın 3. kategoriden en az bir fonksiyonu varsa böyle sınıflara "Abstract Class" denir.

Ex:
class airPlane{
public:
  void takeoff();
  virtual void fly(); //virtual function
  virtual void land()=0; //pure virtual function
}  

-> airPlane sınıfı hem polymorphic hem de bir abstract class'tır. "fly" function polymorphism'i, "land" function ise abstract terimini sınıfa kazandırmıştır.

-> Abstract base sınıfından türetilen sınıflar pure virtual function'u override etmezlerse bir sınıf türünden nesne oluşturamazlar ve türetilmiş sınıf da bir abstract class olur.

-> Virtual function içeren taban sınıfından türetilen sınıfın aynı imzaya sahip farklı geri dönüş değeri türü olan fonksiyonu dilin kurallarına aykırıdır.

-> Taban sınıfın sanal fonksiyonuyla aynı isimli fakat imzası farklı bir fonksiyon bildirilirse syntax hatası değildir ancak function overriding de değildir.

-> Taban sınıfın sanal fonksiyonunun imzası ve geri dönüş değeri türü aynı olan fonksiyon türetilen sınıfta bildirilirse o fonksiyonu override eder. 

-> Modern C++'ta contextual keyword olarak override ve final kelimeleri geldi. Sadece belirli şekilde kullanıldığında işlev yerine getirir. Normal bir keyword değildir yani değişken, fonksiyon vs.
adlandırırken kullanılabilirler. Eğer override eden bir fonksiyon mevcutsa bildiriminde "override" keyword'ünü kullanmak faydalıdır.

-> Eğer bir fonksiyon çağrısı taban sınıf türünden bir nesne ile değil taban sınıf türünden bir pointer değişken ya da taban sınıf türünden bir referans değişken ile yapılıyorsa "virtual dispatch" mekanizması devreye girer.

-> Taban sınıf pointeri veya taban sınıf referansıyla sanal fonksiyona çağrı yapıldığında çağrının yapıldığı zamanda pointer hangi türemiş sınıf türünden nesneti gösteriyorsa o nesnenin fonksiyonu çağrılır. (Override)

-> Taban sınıfından bir nesneyi türemiş sınıftan bir nesneye eşitlemek virtual dispatch mekanizmasını devreden çıkarır.

-> Bir taban sınıfın sanal fonksiyonunu override eden türemiş sınıfın fonksiyonu virtual specifier ile nitelenmemiş olsa da yine de sanal fonksiyondur.

Ex: 
class Base{
public:
  void foo(){
    vfunc();
  }
private:
  virtual void vfunc(){
    std::cout<<"Base::vfunc()\n;"
  }
};
class Der:public Base{
public:  
  virtual void vfunc()override{
    std::cout<<"Der::vfunc";
  }
};
int main(){
  Der myDer;
  myDer.foo();
}

-> İsim arama ve erişim kontrolü her zaman statik türüne göre yapılır.

-> Overload edilen fonksiyonlar olsa da override mekanizması çalışır.

-> Virtual keyword'ü global fonksiyonlar için kullanılamaz.

-> Sınıfın static üye fonksiyonu virtual olamaz.

-> Sınıfın ctor'ları virtual anahtar kelimesiyle bildirilemez. Ancak "virtual ctor" OOP paradigmasında bir ihtiyaç olabilir. C++ dilinde "virtual ctor idiom" veya "clone idiom" bu idiomatik yapıya verilen isimdir.
Bu idiom'u gerçekleştirebilmek için taban sınıfta bir virtual fonksiyon tanımlayıp başka bir taban sınıfının pointeri parametreli global fonksiyonda, taban sınıf pointer değişkeni, parametre değişkeni
virtual fonksiyonunu ok operatörüyle işaret eden ifadeye eşitleyerek elde edebiliriz.

-> Taban sınıf ctor'u içinde yapılan sanal fonksiyon çağrıları için virtual dispatch uygulanmaz. Aynı şekilde destructor için ve nitelenmiş isimle çağrı yapıldığında da virtual dispatch devreye girmez/uygulanmaz. 

-> Eğer taban sınıf pointeri türemiş sınıf türünden dinamik ömürlü bir nesneyi gösteriyorsa ve taban sınıfın dtor'u virtual değilse, taban sınıfın dtor'unun çağırılmasını sağlar. Dolayısıyla türemiş nesne
resource leak oluşturacaktır. Bu durumu önlemek için dtor'u da virtual olarak tanımlamalıyız ki leak oluşması bu dtor'a da "virtual dtor" denir.

-> Polymorphic sınıfların dtor'u ya public virtual ya da protected non-virtual olmalıdır. Base class protected olduğunda client protected dtor'u çağıramayacağından taban sınıf türünden pointerin türemiş sınıfından 
nesneyle  initialize edildiğinde nesnenin delete edilmesi syntax hatası olacaktır ve undefined behaviour elimine edilmiş olur.

-> Global fonksiyonlar virtual olamasa dahi bir kod örüntüsüyle virtual yapılabilirler.

-> Sınıfın boyutu fonksiyon ekleme ve çıkarılmasıyla değişmez ancak virtual olarak bildirilmiş bir fonksiyon sınıfın boyutunu 1 byte artırır. Bunun sebebi gonksiyon değil sınıfın tutacağı adreslerdir ve 2 veya daha 
fazla virtual bildirimi yapılması boyutu artırmaz.

*/
