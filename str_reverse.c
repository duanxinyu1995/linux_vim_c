#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * reverse_str(char *s)
{
	int len= strlen(s);
	char *ret = (char *)malloc((len+1)*sizeof(char));
	for(int i=0;i<len;i++)
	{
		ret[i]=s[len-1-i];
	}	
	ret[len]='\0';
	return ret;
}
void inverted_order(char *s)
{
	char *q, *p, temp;
	int len= strlen(s);
	p= s;
	q= s+len-1;
	while(q-p>0)
	{
		temp=*p;
		*p=*q;
		*q=temp;
		p++;
		q--;
	}
}
int main()
{
	char *ret;
	char *s= (char *)malloc(sizeof(char));
	int count=0;
	char str;
	printf("please enter the strings before reversing:\n");
	while((str=getchar())!=EOF)
	{
		if(str=='\n')
			break;
		count ++;
		s=(char *)realloc(s, count*sizeof(char));
		s[count-1]=str;
		}
	count++;
	s= (char *)realloc(s, count*sizeof(char));
	s[count]='\0';
	ret=reverse_str(s);
	printf("the reversed strings is :\n %s\n", ret);
	inverted_order(ret);
	printf("the inverted_order is :\n %s \n", ret);
	return 0;
}
