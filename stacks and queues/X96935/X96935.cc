#include <iostream>
#include <stack>

using namespace std;

int main() {

    int n,x;
    cin >> n;
    stack <int> s;

    

    if  (n > 0) {

        cin >> x;
        s.push(x);

        for (int i = 1; i < n; ++i) {
            
            cin >> x; 
            
            if ( n%2 == 0 or i != n/2) {

                if (i >= n/2) {
                    if (s.top() == x) s.pop();
                    else i = n-1;
                }

                else s.push(x);
            }
            
        }

    }

    if (s.empty() or n == 1) cout << "SI" << endl;
    else cout << "NO" << endl;


}






