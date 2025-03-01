// Superphone
// AIO 2007
// https://orac.amt.edu.au/cgi-bin/train/problem.pl?problemid=337
// Bottom Up Approach
#include <cstdio>
#include <algorithm> // min

using namespace std;

int N, left[100005], flor[100005], right[100005], dp[100005][2];

int main() {
    // divert IO from files to stdio
    freopen("phonein.txt", "r", stdin);
    freopen("phoneout.txt", "w", stdout);

    scanf("%d", &N);
    for (int i = 1; i <= N-1; i++) {
        scanf("%d %d %d", &left[i], &flor[i], &right[i]);
    }
    scanf("%d", &flor[N]);
    // base cases
    dp[1][0] = 0; // technically don't need this line bc array is initialised to 0 anyway
    dp[1][1] = flor[1];
    
    // recurrence
    for (int i = 2; i <= N; i++) {
        dp[i][0] = min(
            dp[i-1][1] + right[i-1], 
            dp[i-1][0] + left[i-1] + flor[i]
        );
        dp[i][1] = min(
            dp[i-1][0] + left[i-1], 
            dp[i-1][1] + right[i-1] + flor[i]
        );
    }
    printf("%d\n", dp[N][1]);
    return 0;
}

// Mortal Kombat Tower
// https://codeforces.com/problemset/problem/1418/C
// Top down DP approach
#include<cstdio>
#include<algorithm> // min
using namespace std;
int cache[200005][2];
int arr[200005];
int t, n;
 
int dp(int x, int p) {
    if (cache[x][p] != -1)
        return cache[x][p];
    
    if (x >= n-2 && p == 1)
        return cache[x][p] = 0;
    
    if (p == 0 && x == n-1)
        return cache[x][p] = arr[n-1];
    
    if (p == 1)
        return cache[x][p] = min(dp(x+1, 0), dp(x+2, 0));
    
    return cache[x][p] = min(
        arr[x] + dp(x+1, 1),
        arr[x] + arr[x+1] + dp(x+2, 1)
    );
    
}
 
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        
        for (int i = 0; i < n; i++) {
            // init cache to -1 bc 0 is a legal dp value
            cache[i][0] = -1;
            cache[i][1] = -1;
            // read into array
            scanf("%d", &arr[i]);
        }
        printf("%d\n", dp(0, 0));
    }
    
}