#include<iostream>
using namespace std;

class CNode
{	
	private:
	 		int iData;
			CNode *pNext;
	
	public:

		CNode(int iNo)
			{
				iData = iNo;
				pNext = NULL;
			}
		~CNode()
			{
				iData = 0;
				if(pNext !=NULL )
				{
					delete pNext;
					pNext = NULL;
				}
				cout<<"In Node Destructor"<<endl;
			}
	friend class Clist;
};

class CList
{
	
		CNode *pFirst;
	public:
		
		 CList()
		{
			pFirst=NULL;
			
		}
		~CList()
		{
			if(pFirst !=NULL)
			{
				delete pFirst;
				pFirst=NULL;
			}
			cout<<"in List destructor"<<endl;
		 }

		void push(int iNo)
	   {	
			CNode *pTemp=NULL;
			CNode *pNewNode=NULL;
					
			pNewNode =new CNode(iNo);		
		
		
				if(NULL== pNewNode)
			
				{
					cout<<"Memory allocation faild"<<endl;
						return ;				
			   }

				pTemp=pFirst;
       			if(NULL == pFirst)
				{
					
				     pFirst=pNewNode;
					return ;
				}
				while(pTemp->pNext !=NULL)
				pTemp=pTemp->pNext;
				pTemp->pNext==pNewNode;
		}
		/*
	  }	

	int pop()
	{	
	
		CNode *pTemp=pFirst;
		int iDelData;
		if(NULL==pFirst)
		{	
			cout<<"Stack is empty"<<endl;
			return ;
		}
		if(pTemp->pNext==NULL)
		pTemp=pFirst;
		pFirst=pTemp->pNext;
		pTemp->pNext=NULL;
		iData=pTemp->iData;
		delete pTemp;
		return iData;
	}	 	
*/
	void display()
    { 
		int iData;
		CNode *pTemp=pFirst;
		if(NULL==pFirst)
		{
			cout<<"List list is empty"<<endl;
						return ;
		}
		cout<<endl<<"List is:"<<endl;
		while(pFirst)		
		{
			cout<<"|"<<pFirst->iData<<"->"<<endl;
			
			pFirst = pFirst->pNext;
		}
	}
};

int main()
{
	CList obj;
	
	obj.push(10);
	//obj.pop();
	obj.display();
}
