/*
Return Value Optimization: Bir fonksiyonun geri dönüş değerini oluştururken geçici nesne oluşturulmasını önlemek için kullanılan bir C++ optimizasyon tekniğidir.

Ex:
myClass foo(int n){
  //some code here
  return myClass{n};
}
int main(){
  myClass m = foo(13); //C++ 17 öncesinde bu kodda foo çağrısında copy ctor devreye girip bir temporary object oluşturacaktı. Şuan mandatory copy elision ve RVO buna engel olacak. 
}

*/
