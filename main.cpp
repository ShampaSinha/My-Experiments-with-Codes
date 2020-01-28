/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<bits/stdc++.h> 
using namespace std; 
#define INFINITY_ 9999999
int floorSqrt(int n) 
{ 
   int i = 0, units_digit, j; //Loop counters
   int cur_divisor=0;
   int quotient_units_digit=0;
   int cur_quotient=0;
   int cur_dividend=0;
   int cur_remainder=0; 
   int a[10]={0}; 
    
    
    //Dividing the number into periods
  while (n > 0)
    {
      a[i] = n % 100;
      n = n / 100;
      i++;
    }
  i--; //Last index of array of periods
   
   //Start long division from last period (j=i)
        
             for (j = i; j >= 0; j--) {
        cur_remainder = INFINITY_; //initialised to a maximum value
        cur_dividend = cur_dividend * 100 + a[j]; //including next period in new dividend
        
        //in first loop check for perfect square closest to first period c*c when k=10
            //in subsequent loops check which digit to annexe with divisor
            
        for (units_digit = 0; units_digit <= 9; units_digit++) {
            if (cur_remainder >= cur_dividend - ((cur_divisor * 10 + units_digit) * units_digit) && cur_dividend - ((cur_divisor * 10 + units_digit) * units_digit) >= 0) {
                cur_remainder = cur_dividend - ((cur_divisor * 10 + units_digit) * units_digit);
                quotient_units_digit = units_digit;
            }
        }
            
        
       
        cur_quotient = cur_quotient * 10 + quotient_units_digit; //adding units digit to quotient
        cur_divisor = cur_quotient * 2;  //new divisor is two times quotient 
        
       
        cur_dividend = cur_remainder; //including remainder in new dividend
       
    }
    
    return cur_quotient;
}

   
int main() 
{ 
    int x = 5499025; 
    cout << floorSqrt(x) << endl; 
    return 0; 
} 
