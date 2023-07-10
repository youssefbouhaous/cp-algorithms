#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
  map<int,vector<int>> OurGraph; //Let's consider our graph as a map where each index has an vector that represents the neibghbors of this elements
  int n,e; //n : the number of nodes that we have :::: e the number of the edges that we have
  for(int i=0;i<e;i++){
  int a,b;
  cin>>a>>b;
  OurGraph[a].push_back(b);
  OurGraph[b].push_back(a);
  }
}
