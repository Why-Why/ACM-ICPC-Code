def getans(n):
	if n==0:
		return 1;
	if n==1:
		return 1;
	if n==2:
		return 2;
	ret=(n+2)/2+getans(((n-1)/2-1)/2);
	return ret;


n=input();
ans=(n+1)/2+getans(((n/2)-1)/2);

print ans;
