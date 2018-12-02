#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int S, N;
    cin >> S >> N;
    
    int n[N];
    
    for (int i = 0; i < N; ++i)
        cin >> n[i];
        
    int d[S+1] = {0}; 
    
    for (int i = 1; i <= S; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (n[j] <= i) 
                d[i] = max(d[i], d[ i - n[j] ] + n[j]);
        }
    }   
    
    cout << d[S];
}
