/*
-> Algoritmalar, exception throw etmezler. Iteratorlerin taşma ve geçersiz olma durumu algoritma tarafından saptanamaz. 

-> Algoritma yazma işlemi yapıyorsa geri dönüş değeri en son yazılan konumdan sonraki konumdur. Bkz. copy()

-> Algoritmaların parametre değişkenleri iteratördür. Yani bir algoritma şunları yapabilir:
- Bir iteratör konumundaki nesneye atama yapabilir.
- Aynı range'deki iki nesneyi takas edebilir.
- Range'in ilişkin(ait) olduğu kaba ekleme yapamaz. Çünkü ekleme yapabilmesi için kaba erişmesi gerekir ancak parametreleri iteratordür.
- Range'in ilişkin(ait) olduğu kaptan silme yapamaz. 

-> Asla boş cotainer'in .begin() 'un geri dönüş değerini dereference etmemeliyiz. Öğe yoktur.

-> Asla .end() fonksiyonunun geri dönüş değeri olan konumu dereference etmemeliyiz. Çünkü container'in end fonksiyonu son öğenin konumunu değil 
son öğeden sonraki konumu bildirir. 

-> [begin, end) şekinde gösterim begin'in dahil end'in hariç olduğu anlamına gelir.

-> Çoğu yazma algoritmasında yazının yapılacağı alanda yer olup olmadığından yazan sorumludur.

-> Çoğu yazma algoritması bir range içerisindeki öğerleri, yani kaynağı ilk parametrelerine, ardından kopyalanacağı konumu parametre olarak kullanır. Bkz. copy()

-> STL'de sonu if ile biten algoritmalar, ne algoritmasıysa, ne iş yapıyorsa, o işi yaparken bir predicate kullanılır ve true değer dönen değerlerle o işi yapar.  

-> STL'deki arama algoritmalarının geri dönüş değeri iteratördür. Aranan değer bulunursa öğenin konumu döndürülür. Yoksa fonksiyona geçilen end konumu döndürülür.

-> Yazma işlemi yapan bir algoritmanın, bir container'a push_back'e dönüştürmesi için hedef yazı başlangıç konumuna back_inserter ile çağrı yapabiliriz.

-> Yazma işlemi yapan bir algoritmanın, bir container'a push_back'e dönüştürmesi için hedef yazı başlangıç konumuna back_inserter ile çağrı yapabiliriz. 

-> front_inserter ile container'in push_front fonksiyonu kullanılmış olarak arzu edilen range, hedefin ön sıralarından başlanarak eklemeye tabi tutulur.

-> inserter fonksiyon çağrıları ile container'in insert fonksiyonu ile yapılan çağrıya dönüştürür. Insertion'un belirli bir iterator konumuna arzu edilen hedef aralığını eklemek için kullanılabilir. 

-> any_of(), none_of(), all_of() algoritmalarının ortak özelliği boolean döndürmeleridir. 

-> functional kaynak kütüphanesi dahil ederek, unary predicate gereken küçüktür, büyüktür, toplama, çıkarma, bölme vs. gibi çıktıları
lambda ifadesinin yanı sıra less{}, greater{}, plus{} gibi öğelerle  implementasyon sağlanabilir.
Ex:
int main(){
  using namespace std;
  vector<int> x{1,4,5,7,8,9,6};
  vector<int> y{13,24,51,73,8,9,64};
  vector<int> z;
  transform(x.begin(),x.end(),y.begin(),back_inserter(z),plus{}); //x ve ynin öğeleri toplanıp z'ye geçildi.
  
}

*/
