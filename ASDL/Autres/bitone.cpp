#include <iostream>
using namespace std;

int bitone(int T[], int n) {
  int deb = 0, mil, fin = n-1;

  while (deb <= fin) {
    mil = (deb + fin) / 2;
    cout<<"t[mil]="<<T[mil]<<"et"<<T[mil+1]<<endl;
    if (T[mil] < T[mil+1]) {
      deb = mil+1;
    } else {
      fin = mil-1;
    }
  }
  return T[deb];  
}

int main()
{
  int n1 = 6;
  int T1[n1] = {5,6,8,9,8,4};

  int n2 = 4;
  int T2[n2] = {2,5,6,8};

  int n3 = 5;
  int T3[n3] = {9,7,6,4,3};

  int n4 = 6;
  int T4[n4] = {5,6,8,9,8,4};
  
  int n5 = 1;
  int T5[n5] = {-1};
  
  cout << bitone(T1,n1) << endl;
  cout << bitone(T2,n2) << endl;
  cout << bitone(T3,n3) << endl;
  cout << bitone(T4,n4) << endl;
  cout << bitone(T5,n5) << endl;
  
  return 0;
}
