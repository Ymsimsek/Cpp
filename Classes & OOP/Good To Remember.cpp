/*
-> Eğer bir sınıfın veri elemanının değişmesi onun problem domainindeki algılanan değeriyle alakalı değilse const üye fonksiyonda çağırıp değiştirmemizde semantik açıdan bir hata değildir ancak syntax açısından 
hatadır. Bu hatayı aşmamızı sağlayan araç "mutable" keyword'üdür. 

-> Eğer bir sınıf nesnesi için çağırıları ctor'un içinde, başka bir kaynak dosyadaki global bir sınıf değişkeni kullanıyorsak hayata gelmeden kullanma olasılığı meydana gelir ve tanımsız davranış olur. Buna static init fiasco denir. 

-> Eğer bir dönüşüm aşağıdaki dönüşüm sekanslarından biriyle gerçekleştirilebiliyorsa derleyici bu dönüşümü örtülü olarak yapmak zorundadır. 
- User defined conversion + standard conversion
- Standard conversion + user defined conversion

-> "explicit" ve "static" kelimeleri bildirimde kullanılır tanımlamada kullanılmaz.  

-> C++17 ile;
1. Temporary object passing (mandatory)
2. Returning a temporary object (mandatory)
3. Returning an object of an automatic storage class (optimization)
1. ve 2. seçenekte copy ve move ctor'lar olmasa dahi syntax hatası olmaz ancak 3'te olur. 

-> Memory Leak: Fonksiyonun işi bittikten sonra elde ettiği bellek alanının geri verilmemesi durumudur.

-> Resource Leak: Örneğin bir nesne yaratıldıktan ve kullanıldıktan sonra destructor'un çağırılmayıp kaynakların geri verilmemesidir. 

-> Başka modullerde tanımı yapılmış olan ifadeler için "extern" anahtar kelimesi kullanılabilir. 



*/
