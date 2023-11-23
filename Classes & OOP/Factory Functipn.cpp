/*
Factory Function: Bir nesne oluşturup nesne döndüren fonksiyonlardır.

-> Copy elision bir nesne hayata gelirken çalışan bir mekanizmadır. Atama yapıldığında copy elision olmaz.

Ex:
class moveOnly{
public:
  moveOnly()=default;
  moveOnly(const moveOnly&) = delete;
  moveOnly& operator=(const moveOnly&) = delete;
  moveOnly(moveOnly&&);
  moveOnly& operator=(moveOnly&&);
};

moveOnly foo(){
  moveOnly ax;
  return ax; // L value to X value conversion yapılır. Normalde L value olup taşınmaya müsade etmeyen ifade müsade ediyor ve kod çalışıyor.
}

int main(){
  moveOnly x;
  x=foo();
}

-> "return ax;", ax otomatik ömürlü değişkeni "return std::move(ax);" şeklinde değiştirip R value yaparsak bu sefer pessimistic move oluyor. Böyle olunca da copy elision devre dışı kalır. 

*/
