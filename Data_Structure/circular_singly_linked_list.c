#include<stdio.h>
#include<malloc.h>
struct node
{
		int iData;
		struct node *pNext;
};
void insert_first(struct node **pHead,struct node **pTail,int iNo);
void insert_last(struct node **ppHead,struct node **ppTail,int iNo);
void insert_at_position(struct node **ppHead,struct node **ppTail,int iNo,int iPos);
int delete_first(struct node **ppHead,struct node **ppTail);
int delete_last(struct node **ppHead,struct node **ppTail);
int count_node(struct node *pHead,struct node *pTail);
int search_all(struct node *pHead,struct node *pTail,int iNo);
int search_first_occurrence(struct node *pHead,struct node *pTail,int iNo);
void concat_list(struct node **ppHead1,struct node **ppTail1 ,struct node **ppHead2,struct node **ppTail2);
void concat_at_position(struct node **ppHead1,struct node **ppTail1 ,struct node **ppHead2,struct node **ppTail2,int iPos);
void reverse(struct node **ppHead,struct node **ppTail);
void display (struct node *pHead,struct node *pTail);


int main()
{
        int iCounter,iDelData;
		struct node *pFirst = NULL;
		struct node *pLast = NULL;
                
                struct node *pFirst1 = NULL;
		struct node *pLast1 = NULL;
		
	

                for(iCounter=1;iCounter<10;iCounter++)
		insert_first(&pFirst,&pLast,10*iCounter);
               
               
               
                //insert_last(&pFirst,&pLast,50);
               
               //insert_at_position(&pFirst,&pLast,200,5);

              //  iDelData=delete_first(&pFirst,&pLast);
                //printf("Deleted First Node of data is: %d\n",iDelData);
                
                //iDelData=delete_last(&pFirst,&pLast);
                //printf("Deleted last Node of data is: %d\n",iDelData);
                
                //iCounter=count_node(pFirst,pLast);
                //printf("Total No of Count is : %d\n",iCounter);
                
                //iCounter=search_all(pFirst,pLast,30);
                //printf(" Occurrence given Number :%d\n",iCounter);

                //iCounter=search_first_occurrence(pFirst,pLast,30);
                //printf("Item Found at-This position :%d\n",iCounter);
        
       //          for(iCounter=1;iCounter<10;iCounter++)
		//insert_first(&pFirst1,&pLast1,25*iCounter);

                //concat_list(&pFirst,&pLast,&pFirst1,&pLast1);
                
                //concat_at_position(&pFirst,&pLast,&pFirst1,&pLast1,5);
                
                reverse(&pFirst,&pLast);

		display(pFirst,pLast);
		 
		return 0;

}
void insert_first(struct node **ppHead,struct node **ppTail,int iNo)
{
	struct node *pNewnode = NULL;
	pNewnode = (struct node *)malloc (sizeof (struct node));
	if(NULL == pNewnode)
	{
		printf  ("Memory Allocation is faild : ");
		return ;
	}
        pNewnode->iData=iNo;
	if(NULL == *ppHead)
	{
		*ppHead = pNewnode ;
		*ppTail = pNewnode ;
		(*ppTail)-> pNext = *ppHead;
		return ;
	}
	pNewnode->pNext=*ppHead;
	*ppHead=pNewnode;
	(*ppTail)->pNext = *ppHead;

	
}
void insert_last(struct node **ppHead,struct node **ppTail,int iNo)
{
        struct node *pNewnode = NULL;
	pNewnode = (struct node *)malloc (sizeof (struct node));
	if(NULL == pNewnode)
	{
		printf("Memory Allocation is faild : ");
		return ;
	}
        pNewnode->iData=iNo;
	if(NULL == *ppHead)
        {
		*ppHead = pNewnode ;
		*ppTail = pNewnode ;
		(*ppTail)-> pNext = *ppHead;
		return ;
	}
        (*ppTail)-> pNext =pNewnode;
        *ppTail =pNewnode;
        (*ppTail)-> pNext = *ppHead;
        
}

void insert_at_position(struct node **ppHead,struct node **ppTail,int iNo,int iPos)
{
        struct node *pNewnode = NULL;
        struct node *pTemp=NULL;
        int iCounter=count_node(*ppHead,*ppTail);
        if(iPos <=0 || iPos > iCounter ++)
        {
             printf("! Involid Position ! :\n");
                return ;
        }
        if(1 == iPos)
        {
                insert_first(ppHead,ppTail,iNo);
                return ;
        }
        if(iPos == iCounter +1)
        {
                insert_last(ppHead,ppTail,iNo);
                return ;
        }
        pNewnode=(struct node *)malloc (sizeof(struct node));
        if(NULL == pNewnode)
        {
                printf("Malloc Faild");
                return ;
        }
        pNewnode->iData=iNo;
        pTemp=*ppHead;
        iCounter = 1;
        while(iCounter < iPos - 1)
        {
                iCounter ++;
                pTemp = pTemp -> pNext;
        }
        pNewnode -> pNext = pTemp -> pNext;
         (*ppTail)-> pNext =pNewnode;
        pTemp ->pNext = pNewnode ;
        (*ppTail)-> pNext = *ppHead;
}

int delete_first(struct node **ppHead,struct node **ppTail)
{
	struct node *pTemp=NULL;
	int iDelData;	

	if(NULL == *ppHead)
	{
        printf("Linklist is Empty :");
		return -1;
	}
	iDelData=(*ppHead)->iData;
	if(*ppHead == *ppTail)
	{
		(*ppHead)->pNext=NULL;
		
		free(*ppHead);
		*ppHead=*ppTail=NULL;
		return iDelData;
	}
	pTemp=*ppHead;
	*ppHead=pTemp->pNext;
	pTemp->pNext=NULL;

	(*ppTail)->pNext=*ppHead;
	
	free(pTemp);
	pTemp=NULL;
	return iDelData;	
}

int delete_last(struct node **ppHead,struct node **ppTail)
{
        int iDelData;
        struct node  *pTemp = NULL;
        if(NULL == *ppHead)
        {
                printf(" ! Linked list is Empty !:\n");
                return - 1;
        }
       
        if(*ppHead == *ppTail)
        {     
                 
                (*ppHead)->pNext=NULL;
                 iDelData=(*ppHead)->iData;
                free(*ppHead);
                *ppHead =*ppTail =NULL;

                 return iDelData;
        }
        pTemp =*ppHead;
        while(pTemp -> pNext != *ppTail) 
         pTemp=pTemp->pNext;

         (*ppTail)= pTemp;
        pTemp =(*ppTail) -> pNext;
        pTemp ->pNext=NULL;
        iDelData=pTemp->iData;   
       
        (*ppTail)->pNext=*ppHead;
        
        free(pTemp);
        pTemp=NULL;
        
	return iDelData;	
}
      
int count_node(struct node *pHead,struct node *pTail)
{
        int iCounter = 0;
        if(NULL == pHead)
        {
                printf("Link List is Empty !\n");
                return 0;
        }
        do
        {
                iCounter ++;
                pHead = pHead -> pNext;
        }while(pHead != pTail -> pNext );
               
         return iCounter;
}

int search_all(struct node *pHead,struct node *pTail,int iNo)
{
        int iCounter = 0;
        if(NULL == pHead)
        {
                printf("! LinkList is Empty ..!:");
                return 0;
        }
        do
        {
                if(iNo == pHead ->iData)
                iCounter ++;
                pHead = pHead -> pNext;
        }while(pHead != pTail ->pNext);
        return iCounter;
} 
                                   
int search_first_occurrence(struct node *pHead,struct node *pTail,int iNo)
{
         int iCounter = 0;
         do
        {
              iCounter ++;
                if(iNo == pHead ->iData)
                break;
                pHead = pHead ->pNext;
        }while(pHead != pTail ->pNext);
        
        if(pHead == pTail -> pNext)
                return iCounter;
        else
                return iCounter;
}     

void concat_list(struct node **ppHead1,struct node **ppTail1 ,struct node **ppHead2,struct node **ppTail2)
{
        if(NULL == *ppHead2)
        {
                printf("Linklist is Empty :\n");
                return ;
        }
        if(NULL == *ppHead1)
        {
                printf("Linklist is Empty :\n");
                *ppHead1=*ppHead2;
                *ppTail1=*ppTail2;
                *ppTail2=*ppHead2=NULL;
                     
                return ;
        }
         (*ppTail1)->pNext=*ppHead2;
          *ppTail1=*ppTail2;   
        (*ppTail1)->pNext=*ppHead1;
        printf("\nConcatating of The Linked List is Successfully Done :\n");
}  
void concat_at_position(struct node **ppHead1,struct node **ppTail1 ,struct node **ppHead2,struct node **ppTail2,int iPos)
{	
	struct node *pTemp = NULL;
	
	int iCounter;
	 iCounter=count_node(*ppHead1,*ppTail1);
	if(iPos <= 0 ||iPos > iCounter +1)
	{
		printf("position invalid");
		return ;
	}
	if(NULL == *ppHead2)
	{
		return ;
	}
	if(1 == iPos)
	{
		concat_list(ppHead1,ppTail1,ppHead2,ppTail2);
		*ppHead1 = *ppHead2;
                *ppTail1 = *ppTail2;
		*ppHead2 = *ppTail2 = NULL;
		return ;
	}
	if(iPos == iCounter + 1)
	{
		concat_list(ppHead1,ppTail1,ppHead2,ppTail2);
		return ;
						
	}
	pTemp = *ppHead1;
	iCounter = 1;
	while(iCounter != iPos -1)
        {
                iCounter ++;
                pTemp = pTemp -> pNext;	
        	
        }
        (*ppTail2) -> pNext = pTemp -> pNext;	
        
        pTemp ->pNext = *ppHead2;
	
        *ppHead2 = *ppTail2 =NULL;
        printf("\nConcatating of The Linked List is Successfully Done :\n");

}
void reverse(struct node **ppHead,struct node **ppTail)
{
         struct node *pPrev = *ppTail;
         struct node *pCurrent = *ppHead;
         struct node *pNext = NULL;
         if(NULL == *ppHead)
          {
                printf("List is Empty \n");
                return ;
          }
          do
          {
                pNext = pCurrent -> pNext;
                pCurrent -> pNext = pPrev;
                pPrev = pCurrent ;
                pCurrent = pNext;
          }while (pCurrent != *ppHead );
            *ppHead = pPrev;
             *ppTail = pCurrent ;
}
void display (struct node *pHead,struct node *pTail)
{
	if(NULL == pHead)
	{
		printf("!List is empty ! \n");
		return ;
	}  
        printf("List is..\n");
	do
	{       
        	printf("/ %d /-> ",pHead -> iData);
		pHead = pHead -> pNext;
	}while (pHead != pTail -> pNext);
}

