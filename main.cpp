#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

class monom
{
    int grad;
    float coef;
public:
    monom(int x,float y)//constructor
    {
        grad=x;
        coef=y;
    }
    monom(float y)//constructor
    {
        grad=0;
        coef=y;
    }
    ~monom()//destructor
    {
        grad=0;
        coef=0;
    }
    monom (const monom&ob)//cc
    {
        grad=ob.grad;
        coef=ob.coef;
    }
    friend istream &operator>>(istream &in, monom &ob);
    friend ostream &operator<<(ostream &out, const monom &ob);
    monom& operator=(const monom &ob);
};

class polinom
{
    int nr_monoame;
    monom *m;
public:
    polinom(int z)//constructor
    {
        nr_monoame=z;
    }
    ~polinom()//destructor
    {
        nr_monoame=0;
    }
    polinom (const polinom&m)//cc
    {
        nr_monoame=m.nr_monoame;
    }
    friend istream &operator>>(istream &in, polinom &m);
    friend ostream &operator<<(ostream &out, const polinom &m);
    polinom& operator=(const polinom &m);

};
class polinom_i:public polinom
{
    int i;
public:
    polinom_i(const polinom_i&ob):polinom(ob)//cc
    {
        i=ob.i;
    }
    friend istream &operator>>(istream &in, polinom_i &ob);
    friend ostream &operator<<(ostream &out, const polinom_i &ob);
    polinom_i& operator=(const polinom_i &ob);

};
//conform criteriului lui Einstein, daca exista p, un nr prim, care sa divida toti coeficientii unui
//polinom in afara de primul si ultimul, atunci polinomul e ireductibil
void prim(int p)
{
    int ok=0;
    for(int i=2;i<=p/2;i++)
        if(p%i==0)
            ok++;
}
class polinom_r: public polinom
{
    int j;
public:
    polinom_r(const polinom_r&ob):polinom(ob)//cc
    {
        j=ob.j;
    }
    friend istream &operator>>(istream &in, polinom_r &ob);
    friend ostream &operator<<(ostream &out, const polinom_r &ob);
    polinom_r& operator=(const polinom_r &ob);
};

istream &operator>>(istream &in, monom &ob)
{
    in>>ob.grad;
    in>>ob.coef;
    return in;
}
ostream &operator<<(ostream &out, const monom &ob)
{
    out<<ob.grad<<" ";
    out<<ob.coef<<endl;
    return out;
}
monom& monom:: operator=(const monom &ob)
{
    if(this ==&ob)
        return *this;
    grad=ob.grad;
    coef=ob.coef;
    return *this;
}
istream &operator>>(istream &in, polinom &m)
{
    in>>m.nr_monoame;
    return in;
}
ostream &operator<<(ostream &out, const polinom &m)
{
    out<<m.nr_monoame<<endl;
    return out;
}
polinom& polinom:: operator=(const polinom &m)
{
    if(this ==&m)
        return *this;
    nr_monoame=m.nr_monoame;
    return *this;
}
istream &operator>>(istream &in, polinom_i &ob)
{
    in>>((polinom &)ob);
    in>>ob.i;
    return in;
}
ostream &operator<<(ostream &out, const polinom_i &ob)
{
    out<<((polinom &)ob);
    out<<ob.i;
    return out;
}
polinom_i& polinom_i:: operator=(const polinom_i &ob)
{
    if(this ==&ob)
        return *this;
    i=ob.i;
    return *this;
}
istream &operator>>(istream &in, polinom_r &ob)
{
    in>>((polinom &)ob);
    in>>ob.j;
    return in;
}
ostream &operator<<(ostream &out, const polinom_r &ob)
{
    out<<((polinom &)ob);
    out<<ob.j;
    return out;
}
polinom_r& polinom_r:: operator=(const polinom_r &ob)
{
    if(this ==&ob)
        return *this;
    j=ob.j;
    return *this;
}
int main()
{

}
