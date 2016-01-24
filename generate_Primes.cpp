/*
 *  Program to find the 3rd, 58th,
 *  and 10,001th prime numbers
 *
 */

#include <iostream>
#include <vector>
 using namespace std;

const long limit = 999999999; //limit for prime searching

/*
 * generate_primes()
 * inputs:
 * first, second, third -> place of the primes
 *                         requested
 * behavior: prints the first, second, third
 *          primes to console
 * output: none
 */
void generate_primes(int first, int second, int third){
    vector<int> primes; //list of sequential primes
    int size; //size of above vector
    bool isPrime = true; //flag for whether a number is prime

    primes.push_back(2);

    for (int i = 3; i < limit; i = i+2)
    {
        size = primes.size();
        isPrime = true;

        for (int j = 0; j < primes.size(); ++j)
        {
            if (i % primes[j]==0)
               {
                   isPrime =false;
                   break;
               }   
        }

        if (isPrime)
        {
            primes.push_back(i);
        }

        if (size >= first && size >= second && size >= third)
        {
            break;
        }

    }

    cout<<"The number "<<first<<" prime number is "<<primes[first-1]<<endl;
    cout<<"The number "<<second<<" prime number is "<<primes[second-1]<<endl;
    cout<<"The number "<<third<<" prime number is "<<primes[third-1]<<endl;

}

int main(int argc, char const *argv[])
{
    generate_primes(3,58,10001);
    return 0;
}
