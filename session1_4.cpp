#include <bits/stdc++.h>
using namespace std;


int maximum(int n,vector<int> arr){
   int max=arr[0];
   for(int i=1; i<n;i++){
    if (arr[i]>max) {
        max=arr[i];
    }
   }
   return max;
}

int main(){

  int n ;
  cin >> n ;

  vector<int> arr(n);
  for (int i=0; i<n; i++){
    cin >> arr[i];
  }

  cout << maximum(n,arr);

return 0;
}