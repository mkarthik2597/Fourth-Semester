class date
{
    int dd;
    int mm;
    int yyyy;

    int countLeapYears(date d)
    {
        int years = d.yyyy;
        if (d.mm <= 2)
            years--;
        return years / 4 - years / 100 + years / 400;
    }

    int getDifference(date dt1, date dt2)
    {
        const int monthDays[12] = {31, 28, 31, 30, 31, 30,
                                 31, 31, 30, 31, 30, 31};
        long int n1 = dt1.yyyy*365 + dt1.dd;
        for (int i=0; i<dt1.mm - 1; i++)
            n1 += monthDays[i];
        n1 += countLeapYears(dt1);
        long int n2 = dt2.yyyy*365 + dt2.dd;
        for (int i=0; i<dt2.mm - 1; i++)
            n2 += monthDays[i];
        n2 += countLeapYears(dt2);
        return (n1 - n2);
    }


    public:
    date()
    {
        dd=mm=yyyy=0;
    }

    date(int d, int m, int y)
    {
        dd = d;
        mm = m;
        yyyy = y;
    }
    int operator- (date &d)
    {
        return getDifference(*this, d);
    }

  friend ostream& operator<<(ostream& cout,date& d);
};

ostream& operator<<(ostream& cout,date& d)
{
    cout<<d.dd<<"/"<<d.mm<<"/"<<d.yyyy;
    return cout;
}
