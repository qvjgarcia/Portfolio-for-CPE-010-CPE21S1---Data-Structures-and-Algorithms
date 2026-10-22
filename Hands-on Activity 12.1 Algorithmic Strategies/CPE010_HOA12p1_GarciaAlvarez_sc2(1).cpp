#include <iostream>
#include <algorithm>


int getMinSteps(int n){

    int* dp = new int[n + 1], i;
    dp[1] = 0;

    for( i = 2 ; i <= n ; i ++ )
    {
        dp[i] = 1 + dp[i-1];
        if( i % 2 == 0 ) dp[i] = std::min( dp[i] , 1+ dp[i/2] );
        if( i % 3 == 0 ) dp[i] = std::min( dp[i] , 1+ dp[i/3] );
    }
    return dp[n];
}

int main() {

    int n = 10;
    std::cout << "Minimum steps for n: " <<n<< " to 1: " << getMinSteps(n) << std::endl;

    return 0;
}