void get_data()
{
    struct Data sk;
    char ch,ch1;
    int c=0;
    system("cls");
    gotoxy(10,2);
    printf("Enter the name of Medicine: ");
    gotoxy(10,3);
    printf("Enter the Manufacture Date: ");
    gotoxy(47,3);
    printf("/");
    gotoxy(50,3);
    printf("/");
    gotoxy(10,4);
    printf("Enter the Expiry Date: ");
    gotoxy(47,4);
    printf("/");
    gotoxy(50,4);
    printf("/");
    gotoxy(10,5);
    printf("Enter the Price of Medicine: ");
    gotoxy(10,6);
    printf("Enter the Quantity of Medicine: ");
    gotoxy(45,2);
    scanf("%s",&sk.m_name);
    while(c!=1)
        {
            gotoxy(45,3);
            printf("  /  /    ");
            gotoxy(45,3);
            scanf("%d",&sk.mfg_day);
            gotoxy(48,3);
            scanf("%d",&sk.mfg_mon);
            gotoxy(51,3);
            scanf("%d",&sk.mfg_year);
            c=check_date(sk.mfg_day,sk.mfg_mon,&sk.mfg_year);
        }
        c=0;
        while(c!=1)
            {
                gotoxy(45,4);
                printf("  /  /    ");
                gotoxy(45,4);
                scanf("%d",&sk.exp_day);
                gotoxy(48,4);
                scanf("%d",&sk.exp_mon);
                gotoxy(51,4);
                scanf("%d",&sk.exp_year);
                c=check_date(sk.exp_day,sk.exp_mon,&sk.exp_year);
            }
        gotoxy(45,5);
        scanf("%d",&sk.price);
        gotoxy(45,6);
        scanf("%d",&sk.quantity);
        gotoxy(10,7);
        fflush(stdin);
        printf("Do You Want To Save This Data [Y/N]: ");
        gotoxy(50,7);
        scanf("%c",&ch1);
        fflush(stdin);
        if(ch1=='Y' || ch1=='y')
            {
                gotoxy(20,8);
                put_in_file(sk);
                printf("Saved Successfully");
            }
        gotoxy(10,9);
        printf("Do You Want To Add Another Data [Y/N]: ");
        gotoxy(50,9);
        scanf("%c",&ch);
        if(ch=='Y' || ch=='y')
            {
                get_data();
            }
}

void put_in_file(struct Data new)
{
    FILE *fp;
    fp = fopen("sk.txt","a");
    fprintf(fp,"%s %d %d %d %d %d %d %d %d \n",new.m_name,new.mfg_day,new.mfg_mon,new.mfg_year,new.exp_day,new.exp_mon,new.exp_year,new.price,new.quantity);
    fclose(fp);
}

