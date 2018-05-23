/* program fibonacci
 the program generate fibonacci numbers
 f(0) = 0
 f(1) = 1
 f(n) = f(n-1) + f(n-2) for n>1
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

main()
{
 int f[100];
 int i, j, key;
 char prime;

 f[0] = 0;
 f[1] = 1;

 for (i=2; i<=40; i=i+1)
   { f[i] = f[i-1] + f[i-2];
/*   check for prime numbers */
     key =0;
     for (j=2; j< f[i-1]; j=j+1)
       {if (f[i] == (f[i]/j)*j)
          {key=1; break;}
       };
     cout << setw(3) << i << setw(12)<< f[i];
     if(key == 0)
       {cout << "  prime" << endl;}
       else {cout << endl;}
 }
    return 0;
}
