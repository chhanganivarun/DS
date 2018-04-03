int pow(int x,int n)
{
	if(n==0)
		return 1;
	if(n&1)
	{
		return x*pow(x,n-1);
	}
	return pow(x,n>>1)*pow(x,n>>1); 
}
//Todo pow(a,b)%c in log(n)

long long powmod(long long a,long long b,long long c)
{
	if(y==0)
		return 1;
	if(y%2==0)
	{
		return (f(a,b/2)*f(a,b/2))%c;
	}
	return (f(a,b/2)*f(a,b/2)*a)%c;
	
}

