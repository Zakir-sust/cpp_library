int lg[N];
void build()
{
	for(int i = 2;i < N;i++)
		lg[i] = lg[i/2] + 1;
	for(int k = 1; k<= 30; k++){
		for(int i = 1; i + (1<<k) - 1<= n;i++){
			tab[i][k] = min(tab[i][k - 1],tab[i + (1 << (k - 1))][k-1]);
		}
	}
}
int query(int l,int r)
{
	int d = lg[r-l+1];
	return min(tab[l][d],tab[r-(1<<d)+1][d]);
}
