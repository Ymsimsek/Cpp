/*
-> "typeid" operatörleri bir ifadeyle veya bir tür ile kullanılabilirler.
-typeid(*ptr)
-typeid(++x)
-typeid(x)
-typeid(int)
-typeid(myClass)
-typeid(10)

-> "typeid" operatörüyle oluşturulan ifade bir sınıf türünden const bir nesneye referanstır. "typeid" operatörü kullanılacaksa "typeinfo" başlık dosyası include edilmelidir.
#include <typeinfo>

-> "type_info" türünden bir nesne oluşturulamaz ancak "typeid" operatörüyle yaratılan ifadenin türü type-info" olur. "type_info" nesnesinin ctor'u yoktur.

-> "typeid" operatörüyle oluşturulan ifadeye "const auto& x" veya "auto& x" şeklinde ifadeler ile referans değişkenler bağlanabilir ancak "typeid" ile oluşturulan ifadelerin const olduğu unutulmamalıdır.

-> "typeid" operatörü aynen "decltype" ve "sizeof" gibi unevaluated context bildirir.

-> "typeid" ifadeleriyle karşılaştırma yapılabilir.

Ex:
int x{1};
double dval{5.78};
cout<<(typeid(x)==typeid(dval)<<'\n'; //Output:0 

Ex:
Der myDer;
Base* ptr = &myDer;
cout<<typeid(*ptr)==typeid(Der); //Output: 0, Der ve Base aynı class değil

-> typeid operatörünün davranışı operandı olan ifadenin polymorphic bir tür olup olmamasına göre değişir. Polymorphic değilse static bir tür olup olmamasına göre değişir.
Polymorphic değilse static, eğer polymorphic ise de dinamik türü esas alır.

*/
