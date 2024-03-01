#include<stdio.h>
#include<stdlib.h> 
#define capacity 20 
void order_food(int order); int serve_food(); 
void display(); 
int restaurant[capacity]; 
int order_no=0; 
int front=-1,rear=-1; 
int isFull()
{
if((front==rear+1)||(front==0&&rear==capacity-1))
{
return 1;
}
return 0;
} 
int isEmpty()
{
if(front==-1)
{
return 1;
}
return 0;
}

void main()
{
int choice=0;  	while(choice!=9) {
printf("\n\n1.Order Food\n2.Serve Food\n3.Display
orders\n4.exit");
printf("\nEnter your choice:");  	 	scanf("%d",&choice);  	 	
switch(choice)
{
case 1:
order_food(++order_no);
break;  	 	 	
case 2:  	 	 	 	serve_food();
break;  	 	 	
case 3:  	 	 	 	display();  	 	 	 	break;                                      
case 4:
printf(“exiting”);                                                
break;  	 	 	
default:
printf("\nPlease Enter a valid choice:");
break;
}
}
}
void order_food(int order)
{
if(isFull())
{
printf("\nRestaurant is full. Please wait for sometime.");
}
else
{
if(front==-1)
{
front=0;
}
rear=(rear+1)%capacity;  	 	
restaurant[rear]=order;
printf("\nOrder placed with order number %d",restaurant[rear]);
}
} 
int serve_food()
{
int serve_order;  	if(isEmpty()){  	 	printf("\nNO order is placed.");  	 	return (-1);
}
else
{
serve_order=restaurant[front];  	 	
if(front==rear)
{
front=-1;  	 	 	
rear=-1;
}
else
{
front=(front+1)%capacity;
}
printf("\nServed food for order no %d",serve_order);
}
} 
void display()
{
int i;  	
if(isEmpty())
{
printf("\nNo order is placed.");
}
 else
{
for(i=front;i!=rear;i=(i+1)%capacity)
{
printf("\nOrder no %d\n",restaurant[i]);
}
printf("\nFront -> %d",front);  	 	
printf("\nRear -> %d\n",rear);  	 	
printf("\nRestaurant Orders -> %d",rear-front);

}
}
