#include "head.h"
#include "pro.h"

//void menu_cur(int);
//void filmain(int);
//defining the hex values
//detecting mouse
//void (*fil_fn_cur) ();
//void (*curnt_fn) (int key);

struct error
{
	int mse;
	int file;
	int psswd;
	int settings;
};

struct error load;

void detectmouse ()
{
 in.x.ax = 0;
 int86 (0X33,&in,&out);
 gotoxy(1,1);
 if (out.x.ax == 0) //initializing mouse
 {
	printf ("\nMouse Fail To Initialize");
	load.mse=0;
 }
 else
 {
	load.mse=1;
	printf ("\nMouse Succesfully Initialize");
 }
}

//displaying mouse in text view
void showmouse ()
{
  in.x.ax = 1;
  int86 (0X33,&in,&out);
}

//for hiding mouse
void hidemouse ()
{
 in.x.ax = 2;
 int86 (0X33,&in,&out);
}

//detecting position and text box
void mse(int x, int y)//detecting if the mouse buttons have clicked teh buttons or the text  box part
{
	int i;
	for (i=0;i<nbox;i++)
	if (pos[i].x<=x && x<=(pos[i].x+pos[i].wd) &&
	    pos[i].y==y)
	{    cur=i;
	     key=0;
	     go_flag=1;

	     gotoxy(10,15);
	     //cprintf("mse job");
	     curnt_fn(key);
	}
}

//detecting mouse button
void dtcbttn ()
{
  /* function 1 returns 0 until a key is pressed */
  //while (_bios_keybrd(_KEYBRD_READY) == 0)  //while (!kbhit () )
    {
     int x,y;
     static int mov_flag=0;
     float x1,y1;
     static int xx,yy;
     static buffer[2];

     in.x.ax = 3;
     int86 (0X33,&in,&out);
       //clrscr();
       //gotoxy(40,30);
	 x = out.x.cx;
	 y = out.x.dx;
	 //printf ("\nLeft || X - %d  Y - %d", x, y);
	 x1=x/639.0*80;
	 y1=y/399.0*50;
	 if (x1>(int)x1) x=(int)x1+1;
	 else x=x1;
	 if (y1>(int)y1) y=(int)y1+1;
	 else y=y1;

	/*if (mov_flag==1 && ((xx!=x) ||(yy!=y)))
	{puttext(xx,yy,xx,yy,buffer); printf("%d",buffer[0]);}
	mov_flag=1;
	 xx=x;
	 yy=y;
	 gettext(xx,yy,xx,yy,buffer);
	*/
     if (out.x.bx == 1)
       {
	 //gotoxy(2,2);
	 //cprintf ("\nLeft || X - %f  Y - %f",x1,y1 );
	 //cprintf ("\nLeft || X - %d  Y - %d", x, y);
	 //gotoxy(x,y);
	 //cprintf("||");
	 mse_flag=1;
	 mse(x,y);
       }
       else if (out.x.bx == 2)
       {
       //printf ("\nRight");
       delay (100);}
       else if (out.x.bx == 3)
       {//printf ("\nMiddle");
       delay (100);}
       else
       mse_flag=0;
	  // Otherwise due to quick computer response 100s of words will get print
    }
       delay(100);
}

int keyhit()
{
   /* function 1 returns 0 until a key is pressed */
   //int wxmax=80;//user setting max x value
   //int wymax=25;//user setting max y value
   //float xunit;//horixontal unit(scaling ratio) step =1 for 80,25
   //float yunit;//vertical unit(scaling ratio) step =1 for 80,25
   //int flag;// flag for local purpose

   /* function 0 returns the key that is waiting */
   /* function 1 returns 0 until a key is pressed */

   if (_bios_keybrd(_KEYBRD_READY) != 0)  //while (!kbhit () )
   {
   //do{
   key = _bios_keybrd(_KEYBRD_READ);

   /* use function 2 to determine if shift keys were used */
   /*modifiers = _bios_keybrd(_KEYBRD_SHIFTSTATUS);
   if (modifiers)
   {
      printf("[");
      if (modifiers & RIGHT) printf("RIGHT");
      if (modifiers & LEFT)  printf("LEFT");
      if (modifiers & CTRL)  printf("CTRL");
      if (modifiers & ALT)   printf("ALT");
      printf("]");
   }
   // print out the character read
   printf("%#02x\n", key);         */

   hidemouse();
   switch (key)//detecting the function keys
   {
     case 0x3b00://Fn1 key is pressed
	help();
	//getch();
	break;
     case 0x3c00://Fn2 key is pressed
	curnt_fn=billmain;
	tbldisp();
	break;
     case 0x3d00://Fn3 key is pressed
	  curnt_fn=menu_cur;
	  menu();
	  break;
     case 0x3e00:

	  break;
     case 0x4400:

	  //psswd_disp();//initial display for the table of the bill
	  //curnt_fn=get_psswd;//assigning the current function as the main of the billing part
	  psswd_main();
	break;
   }
   curnt_fn(key);
   //}while (detect ()!=0x11b);
   }
   //getch();
   showmouse();
   return key;
}


int detect()//detecting input interface device event
{

  if (load.mse==1) dtcbttn();//detecting the mouse buttons clicks
  return (keyhit());//detecting the key strokes



}



void loading()
{
  int l_x=20,l_y=20,l_w=20;
  int dly=100;
  textcolor(7);
  tbox(l_x,l_y,l_w);
  gotoxy(l_x,l_y-1);
  delay(dly);
  printf("loading...");
  delay(dly);
  textbackground(0);
  gotoxy(l_x,l_y);
  printf("%c",219);
  delay(dly);
  printf("%c",219);
  delay(dly);
  detectmouse ();//detecting and initializing mouse
  gotoxy(l_x+2,l_y);
  printf("%c",219);
  delay(dly);
  printf("%c",219);
  delay(dly);
  showmouse ();//assigning the flaag interrupt for showing mouse as true
 // curnt_fn=filmain;
 gotoxy(l_x+4,l_y);
  delay(dly);
  printf("%c",219);
  delay(dly);
  printf("%c",219);
  fp=fopen("settings.txt","r");
  fscanf(fp,"%d %d %d %d %d",&read_flag.fil,&read_flag.name,&read_flag.name,&read_flag.price,&read_flag.st);
  fcloseall();
  delay(dly);
  gotoxy(l_x+6,l_y);
  printf("%c",219);
  delay(dly);
  gotoxy(l_x+7,l_y);
  printf("%c",219);
  delay(dly);
  gotoxy(l_x+8,l_y);
  printf("%c",219);
  delay(dly);
  gotoxy(l_x+9,l_y);
  printf("%c",219);
  gotoxy(l_x+10,l_y);
  printf("%c",219);
  fopen ("File.txt","a");
  gotoxy(l_x+11,l_y);
  printf("%c",219);
  gotoxy(l_x+12,l_y);
  printf("%c",219);
  if (!fopen("Psswd.txt","r"))
	{	fp=fopen("Psswd.txt","w");
		fprintf(fp,"  ");
		fcloseall();
	}
  gotoxy(l_x+13,l_y);
  printf("%c",219);
  gotoxy(l_x+14,l_y);
  printf("%c",219);
  gotoxy(l_x+15,l_y);
  printf("%c",219);
  gotoxy(l_x+16,l_y);
  printf("%c",219);
  fcloseall();
  gotoxy(l_x+17,l_y);
  printf("%c",219);
  delay(dly);
  gotoxy(l_x+18,l_y);
  printf("%c",219);
  gotoxy(l_x+19,l_y);
  printf("%c",219);
  //getch();
  //if (fopen())
   tbldisp();//initial display for the table of the bill
  curnt_fn=billmain;//assigning the current function as the main of the billing part
  //billmain contorlls the event hanling in the bill
}

int main ()
{
  clrscr();
  loading();
  //getch();
  //psswd_disp();
  //curnt_fn=set_psswd;
  while (!(detect ()==0x2d00 ));//&& (modifiers & ALT))  );//detecting the mose and keyboard action
  hidemouse ();//assiging the flag interrupt for hiding the mouse

  //closing all the files
  fcloseall();
  //cleardevice();
  return 0;
}

void help()
{
clrscr();
gotoxy(38,1);
printf("HELP");
printf("\nThis is a user friendly billing software designed. This program faciliates the graphical user interface but with the dos mode graphics. The baseccursor contorl keys are ");
printf("\n\t%c\t Up\n\t%c\t Down\n\t%c\t Left\n\t%c\t Right",30,31,17,16);
printf("\nThe other cusror control keys are");
printf("\n\n\tPress F2");
}