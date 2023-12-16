/*
-> Birinci overload'u bir range ve iki değer alır. Değeri 3. parametresinde olan öğeleri 4. öğeye eşitler.
Ex:
int main(){
  using namespace std;

  vector<int> ivec {2,43,242,6,543,52,2,2,2,456,667,58,9,3,2,2,2,4,5,6,7,8,9,0,6};
  for_each(ivec.begin(),ivec.end(),[](const auto& i){cout<<i<<'\n';});
  replace(ivec.begin(),ivec.end(),2,999);
}





*/
