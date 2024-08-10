#include <bits/stdc++.h>
using namespace std;


int LinearSearch(int n,vector<int> arr,int target){
   int index=-1;
   for(int i=0; i<n;i++){
    if (arr[i]==target) {
        index=i;
        break;
    }
   }
   return index;
}

int main(){

  int n ;
  cin >> n ;

  vector<int> arr(n);
  for (int i=0; i<n; i++){
    cin >> arr[i];
  }

  int target;
  cin >> target;

  cout << LinearSearch(n,arr,target);

return 0;
}