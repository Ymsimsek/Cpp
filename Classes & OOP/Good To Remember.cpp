/*
-> Eğer bir sınıfın veri elemanının değişmesi onun problem domainindeki algılanan değeriyle alakalı değilse const üye fonksiyonda çağırıp değiştirmemizde semantik açıdan bir hata değildir ancak syntax açısından 
hatadır. Bu hatayı aşmamızı sağlayan araç "mutable" keyword'üdür. 

-> Eğer bir sınıf nesnesi için çağırıları ctor'un içinde, başka bir kaynak dosyadaki global bir sınıf değişkeni kullanıyorsak hayata gelmeden kullanma olasılığı meydana gelir ve tanımsız davranış olur. Buna static init fiasco denir. 

-> Eğer bir dönüşüm aşağıdaki dönüşüm sekanslarından biriyle gerçekleştirilebiliyorsa derleyici bu dönüşümü örtülü olarak yapmak zorundadır. 
- User defined conversion + standard conversion
- Standard conversion + user defined conversion

-> "explicit" ve "static" kelimeleri bildirimde kullanılır tanımlamada kullanılmaz.  

*/
