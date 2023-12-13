/*

-> Programming errors(coding errors) kodlama yapılırken, program yazılırken, yapılan hatalardır. Bunları assertions ile en aza indirmeye çalışırız. İki tip assertions vardır:
- Dynamic Assertions (Run-time)
- Static Assertions  (Compile Time)

-> Assertion kodları C'de Assert.h ile ekleniyordu. Yazılan kodu kontrol eden süreçtir. Assert makroları kullanılır.

-> C++'da da assertions mevcuttur. Ancak assertions exception handling kapsamında değildir.

-> Runtime Errors veya Exceptions, Exception handling kapsamındadır. Eğer işini yapamayan kod parçası kendisini çağıran koda bildirirse buna exception handling denir. 

-> Exception throw etmek için, "throw", "try" ve "catch" anahtar kelimeleri kullanılır. 

-> "throw" statement bir kontrol deyimidir. Program akışı üstünde kontrole sahiptir. Üst kısımdaki fonksiyonlara alt kısımdaki
fonksiyonda hata olduğunu bildiren, haberdar eden, statement throw statement'dir. Üst fonksiyonlara bir hata nesnesi iletir.
Bu olaya "exception throw" denir.

-> "try" anahtar sözcüğüyle oluşturulan bloğa try bloğu denir. 
Ex:
try{
  
}

-> Eğer bu blok içinde hata oluşacak olursa try bloğu bu hatayı yakalamaya aday olduğunu bildiren bloktur. Sadece blok içindeki
fonksiyonlardaki hatayı değil o fonksiyonun çağırdığı diğer fonksiyon zincilerindeki hataları da yakalamaya adaydır.
  
-> Her try bloğunu en az bir catch bloğu izlemek zorundadır. 

-> "catch" anahtar kelimesiyle catch blokları oluşuturulur. Catch blokları hataya müdahale eden kodu temsil eder. Bunlara exception
handler denir.
Ex:
try{
  
}
catch(int){
  
}
//Try bloğunda çalışan kodlardan biri bir hata nesnesi gönderirse gönderilen hata nesnesinin türü int ise program akışı catch bloğuna
aktarılıp hata nesnesi catch parametresi değişkenine kopyalanır. 

-> Catch bloklarında bu amaç için özel olarak kullanılan hata nesneleri kullanılır.

-> Farklı hatalara müdahale etmek için farklı bloklar kullanılabilir.

Ex:
try{
  
}
catch(int){
  
}
catch(double){

}
catch(long){

}

-> catch bir fonksiyon değildir. Dönüşüm kuralları geçerli değildir. Geri dönüş değeri yoktur. Promotion yoktur. İkinci parametreye 
izin yoktur.

-> try bloğunda bulunan hata nesnesi catch bloğuna aktarılırsa bu işe "to catch an exception" denir. (exception caught)

-> uncaught exception: Bir kod bir exception gönderir ancak yakalanmazsa bu duruma verilen addır. Bu durumda terminate fonksiyonu çağrılır.
Terminate fonksiyonu (std::terminate), abort fonksiyonunu çağırır. Abort fonksiyonu doğrudan programı kapatır. Terminate fonksiyonu
aborttan başka fonksiyon çağrıları yapabilecek şekilde konfigure edebiliriz. Terminate fonksiyonuna müdahale edebilmek için
set_terminate adında fonksiyona çağrı yapabiliriz. set_terminate bir fonksiyon adresi alıp yine bir fonksiyon adresi döndürür.

-> set_terminate fonksionu şu şekildedir:
terminate_handler set_terminate(terminate_handler); 
Başlık dosyasında şu bildirim kullanılarak function pointer'a eş isim oluşturulmuştur.
using terminate_handler = void(*)()

-> Programlarda kaynakların geri verilmesi gereklidir. Ancak exception yakalanırsa kaynaklar geri verilir. Bazı programlarda hata oluşursa 
programı kapatıp tekrar başlatmak bir seçenek olabilir bu yaklaşıma terminatif yaklaşım denir.

-> Resumptive yaklaşım ise exception'un yakalanıp kaynakların geri verilip programın akışına devam edilebilmesine verilen isimdir.

-> Rethrow statement: 

throw;

-> throw expr; statement'da oluşturulan nesne expression'un kendisi değildir. Throw statement'daki ifade aynı türden başka bir nesne 
oluşturur ve onu gönderir.

Ex:

class mathException{
//...
};

int main(){
mathException m;
throw m; // m nesnesinin kendisi değil, mathException sınıfı türünden nesne gönderilir.
}

-> Hemen hemen her zaman taşıma veya copy elision kullanmak için PR value expression throw statement'da kullanılır.

-> Up-casting dönüşümüne izin verilir. Catch parametreleri hemen her zaman referans semantiğiyle oluşturulur. Copy ctor'un çağırılmaması
içindir.

-> Hata yakalanırken hiyerarşik sınıflar kullanılabilir. Up-casting ile bir hata hem türemiş hem de taban sınıf nesnesi kullanılarak
yakalanabilir.

Ex:
class exBase{
public:
  virtual const char* what()const{
    return "exbase";
  }
};

class mathException: public exBase{
public:
  virtual const char* what()const override{
    return "mathException";
  }
};

class divideByZero: public mathException{
public:
  virtual const char* what()const override{
    return "divideByZero";
  }
};

void f1(){
  throw divideByZero{};
}
int main(){
  try{
    f1();
  }
  catch(divideByZero&){
    std::cout<<"hata yakalandı";
  }
  catch(exBase&){
    std::cout<<"hata yakalandı";
  }
  catch(mathException&){ 
    std::cout<<"hata yakalandı";
  }
  catch(const exBase& ex){ // Eğer referans olmazsa virtual dispatch devreye girmez ve copy ctor çağırılırdı.
    std::cout<<"hata yakalandı";
  }  
}

-> catch parametreleri hiyerarşik düzende özelden genele doğru sıralamalayız. 

-> catch(...){} bloğu tüm hataları yakalar.(catch all) Özelden genele doğru sıralamada son sırada olmalıdır. 

-> Standart kütüphanenin gönderebileceği exception'ların oluşturduğu bir hiyerarşi vardır ve virtual dispatch mekanizması da uygulanır.
En tepede exception sınıfı vardır. Gönderilen bütün exception'lar exception sınıfı türündendir bütün exception sınıfları bu sınıftan
kalıtım yoluyla elde edilmiştir. 

-> Exception sınıfın what() fonksiyonuyla hatanın ne olduğunu string halinde görebiliriz.

-> std::bad_alloc: operatör new fonksiyonu başarısız olduğunda throw edilen exception türüdür.

Ex:
class Nec{
  unsigned char buf[1024*1024]{};
};
int main(){
  std::vector<Nec*> nvec;
  try{
    for (int i=0;i<1'000'000;++i){
      nvec.push_back(new Nec{});
    }
  }
  catch(const std::exception& ex){
    std::cout<<"exception caught"<<ex.what<<'\n'; //bad alloc
    std::cout<<"i="<<i<<'\n';
  }
}

-> bad_cast: dynamic_cast operatörüyle down casting yapılırken başarısızlık durumunda gönderilen hata sınıfıdır.

-> bad_typeid: typeid operatörü pointeri dereference edilip nullptr olduğunda gönderilen hata sınıfıdır.

-> Exception yakalandığında tipik olarak 4 senaryo devreye girebilir:
1. Resumption: Exception yakalanır. Kaynak sızıntısı olmadığı garantisi verilir ve akış o noktadan devam eder.
2. Terminate: Exception yakalandıktan sonra programın sonlandırılmasının tercih edilmesidir.
3. Kısmi müdahale: Kısmi müdahale gerçekleştirip exception'un rethrow edilmesidir.
4. Translate: Exception'u yakalamak ve translate etmektir. Kısmi müdahale yapılabilir ya da yapılmayabilir. Yani alt seviyedeki exceptionu
üst seviye exception'u gönderilmesidir.

-> Ne yapılacağı bilinmiyorsa exception yakalanması anlamsızdır. 

-> try ve catch bloklarında bildirilen isimler o bloğun scope'undadır.

-> Exception yakalandığında bir kaynak sızıntısı olmayacağından emin olunmalıdır yani akış şu şekilde olmalıdır. 
a) Exception'lar yakalanıyor mu?
b) Hataların yakalanması durumunda kaynak sızıntısı oluyor mu?

-> Stack Unwinding: Zincileme şeklinde yapılan fonksiyon çağrılarında, fonksiyonların içinde tanımlanan nesneler için 
exception yakalanmadığında destructor'larının çağırılma garantisi yoktur. Bir exception yakalandığında, bu zincirleme 
fonksiyonlarda oluşturulan otomatik ömürlü nesnelerin kaynaklarının sırasıyla geri verileceğinin garanti verilmesidir. 
Sıralama son çalışan fonksiyonun kaynaklarını ilk olarak vereceği şekildedir. 

-> Dinamik ömürlü nesneler stack'te değil heap'te yer aldığından dinamik ömürlü nesneleri smart pointer'lara bağlamak 
stack unwinding mekanizmasının çalışması için kullanılabilir.

-> Aksi biçimde davranmamızı gerektirecek bir durum söz konusu değilse dinamik ömürlü nesneler ham kaynaklarla değil, 
smart pointer nesneleriyle kullanılmalıdır.

-> Eğer catch parametresi kullanılmayacaksa değişken kullanılmamalıdır.

-> Exception'un Rethrow Edilmesi: 

-> Aşağıdaki örnek rethrow statement değildir:
Ex:
try{
 foo();
 //
}
catch(const std::mathError& ex){
  //
 throw ex; // Burada mathError sınıfının copy ctor'u çağırılır. Hata nesnesi destruct edilmeden yeni nesne 
 //oluşturulur. Copy ctor ile yeni nesneye hata nesnesi kopyalanır ve sonra yeni üretilen nesne destruct edilir.
}

-> Aşağıdaki örnek rethrow statement'dir.
Ex: 
void func(){
  try{
    throw std::out_of_range("range hatası");
  }
  catch(const std::exception% ex){
    std::cout<<"hata func icinde yakalandı: "<<ex.what()<<'\n';
    throw; //burada "throw ex;" şeklinde ifade oluşturulursa rethrow olmaz. std::exception türünden exception throw edilir. !!
  }
}
int main(){
  try{
    func();
  }
  catch(const std::out_of_range&){
    std::cout<<"hata yakalandı out of range.\n";   //Ekrana bu basıldı, out of range yakalandı. 
  }
  catch(const std::exception&){
    std::cout<<"hata yakalandı std::exception.\n";
  }
}

-> Aşağıdaki kod legaldir. Rethrow statement catch bloğunun içinde fiziksel olarak bulunmak zorunda değildir.

void bar(){
  throw;
}

void foo(){
  try{
    if(1){
      throw std::out_of_range{"out of range error"};
    }
  }
  catch(const std::exception&){
    bar();
  }
}
//Burada exception dispatcher mekanizması kullanılır. 

-> Rethrow mekanizmasında da exception yakalanmazsa program yine terminate edilir. 

-> Bir nesne hayata getirilemiyorsa, ctor exception throw etmelidir. 
Ex:
class myClass{
public:
  myClass(int x){
    if(x<0){
      throw std::invalid_argument{"gecersiz arguman"};
    }
  }
  ~myClass(){
    std::cout<<"destructor myClass\n";
  }
};

int main(){
  try{
    myClass m{-12}; //Nesnenin ctoru oluşturulurken ctor bloğu içinde exception throw ediliyor. Destructor çağırılmıyor.
  }
  catch(const std::exception& ex){
    std::cout<<"exception caught: "<<ex.what()<<'\n'; 
  }
}

-> Exception Safety: Exceptionların yakalanıp, resource leak oluşturulmamasına exception safety denir.

-> Nesneler akıllı pointerlara bağlanırsa ctor içinde exception throw edilse dahi destructor'ları çağırılır.

Function Try Block: Ctor initializer list'de sınıfın data memberlerini initialize ederken ctor'un içinde exception yakalanmasını
sağlayan mekanizmadır. Herhangi bir fonksiyon için kullanılabilir.

Ex:
void func(int x)
try{
   if(x<0)
     throw std::runtime_error{"gecersiz deger"};
}
catch(const std::bad::alloc&){

  return 1;

}

Exception Guarantees: Bir exception mutlaka aşağıdakilerden birine dahil olmalıdır. 
1. Basic Guarantee: Exception yakalandığında kesinlikle bir kaynak sızıntısı oluşması ya da programın geçersiz bir duruma
gelmesinin önüne geçilmesidir. Nesnelerinin state'inin değişmesini engellemez.
2. Strong Guarantee: Basic garantinin güvencelerini verir ve ek olarak state'i korur. (Ya işini yap ya da işe başlamadan önceki 
durumu koru) (commit or rollback)
3. Nothrow Guarantee: Exception vermeyeceğini garanti eder. Derleyici bazı fonksiyonların exception vermeyeceğini bilip daha 
iyi optimizasyon verir. 






*/
