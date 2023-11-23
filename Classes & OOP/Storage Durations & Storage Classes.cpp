/*
Storage Duration: (Storage Class)
- Automatic Storage Class: Fonksiyon parametreleri ve fonksiyon içinde static kelimesi olmadan tanımlanan yerel değişkenler örnek olarak verilebilirler.
- Static Storage Class: Main fonksiyonu çağırılmadan yer elde edilir. Global nesneler, static kelimesi ile tanımlanan yerel nesneler, sınıfların static veri elemanları örnek olarak verilebilir.
- Dynamic Storage Class: "new" ifadeleri ile hayata başlatılan nesnelerin storage class'ıdır. 
- Thread Local Storage Class

-> Bir nesnenin life spani'ni storage class'ı belirler. 

Global Sınıf Nesneleri:
-> Static storage class'a tabilerdir. cout, cin gibi işlevler global sınıf nesneleridir. Hayatları main çağırılmadan başlar.

-> Aynı kaynak dosyada tanımlanan iki sınıfın constructor çağırma sırası bildirim sıralamasına göre yapılır. İlk bildirilen nesne ilk çağırılır. En son bildirimi yapılan nesne ise ilk destruct edilendir.

-> Aynı programın farklı kaynak dosyalarında tanımlanan global sınıf nesnelerinin ctor'larının çağırılma sırası dil tarafından belirlenmiş değildir.

-> Eğer bir sınıf nesnesi için çağırıları ctor'un içinde, başka bir kaynak dosyadaki global bir sınıf değişkeni kullanıyorsak hayata gelmeden kullanma olasılığı meydana gelir ve tanımsız davranış olur. Buna static init fiasco denir. 

-> "static" kelimesiyle tanımlanan yerel sınıf nesneleri ancak o fonksiyon çağırılınca  hayata gelir, programın sonuna kadar hayatları devam edecek ve eğer fonksiyon tekrar çağırılırsa yeni bir nesne çağırılmayacaktır. 

Ex:
class myClass{
  myClass(){}
  ~myClass(){}
};

void foo(){
  static myClass m;
}

int main(){
  foo();
  foo();
  foo(); // Fonksiyon 3 kez çağırılmasına karşın 1 adet m nesnesi yaratılmıştır. Main bitince nesne destruct edilir. 
}

Otomatik Ömürlü Sınıf Nesneleri:
-> Otomatik ömürlü sınıf nesneleri, programın akışı onların tanımı noktasına gelince ctor'ları çağırılacak programın akışı scope sonuna gelindiğinde dtor'ları çağırılacak. 

-> Statik ömürlü nesneler, default veya value initialize edilseler de önce zero initialize edilirler. İlk değerleri sıfır olur. (Pointer ise nullptr)

-> ctor'u olan nesne direct initialization ile çağrı yapıldığında initialize edilen değer ctor'a argüman olarak gider. (veya copy init)

Ex:
class myClass{
public:
  myClass(int x){
    std::cout<<"myClass(int x) = "<< '\n';
  }
};
int main(){
  myClass m1(10); //direct init
  myClass m2=20; //copy init
  myClass m3{57}; //direct list init
}

-> Yukarıdaki 3 kullanım da değerleri ctor'a argüman olarak gönderir. Direct ve copy init'de float ifade kullanılırsa uyarı mesajı alırız ancak direct list init'de syntax hatası alırız.

-> ctor için de function overloading kuralları geçerlidir.

-> Parametreli ctor bildirildiğinde normalde ctor tanımlanmadığında kendiliğinden tanımlanan default ctor tanımlanmaz. (Default çağrı yapılınca)

*/
