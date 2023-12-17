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
emplace_back(U&& ...args)//perfect forwarding, nesne içerisinde elemanları ctor ile oluşturmak için gereken argümanları ister. 

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

Silme İşlevleri:

pop_back Fonksiyonu: Containerde tutulan son öğeyi siler. Geri dönüş değeri yoktur. Boş container üzerinde çalışması tanımsız davranıştır.

Ex:
int main(){
  using namespace std;
  vector<string> svec{"ali","mehmet","can","orhan","derya","isil","meryem" };
  while(!=svec.empty()){
    svec.pop_back();
    (void)getchar();
  }
}

Iterator Parametreli Silme İşlevleri:

erase() Fonskiyonu: Verilen konum bilgisindeki öğeyi siler. Erase fonksiyonları silinmiş öğe ya da öğelerden sonraki ilk öğenin konumunu
döndürür. 

Ex:
int main(){
  using namespace std;
  vector<string> svec{"ali","mehmet","can","orhan","derya","isil","meryem" };
  while(!=svec.empty()){
    svec.erase(svec.begin()));
    (void)getchar();
    }
}
Ex:
int main(){
  using namespace std;
  vector<string> svec{"ali","mehmet","can","orhan","derya","isil","meryem" };
  while(!=svec.empty()){
    auto iter = svec.erase(svec.begin()));
    (void)getchar();
    cout<<*iter<<'\n';
    }
}

erase() range silme overload'u:
Ex:
int main(){
  using namespace std;
  vector<string> svec{"ali","mehmet","can","orhan","derya","isil","meryem" };
  svec.erase (svec.begin()+1,svec.end()-1);//ilk ve son öğe hariç tüm öğeler silinir. Silinen tüm öğelerden sonraki ilk konumu dödürür
  //Bu örnek için erase(), vektörün son öğesinin konumunu döndürür. 
}

Container'in Tüm İçeriğini Silen İşlevler: 

-> clear() Fonksiyonu: Containerdeki tüm öğeleri siler. Ex: svec.clear();
-> resize() Fonksiyonu:container_name.resize(0) çağrısı da  elemanlarının hepsini siler. 
-> assign() Fonksiyonu: assign() fonksiyonunun initializer_list overload'u vardır. Ex: svec.assign({});
-> erase() Fonksiyonu: Container'in begin ve end iteratorleriyle yapılan range overload çağrısı tüm öğeleri siler.
-> Atama Operator Fonksiyonu: Boş initializer list'e yapılan assignment containerdeki tüm öğeleri siler. Ex: svec = {};
-> svec= vector<string>{};

Lexicographical Compare: Karşılaştırma yapılırken containerlerde ilk elemandan başlayarak elemanlar karşılaştırılır. İlk farklı öğenin olduğu 
konumda hangi container'in üyesinin değeri büyükse o container karşılaştırmada daha büyük olacaktır. Tüm öğeler aynı ise
karşılaştırma sonucu eşit çıkar. 

-> Iterator gösteriminden pointer elde etmek için önce derefrence edip ardından '*' operatörüyle pointer'a çevirebiliriz:
Ex: int* pvec = &*ivec.begin();

-> Vektörün swap fonksiyonu öğeyi değil pointerları swap eder. 

Vektörün Bool Açılımı: Vector'un bool açılımındaki öğeler bool türünden değildir. Bitlerden oluşur. Ayrı bir partial specializationdur. 
Ex:
vector<bool> myvec(20);
auto x = myvec[0]; //auto için yapılan çıkarım vector<bool>::reference. Reference bir nested class'tır ve içinde bool'a dönüşüm sağlayan
//öğeler barındırır. 
bool b = x; //hata değildir. operator bool(), fonksiyonu çağırılır. 
myvec.flip();//Belirli bir indeksteki öğenin ya da öğelerin tamamının free() fonksiyonunu çağırır. Bit seviyesinde implementasyon için...


Iterator Invalidation: Bazı durumlarda iteratorlerin de tıpkı pointerler gibi(dangling pointer) geçersiz hale gelmesi söz konusudur.
Geçersiz hale gelen iteratorlerin kullanımı büyük hatalardır. 

vector: all iterators and references before the point of insertion are unaffected, unless the new container size is greater than the
previous capacity.

vector: every iterator and reference after the point of erase is invalidated. 

Ex:
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
int main(){
  using namespace std;
  
  vector<string> svec{"ali","aaaa","aaaaa","aaaaaa","aaaaaa","aaaa","aaaaaa","aaaaaa","aaaaa","aaaaa","aaaaa""ali","aaaa","aaaaa","aaaaaa","aaaaaa","aaaa","aaaaaa","aaaaaa","aaaaa","aaaaa","aaaaa"};
  // 5 karakter uzunluğa sahip stringler silinecek ve 6 karakter uzunluğundaki stringlerden oldukları konuma bir tane daha eklencektir.
  //silme işlemi yapan fonksiyonlar silinen öğeden sonraki ilk silinmemiş öğenin konumunu döndürür.
  //ekleme işlemi yapan fonksiyonlar eklenmiş öğenin konumunu döndürür. Dolayısıyla iterator invalidationdan kaçınmanın tek yolu
  //silme ve ekleme yapıldığında kullanılan iterator'e insert ya da erase işleminin geri dönüş değerini atamamız gerekir.

  copy(svec.begin(),svec.end(),ostream_iterator<string>{cout," "});
  cout<<'\n';
  auto iter = svec.begin();
  while(iter!=svec.end()){
    if(iter->length() == 5){
      iter=svec.erase(iter); //silme yapıldı dönüş değeri silinmemiş ilk öğe o yüzden direk eşitlendi.
    }
    else if(iter->length() == 6){
      iter= next(svec.insert(iter,*iter),2); //iter ekleme yapılan konumda, ekleme yapıldığında iteri eklemeden sonraki elemana yani 2 sonrasına eşitledik.
    }
    else{
      ++iter;
    }
  }
  copy(svec.begin(),svec.end(),ostream_iterator<string>{cout," "});
}


















*/
