#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cassert>
using namespace std;

struct BigInteger
{
    static const int maxn = 1000;
    static const int maxval = 10;
    int top;
    int numb[maxn];
    BigInteger()
    {
        top=0;
        memset(numb,0,sizeof(numb));
    }
    BigInteger(string str)
    {
        memset(numb,0,sizeof(numb));
        top=str.length()-1;
        for (int i=0;i<str.length();i++)
            numb[str.length()-i-1]=numb[str.length()-i-1]*10+str[i]-'0';
    }
    void Read()
    {
        string str;
        cin>>str;
        (*this) = BigInteger(str);
    }
    void Print()
    {
        printf("%d",numb[top]);
        for (int i=top-1;i>=0;i--)
            printf("%04d",numb[i]);
        printf("\n");
    }
    void Print_detail()
    {
        cout<<"TOP:"<<top<<endl;
        cout<<"{";
        for (int i=0;i<=top;i++)
            cout<<numb[i]<<",";
        cout<<"}"<<endl;
    }
};
istream & operator >> (istream &in,BigInteger& num)
{
    string str;
    in>>str;
    num = BigInteger(str);
    return in;
}
ostream & operator << (ostream &out,BigInteger &num)
{
    char buf[10];
    out<<num.numb[num.top];
    for (int i=num.top-1;i>=0;i--)
    {
        sprintf(buf,"%d",num.numb[i]);
        out<<buf;
    }
    return out;
}
BigInteger A,B,C;
BigInteger operator +(BigInteger &num1,BigInteger &num2)
{
    BigInteger ret;
    ret.top=max(num1.top,num2.top);
    for (int i=0;i<=ret.top;i++)
    {
        ret.numb[i] = (ret.numb[i] + num1.numb[i] + num2.numb[i]);
        if (ret.numb[i]>=BigInteger::maxval)
            ret.numb[i]-=BigInteger::maxval,ret.numb[i+1]++;
    }
    if (ret.numb[ret.top+1])ret.top++;
    return ret;
}

bool operator >=(BigInteger &num1,BigInteger &num2)
{
    if (num1.top!=num2.top)
        return num1.top>num2.top;
    for (int i=num1.top;i>=0;i--)
    {
        if (num1.numb[i]!=num2.numb[i])
            return num1.numb[i] > num2.numb[i];
    }
    return true;
}

BigInteger operator -(BigInteger &num1,BigInteger &num2)
{
    assert(num1 >= num2);
    BigInteger ret;
    ret.top=num1.top;
    for (int i=0;i<=ret.top;i++)
        ret.numb[i] = num1.numb[i] - num2.numb[i];
    for (int i=0;i<=ret.top;i++)
        if (ret.numb[i]<0)
            ret.numb[i]+=BigInteger::maxval,ret.numb[i+1]--;
    while (ret.top && !ret.numb[ret.top])
        ret.top--;
    return ret;
}
BigInteger operator *(BigInteger &num1,BigInteger &num2)
{
    BigInteger ret;
    ret.top = num1.top + num2.top;
    for (int i=0;i<=num1.top;i++)
        for (int j=0;j<=num2.top;j++)
        {
            ret.numb[i+j] += num1.numb[i] * num2.numb[j];
            ret.numb[i+j+1] += ret.numb[i+j]/BigInteger::maxval;
            ret.numb[i+j] %= BigInteger::maxval;

        }
    for (int i=0;i<=ret.top;i++)
    {
        ret.numb[i+1] += ret.numb[i]/BigInteger::maxval;
        ret.numb[i] %= BigInteger::maxval;
    }
    if (ret.numb[ret.top+1])ret.top++;
    return ret;
}
BigInteger operator /(BigInteger &num1,int &num2)
{
    BigInteger ret;
    int i,x=0;
    for(i=num1.top;i>=0;i--)
    {
        ret.numb[i]=(x*10+num1.numb[i])/num2;
        x=(x*10+num1.numb[i])%num2;
    }
    ret.top=num1.top;
    while(ret.numb[ret.top]==0 && ret.top>1)
        ret.top--;
    return ret;
}
int Mod(BigInteger &num1,int p)
{
    int ret=0;
    for (int i=num1.top;i>=0;i--)
        ret = (ret*BigInteger::maxval + num1.numb[i])%p;
    return ret;
}

int main()
{
    BigInteger A,B,C;
    cin>>A>>b;
    //C=A/B;
    //cout<<C;
    int ret;
    C=A/b;
    cout<<C<<endl;
    return 0;
}
