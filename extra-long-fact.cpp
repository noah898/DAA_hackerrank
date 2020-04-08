#include <bits/stdc++.h>

using namespace std;
#define MAX 150

int mul(int x, int res[],int size);

// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {
    int res[MAX];
    res[0] =1;
    int size =1;

    for(int x=2; x<=n;x++)
    {
       size = mul(x,res,size);
    }

    for(int i=size-1; i>=0; i--)
        cout<<res[i];
}

int mul(int x, int res[],int size)
{
    int carry =0;

    for(int i=0; i<size; i++)
    {
        int product = res[i]*x + carry;
        res[i] = product % 10;
        carry = product/10;
    }

    while(carry)
    {
        res[size] = carry%10;
        carry = carry/10;
        size++;
    }
    return size;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}