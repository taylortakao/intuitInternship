/*
 * Program to sort the list:
 * 1,10,5,63,29,71,10,12,44,29,10,-1
 *
 */

#include <vector>
#include <iostream>
 using namespace std;

/*
 * merge()
 * inputs:
 * v -> reference to vector to be sorted about midpoint
 * low -> lower index of to be sorted section
 * high -> upper index of to be sorted section
 * midpoint -> point to be sorted about
 * behavior: sorts the input vector about its midpoint
 * output: none
 */
void merge(vector<int> &v, int low, int high, int midpoint)
{
    int lowstart,highstart, start;
    vector<int> temporary;

    start = lowstart = low;
    highstart = midpoint+1;
    temporary = v;

    while(lowstart <= midpoint && highstart <= high){
        if (temporary[lowstart] < temporary[highstart])
        {
            v[start++] = temporary[lowstart++];
        }else{
            v[start++] = temporary[highstart++];
        }
    }

    while(lowstart <= midpoint){
        v[start++] = temporary[lowstart++];
    }

    while(highstart <= high){
        v[start++] = temporary[highstart++];
    }

    return;
}

/*
 * mergesort()
 * inputs:
 * v -> reference to vector to be sorted
 * low -> lower index of to be sorted section
 * high -> upper index of to be sorted section
 * behavior: sorts the input vector
 * output: none
 */
void mergesort(vector<int> &v, int low, int high)
{
    int midpoint;

    if (low < high)
    {
        midpoint=(low+high)/2;
        mergesort(v,low,midpoint);
        mergesort(v,midpoint+1,high);
        merge(v,low,high,midpoint);
    }

    return;
}


int main(int argc, char const *argv[])
{
    vector<int> v;

    v.push_back(1);
    v.push_back(10);
    v.push_back(5);
    v.push_back(63);
    v.push_back(29);
    v.push_back(71);
    v.push_back(10);
    v.push_back(12);
    v.push_back(44);
    v.push_back(29);
    v.push_back(10);
    v.push_back(-1);


    cout << "unsorted list:";
    for (vector<int>::iterator it = v.begin() ; it != v.end(); ++it)
        cout << ' ' << *it;

    cout << '\n';

    mergesort(v, 0, v.size()-1);

    cout << "sorted list:";
    for (vector<int>::iterator it = v.begin() ; it != v.end(); ++it)
        cout << ' ' << *it;

    cout << '\n';

    return 0;
}