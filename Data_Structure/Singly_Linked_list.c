#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>

struct node
{
	int iData;
	struct node*pNext;
};

void insert_first(struct node **,int);
void insert_last(struct node **,int);					
void insert_at_position(struct node **,int,int);			
void display(struct node *);							
int  search_all(struct node *,int );
int  search_first_occurrence(struct node *,int);									
int  count_node(struct node *pHead); 							
int  delete_first(struct node **);					
int  delete_last(struct node **);					
int  delete_at_position(struct node **, int );       
void concat_list(struct node **,struct node **);
void concat_at_position(struct node **,struct node **,int iPos);
void reveres(struct node **);



int main()
{
	struct node *pFirst = NULL;
	struct node *pSecond = NULL;
	int iDelData,iData,iPosition,iCounter;
	
	while(1)
		{
			
					printf(" \n 1.Add At beginning list :\n 2.Add At End :\n 3.Add After possition :\n 4.Display list:\n 5.Search All_list :\n 6.Search Firstoccurnse list :\n 7.count list :\n 8.Delete First Element :\n 9.Delete last Element :\n 10.Delete Atpossition Element :\n 11.concat list :\n 12.concat Atpossition list :\n 13.Reveres list :\n 14.2nd list inserting :\n 15.Exit :\n " );
		
				printf("Enter Your choice :\t");
				scanf("%d",&iData);
	
			switch(iData)
			{
				case 1:
						printf("\nEnter the element to be inserted :\t");
						scanf("%d",&iData);
						insert_first(&pFirst,iData);
						break;
				
				case 2:
						
						printf("Enter the element to be  inserted :\t ");
						scanf("%d",&iData);
						insert_last(&pFirst,iData);
						break;

				case 3:
					
						printf("Enter the element to be inserted:\t ");
						scanf("%d",&iData);
						printf("Enter the element after possition which to insert :\t");
						scanf("%d",&iPosition);
						insert_at_position(&pFirst,iData,iPosition);
						break;

				case 4:

						display(pFirst);
						
						break;

				case 5:

						printf("Enter the element which you want to sreached:\t  ");
						scanf("%d",&iData);
						iCounter = search_all(pFirst,iData);
						printf(" Occurrence given Number :%d\n",iCounter);
						break;
				
				case 6:		
						printf("Enter the element which you want to search First Occurence:\t");
						scanf("%d",&iData);
						iPosition =search_first_occurrence(pFirst,iData);
						printf("Item Found at position :%d\n",iPosition);						
						break;
		
				case 7:
						iData =count_node(pFirst);
						printf("No Element of is count :%d\n",iData);
						break;

				case 8:
						
						iDelData = delete_first(&pFirst);
						printf("Deleted element value :%d\n",iDelData);
						break;

				case 9:
						
						iDelData = delete_last(&pFirst);
						printf("deleted  element value :%d\n",iDelData);
						break;
					
				case 10:

						printf("Enter the position to be deleted :\t");
						scanf("%d",&iPosition);
						iDelData = delete_at_position (&pFirst,iPosition);
						printf("deleted element given value: %d\n",iDelData);
                
						break;	
			
				case 11:
                                                if(iData == 11)
                                                {
                                                       printf("\n\t! Your 2nd list is Empty. You Want To Enter a Data Than Press Non Zero Number or No then enter 0 \t:");
                                                      scanf("%d",&iCounter);
                                                      if(iCounter !=0)
                                                        {
                                                           for(iCounter=1;iCounter<5;iCounter++) 
                                                           insert_first(&pSecond,5*iCounter);
                                                        }    
						        concat_list(&pFirst,&pSecond);
						        printf("Marged two list\n");
						}
                                                display(pSecond);
						break;
			
				case 12:
                                                if(iData == 12)
                                                {
						        printf("Enter the  possition will start marge list:");
						        scanf("%d",&iPosition);
                                                        printf("\n\t! Your 2nd list is Empty. You Want To Enter a Data Than Press Non Zero Number or No then enter 0 \t:");
                                                        scanf("%d",&iCounter);
                                                        if(iCounter !=0)
                                                         {
                                                                 for(iCounter=1;iCounter<5;iCounter++) 
                                                                 insert_first(&pSecond,4*iCounter);
                                                         }   
						        concat_at_position(&pFirst,&pSecond,iPosition);
                                                        printf("Marged that position to  list\n");
                                                }
                                                display(pSecond);						
                                                break;

				case 13:
						
						 reveres(&pFirst);
						  	 
						 
						 break;
				case 14:
				
						printf("Calling 2nd list\n");
						for(iCounter=1;iCounter<10;iCounter++)
						insert_first(&pSecond,10*iCounter);
						break;
	
				case 15:
	                                        exit(1) ;
	                                
				default:
						 printf("Wrong choice :\n");
			}
                                        
                                        display(pFirst);
		}
		
		return 0;
}
void insert_first(struct node **ppHead,int iNo)
{
	struct node *pNewnode = NULL;

	pNewnode=(struct node *)malloc(sizeof(struct node));
	if(NULL == pNewnode)
	{
		printf("Memory Allocation faild\n");
		return ;
	}
	pNewnode -> iData =iNo;
	pNewnode -> pNext = *ppHead;
	*ppHead = pNewnode;

}

void insert_last(struct node **ppHead,int iNo)
{
	struct node *pTemp = NULL;
	struct node *pNewnode = NULL;
	
	pNewnode = (struct node *)malloc(sizeof(struct node));
	if(NULL == pNewnode)
	{
		printf("link list is empty\n");
		return ;
	}
	pNewnode -> iData = iNo;
	pNewnode -> pNext = NULL;
	
	if(NULL == *ppHead)
	{
		*ppHead = pNewnode;
		return ;
	}
	pTemp =* ppHead;
	while (pTemp -> pNext !=NULL)
	pTemp = pTemp -> pNext;
	pTemp -> pNext = pNewnode;
}

void insert_at_position(struct node **ppHead,int iNo,int iPos)
{
	int iCounter;
	int iTotalCount;
	struct node *pTemp = NULL;
	struct node *pNewnode = NULL;
	iTotalCount = count_node(*ppHead);
	if(iPos < 0 || iPos > iTotalCount +1)	
	{
		printf("position is invild \n");
		return ;
	}
	if(1 == iPos)		
	{
		insert_first(ppHead,iNo);
		return;
	}

	pNewnode = (struct node *)malloc(sizeof(struct node));
	if(NULL == pNewnode)
	{
		printf("Malloc faild\n");
		return ;
	} 
	pNewnode -> iData =iNo;
	pTemp =* ppHead;
	iCounter = 1;
	while(iCounter < iPos-1)
	{
		iCounter ++;
		pTemp = pTemp -> pNext;
	}
	pNewnode -> pNext = pTemp -> pNext;
	pTemp -> pNext = pNewnode;
}
void display(struct node *pHead)
{
	if(NULL == pHead)
	{
		printf("Linked list ls Empty\n");
		return ;
	}
	printf("\nList is :\n");
	while(pHead != NULL)		
	{
		printf("/ %d /-> ",pHead->iData);
		
		pHead = pHead -> pNext;
	}

}
int search_all(struct node *pHead,int iData)
{
	int iCounter = 0;
	while(pHead != NULL)
	{
		if(iData == pHead -> iData)
			iCounter ++;
		pHead = pHead -> pNext;
	}
	
	return iCounter ;
}

int search_first_occurrence(struct node *pHead,int iData)
{
	int iPosition = 0;
	while(pHead != NULL)
	{
		iPosition ++;
		if(iData == pHead -> iData)
		break;
		pHead = pHead -> pNext;
	}
	if(NULL == pHead)
		return 0;
	else
		return iPosition;
}

int count_node(struct node *pHead1)
{	
	int iData = 0;
	while(pHead1 != NULL)
	{
		iData ++;
		pHead1 = pHead1 -> pNext;
	}
	return iData;
}

int delete_first(struct node **ppHead)
{
	int iDelData;
	struct node * pTemp = *ppHead;	 
	if(NULL == *ppHead) 				
	return -1;
	*ppHead = pTemp -> pNext;			 
	iDelData = pTemp -> iData;			
	pTemp -> pNext = NULL;				
	free(pTemp); 					
	pTemp = NULL;						
	return iDelData;
}

int delete_last(struct node **ppHead)
{
	int iDelData;
	struct node *pTemp =*ppHead;
	if(NULL == *ppHead)			
		return -1;				
	if(pTemp -> pNext == NULL)		
	{
		iDelData = pTemp -> iData;
		free(pTemp);			
		pTemp = NULL;
		*ppHead = NULL;			
	}
	{
		while(pTemp -> pNext -> pNext !=NULL) 
		{
			pTemp= pTemp -> pNext;
		}
		iDelData = pTemp -> pNext -> iData;
		pTemp -> pNext = NULL;
		free(pTemp -> pNext); 	
	}
	return iDelData;
}

int delete_at_position(struct node **ppHead, int iPos)
{
	
		int iCounter,iCount,iDelData;

		struct node *pTemp1 = NULL;
		struct node *pTemp2 = NULL;
	
	 	iCount=count_node(*ppHead);
		if(iPos < 0 || iPos > iCount)
		{
			printf("position is inVoid\n ");
			return -1;
		}
		if(1 == iPos)
		{
			return delete_first(ppHead);
		}
	
		pTemp1 = *ppHead;
		iCounter = 1;
		while(iCounter < iPos -1)
		{
			pTemp1 = pTemp1 -> pNext;
			iCounter ++;
		}
		pTemp2 = pTemp1 -> pNext;
		iDelData = pTemp2 -> iData;
		pTemp1 -> pNext = pTemp2 -> pNext;
		pTemp2 -> pNext = NULL;
		free(pTemp2);
		pTemp2 = NULL;
		return iDelData;
}
void concat_list(struct node **ppHead1,struct node **ppHead2)
{
	      struct node*pTemp = NULL;
	      if(NULL == *ppHead2)
	     {
		return;
             }

	     if(NULL == *ppHead1) 
	    {
			*ppHead1 = *ppHead2;
			*ppHead2 = NULL;
			return ;
	    }
	    pTemp = *ppHead1;
	    while(pTemp -> pNext != NULL)
	    pTemp = pTemp -> pNext;
	    pTemp -> pNext = *ppHead2;
	    *ppHead2 = NULL;
            printf("\nConcatating of The Linked List is Successfully Done :\n");

}
void concat_at_position(struct node **ppHead1,struct node **ppHead2,int iPos)
{	
	struct node *pTemp1 = NULL;
	struct node *pTemp2 = NULL;
	int iCounter,iCount;
	 iCount=count_node(ppHead1);
	if(iPos <= 0 ||iPos > iCount +1)
	{
		printf("position invalid");
		return ;
	}
	if(NULL == ppHead2)
	{
		return ;
	}
	if(1 == iPos)
	{
		concat_list(ppHead1,ppHead2);
		*ppHead1 = *ppHead2;
		*ppHead2 = NULL;
		return ;
	}
	if(iPos == iCount + 1)
	{
		concat_list(ppHead1,ppHead2);
		return ;
						
	}
	pTemp1=*ppHead1;
	iCounter=1;
	while(iCounter < iPos -1)
	iCounter ++;
	pTemp1=pTemp1->pNext;	

	pTemp2 = *ppHead2;
	while(pTemp2 -> pNext != NULL)
	pTemp2 = pTemp2 -> pNext;
	pTemp2 -> pNext = pTemp1 -> pNext;
	pTemp1 -> pNext = *ppHead2;
	*ppHead2 = NULL;
        printf("\nConcatating of The Linked List is Successfully Done :\n");

}

void reveres(struct node **pHead)
{
	struct node *pPrev = NULL;
	struct node *pCurrent =* pHead;
	struct node *pNext = NULL;
	while(pCurrent !=NULL)
	{
		pNext = pCurrent ->pNext;
		pCurrent -> pNext = pPrev;
		pPrev = pCurrent;
		pCurrent = pNext;
	}
	*pHead = pPrev;
	

}

