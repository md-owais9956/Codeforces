#include <bits/stdc++.h>
using namespace std;
int main(){

    int x{0};
    
    int n;
    cin>>n;
    vector <string> op(n);

    for (int  i = 0; i < n; i++)
    {
        cin>>op[i];
    }
    for (int  i = 0; i < n; i++)-
    {
        if(op[i]=="++x" || op[i] == "x++"){
            x++;
        }else{
            x--;
        }
    }
    cout<<x<<endl;
    
    return 0;
}

