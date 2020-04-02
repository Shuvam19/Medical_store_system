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



void print_data_in_record(struct record new,int g,int f)
{
    gotoxy(3,g);
    printf("%d",f);
    gotoxy(6,g);
    printf("||");
    gotoxy(10,g);
    printf("%s",new.m_name);
    gotoxy(24,g);
    printf("||");
    gotoxy(27,g);
    printf("%d/%d/%d",new.sell_day,new.sell_mon,new.sell_year);
    gotoxy(38,g);
    printf("||");
    gotoxy(41,g);
    printf("%d/%d/%d",new.exp_day,new.exp_mon,new.exp_year);
    gotoxy(52,g);
    printf("||");
    gotoxy(56,g);
    printf("%d",new.price);
    gotoxy(59,g);
    printf("||");
    gotoxy(64,g);
    printf("%d",new.quantity);
    gotoxy(69,g);
    printf("||");
    gotoxy(74,g);
    printf("%d",new.total_price);
}



void print_record_layout()
{
    gotoxy(1,2);
    printf("Sr.no");
    gotoxy(6,2);
    printf("||");
    gotoxy(10,2);
    printf("Medicine Name");
    gotoxy(24,2);
    printf("||");
    gotoxy(27,2);
    printf("Manuf Date");
    gotoxy(38,2);
    printf("||");
    gotoxy(41,2);
    printf("Expiry Date");
    gotoxy(52,2);
    printf("||");
    gotoxy(54,2);
    printf("Price");
    gotoxy(59,2);
    printf("||");
    gotoxy(61,2);
    printf("Quantity");
    gotoxy(69,2);
    printf("||");
    gotoxy(71,2);
    printf("Tot Price");
}



void record_in_file(struct record rk)
 {
     FILE *fp;
     fp = fopen("record.txt","a");
     fprintf(fp,"%s %d %d %d %d %d %d %d %d %d \n",rk.m_name,rk.exp_day,rk.exp_mon,rk.exp_year,rk.sell_day,rk.sell_mon,rk.sell_year,rk.price,rk.quantity,rk.total_price);
     fclose(fp);
 }
