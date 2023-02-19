#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int n, temp;
    cin>>n;
    if (n < 0)
    {
    	cout << n;
    	return 0;
	}
    cout << n << " ";
    while (n > 0)
    {
        temp = n;
        cin >> n;
        if(n != temp) cout << n << " ";
    }
    return 0;
}
