#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>
struct node
{
	struct node *pPrev; 
	int iData;
	struct node *pNext;
};
void insert_first(struct node **,int);
void insert_last(struct node **,int);					
void insert_at_position(struct node **,int,int);			
void display(struct node *);							
int  search_all(struct node *,int );
int  search_first_occurrence(struct node *,int);									
int  count_node(struct node *); 							
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
			printf(" \n 1.Insret :\n 2.Delete : \n 3.Display list:\n 4.Search  :\n 5.count list :\n 6.concat list :\n 7.Reveres list :\n 8.Exit :\n " );
		
				printf(" \n Enter Your choice :\t");
				scanf("%d",&iData);
	        switch(iData)
                  {
                      case 1: 
                                while(1)
                                 {
                                       printf("\n\t1.Add At beginning list :\n\t2.Add At End :\n\t3.Add After possition :\n\t4.Display :\n\t5.back :\n");
                                       printf("\nEnter Your choice :\t");
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
                                                        break ;
                                	        case 5:
	
							break ;
			        	        default:
						         printf("Your choice is Wrong:\n"); 
                                        
                                                }
                                                 if(iData == 5)
                                                         break;
                                                
                                                      
                                      }
                                      break;
                        case 2:
                                
                               while(1)
                               {
                                           printf("\n\t1.Delete First Element :\n\t2.Delete last Element :\n\t3.Delete Atpossition Element \n\t4.Display :\n\t5.Back \n");
                                           printf("\n Enter Your choice :\t");
				           scanf("%d",&iData);
                                        switch(iData)
			                {
                                                 case 1:
						
					        	iDelData = delete_first(&pFirst);
					        	printf("Deleted element value :%d\n",iDelData);
					        	break;
        
				                 case 2:
						
					        	iDelData = delete_last(&pFirst);
					                printf("deleted  element value :%d\n",iDelData); 
					        	break;
					
				                case 3:

					        	printf("Enter the position to be deleted :\t");
					        	scanf("%d",&iPosition);
					        	iDelData = delete_at_position (&pFirst,iPosition);
					        	printf("deleted element given value: %d\n",iDelData); 
					        	break;
                        	                case 4:
                                                         display(pFirst); 
	                                                 break ;
                                                case 5:
                                                         break;
				                default:
        
					        	 printf("Your choice is Wrong:\n"); 
                                        
                                         }
                                                 
                                                        if(iData==5)
                                                        break;
                                        }
                                                                
                                        break;
                        case 3:
			
	                        display(pFirst); 
						
			        break;
                        case 4:
                                while(1) 
                                { 
                                   printf("\n\t1.Search All_list :\n\t2.Search Firstoccurnse list :\n\t3.Display :\n\t4.Back \n");
                                  printf("\nEnter Your choice :\t");
	                          scanf("%d",&iData);
                                  switch(iData)
			         {
                                        case 1:
                                                printf("Enter the element which you want to sreached:\t  ");
						scanf("%d",&iData);
						iCounter = search_all(pFirst,iData);
						printf(" Occurrence given Number :%d\n",iCounter); 
						break;
				
				       case 2:		
				        	printf("Enter the element which you want to search First Occurence:\t");
						scanf("%d",&iData);
					        iPosition =search_first_occurrence(pFirst,iData);
                                                printf("Item Found this position :%d\n",iPosition);
					
						break;
                                       case 3:
                                                display(pFirst); 
                                                break;
                                       case 4:
                                                break;
                                        default:
						         printf("Your choice is Wrong:\n"); 
                                }
                                if(iData == 4)
                                        break;
                        }
                                break;
                                                                
                                                                            
		    case 5:                 
        		        iData =count_node(pFirst);
		        	printf("Number of Element is:%d\n",iData); 
			        break;                
                   case 6:
                         while(1)
                               {
                                           printf("\n\t1..2nd list inserting :\n\t2.concat list :\n\t3.concat Atpossition list :\n\t4.Display \n\t5.Back \n");
                                           printf("\nEnter Your choice :\t");
				           scanf("%d",&iData);
                                     switch(iData)
                                       {
                                                
                                               case 1: 	
                                                        printf("Calling 2nd list......\n");
        						for(iCounter=1;iCounter<10;iCounter++)
        						insert_first(&pSecond,100*iCounter);
        						break;
                                                case 2:

						        concat_list(&pFirst,&pSecond);
						        printf("Marged two list\n");
						
						        break;
			
				                case 3:

						        printf("Enter the  possition will start marge list:");
						        scanf("%d",&iPosition);
						        concat_at_position(&pFirst,&pSecond,iPosition);
						        break;
                                                case 4:
                                                         display(pFirst); 
                                                         break;
                                                case 5:
                                                        break;
                                                 default:
						         printf("Your choice is Wrong:\n"); 
                                          }
                                               if(iData == 5)
                                                break;
                                }
                                break;

                   case 7:
						
		        reveres(&pFirst);
						  
			 break;
                  case 8:
	
			    exit(1) ;
	          default:
			        printf("Your choice is Wrong :\n"); 

             }
      }

    return 0;
}    



void insert_first(struct node **ppHead,int iNo)
{
	struct node *pNewnode=NULL;
	pNewnode=(struct node *)malloc(sizeof(struct node));
	if(NULL==pNewnode)
	{
		printf("memory allocation faild");
		return ;
	}
	pNewnode ->iData=iNo;
	pNewnode ->pPrev=NULL;
	if(NULL==*ppHead)  
	{						
		pNewnode->pNext=NULL;
		*ppHead=pNewnode;
		return ;
	}
	pNewnode->pNext=*ppHead;
	(*ppHead)->pPrev=pNewnode;
	*ppHead=pNewnode;

}
void insert_last(struct node **ppHead,int iNo)
{
	struct node *Temp=NULL;
	struct node *pNewnode=NULL;
	
	pNewnode=(struct node *)malloc(sizeof(struct node));
	if(NULL==pNewnode)
	{
		printf("link list is empty");
		return ;
	}
	pNewnode->iData=iNo;
	pNewnode->pNext=NULL;
	
	if(NULL==*ppHead)
	{
		pNewnode->pPrev=NULL;
		*ppHead=pNewnode;
		return ;
	}
	Temp=*ppHead;
	while(Temp->pNext !=NULL)
	Temp=Temp->pNext;
	Temp->pNext=pNewnode;
	pNewnode->pPrev=Temp;
}
void insert_at_position(struct node **ppHead,int iNo,int iPos)
{
	int iCounter,iTotalCount;
	struct node *pTemp=NULL;
	struct node *pNewnode=NULL;
	iTotalCount=count_node(*ppHead);
	if(iPos <0 || iPos>iTotalCount +1)
	{
		printf("position invild");
		return ;
	}
	if(1==iPos)
	{
		insert_first(ppHead,iNo);
		return;
	}
	if(iPos==iTotalCount +1)
	{
		insert_last(ppHead,iNo);
		return ;
	} 
	pNewnode=(struct node *)malloc(sizeof(struct node));
	if(NULL==pNewnode)
	{
		printf("malloc faild");
		return ;
	} 
	pNewnode->iData=iNo;
	pTemp=*ppHead;
	iCounter =1;
	while(iCounter<iPos-1)
	{
		iCounter ++;
		pTemp=pTemp->pNext;
	}
	pNewnode->pNext=pTemp->pNext;
	pTemp->pNext->pPrev=pNewnode;
	pTemp->pNext=pNewnode;
	pNewnode->pPrev=pTemp;
}

void display(struct node *pHead)
{
	if(NULL == pHead)
	{
		printf("Linked list ls Empty\n");
		return ;
	}
	printf("List is :\n");
	while(pHead != NULL)		
	{
		printf("/ %d / -> ",pHead->iData);
		
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
	if(NULL !=*ppHead)
	(*ppHead)->pPrev=NULL;						
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
   else
	{
		while(pTemp -> pNext -> pNext !=NULL) 
		{
			pTemp= pTemp -> pNext;
		}
		iDelData = pTemp -> pNext -> iData;
		pTemp -> pNext -> pPrev = NULL;
		pTemp -> pNext = NULL;
		free(pTemp -> pNext);
		pTemp=NULL;	
	}
	return iDelData;
}
int delete_at_position(struct node **ppHead, int iPos)
{
	
		int iCounter,iCount,iDelData;

		struct node *pTemp = NULL;
		
	
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
		if(iPos == iCount)
		{
			return delete_last(ppHead);
		}
		pTemp = *ppHead;
		iCounter = 1;
		while(iCounter < iPos -1)
		{
			pTemp = pTemp -> pNext;
			iCounter ++;
		}
		iDelData = pTemp -> iData;
		pTemp -> pPrev -> pNext = pTemp -> pNext;
		
		pTemp -> pNext -> pPrev = pTemp -> pPrev;
		pTemp -> pPrev = NULL;
		pTemp -> pNext =NULL;
        free(pTemp);
		pTemp = NULL;
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
	    (*ppHead2) -> pPrev =pTemp;
	    *ppHead2 = NULL;
            printf("\nConcatating of The Linked List is Successfully Done :\n");

}
void concat_at_position(struct node **ppHead1,struct node **ppHead2,int iPos)
{	
	struct node *pTemp1 = NULL;
	struct node *pTemp2 = NULL;
	int iCounter,iCount;

	 iCount=count_node(*ppHead1);
	if(iPos <= 0 ||iPos > iCount +1)
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
	while(iCounter != iPos -1)
	iCounter ++;
	pTemp1=pTemp1->pNext;	

	pTemp2 = *ppHead2;
	while(pTemp2 -> pNext != NULL)
	pTemp2 = pTemp2 -> pNext;
	pTemp2 -> pNext = pTemp1 -> pNext;
	pTemp1 -> pNext ->pPrev =pTemp2;
	pTemp1 -> pNext = *ppHead2;
	(*ppHead2) -> pPrev =pTemp1;	
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
		pCurrent -> pPrev = pNext;
		pPrev = pCurrent;
		pCurrent = pNext;
	}
	*pHead = pPrev;
	

}

