/*
-> Veri yapılarına eleman eklemek istediğimizde bir node oluşturmamız gereklidir. Node'u dinamik olarak oluştururuz ve bunun bir maliyeti 
vardır. Bağlı listeye her eleman eklendiğinde bir düğüm allocate edilir. Veri yapısından eleman silindiğinde de free eder. 

-> Vektörde bir öğe 4 byte yer kaplarken, burada her öğe için 2 pointer kullanılır ve 12 bit yer kaplar. Bunun üzerine her insertion yapıldığında
burada yine kayıp oluşur. 

-> Çifte bağlı listelerin avantajı konumunu bildiğimiz yerden yapılan ekleme ve çıkarmaların maliyeti, karmaşıklığı, constant time'dır.

-> Swap yaparken pointerleri da swap yaparken avantaj olması açısından, reverse, sort, remove gibi fonksiyonlar üye fonksiyon olarak verilmiştir.

-> Forward list'in size() fonksiyonu yoktur.

-> Dikkat!! Ortadan ekleme çıkarma yapacağımızda listelerin daha avantajlı olduğu sanılanın aksine her zaman doğru değildir. Birçok
durumda vektör daha avantajlıdır. O sebeple container seçilirken mutlaka profiling yapılması gerekir. 

-> Iteratorleri bidirectionaldır. Yani random access iterator kategorisinde olup bidirectional iterator kategorisinde olmayan, örneğin
büyüklük kıyası, iki iteratorün farkını almak, +=, -= gibi işlemler yapmak [] operatorun operandı yapmak syntax hatası olacaktır.

-> Listeden öğe silmek için doğrudan remove fonksiyonunu çağırabiliriz.

-> merge() : iki sıralı listeyi birleştirir.

-> reverse(): listeyi tersine çevirir.

-> splice(): Bir listenin içindeki düğümü destroy etmeye gerek kalmadan listeden çıkartık başka bir listeye eklemeye denir. 

*/




















*/
