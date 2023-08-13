#include <iostream>
#include <vector>
#include <cmath>
#define ll long long int
using namespace std;
vector<ll> tree;
 
ll sum(int k) {
  ll s=0;
  while(k>=1){
    s+=tree[k];
    k-=k&-k;
  }  
  return s;
}
 
void add(int k, int x, int n) {
   while(k<=n){
    tree[k]+=x;
    k+=k&-k;
   }
}
 
int main() {
    int n, q,op,l,r;
    cin >> n >> q;
    vector<int> a(n + 1);
    tree.assign(n + 1, 0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        add(i,a[i],n);
    }
    while(q--){
        cin>>op>>l>>r;
        if(op==1){
            add(l,r-a[l],n);
            a[l]=r;
        }
        else{
            cout<<sum(r)-sum(l-1)<<endl;
        }
    }
    return 0;
}
