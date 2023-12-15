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

-> 




*/
