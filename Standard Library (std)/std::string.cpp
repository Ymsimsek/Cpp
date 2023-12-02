/*
std::string: Bir sınıf şablonudur (class template). Container niteliği taşır. Sequence containers'a tabidir. String yazı isimleri için interface'i özelleştirilmiş
dinamik dizi sınıfıdır. Operator overloading'den çokça yararlanan bir kütüphanedir. Karşılaştırma operatörlerini, spaceship operatörü ile overload ederler (C++20 ile eklendi). 

-> String fonksiyonlarda, yazı uzunluğu türü, kapasite türü, bir ya da iki parmetre indeks değeri, karakterlerin adet sayısı, npos;"size_type" türü cinsindendir. (std::string::size_type)

-> String fonksiyonlarına girilebilen bazı argümanlar ve temsiliyetleri:
- const string& //whole string 
- const string&, size_type idx//sub string, indexten string sonuna
- const string&, size_type idx, size_type len //substring, indexten len kadar ileri
- const char* //cstring, son parametresi nullptr olan string
- const char*, size_type len //Data parameter, char* adresinden len kadar ileri
- char //karakter
- size_type n ,char c //n adet c karakteri
- iterator beg, iterator end //range parameter

Ex:
int main(){
  std::string s1(50,'A'); //50 Adet A karakterine sahip dizi 
  std::string s2{50,'A'} //2 ve A karakterlerine sahip dizi
}

String Sınıfının Fonksiyonları: 

Ex:
int main(){
  using namespace std;
  string s1; //Default ctor'u çağırılacak boş yazı tutacak 
  cout<<"s1.length()="<<s1.length()<<'\n'; // "0" değeri döndürülecek, dizinin uzunluğunu gösteren fonksiyon length()
  cout<<"s1.size()="<<s1.size()<<'\n'; //  "0" değeri döndürülecek, dizinin boyutunu gösteren fonksiyon size(), common container interface
}

-> Stl container'lerin tutuğu öğe sayısını döndüren fonksiyon size() öğe fonksiyonudur. (forward list hariç) (Generic programlamada)

Ex:
int main(){
  using namespace std;
  string s1;
  s1.empty(); // empty boolean fonksiyonudur. 0 veya 1 olarak çıktı verir. Eğer container boşsa 1 döndürür.
  }

Ex:
int main(){
  using namespace std;
  string str("ahmet");
  cout<<str.size(); // 5
}

Ex:
int main(){
  using namespace std;
  char ar[] = {'A','B'}; // C ctor
  string str(ar); //Undefined behaviour
}

Ex:
int main(){
  using namespace std;
  char ar[] = "murathan";
  string str(ar+3,2); //"ar+3" parametresi dizinin başlangıcını 3 karakter ileri attı ve "2" parametresi başlangıçtan 2 karakteri bastı
  cout<<str; // "at" ekrana basılır. 
}

Ex:
int main(){
  using namespace std;
  char ar[] = "murathan";
  string str(ar,20); // ub 
}

Ex:
int main(){
  using namespace std;
  char ar[] = "murat"; //dizi sonunda null character var
  string str(ar,6); // Hata yok 
}

-> Geçici nesne kullanabilirken nesneleri isimlendirdiğimizde boşuna copy elision veya taşıma devreye girer. Onun yerine geçici nesne ile sorunları çözmek daha iyi bir çözümdür.

Ex:
int main(){
  using namespace std;
  size_t n;
  cout<<"kaç tane";
  cin>>n;
  cout<<string(n,'*'); //n kadar '*' karakteri ekrana basılır. 
}

Ex:
int main(){
  using namespace std;
  string str(20,'\0'); // 20 adet null character tutar 
}

Ex:
int main(){
  using namespace std;
  string s1(100,'A'); 
  string s2(s1); //copy ctor çağırılır. l value verildi
  string s3(std::move(s1)); //move ctor çağırılır. s1'i sağ taraf referans yaptığı için move ctor çağırılır. 
}

-> String sınıfının ctor'ları arasında tek karakterli parametreye sahip ctor bulunmaz. Tek karakter içeren bir sınıf nesnesi şu şekillerde oluşturulabilir:
- string s1("a"); //cstring ctor
- string s2(1,'A'); //fill ctor
- string s3{ 'A' }; //init list ctor

-> String sınıfı nesneleri assignment operatörüyle bir karaktere eşitlenebilir. Yani char parametreli atama operatör fonksiyonu vardır.

Ex:
string s1{"cengizhan"};
string s2(s1,3); //gizhan 
string s3(s1,3,3) //giz, substring ctor

-> Substring parametre oluşturulurken belirtilen uzunluk bahsi geçen string değerinden uzunsa bunun anlamı geriye kalan değerlerin hepsinin dahiliyetini belirtir. 

Ex:
int main(){
  using namespace std;
  char str[] = {"gokhan girgin"};

  string s1{str}; //cstr, gokhan girgin
  string s2{str,3}; //array, gok
  string s3{str, str+4}; //range, gokh
}

-> String nesneleri "size_t capacity()const" fonksiyonunu içerirler ve capacity() fonksiyonu kullanılarak ayrılan belleğin kapasitesi kullanılabilir.
Başka bir deyişle, kapasite dolmadan reallocation yapılmayacaktır.

Ex:
string str(153, 'A');
cout<<str.size()<<'\n'<<str.capacity()<<'\n'; //size: 153, capacity:159 olarak görüldü. Dizi 6 karakter daha alsa da reallocation yapılmayacak.
str+= "gokhan"
cout<<str.capacity()<<'\n';

-> String ve vector sınıflarında kapasitenin artış katsayısı derleyiciye bağlıdır.

Ex:
string str(40,'A');
auto cap = str.capacity();
int cnt{};
while(str.size<500'00){
  str.push_back('A');
    if(str.capacity() > cap){
    cout<<++cnt<<".reallocation\n";
    cout<<"size= "<<str.size()<<'\n';
    cout<<"capacity= "<<str.capacity()<<'\n';
    cap=str.capacity();
    (void)getchar();
    }
}

-> reserve() fonksiyonu ile string nesnesi için ayırılan boyut baştan belirlenip reallocation'un önüne geçilebilir. String'in kaplayacağı boyut baştan tanımlandığı
takdirde reallocation ile kopyalamaya gerek kalmayacaktır. Reserve fonksiyonu size'ı değil kapasiteyi artırır.

Ex:
string str(40,'A');
auto cap = str.capacity();
int cnt{};
str.reserve(600'000)
while(str.size<500'00){
  str.push_back('A');
    if(str.capacity() > cap){
    cout<<++cnt<<".reallocation\n";
    cout<<"size= "<<str.size()<<'\n';
    cout<<"capacity= "<<str.capacity()<<'\n';
    cap=str.capacity();
    (void)getchar();
    }
}

-> SSO: Small String Optimization, küçük ve uzunluğu kısa stringlerin doğrudan string nesnesinin içinde oluşturulmasıdır. 

Elemanlara Erişim Fonksiyonları:

-> "[]" operatör fonksiyonu yardımıyla string'in öğelerine erişim sağlayabiliriz.

Ex:
int main(){
  using namespace std;
  string str{"burak kose"};
  for(size_t i{};i<str.length();i++){
    cout.put(str[i]); //burak kose 
  }
  str[2]='s'; // bsrak kose
  cout<<str<<'\n';
}

-> const stringlerin index operatörüyle öğe değiştirmesi undefined behaviour'dur.

-> at() fonksiyonu ile öğelere erişim sağlansa dahi const string'lerin öğeleri değiştirilmeye çalışıldığında at() fonksionu exception throw eder ve index operatöründen farkı budur.

-> "at()" ve "[]" vector gibi diğer containerlerda da geçerlidir.

-> front() ve back() fonksiyonları ilk ve son elemanlara referans döndürürler.

Range Based For Loop:
Ex:
int main(){
using namespace std;
vector ivec{2,4,5,76,32,5,6};
list ilist{23,543,765,43,74,21};
string str{"mehmet"};

for(auto iter = ivec.begin();iter!=ivec.end();++iter){
  cout<<*iter<<' ';
}
for(auto iter = ilist.begin();iter!=ilist.end();++iter){
  cout<<*iter<<' ';
}
for(auto iter = str.begin();iter!=str.end();++iter){
  cout<<*iter<<' ';
}
}
--------Yukarıdaki örneği kendimiz yazıyoruz------------

for(auto i : str) //Range Based Loop
  cout<<i<<' ';
for(auto i : iter) //Range Based Loop
  cout<<i<<' ';
for(auto i : ilist) //Range Based Loop
  cout<<i<<' ';

->Range based loop örnekte bizim yazdığımız kodun derleyiciye yazdırılmasıdır. Modern C++'da dile eklenmiştir. Diziler için dahi kullanılabilir.

String Modifiers: 
- Parametresi cstring olan atama operatör fonksiyonu
- Parametresi char olan atama operatör fonksiyonu
- Move Assignment
- Copy Assignment
- Initializer list parametreli atama operatör fonksiyonu
- Resize fonksiyonu

Ex:
std::string get_name(){
  return "kerim";
}
int main(){
  using namespace std;
  string name = "tayyip erguder";
  
  string str{"mustafa"};
  cout<<"|"<<str<<"|\n";
 
  str=name;   //copy assignment
  cout<<"|"<<str<<"|\n";
 
  str=get_name(); //move assignment
  cout<<"|"<<str<<"|\n";
 
  str="alican"; // Parametresi cstring olan atama operatör fonksiyonu
  cout<<"|"<<str<<"|\n";

  str='x'; //Parametresi char olan atama operatör fonksiyonu
  cout<<"|"<<str<<"|\n";
  
  str={'a','l','i'}; //Parametresi initializer list olan atama operatör fonksiyonu
  cout<<"|"<<str<<"|\n";
}

Ex:
int main(){
  using namespace std;
  string name = "tayyip erguder";
  cout<<"name.size()="<<name.size()<<'\n'; //name.size()=14
  name.resize(20); //ilk 14 karakter aynı kalmak üzere dizinin size'ı 20'ye çıktı.
  cout<<"name.size()="<<name.size()<<'\n'; //name.size()=20
  name.resize(20,'!'); //ilk 14 karakter aynı kalmak üzere dizinin size'ı 20'ye çıktı. Eklenen karakterler ! oldu.
  cout<<"name.size()="<<name.size()<<'\n'; //name.size()=20
  name.resize(6); //tayyip, sondan silme işlemi yapılıyor.
  cout<<"name.size()="<<name.size()<<'\n'; //name.size()=6  
  name.resize(0); //Stringin öğeleri silinir.
  name.clear();//String temizlenir.
  name="";//String temizlenir.
  name={};//String temizlenir.
}

-> push_back fonksiyonu string'e sondan bir karakter ekler. 

Ex:
string str{"m"};
str.push_back('u');

-> "+=" operatörünün overload'u vardır. Sağ operandı çağırıldığı dizinin sonuna ekler.
Ex:
string str{"deniz"};
string s{"han"};
str+=s; //denizhan


-> assign(), fonksiyonu ile atama operatörüyle yapamadığımız tekrarlı atamaları yapmamızı sağlar.
Ex:
string str{""};
str.assign("nurhan");
str.assign(10,'T');

-> append() Fonksiyonu: Bu fonksiyon ile "+=" operatörüyle yapamadığımız daha karmaşık ekleme işlemlerini yapabiliriz.

Ex:
int main(){
  using namespace std;
  string s1 = "omer faruk";
  string s2 = "selma deniz";
  s1.append(s2,5); // s2'nin 5. indexinden başlayarak kalanların s1'e eklenmesini sağlar.
  cout<<s1<<'\n'; //omer faruk deniz
  s1.append(s2,1,4);
  cout<<s1<<'\n'; //omer farukelma
  s1.append(s2,1,s2.npos); //s1'in sonuna s2'nin 1. elementinden sonuna kadar eklenir
  s1.append(12,'A'); //Fill parameter, s1 sonuna 12 tane A eklenecek
}

Insert ve Erase fonksiyonları:
-> container.insert(iter, value): Spesifik bir konuma belirli değeri yerleştirir. O konumda yer alan değer silinmez, insert edilen değer eklenir, o konumdan sonraki konumlarda yer alan ifadelerin konumları ileri gider.Insert fonksiyonu, index interface'i
ile çalışırsa "*this" döndürür. 
-> container.erase(): Tüm container'ların 2 adet erase fonksiyonu vardır. Erase fonksiyonlarından biri bir iterator konumunu alır ve o konumdaki öğeyi stringten cıkarır. Geri dönüş değerleri silinmiş değerin sonrasındaki ilk öğenin konumudur.
Diğer erase fonksiyonu ise range alır ve o range arasındaki değerleri siler yine geri dönüş değeri silinen öğelerden sonra silinmemiş olarak kalan ilk ifadenin konumudur.
Silme fonksiyonuna index verilirken konumu ve kaç karakter silineceği girilmelidir. Direk konum verilmesi o konumdan string sonuna kadar olan tüm elemanları siler.

Ex:
using namespace std;
vector ivec{2,3,4,6,9,1};
ivec.insert(ivec.end(), 6);
string s{"mehmet bal"};
s.insert(s.begin(),'!');//smehmet bal
s.insert(s.begin()+3,'!');//mehsmet bal
while(!s.empty()){
  s.erase(s.begin()); //s.pop_back(); 
}
s.erase(s.begin(),s.begin()+3);//met bal
s.erase(s.end()-3,s.end());//mehmet bal
s.insert(0,'!');//!mehmet bal;
s.insert(0,20,'A');//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAmehmetbal
s.insert(s.size(),"ekrem");//mehmet bal ekrem


Arama Fonksiyonları:
->static constexpr string::sizetype npos: Değeri string sınıfı için size_t'nin alabileceği en büyük değerdir. Bir çok fonksiyon parametrelerinde index ve bir tam sayı istiyor. Indexten sonraki karakter sayısı 
geriye kalan karakterlerden daha fazlaysa normalde undefined behaivour oluşturuyordu. Stringin sonuna kadar tüm elemanları ifade içine almak için npos kullanılabilir.  
Ex:
std::cout<<"npos= "<< std::string::npos;//npos=4294967295

-> constexpr olduğu için değiştirilemez. Başka bir değişkene atanabilir ve ilk değer verebilir.

-> npos hiçbir yazıya geçerli bir index olamaz. String sınıfının arama fonksiyonları indeks döndürürler. Aranan değerin bulunamaması durumunda sizetype türünden npos döndürürler.

Arama fonksiyonları: Aranan değere "key" denir. Aranan bulunduğunda indeksini, bulunamazsa npos'u döndürürler. 
Bir parametreleri aramanın yapılacağı substring'in indexini alır ve default argüman olarak 0 elemanını alır.  
- std::string::size_type find(): Karakter, cstring, substring, string'lerde arama yapar. Index döndürür.
- std::string::size_type rfind(): Aramayı sondan yapar. Stringin sonuna en yakın konumda bulunan aranmış ifadenin indexini döndürür.
- std::string::size_type find_first_of(): Bir yazıdaki karakterlerden herhangi birinin bulunduğu ilk indexi döndürür.
- std::string::size_type find_last_of():
- std::string::size_type find_first_not_of(): Bir yazıdaki karakterlerden herhangi birinden olmayan karakterin ilk indexini döndürür.
- std::string::size_type find_last_not_of()
- starts_with(): Yazının aranan baslıkla baslayıp başlamadığını değerlendirir. Boolean döndürür. (C++20)
- ends_with(): Yazının aranan baslıkla bitip bitmediğini değerlendirir. Boolean döndürür. (C++20)
- contains(): Stringte aranan kelime var mı yok mu kontrol eder. Boolean döndürür. (C++23)

Ex:
int main(){
  using namespace std;
  string str;
  char c='a';
  
  cout<<"yazı girin ";
  cin>>str;
  
  string::size_type idx = str.find(c); //if with initializer ile kullanımı alttaki örnekte
  if(idx!=string::npos){
    cout<<"bulundu. idx= "<<idx<<'\n';
    str[idx]='*';
    cout<<"|"<<str<<"|\n";
  }
  else{
  cout<<"bulunamadı\n";
  }

}

Ex:
//Yukarıdaki örnekteki idx değişkeni scope'lar arası karmaşıklık yaratabilir. if with initializer (C++17) ile bunun önüne geçilebilir.
if(auto idx=str.find(c); idx !=string::npos){
//...
}
else(){
//...
}

Substring İşlemleri:
Substring'lerle yapılan işlem bir string döndürür. Ayrı bir allocation yapılması gerektiğinden görece maliyetlidir. Çok uzun yazının belirli bir alanını substring yapmak yerine substring yapılması planlanan aralığın
ilk ve son öğelerinin konumlarıyla C++17 ile eklenen string_view fonksiyonu kullanılabilir.

Ex:
using namespace std;
string str{"melike kaptan"};
str.substr(0,npos);//stringin kendisini elde ederiz. Ancak kopyalama işlemi yapılır.
str.substr(7);//7. elemandan string sonuna
str.substr(7,3);//7. elemandan 3 eleman uzunluğunda substring

Karşılaştırma İşlemleri: C++20 ile spaceship operatörü eklendi. String nesneleri tüm kıyas operatörlerini overload eder. 

Ex:
string name{"ayhan"};
string word{"ekrem"};
if(name==word);
if(name>word);
if(name<word);
if(name<=word);

strcmp() Fonksiyonları: int strcmp(s1,s2), s1>s2 ise geri dönüş değeri 0'dan büyük, s1<s2 ise geri dönüş değeri sıfırdan küçük, s1=s2 ise de geri dönüş değeri 0 olur.

Ex:
string name{"ayhan"};
// int result{name.compare(? ? ?)};
// result > 0, result < 0, ...

data() Fonksiyonu: data() allocate edilmiş bellek bloğunun adresini döndürür. 

Ex:
string name{"bugun gunlerden pazartesi"};
name.data() //adres olarak kullanılabilir. Bu işlev için cstr ve data kullanılanılabilir.
name.c_str() //geri dönüş değeri const char*, sadece okuma yapılabilir. 
std::strlen(name.cstr()) //c api'sine argüman olarak geçilebilir.

-> data() ve c_str fonksiyonlarında dangling pointer'a dikkat etmek gerekir.

Ex:
string s{pazartesi};
const char* p= s.c_str();
puts(p);
s+="salı";
cout<<s<<'\n';
cout<<p<<'\n'; //ub var, p dangling pointer haline geldi. 

-> data() ve c_str() null terminated byte stream olarak verirler. 

-> Stringden öğe silindiğinde kapasite değişmez. Capacity shrink için shrink_to_fit() fonksiyonu bulunmaktadır.

Ex:
str.shrink_to_fit();








*/

