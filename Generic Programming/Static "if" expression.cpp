/*
-> Static if C++17 ile dile eklendi yani compile time'da uygulanan if.

Ex:
template<typename T>
void func(T x){
  if constexpr (ct expression){ //constexpr ile tanımlanıyor. 
  //code for true path
  }
  else{
  //code for false path
  }
}


Ex:
template<typename T>
auto get_value(T x){
  if constexpr (std::is_pointer_v<T>){
    return *x;
  }
  else{
    return x;
  }  
}
int main(){
  int x=5;
  double dval = 4.971;

  int* ip{&x};
  double* dp{&dval};

  std::cout<<get_value(x)<<'\n';
  std::cout<<get_value(dval)<<'n';
  std::cout<<get_value(ip)<<'n';
  std::cout<<get_value(dp)<<'\n';

}






*/
