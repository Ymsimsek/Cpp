/* 
Covariance: Normalde türemiş sınıf taban sınıfın sanal fonksiyonunu override ederken farklı bir geri dönüş değeri türü kullanamaz. Bu konuda bir istisna vardır ve bu "covariance" olarak adlandırılır.
Diyelim ki taban sınıf sanal fonksiyonunun geri dönüş değeri türü B* olsun. B'nin bir sınıf olduğunu varsayarak B'den türetilmiş bir D sınıfı varsa B* parametreli sanal fonksiyonu içeren bir taban sınıftan
türetilen sınıf da D* geri dönüş değeri türüne sahip fonksiyonu override edebilir.

Ex:
class B{};
class D: public B{};
class Base{
public:
  virtual B* foo();
  virtual B& bar();
};

class Der: public Base{
public:
  D* foo()override;
  D& bar()override;
};

*/
