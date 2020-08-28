#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>
struct node
{
        struct node *pPrev; 
    	int iData;
	struct node *pNext;
};
void insert_first(struct node **pHead,struct node **pTail,int iNo);
void insert_last(struct node **ppHead,struct node **ppTail,int iNo);
void insert_at_position(struct node **ppHead,struct node **ppTail,int iNo,int iPos);
int delete_first(struct node **ppHead,struct node **ppTail);
int delete_last(struct node **ppHead,struct node **ppTail);
int delete_at_position(struct node **ppHead , struct node **ppTail , int iPos);
int count_node(struct node *pHead,struct node *pTail);
int search_all(struct node *pHead,struct node *pTail,int iNo);
int search_first_occurrence(struct node *pHead,struct node *pTail,int iNo);
void concat_list(struct node **ppHead1,struct node **ppTail1 ,struct node **ppHead2,struct node **ppTail2);
void concat_at_position(struct node **ppHead1,struct node **ppTail1 ,struct node **ppHead2,struct node **ppTail2,int iPos);
void reverse(struct node **pHead,struct node **pTail);
void display (struct node *pHead,struct node *pTail);

int main()
{ 

         int iCounter,iDelData,iData,iPosition;
	 struct node *pFirst = NULL;
	 struct node *pLast = NULL;

                
         struct node *pFirst1 = NULL;
	 struct node *pLast1 = NULL;

        while(1)
		{
			printf(" \n 1.Insret :-\n 2.Delete :- \n 3.Display list :-\n 4.Search :-\n 5.count list :-\n 6.concat list :-\n 7.Reveres list :-\n 8.Exit :-\n " );
		
			printf("\n! Enter Your choice !:-\t");
			scanf("%d",&iData);
 	        switch(iData)
                  {
                      case 1: 
                            
                        while(1)
                           {
                                printf("\n\t1.Add At beginning list :-\n\t2.Add At End :-\n\t3.Add After possition :-\n\t4.Display :-\n\t5.back :-\n");
                               printf("\n! Enter Your choice !:-\t");
		                 scanf("%d",&iData);
                        
		       	      switch(iData)
			        {
			             case 1:
				              printf("\nEnter the element to be insert First position :-\t");
				              scanf("%d",&iData);
                                              insert_first(&pFirst,&pLast,iData);
					      break;
				
			            case 2:
						
					      printf("Enter the element to be  insert Last Position :-\t ");
					      scanf("%d",&iData);
					      insert_last(&pFirst,&pLast,iData);
			        	      break;

			           case 3:
					
				              printf("Enter the element to be inserted :-\t ");
					      scanf("%d",&iData);
					      printf("Enter the element after possition which to insert :-\t");
					      scanf("%d",&iPosition);
					      insert_at_position(&pFirst,&pLast,iData,iPosition);
			        	      break;

                                   case 4:
                                               display(pFirst,pLast);
	
                                              break ;
                                   case 5:
	
					      break ;
			           default:
				              printf("! Your choice is Wrong !:-\n"); 
                                        
                                }
                                              if(iData == 5)
                                              break;
                                                
                                                      
                      }
                                              break;
                      case 2:
                                
                              while(1)
                               {
                                            printf("\n\t1.Delete First Element :\n\t2.Delete last Element :\n\t3.Delete Atpossition Element :-\n\t4.Display :-\n\t5.Back :-\n");
                                            printf("\n! Enter Your choice !:-\t");
				            scanf("%d",&iData);
                                        switch(iData)
			                {
                                              case 1:
					        	iDelData=delete_first(&pFirst,&pLast);
					        	printf("Deleted element value :-%d\n",iDelData);
					        	break;
        
				              case 2:
						
					        	iDelData=delete_last(&pFirst,&pLast);
					                printf("deleted  element value :-%d\n",iDelData); 
					        	break;
					
				              case 3:

					        	printf("Enter the position to be deleted :-\t");
					        	scanf("%d",&iPosition);
					        	iDelData=delete_at_position(&pFirst,&pLast,iPosition);
					        	printf("deleted element given value :- %d\n",iDelData); 
					        	break;
                        	              case 4:
                                                         display(pFirst,pLast);
	 
	                                                 break ;                                                
                                              case 5:
                                                         break;
				              default:
        
					        	printf("! Your choice is Wrong !:-\n"); 
                                        
                                         }
                                                 
                                                        if(iData==5)
                                                        break;
                                }
                                                                
                                        break;
                        case 3:
			
	                         display(pFirst,pLast);
	 
						
			        break;
                        case 4:

                                while(1) 
                                { 
                                   printf("\n\t1.Search All_list :-\n\t2.Search Firstoccurnse list :-\n\t3.Display :-\n\t4.Back :-\n");
                                   printf("\n! Enter Your choice !:-\t");
	                           scanf("%d",&iData);
                                  
                                     switch(iData)
         			     {
                                        case 1:
                                                printf("Enter the element which you want to sreached :-\t  ");
						scanf("%d",&iData);
						iCounter=search_all(pFirst,pLast,iData);
						printf(" Occurrence given Number :-%d\n",iCounter); 
						break;
				
				        case 2:		
				        	printf("Enter the element which you want to search First Occurence :-\t");
						scanf("%d",&iData);
					        iCounter=search_first_occurrence(pFirst,pLast,iData);
                                                printf("Item Found at-This position :-%d\n",iCounter);
					
						break;
                                        case 3:
                                                 display(pFirst,pLast);
	 
                                                break;
                                        case 4:
                                                break;

                                         default:
						   printf("! Your choice is Wrong !:-\n"); 
                                  }
                                
                                        if(iData == 4)
                                        break;
                            }
                                break;
                                                                
                                                                            
		    case 5:                 
        		        iCounter=count_node(pFirst,pLast);
                                printf("\n! Total No of Count is !:- %d\n",iCounter);
			        break;                
                   case 6:
                         while(1)
                               {
                                     printf("\n\t1..2nd list inserting :-\n\t2.concat list :-\n\t3.concat Atpossition list :-\n\t4.Display :- \n\t5.Back :-\n");
                                    printf("\n! Enter Your choice !:-\t");
				      scanf("%d",&iData);
                                      switch(iData)
                                      {
                                                
                                        case 1: 	
                                                 printf("Calling 2nd list......:-\n");
        					 for(iCounter=1;iCounter<10;iCounter++)
		                                 insert_first(&pFirst1,&pLast1,25*iCounter);
        				         break;
                                        case 2:

						  concat_list(&pFirst,&pLast,&pFirst1,&pLast1);
						  printf("\n Marged two list :-\n");
						
						  break;
			
				         case 3:

						  printf("Enter the  possition will start marge list :-");
						  scanf("%d",&iPosition);
						  concat_at_position(&pFirst,&pLast,&pFirst1,&pLast1,iPosition);
						  break;
                                         case 4:
                                                   display(pFirst,pLast);
	
                                                  break;

                                         case 5:
                                                   break;

                                         default:
						  printf("! Your choice is Wrong !:-\n"); 
                                          

                                         }
                                           if(iData == 5)
                                                break;
                                }
                                break;

                        case 7:
			while(1)

                               {
                                     printf("\n\t1.reverse call :-\n\t2.reverse Display :-\n\t3.Back :-\n");
                                     printf("\n! Enter Your choice !:-\t");
				      scanf("%d",&iData);
                                      switch(iData)
                                      {		
                                        case 1:	
		                                 reverse(&pFirst,&pLast);
                                                 break;
                                        case 2:						  
			                        display(pFirst,pLast);
                                                 break; 
                                        case 3:
                                                 break;
                
                                        default:
						   printf("! Your choice is Wrong !:-\n"); 
                                          

                                       }
                                           if(iData == 3)
                                              break;
                                 }  
                                      break;                  

                  case 8:
	
			    exit(1) ;
	          default:
			        printf("! Your choice is Wrong !:-\n"); 

             }
      }



	 return 0;

}
void insert_first(struct node **ppHead,struct node **ppTail,int iNo)
{
	struct node *pNewnode = NULL;
	pNewnode = (struct node *)malloc (sizeof (struct node));
	if(NULL == pNewnode)
	{
		printf  ("Memory Allocation is faild :- ");
		return ;
	}
        pNewnode->iData=iNo;
	if(NULL == *ppHead)
	{
		*ppHead = pNewnode ;
		*ppTail = pNewnode ;
		(*ppTail)-> pNext = *ppHead;
                (*ppHead)->pPrev=*ppTail;
		return ;
	}
	pNewnode->pNext=*ppHead;
        (*ppHead)->pPrev=pNewnode;
	*ppHead=pNewnode;
	(*ppTail)->pNext = *ppHead;
        (*ppHead)->pPrev=*ppTail;

	
}

void insert_last(struct node **ppHead,struct node **ppTail,int iNo)
{
        struct node *pNewnode = NULL;
	pNewnode = (struct node *)malloc (sizeof (struct node));
	if(NULL == pNewnode)
	{
		printf  ("Memory Allocation is faild :- ");
		return ;
	}
        pNewnode->iData=iNo;
	if(NULL == *ppHead)
        {
		*ppHead = pNewnode ;
		*ppTail = pNewnode ;
		(*ppTail)-> pNext = *ppHead;
                  (*ppHead)->pPrev=*ppTail;
		return ;
	}
        (*ppTail)-> pNext =pNewnode;
        *ppTail =pNewnode;
        (*ppTail)-> pNext = *ppHead;
        (*ppHead)->pPrev=*ppTail;
        
}
void insert_at_position(struct node **ppHead,struct node **ppTail,int iNo,int iPos)
{
        struct node *pNewnode = NULL;
        struct node *pTemp=NULL;
        int iCounter=count_node(*ppHead,*ppTail);
        if(iPos <=0 || iPos > iCounter ++)
        {
             printf("! Position is Invalid ! :-\n");
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
                printf("Malloc Faild :-");
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
        pNewnode ->pNext -> pPrev=pNewnode;
        pTemp ->pNext = pNewnode ;
        pNewnode ->pPrev =pTemp;
}
int delete_first(struct node **ppHead,struct node **ppTail)
{
	struct node *pTemp=NULL;
	int iDelData;	

	if(NULL == *ppHead)
	{
                printf("! Your List is Empty...! :-");
		return -1;
	}
	iDelData=(*ppHead)->iData;
	if(*ppHead == *ppTail)
	{
		(*ppHead)->pNext=NULL;
		(*ppHead)->pPrev=NULL;
		free(*ppHead);
		*ppHead=*ppTail=NULL;
		return iDelData;
	}
	pTemp=*ppHead;
	*ppHead=pTemp->pNext;
	pTemp->pNext=NULL;
	pTemp->pPrev=NULL;
	(*ppHead)->pPrev=*ppTail;
	(*ppTail)->pNext=*ppHead;
	
	free(pTemp);
	pTemp=NULL;
	return iDelData;	
}

int delete_last(struct node **ppHead,struct node **ppTail)
{
        struct node *pTemp=NULL;
        int iDelData;
        if(NULL == *ppHead)
        {
                printf("! Your List is Empty...! :-");
                return -1;
        }
        if(*ppHead == *ppTail)
        {
                (*ppHead)->pNext = NULL;
                (*ppHead)->pPrev=NULL;
                iDelData=(*ppHead)->iData;
                free(*ppHead);
                *ppHead=*ppTail=NULL;
                return iDelData;
        }
        pTemp=*ppHead;
        while(pTemp->pNext != *ppTail)
        pTemp=pTemp->pNext;

        (*ppTail)=pTemp;
        pTemp=(*ppTail)->pNext;
        pTemp->pNext=NULL;
        pTemp->pPrev=NULL;
        iDelData=pTemp->iData;
        (*ppTail)->pNext=*ppHead;
       (*ppHead)->pPrev=*ppTail;
        free(pTemp);
        pTemp=NULL;
        return iDelData;
}
int delete_at_position(struct node **ppHead , struct node **ppTail , int iPos)
{
	struct node *pTemp = NULL;
	 
	int iDelData=count_node(*ppHead,*ppTail);
	if(iPos<0 || iPos > iDelData)
	{
		printf("\n! Position is Invald !:-\n");
		return -1;
	}
	if(iPos == 1)
	{
		return delete_first(ppHead,ppTail);
	}
	if(iPos == iDelData)
	{
		return delete_last(ppHead,ppTail);
	}
	pTemp = *ppHead;
	iDelData = 1;
	while(iDelData < iPos)
	{	
		iDelData ++;
		pTemp = pTemp -> pNext;
	}
	pTemp -> pPrev -> pNext = pTemp -> pNext;
	pTemp -> pNext -> pPrev = pTemp -> pPrev;
	iDelData = pTemp -> iData;
	pTemp -> pNext = NULL;
	pTemp -> pPrev = NULL;
	free (pTemp);
	pTemp = NULL;
 
	return iDelData;
	
}
int count_node(struct node *pHead,struct node *pTail)
{
        int iCounter = 0;
        if(NULL == pHead)
        {
               	printf("! Your List is Empty...!:- ");
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
                printf("! Your List is Empty...! :-");
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
                printf("! Your List is Empty...! :- ");
                return ;
        }
        if(NULL == *ppHead1)
        {
                printf("! Your List is Empty...! :- ");
                *ppHead1 = *ppHead2;
                *ppTail1 = *ppTail2;
                *ppTail2 = *ppHead2 = NULL;
                     
                return ;
        }
         (*ppTail1) -> pNext = *ppHead2;
        (*ppHead2) -> pPrev=*ppTail1;
          *ppTail1 = *ppTail2;   
        (*ppTail1) -> pNext = *ppHead1;
        (*ppHead1) -> pPrev = *ppTail1;
        printf("\n ! Concatating of The Linked List is Successfully Done ! :-\n");
}  
void concat_at_position(struct node **ppHead1,struct node **ppTail1 ,struct node **ppHead2,struct node **ppTail2,int iPos)
{	
	struct node *pTemp = NULL;
	
	int iCounter;
	 iCounter=count_node(*ppHead1,*ppTail1);
	if(iPos <= 0 ||iPos > iCounter +1)
	{
		printf(" ! Position invalid ! :-");
		return ;
	}
	if(NULL == *ppHead2)
	{
		return ;
	}
	if(1 == iPos)
	{
		concat_list(ppHead2,ppTail2,ppHead1,ppTail1);
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
        pTemp -> pNext -> pPrev = *ppTail2;
        pTemp ->pNext = *ppHead2;
	(*ppHead2) -> pPrev = pTemp;
        *ppHead2 = *ppTail2 = NULL;
      printf("\n ! Concat The List is successfully Done....! :-\n");

} 

void reverse( struct node **ppHead , struct node **ppTail)
{
	
        struct node *pCurrent = *ppHead;
        struct node *Next = NULL;
	if(NULL == *ppHead)
	{
		printf("! Your List is Empty...! :- ");
		return;
	}
	do
	{
		Next = pCurrent -> pNext;
		pCurrent -> pNext = pCurrent -> pPrev;
		pCurrent -> pPrev = Next;
		pCurrent = Next;
	}
        while(pCurrent != *ppHead);
        *ppTail = pCurrent;
	*ppHead = (*ppTail) -> pNext;
         printf("  \nYour List is Reverse oder Display...:-\t ");
}

         
void display (struct node *pHead,struct node *pTail)
{
	if(NULL == pHead)
	{
			printf("! Your List is Empty...! :-");
			return ;
	}
        printf(" \n ! Your List is...! :-\t");      
	do
	{
		printf("<-|%d|-> ",pHead -> iData);
		pHead = pHead -> pNext;
	}while (pHead != pTail -> pNext);
}
