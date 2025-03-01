// Swappable 1
// O(n^2) (too slow) solution
#include <cstdio> // stdio.h
int ans, a[300010], n;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[i] != a[j]) {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
}

// Swappable 2
// O(n log n) solution
#include <cstdio> // stdio.h
#include <algorithm> // std::sort
typedef long long ll;
ll ans, a[300010], n;
int main() {
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    std::sort(a, a+n);
    ll currentLen = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i-1]) {
            currentLen++;
        } else {
            ans += (currentLen)*(currentLen-1)/2;
            currentLen = 1;
        }
    }
    ans += (currentLen)*(currentLen-1)/2;

    ans = n*(n-1)/2 - ans;
    printf("%lld\n", ans);
}

// Unabalanced 1
// O(26*n^3) (too slow) solution
#include <cstdio>
#include <cstring>
char str[100010];
int freq[200];
int main() {
    scanf(" %s", str);
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            // consider the range [i, j]

            // initialise the count of that variable
            for (char c = 'a'; c <= 'z'; c++) {
                freq[c] = 0;
            }

            for (int k = i; k <= j; k++) {
                freq[str[k]]++;
            }

            for (char c = 'a'; c <= 'z'; c++) {
                if (freq[c] > (j-i+1)/2) {
                    printf("%d %d\n", i+1, j+1);
                    return 0;
                }
            }
        }
    }
    printf("-1 -1\n");
}

// Unbalanced 2
// O(n) solution
#include <cstdio>
#include <cstring>
char str[100010];
int main() {
    scanf(" %s", str);
    int n = strlen(str);
    // check substring of size 2
    for (int i = 0; i < n-1; i++) {
        if (str[i] == str[i+1]) {
            printf("%d %d\n", i+1, i+2);
            return 0;
        }
    }
    // check substrings of size 3
    for (int i = 0; i < n-2; i++) {
        if (str[i] == str[i+2]) {
            printf("%d %d\n", i+1, i+3);
            return 0;
        }
    }
    printf("-1 -1\n");
}