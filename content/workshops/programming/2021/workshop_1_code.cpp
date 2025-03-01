// Stacks
#include <stack>                                    // Include this to use std::stack
#include <cstdio>                                   // The same as stdio.h, gives printf/scanf
using namespace std;                                // Allows us to type stack<int> instead of std::stack<int>
int main() {
    stack<int> s;                                   // Declares a stack called s
    s.push(3);                                      // Push 3 onto the stack
    printf("top of stack: %d\n", s.top());          // prints 3
    printf("size of stack %d\n", (int)s.size());    // prints 1
    s.push(1);
    s.push(2);
    printf("top of stack: %d\n", s.top());          // prints 2
    printf("size of stack %d\n", (int)s.size());    // prints 3
    s.pop();                                        // Remove the top element from the stack
    printf("top of stack: %d\n", s.top());          // prints 1
    printf("size of stack %d\n", (int)s.size());    // prints 2
    s.push(4);
    printf("top of stack: %d\n", s.top());          // prints 4
    printf("size of stack %d\n", (int)s.size());    // prints 3
    s.pop();
    printf("top of stack: %d\n", s.top());          // prints 1
    printf("size of stack %d\n", (int)s.size());    // prints 2
    s.pop();
    printf("top of stack: %d\n", s.top());          // prints 3
    printf("size of stack %d\n", (int)s.size());    // prints 1
    s.pop();
    printf("size of stack %d\n", (int)s.size());    // prints 0
}

// Bracket Matching
#include <stack>                        // Include this to use std::stack
#include <cstdio>                       // The same as stdio.h, gives printf/scanf
#include <cstring>                      // The same as string.h, gives strlen
#include <cstdlib>                      // The same as stdlib.h, Gives exit
using namespace std;
#define MAXN 100010
char brackets[MAXN];

void NO() {
    // Prints no and ends the program
    printf("NO\n");
    exit(0);                            // exit(0) terminates the program without any errors
}

int main() {
    scanf(" %s", brackets);
    int n = strlen(brackets);
    stack<char> s;
    for (int i = 0; i < n; i++) {
        if (brackets[i] == '(' || brackets[i] == '[' || brackets[i] == '{') {
            s.push(brackets[i]);
        } else {
            if (s.empty()) {
                NO();                   // No opening bracket to match us with
            } else if (brackets[i] == ')' && s.top() != '(') {
                NO();                   // Matched the wrong types of brackets together!
            } else if (brackets[i] == ']' && s.top() != '[') {
                NO();                   // Matched the wrong types of brackets together!
            } else if (brackets[i] == '}' && s.top() != '{') {
                NO();                   // Matched the wrong types of brackets together!
            }
            s.pop();                    // Remove the opening bracket from the stack, as it is now matched
        }
    }    
    if (!s.empty()) {
        NO();                           // There are unmatched opening brackets!
    }
    printf("YES\n");       
}

// Sculpture
#include <stack>                            // Include this to use std::stack
#include <cstdio>                           // The same as stdio.h, gives printf/scanf
#include <algorithm>                        // Gives us std::max
using namespace std;
#define MAXN 100010
int n, t[MAXN], w[MAXN], h[MAXN];
int curr_hei;                               // the height of the current stack
int ans;                                    // the height of the highest stack we have seen so far
stack<int> s;                               // will contain the indicies of the blocks on the current stack
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &t[i], &w[i], &h[i]);

        // this is the condition for popping from the solution slide
        while (!s.empty() && t[i] >= t[s.top()]+w[s.top()]) {   
            curr_hei -= h[s.top()];         // we remove the block from the stack, so decrement the current stack height
            s.pop();
        }

        curr_hei += h[i];                   // we add the block to the stack, so increment the current stack height
        ans = max(ans, curr_hei);           // update the answer if our stack height is the highest so far
        s.push(i);
    }
    printf("%d\n", ans);
}

// Histogram O(N^3) solution (Subtask 1, N <= 100)
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 100010
int n, hei[MAXN], ans;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &hei[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // Consider the range [i, j]. We will find the height of the bar rectangle in this range
            int mn = hei[i];
            for (int k = i; k <= j; k++) {
                mn = min(mn, hei[k]);
            }
            // Update maximum area, if this rectangle exceeds it
            ans = max(ans, (j-i+1)*mn);
        }
    }
    printf("%d\n", ans);
}

// Histogram O(N^2) solution (Subtask 2, N <= 1000)
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 100010
int n, hei[MAXN], ans;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &hei[i]);
    }
    for (int i = 0; i < n; i++) {
        int mn = hei[i];
        for (int j = i; j < n; j++) {
            mn = min(mn, hei[j]);
            // Update maximum area, if this rectangle exceeds it
            ans = max(ans, (j-i+1)*mn);
        }
    }
    printf("%d\n", ans);
}

// Sorted Stack
// n and h are the input
// left_limit is the array which we will use to store the output
void find_left_limits(int n, int h[], int left_limit[]) {
    stack<int> s;                                   // Will contains indices of the bars on the sorted stack
    for (int i = 0; i < n; i++) {
        while (!s.empty() && h[s.top()] >= h[i]) {  // Pop a bar if it can never again be a left-limiting bar
            s.pop();
        }
        if (s.empty()) {
            // The bar does not have a left limit
            left_limit[i] = -1;
        } else {
            left_limit[i] = s.top();
        }
        s.push(i);
    }
}

// Histogram O(N) solution (Full marks)
#include <cstdio>
#include <algorithm>                        // Gives us reverse
using namespace std;   
#define MAXN 100010
typedef long long ll;                       // The maximum possible answer is 10^5 * 10^6 = 10^11, so we need long longs
void find_left_limits(int n, int h[], int left_limit[]); // Omitted - see code from sorted stack
int n, hei[MAXN], left_limit[MAXN], right_limit[MAXN];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &hei[i]);
    }
    find_left_limits(n, hei, left_limit);
    reverse(hei, hei+n);                            // Reverse the array
    find_left_limits(n, hei, right_limit);          // The right limits (in reverse order) are now stored in right_limit
    reverse(hei, hei+n);
    reverse(right_limit, right_limit+n);   
    for (int i = 0; i < n; i++) {
        right_limit[i] = n-1-right_limit[i];        // Because we reversed the array, need to "reverse" every index
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll len = right_limit[i]-left_limit[i]-1;    // The width of the rectangle with its lowest bar at bar i
        ll area = len*(ll)hei[i]; 
        ans = max(ans, area);                       // Check if we improve the answer
    }
    printf("%lld\n", ans);
}