/*#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "table2.h"
#include "object.h"
#include "bill5.h"
#include "file4.h"
*/

#include "pro.h"

#ifndef MENU
#define MENU

/*
//global variables
   int cur=0;//position of the cursor
   struct Position pos[5];//position of each option
   int nbox=5;
*/

void menu()
{

	//values for the table
	int xn=1;
	int yn=1;
	int wd[1]={3};
	int hd[1]={1};
	int menucorn[4]={5,5,50,20};
	int mpos_x,mpos_y;

	int i,j,c;//counter variables

	cur=0;//position of the cursor
	nbox=5;
	go_flag=0;
	no_op=5;

	textbackground(BLUE);
	clrscr();
	//cprintf("\n We r visitin MENU");

	//printingg the table
	table(menucorn[0],menucorn[1],menucorn[2],menucorn[3],wd,xn,hd,yn);

	//taking average of the starting and end columns
	//subtracting strlen/2 bcoz center lies 2 char after starting of
	//word MENU
	mpos_x= ((menucorn[0]+wd[0]+2)+(menucorn[2]))/2.0-strlen("MENU")/2;

	mpos_y=menucorn[1]+1;//1*yunit;
	gotoxy(mpos_x,mpos_y);
	cprintf("MENU");

	//other options
	strcpy(opt[0].titl,"BILLING PAGE\0");
	strcpy(opt[1].titl,"ADMINISTRATIVE\0");
	strcpy(opt[2].titl,"VIEW ITEMS\0");
	strcpy(opt[3].titl,"HELP\0");
	strcpy(opt[4].titl,"EXIT\0");
	for (i=0;i<no_op;i++)
	{
		int l=strlen(opt[i].titl);
		for (j=l;j<20;j++)
		{
			opt[i].titl[j]=' ';
		}
		opt[i].titl[20]='\0';
	}

	//displaying the options
	for(i=0;i<no_op;i++)
	{
		pos[i].x=menucorn[0]+6;
		pos[i].y=menucorn[1]+3+i;
		pos[i].wd=max_len;
		gotoxy( (menucorn[0]+2),menucorn[1]+3+i);
		cprintf("%d",i+1);
		gotoxy(pos[i].x,pos[i].y);
		cprintf("%s",opt[i].titl);
	}
	//delay(600);
	/*for(i=0;i<no_op;i++)
	//pointing til in menop sturct

	//processing othe options
	{
		int l=strlen(opt[i].titl);
		opt[i]->tit=&opt[i].titl;
		c=max_len/2;//here c is the centre of the word option
		for(j=max_len;j>c+l/2;j--)
			opt[i]->tit[j]=" ";//filling array with space
		for(j=c-l/2-1;j>=0;j--)
		{
			opt[i]->tit[j+l]=opt[i]->tit[j];
			opt[i]->tit[j]=" ";//filling array with space
		}
		opt[i]->tit[max_len+1]="\0";
	}
	for (i=0;i<no_op;i++)
	{
		gotoxy( (menucorn[0]+wd[0]+2),menucorn[1]+1+i);
		cprintf("%s",opt[i].titl);
	}

	//placing other options
	*/
	//gotoxy(1,1);
	//cprintf("%d",nbox);
}


//event hangling part
void menu_cur(int key)
{
   int asc=key%256;//store th asc input by the user
   textbackground(BLUE);
   gotoxy(pos[cur].x,pos[cur].y);
   cprintf(opt[cur].titl);


   //cursor handling part
       if ((asc==9) || (key==0x5000)) cur++;
      else if (key==0x4800 || key==0Xf00) cur--;
      else
      {

      }
      if (cur==nbox) cur=0;
      else if(cur==-1) cur=nbox-1;
   //gotoxy(4,15);
      //cprintf("%d               ",cur);

//checking the key board strokes for the choosing of the options by
//typing the number

//we put a go_flag ever time a menu is choosen by pressing the
//number key or enter key
   if (47<asc && asc<58)
   {
	go_flag=1;
	cur=asc-49;
   }
   else if( asc==13)
	go_flag=1;
   textbackground(RED);
   gotoxy(pos[cur].x,pos[cur].y);
   cprintf(opt[cur].titl);


   //if go_flag is ie the user has chooser an option
   if (go_flag==1)
   {
	go_flag=0;//to detect next time
	//the curor pos whe enter was pressed
	//or the number that was pressed
	switch (cur+1)
    {
      case 1:
	{
//	  key=0x3c00;
	  gotoxy(10,15);
	  cprintf("%s",opt[cur].titl);
	  //delay(600);
	  curnt_fn=billmain;//the billing part as the current function to the pointer
	tbldisp();//the initial display of the billing part

	  break;
	}
      case 2:
	{
	  key=0x3e00;
	  gotoxy(10,15);
	  cprintf("%s",opt[cur].titl);
	  //delay(1000);
	  psswd_disp();//initial display for the table of the bill
	  curnt_fn=get_psswd;//assigning the current function as the main of the billing part
	  break;
	}

      case 3:
	{
	  gotoxy(10,15);
	  cprintf("%s",opt[cur].titl);
	  readall();
	  clrscr();
	  fil_no.cur_pos=0;
	  fil_no.chng_flag=1;
	  clrscr();
	  view(0);
	  curnt_fn=view;;//assigning the current function as the main of the billing part
	  //view.();
	  printf("\n\n\t press F3 to continue...");
	  break;
	}

      case 4:
	{
	  key=0x4000;
	  gotoxy(10,15);
	  cprintf("%s",opt[cur].titl);
	  help();
	  //delay(600);
	  break;
	}
      case 5:
	{
	  key=0x3c00;
	  gotoxy(10,15);
	  cprintf("%s",opt[cur].titl);
//	  //delay(600);
	  exit(0);
	  break;
	}


      default:
      {
	//gotoxy(10,15);
	//cprintf("%d",cur);
      }
    }
   }



//   else
//   {
      //printf("%#02x\n", key);

//   }
   //return (key);
}
#endif

#ifndef ADM_MNU_H
#define ADM_MNU_H

//void set_psswd(int key);
//void psswd_disp();
void psswd_main();
/*
//global variables
   int cur=0;//position of the cursor
   struct Position pos[5];//position of each option
   int nbox=5;
*/

void adm_mnu()
{

	//values for the table
	int xn=1;
	int yn=1;
	int wd[1]={3};
	int hd[1]={1};
	int menucorn[4]={5,5,50,20};
	int mpos_x,mpos_y;

	int i,j,c;//counter variables

	cur=0;//position of the cursor
	nbox=6;
	go_flag=0;
	no_op=6;

	textbackground(BLUE);
	clrscr();
	//cprintf("\n We r visitin MENU");

	//printingg the table
	table(menucorn[0],menucorn[1],menucorn[2],menucorn[3],wd,xn,hd,yn);

	//taking average of the starting and end columns
	//subtracting strlen/2 bcoz center lies 2 char after starting of
	//word MENU
	mpos_x= ((menucorn[0]+wd[0]+2)+(menucorn[2]))/2.0-strlen("MENU")/2;

	mpos_y=menucorn[1]+1;//1*yunit;
	gotoxy(mpos_x,mpos_y);
	cprintf("MENU");

	//other options
	strcpy(opt[0].titl,"Set/Change Username/password\0");
	strcpy(opt[1].titl,"File Handling\0");
	strcpy(opt[2].titl,"Settings\0");
	strcpy(opt[3].titl,"Main Menu\0");
	strcpy(opt[4].titl,"Billing Page\0");
	strcpy(opt[5].titl,"HELP\0");
	strcpy(opt[6].titl,"EXIT\0");
	for (i=0;i<no_op;i++)
	{
		int l=strlen(opt[i].titl);
		for (j=l;j<20;j++)
		{
			opt[i].titl[j]=' ';
		}
		opt[i].titl[20]='\0';
	}

	//displaying the options
	for(i=0;i<no_op;i++)
	{
		pos[i].x=menucorn[0]+6;
		pos[i].y=menucorn[1]+3+i;
		pos[i].wd=max_len;
		gotoxy( (menucorn[0]+2),menucorn[1]+3+i);
		cprintf("%d",i+1);
		gotoxy(pos[i].x,pos[i].y);
		cprintf("%s",opt[i].titl);
	}
	//delay(600);
	/*for(i=0;i<no_op;i++)
	//pointing til in menop sturct

	//processing othe options
	{
		int l=strlen(opt[i].titl);
		opt[i]->tit=&opt[i].titl;
		c=max_len/2;//here c is the centre of the word option
		for(j=max_len;j>c+l/2;j--)
			opt[i]->tit[j]=" ";//filling array with space
		for(j=c-l/2-1;j>=0;j--)
		{
			opt[i]->tit[j+l]=opt[i]->tit[j];
			opt[i]->tit[j]=" ";//filling array with space
		}
		opt[i]->tit[max_len+1]="\0";
	}
	for (i=0;i<no_op;i++)
	{
		gotoxy( (menucorn[0]+wd[0]+2),menucorn[1]+1+i);
		cprintf("%s",opt[i].titl);
	}

	//placing other options
	*/
	//gotoxy(1,1);
	//cprintf("%d",nbox);
}


//event hangling part
void adm_cur(int key)
{
   int asc=key%256;//store th asc input by the user
   textbackground(BLUE);
   gotoxy(pos[cur].x,pos[cur].y);
   cprintf(opt[cur].titl);


   //cursor handling part
       if ((asc==9) || (key==0x5000)) cur++;
      else if (key==0x4800 || key==0Xf00) cur--;
      else
      {

      }
      if (cur==nbox) cur=0;
      else if(cur==-1) cur=nbox-1;
   //gotoxy(4,15);
      //cprintf("%d               ",cur);

//checking the key board strokes for the choosing of the options by
//typing the number

//we put a go_flag ever time a menu is choosen by pressing the
//number key or enter key
   if (47<asc && asc<58)
   {
	go_flag=1;
	cur=asc-49;
   }
   else if( asc==13)
	go_flag=1;
   textbackground(RED);
   gotoxy(pos[cur].x,pos[cur].y);
   cprintf(opt[cur].titl);


   //if go_flag is ie the user has chooser an option
   if (go_flag==1)
   {
	go_flag=0;//to detect next time
	//the curor pos whe enter was pressed
	//or the number that was pressed
	switch (cur+1)
    {
      case 5:
	{
//	  key=0x3c00;
	  gotoxy(10,15);
	  cprintf("%s",opt[cur].titl);
	  //delay(600);
	  curnt_fn=billmain;//the billing part as the current function to the pointer
	tbldisp();//the initial display of the billing part

	  break;
	}
      case 2:
	{
	  //key=0x3d00;
	  gotoxy(10,15);
	  cprintf("%s",opt[cur].titl);
	  //delay(600);
	  fil_main(key);
	  break;
	}

      case 1:
	{
	  key=0x3e00;
	  gotoxy(10,15);
	  cprintf("%s",opt[cur].titl);
	  //delay(1000);
	  psswd_main();
//	  psswd_disp();//initial display for the table of the bill
//	  curnt_fn=set_psswd;//assigning the current function as the main of the billing part
	  break;
	}
      case 3:
	{
	  //key=0x3f00;
	  gotoxy(10,15);
	  cprintf("%s",opt[cur].titl);
	  setn_main();
	  //delay(600);
	  break;
	}
      case 4:
	{
	  key=0x4000;
	  gotoxy(10,15);
	  cprintf("%s",opt[cur].titl);
	  //delay(600);
	  curnt_fn=menu_cur;
	  menu();
	  break;
	}
      case 6:
	  help();
	  break;
      case 7:
	{
	  key=0x3c00;
	  gotoxy(10,15);
	  cprintf("%s",opt[cur].titl);
//	  //delay(600);
	  exit(0);
	  break;
	}
      default:
      {
	//gotoxy(10,15);
	//cprintf("%d",cur);
      }
    }
   }



//   else
//   {
      //printf("%#02x\n", key);

//   }
   //return (key);
}
#endif