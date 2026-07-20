#include <bits/stdc++.h>
using namespace std;
int main(){

    int a,b;
    int count{0};

    cin >> a >> b;

    while(b >= a){
        a *= 3;
        b *= 2;
        count++;
    }
    cout << count;

    return 0;
}