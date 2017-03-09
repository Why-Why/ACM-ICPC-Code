class NUM(object):
	def __init__(self,S,X):
		self.S=S;
		self.X=X;

	def add(self,b):
		return NUM(b.S*self.X+b.X*self.S,b.X*self.X);

T=input();
cas=1;

def mcmp(a,b):
	if a.S*b.X<a.X*b.S:
		return -1;
	elif a.S*b.X==a.X*b.S:
		return 0;
	else :
		return 1;

while T:
	N=input();
	arr=[];
	for i in range(0,N):
		s=raw_input().split(":");
		arr.append(NUM(int(float(s[0])*1000),int(float(s[0])*1000)+int(float(s[1])*1000)));

	arr.sort(mcmp);
	ss=NUM(0,1);
	ans=0;

	for i in range(0,N):
		temp=ss.add(arr[i]);

		if temp.S<temp.X:
			ans+=1;
			ss=temp;
		else:
			break;

	print 'Case #'+str(cas)+': '+str(ans);

	cas+=1;
	T-=1;
