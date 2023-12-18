/*
-> Dört adet associative container grubu vardır.
-set
-multiset
-map
-multimap

-> Özünde aynı veri yapılarıdırlar. Tipik olarak bu containerler implementasyon tarafında binary search tree denilen veri yapısıdır. 

-> Derleyicilerin implementasyonu çoğunlukla, red-black tree denilen ikili arama ağaçlarıdırlar. 

-> Set'de sadece anahtarlar tutulur. Birincil varlık nedeni önceden seçilmiş değerler arasında bir değerin olup olmadığına bakmak 
ve varsa ona erişmektir. Anahtarla değere erişmek logaritmik karmaşıklıktadır. Yine öğe ekleyip silmek de logaritmik karmaşıklıktadır.
Yani 1024 öğe varsa 10 sorgulamada bulabiliriz. 

-> Set ile multiset arasındaki fark set'te bir anahtardan bir tane olabilir. Ancak multiset'te bir anahtardan birden çok sayıda olabilir.
Örneğin tam sayı kümesi oluşturuyor olsak set'de bir sayıdan bir tane olabiliyorken multisette aynı sayıdan birden fazla olabilir. 

-> Map'te anahtarlar pair'ler ile tutulur. (Key ve value) Anahtarla bir öğeye erişmek yine logaritmik karmaşıklıktadır. 
Örneğin T.C. kimlik numarasından isime erişim. T.C. kimlik bir key, isim ise bir value olabilir.

-> Map ve multimap arasındaki fark yine map'te bir anahtardan en fazla bir tane, multimap'te ise birden çok olabileceğidir.

-> Set, bir karşılaştırma işlemine ihtiyac vardır. Ekleme ve silme işlemi bir comparator yardımıyla yapılır. O da template
parametresine karşılık gelen template argumanıdır. Default olarak std::less kullanılır.

-> Set ve multiset'in başlık dosyaları "set", map ve multimap'in başlık dosyaları "map"tir.

-> Associative containers ekleme yaparken değere göre ekleme yaparlar. Örneğin bir set'e 16 değerini başa veya sona ekle diyemeyiz.
Onun ekleneceği yerden associative containerler sorumludur. 

-> set'teki öğelere erişildiğinde o değerleri değiştiremeyiz. Syntax engeli aşılıp bir öğesi değiştirilirse bu tanımsız davranış olur.


Ex:
#include <set>
#include <map>

int main(){
  using namespace std;

  set<int> myset{3,12,4,576,43,3,23,4,52};
  for(auto iter= myset.begin();iter!=myset.end();++iter){
    cout<<*iter<<'\n';
  }
}

-> Set'e insert() ile öğe eklenebilir. (Bidirectional Iterator) Doğrudan bir değer ister:
Ex:
#include <set>
#include <string>
#include <iostream>
#include <vector>
int main(){
  using namespace std;
  set<string> myset;
  vector<string> svec{"ali","veli","ahmet"};
  myset.insert("ayse");//ayse
  myset.insert({"ayse","zeki","nuri"}); //ayse nuri zeki
  myset.insert(svec.begin(),svec.end()); // ahmet ali ayse nuri veli zeki
  cout<<"size= "<<myset.size()<<'\n';
  copy(myset.begin(),myset.end(),ostream_iterator<string>{cout," "}); // ahmet ali ayse nuri veli zeki
}

Ex:
int main(){
  using namespace std;
  multiset<int> myset{2,2,2,5,6,7,7,7,7,9};
  cout<<myset.count(7);
  auto iter =myset.find(7);
  auto n = distance(myset.begin(),iter);
  
}

Ex:
int main(){
  using namespace std;
  multiset<int> myset{2,2,2,5,6,7,7,7,7,9};  
  auto iterlower =myset.lower_bound(7);
  auto iterupper =myset.upper_bound(7);
  cout<< distance(myset.begin(),iterlower)<<'\n'; 
  cout<< distance(myset.begin(),iterupper)<<'\n';
  
}
Ex:
int main(){
  using namespace std;
  multiset<int> myset{2,2,2,5,6,7,7,7,7,9};  
  auto [iterlower , iterupper] = myset.equal_range(7);
  cout<< distance(myset.begin(),iterlower)<<'\n'; //3
  cout<< distance(myset.begin(),iterupper)<<'\n'; //7
  
}

-> Set'in silme fonksiyonu değerle siler.

Ex:
int main(){
  using namespace std;
  multiset<int> myset{2,2,2,5,6,7,7,7,7,9};  
  myset.erase(myset.begin());
  myset.erase(prev(myset.end()));
  auto n = myset.erase(7);
  erase(myset,7);
}

-> Insert fonksiyonunda ilk elemana konum geçildiğinde eğer koyulacak konum doğruysa bu işlem daha hızlı yapılır. Buna hint insert denir.

-> Map'in insert fonksiyonlarına bir pair geçilir. Pair'in first'i key, second'u ise value alır. Başlık dosyası "map"tir. Multimap ile
map arasındaki fark set ile multiset arasındakiyle aynıdır.

-> Map template'inin birinci parametresi anahtarın türü, ikinci template parametresi o anahtara karşılık gelecek değerin türü, üçüncü parametresi
karşılaştırma kriteridir ve default olarak std::less alır. Son parametresi de allocator'un pair açılımıdır.

Ex:
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <map>

int main(){
  using namespace std;
  vector<int> ivec{1,2,3,4,5,6,7,8,9,10};
  vector<string> svec{"a","c","d","a","b","e","c","d","c","a"};
  map<int, string> mx;
  for(int i=0;i<10;i++){
    mx.insert(pair{ivec[i],svec[i]});
  }
  for(const auto& ivec : mx ){
      cout<<ivec.first<<" "<<ivec.second<<"\n";
  }
}

Ex:
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <map>

int main(){
  using namespace std;
  vector<int> ivec{1,2,3,4,5,6,7,8,9,10};
  vector<string> svec{"a","c","d","a","b","e","c","d","c","a"};
  map<int, string,greater<>> mx;
  for(int i=0;i<10;i++){
    mx.insert(pair{ivec[i],svec[i]});
  }
  for(const auto& ivec : mx ){
      cout<<ivec.first<<" "<<ivec.second<<"\n";
  }
}

Ex:
int main(){
  using namespace std;
  map<string, int> mx{{"deniz",1},{"ayca",2},{"mehmet",3}}; //Legal
  pair<string,int> p1 {"tayfun",4};
  mx.insert(p1);
}

Ex:
int main(){
  using namespace std;
  vector<string> svec;
  rfill(svec,1000,rname);
  map<string,int> cmap;
  for(const auto& name:svec){
    ++cmap[name];
  }
}








  
*/  
