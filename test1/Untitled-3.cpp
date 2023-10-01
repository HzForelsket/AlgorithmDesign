#include<iostream>
using namespace std;
#define max Max
const long MAXP = 100000;
long prim[MAXP];
long max, numb, PCOUNT; //max存放最多约数个数，numb存放约数个数最多的数
void primes();          //用筛选法产生质数存于prim数组中
void search(long from, long tot, long num, long low, long up);
int main()
{
	primes();
    cout<<PCOUNT;
	long l, u;
	cin >> l >> u;
	if ((l == 1) && (u == 1))
	{
		max = 1;
		numb = 1;
	}
	else
	{
		max = 2;
		numb = l;
		search(1, 1, 1, l, u);
	}
	cout << max << endl << numb << endl;
	system("pause");
	return 0;
}
 
void primes() 
{
	bool get[MAXP+1];
	long i;
	for (i = 2; i <= MAXP; i++)
		get[i] = true;
	for (i = 2; i <= MAXP; i++)
		if (get[i])
		{
			long j = i + i;
			while (j <= MAXP) 
			{
				get[j] = false;
				j += i;
			}
		}
		long ii, j;
		for (ii = 2, j = 0; ii <= MAXP; ii++)
			if (get[ii]) prim[++j] = ii;
		PCOUNT = j;
}
 
void search(long from, long tot, long num, long low, long up)
{
	if (num >= 1)
		if ( (tot > max) || ((tot == max) && (num < numb)) )
		{
			max = tot;
			numb = num;
		}
		if ((low == up) && (low > num)) search(from, tot*2, num*low, 1, 1);
		for (long i = from; i <=PCOUNT; i++)
		{
			if (prim[i] > up) return; 
			else
			{
				long j = prim[i], x = low - 1, y = up, n = num, t = tot, m = 1;
				while (true)
				{
					m++;
					t += tot;
					x /= j;
					y /= j;
					if (x == y) break;
					n *= j;
					search(i+1, t, n, x+1, y);
				}
				m = 1 << m;
				if (tot < max / m) return;
			}
		}
}