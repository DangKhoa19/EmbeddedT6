#include<iostream>
using namespace std;


class A
{
    public:
    void Xuat()
    {
        cout<<"Ai keu toi day co A day !!!";
    }
};


class B: public A
{
    public:
    void Xuat()
    {
        cout<<"Ai keu toi day co B day !!!";
    }
};

int main()
{
    A *x = new B;
    x->Xuat();
    system("pause");
    return 0;
}