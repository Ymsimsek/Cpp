/*
C++ dilinde referansa referans olmamasına karşın bazı yerlerde contexte referansa referans oluşabilir. Buna Reference Collapsing adı verilir.

Reference Collapsing: 

T&    |    &    ->    T&
T&    |    &&   ->    T&
T&&   |    &    ->    T&
T&&   |    &&   ->    T&&  

*/


/*

Universal Reference / Forward Reference:

auto&& r | r bir universal reference ise her değer kategorisinden ifadeye bağlanabilir. 

auto&& r{x};

-> İlk değer veren ifadenin "x" değer kategorisi auto için yapılan kategoridedir.
-> r değişkeninin türü reference collapsing ile bulunur.
-> İlk değer verme hangi değerle yapılırsa r değişkeninin değer kategorisi o olur. 

*/

// Example:

auto&& x=10;// int&& -> r value

// Example:

int ival{4};
auto&& x{ival};// Reference collapsing : int& &&x = int& x = ival

/* 
auto&& r her şeye bağlanır. Eğer L value'ya bağlanırsa "r", L value referans olur. R value'ya bağlanırsa "r" R value referans olur. 
const nesneye bağlanırsa auto için yapılan çıkarım const T veya const T& olur.
*/








