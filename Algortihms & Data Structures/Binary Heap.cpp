/*
-> Vektörel yapıdan heap haline getirme karmaşıklığı: nlog(n)

Ex:

int main(){
  using namespace std;
  vector<int> ivec{12,24,35,546,43,877,14,5,523,54,654,7,656,83,67,96};
  copy(ivec.begin(),ivec.end(),ostream_iterator<int>{cout," "});
  cout<<'\n'<<'\n';
  make_heap(ivec.begin(),ivec.end()); //binary heap haline getirdi.
  copy(ivec.begin(),ivec.end(),ostream_iterator<int>{cout," "});
  cout<<'\n'<<'\n';
  pop_heap(ivec.begin(),ivec.end()); //vektörün en büyük elemanını vektörün son konumuna getirdi. Geri kalan öğeler yine heap oluşturuyor.
  copy(ivec.begin(),ivec.end(),ostream_iterator<int>{cout," "});
  cout<<'\n'<<'\n';
  ivec.pop_back(); //en büyük öğe cıkartıldı ancak heap halen korunuyor
  copy(ivec.begin(),ivec.end(),ostream_iterator<int>{cout," "});
  cout<<'\n'<<'\n';
  ivec.push_back(125);
  copy(ivec.begin(),ivec.end(),ostream_iterator<int>{cout," "});
  cout<<'\n'<<'\n';
  push_heap(ivec.begin(),ivec.end());
  copy(ivec.begin(),ivec.end(),ostream_iterator<int>{cout," "});
  cout<<'\n'<<'\n';
}






*/
