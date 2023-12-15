 /*
-> STL'de sonu if ile biten algoritmalar, ne algoritmasıysa, ne iş yapıyorsa, o işi yaparken bir predicate kullanılır ve true değer 
   dönen değerlerle o işi yapar.

-> Bir range'deki öğelerde koşula uyan öğeleri başka bir yere kopyalamaya yarar. !!Avoid Raw Loops

Ex:
template<typename InIter, typename OutIter, typename Upred>
OutIter Copyif(InIter beg, InIter end, OutIter destbeg, Upred f){
  while(begin!=end){
    if(f(*beg)){
      *destbeg++=*beg;
    }
    ++beg;
  }
  return destbeg;
}

bool iseven(intx){
  return x%2 ==0;
}

int main(){
  
  using namespace std;

  vector<int> ivec{2,5,7,10,4,3,6,8,1,9};
  list<int>ilist(10);
  Copyif(ivec.begin(),ivec.end(),ilist.begin(),iseven)


}


















*/
