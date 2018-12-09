#include<stdio.h>
#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
char stack[20][20];
int top=-1,ch=48;
void border()
{
  int x,y;
  x=getmaxx();
  y=getmaxy();
  setcolor(RED);
  rectangle(0,0,x,y);
  rectangle(5,5,x-5,y-5);
  setcolor(15);
}
void print()
{
  int i,j;
  char s[10];
  border();
  setcolor(BLUE);
  line(425,100,425,400);
  line(425,400,575,400);
  line(575,400,575,100);
  j=375;
  for(i=0;i<=top;i++)
  {
    outtextxy(500,j,stack[i]);
    line(425,j-25,575,j-25);
    j=j-50;
  }
  sprintf(s,"%d",top);
  outtextxy(350,j+50,s);
  outtextxy(380,j+50,"-->");
  setcolor(15);
}

void title()
{
   outtextxy(150,180,"stack size: 5");
  outtextxy(150,210,"1.Push");
    outtextxy(150,240,"2.Pop");
    outtextxy(150,270,"3.Peek");
    outtextxy(150,300,"4.exit");
    outtextxy(150,330,"enter your choice:");
    print();
}
void push(char s[])
{
  int i,j;

    outtextxy(500,50,s);
    if(top==-1)
    {
      j=375;
    }
    else if(top==0)
    {
      j=325;
    }
    else if(top==1)
    {
      j=275;
    }
    else if(top==2)
    {
      j=225;
    }
    else
    {
      j=175;
    }
    cleardevice();
    for(i=50;i<=j;)
    {
	setcolor(WHITE);
      outtextxy(500,i,s);
      print();
      delay(10);
      setcolor(BLACK);
      outtextxy(500,i,s);
      i=i+1;
    }
    line(425,j-25,575,j-25);
    ++top;
    strcpy(stack[top],s);

}
void pop()
{
  int i,j;
  char s[10];
  if(top==-1)
  {
    cleardevice();
    outtextxy(300,50,"stack is empty");
    print();
    getch();
  }
  else
  {
    strcpy(s,stack[top]);
    if(top==0)
    {
      j=375;
    }
    else if(top==1)
    {
      j=325;
    }
    else if(top==2)
    {
      j=275;
    }
    else if(top==3)
    {
      j=225;
    }
    else
    {
      j=175;
    }
    top--;
    for(i=j;i>=50;i--)
    {
	setcolor(WHITE);
      outtextxy(500,i,s);
      print();
      delay(10);
      setcolor(BLACK);
      outtextxy(500,i,s);
      i=i-1;
    }
  }
}
void peek()
{
  if(top==-1)
  {
    outtextxy(300,50,"stack is empty");
  }
  else
  {
    outtextxy(300,50,"Top most element:");
    outtextxy(500,50,stack[top]);
  }
}
void check()
{
    int i;
    char val,s[10];
    cleardevice();
    print();
    switch(ch)
    {
      case 49:
	if(top==4)
	{
	 cleardevice();
	 outtextxy(200,50,"sorry stack is full");
	 print();
	 getch();
	}
	else
	{
		outtextxy(10,50,"enter value(press spacebar after entering):");
		i=0;
		while(1)
		{
		 val=getch();
		 if(val==' ')
		 {
			 s[i]='\0';
			  break;
		 }
		 s[i++]=val;
		}
		push(s);
	}
	break;
    case 50:
	pop();
	break;
    case 51:
	peek();
	break;
    case 52:
	 cleardevice();
	 border();
	 setcolor(YELLOW);
	    settextstyle(1,HORIZ_DIR,5);
	    outtextxy(200,10,"APPLICATIONS");
	    delay(1000);
	    setcolor(MAGENTA);
	    settextstyle(1,HORIZ_DIR,3);
	    outtextxy(20,100,"-> Reversing a list");
	    delay(1000);
	    outtextxy(20,150,"-> Infix to Postfix conversion");
	    delay(1000);
	    outtextxy(20,200,"-> Towers of Hanoi");
	    delay(3000);
	    cleardevice();
	    setbkcolor(15);
	    setcolor(GREEN);
	    settextstyle(4,HORIZ_DIR,8);
	    outtextxy(70,200,"THANK YOU");
	    getch();
	clrscr();
	closegraph();
	exit(0);
	break;
    }
}
int main()
{
int i,j;
char s[10],val;
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\turboc3\\BGI");
	border();
	setcolor(YELLOW);
	settextstyle(1,HORIZ_DIR,5);
	outtextxy(250,10,"STACK");
	setcolor(WHITE);
	settextstyle(1,HORIZ_DIR,3);
	setcolor(CYAN);
	outtextxy(20,100,"DEFINITION : ");
	setcolor(MAGENTA);
	settextstyle(1,HORIZ_DIR,2);
	outtextxy(40,130,"STACK is a LINEAR DATA STRUCTURE in which insertion ");
	outtextxy(40,160,"and deletion are done at SAME END. ");
	delay(1000);
	outtextxy(40,200,"-> Stack follows the principle of FILO or LIFO ");
	delay(1000);
	outtextxy(40,230,"-> FILO-First In Last Out");
	delay(1000);
	outtextxy(40,260,"-> LIFO-Last In First Out");
	delay(2000);
	cleardevice();
	border();
	settextstyle(1,HORIZ_DIR,3);
	setcolor(CYAN);
	outtextxy(20,100,"OPERATIONS OF STACK :- ");
	outtextxy(20,130,"1.PUSH");
	setcolor(MAGENTA);
	settextstyle(1,HORIZ_DIR,2);
	outtextxy(50,160,"Inserting an element into the stack");
	delay(1000);
	settextstyle(1,HORIZ_DIR,3);
	setcolor(CYAN);
	outtextxy(20,190,"2.POP");
	setcolor(MAGENTA);
	settextstyle(1,HORIZ_DIR,2);
	outtextxy(50,220,"Deleting an element from the stack");
	delay(1000);
	settextstyle(1,HORIZ_DIR,3);
	setcolor(CYAN);
	outtextxy(20,250,"3.PEEK");
	setcolor(MAGENTA);
	settextstyle(1,HORIZ_DIR,2);
	outtextxy(50,280,"Representing the top of the stack");
	delay(2000);
	settextstyle(0,HORIZ_DIR,0);
	cleardevice();
settextstyle(1,HORIZ_DIR,2);
while(1)
{
  if(ch==48)
  {
    title();
    border();
    ch=getch();
    check();
  }
  else if(ch==49)
  {
    j=(375-(50*top));
    for(i=50;i<=j;)
    {
      title();
      print();
      outtextxy(500,i,stack[top]);
      delay(75);
      if(kbhit())
      {
	ch=getch();
	check();
	break;
      }
      setcolor(0);
      outtextxy(500,i,stack[top]);
      setcolor(15);
      i=i+5;
    }
  }
    else if(ch==50)
  {
    j=(375-(50*(top+1)));
    for(i=j;i>=50;)
    {
      title();
      print();
      outtextxy(500,i,stack[top+1]);
      delay(75);
      if(kbhit())
      {
	ch=getch();
	check();
	break;
      }
       setcolor(0);
      outtextxy(500,i,stack[top+1]);
      setcolor(15);
      i=i-5;
    }
  }
  else
  {
    title();
    print();
    peek();
    ch=getch();
    check();
  }
  cleardevice();
}
}