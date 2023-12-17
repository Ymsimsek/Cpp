/*
-> Amaç sadece sondan yapılan ekleme ve silme işlemlerinin değil, baştan yapılan ekleme ve silme işlemlerinin de complexity'sini 
amortised constant time'a çekmek ve aynı zamanda indeksle erişimi de amortised constant time'a çekmektir.

-> Deque dinamik dizilerin dizisi olarak düşünebilir. 

-> Temel avantaj reallocation'un olmamasıdır. Belirli bir chunk dolduğunda, yeni bir chunk dinamik olarak allocate edilir. Fakat öğeler
bir bellek bloğundan başka bloğa aktarılmazlar. İndeksle erişim, aritmetik hesapla indeksin hangi chunk'ın kaçıncı indeksi olduğunun
bilgisine dönüştürüyorlar. 

-> Deque kullanmaya aday olabilmesi için, şunlardan birinin olması gerekir: 
- Ekleme ve silme her iki uçtan da yapılıyorsa.
- Deque'in iterator'unun invalid hale gelmemesi vektore tercih ediliyorsa.
- Reallocation maliyetinden kaçınmak olabilir. (Öngörüde bulunup reserve edilemiyorsa)
  
-> C api leriyle birlikte kullanılacaksa deque contigious memory kullanmaz.

-> Interface'i birkaç istisna dışında vektor ile ortaktır.

-> Vektörden farklı olarak push_front, pop_front, emplace_front fonksiyonları vardır. 

-> Insertion: All iterators and references are invalidated, unless the inserted member is at an end (front or back) of the deque.(in which case
all iterators are invalidated, but references to elements are unaffected)

-> Erasure: All iterators and references are invalidated, unless the erased members are at an end of the deque.(front or back)


*/
