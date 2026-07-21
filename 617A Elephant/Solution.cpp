#include <bits/stdc++.h>
using namespace std;
int main(){
    
    int dist;
    int step{0};

    cin >> dist;
    while(dist >= 1){
    if(dist  >= 5){
        dist -= 5;
        step++;
    }else if(dist >= 4 ){
        dist -= 4;
        step++;
    }else if (dist >= 3 ){
        dist -= 3;
        step++;
    }else if (dist >= 2 ){
        dist -= 2;
        step++;
    }else{
        dist--;
        step++;
    }
}
    cout << step;

    return 0;
}