#include<stdio.h>
#include<stdlib.h>
struct Node{
	char  digit;
	struct Node *next;
};
struct Node *head;
struct Node *subhead;
int noofdigits;
void makelist(char digi){
	struct Node *temp;
	temp = new struct Node;
	temp->digit=digi;
	temp->next=head;
	head=temp;
}
void listmaker()
{
	char digi;
	scanf("%c",&digi);
	struct Node *temp;
	head=NULL;
	temp = new struct Node;
	temp->digit=digi;
	temp->next=head;
	head=temp;
	scanf("%c",&digi);
	noofdigits=1;
	while(digi!='\n')
	{
		noofdigits=noofdigits+1;
		makelist(digi);
		scanf("%c",&digi);
	}
	//printf("yes");
}
void add(struct Node *head1,struct Node *head2)
{
	int carry=0;
	head=NULL;
	struct Node *temp;
	temp=new struct Node;
	while(head1!=NULL && head2!=NULL){
		temp=new struct Node;
		temp->digit=(((((head1->digit)-48) + ((head2->digit)-48))+carry)%10)+48;
		carry=((((head1->digit)-48) + ((head2->digit)-48))+carry)/10;
		temp->next=head;
		head=temp;
		head1=head1->next;
		head2=head2->next;
	}
	if(head1!=NULL)
	{
		while(head1!=NULL)
		{
			temp=new struct Node;
			temp->digit=((((head1->digit)-48) +carry)%10)+48;
			carry=(((head1->digit)-48) +carry)/10;
			temp->next=head;
			head=temp;
			head1=head1->next;
		}}
	if(head2!=NULL)
	{
		while(head2!=NULL)
		{
			temp=new struct Node;
			temp->digit=((((head2->digit)-48) +carry)%10)+48;
			carry=(((head2->digit)-48) +carry)/10;
			temp->next=head;
			head=temp;
			head2=head2->next;
		}}
	if(carry!=0)
	{
		temp=new struct Node;
		temp->digit=carry+48;
		temp->next=head;
		head=temp;
	}
}
int compare(struct Node *head1,struct Node *head2)
{
	int i=2,flag=1;
	struct Node *temphead1,*temphead2;
	temphead1=head1;
	temphead2=head2;
	while(i>0)
	{
		head1=head1->next;
		head2=head2->next;
		if(head1==NULL && head2==NULL)
		{
			flag=1;
			break;
		}
		if(head1==NULL)
		{
			return 0;
			break;
		}
		if(head2==NULL)
		{
			return 1;
			break;
		}
	}
	while(flag)
	{
		if((temphead1->digit)>(temphead2->digit))
		{
			return 1;
		}
		if((temphead1->digit)<(temphead2->digit))
		{
			return 0;
		}
		if((temphead1->digit)==(temphead2->digit))
		{
			temphead1=temphead1->next;
			temphead2=temphead2->next;
		}
		if((temphead1==NULL) &&(temphead2==NULL))
		{
			return 1;
			break;
		}
	}
}
void reverse(struct Node *temphead1)
{
	struct Node *previous,*nextadd,*current;
	current=temphead1;
	previous=NULL;
	nextadd=NULL;
	while(current!=NULL)
	{
		nextadd=current->next;
		current->next=previous;
		previous=current;
		current=nextadd;
	}
	temphead1=previous;
	
	while(temphead1!=NULL)
	{
		if(temphead1->digit=='`')
	printf("0");
else{
	printf("%c",temphead1->digit);}
		temphead1=temphead1->next;
	}
}
void substracter(struct Node *head1,struct Node *head2,int noofdigitsa,int noofdigitsb)           
{
	int carry=0;
	struct Node *temphead1;
	temphead1=head1;
	while(head2!=NULL)
	{
		if(((head1->digit-48)-carry)>=(head2->digit-48))
		{
			head1->digit=(head1->digit-head2->digit)+48;
			carry=0;
		}
		else{
			head1->digit=(((head1->digit-48)+10)-(head2->digit-48))+48;
			carry=1;
		}
		head1=head1->next;
		head2=head2->next;
	}
	while(carry==1)
	{
		if(((head1->digit-48)-carry)>=0)
		{
			head1->digit=(head1->digit-1)+48;
			carry=0;
		}
		else{
			head1->digit=(((head1->digit-48)+10)-1)+48;
			carry=1;
		}
		head1=head1->next;
	}
	reverse(temphead1);
}
int main()                                                     //do the 9,s compliment the proper way noyhing left
{
	struct Node *head1,*head2,*transverse;
	int noofdigitsa,noofdigitsb,i;
	listmaker();
	head1=head;
	head=NULL;
	noofdigitsa=noofdigits;
	listmaker();
	noofdigitsb=noofdigits;
	head2=head;
	head=NULL;
//	add(head1,head2);
	transverse=head;
	while(transverse!=NULL)
	{
		printf("%c",transverse->digit);
		transverse=transverse->next;
	}
	//printf("\n%d %d",noofdigitsa,noofdigitsb);
	i=compare(head1,head2);
	if(i==1){
		substracter(head1,head2,noofdigitsa,noofdigitsb);
	}
	else{
		printf("-");
		substracter(head2,head1,noofdigitsb,noofdigitsa);
	}
	return 0;
}

