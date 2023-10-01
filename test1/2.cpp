#include <bits/stdc++.h>
using namespace std;
int ma[7] = {0, 26, 351, 2951, 17901, 83681, 313911};
int main()
{

    int n;
    cin >> n;
    for (int i = 0, ans = 0; i < n; i++)
    {
        string c;
        cin >> c;
        ans = ma[c.length() - 1];
        int l = c.length();
        if(l==1)
        {
            printf("%d\n",c[0]-'a'+1);
            continue;
        }
        int m[27];
        memset(m, 0, sizeof(int) * 27);
        for (int k = 0; k < l; k++)
        {
            if(k==l-1)continue;

            for (int ii = 1; ii <= 26; ii++)
            {
                if (m[ii] != 0)
                {
                    for (int j = ii - 1; j > 0; j--)
                    {
                        m[j] += m[ii];
                    }
                    m[ii] = 0;
                }
            }
            for (int a = k-1>=0?c[k-1]+1:'a'; a < c[k]; a++)
            {
                m[26-(a-'a'+1)]++;
            }
        }
        for(int ii=1;ii<=26;ii++)
        {
            ans+=ii*m[ii];
        }
        ans+=c[l-1]-c[l-2];
        printf("%d\n",ans);
    }
    return 0;
}
