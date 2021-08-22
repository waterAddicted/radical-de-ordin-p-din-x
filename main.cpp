#include <iostream>
#include <cmath>
using namespace std;


double ridicare_la_putere(double x,int p)
{
    double r=1;
    while(p!=0)
    {
        if(p%2==1) r=r*x;
        x=x*x;
        p/=2;
    }
    return r;
}


double radical_de_ordin_p(double x,double eps,int p)
{
    double st=0;
    double dr=x;
    double mij=(st+dr)/2;
    double pmij=ridicare_la_putere(mij,p);
    while(fabs(pmij-x)>eps)
    {
        if(pmij<x) st=mij;
        else dr=mij;
        mij=(dr+st)/2;
        pmij=ridicare_la_putere(mij,p);
    }
    return mij;
}

int main()
{
    double x;
    double eps=0.00001;
    int p;
    cin>>x>>p;
    cout<<radical_de_ordin_p(x,eps,3);
}