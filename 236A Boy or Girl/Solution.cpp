#include <bits/stdc++.h>
using namespace std;

int main(){

    string name;
    unordered_set<char> st;

    cin >> name ;

    for (char ch : name)
    {
        st.insert(ch);
    }
    
    if (st.size() %2 == 1)
        cout << "IGNORE HIM!";
    else 
        cout << "CHAT WITH HER!";

    return 0;
}