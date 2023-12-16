/*
Vectors: Vector'lerin en büyük avantajlarından birisi, vektörlerin bellekte contiguous memory'de tutulmasıdır. (cash friendly)
Dinamik dizi veri yapısıdır. Öğelerin, bellekte tek bir blokta contiguous, ardışık, olarak tutulduğu veri yapısıdır ve temel avantajı
sondan ekleme ve sondan silme işlemlerinin amorti edilmiş sabit zamanda yapılacaktır. Aynı zamanda indeks erişimi de constant zamandadır.

Örnek Template:

template<typename Elem, typename A = std::allocator<Elem>>
class Vector{
  
};
-> Her container birçok nested type barındırır. Her container'in value_type isimli bir nested type'ı vardır. Containerde tutulan öğenin 
türünün eş ismidir. 

Reallocation: Maliyetli bir işlemdir. Gereksiz bir reallocationdan kaçınmak gerekir. Kapasite otomatik olarak büyütülebilir ancak kapasite otomatik
olarak büzülmez. 

Vector Access Fonksiyonları:
-> Container'in kategorisinden bağımsız olarak hemen hemen her container'de yer alan üye fonksiyonlar vardır. Örneğin, .size().
size() ve empty() fonksiyonları const fonksiyonlardır. 

-> empty() bool döndürür. Container boş ise true, değil ise false döndürür.  

-> clear() erase all işlemi yapar ve tüm öğeleri siler.

-> Containerlerin tipik olarak iki erase overload fonksiyonu olur. Birisi hangi iterator verilirse o konumdaki öğeyi siler. Diğeri ise verilen range'deki
öğelerin tamamını siler. Silinen hücre sayısı kadar size azalır. Her silme fonksiyonuna yapılan çağrı, onların ctor ve destructorlarını çağırır. 

-> front() containerin ilk, back() son öğesine erişir.

-> push_back() ve push_front()'un ikişer overload'ları vardır. T& ve T&&, copy ve move ctor için. 

-> Bazı sınıflar non-copyable non-movable'dır. Bu containerler'da emplace_back fonksiyonu kullanarak move veya copy ctor kullanmak yerine derleyiciye
doğrudan containerin içerisinde push_back yapılacak öğeyi ctor'a argüman geçerek oluşturabiliriz. İçinde emplace sözcüğü geçen fonksiyonlar,
çağıran koddan ctor'a gönderilecek argümanları alıp o argümanları perfect forwarding mekanizmasıyla sınıfın ctor'una gönderip ctor'un doğrudan
container'in elde ettiği bellek alanında yani o adresi this* olarak kullanıp nesnenin oluşturulmasını sağlarlar. Bu nedenle parametrenin 
universal reference olması gerekir:
Container class def içinde: 
template<typename ...Args>
void emplace_back(Args&& ...args){
  T(std::forward<Args>(args)...)
}

-> size() ve capacity() fonksiyonları size_type türünden geri dönüşe  sahiptir. 

Ex:
int main(){
  using namespace std;
  vector<int>ivec(10);
  auto cap = ivec.capacity();
  while(ivec.size()<5'000'000){
    ivec.push.back(1);
    if(ivec.capacity>cap){
      cout<<++cnt<<ivec.size()<<ivec.capacity(); //32 kez reallocation oldu. 5 milyona çıkılacağı bilindiğinde baştan reserve edilmeliydi. ivec.reserve(6'000'000) while bloğundan önce koyulmalı.
      cap=ivec.capacity();
      (void)getchar;
    }
  }
}


Vector'ün Üye Fonksiyonları:

Default Ctor: size 0 olan boş vector nesnesi yaratılır. Default ctor ile oluşturulan vector nesnelerinde front,end,begin,end fonksiyona
yapılan çağrılar tanımsız davranış olur. 

Fill Ctor: Parametre türü container::size_t'dir. Örn. vector<int> ivec(20);
Ex:
vector<int> vec1(12);
vector<int> vec2{12};
cout<<vec1.size()<<" "<<vec2.size(); //12 1

Range Ctor: Belirli bir range iteratorleri kullanarak vectorü initialize etmemizi sağlar.
Ex:
int main(){
  using namespace std;
  string a[]={"ali","veli","eda","can","sefa","mahmut"};
  vector<string>vec{begin(a),end(a)};
}
Range Assign:
auto myset = set<int>{ivec.begin(),ivec.end()}; //karmaşık dizilimde ve bazı öğeleri birden fazla olan ivec ile set initialize edilirken öğeler sıralandı ve her öğeden birer tane kaldı.
ivec.assign(myset.begin(),myset.end());//range assign ile set'de sırası düzenlenmiş ve her elemandan birer tane kalmış set'in parametreleri ivec'e assign edildi.

Init list Ctor: CTAD'dan faydalanır. 

Vektörlerde Öğeye Erişim:
1. "[]", indeks operatörü
2. at() fonksiyonu
3. iterator'un dereference edilişi

Ex:
vector<string> svec{"can","ayhan","melike","alp","nur"};
//svec[2] yazmak şu anlama gelir: svec.operator[](2)
svec[2] = "mehmet";
svec[2] += "can";
svec.at(1)[0] = 'T';
svec[2][0] = 'A';

//[] operator fonksiyonu ve at() fonksiyonu arasındaki fark [] operator fonksiyonu geçersiz ifade durumunda undefined beha. oluşturur. at(), exception throw eder. (out of range)
 
svec.front() += "can";
svec.back() += "mavi";

Traversing across elements: 

for(size_t i{};i<svec.size();i++){
  std::cout<<svec[i]; 
}

for(auto iter= svec.cbegin();iter!=svec.cend();++iter){
  std::cout<<*iter;
}

for(const auto& s:svec){//range based loop, & kullanmazsak her indeks kopyalanmış olur. const kullanma sebebimiz de nesneyi değiştirmemek
//iterator döngüsünü derleyiciye yazdırırız. 

}
for(auto riter=svec.rbegin();riter !=svec.crend();++riter){ //reverse loop


}

Container Üzerinde Mutation Yapan Fonksiyonlar:
push_back(const T &r)//copy ctor
push_back(T &&r)//move ctor
emplace_back(U&& ...args)//perfect forwarding, nesne içerisinde elemanları ctor initialize etme

Ex:
int main(){
  vector<string>svec{"ali","veli","mehmet","asli","can"};
  svec.push_back("murat");
  //sequence cont.da insert interface: Insert parametreleri ilk parametrelerine her zaman insert edilecek konumu alırlar. veli yerine ayse eklersek ali ayse veli mehmet olur. 
  //insert fonksiyonları konumu index olarak değil iterator olarak ister. 
  svec.insert(next(svec.begin()),"deniz"); //veli yerine deniz gelir. ali deniz veli mehmet
  svec.insert(svec.end(),"taylan"); // ... asli can taylan
  //insertin birçok overloadı vardır. Bir konuma bir öğe,  range ve initializer list overloadları vardır.
  svec.insert(svec.end(),{"taylan","eda","buse" }); //init list overload
  //insert fonksiyonları iterator döndürür. Insert edilmiş öğenin konumunu döndürür. Birden fazla öğe insert ediliyorsa ilk öğenin konumunu döndürür.
}
-> Birden fazla elamanı tek seferde enjekte etmek döngü vs. kullanmaya göre daha verimlidir. Yani init list, range gibi öğelerle insert edilebilecek
objeleri döngü içinde insert etmek verimsizdir.

-> Vektörlerde default atama operatorlerinin yanı sıra initializer list atama operator fonksiyonu vardır.

-> Diğer atamalar için assign() fonksiyonu vardır.
Ex:
vector<int>ivec(100);
list<double>mylist {1,4,56,57,9,86,43,21};
ivec.assign(ivec.assign(mylist.begin(),mylist.end()));

Fill assign:
ivec.assign(10,3333); //10 adet 3333 tutar.

resize() :size'ı değiştirir. Size küçülüp elemanlar sığmazsa sondaki elemanlar silinir. 
ivec.resize(10,8);//10 öğeye gelene kadar boş öğeleri 8 ile doldurur. 
  
  
}
 




*/
