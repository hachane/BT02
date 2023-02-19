#include <bits/stdc++.h>
using namespace std;
int main ()
{
	string s; cin >> s;
	int n = s.length(), idx1 = 0, idx2 = 0;
	int danhdau1[n] = {0}, danhdau2[n] = {0};
	for (int i = 0; i < n; i++)
	{
        if(s[i + 1] == s[i])
        {
            int temp1 = i + 1;
            while(s[temp1] == s[i]) temp1++;
            danhdau1[idx1] = temp1 - i;
            idx1 ++;
            if(s[temp1] == s[temp1 + 1]) i = temp1 - 1;
            else i = temp1;
        }
        if(s[i + 1] != s[i])
		{
		  if((s[i] == s[i + 2]) && (s[i + 1] == s[i + 3]))
        	{
        		int temp2 = i;
        		while((s[temp2] == s[temp2 + 2]) && (s[temp2 + 1] == s[temp2 + 3])) temp2 += 2;
        		danhdau2[idx2] = temp2 - i + 2;
        		idx2++;
        		i = temp2;
			}
		}
    }
    int sum = 0;
    for (int i = 0; i < idx1; i++)
    {
        sum += (danhdau1[i]*(danhdau1[i] - 1))/2 - 1;
        sum += (danhdau1[i] - 1)*(n - danhdau1[i]);
    }
    for (int i = 0; i < idx2; i++) sum += (danhdau2[i]*(danhdau2[i] - 1))/2 - 1;
    cout << (n*(n - 1))/2 - sum;
	return 0;
}
