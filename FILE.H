#include "pro.h"

#ifndef FILE4_H
#define FILE4_H
int choice=0;
void (*fil_fn_cur) ();
void rtrim(char *);
int cur_pos;
/*void filmain(int);

void readall();
void view();
void fil_inp(int);


void init_disp();
void add();
void edit();
void editstock();
void decs_del(int);
void search();
void delfiel();
void reset();*/

void readall()
{
	textbackground(BLUE);
	fp=fopen("file.txt","r");
	fil_no.chng_flag=0;
	fil_no.tot_dat=0;
	fil_no.tot_aloc=10;
	freemaloc();
	fil_no.list=(struct bill3 **)malloc(sizeof(struct bill3 )*fil_no.tot_aloc);
	//clrscr();
	fp=fopen ("file.txt","r");
	if (fp==NULL) printf("\n\n\ncannot open file.txt");
	//afitem=malloc(sizeof(struct bill3 ));
	//printf("\ncontents of file.txt\n");
	//fitem->prev=NULL;
	while (!feof(fp))
	{
		/*printf("\n\tProduct Id : ");
		printf("%s",fitem.id);
		printf("\t\tProduct Name : ");
		printf("%s",fitem.nm);
		printf("\n\tPrice : ");
		printf("%.2f",fitem.pr);
		printf("\nStock : ");
		printf("%d",fitem.st);*/
	if (fil_no.tot_dat==fil_no.tot_aloc)
		{
			fil_no.tot_aloc+=10;
			fil_no.list=realloc(fil_no.list,sizeof(struct bill3 *)*fil_no.tot_aloc);
			//item=realloc(item,sizeof(struct bill2)*fil_no.tot_aloc);
		}
		/*if (fscanf(fp,"%s %s %f %d ",&fitem[]->id,&fitem[]->nm,&fitem[]->pr,fitem[]->st)!=EOF)
		{
			fil_no.tot_dat++;

			afitem=malloc(sizeof(struct bill3 *));
			fil_no.list[fil_no.tot_dat]=&afitem;
			//fitem[fil_no.tot_dat-1]->next=fitem[fil_no.tot_dat];
			//fitem[fil_no.tot_dat-1]->prev=filem[fil_no.tot_dat-2];
		}*/

		if (fscanf(fp,"%s %s %f %d ",&fitem.id,&fitem.nm,&fitem.pr,&fitem.st)!=EOF)//&afitem->id,&afitem->nm,&afitem->pr,&afitem->st)!=EOF)//
		{
			afitem=(struct bill3 *)malloc(sizeof(struct bill3 ));
			fil_no.list[fil_no.tot_dat]=afitem;
			/*
			printf("\n%s",fitem.id);
			printf("\t%s",fitem.nm);
			printf("\t%.2f",fitem.pr);
			printf("\t%d",fitem.st);
			*/
			strcpy(afitem->id,fitem.id);
			strcpy(afitem->nm,fitem.nm);
			afitem->pr=fitem.pr;
			afitem->st=fitem.st;
			/*
			printf("\n%s",afitem->id);
			printf("\t%s",afitem->nm);
			printf("\t%.2f",afitem->pr);
			printf("\t%d",afitem->st);
			/*
			strcpy(fil_no.list[fil_no.cur_pos]->id,fitem.id);
			strcpy(fil_no.list[fil_no.cur_pos]->nm,fitem.nm);
			fil_no.list[fil_no.cur_pos]->pr=fitem.pr;
			fil_no.list[fil_no.cur_pos]->st=fitem.st;
			/
			printf("\n%s",fil_no.list[fil_no.cur_pos]->id);
			printf("\t%s",fil_no.list[fil_no.cur_pos]->nm);
			printf("\t%.2f",fil_no.list[fil_no.cur_posl]->pr);
			printf("\t%d",fil_no.list[fil_no.cur_pos]->st);
			*/
			//fitem[fil_no.tot_dat-1]->next=fitem[fil_no.tot_dat];
			fil_no.tot_dat++;
		}
	}
	/*
	printf("\n\tProduct Id : ");
	printf("\t\tProduct Name : ");
	printf("\t\tPrice : ");
	printf("\tStock : ");

	for(fil_no.cur_posl=0;fil_no.cur_poslll<fil_no.tot_dat;fil_no.cur_pos++)
	//while (fscanf(fp,"%s %s %f %d ",&fitem.id,&fitem.nm,&fitem.pr,&fitem.st)!=EOF)//(feof(fp))
	{
		printf("\n\t%s",fil_no.list[fil_no.cur_pos]->id);
		printf("\t%s",fil_no.list[fil_no.cur_pos]->nm);
		printf("\t\t%.2f",fil_no.list[fil_no.cur_pos]->pr);
		printf("\t%d",fil_no.list[fil_no.cur_pos]->st);
		//if (fil_no.cur_pos%70==0) getch();
	}
	//fitem[fil_no.tot_dat-1]->next=NULL;
	*/
	fcloseall();
}

void fact_menu()
{
	//int xn=1;
	//int yn=1;
	//int wd[1]={3};
	//int hd[1]={1};
	//int menucorn[4]={5,5,50,20};
	//int mpos_x,mpos_y;

	int i,j,c;//counter variables

	cur=0;//position of the cursor
	nbox=14;
	go_flag=0;
	no_op=9;

	//textbackground(BLUE);
	//clrscr();
	//cprintf("\n We r visitin MENU");
	//table(menucorn[0],menucorn[1],menucorn[2],menucorn[3],wd,xn,hd,yn);

	//taking average of the starting and end columns
	//subtracting strlen/2 bcoz center lies 2 char after starting of
	//word MENU
	//mpos_x= ((menucorn[0]+wd[0]+2)+(menucorn[2]))/2.0-strlen("MENU")/2;

	//mposl_y=menucorn[1]+1;//1*yunit;
	//gotoxy(10,2);
	//cprintf("MENU");

	//other options
	strcpy(opt[0].titl,"1.Add\0");
	strcpy(opt[1].titl,"2.Edit\0");
	strcpy(opt[2].titl,"3.Edit Stock\0");
	strcpy(opt[3].titl,"4.Search Record\0");
	strcpy(opt[4].titl,"5.Delete Record\0");
	strcpy(opt[5].titl,"6.Reset\0");
	strcpy(opt[6].titl,"7.Main Menu\0");
	strcpy(opt[7].titl,"8.Billing Page\0");
	strcpy(opt[8].titl,"9.Exit\0");
	for (i=0;i<no_op;i++)
	{
		int l=strlen(opt[i].titl);
		for (j=l;j<20;j++)
		{
			opt[i].titl[j]=' ';
		}
		opt[i].titl[20]='\0';
	}

		//clrscr();
		//textcolor(2);
		for (i=0;i<no_op;i++)
		{
			tbox(pos[i].x=60,pos[i].y=2+i*2,pos[i].wd=20);
			gotoxy(pos[i].x,pos[i].y);
			printf("%s",opt[i].titl);
		}
		gotoxy(pos[8].x-1,pos[8].y+1);
		printf(" ");
		textcolor(1);
		for(i=0;i<20;i++)
		{
			gotoxy(pos[8].x+i,pos[8].y+1);
			printf(" ");
		}
		/*for(i=0;i<20;i++)
		{
			gotoxy(pos[7].x+i,pos[7].y+1);
			printf("%c",50);
		}*/
		textcolor(WHITE);
	/*for(i=0;i<no_op;i++)
	{
		pos[i].x=menucorn[0]+6;
		pos[i].y=menucorn[1]+3+i;
		pos[i].wd=max_len;
		gotoxy( (menucorn[0]+2),menucorn[1]+3+i);
		cprintf("%d",i+1);
		gotoxy(pos[i].x,pos[i].y);
		cprintf("%s",opt[i].titl);
	} */
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
	   textbackground(RED);

		//highlightining part
   gotoxy(pos[cur].x,pos[cur].y);
   cprintf("%s",opt[cur].titl);
    textbackground(0);

	//gotoxy(1,1);
	//cprintf("%d",nbox);
}

void view(int key)
{
	//FILE *fp,*tp;
	//clrscr();
	//fil_no.cur_pos=0;//0=view;
	int nod=20;
	int i;
	if (fil_no.chng_flag==0)
	switch (key)
	{
		case 0x4900:
			fil_no.chng_flag=-1;
			break;
		case 0x5100:
			fil_no.chng_flag=1;
			if (fil_no.cur_pos>=fil_no.tot_dat) goto d_view;
			break;
		default:
			goto d_view;
	}
	if (fil_no.cur_pos>fil_no.tot_dat) goto d_view;
	fp=fopen ("file.txt","r");
	if (fp==NULL) printf("\n\n\ncannot open file.txt");
	//tp=fopen ("temp.txt","r");
	//if (tp==NULL) printf("\n\n\ncannot open temp.txt");

	//printf("\ncontents of file.txt\n");
	//fact_menu();
	gotoxy(2,2);
	printf("SN");
	gotoxy(5,2);
	printf("Product Id : ");
	gotoxy(15,2);
	printf("Product Name : ");
	gotoxy(30,2);
	printf("Price : ");
	gotoxy(40,2);
	printf("Stock : ");
	gotoxy(50,2);

	if  ((fil_no.chng_flag==-1) &&(fil_no.cur_pos>=29))
	{      fil_no.cur_pos-=(nod+1);
	      fil_no.cur_pos-=fil_no.cur_pos%nod;
	}
	else if (fil_no.chng_flag==-1)  fil_no.cur_pos=0;
	for(i=0;i<nod;i++)
	{
		gotoxy(2,3+i);
		printf("                                        ");
	}
	for(;fil_no.cur_pos<fil_no.tot_dat;fil_no.cur_pos++)
	//while (fscanf(fp,"%s %s %f %d ",&fitem.id,&fitem.nm,&fitem.pr,&fitem.st)!=EOF)//(feof(fp))
	{
		if ((fil_no.cur_pos%nod==0) && (fil_no.chng_flag==0)) break;
		if  (fil_no.chng_flag!=0) fil_no.chng_flag=0;
		gotoxy(2,3+fil_no.cur_pos%nod);
		printf("%d",fil_no.cur_pos+1);
		gotoxy(5,3+fil_no.cur_pos%nod);
		printf("%s",fil_no.list[fil_no.cur_pos]->id);
		gotoxy(15,3+fil_no.cur_pos%nod);
		printf("%s",fil_no.list[fil_no.cur_pos]->nm);
		gotoxy(30,3+fil_no.cur_pos%nod);
		printf("%.2f",fil_no.list[fil_no.cur_pos]->pr);
		gotoxy(40,3+fil_no.cur_pos%nod);
		printf("%d",fil_no.list[fil_no.cur_pos]->st);
		//gotoxy(50,11+fil_no.cur_pos%nod);
		//if ((fil_no.cur_pos1)%5==0) getch();
	}
	/*printf("\ncontents of temp.txt\n");

	while (fscanf(tp,"%s %s %f %d ",&fitem.id,&fitem.nm,&fitem.pr,&fitem.st)!=EOF)//(feof(tp))
	{
		printf("\n\nProduct Id : ");
		printf("%s",fitem.id);
		printf("\t\tProduct Name : ");
		printf("%s",fitem.nm);
		printf("\t\tPrice : ");
		printf("%.2f",fitem.pr);
		printf("\nStock : ");
		printf("%d",fitem.st);
	}*/
	//getch();
	fcloseall();
	d_view:
	if  (fil_no.chng_flag!=0) fil_no.chng_flag=0;
}

void fil_inp(int key)
{
	int ans;
	int asc=key%256;
	//struct bill2 item;
	//struct bill fitem;
	int c,i;

	/*if ((choice<0) && (min_cur!=0) &&(nbox!=9))
	{
		min_cur=0;
		nbox=8;
		if (!(min_cur<cur && cur <nbox))
			cur=0;
	}

	else if ((choice>=0) &&(min_cur!=10))
	{
		min_cur=10;
		nbox=14;
		if (!(min_cur<cur && cur <nbox))
		cur=10;
	}
	*/

	{
		//initializing the flag
		item.sp_flag=0;

		if (10<=cur<14)
			item.flag[cur-10]=true;
		switch (cur)
	    {
	      case 10:
		{
		  TBDISP;
		  cnvts (&item.id,asc,ic[cur],mc[cur]); //converts typed key to string and stores in pd id
		  break;
		}
	      case 11:
		{
		  TBDISP;
		  cnvts (&item.nm,asc,ic[cur],mc[cur]); //converts typed key to string and stores in pd nm
		  break;
		}
	      case 12:
		{
		  //static char[9];
		  TBDISP;//putting invisible boxes(no borders in the boxes) inside the tables

		  //converts the typed keys first to string
		  //and stores in sqty
		  //then converts to int and stroes in qty
		  item.pr=cnvtf (&item.spr,asc,ic[cur],mc[cur]);
		  break;
		}
	      case 13:
		{
		  TBDISP;//putting invisible boxes(no borders in the boxes) inside the tables
		  //converts the typed keys first to string
		  //and stores in sprce
		  //then converts to int and stroes in prce
		  //bill[cur/4].prce=cnvtf (&bill[cur/4].sprce,asc,ic[cur],mc[cur]);
		  item.st=cnvti (&item.s_st,asc,ic[cur],mc[cur]);
		  break;
		}
	      default:
		{
			//gotoxy(10,15);
			//cprintf("%d",cur);
		}
	    }

	  }
//   	else
//   	{
      //printf("%#02x\n", key);

	if ((asc==9) || (key==0x5000))
	{
		prev_cur=cur;
		cur++;
		switch (cur)
		{
			case 9:
				cur++;
				break;
			case 10:
				break;
			case 11:
				if (choice==3)
					cur +=2;
				else if (choice==5 || choice==6)
					cur +=3;

				break;
			case 12:

				break;
			case 13:
				break;
			//case 14:
			//	break;
			//case 15:
			//	break;
		}
	}
	else if (key==0x4800)
	{
		prev_cur=cur;
		cur--;
		switch (cur)
		{
			case 9:
				//cur--;
				break;
			case 10:
				break;
			case 11:

				break;
			case 12:
				if (choice==3)
					cur -=2;
				break;
			case 13:
				if (choice==5 || choice==6)
					cur -=3;
				break;
			//case 14:
			//	break;
			//case 15:
			//	break;
		}

	}
      else
      {

      }
      if (cur==nbox) cur=min_cur;
      else if(cur<min_cur) cur=nbox-1;

      if ((choice<0) && (47<asc && asc<58))
      {
	go_flag=1;
	prev_cur=cur;
	cur=asc-49;
   }
   else if( asc==13)
	go_flag=1;
   textbackground(0);
   gotoxy(pos[prev_cur].x,pos[prev_cur].y);
   cprintf("%s",opt[prev_cur].titl);
   textbackground(RED);

   gotoxy(pos[cur].x,pos[cur].y);
   cprintf("%s",opt[cur].titl);
   textbackground(0);
   switch (key)
  {
		case 0x4900:
		case 0x5100:
			view(key);
			break;
		default:

   if (go_flag==1)
   {
	go_flag=0;
	//min_cur=10;
   switch (cur+1)
    {
      case 1:
	  //key=0x3c00;
	  choice=1;
	  //gotoxy(10,15);
	  //cprintf("%s",opt[cur].titl);
	  ////delay(600);
	  cur =10;
	  init_disp();
	  fil_fn_cur=add;
	  curnt_fn=fil_inp;

	  //curnt_fn=billmain;
	//tbldisp();

	  break;
      case 2:
	  //key=0x3d00;
	  choice =2;
	  //gotoxy(10,15);
	  //cprintf("%s",opt[cur].titl);
	  //delay(600);
	  cur =10;
	  init_disp();
	  fil_fn_cur=edit;
	  curnt_fn=fil_inp;

	  break;
      case 3:
	  //key=0x3e00;
	  choice=3;
	  //gotoxy(10,15);
	  //cprintf("%s",opt[cur].titl);
	  //delay(600);
	  cur =10;
	  init_disp();
	  fil_fn_cur=editstock;
	  curnt_fn=fil_inp;
	  //cr_disp(fil,'r');
	  //curnt_fn=crpt_rmode;
	  break;
      case 4:
	  //key=0x3f00;
	  choice=4;
	  //gotoxy(10,15);
	  //cprintf("%s",opt[cur].titl);
	  //delay(600);
	  cur =10;
	  init_disp();
	  fil_fn_cur=search;
	  curnt_fn=fil_inp;
	  break;
      case 5:
	  //key=0x4000;
	  choice=5;
	  //gotoxy(10,15);
	  //cprintf("%s",opt[cur].titl);
	  //delay(600);
	  cur =10;
	  init_disp();
	  fil_fn_cur=delrec;
	  curnt_fn=fil_inp;
	  break;

      case 6:
	  //key=0x3c00;
	  //gotoxy(10,15);
	  //cprintf("%s",opt[cur].titl);
	  //delay(600);
	  cur =10;
	  //init_disp();
	  reset();
	  //curnt_fn=fil_inp;
	  break;
      case 7:
	  //key=0x3c00;
	  //gotoxy(10,15);
	  //cprintf("%s",opt[cur].titl);
	  //delay(600);
	  curnt_fn=menu_cur;
	  menu();
	  break;
      case 8:
	  //key=0x3c00;
	  //gotoxy(10,15);
	  //cprintf("%s",opt[cur].titl);
	  //delay(600);
	  curnt_fn=billmain;
	  tbldisp();
	  break;

      case 9:
	  //key=0x3c00;
	  //gotoxy(10,15);
	  //cprintf("%s",opt[cur].titl);
	  //delay(600);
	  exit(0);
	  break;
    }
   }
  }

      if (
		((asc==13)&&(item.flag[0]==true))    &&
		(
		   ((choice==3)||
			(
				(item.flag[1]==true)  &&
				(item.flag[2]==true)
			)
		   )               ||
		   (
			(choice==4)||(choice==5)||(item.flag[3]==true))
		   )
		)
		fil_fn_cur();

			  //		gotoxy(10,15);
			//cprintf("%d",cur);
      gotoxy(pos[cur].x+mc[cur],pos[cur].y);


}

void init_disp()
{
	int c;
	for (c=0;c<40;c++)
	{
		ic[c]=0;
		mc[c]=0;
	}

	//nbox=4;
		//clrscr();
		textcolor(2);
		tbox(pos[10].x=10,pos[10].y=35,pos[10].wd=10);
		gotoxy(pos[10].x-6,pos[10].y);

		cprintf("id");
		if (choice==3  || choice==4 || choice ==5 )
			textcolor(4);
		tbox(pos[11].x=30,pos[11].y=35,pos[11].wd=10);
		gotoxy(pos[11].x-6,pos[11].y);
		cprintf("name");

		tbox(pos[12].x=50,pos[12].y=35,pos[12].wd=10);
		gotoxy(pos[12].x-6,pos[12].y);
		cprintf("price");

		if (choice==5 || choice==4)
			textcolor(4);
		else
			textcolor(2);
		tbox(pos[13].x=69,pos[13].y=35,pos[13].wd=10);
		gotoxy(pos[13].x-6,pos[13].y);
		cprintf("stock");
	//flaging false
	for (i=10;i<14;i++)
		item.flag[i]=false;



	// displaying the buttons
	textcolor(2);
	tbox(pos[14].x=60,pos[14].y=50-7,pos[14].wd=20);
	gotoxy(pos[14].x,pos[14].y);
	printf("Ok");
	tbox(pos[15].x=60,pos[15].y=50-3,pos[15].wd=20);
	gotoxy(pos[15].x,pos[15].y);
	printf("Cancel");
	//fil_fn_cur();
}


void add()
{
	fil_no.cur_pos=1;//add=1;
	//printf("editing\n\n");
	fp=fopen ("file.txt","r");
	if (fp==NULL) printf("\n\n\ncannot open file.txt");
	tp=fopen ("temp.txt","w");
	if (tp==NULL) printf("\n\n\ncannot open temp.txt");
		//clrscr();
		item.sp_flag=0;
		while (fscanf(fp,"%s %s %f %d ",&fitem.id,&fitem.nm,&fitem.pr,&fitem.st)!=EOF)
		{
			//printf("\n\nProduct Id : ");
			//printf("%s",fitem.id);
			//printf("\t\tProduct Name : ");
			//printf("%s",fitem.nm);
			//printf("\nPrice : ");
			//printf("%f",fitem.pr);
			//printf("\tStock : ");
			//printf("%d",fitem.st);
			//printf(tp,"\n%s\t%s\t",fitem.id,fitem.nm);
			if(item.sp_flag==0)
			{
				if ( strcmp(fitem.id,item.id) > 0 )
				{
					fprintf(tp,"%s\t%s\t%f\t%d\t",item.id,item.nm,item.pr,item.st);
					item.sp_flag=1;
				}
				else if (strcmp(fitem.id,item.id)==0)
				{
					printf("Item id already exists");
					fcloseall();
					remove("temp.txt");
					goto add_endofloop;
				}
			}
			fprintf(tp,"%s\t%s\t%f\t%d\t",fitem.id,fitem.nm,fitem.pr,fitem.st);
		}
		if (item.sp_flag==0)
		{
			fprintf(tp,"%s\t%s\t%f\t%d\t",item.id,item.nm,item.pr,item.st);
			item.sp_flag=1;
		}

		{
		//printf("\niProduct Id : ");
		//printf("%s",item.id);
		//printf("\tProduct Name : ");
		//printf("%s",item.nm);
		//printf("\tPrice : ");
		//printf("%f",item.pr);
		//printf("\nStock : ");
		//printf("%d",item.st);
		}

		//.getch();

		fcloseall();
		remove("file.txt");
		rename("temp.txt","file.txt");
		add_endofloop:
		curnt_fn=filmain;
}

void edit()
{
	//FILE *fp,*tp;
	//struct bill item-;
	//struct bill fitem;
	int n=3,c=0,i;
	fil_no.cur_pos=2;//edit=2
	fp=fopen ("file.txt","r");
	if (fp==NULL) printf("\n\n\ncannot open file.txt");
	tp=fopen ("temp.txt","w");
	if (tp==NULL) printf("\n\n\ncannot open temp.txt");

	item.sp_flag=0;
	/*
	{
		printf("\nProduct Id : ");
		scanf("%s",&item.id);
		printf("\nProduct Name : ");
		scanf("%s",&item.nm);
		printf("\nPrice : ");
		scanf("%f",&item.pr);
		printf("\nStock : ");
		scanf("%d",&item.st);
	}
	*/
	//printf("editing\n\n");
	while (fscanf(fp,"%s %s %f %d ",&fitem.id,&fitem.nm,&fitem.pr,&fitem.st)!=EOF)
	{
		//printf("\n\nProduct Id : ");
		//printf("%s",fitem.id);
		//printf("\t\tProduct Name : ");
		//printf("%s",fitem.nm);
		//printf(tp,"\n%s\t%s\t",fitem.id,fitem.nm);
		if ( strcmp(fitem.id,item.id) == 0 )
		{
			fprintf(tp,"%s\t%s\t%f\t%d\t",item.id,item.nm,item.pr,item.st);
			item.sp_flag=1;
		}
		else
			fprintf(tp,"%s\t%s\t%f\t%d\t",fitem.id,fitem.nm,fitem.pr,fitem.st);
	}
	if (item.sp_flag==0)
		printf("Item not found");

	//.getch();
	fcloseall();

	remove("file.txt");
	rename("temp.txt","file.txt");
	curnt_fn=filmain;
}

void editstock()
{
	//FILE *fp,*tp;
	//struct bill item;
	//struct bill fitem;
	//int n=3,c=0,i;
	fil_no.cur_pos=3;//edit=3
	fp=fopen ("file.txt","r");
	if (fp==NULL) printf("\n\n\ncannot open file.txt");
	tp=fopen ("temp.txt","w");
	if (tp==NULL) printf("\n\n\ncannot open temp.txt");
	item.sp_flag=0;
	while (fscanf(fp,"%s %s %f %d ",&fitem.id,&fitem.nm,&fitem.pr,&fitem.st)!=EOF)
	{
		//printf("\n\nProduct Id : ");
		//printf("%s",fitem.id);
		//printf("\t\tProduct Name : ");
		//printf("%s",fitem.nm);
		//printf(tp,"\n%s\t%s\t",fitem.id,fitem.nm);
		if ( strcmp(fitem.id,item.id) == 0 )
		{
			fprintf(tp,"%s\t%s\t%f\t%d\t",item.id,fitem.nm,fitem.pr,item.st);
			item.sp_flag=1;
		}
		else
			fprintf(tp,"%s\t%s\t%f\t%d\t",fitem.id,fitem.nm,fitem.pr,fitem.st);
	}
	if (item.sp_flag==0)
		printf("Item not found");

	//.getch();
	fcloseall();

	remove("file.txt");
	rename("temp.txt","file.txt");
	curnt_fn=filmain;
}

int updat_stok(char *a,int d_st)
{
	strcpy(item.id,a);
	rtrim(item.id);
	//FILE *fp,*tp;
	//struct bill item;
	//struct bill fitem;
	//int n=3,c=0,i;
	fcloseall();
	fp=fopen ("file.txt","r");
	if (fp==NULL) printf("\n\n\ncannot open file.txt");
	tp=fopen ("temp.txt","w");
	if (tp==NULL) printf("\n\n\ncannot open temp.txt");
	item.sp_flag=0;
	while (fscanf(fp,"%s %s %f %d ",&fitem.id,&fitem.nm,&fitem.pr,&fitem.st)!=EOF)
	{
		//printf("\n\nProduct Id : ");
		//printf("%s",fitem.id);
		//printf("\t\tProduct Name : ");
		//printf("%s",fitem.nm);
		//printf(tp,"\n%s\t%s\t",fitem.id,fitem.nm);
		if ( strcmp(fitem.id,item.id) == 0 )
		{
			item.st=d_st;
			if (item.st<=0) return (fitem.st);
			fprintf(tp,"%s\t%s\t%f\t%d\t",item.id,fitem.nm,fitem.pr,item.st);
			item.sp_flag=1;
		}
		else
			fprintf(tp,"%s\t%s\t%f\t%d\t",fitem.id,fitem.nm,fitem.pr,fitem.st);
	}
	if (item.sp_flag==0)
		//printf("Item not found");

	//.getch();
	fcloseall();

	remove("file.txt");
	rename("temp.txt","file.txt");
	return 0;
}


void decs_del(int key)
{
	int asc=key%256;
		if (asc=='y' ||asc=='Y')
		{
			remove("file.txt");
			rename("temp.txt","file.txt");
		}
		else
			remove("temp.txt");
	curnt_fn=filmain;
}

void delrec()
{
	//FILE *fp,*tp;
	//struct bill item;
	//struct bill fitem;
	int n=3,c=0,i;
	fil_no.cur_pos=5;//delete=5

	fp=fopen ("file.txt","r");
	if (fp==NULL) printf("\n\n\ncannot open file.txt");
	tp=fopen ("temp.txt","w");
	if (tp==NULL) printf("\n\n\ncannot open temp.txt");

	{
	//	printf("\nProduct Id : ");
	//	scanf("%s",item.id);

	}
	item.sp_flag=false;
	while (fscanf(fp,"%s %s %f %d ",&fitem.id,&fitem.nm,&fitem.pr,&fitem.st)!=EOF)
	{
		//printf("\n\nProduct Id : ");
		//printf("%s",fitem.id);
		//printf("\t\tProduct Name : ");
		//printf("%s",fitem.nm);
		//printf(tp,"\n%s\t%s\t",fitem.id,fitem.nm);

		if ( strcmp(fitem.id,item.id) != 0 )
			fprintf(tp,"%s\t%s\t%f\t%d\t",fitem.id,fitem.nm,fitem.pr);
		else
		{
			item.sp_flag=true;
			gotoxy(30,20);
			printf("%s",fitem.nm);
			printf("\tPrice : ");
			gotoxy(pos[2].x,pos[2].y);
			gotoxy(30,25);
			printf("%f",fitem.pr);
			printf("\nStock : ");
			gotoxy(pos[3].x,pos[3].y);
			gotoxy(30,30);
			printf("%d",fitem.st);

			printf ("\n\tdo you want to delete this(y/n)?");
			curnt_fn=decs_del;
			if (getch()=='n')
				fprintf(tp,"%s\t%s\t%f\t%d\t",fitem.id,fitem.nm,fitem.pr);

		}
	}
	fcloseall();
	printf("\n\n\n");
	if (item.sp_flag==false)
	{
		printf("item not found");
		curnt_fn=filmain;
		//.getch();
	}
	else
	{}
}


void search()
{
	FILE *fp,*tp;
	//struct bill item;
	//struct bill fitem;
	int n=3,c=0,pos;
	clrscr();
	fil_no.cur_pos=4;//search=4
	fp=fopen ("file.txt","r");
	if (fp==NULL) printf("\n\n\ncannot open file.txt");
	{
		//printf("\nProduct Id : ");
		//scanf("%s",item.id);
		//printf("\nProduct Name : ");
		//scanf("%s",item.nm);
		//printf("\nPrice : ");
		//scanf("%f",&item.pr);
	}
	item.sp_flag=0;

	while ((fscanf(fp,"%s %s %f %d ",&fitem.id,&fitem.nm,&fitem.pr,&fitem.st)!=EOF)
		&&(item.sp_flag!=2))
	{
		/*printf("\n\nProduct Id : ");
		printf("%s",fitem.id);
		printf("\t\tProduct Name : ");
		printf("%s",fitem.nm);*/
		//printf(tp,"\n%s\t%s\t",fitem.id,fitem.nm);
		if ( strcmp(fitem.id,item.id) == 0 )
		{
			item.sp_flag=1;
			printf("\nProduct Id : ");
			printf("%s",fitem.id);
			printf("\tProduct Name : ");

			gotoxy(30,30);
			printf("%s",fitem.nm);
			printf("\tPrice : ");
			//gotoxy(pos[12].x,pos[12].y);
			gotoxy(30,35);
			printf("%f",fitem.pr);
			printf("\nStock : ");
			//gotoxy(pos[13].x,pos[13].y);
			gotoxy(30,40);
			printf("%d",fitem.st);

			goto done;
		}
		//else if (( strcmp(fitem.id,item.id) != 0 )&&(item.sp_flag==1))
		//	item.sp_flag=2;
		pos++;
	}
	//if (item.sp_flag==0)
		printf("\n\n\n\tItem not found");
	done:
	getch();
	fcloseall();
	curnt_fn=filmain;
	//return (pos);
}

int searchid(struct bill2 *item)
{
	FILE *fp,*tp;
	//struct bill item;
	//struct bill fitem;
	int n=3,c=0,pos;
	//clrscr();
	fil_no.cur_pos=4;//search=4
	fp=fopen ("file.txt","r");
	if (fp==NULL) printf("\n\n\ncannot open file.txt");
	{
		//printf("\nProduct Id : ");
		//scanf("%s",item.id);
		//printf("\nProduct Name : ");
		//scanf("%s",item.nm);
		//printf("\nPrice : ");
		//scanf("%f",&item.pr);
	}
	item->sp_flag=0;

	while ((fscanf(fp,"%s %s %f %d ",&fitem.id,&fitem.nm,&fitem.pr,&fitem.st)!=EOF)
		&&(item->sp_flag!=2))
	{
		/*printf("\n\nProduct Id : ");
		printf("%s",fitem.id);
		printf("\t\tProduct Name : ");
		printf("%s",fitem.nm);*/
		//printf(tp,"\n%s\t%s\t",fitem.id,fitem.nm);
		if ( strcmp(fitem.id,item->id) == 0 )
		{
			item->sp_flag=1;
			//printf("\nProduct Id : ");
			//printf("%s",fitem.id);
			//printf("\tProduct Name : ");

			strcpy(item->nm,fitem.nm);
			item->st=fitem.st;
			item->pr=fitem.pr;


			gotoxy(30,30);
			//printf("%s",fitem.nm);
			//printf("\tPrice : ");
			//gotoxy(pos[2].x,pos[2].y);
			gotoxy(30,35);
			//printf("%f",fitem.pr);
			//printf("\nStock : ");
			//gotoxy(pos[3].x,pos[3].y);
			//gotoxy(30,40);
			//printf("%d",fitem.st);

			goto done;
		}
		//else if (( strcmp(fitem.id,item.id) != 0 )&&(item.sp_flag==1))
		//	item.sp_flag=2;
		pos++;
	}
	//if (item.sp_flag==0)
		//printf("\n\n\n\tItem not found");

	done:
	//getch();
	fcloseall();
	if (item->sp_flag==1) return (true);
	else return (false);
	//return (pos);
}


void reset()
{
	char ans;
	fil_no.cur_pos=6;//reset=6
	printf("\nThis will reset");
	//delay(500);
	printf("\n\tThat is delete  all the records permanently");
	//delay(1500);
	printf("\nAre you sure you want to do this?(y/n)");
	ans=getch();
	if (ans=='y'||ans=='Y') remove ("file.txt");
}

void filmain(int key)
{
	int c;
	clrscr();
	fcloseall();
	choice=-1;
	min_cur=0;
	nbox=9;
		readall();
		//init_view();
	for (c=0;c<40;c++)
	{
		ic[c]=0;
		mc[c]=0;
	}

		fil_fn_cur=view;
		curnt_fn=fil_inp;

		//init_disp();
		fil_no.chng_flag=1;
		fil_no.cur_pos=0;
		view(0);
		fact_menu();

		//filmenu(key);
		//getch();
}

void fil_main(int key)
{
	filmain(key);
}
#endif
#ifndef CRYPT_H
#define CRYPT_H

//void pssw_disp();
//void fil_main(int);
/*struct text_box
{
	char field[20];
};
*/

struct passwd
{
	char usrnm[25];
	char psswd[25];
};

void (*int_fn_curn) (struct passwd);

void psswd_disp()
{
	int c;
	for (c=0;c<4;c++)
	{
		ic[c]=0;
		mc[c]=0;
	}

	nbox=2;
		//clrscr();
		textcolor(2);
		tbox(pos[0].x=10,pos[0].y=35,pos[0].wd=10);
		gotoxy(pos[0].x,pos[0].y-1);

		cprintf("Username:");
		tbox(pos[1].x=30,pos[1].y=35,pos[1].wd=10);
		gotoxy(pos[1].x,pos[1].y-1);
		cprintf("Password:");

	//flaging false
	for (i=10;i<14;i++)
		item.flag[i]=false;

	// displaying the buttons
	textcolor(2);
	tbox(pos[2].x=60,pos[2].y=50-7,pos[2].wd=20);
	gotoxy(pos[2].x,pos[2].y);
	printf("Ok");
	tbox(pos[3].x=60,pos[3].y=50-3,pos[3].wd=20);
	gotoxy(pos[3].x,pos[3].y);
	printf("Cancel");
	cur=0;
	go_flag=0;//unraised
	//fil_fn_cur();
}

void inp_psswd(int key)
{

	int ans;
	int asc=key%256;
	int c,i;
	static struct passwd cr;
	//printf("void get psswd");

		//initializing the flag
		item.sp_flag=0;
	if ((asc==9) || (key==0x5000))
	{
		prev_cur=cur;
		cur++;
	}
	else if (key==0x4800)
	{
		prev_cur=cur;
		cur--;
	}
	else
	{

	}


	if (cur==nbox) cur=min_cur;
	else if(cur<min_cur) cur=nbox-1;
	else if( asc==13)
		go_flag=1;
/*   textbackground(0);
   gotoxy(pos[prev_cur].x,pos[prev_cur].y);
   cprintf("%s",opt[prev_cur].titl);
   textbackground(RED);

   gotoxy(pos[cur].x,pos[cur].y);
   cprintf("%s",opt[cur].titl);
*/

   textbackground(0);
	switch (cur)
	    {
	      case 0:
		{
		  TBDISP;
		  cnvts (&cr.usrnm,asc,ic[cur],mc[cur]); //converts typed key to string and stores in pd id
		  break;
		}
	      case 1:
		{
		  PSSDISP;
		  cnvts (&cr.psswd,asc,ic[cur],mc[cur]); //converts typed key to string and stores in pd nm
		  break;
		}
	      case 2:
		  if (asc==32) go_flag=1;
		  break;
	      case 3:
		  curnt_fn=menu_cur;
		  menu();
		  break;
	      case 4:
		  break;
	      case 5:
		  break;
	    }
    if (go_flag==1)
    {
	go_flag=0;
	int_fn_curn(cr);
    }
    gotoxy(pos[cur].x+mc[cur],pos[cur].y);
      /*if (
		((asc==13)&&(item.flag[0]==true))    &&
		(
		   ((choice==3)||
			(
				(item.flag[1]==true)  &&
				(item.flag[2]==true)
			)
		   )               ||
		   (
			(choice==4)||(choice==5)||(item.flag[3]==true))
		   )
		)
		fil_fn_cur();

					gotoxy(10,15);
			cprintf("%d",cur);*/

}

void g_passwd (struct passwd cr)
{
	long count=0;//16732197;//this can be any number
	int i;
	int flag=0;//unraised
	fp=fopen("Psswd.txt","r");

	//fprintf(fp,"%s\t%s\t",cr.usrnm,cr.psswd);
	for(i=0;cr.usrnm[i]!='\0';i++)
	{
		char str[4];
		char fstr[4];
		itos(cr.usrnm[i],str,3);
		fgets(fstr,4,fp);
		//printf("\t%s->%s ?%d??",str,fstr,flag);
		if (strcmp(str,fstr)) flag=1;//raised //if they are not the same
	}
	if (fgetc(fp)!=32) flag=1;
	//printf("\n%dflag\n",flag);
	for(i=0;cr.psswd[i]!='\0';i++)
	{
		char str[9], fstr[9];
		//cr.psswd[i]*=16;
		//cr.psswd[i]-=27;
		count+=cr.psswd[i];
		itos(count,str,8);
		fgets(fstr,9,fp);
		if (strcmp(str,fstr)) flag=1;//raised //if they are not the same
	}
	if (fgetc(fp)!=32) flag=1;
	if (flag ==0)//flag not raised
	{
		printf("both are correct");
		//delay(400);
		curnt_fn=adm_cur;
		adm_mnu();
	}
	else
	printf("\n\n\t\tEiter or is incorrect");
	//printf("\n you typed %s %s",cr.usrnm,cr.psswd);
	//printf("\n correct ones are %s %s",fcr.usrnm,fcr.psswd);

//	getch();
//	exit(0);
}

void s_passwd (struct passwd cr)
{
	long count=0;//16732197;//this can be any number
	int i;
	fp=fopen("Psswd.txt","w");
	//fprintf(fp,"%s\t%s\t",cr.usrnm,cr.psswd);
	for(i=0;cr.usrnm[i]!='\0';i++)
	{
		char str[4];
		itos(cr.usrnm[i],str,3);
		fputs(str,fp);
	}
	fputc(' ',fp);
	for(i=0;cr.psswd[i]!='\0';i++)
	{
		char str[9];
		//cr.psswd[i]*=16;
		//cr.psswd[i]-=27;
		count+=cr.psswd[i];
		itos(count,str,8);
		fputs(str,fp);
	}
	fputc(32,fp);
	printf("\n\n\t\t%s\t%s\t",cr.usrnm,cr.psswd);
	fcloseall();
	printf("\n asdasd!!!!!!!!!!writing successful");
	adm_mnu();
	curnt_fn=adm_cur;
	//getch();

	//exit(1);
}

void get_psswd(int key)
{
	if (int_fn_curn!=g_passwd) int_fn_curn=g_passwd;
	inp_psswd(key);
}

void set_psswd(int key)
{
	if (int_fn_curn!=s_passwd) int_fn_curn=s_passwd;
	inp_psswd(key);
}

void psswd_main()
{
	  curnt_fn=set_psswd;//assigning the current function as the main of the billing part
	  psswd_disp();//initial display for the table of the bill
}
#endif