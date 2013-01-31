/*#include<conio.h>
#include <stdio.h>
#include <stdlib.h>
*/
#include "pro.h"

#ifndef TABLE2_H
#define TABLE2_H

int xlin[8];
int xmin, ymin, xmax, ymax;
int xcor;
int ycor;


void bord()
{
	int i,j;
	xcor=xmin;
	ycor=ymin;
	for(i=xmin+1;i<xmax;i++)
	{
		gotoxy(i,ymin);
		cprintf("%c",205);
		gotoxy(i,ymax);
		cprintf("%c",205);
	}

	for(j=ymin+1;j<ymax;j++)
	{
		gotoxy(xmin,j);
		cprintf("%c",186);
		gotoxy(xmax,j);
		cprintf("%c",186);
	}
	gotoxy(xmin,ymin);
	cprintf("%c",201);
	gotoxy(xmax,ymin);
	cprintf("%c",187);
	gotoxy(xmax,ymax);
	cprintf("%c",188);
	gotoxy(xmin,ymax);
	cprintf("%c",200);

}

void hrln (int wd,int *n)
{
	int i;
	xcor+=wd+1;
	for(i=ymin+1;i<ymax;i++)
	{
		gotoxy(xcor,i);
		cprintf("%c",179);
	}
	xlin[*n]=xcor;
	(*n)++;
	gotoxy(xcor,ymin);
	cprintf("%c",209);
	gotoxy(xcor,ymax);
	cprintf("%c",207);
}

void vrln (int vd,int n)
{
	int i,j;
	ycor+=vd+1;
	for(i=xmin+1;i<xmax;i++)
	{
		gotoxy(i,ycor);
		cprintf("%c",196);
		for (j=0;j<n;j++)
		{
			if (i==xlin[j])
			{
				gotoxy(i,ycor);
				cprintf("%c",197);
			}
		}
	}
	gotoxy(xmin,ycor);
	cprintf("%c",199);
	gotoxy(xmax,ycor);
	cprintf("%c",182);
}


void table(int xmn,int ymn,int xmx,int ymx,int *wd,int xn,int *hd,int yn)
{
	int n=0;
	int i;
	xmin=xmn;
	xmax=xmx;
	ymin=ymn;
	ymax=ymx;
	bord();
	for(i=0;i<xn;i++)
	{
		hrln(wd[i],&n);
	}
	for(i=0;i<yn;i++)
	{
		vrln(hd[i],n);
	}
}

#endif


#ifndef textbox_h
#define textbox_h


void box(int xmin,int ymin,int xmax,int ymax)
{
	int i,j;
	for(i=xmin+1;i<xmax;i++)
	{
		gotoxy(i,ymin);
		cprintf("%c",196);
		gotoxy(i,ymax);
		cprintf("%c",196);
	}

	for(j=ymin+1;j<ymax;j++)
	{
		gotoxy(xmin,j);
		cprintf("%c",179);
		gotoxy(xmax,j);
		cprintf("%c",179);
	}
	gotoxy(xmin,ymin);
	cprintf("%c",218);
	gotoxy(xmax,ymin);
	cprintf("%c",191);
	gotoxy(xmax,ymax);
	cprintf("%c",217);
	gotoxy(xmin,ymax);
	cprintf("%c",192);

}
void tbox(int xst,int ymid,int xwd)
{
	int ymn=ymid-1;
	int xmn=xst-1;
	int ymx=ymid+1;
	int xmx=xst+xwd;
	box(xmn,ymn,xmx,ymx);
}
#endif


//plus 197
//down 207
//right182
//up 209
//left199