//
//  linear.cpp
//  HW 3
//
//  Created by Anica Wang on 2/4/21.
//

//#include <iostream>
//#include <cassert>
//using namespace std;
//
//// Return true if the somePredicate function returns true for at
//// least one of the array elements, false otherwise.
//
//bool somePredicate(double x)
//{
//    return x < 0;
//}

bool anyTrue(const double a[], int n)
{
    if (n <= 0)
    {
        return false;
    }
    if (somePredicate(a[n - 1]) == true)
    {
        return true;
    }
    anyTrue(a, n - 1);
    return false;
}

// Return the number of elements in the array for which the
// somePredicate function returns true.
int countTrue(const double a[], int n)
{
    int count = 0;

    if (n <= 0)
    {
        return 0;
    }

    if (somePredicate(a[n - 1]) == true)
    {
        count++;
    }
    return count + countTrue(a, n - 1);
}

// Return the subscript of the first element in the array for which
// the somePredicate function returns true.  If there is no such
// element, return -1.
int firstTrue(const double a[], int n)
{
    if (n < 1)
    {
        return -1;
    }

    if (somePredicate(a[0]) == true)
    {
        return 0;
    }

    else
    {
        int x = firstTrue(a + 1, n - 1);

        if (x == -1)
        {
            return x;
        }
        return 1 + x;
    }

    return 0;
}

// Return the subscript of the largest element in the array (i.e.,
// return the smallest subscript m such that a[m] >= a[k] for all
// k from 0 to n-1).  If the function is told to examine no
// elements, return -1.
int positionOfMax(const double a[], int n)
{
    if (n < 1)
    {
        return -1;
    }
    if (n == 1)
    {
        return 0;
    }

    int mid = n/2;
    int m = positionOfMax(a, mid);
    int k = positionOfMax(a + mid, n - mid) + mid;

    if(a[m] >= a[k])
    {
        return m;
    }
    else
    {
        return k;
    }
}

// If all n1 elements of a1 appear in the n2 element array a2, in
// the same order (though not necessarily consecutively), then
// return true; otherwise (i.e., if the array a2 is not a
// not-necessarily-contiguous subsequence of a1), return false.
// (Of course, if a1 is empty (i.e., n1 is 0), return true.)
// For example, if a2 is the 7 element array
//    10 50 40 20 50 40 30
// then the function should return true if a1 is
//    50 20 30
// or
//    50 40 40
// and it should return false if a1 is
//    50 30 20
// or
//    10 20 20
bool isIn(const double a1[], int n1, const double a2[], int n2)
{
    if (n1 == 0)
    {
        return true;
    }

    if (n1 > n2 || n2 == 0)
    {
        return false;
    }

    if (a1[0] == a2[0])
    {
        return true && isIn(a1 + 1, n1 - 1, a2 + 1, n2 - 1);
    }
    if ((a1[0] != a2[0]) && (n2 > 0))
    {
        return isIn(a1, n1, a2 + 1, n2 - 1);
    }
    return false;
}

//int main()
//{
//    double a[5] = {1, -2, -3, 4, -5};
//    double b[2] = {-3, 4};
//    if (anyTrue(a, 5))
//    {
//        cout << "Success" << endl;
//    }
//
//    cout << "count true: " << countTrue(a, 5) << endl;
//    cout << "first true: " << firstTrue(a, 5) << endl;
//    cout << "pos of max: " << positionOfMax(a, 5) << endl;
//    cout << "is in: " << isIn(a, 5, b, 2) << endl;
//}

//int main(){
//    double a[] = {1.0,3.0,-1.0,-2.0,5.0,-7.0};
//    double b[] = {1.0,3.0,7.0,2.0,5.0,7.0};
//    assert(anyTrue(a, 6));
//    assert(!anyTrue(b, 6));
//    assert(countTrue(a, 6)==3);
//    assert(countTrue(b, 6)==0);
//    assert(firstTrue(a, 6)==2);
//    assert(firstTrue(b, 6)==-1);
//    assert(positionOfMax(a, 6)==4);
//    assert(positionOfMax(b, 6)==2);
//    assert(positionOfMax(b, 0)==-1);
//    double d[] = {1.0,3.0,1.0,3.0,2.0,5.0,7.0};
//    double c[] = {1.0,3.0};
//    assert(isIn(c, 2, d, 7));
//    assert(!isIn(b, 6, d, 7));
//    assert(!isIn(d, 7, d, 6));
//    cout << "yes" << endl;
//}
//int main()
//{
//    double a[5] = { 1, 50, -200, 1000, -10 };
//    assert(anyTrue(a, 1) == 0);
//    assert(countTrue(a, 1) == 0);
//    assert(firstTrue(a, 1) == -1);
//    assert(positionOfMax(a, 3) == 1);
//    assert(anyTrue(a, 5) == 1);
//    assert(countTrue(a, 5) == 2);
//    assert(firstTrue(a, 5) == 2);
//    assert(positionOfMax(a, 5) == 3);
//    double a2[7] = { 10, 50, 40, 20, 50, 40, 30 };
//    double a1[3] = { 50, 40, 40 };
//    assert(isIn(a1, 0, a2, 7) == 1);
//    assert(isIn(a1, 0, a2, 0) == 1);
//    assert(isIn(a1, 3, a2, 7) == 1);
//    cout << "Passed" << endl;
//}
