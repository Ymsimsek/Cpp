/*

-> Container adepter'ler container değillerdir. so-called containers diye de adlandırılabilirler. 3 tane abstarct data-type'ı 
implemente eden onlar için interface sunan sınıf şablonlarıdır. (Stack, queue, priority queue) 

Stack: Son girenin ilk çıktığı veri yapısıdır. Genel olarak push, pop, top, empty gibi fonksiyonlar kullanılır. 

Queue: İlk girenin ilk çıktığı veri yapısıdır. 

Priority Queue: Öncelikler vardır. Önceliği olanın ilk çıktığı veri yapısıdır.

-> Bu sınıflar STL'de bir container'i member olarak alıp onu sarmalayıp onun interface'ine kendi interface'lerine adepte ederler.

-> STL'de container'in ne olacağını bir template argüman'ı belirler. Örneğin stack kullanmak isteyip vector compositionu edinebiliriz.

-> Stack ve queue'nun default template argumanı bir dequeue, piority queue'da ise default template argumanı bir vektördür.

-> Stack'in başlık dosyası "stack", queue ve priorty queue için başlık dosyası "queue"dur.

-> Stack, queue, priorty queue kalıtıma uygun olarak dizayn edilmişlerdir. Dolayısıyla bunlardan kalıtım yapılabilir. Taban sınıfın 
containerine "mystack.c " yoluyla erişebiliriz. 

-> Stack exception throw etmez. Yani stack boşken pop() çağrısı tanımsız davranıştır.
Ex:
#include <stack>
int main(){
  using namespace std;
  stack<int> mystack; //stack'in int,dequeue açılımı
  //stack<int,deque<int>> mystack; aynı anlamdadır.
  stack<int, vecto<int>> mystack2; //container vector olarak kullanılır.
}

Ex:
int main(){
  using namespace std;

  stack<int> mystack;
  mystack.push(2);
  mystack.push(3);
  mystack.push(6);
  cout<<"size= "<<mystack.size()<<'\n';
  cout<<"mystack.top()= "<<mystack.top()<<'\n'; //en tepedeki öğeye erişim, son eklenen öğeye
  mystack.top()++; //son eklenen öğeyi 1 artırır.

  while(!mystack.empty()){
    cout<<mystack.top()<<'\n';
    mystack.top()<<'\n';
    mystack.pop();  
  }  
  
}

Ex: (Template Örneği)

template<typename T, typename C=std::deque<T>>
class Stack{
public:
  void push(const T& val){
    C.push_back(val);  
  }
  T& top(){
    return C.back();
  }
   bool empty()const{
     return C.empty();
   } 
  auto size()const{
    return C.size();
  }
}

-> Stack'de initializer list ctor yoktur. Ancak default olarak deque ile initialize edilebilir. Deque kullanmanın bir diğer dezavantajı
ise dequeue contaier seçiminde initialization sırasında başka bir container ile initialize edilememesidir.

Ex:
int main(){
  using namespace std;
  //vector dvec{3,5,6,8};
  //stack<int>mystack{dvec}; //hata
  deque<int> mydec{1,23,4,5,7,98};
  stack<int> {mydec};
}

-> queue, başlık dosyası queue'dur. Yine stack gibi default olarak deque kullanır. 
Ex:
int main(){
  using namespace std;
  queue<string> names;
  names.push("melike");
  names.push("can");
  names.push("ahmet");
  names.push("selda");

  std::cout<<"kuyrukta "<<names.size()<<"kisi var\n";
  std::cout<<"kuyruk basi: "<<names.front()<<'\n';
  std::cout<<"kuyruk sonu: "<<names.back()<<'\n';

  while(!names.empty()){
    cout<<names.front()<<'\n';
    names.pop();
    (void)getchar;
  }
}

-> Priorty Queue'nin default template argumanı vektördür. Priorty queue'nin template parametreleri queue'den daha fazladır.
İlk template parametresi kuyrukta tutulacak öğenin türü, ikinci template parametresi container türü üçüncü parametre ise karşılaştırmadır.

Ex:
#include <iostream>
#include <algorithm>
#include <queue>
int main(){
  using namespace std;
  priority_queue<string> x; //karşılaştırma parametresi verilmeyince max heap olur en büyük öğeler ilk çıkar. 
  for(int i=0;i<10;i++){
    auto name = "can";
    x.push(name);
    cout<<name<<"eklendi.\n";
  }
  while(!x.empty()){
  cout<<x.top()<<"kuyruktan cıkıyor\n";
  x.pop();
  (void)getchar();
  }
}

Ex:
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
int main(){
  using namespace std;
  priority_queue<string, vector<string>, greater<string>> x; //karşılaştırma parametresi verilmeyince max heap olur en büyük öğeler ilk çıkar. 
  vector<string> names={"ali","veli","can","ahmet","nazar","gizem","mithat","sinem","mehmet","soner","kaya"};
  for(int i=0;i<10;i++){
    auto name =names[i];
    x.push(name);
    cout<<name<<"eklendi.\n";
  }
  while(!x.empty()){
  cout<<x.top()<<"kuyruktan cıkıyor\n";
  x.pop();
  (void)getchar();
  }
}
















*/
