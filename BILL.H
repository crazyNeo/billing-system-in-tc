#include "dos.h"
#include "object.h"
#include "pro.h"
#ifndef BILL_H
#define BILL_H

// the following function displays the outline of the bill
// this function is called only once
// it is called when the window for bill is opened

void savebill();
void newbill();
struct  time t;
struct date d;

void tbldisp()
{

//declaration part

   int i,j,c;//counter variables
   int actcorn[4];//actual corners or the bill
//  clrscr();
   //displaying the table
   go_flag=0;
	clrscr();
//textmode(BW40);//setting text mode.
   //gotoxy(0,0);
   //cprintf("|");

   //initialixing the variable 'ii' of the textboxes
   //for(i=0;i<40;i++)
	//ii[i]=0;


   nbox=45;//no of boxes

   //setting the actual coordinate positions of the table
   actcorn[0]=4;
   actcorn[1]=6;
   actcorn[2]=70+4;
   actcorn[3]=15+6;

   //setting the relative corner positions of the table from (x1,y1) to (x2,y2)
   billcorn[0]=actcorn[0]*xunit;//x1
   billcorn[1]=actcorn[1]*yunit;//y1
   billcorn[2]=actcorn[2]*xunit;//x2
   billcorn[3]=actcorn[3]*yunit;//y2

   //setting the relative wd positions of the table columns
   for (i=0;i<xn;i++)
   {
	wd[i]*=xunit;
   }

   for (i=0;i<yn;i++)
   {
	hd[i]*=yunit;
   }

/*//   temp=(9.0/25.0*(float)wymax);//if this value is directily assigned to the billcorn array it gives 8 instead of 9
//   billcorn[1]=(int)temp;
   billcorn[2]=70/80.0*wxmax;
//   temp=24/25.0*wymax;  //if this value is directily assigned to the billcorn array it gives 23 instead of 24
//   billcorn[3]=(int)temp;
   for (i=0;i<4;i++)
   cprintf("  %d",billcorn[i]);
//   cprintf("  %f",temp);
*/

   //

   //printing the table
   table(billcorn[0],billcorn[1],billcorn[2],billcorn[3],wd,xn,hd,yn);
   billpos[0]=billcorn[0]+1*xunit;

   for (i=0;i<xn;i++)
	billpos[i+1]=billpos[i]+wd[i]+1*xunit;

   //gotoxy(11,10);
   gotoxy(billpos[0],billcorn[1]+1*yunit);
   cprintf("SN");
   //gotoxy(11+5+1,10);
   gotoxy(billpos[1],billcorn[1]+yunit);
   cprintf("Product ID");
   //gotoxy(11+5+1+10+1,10);
   gotoxy(billpos[2],billcorn[1]+yunit);
   cprintf("Product Name");
   //gotoxy(11+5+1+10+1+12+1,10);
   gotoxy(billpos[3],billcorn[1]+yunit);
   cprintf("Quantity");
   //gotoxy(11+5+1+10+1+12+1+8+1,10);
   gotoxy(billpos[4],billcorn[1]+yunit);
   cprintf("Price");
   //gotoxy(11+5+1+10+1+12+1+8+1+8+1,10);
   gotoxy(billpos[5],billcorn[1]+yunit);
   cprintf("Amount");


   //gotoxy(60,23);
   gotoxy(billpos[4],billcorn[1]+14*yunit);
   cprintf("TOTAL");


   gotoxy(5,5);
   getdate(&d);
   printf("Date : %d\\%d\\%d", d.da_mon, d.da_day, d.da_year);

   gotoxy(55,5);
  //_dos_gettime(&t);
  //printf("Time: %2d:%02d:%02d.%02d\n", t.hour, t.minute,t.second, t.hsecond);
	gettime(&t);
	printf("Time : %2d:%02d:%02d",
	t.ti_hour, t.ti_min, t.ti_sec);

   gotoxy(55,25);
   //cprintf("|");

   //initializing the struct object flags.
   for (i=0;i<10;i++)
	for (j=0;j<4;j++)
		bill[i].flag[j]=0;

   //positions for invisible boxes(no borders in the boxes) inside the tables
   c=0;
   for (i=0;i<10;i++)
	for(j=0;j<4;j++)
	{
		pos[c].x=billpos[j+1];
		pos[c].y=billcorn[1]+1+(i+2)*yunit;//billcorn[1]=y1
		pos[c].wd=wd[j+1];
		c++;
	}
   //testing
   gotoxy(pos[0].x-5-1,pos[0].y);
   cprintf("1");
   //gotoxy(2,1);
   //cprintf("%d,%d,%d",pos[1].x,pos[1].y,pos[1].wd);

   //initializing ic and mc
   for (i=0;i<40;i++)
   {
	ic[i]=0;
	mc[i]=0;
   }
   printflag=0;
   //buttons
   tbox(pos[40].x=5,pos[40].y=23,pos[40].wd=10);
   gotoxy(pos[40].x,pos[40].y);
   printf("Print Bill");
   tbox(pos[41].x=20,pos[41].y=23,pos[41].wd=10);
   gotoxy(pos[41].x,pos[41].y);
   printf("save bill");
   tbox(pos[42].x=35,pos[42].y=23,pos[42].wd=15);
   gotoxy(pos[42].x,pos[42].y);
   printf("print and save");
   tbox(pos[43].x=55,pos[43].y=23,pos[43].wd=7);
   gotoxy(pos[43].x,pos[43].y);
   printf("New");
   tbox(pos[44].x=67,pos[44].y=23,pos[44].wd=10);
   gotoxy(pos[44].x,pos[44].y);
   printf("Main Menu");


   //fp=fopen("file.txt","r");
   cur=0;
   gotoxy(pos[0].x,pos[0].y);

}

//detectin click in the bill from mouse

int billmain(int key)
{

  int asc=key%256;//store th asc input by the user
  int i,j,c;//counter variables
  struct Position totpos[10];//tot position
			     //1*10struct array storeing position

  struct Position crps;//store posof current cursor;


//   if ((isalnum(key & 0xFF))||asc==8||asc==32)
//   {
//	printf("'%c'\n", key);
//	  gotoxy(pos[cur].x+4,pos[cur].y);
//	  cprintf(":");
//  TOTAL=0;//total of the amount in the bill
	  //gotoxy(3,3);
	  //cprintf("%d",cur);
    if (cur>maxcur) maxcur=cur;
    if (0<=cur && cur<40)
   {
    swcase:
    switch (cur%4)
    {
      case 0:
	{
	  TBDISP;
	  cnvts (&bill[cur/4].pdid,asc,ic[cur],mc[cur]); //converts typed key to string and stores in pd id
	  if (read_flag.fil==1)
	  {
		struct bill2 item;
		  strcpy(item.id,bill[cur/4].pdid);
		  if (searchid (&item))
		  {
			strcpy(bill[cur/4].pdnm,item.nm);
			bill[cur/04].prce=item.pr;
			gotoxy(12,2);
			//printf("found");
		  }
		  else
		  {
			strcpy(bill[cur/4].pdnm,"notfound");
			bill[cur/4].prce=0;
		  }
		  if (read_flag.name==1)
		  {
			bill[cur/4].flag[1]=1;
			gotoxy(pos[cur+1].x,pos[cur+1].y);
			printf("            ");
			gotoxy(pos[cur+1].x,pos[cur+1].y);
			printf("%s",bill[cur/4].pdnm);
		  }
		  if (read_flag.price==1)
		  {
			bill[cur/4].flag[3]=1;
			gotoxy(pos[cur+3].x,pos[cur].y);
			printf("%.2f",bill[cur/4].prce);
		  }
	  }
	  AMOUNT;//calculate amount
	  break;
	}
      case 1:
	{
	  if (read_flag.name==1)
	  {
		/*//AMOUNT;//calculate amount
		cur++;
		gotoxy(pos[cur].x,pos[cur].y);
		goto swcase;
		*/
	  }
	  else
	  {
		TBDISP;
		cnvts (&bill[cur/4].pdnm,asc,ic[cur],mc[cur]); //converts typed key to string and stores in pd nm
		AMOUNT;//calculate amount
	  }
	  break;
	}
      case 2:
	{
	  //static char[9];
	  TBDISP;//putting invisible boxes(no borders in the boxes) inside the tables
	  //converts the typed keys first to string
	  //and stores in sqty
	  //then converts to int and stroes in qty
	  bill[cur/4].qty=cnvti (&bill[cur/4].sqty,asc,ic[cur],mc[cur]);
	  if (read_flag.st==1)
	  {
		struct bill2 item;
		  strcpy(item.id,bill[cur/4].pdid);
		  if (searchid (&item))
		  {
			strcpy(bill[cur/4].pdnm,item.nm);
			gotoxy(pos[cur].x+mc[cur],pos[cur].y);
			printf(" (/%d)",item.st);
			if (bill[cur/4].qty>item.st)
			{
				bill[cur/4].qty=item.st;
				itos(item.st,bill[cur/4].sqty,0);
				gotoxy(pos[cur].x,pos[cur].y);
				ic[cur]--;
				mc[cur]--;
				printf("%s (/%d) ",bill[cur/4].sqty,item.st);
			}
			bill[cur/4].st=item.st;
		  }
	  }

	  AMOUNT;//calculate amount
	  break;
	}
      case 3:
	{
	  //converts the typed keys first to string
	  //and stores in sprce
	  //then converts to int and stroes in prce
	  if (read_flag.price==1)
	  {
		/*//AMOUNT;//calculate amount
		cur++;
		gotoxy(pos[cur].x,pos[cur].y);
		goto swcase;
		*/
	  }
	  else
	  {
		TBDISP;//putting invisible boxes(no borders in the boxes) inside the tables
		bill[cur/4].prce=cnvtf (&bill[cur/4].sprce,asc,ic[cur],mc[cur]);
		AMOUNT;//calculate amount
	  }
	  break;
	}

      default:
      {
	//gotoxy(10,15);
	//cprintf("%d",cur);
      }
    }
   }
   else
   switch (cur)
   {
	case 40:
		gotoxy(20,33);
		if (asc==13  || go_flag==1)
		{	textcolor(RED);
			printf("\n\nprinting");
			printbill();
			textcolor(WHITE);
		}
		break;
	case 41:
		gotoxy(20,33);
		if (asc==13  || go_flag==1)
		{	textcolor(RED);
			printf("\n\nsaving");
			savebill();
			textcolor(WHITE);
		}
		break;
	case 42:
		gotoxy(20,33);
		if (asc==13  || go_flag==1)
		{	textcolor(RED);
			printf("\n\nprinting");
			printbill();
			savebill();
			textcolor(WHITE);
		}
		break;
	case 43:
		if (asc==13  || go_flag==1)
		{	newbill();
			textcolor(WHITE);
		}
		break;
	case 44:
		curnt_fn=menu_cur;
		  menu();
		  break;

   }
   if (go_flag==1)
	go_flag=0;
//  }
//   else
//   {
      //printf("%#02x\n", key);

      if ((asc==9) || (asc ==13) || (key==0x5000))
      {
	cur++;
	if ((
		((read_flag.name==1 && cur%4==1) ||
		(read_flag.price==1 && cur%4==3))
	   ) && (cur<40)) cur++;
      }
      else if (key==0x4800 || key==0xf00)
      {
	cur--;
	if ((read_flag.name==1 && cur%4==1) ||
       (read_flag.price==1 && cur%4==3)) cur--;
      }
      else
      {

      }
      if (cur==nbox) cur=0;
      else if(cur==-1) cur=nbox-1;
      gotoxy(pos[cur].x+mc[cur],pos[cur].y);

//   }

 /*  for(i=0;i<10;i++)
   {
	printf("\n%dPr ID ->%s",i,bill[i].pdid);
	printf("\n%dpr name ->%s",i,bill[i].pdnm);
   }    */
   return (key);
}

void newbill()
{
	tbldisp();
}

void savebill()
{
	char filnm[10];
	char dir[10];
	char str[5];
	char path[25];
	int i;
	fp=fopen("dir.txt","r");
	fscanf(fp,"%s",dir);
	fcloseall();
//	strcpy(dir,"c:\\bill10");
	strcpy(path,dir);
//	strcat(path,str);
	strcat(path,"\\\0");

//	strcpy(filnm,str);
	itos(d.da_year,str,0);
	str[0]=str[2];
	str[1]=str[3];
	str[2]='\0';
	strcpy(filnm,str);

	itos(d.da_mon,str,0);
	strcat(filnm,str);
	itos(d.da_day,str,0);
	strcat(filnm,str);
	itos(t.ti_hour,str,0);
	strcat(filnm,str);
	itos(t.ti_min,str,0);
	strcat(filnm,str);
	itos(t.ti_sec,str,0);
	strcat(filnm,str);
	strcat(filnm,".txt");
	strcat(path,filnm);

	fp=fopen(path,"w");

	if (printflag==1)
		fprintf(fp,"\n\t\t\treprinted");
fprintf(fp,"\n\t\t\tbilling software");
	fprintf(fp,"\n\t+-------+--------------+---------------+----------+-------------+---------------+");
	fprintf(fp,"\n\t|SN\t|ProductID\t|Name      \t|Price\t|Quantity\t|Amount\t\t|");
	fprintf(fp,"\n\t+-------+--------------+---------------+----------+-------------+---------------+");
	for (i=0;i<10;i++)
	{

		int l=strlen(bill[i].pdid);
		int j;
		for (j=l;j<10;j++)
		{
			bill[i].pdid[j]=' ';
		}
		bill[i].pdid[10]='\0';
		l=strlen(bill[i].pdnm);
		for (j=l;j<10;j++)
		{
			bill[i].pdnm[j]=' ';
		}

		bill[i].pdnm[10]='\0';
		fprintf(fp,"\n\t|%d\t|%s\t|%s\t|%d\t|%f\t|%f\t|",
		i+1,bill[i].pdid,bill[i].pdnm,bill[i].qty,bill[i].prce,bill[i].amount);
	}
	fprintf(fp,"\n\t+-------+--------------+---------------+----------+-------------+---------------+");
	fprintf(fp,"\n\t|                                                 |TOTAL        =%f\t|",TOTAL);
	//fprintf(fp,"\n\t\t\tTotal : %f",TOTAL);
	fprintf(fp,"\n\t+-------------------------------------------------------------------------------+");


	//fprintf(stdprn,"\n\t\t\tbilling software");
	//fprintf(stdprn,"\n\t+-------+--------------+---------------+----------+-------------+---------------+");
	//fprintf(stdprn,"\n\t|SN\t|ProductID\t|Name      \t|Price\t|Quantity\t|Amount\t\t|");
	//fprintf(stdprn,"\n\t+-------+--------------+---------------+----------+-------------+---------------+");
	for (i=0;i<10;i++)
	{
	 //	fprintf(stdprn,"\n\t|%d\t|%s\t|%s\t|%d\t|%f\t|%f\t|",
//		i+1,bill[i].pdid,bill[i].pdnm,bill[i].qty,bill[i].prce,bill[i].amount);
	}
	//fprintf(stdprn,"\n\t+-------+--------------+---------------+----------+-------------+---------------+");
	//fprintf(stdprn,"\n\t|                                                 |TOTAL        =%f\t|",TOTAL);
	//fprintf(fp,"\n\t\t\tTotal : %f",TOTAL);
	//fprintf(stdprn,"\n\t+-------------------------------------------------------------------------------+");

	printf("printed successfully");

	fcloseall();
}

void printbill()
{
	char filnm[10]="bill.txt";
	int i;
	if (printflag==1)
		fprintf(stdprn,"\n\t\t\treprinted");
	fprintf(stdprn,"\n\t\t\tbilling software");
	fprintf(stdprn,"\n\t+-------+--------------+---------------+----------+-------------+---------------+");
	fprintf(stdprn,"\n\t|SN\t|ProductID\t|Name      \t|Price\t|Quantity\t|Amount\t\t|");
	fprintf(stdprn,"\n\t+-------+--------------+---------------+----------+-------------+---------------+");
	for (i=0;i<10;i++)
	{

		int l=strlen(bill[i].pdid);
		int j;
		for (j=l;j<10;j++)
		{
			bill[i].pdid[j]=' ';
		}
		bill[i].pdid[10]='\0';
		l=strlen(bill[i].pdnm);
		for (j=l;j<10;j++)
		{
			bill[i].pdnm[j]=' ';
		}

		bill[i].pdnm[10]='\0';
		if (read_flag.st==1)
		{
		if (printflag==0)
			printflag=1;
		updat_stok(bill[i].pdid,bill[i].st-bill[i].qty);
		}
		fprintf(stdprn,"\n\t|%d\t|%s\t|%s\t|%d\t|%f\t|%f\t|",
		i+1,bill[i].pdid,bill[i].pdnm,bill[i].qty,bill[i].prce,bill[i].amount);
	}
	fprintf(stdprn,"\n\t+-------+--------------+---------------+----------+-------------+---------------+");
	fprintf(stdprn,"\n\t|                                                 |TOTAL        =%f\t|",TOTAL);
	fprintf(stdprn,"\n\t+-------------------------------------------------------------------------------+");

	printf("printed successfully");
}

#endif



#ifndef MSGBOX_H
#define MSGBOX_H

/*
void cls(int x1,y1,x2,y2)
{
	int i,j;
	for (i=y1;i<y2;i++)
		for (j=x1;j<x2;j++)
		{	gotoxy(j,i);
			printf(" ");
		}
}

int msg(char *a);
{
	char buffer[8096];
	gettext(1,1,80,50,buffer);
	cls(20,10,60,20);
	gotoxy(22,12);
	printf("%a");
	tmpcurnt_fn=curnt_fn;
	curnt_fn=msg_inp;
}
*/
#endif
