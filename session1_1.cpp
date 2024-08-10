#include <bits/stdc++.h>
using namespace std;

int main()

{  string name;
    getline(cin , name );
    if(name.length() >100 || name.length() <=1 ){
      cout << "invalid" << endl;
    }
    else{
    cout << "Hello, "<< name <<"!";}
    return 0;
}