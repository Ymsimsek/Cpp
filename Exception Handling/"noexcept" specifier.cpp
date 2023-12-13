/*
-> "noexcept" anahtar sözcüğüyle bildirilen isim exception göndermeyeceğini garanti eder ve derleyici yeni optimizastonları yapabilmesini
sağlar. 
- void foo(int)noexcept;

-> Bir fonksiyon exception vermeme garantisi verip exception verirse terminate fonksiyonu çağırılır. 
Ex:
void func(){  
  if(1){
    throw std::exception{};
  }
}
void foo()noexcept{
  func();
}
int main(){
  try{
    foo();
  }
  catch(const std::exception& ex){
    std::cout<<"exception caught"<<ex.what(); //Bu bloğa girilmeyecek çünkü noexcept beklenen yerde exception verildi ve terminate edildi.
  }
}

-> noexcept aynı zamanda bir operatördür. Oluşturulan ifade bool türündendir. Exception throw etme ihtimali yoksa operatörün
ürettiği değer true, varsa false'tur. 

Ex: 
noexcept(expr); 

Ex:
int a[5]{};
int x=4576;
constexpr boll b=noexcept(x+a);//noexcept true üretti

Ex:
void foo(){}
int main(){
  noexcept(foo());//noexcept false üretti 
}

Ex:
void foo()noexcept;
int main(){
  noexcept(foo());//noexcept true üretti 
}


-> Taban sınıfın sanal fonksiyonu noexcept garantisiyle oluşturulup türemiş sınıfta override eden fonksiyon noexcept 
garantisi vermemesi hata oluşturur. 

Ex:
class Base{
public:
  virtual void func()noexcept;
};

class Der: public Base{
public:
  void func()override; //Hata!!
};

Ex:
class Base{
public:
  virtual void func()noexcept;
};

class Der: public Base{
public:
  void func()noexcept override; //Legal
};

-> noexcept operatörünün operandı unevaluated context oluşturur. 

-> Destructor'lar her zaman görünmeden noexcept olarak bildirilir. 

























*/
