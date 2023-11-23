/*

C++ derleyicilerinin yaptığı bir optimizasyondur. Mandatory değildir. Çağırılabilir bir copy ctor veya move ctor'un olmasını zorunlu kılar. Bu optimizasyon, bir fonksiyonun geri dönüş değerini, 
çağrıldığı yerdeki değişkenin adıyla doğrudan eşleştirmeye çalışır. Yani, fonksiyonun geri dönüş değeri için bir isim verildiğinde, derleyici bu değeri çağrıldığı yerdeki değişkenle ilişkilendirerek 
bir kopya oluşturmak yerine, doğrudan o değişkeni oluşturmaya çalışır.

-> C++17 ile;
1. Temporary object passing (mandatory)
2. Returning a temporary object (mandatory)
3. Returning an object of an automatic storage class (optimization)

-> 1. ve 2. seçenekte copy ve move ctor'lar olmasa dahi syntax hatası olmaz ancak 3'te olur. 

*/ 
