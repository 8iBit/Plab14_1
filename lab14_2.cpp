#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}

void updateImage(bool img[N][M],int s,int x,int y)
{
    double A,B,C;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            A=pow(i-x,2);
            B=pow(j-y,2);
            C=sqrt(A+B);
            if(C<=s-1)
            {
                img[i][j]=1;
            }
        }
    }
}

void showImage(const bool img[N][M])
{
    cout << "------------------------------------------------------------------------\n";
    for(int i=0;i<N;i++)
    {
        cout << "|";
        for(int j=0;j<M;j++)
        {
            if (img[i][j]==1)
                cout << "*";
            else 
            {
                cout << " ";
            }
        }
        cout << "|";
        cout << "\n";
    }
    cout << "------------------------------------------------------------------------\n";
}