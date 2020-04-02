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


int check_greater_date(struct Data rk,struct Data sk)
{
    if((rk.exp_year > sk.exp_year))
        {
            return 1;
        }
    if((rk.exp_year == sk.exp_year))
        {
            if((rk.exp_mon > sk.exp_mon))
                {
                    return 1;
                }
        }
    if((rk.exp_year == sk.exp_year))
        {
            if((rk.exp_mon == sk.exp_mon))
            {
                if((rk.exp_day > sk.exp_day))
                return 1;
            }
        }
    return 0;
}

