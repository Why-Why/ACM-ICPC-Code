// 增加函数countMin。
// 找到小于等于k的数的个数。
// 可以修改来找到比k大的所有数里面维护的值最大的那个。

int countMin(int k)
{
	int u=root;
	int ret=0;

	while(u)
	{
		if(key[u]==k)
			return ret+cou[u]+size[ch[u][0]];

		if(key[u]<k)
		{
			ret+=cou[u]+size[ch[u][0]];
			u=ch[u][1];
		}
		else
			u=ch[u][0];
	}

	return ret;
}


