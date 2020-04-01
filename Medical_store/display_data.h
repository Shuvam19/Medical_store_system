void show_stock()
{
    FILE *fp,*fp1;
    struct Data new;
    struct record rk;
    fpos_t l;
    char ch,x;
    int f=1,p=0,d=0;
    int g=3;
    system("cls");
    fp = fopen("sk.txt","r");
    while(fscanf(fp,"%s %d %d %d %d %d %d %d %d ",&new.m_name,&new.mfg_day,&new.mfg_mon,&new.mfg_year,&new.exp_day,&new.exp_mon,&new.exp_year,&new.price,&new.quantity)!= EOF)
        {
            p++;
            fgetpos(fp,&l);
            print_layout();
            fp1 = fopen("record.txt","r");
            while(fscanf(fp1,"%s %d %d %d %d %d %d %d %d %d ",&rk.m_name,&rk.exp_day,&rk.exp_mon,&rk.exp_year,&rk.sell_day,&rk.sell_mon,&rk.sell_year,&rk.price,&rk.quantity,&rk.total_price)!= EOF)
                {
                    if(!strcmp(new.m_name,rk.m_name))
                    {
                        new.quantity = new.quantity - rk.quantity;
                    }
                }
            fclose(fp1);
            print_data(new,g++,f++);
            gotoxy(10,25);
            printf(" 4 for Backward  6 for Forward ");
            if(p%7==0 /*|| work from here */)
                {
                    d = getch();
                    if(d==54)
                        {
                            system("cls");
                            g=3;
                        }
                    if(d==52)
                        {
                        }
                }
        }
    fclose(fp);
    getch();
}


void print_layout()
{
    gotoxy(1,2);
    printf("Sr.no");
    gotoxy(7,2);
    printf("|");
    gotoxy(9,2);
    printf("Medicine Name");
    gotoxy(24,2);
    printf("|");
    gotoxy(26,2);
    printf("Date of Manufacture");
    gotoxy(46,2);
    printf("|");
    gotoxy(48,2);
    printf("Date of Expiry");
    gotoxy(63,2);
    printf("|");
    gotoxy(65,2);
    printf("Price");
    gotoxy(71,2);
    printf("|");
    gotoxy(73,2);
    printf("Quantity");
}



void print_data(struct Data new,int g,int f)
{
    gotoxy(3,g);
    printf("%d",f);
    gotoxy(7,g);
    printf("|");
    gotoxy(10,g);
    printf("%s",new.m_name);
    gotoxy(24,g);
    printf("|");
    gotoxy(30,g);
    printf("%d/%d/%d",new.mfg_day,new.mfg_mon,new.mfg_year);
    gotoxy(46,g);
    printf("|");
    gotoxy(50,g);
    printf("%d/%d/%d",new.exp_day,new.exp_mon,new.exp_year);
    gotoxy(63,g);
    printf("|");
    gotoxy(67,g);
    printf("%d",new.price);
    gotoxy(71,g);
    printf("|");
    gotoxy(76,g);
    printf("%d",new.quantity);
}

// It diaplays the data in range of Days
void show_stock_d_m()
{
FILE *fp;
struct record rk;
struct date sk;
char ch;
int f,c=0;
int g=2;
system("cls");
gotoxy(20,2);
printf("Enter the Range of Days : ");
gotoxy(10,4);
printf("From :");
gotoxy(35,4);
printf("To :");
while(c!=1)
{
gotoxy(17,4);
printf("  /  /    ");
gotoxy(17,4);
scanf("%d",&sk.pre_day);
gotoxy(20,4);
scanf("%d",&sk.pre_mon);
gotoxy(23,4);
scanf("%d",&sk.pre_year);
c=check_date(sk.pre_day,sk.pre_mon,&sk.pre_year);
}
c=0;
while(c!=1)
{
gotoxy(40,4);
printf("  /  /    ");
gotoxy(40,4);
scanf("%d",&sk.post_day);
gotoxy(43,4);
scanf("%d",&sk.post_mon);
gotoxy(46,4);
scanf("%d",&sk.post_year);
c=check_date(sk.post_day,sk.post_mon,&sk.post_year);
}
fp = fopen("record.txt","r");
system("cls");
print_record_layout();
f=0;
while(fscanf(fp,"%s %d %d %d %d %d %d %d %d %d ",&rk.m_name,&rk.exp_day,&rk.exp_mon,&rk.exp_year,&rk.sell_day,&rk.sell_mon,&rk.sell_year,&rk.price,&rk.quantity,&rk.total_price)!= EOF)
{
f++;
g++;
if((rk.sell_year > sk.pre_year) && (rk.sell_year < sk.post_year))
{
  print_data_in_record(rk,g,f);
}
if((rk.sell_year == sk.pre_year) || (rk.sell_year == sk.post_year))
{
  if((rk.sell_mon > sk.pre_mon) || (rk.sell_mon < sk.post_mon))
  {
  print_data_in_record(rk,g,f);
  }
}
if((rk.sell_year == sk.pre_year) || (rk.sell_year == sk.post_year))
{
  if((rk.sell_mon == sk.pre_mon) || (rk.sell_mon == sk.post_mon))
  {
    if((rk.sell_day >= sk.pre_day)||(rk.sell_day <= sk.post_day))
      print_data_in_record(rk,g,f);
  }
}
}
fclose(fp);
getch();
}
