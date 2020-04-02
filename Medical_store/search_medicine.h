void search_medicine_stock()
{
    char f,name[20];
    int c=0,d=0;
    int g=21;
    system("cls");
    gotoxy(8,1);
    printf("Enter Name : ");
    while(c!=-84)
        {
            gotoxy(g++,1);
            f=getch();
            c = f - 'a';
            if(c==-89)
                {
                    g=g-2;
                    d--;
                    name[d] = '\0';
                    search_medicine_extra(name,d-1);
                }
            else if(c==-65)
                {
                    g=g-1;
                }
            else
                {
                    name[d++] = f;
                    name[d] = '\0';
                    search_medicine_extra(name,d-1);
                }
        }
}


struct Data search_medicine(char name[],int *p)
 {
     FILE *fp;
     int c=1;
     struct Data new;
     while(c!=0)
        {
            fp = fopen("sk.txt","r");
            while(fscanf(fp,"%s %d %d %d %d %d %d %d %d ",&new.m_name,&new.mfg_day,&new.mfg_mon,&new.mfg_year,&new.exp_day,&new.exp_mon,&new.exp_year,&new.price,&new.quantity)!= EOF)
                {
                    if(!strcmp(name,new.m_name))
                    {
                        *p = 0;
                        return new;
                    }
                }
            c=0;
            fclose(fp);
        }
  }


struct Data search_medicine_extra(char name[],int x)
{
    FILE *fp;
    struct Data new;
    int g=3,f=1;
    fp=fopen("sk.txt","r");
    system("cls");
    gotoxy(21,1);
    printf("%s",name);
    gotoxy(8,1);
    printf("Enter Name : ");
    print_layout();
    while(fscanf(fp,"%s %d %d %d %d %d %d %d %d ",&new.m_name,&new.mfg_day,&new.mfg_mon,&new.mfg_year,&new.exp_day,&new.exp_mon,&new.exp_year,&new.price,&new.quantity)!= EOF)
        {
            int d=0;
            char sub[20];
            while(d<=x)
                {
                    sub[d] = new.m_name[d];
                    d++;
                }
            sub[d]='\0';
            if(!strcmp(sub,name))
                {
                    print_data(new,g++,f++);
                }
        }
    fclose(fp);
}
