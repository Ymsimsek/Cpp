/*
#include <vector>
#include <algorithm>
#include <string>

int main(){

  using namespace std;
  
  vector<string> svec;
  rfill(svec,100'000,rname);

  char c;

  cout<<"İcinde hangi karakter olanlar sayilsin: ";
  cin>>c;
  auto n = count_if(begin(svec), end(svec), [c](const string& s){
    return s.find(c) != string::npos
  });

  std::cout<<n<<'\n';
  
}
  
    

*/
