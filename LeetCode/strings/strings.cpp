#include<bits/stdc++.h>

using namespace std;

int main() {
    string a,b;
    getline(cin, a);
    getline(cin, b);
    cout << a.size() << " " << b.size() << endl;
    string c = a + b;
    cout << c << endl;
    char t = a[0];
    a[0] = b[0];
    b[0] = t;
    cout << a << " " << b << endl;
    return 0;
}