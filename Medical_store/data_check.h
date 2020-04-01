int check_date(int a,int b,int *c)
{
    if(*c<100)
        {
            *c= 2000 + *c;
        }
    if((*c>100 && *c<1900) || *c>2200)
        return 0;
    else
        {
            if((a>31 || a<=0) || (b<=0 ||b>12))
            {
                return 0;
            }
        return 1;
        }
}
