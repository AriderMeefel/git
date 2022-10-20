#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if (n>9)
    cout<<"Error"<<endl;
    else
    {
        for(int i = 1;i <= n;i++)
        cout<<"HelloRobomaster!"<<endl;
    }
    return 0;
}
