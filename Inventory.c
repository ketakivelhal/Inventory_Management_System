#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
//float SP=0,CP=0;
//int Q=0;
struct node 
{
	int itemcode,Qsold;
	char itemname[50];
	float SellingPrice,CostPrice,TCP,TSP,profit;
	int No_item;
	struct node *next;
};
struct node *start=NULL;
struct node *create(struct node *start)
{
	int i=1,code,quan,num;
	float sp,cp=0.0,cp1=0;
	char name[50];
	struct node *nn,*ptr;
	printf("\nEnter number of items to be added:");
	scanf("%d",&num);
	while(i<=num)
	{
		nn=(struct node *)malloc(sizeof(struct node));
		printf("Enter item name\n");
			scanf("%s",name);
			strcpy(nn->itemname,"");
			strcpy(nn->itemname,name);
			printf("Enter item code:\n");
			scanf("%d",&code);
			nn->itemcode=code;
			printf("Enter Quantity:\n");
			scanf("%d",&quan);
			nn->No_item=quan;
			printf("Enter Unit cost:\n");
			scanf("%f",&cp);
			nn->CostPrice=cp;
			printf("Enter Sale Price:\n");
			scanf("%f",&sp);
			nn->SellingPrice=sp;
			nn->TCP=nn->CostPrice*nn->No_item;
		if(start==NULL)
		{
			nn->next=NULL;
			start=nn;
			
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=nn;
			nn->next=NULL;
			
		}

		i++;
	}
	/*ptr=start;
	while(ptr!=NULL)
	{
		ptr->TCP=ptr->TCP+ptr->CostPrice*ptr->No_item;
		ptr=ptr->next;
	}
	CP=CP+cp1;*/
	return start;
}
struct node *add(struct node *start)
{
	int i=1,code,quan,num;
	float sp,cp=0.0,cp1=0;
	char name[50];
	struct node *nn,*ptr;
	printf("\nEnter number of items to be added:");
	scanf("%d",&num);
	while(i<=num)
	{	nn=(struct node *)malloc(sizeof(struct node));
		printf("Enter item name\n");
		scanf("%s",name);
		strcpy(nn->itemname,"");
		strcpy(nn->itemname,name);
		printf("Enter item code:\n");
		scanf("%d",&code);
		nn->itemcode=code;
		printf("Enter Quantity:\n");
		scanf("%d",&quan);
		nn->No_item=quan;
		printf("Enter Unit cost:\n");
		scanf("%f",&cp);
		nn->CostPrice=cp;
		printf("Enter Sale Price:\n");
		scanf("%f",&sp);
		nn->SellingPrice=sp;
		nn->TCP=nn->CostPrice*nn->No_item;
		ptr=start;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=nn;
		nn->next=NULL;
			i++;
	}
	/*ptr=start;
	while(ptr!=NULL)
	{
		ptr->TCP=ptr->TCP+ptr->CostPrice*ptr->No_item;
		ptr=ptr->next;
	}*/
	//CP=CP+cp1;
	return start;
}
struct node *search(struct node *start)
{
	int op,code,v=1,flag=0;
	char name[50];
	struct node *p;
	{
		
	};
	printf("Enter choice\n1.Search by name:\n2.Search by item code:\n" );
	scanf("%d",&op);
	switch(op)
	{
		case 1: printf("Enter item name: ");
				scanf("%s",name);
				p=start;
				while(p!=NULL)
				{
					v=strcmp(p->itemname,name);
					if(v==0)
					{
						printf("Item name:%s\nItem code:%d\nQuantity%d\nCost Price:%f\nSelling Price:%f\n",p->itemname,p->itemcode,p->No_item,p->CostPrice,p->SellingPrice);
						break;
					}
					p=p->next;
				}
				if((v>0)||(v<0))
					printf("item not found\n");
				break;
		case 2: printf("Enter item code: ");
				scanf("%d",&code);
				p=start;
				while(p!=NULL)
				{
					if(p->itemcode==code)
					{
						printf("Item name:%s\nItem code:%d\nQuantity%d\nCost Price:%f\nSelling Price:%f\n",p->itemname,p->itemcode,p->No_item,p->CostPrice,p->SellingPrice);
						flag=1;
						break;
					}
					p=p->next;
				}
				if(flag!=1)
					printf("item not found\n");
				break;
		default : printf("Invalid Choice\n");
	}
	return start;
}
struct node *delete(struct node *start)
{
	struct node *p,*pp;
	int v=1;
	char name[50];
	p=start;
	pp=start;
	printf("Enter item name to be deleted: ");
	scanf("%s",name);
	while(p!=NULL)
	{
		v=strcmp(p->itemname,name);
		if(v==0)
		{
			if(p==start)
			{
				start=start->next;
			}
			
			else
				{
					pp->next=p->next;
			        p->next=NULL;
			    }
			free(p);
			break;
		}
		pp=p;
		p=p->next;

  	}
  	if((v>0)||(v<0))
		printf("Item doesn't exist\n");
	return start;
}
struct node *edit(struct node*start)
{	int op,v=1,flag=0,choice,c1,c2,q,editpos=0,code;
	struct node *p;
	char name[50],name2[50];
	float sp,cp;
	printf("Enter choice\n1.Search by name:\n2.Search by item code:\n" );
	scanf("%d",&op);
	switch(op)
	{
		case 1: printf("Enter item name: ");
				scanf("%s",name);
				p=start;
				while(p!=NULL)
				{
					v=strcmp(p->itemname,name);
					if(v==0)
					{
						printf("Item found ");
						break;
					}
					p=p->next;
				}
				if((v>0)||(v<0))
					{
						printf("Item not found\n\n");
						editpos=1;
						
					}
					break;
				
		case 2: printf("Enter item code: ");
				scanf("%d",&code);
				p=start;
				while(p!=NULL)
				{
					if(p->itemcode==code)
					{
						printf("Item found");
						flag=1;
						break;
					}
					p=p->next;
				}
				if(flag!=1)
					{	
						printf("Item not found\n\n");
						editpos=1;
						
					}
					break;
		default : printf("Invalid Choice\n");
					editpos=1;

	}
	if(editpos==0)
	{
		printf("Choose one to edit:\n1.Item name\t2.Item code\t3.Quantity\t4.Unit Cost\t5.Sale Price\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: /*printf("Enter old name : ");
			scanf("%s",n1);
			while(p!=NULL)
			{
				v=strcmp(p->itemname,n1);
				if(v==0)
				{*/
					printf("Enter new name : ");
					scanf("%s",name2);
					strcpy(p->itemname,name2);
					//break; 
				/*}
				p=p->next;
			}
			if((v>0)||(v<0))
				printf("Item doesn't exist\n\n");*/
			break;
		case 2: /*printf("Enter code no. : ");
			scanf("%d",&c1);
			while(p!=NULL)
			{
				if(p->itemcode==c1)
				{*/
					printf("Enter new item code : ");
					scanf("%d",&c2);
					p->itemcode=c2;
					flag=1;
					break; 
				/*}
				p=p->next;
			}
			if(flag!=1)
				printf("Item doesn't exist\n\n");
			break;*/
		case 3:/* printf("Enter code no. : ");
			scanf("%d",&c1);
			while(p!=NULL)
			{
				if(p->itemcode==c1)
				{*/
					printf("Enter quantity : ");
					scanf("%d",&q);
					p->No_item=q;
					//flag=1;
					break; 
				/*}
				p=p->next;
			}
			if(flag!=1)
				printf("Item doesn't exist\n\n");
			break;*/
		case 4: p->TCP =0;/*printf("Enter code no. : ");
			scanf("%d",&c1);
			while(p!=NULL)
			{
				if(p->itemcode==c1)
				{*/
					printf("Enter Unit cost : ");
					scanf("%f",&cp);
					p->CostPrice=cp;
					p->TCP=p->CostPrice*p->No_item;
					//flag=1;
					break; 
				/*}
				p=p->next;
			}
			if(flag!=1)
				printf("Item doesn't exist\n\n");
			break;*/
		case 5: p->TSP=0;/*printf("Enter code no. : ");
			scanf("%d",&c1);
			while(p!=NULL)
			{
				if(p->itemcode==c1)
				{*/
					printf("Enter Sale price : ");
					scanf("%f",&sp);
					p->SellingPrice=sp;
					p->TSP=p->SellingPrice*p->Qsold;
					//flag=1;
					break; 
				/*}
				p=p->next;
			}
			if(flag!=1)
				printf("Item doesn't exist\n\n");
			break;*/
					
	}
	}
	return start;
}
struct node *sale_rec(struct node *start)
{
	struct node *p;
	char name[50];
	int v=1,op,Q,val;
	float sp=0,cp=0;
	p=start;
	while(val!=2)
	{printf("\nAdd an item to the sale order?\n1.Yes\n2.No\n");
		scanf("%d",&val);
		printf("Enter item name: ");
		scanf("%s",name);
	while(p!=NULL)
	{
		v=strcmp(p->itemname,name);
		if(v==0)
		{
			printf("Enter quantity :\n");
			scanf("%d",&Q);
			//Q=Q+q;
			sp=Q*p->SellingPrice;
			cp=Q*p->CostPrice;
			p->profit=sp-cp;
			p->No_item=p->No_item-Q;
			p->Qsold=p->Qsold+Q;
			break;
		}
		p=p->next;
	}
	if((v>0)||(v<0))
	{
		printf("item not found\n");	
	}
	/*if(flag!=1)	
	{
		//SP=SP+sp;
		//CP=CP+cp;
	//printf("SP=%f",SP);
	}*/
	printf("\nDo you want to purchase an item?\n1.Yes\n2.No\n");
	scanf("%d",&val);
	}
	return start;
}
struct node *report(struct node *start)
{
 	struct node *p;	
	float Grandtsp=0,Grandtcp=0,Grandprofit=0;
	p=start;
	while(p!=NULL)
	{
		Grandtcp=Grandtcp+p->TCP;
		Grandtsp=Grandtsp+p->TSP;
		Grandprofit=Grandprofit+p->profit;
	}
	printf("\nTotal Cost Price : %f\nTotal Sales Price : %f\nTotal profit: %f\n",Grandtcp,Grandtsp,Grandprofit);
	/*p=start;
	while(p!=NULL)
	{
		cp1=cp1+p->CostPrice*p->No_item;
		p=p->next;
	}
	//printf("cp1=%f",cp1);
	printf("Total Profit : %f\n",SP-CP);*/
	return start;
}
struct node *display(struct node *start)
{
	struct node *p;
	p=start;
	while(p!=NULL)
	{
		printf("%s\t\t%d\t\t%d\t\t%.3f\t\t%.3f\n",p->itemname,p->itemcode,p->No_item,p->CostPrice,p->SellingPrice);
		p=p->next;	
	}
	return start;
}

void main()
{
	int choice;
	do{
		printf("\t\tDEPARTMENTAL STORE\t\t\t\t\n");
		printf("MAIN MENU:\t\t\t\t\n1.Products Info\n2.Add an item to stock\n3.Delete record from store database\n4.Edit item record\n5.Search item record\n6.Display record of available products\n7.View Sales,Purchase and profit report\n8.Place sale order\n9.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("This store provides general items,edibles,fashion wear and appliances\n");
				break;	
			case 2:if(start==NULL)
				start=create(start);
				else
					start=add(start);
				break;
			case 3:start=delete(start);
					break;
			case 4:start=edit(start);
				break;
			case 5:start=search(start);
					break;
			case 6: printf("\n\t\t\t*******Inventory*******\t\t\t\t\t\n");
					printf("-----------------------------------------------------------------------------------------------------------\n");
					printf("Name\t\tCode\t\tQuantity\tCost Price\tSales Price\n");
					printf("-----------------------------------------------------------------------------------------------------------\n");
					start=display(start);
					break;
			case 7: start=report(start);
				break;
			case 8: start=sale_rec(start);
				break;
		}
	}while(choice!=9);
}