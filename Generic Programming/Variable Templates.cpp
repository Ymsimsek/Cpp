/*
-> Variable template'in instantiation'u değişken kodu oluşturmasını sağlar. Yani variable template'in specialization'u değişken olur.
Ex:
template<typename T>
constexpr T pi = T(3.1459265872332353235L);

int main(){
  constexpr auto x = pi<int>; //x=3
}


Ex:

Ex:
template<typename T>
constexpr T pi = T(3.1459265872332353235L);

template<typename T>
T get_circle_area(T radius){
  return pi<T>*radius*radius;
}

int main(){
  get_circle_area(4.5L); //pi in long açılımı kullanıldı
}

Ex:
template <size_t n>
constexpr size_t factorial = n* factorial<n-1>;

template<>
constexpr size_t factorial<0> = 1;
int main(){
  factorial<12>;
}






























*/
