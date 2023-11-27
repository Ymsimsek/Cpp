/*
-> Class'ların private bölümüne türetilen sınıflar erişemez. Taban sınıfın public öğeleri, türetilmiş sınıfın private bölüöüne eklenir Taban sınıfın protected öğeleri yine
türetilmiş sınıfın private bölümüne eklenir. Private inheritance bir has-a-relationship kapsamındadır. Artık türemiş sınıftan bir nesne taban sınıfı türünden kabul edilemez.
Dolayısıyla up-casting örtülü olarak yapılmaz. Up-casting için static_cast kullanılabilir. Türemiş sınıfın üye fonksiyonları içinde is-a relationship oluşturulabilir.
Client tarafında is-a relationship yoktur.

-> Private inheritance containment (composition) için bir alternatif oluşturur. Containment'de yani class içinde başka nesne oluşturulduğunda:
1. Eleman sınıfının sanal fonksiyonu doğrudan override edilemez. Ancak private inheritance ile taban sınıfın fonksiyonları override edilebilir.
2. Eleman sınıfın protected kısmına erişilemezken, private inh. ile taban sınıfın protected kısmına erişilebilir.
3. Bir sınıf nesnesi elemanının türünden değildir. Ancak türemiş sınıfın üye fonksiyonları ve türemiş sınıfı friend ile is-a relationship kapsamındadır.

-> Veri elemanlarına sahip olmayan class'ların boyutu 1 byte'dır.

Restricted Polymorphism: Private inheritance ile elde edilen sınıfta, sınıf dışındaki fonksiyonlara private verilerek erişilebilecek sınıfların kontrol edilme mekanızmasıdır.

*/

