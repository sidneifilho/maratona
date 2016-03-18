// A Divide and Conquer Program to find maximum rectangular area in a histogram
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll N;
ll hist[100005];
ll st[262153];   // Allocate memory for segment tree h = log2(N), size = 2*pow(2,h)-1
 
// A utility function to find minimum of three integers
ll max(ll x, ll y, ll z){  return max(max(x, y), z); }
 
// A utility function to get minimum of two numbers in hist[]
ll minVal(ll i, ll j)
{
    if (i == -1) return j;
    if (j == -1) return i;
    return (hist[i] < hist[j])? i : j;
}
 
// A utility function to get the middle index from corner indexes.
ll getMid(ll s, ll e){ return s + (e -s)/2; }
 
/*  A recursive function to get the index of minimum value in a given range of
    indexes. The following are parameters for this function.
 
    hist   --> Input array for which segment tree is built
    st    --> Pointer to segment tree
    index --> Index of current node in the segment tree. Initially 0 is
             passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment represented by
                 current node, i.e., st[index]
    qs & qe  --> Starting and ending indexes of query range */
ll RMQUtil(ll ss, ll se, ll qs, ll qe, ll index)
{
    // If segment of this node is a part of given range, then return the
    // min of the segment
    if (qs <= ss && qe >= se)
        return st[index];
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return -1;
 
    // If a part of this segment overlaps with the given range
    ll mid = getMid(ss, se);
    return minVal(RMQUtil(ss, mid, qs, qe, 2*index+1), RMQUtil(mid+1, se, qs, qe, 2*index+2));
}
 
// Return index of minimum element in range from index qs (quey start) to
// qe (query end).  It mainly uses RMQUtil()
ll RMQ(ll qs, ll qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > N-1 || qs > qe)
    {
        cout << "Invalid Input";
        return -1;
    }
 
    return RMQUtil(0, N-1, qs, qe, 0);
}
 
// A recursive function that constructs Segment Tree for hist[ss..se].
// si is index of current node in segment tree st
ll constructSTUtil(ll ss, ll se, ll si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se) return (st[si] = ss);
 
    // If there are more than one elements, then recur for left and
    // right subtrees and store the minimum of two values in this node
    ll mid = getMid(ss, se);
    st[si] =  minVal(constructSTUtil(ss, mid, si*2+1), constructSTUtil(mid+1, se, si*2+2));
    return st[si];
}
 
// A recursive function to find the maximum rectangular area.
// It uses segment tree 'st' to find the minimum value in hist[l..r]
ll getMaxAreaRec(ll l, ll r)
{
    // Base cases
    if (l > r)  return INT_MIN;
    if (l == r)  return hist[l];
 
    // Find index of the minimum value in given range
    // This takes O(Logn)time
    ll m = RMQ(l, r);
 
    /* Return maximum of following three possible cases
       a) Maximum area in Left of min value (not including the min)
       a) Maximum area in right of min value (not including the min)
       c) Maximum area including min */
    return max(getMaxAreaRec(l, m-1), getMaxAreaRec(m+1, r), (r-l+1)*(hist[m]) );
}
 
// Driver program to test above functions
int main()
{
    while(scanf("%llu", &N) != -1 && N != 0){

        for (int i = 0; i < N; ++i)
        {
            scanf("%llu", &hist[i]);
        }

        // Build segment tree from given array. This takes O(n) time
        constructSTUtil(0, N-1, 0);
     
        // Use recursive utility function to find the maximum area
        printf("%llu\n", getMaxAreaRec(0, N-1));
    }

    return 0;
}