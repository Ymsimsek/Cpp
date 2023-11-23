/*
Rule of Zero: Eğer derleyicinin, special member function'ları yazmasında, dezavantaj veya undefined behaviour oluşturmuyorsa, derleyicinin fonksiyonları yazmasına denir. 

-> Aksi halde bir ihtiyaç olmadıkça rule of zero'ya uyabiliriz.

-> Default ctor'u derleyicinin yazımına bırakırsak sınıfın non-static arithmetic türden veri öğeleri, garbage value ile hayata gelir. Bunu engellemenin yolu ise default initializationdur. 

-> Value Initialization yapılan data memberların oluşturduğu classta ctor func. parametreleri mevcut ve data memberlardan oluşmuyorsa sınıfın default ctoru not-declared olur ve "default" kelimesini kullanarak hem user-declared
hem de tanımını derleyiciye bırakabiliriz.

Ex:
class Date{
public:
  Date()= default;
  Date (int,int,int){}
private:
  int m_day{1};
  int m_mon{1};
  int m_year{1900};
};
*/ 
