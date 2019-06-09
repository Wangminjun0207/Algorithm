#include "Predefine.h"

//ÅÅÐòº¯Êý
void Sort(BSubT p,int key)
{
	int i,j;
	p->n++;
	for(i=1;i<p->n;i++)
		if(key<p->K[i]){
			for(j=p->n;j>i;j--)
				p->K[j]=p->K[j-1];
			p->K[i]=key;
			break;
		}
	if(i==p->n) p->K[i]=key;
}
