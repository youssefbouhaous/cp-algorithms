/*
The problem is just the classic fibonacci sequence in it's general form but doing the brute force give us o(n*k) (TLE n <=10^9 and k<=20)
The problem that we have is how to compute it efficiently ? to do so we need to use the matrix form, then compute the matrix using matrix exponentiation algorithm that runs in log(n)
The total complexity o(log(n)*k*k) so it works because k could be 20 and n is large (10^9) 
  */


#include <iostream>
#include <vector>
#define ll long long int

using namespace std;





constexpr ll mod=1e9+7;
vector<ll>initial;

vector<vector<ll>> multiply(vector<vector<ll>> &a,vector<vector<ll>> &b){
    vector<vector<ll>>res(a.size(),vector<ll>(a.size()));
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a.size();j++){
            res[i][j]=0;
            for(int k=0;k<a.size();k++){
                res[i][j]=(res[i][j]+a[i][k]*b[k][j]%mod)%mod;
            }
        }
    }
    return res;
}



int main(){

    ll n,k;cin>>n>>k;
    initial.resize(k);
    initial[0]=1;
    for(int i=1;i<k;i++){
        for(int j=0;j<i;j++){
            initial[i]=(initial[i]+initial[j])%mod;
        }
    }
    if(n<k){
        cout<<initial[n]<<endl;
        return 0;
    }
    vector<vector<ll>>fib(k,vector<ll>(k));
    for(int i=0;i<k;i++){
        fib[0][i]=1;
    }
    for(int i=1;i<k;i++){
        fib[i][i-1]=1;
    }
    vector<vector<ll>>I(k,vector<ll>(k));
    for(int i=0;i<k;i++){
        I[i][i]=1;
    }
    n=n-k+1;
    while(n){
        if(n&1){
            I=multiply(I,fib);
        }
        fib=multiply(fib,fib);
        n>>=1;
    }
    ll ans=0;
    for(int i=0;i<k;i++){
        ans=(ans+I[0][i]*initial[k-i-1])%mod;
    }
    cout<<ans<<endl;
    return 0;
}
