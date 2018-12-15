#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision
#include<math.h>
int main () 
{
	double f;
	f=pow((11+5*pow(5,1.0/2))/2,1.0/5);
	f+=pow((47+21*pow(5,1.0/2))/2,1.0/8);
	f+=pow((18+8*pow(5,1.0/2))/2,1.0/6);
	f-=pow((2207-987*pow(5,1.0/2))/2,1.0/16);
	f-=pow((39603-17711*pow(5,1.0/2))/2,1.0/22);
	f+=pow((199+89*pow(5,1.0/2))/2,1.0/11);
	f+=pow((1860498-832040*pow(5,1.0/2))/2,1.0/30);
	f+=pow((521+233*pow(5,1.0/2))/2,1.0/13);
	f-=pow((322-144*pow(5,1.0/2))/2,1.0/12);
	f-=pow((123-55*pow(5,1.0/2))/2,1.0/10);
	f-=pow((271443-121393*pow(5,1.0/2))/2,1.0/26);
	 std::cout << std::setprecision(12) << f*1000000000 ;
}
