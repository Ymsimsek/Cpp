/*
std::string: Bir sınıf şablonudur (class template). Container niteliği taşır. Sequence containers'a tabidir. String yazı isimleri için interface'i özelleştirilmiş
dinamik dizi sınıfıdır. Operator overloading'den çokça yararlanan bir kütüphanedir. Karşılaştırma operatörlerini, spaceship operatörü ile overload ederler (C++20 ile eklendi). 

-> String fonksiyonlarda, yazı uzunluğu türü, kapasite türü, bir ya da iki parmetre indeks değeri, karakterlerin adet sayısı, npos;"size_type" türü cinsindendir. (std::string::size_type)

-> String fonksiyonlarına girilebilen bazı argümanlar ve temsiliyetleri:
- const string& //whole string 
- const string&, size_type idx//sub string, indexten string sonuna
- const string&, size_type idx, size_type len //substring, indexten len kadar ileri
- const char* //cstring, son parametresi nullptr olan string
- const char*, size_type len //Data parameter, char* adresinden len kadar ileri
- char //karakter
- size_type n ,char c //n adet c karakteri
- iterator beg, iterator end //range parameter


*/
