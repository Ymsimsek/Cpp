/*
Special Member Functions of Classes:
- Defalut Ctor
- Destructor
- Copy Ctor
- Move Ctor (C++11)
- Copy Assignment
- Move Assignment (C++11)

-> Bu fonksiyonlara special member functions denmesinin sebebi bu fonksiyonların kodlarının (Belirli koşullar sağlandığında) derleyici tarafından yazılmasıdır. 

-> Derleyicinin bu kod yazma işlemine default etmesi adı verilir. 

-> C++'da Dtor, kullanılmayan nesnelerin ömrünü sonlandırmaya yarar.

-> Bu fonksiyonlardan herhangi biri şu statülerinden birinde olabilir:
- not declared: Fonksiyonun bildirilmemiş olması.
- user declared: Programcı tarafıntan bildirilmesi
- implicitly declared: Derleyici tarafından örtülü olarak bildirilmesi

-> Eğer default ctor'dan başka bir ctor tanımlanırsa default ctor undeclared haline gelir. 

-> Eğer programcı default ctor'u bildirirse user-declared olur. (Örn. myClass(); veya myClass()=default;

-> "default" kelimesi yalnızca special member functions ile kullanılabilir.

-> delete kelimesinin kullanımı da fonksiyonu user-declared hale getirir.

-> Bir fonksiyon derleyici tarafından implicitly declared function oluşturursa ya default yapar ya da delete eder. 

-> Eğer bir class'ta kısıtlama, gizleme yoksa sınıf elemanları ortadaysa bunlara "aggregate" denir. Invariant kontrolü programcıya bırakılacak ve invariant kullanılmayacaktır. 


  */

