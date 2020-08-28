#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
	struct  node *pPrev;
	int iData;
	struct  node *pNext;
};
 
void createList(struct  node **, struct  node **);
void insertNode(struct  node *, struct  node *,int iNo,int *);
int deleteNode(struct  node *, struct  node *, int);
void display(struct  node *, struct  node *);
 


int main()
{
	struct  node *pFirst=NULL,*pLast=NULL;
	struct  node *pTemp=NULL,*pTLast=NULL;
	int iChoice,iNo,iCount=0;	
	createList(&pFirst,&pLast);
	display(pFirst,pLast);
	

	while(1)
	{
		printf("\n\n 1.InsertNode \n 2.DeleteNode \n 3.Exit\n");
		printf(" Enter Your Choice\t");
		scanf("%d",&iChoice);
		if(iChoice==3)
			break;
		
		switch(iChoice)
		{
			case 1 :
				if(iCount==5)
				{
					printf("\n\t Linked List Is Full\n");
					continue;
				}
				printf("\n\t Enter a Data\t");
				scanf("%d",&iNo);
				insertNode(pFirst,pLast,iNo,&iCount);
				display(pFirst,pLast);
				break;
			case 2 :
				pTemp=pFirst;
				pTLast=pLast;
				iChoice=0;
				do
				{
					if(pTemp->iData==0)
						iChoice++;
					if(iChoice==5)
					{
						printf("\n\tData is Not Present\n");
						break;
					}
					pTemp=pTemp->pNext;
				}while(pTemp!=pTLast->pNext);
				
				printf("\n\t Enter a Postion To Delete Data\t");
				scanf("%d",&iChoice);
				if(iChoice<=0 || iChoice>iCount)
				{
					printf("\n\t Position is Invalid\n");
					continue;
				}
				iChoice=deleteNode(pFirst,pLast,iChoice);
				if(iChoice==0)
					printf("\n\t Data is Not Present\n");
				else
					printf("\n\t Deleted Data is : %d\n",iChoice);

				display(pFirst,pLast);

				break;
			default :
				printf("\n\t Invalid Choice\n");				
		}


    	}
	while(pFirst!=NULL)
	{
		if(pFirst==pLast)
		{
			pFirst->pNext=pFirst->pPrev=NULL;
			free(pFirst);
			pFirst=pLast=NULL;
		}
		else
		{
			pLast=pLast->pPrev;
			pLast->pNext->pNext=NULL;
			pLast->pNext->pPrev=NULL;
			free(pLast->pNext);
			pLast->pNext=pFirst;
			pFirst->pPrev=pLast;

		} 
	} 
		
	return 0;
}
void createList(struct  node **ppHead, struct  node **ppTail)
{
	int iCounter,iCounter2;
	struct  node *pNewNode[5]={NULL};
	for(iCounter=0;iCounter<5;iCounter++)
	{
		pNewNode[iCounter]=(struct  node *)malloc(sizeof(struct  node));
		if(NULL == (pNewNode[iCounter]))
		{
			for(iCounter2=0;iCounter2<=iCounter;iCounter2++)
			{
				printf("Memory Allocation Failed\n");
				free(pNewNode[iCounter2]);
				pNewNode[iCounter2]=NULL;	
			}
			return ;
		}
		(pNewNode[iCounter])->iData=0;
		if(NULL==*ppHead)
		{
			*ppHead=*ppTail=(pNewNode[iCounter]);
			(*ppHead)->pNext=(*ppHead)->pPrev=*ppTail;
		}
		else
		{
			(pNewNode[iCounter])->pPrev=*ppTail;
			(*ppTail)->pNext=(pNewNode[iCounter]);
			*ppTail=(pNewNode[iCounter]);
			(*ppTail)->pNext=*ppHead;
			(*ppHead)->pPrev=*ppTail;
	
		}
	}

}
 
int deleteNode(struct  node *pHead , struct  node *pTail , int iPos)
{
	int iVal=1;

	
	while(iVal<=iPos-1)
	{
		 iVal++;
		
		pHead=pHead->pNext;
	}

	if(pHead->iData!=0)
	{
		iVal=pHead->iData;
		pHead->iData=0;
		return iVal;
	}
	return 0;
}
void insertNode(struct  node *pHead, struct  node *pTail,int iNo,int *iCount)
{
	int iPos=0;
	while(iPos!=(*iCount))
	{
		pHead=pHead->pNext;
		iPos++;
	}
	pHead->iData = iNo;
	(*iCount)++;
}
void display(struct  node *pHead, struct  node *pTail)
{
	 
	printf("\n\t");
	do
	{
		printf(" | %d |->",pHead->iData);
		pHead=pHead->pNext;
	}while(pHead!=pTail->pNext);
	
}

