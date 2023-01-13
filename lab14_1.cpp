#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[] ,int N ,double B[])
{
    //mean
    double sumA=0;
    for(int i=0;i<N;i++)
    {
        sumA+=A[i];
    }
    B[0] = sumA/N;

    //S.D.
    double sumB=0;
    double sumC;
    for(int i=0;i<N;i++)
    {
        sumB += pow(A[i]-B[0],2);
        sumC = sumB/N;
    }
    B[1] = sqrt(sumC);

    //G.M.
    double sumD=1;
    for(int i=0;i<N;i++)
    {
        sumD *=A[i];
    }
    B[2] = pow(sumD,1.0/N);

    //H.M.
    double sumE=0;
    for(int i=0;i<N;i++)
    {
        sumE += 1.0/A[i];
    }
    B[3] = N/sumE;

    //find max
    double max=0;
    max=A[0];
    for(int i=1;i<N;i++)
    {
        if(max<A[i])
        {
            max=A[i];
        }
    }
    B[4]=max;

    //find min
    double min;
    min=A[0];
    for (int i=1;i<N;i++)
    {
        if(min>A[i])
        {
            min=A[i];
        }
    }
    B[5]=min;
}