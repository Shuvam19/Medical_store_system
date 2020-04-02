#include <stdio.h>
#include <stdlib.h>
#include "gotoxy.h"
#include "data.h"
#include "data_check.h"
#include "printing_format.h"
#include "add_stock.h"
#include "display_data.h"
#include "search_medicine.h"
#include "record_sold_medicine.h"

int main()
{
    int ch=0;
    char f;
    system("cls");
    while(ch!=8)
        {
            system("cls");
            gotoxy(10,3);
            printf("1. Add A Medicine To Your Stock \n");
            gotoxy(10,4);
            printf("2. Show Your Complete Stock \n");
            gotoxy(10,5);
            printf("3. Show stock By Date and Month \n");
            gotoxy(10,6);
            printf("4. Sell any Medicine \n");
            gotoxy(10,7);
            printf("5. Search any medicine in stock \n");
            gotoxy(10,8);
            printf("6. Show the Sold Products \n");
            gotoxy(10,9);
            printf("7. Expiring Medicine");
            gotoxy(10,10);
            printf("8. Exit\n");
            f = getch();
            ch = f - '0';
            switch(ch)
            {
            case 1: get_data();
            break;
            case 2: show_stock();
            break;
            case 3: show_stock_d_m();
            break;
            case 4: sell_medicine();
            break;
            case 5: search_medicine_stock();
            break;
            case 6: show_sold_stock();
            break;
            case 7: show_expiring();
            break;
            }
        }
    return 0;
}
