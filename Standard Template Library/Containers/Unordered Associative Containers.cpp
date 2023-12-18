/*
-> Hash table anahtarla aramalar amortised constant time'dadır. Anahtarı indexe dönüştüren bir fonksiyon vardır. İşte bu işleme hashing denir.

-> Anahtarı indekse dönüştüren fonksiyona hash function denir. Anahtar indekse dönüştürüldüğünde, o indeksteki öğeye erişiriz. Dolayısıyla
arka planda bir vektörel veri yapısı vardır ve vektörel veri yapısını kullanarak indekse erişim sağlarız. Bunun için de anahtarın indekse 
dönüştürülmesi gerekir. Burada temel problem collision'dur. Bazen farklı anahtarlar aynı index veya tam sayı değerine hash edilebilir. 
Bu yüzden indekse erişildiğinde iki tane anahtar aynı indekse hash edilmişse ikisine de erişebilmemiz gerekir. Bunu aşmak için en tipik yol
(standart kütüphane de bunu kullanıyor) Vektörde bağlı listelerin tutulmasıdır. 

-> STL, hash template'inde bütün standart türler için explicit specializtion'lar sağlar. "funcitonal" kaynak dosyasının include edilmesi
gereklidir. 

Ex:
int main(){
  using namespace std;
  hash<int> hasher;//anahtarı size_t'ye dönüştüren fonksiyon çağrı operator fonksiyonu vardır. 
  size_t val = hasher(9832);
  cout<<val<<'\n';
}

Ex:
int main(){
  using namespace std;
  hash<string> hasher;
  cout<<hasher("deniz");
  cout<<hasher("denizc");
  cout<<hasher("denizca");
  cout<<hasher("denizcan"); //birbiriyle alakasız değerler çıkıyor.
  cout<<hasher("deniz");//ilk çağrı ile aynı
}

Ex:
int main(){
  using namespace std;
  int val=12424432;
  cout<<hash<int>{}(ival);
}

Kendi sınıfımız için hasher oluşturmak:

struct DateHasher{
  std::size_t operator()(const Date& dt)const{
   std::hash<int> hasher;
   return hasher(dt.month_day())+hasher(dt.month())+hasher(dt.year()); //Böyle olmak zorunda değil.
  }
}

int main(){
  using namespace std;
  Date myDate{14,12,2023};
  cout<<DateHasher{}(mydate);
}

-> Set ya da mapte karşılaştırma kriteri büyüklük küçüklüğe göreydi. Burada default olarak "==" ile kontrol edilir. 

unordered_set:
Ex:
int main(){
  using namespace std;
  unordered_set<int, std::hash<int>,equal_to<int>> //equal_to<int>, default
}

Ex:
int main(){
  using namespace std;
  unordered_set<int> myset(512);
  cout<<myset.bucket_count();

}

-> Interface bucket interface'i hariç neredeyse tamamen associative container'lerle aynıdır. 


















*/
