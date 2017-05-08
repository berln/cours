int main(int argc, char const *argv[])
{
	int pida;
	pida=fork();
	if(pida==-1)
		printf("fail fork\n");
	if (pida==0)
	{
		execl(arg[1],(char*)0)
		exit(0);
	}

	seekshild()
	return 0;
}