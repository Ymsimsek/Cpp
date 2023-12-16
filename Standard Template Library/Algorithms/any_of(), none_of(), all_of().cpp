/*
-> any_of() range ve unary predicate parametreleri alıp o unary predicate'ı sağlayan en az bir öğe varsa true döndürür. 

any_of(x.begin(),x.end(),unary_predicate)

Ex:
int main(){
    using namespace std;
    constexpr int a[] = {1,3,5,7,9,12};
    constexpr bool b = any_of(begin(a),end(a),[](int x{return x%2==0;}); //constexpr sayesinde derleme sürecinde cevap bulunur. 
}

-> none_of(): Bir aralıktaki elemanların hiçbirisinin belirli bir koşulu sağlamadığını kontrol etmek için kullanılır. 

-> all_of(): bir aralıktaki tüm elemanların belirli bir koşulu sağladığını kontrol etmek için kullanılır.


*/
