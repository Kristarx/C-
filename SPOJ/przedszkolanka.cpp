#include<iostream>
using namespace std;
int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;++i)
    {
        int a,b;
        cin>>a;
        cin>>b;

            int	w=a*b;
            while (b!=0)
            {
                int	c = a % b;
                a = b;
                b = c;
            }

            cout<<w/a << endl;
    }
}
