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
            /*if(p%7==0 /*|| work from here )
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
                } */
        }
    fclose(fp);
    getch();
}




// It displays the data in range of Days
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


void show_sold_stock()
{
    struct record rk;
    FILE *fp;
    int g=3,f=1;
    system("cls");
    print_record_layout();
    fp = fopen("record.txt","r");
    while(fscanf(fp,"%s %d %d %d %d %d %d %d %d %d ",&rk.m_name,&rk.exp_day,&rk.exp_mon,&rk.exp_year,&rk.sell_day,&rk.sell_mon,&rk.sell_year,&rk.price,&rk.quantity,&rk.total_price)!= EOF)
        {
            print_data_in_record(rk,g++,f++);
        }
    getch();
}



void show_expiring()
{
    int g=3,f=1,d=0;
    FILE *fp,*fp1,*fp2;
    struct Data new,rc;
    struct record rk;
    fp = fopen("sk.txt","r");
    system("cls");
    print_layout();
    gotoxy(20,10);
    while(fscanf(fp,"%s %d %d %d %d %d %d %d %d ",&new.m_name,&new.mfg_day,&new.mfg_mon,&new.mfg_year,&new.exp_day,&new.exp_mon,&new.exp_year,&new.price,&new.quantity)!= EOF)
        {
            d=0;
            fp1 = fopen("sk.txt","r");
            while(fscanf(fp1,"%s %d %d %d %d %d %d %d %d ",&rc.m_name,&rc.mfg_day,&rc.mfg_mon,&rc.mfg_year,&rc.exp_day,&rc.exp_mon,&rc.exp_year,&rc.price,&rc.quantity)!= EOF)
                {
                    if(check_greater_date(new,rc))
                    {
                        d++;
                    }
                }
            fclose(fp1);
            fp2 = fopen("record.txt","r");
            while(fscanf(fp2,"%s %d %d %d %d %d %d %d %d %d ",&rk.m_name,&rk.exp_day,&rk.exp_mon,&rk.exp_year,&rk.sell_day,&rk.sell_mon,&rk.sell_year,&rk.price,&rk.quantity,&rk.total_price)!= EOF)
                {
                    if(!strcmp(new.m_name,rk.m_name))
                    {
                        new.quantity = new.quantity - rk.quantity;
                    }
                }
            fclose(fp1);
            print_data(new,d+g,d+f);
        }
    getch();
}
