//index.c
void detectmouse ();
void showmouse ();
void hidemouse ();
void mse(int x, int y);
void dtcbttn ();
int keyhit();
int detect();
void loading();
void printbill();
void tbldisp();
int billmain(int key);
void printbill();
void filmain(int);
void help();

//file4.h
void readall();
void view();
void fil_inp(int);


void init_disp();
void add();
void edit();
void editstock();
void decs_del(int);
void search();
void delrec();
void reset();
void fact_menu();
void fil_inp(int key);
//void st_update(char a[10],int st);
int updat_stok(char a[10],int d_st);
void decs_del(int key);
int searchid(struct bill2 *item);
void filmain(int key);
void fil_main(int key);



//crypt.h of file4.h
void psswd_disp();
void inp_psswd(int key);
void g_passwd (struct passwd cr);
void s_passwd (struct passwd cr);
void get_psswd(int key);
void set_psswd(int key);
void psswd_main();


//menu.h
void menu();
void menu_cur(int key);
//adm_mnu.h
void adm_mnu();
void adm_cur(int key);

//convt5.h in object.h
void cnvts(char str[],char asc,int i,int n);
float cnvtf(char str[],char asc,int i,int n);
int cnvti(char str[],char asc,int i,int n);
void itos(long a,char *b,int n);


//setting.h in object.h
void setn_disp();
void  settin(int key);
void setn_main();

//freemaloc.h in object .h
void freemaloc();

//table2.h
void bord();
void hrln (int wd,int *n);
void vrln (int vd,int n);
void table(int xmn,int ymn,int xmx,int ymx,int *wd,int xn,int *hd,int yn);


//textbox.h in table2.h
void box(int xmin,int ymin,int xmax,int ymax);
void tbox(int xst,int ymid,int xwd);