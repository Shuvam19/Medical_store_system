struct Data
{
    char m_name[20];
    int mfg_day,mfg_mon,mfg_year;
    int exp_day,exp_mon,exp_year;
    int price,quantity;
};
struct record
{
    char m_name[20];
    int exp_day,exp_mon,exp_year;
    int sell_day,sell_mon,sell_year;
    int price,quantity,total_price;
};
struct date
{
    int pre_day,pre_mon,pre_year;
    int post_day,post_mon,post_year;
};
struct curr_date
{
    int day,mon,year;
};
// All the Function's Prototype
void put_in_file(struct Data);
int check_date(int,int,int *);
void print_layout();
void print_data(struct Data,int,int);
struct Data search_medicine(char [],int *);
void record_in_file(struct record);
void print_record_layout();
void show_stock_record();
void make_the_bill(struct record new);
void print_data_in_record(struct record,int,int);
struct Data search_medicine_extra(char[],int);
int check_greater_date(struct Data,struct Data);
void search_medicine_stock();
