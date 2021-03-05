// A+B (Your First Submission)
#include <stdio.h>
int main() {
    // Read input
    int a, b;
    scanf("%d %d", &a, &b);
    
    // Compute answer
    int ans = a + b;
    
    // Print output
    printf("%d\n", ans);
}

// Prefix Sum
#include <stdio.h>
int N, A[100005], pre[100005], Q, l, r;
int main() {
    // Read input
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
    // Compute prefix sums
    for (int i = 1; i <= N; i++) pre[i] = pre[i-1] + A[i];
    // Answer queries
    scanf("%d", &Q);
    for (int i = 1; i <= Q; i++) {
        scanf("%d %d", &l, &r);
        printf("%d\n", pre[r] - pre[l-1]);
    }
}