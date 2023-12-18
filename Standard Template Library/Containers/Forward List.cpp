/*

-> Forward list bir tekli bağlı listedir. forward_list başlık dosyasındadır. size() fonksiyonu yoktur. 

Tekli bağlı liste ve çifte bağlı liste arasındaki fark:
- Tekli bağlı veri yapısında düğüm içinde bir tane pointer mevcuttur. Düğüm içindeki pointer, bir sonraki veriyi tutan düğümü gösterir.
Bu yüzden bağlı listede sadece tek yönde hareket edebilir. Bu da belirli sonuçları doğurur. Bellek kullanımı açısından daha avantajlıdır.
Ekleme ve silme söz konusu olduğunda eğer bağlı liste çife bağlı listeyse düğümlerin içinde iki adet pointer olacağından, belirli 
bir konuma ekleme yapılacağında sadece konumun elimizde olması yeterlidir çünkü ekleme yapılacak düğümden önceki ve sonraki düğümü 
manipule etmemiz gerekir ve bunlara da erişimimiz vardır. Ancak tekli bağlı liste sınıfında belirli bir konuma ekleme yapabilmek
için ekleme yapılacak konumdan önceki düğümdeki pointeri de update etmemiz gerekir ancak o düğüme erişimimiz yoktur. Dolayısıyla,
elimizde varolan konuma değil sonraki konuma ekleme yapabiliriz. Aynı şey silme işlemi için de geçerlidir. 

-> Yukarıda açıklanan sebeplerle tekli listelerde ekleme yapan fonksiyon insert değil insert_after, silme yapan fonksiyon erase_after 
olarak adlandırılmıştır. Dolayısıyla, insert_after fonksiyonu bizden bir konum ister ancak o konumdan sonraki konuma insert eder.
erase_after fonksiyonu da bizden bir konum ister ancak o konumdan sonraki öğeyi erase eder. 

-> Tekli bağlı liste bize bir before_begin isimli bir fonksiyon verir. before_begin fonksiyonu da bize bir iterator verir. Ancak
o iteratorun tuttuğu konumda liste boş olmasa dahi bir öğe yoktur. O konumu insert_after veya erase_after fonksiyonları yardımıyla 
ilk öğenin konumuna eklemeler ya da ilk öğenin konumundan çıkarmalar yapabiliriz. 

-> Normal koşullarda bir öğeyi silmek istediğimizde find() ile öğenin konumunu bulup erase() ile silebiliyorduk. Tekli bağlı listede
bu olmaz. Çünkü o öğenin konumunu değil ondan önceki öğenin konumunu bulmamız gerekir ve onu erase_after ile silmemiz gerekir. 

-> Forward list'in iteratorleri bidirectional iterator değil, forward iterator'dur. Dolayısıyla tekli bağlı listelerde, rbegin,
rend, operator--, crbegin, crend, size(), push_back(), back() fonksiyonları yoktur. 

-> Containerde her öğeden bir tane bırakmak istiyorsak sort() edip unique() çağrısı yapabiliriz.  

Ex:
#include <forward_list>
#include <iostream>
#include <algorithm>
int main(){
  using namespace std;

  forward_list<int> myList{3,5,6,8,3,6,1,9};
  copy(myList.begin(),myList.end(),ostream_iterator<int>{cout," "});
  std::cout<<'\n';

  auto iter = next(myList.begin(),3);
  cout<<*iter<<'\n';
  myList.insert_after(iter,{-7,-8,-9});
  copy(myList.begin(),myList.end(),ostream_iterator<int>{cout, " "});
  cout<<'\n';  
  myList.insert_after(myList.before_begin(),{-7,-8,-9});
  copy(myList.begin(),myList.end(),ostream_iterator<int>{cout, " "});
  cout<<'\n';  
  myList.erase_after(myList.begin(),next(myList.begin(),3));
  copy(myList.begin(),myList.end(),ostream_iterator<int>{cout, " "});
  cout<<'\n';  
   myList.erase_after(myList.before_begin(),next(myList.begin(),3));
  copy(myList.begin(),myList.end(),ostream_iterator<int>{cout, " "});
  cout<<'\n'; 
}










 */ 
