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











*/  
