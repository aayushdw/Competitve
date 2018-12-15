#include <iostream>

       #include <iomanip>

       #include <cmath>

        

       // triangle (same shape as 30,40,50 !)

       const double a = 3; // shortest leg

       const double b = 4; // longest  leg

       const double c = 5; // hypotenuse

        

       // |\.

       // | \.

       // | \.

       // b  c

       // |   \.

       // |   \.

       // +--a-\.

        

       const double PI = 3.1415926535897932384626433832795028;

        

       // compute angle in upper left corner

       double getAlpha(double x, double y)

       {

         // tan(alpha) = opposite / adjacent = X / Y

         // alpha      = arctan(X / Y)

         // where X = x and Y = b - y

         return atan(x / (b - y));

       }

        

       // compute angle in lower right corner

       double getBeta(double x, double y)

       {

         // similar to getAlpha:

         // tan(beta) = opposite / adjacent = Y / X

         // beta      = arctan(Y / X)

         // where X = a - x and Y = y

         return atan(y / (a - x));

       }

        

       // return probability of leaving the triangle

       double getProbability(double x, double y)

       {

         // the of all angles in a triangle is pi:

         // pi =         otherAlpha +        otherBeta + gamma

         // but the big triangle must fulfil the same condition, so

         // pi = alpha + otherAlpha + beta + otherBeta + pi/2

         // therefore the difference is

         // 0  = gamma - alpha - beta - pi/2

         // gamme = alpha + beta + pi/2

         auto gamma = PI/2 + getAlpha(x, y) + getBeta(x, y);

         // each direction is equally likely: "exit probability" = gamma / full circle

         // and a full circle has 360 degrees => 2pi

         return gamma / (2 * PI);

       }

        

       int main()

       {

         // display 10 digits

         std::cout << std::fixed << std::setprecision(10);

        

         double epsilon = 0.01;

         //std::cin >> epsilon;

        

         // add all percentages

         double sum = 0;

         unsigned long long numPoints = 0;

         for (double x = epsilon; x < a; x += epsilon)

         {

           auto height = b - x * b/a;

           for (double y = epsilon; y < height; y += epsilon)

           {

             auto current = getProbability(x, y);

             sum += current;

        

             numPoints++;

             //if (numPoints % 10000000 == 0)

               //std::cout << numPoints << std::endl;

           }

         }

        

         // compute average percentage

         auto result = sum / numPoints;

         // ==> uncomment the following line to see my approximate result

         //std::cout << result << std::endl;

        

         // I reduced the triangle's dimensions from 30,40,50 to 3,4,5 (doesn't affect the probability)

         // and Wolfram Alpha double-integrated to

         // 0.5 + log((2^16 3^4 sqrt(3/5))/5^12) / 12pi

         // (actually Wolfram Alpha's output contained large numbers: 5308416 = 2^16 3^4 and 244140625 = 5^12)

         // I have no clue how Wolfram Alpha found that strange equation

         // but the resulting value matched my approximation and it's indeed correct

         result = 0.5 + log((pow(2, 16) * pow(3, 4) * sqrt(3.0 / 5)) / pow(5, 12)) / (12*PI);

         // and here comes the accurate result

         std::cout << result << std::endl;

         return 0;

       }