void sell_medicine()
{
    struct Data search;
    struct record rc;
    int quantity,c=0,p=1;
    char ch,ch1;
    char name[20];
    system("cls");
    while(p!=0)
        {
            gotoxy(8,3);
            printf("Enter Name : ");
            gotoxy(20,3);
            scanf("%s",&name);
            search = search_medicine(name,&p);
            if(p==1)
                {
                    gotoxy(10,10);
                    printf("Name not Found");
                }
        }
    system("cls");
    gotoxy(10,3);
    printf("Name : ");
    gotoxy(30,3);
    printf("%s",search.m_name);
    strcpy(rc.m_name,search.m_name);
    gotoxy(10,4);
    printf("Expiry :");
    gotoxy(30,4);
    printf("%d/%d/%d",search.exp_day,search.exp_mon,search.exp_year);
    rc.exp_day = search.exp_day;
    rc.exp_mon = search.exp_mon;
    rc.exp_year = search.exp_year;
    gotoxy(10,5);
    printf("Price : ");
    gotoxy(30,5);
    printf("%d",search.price);
    rc.price = search.price;
    gotoxy(10,6);
    printf("Quantity : ");
    gotoxy(10,7);
    printf("Total Price : ");
    gotoxy(10,8);
    printf("Date of sell : ");
    gotoxy(30,6);
    scanf("%d",&rc.quantity);
    gotoxy(30,7);
    printf("%d",(search.price * rc.quantity));
    rc.total_price = (search.price * rc.quantity);
    while(c!=1)
        {
            gotoxy(30,8);
            printf("  /  /    ");
            gotoxy(30,8);
            scanf("%d",&rc.sell_day);
            gotoxy(33,8);
            scanf("%d",&rc.sell_mon);
            gotoxy(36,8);
            scanf("%d",&rc.sell_year);
            c=check_date(rc.sell_day,rc.sell_mon,&rc.sell_year);
        }
    fflush(stdin);
    gotoxy(10,9);
    printf("Do you want to Record this [Y/N] : ");
    gotoxy(50,9);
    scanf("%c",&ch1);
    if(ch1 == 'Y' || ch1 == 'y')
        {
            record_in_file(rc);
            gotoxy(30,10);
            printf("Record Updated Successfully");
        }
    getch();
}
