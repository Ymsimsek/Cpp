/*
-> "dynamic_cast" opertatörü run-time'da down-casting'in doğru yapılıp yapılmayacağını sınar. Operatörün ürettiği değer, hedef türünden olur.

Kullanımı:
dynamic_cast<target type>() 

Ex:
dynamic_cast<Mercedes*>(car_ptr);

Ex:
dynamic_cast<Mercedes&>(car_ref);

Ex:
Mercedes *p =dynamic_cast<Mercedes*>(car_ptr);
if(p){
  //p'yi mercedes olarak kullanabilmek için p null_ptr olmamalı
}

-> Dynamic cast operatörünün operandı olan isim polymorphic bir sınıf türünden olmalıdır. 

-> Scope leakage engellenmesi için dynamic_cast operatörünün if bloğunun içinde şu şekilde kullanabiliriz:
if(Tesla* tp = dynamic_cast<Tesla*>(car_ptr){
  tp -> autopilot();
}

//Bu örnekte değişken if parantezi içinde tanımlı olduğu için sadece if'in doğru ve yanlış kısımlarında visible olur.
 
-> "dynamic_cast" operatörü söz konusu olunca hedef tür bir pointer ise tabandan türetilen sınıflar da dahil olur.

-> Dynamic cast kullanımında hedef tür referans türü ise down-casting güvenli bir şekilde yapılmıyorsa std'nin "std::bad_cast" sınıfı türünden exception throw edilir.

*/
