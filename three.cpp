#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int saved1[1000000];

bool isPrime3(int n)
{
   for(int i=2; i<=sqrt(n); i++)
      if(n % i == 0)
         return false;
    if(n % 10 == 3)
       return true;
    return false;
}

bool isNum(int n)
{
   if(saved1[n] != -1)
      return saved1[n];
   if(isPrime3(n))
      return saved1[n] = 1;
   int i;
   for(i=2; i<=sqrt(n); i++)
   {
      if(n%i == 0)
         return saved1[n] = isNum(i) && isNum(n/i);
   }
   return saved1[n] = 0;
}

int main()
{
  int n;
  ifstream in;
  in.open("three.in");
  in >> n;
  while (n != -1)
  {
     for(int i=0; i<1000000; i++)
       saved1[i] = -1;
     if (isNum(n))
        cout << n << " YES" << endl;
     else
        cout << n << " NO" << endl;
    in >> n;
  }
  return 0;
}

