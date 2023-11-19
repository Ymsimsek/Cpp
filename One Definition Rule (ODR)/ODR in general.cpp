/* 
Yazılımsal varlıkların bildirimleri program içinde birden fazla yerde kullanılabilir. 
Ancak her fonksiyon tanımı ancak bir kez yapılmalıdır.
Bu kurala One Definition Rule (ODR) denir. 
*/

/*
Header File'da ODR İhlali Yapmamak İçin:
1. Inline Fonksiyon Tanımlamaları
2. Inline Değişken Tanımlamaları (C++17)
3. User-Defined Types
4. Bir fonksiyon vera değişkeni constexpr keyword'u ile tanımlarsak implicit olarak inline etmiş oluruz Bu sebepler ODR ihlal edilmemiş olur.
*/


  
