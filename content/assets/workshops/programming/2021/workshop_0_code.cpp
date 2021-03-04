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

// Prefix Sum - Motivation
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

// Bad Subarrays - O(N^3)
#include <stdio.h>
int N, A[100005];
int main() {
    // Read input
    scanf("%d", &N);
    int sum = 0;
    int answer = 0;
    for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
    // Every possible starting point of subarray
    for (int i = 1; i <= N; i++) {
        // Every possible ending point of subarray
        for (int j = i; j <= N; j++) {
            sum = 0;
            // Add all the elements in the subarray
            for (int k = i; k <= j; k++) {
                sum += A[k];
            }
            if (sum == 13) {
                answer++;
            }
        }
    }
    printf("%d\n",answer);
}

// Bad Subarrays - O(N^2)
#include <stdio.h>
int N, A[100005], pre[100005];
int main() {
    // Read input
    scanf("%d", &N);
    int sum = 0;
    int answer = 0;
    for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
    // Compute prefix sums
    for (int i = 1; i <= N; i++) pre[i] = pre[i-1] + A[i];
    // Every possible starting point of subarray
    for (int i = 1; i <= N; i++) {
        // Every possible ending point of subarray
        for (int j = i; j <= N; j++) {
            sum = 0;
            // Calculate sum from prefix array, we use i-1 because we want to include A[i]
            sum = pre[j] - pre[i-1];
            if (sum == 13) {
                answer++;
            }
        }
    }
    printf("%d\n",answer);
}

// Bad Subarrays - O(N)
// We assume magnitude of any contiguous subarray is <= 50000
// Essentially, instead of using 13 = pre[r] - pre[l-1], we use pre[l-1] = pre[r] - 13
// This is useful because we can store the count of previous prefix sum array values, instead of the value itself
// For example, the prefix sum array [1, 3, 6, 10, 5, 1, 1, 3], we would build the array [0, 3, 0, 2, 0, 1, 1, 0, 0, 0, 1]
// This is because there are 0 zeroes in the array, 3 ones, 0 twos, 2 threes, etc. etc.
// Then if we are looking at an end point i, and we have the previous prefix sum counts up to i, we can just look up pre[i] - 13 and see what the count is
// We use two arrays to store prefix sum counts, one for positive numbers and zero, one for negative numbers
#include <stdio.h>
int N, A[100005], pre[100005], prevPosVals[100005], prevNegVals[100005];
int main() {
    // Read input
    scanf("%d", &N);
    int answer = 0;
    for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
    // Compute prefix sums
    for (int i = 1; i <= N; i++) pre[i] = pre[i-1] + A[i];
    // Every possible ending point of subarray
    for (int i = 1; i <= N; i++) {
        // Check how many previous prefix sums we can remove to get 13
        if (pre[i]-13 < 0) answer += prevNegVals[-(pre[i]-13)];
        else answer += prevPosVals[pre[i]-13];

        // Add the current prefix sum to the counts
        if (pre[i] < 0) prevNegVals[-pre[i]]++;
        else prevPosVals[pre[i]]++;
    }
    printf("%d\n",answer);
}

// Bad Subarrays - O(N)
// We make no assumptions apart from any contiguous subarray will fit into a C++ int
// This requires use of a map, which will be taught in Workshop #1
// The problem Good Subarrays does not require a map
// http://www.cplusplus.com/reference/map/map/
#include <stdio.h>
#include <map>
int N, A[100005], pre[100005];
std::map<int,int> prevVals;
int main() {
    // Read input
    scanf("%d", &N);
    int answer = 0;
    for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
    // Compute prefix sums
    for (int i = 1; i <= N; i++) pre[i] = pre[i-1] + A[i];
    // Every possible ending point of subarray
    for (int i = 1; i <= N; i++) {
        // Check how many previous prefix sums we can remove to get 13
        if (prevVals.find(pre[i]-13) != prevVals.end()) answer += prevVals[pre[i]-13];

        // Add the current prefix sum to the counts
        if (prevVals.find(pre[i]) != prevVals.end()) prevVals[pre[i]]++;
        else prevVals[pre[i]] = 1;
    }
    printf("%d\n",answer);
}

// Walkscotch
/*
(1) N = 1
We have no choice of where to move, we need to stay on the same square K times
But K can be huge, so we can't just add the value of the square every step K times
With some quick maths we find that the answer is just A[1]*K, so we don't actually need to simulate all the steps

This is O(1)
*/
/*
(2) M = 1 and K = 1
We start on the first square and want to get as many points as we can!
Sound familiar?
With a standard prefix sum array, pre[i] will give us the number of points we get if we jump from square 1 to square i
Just find the max of the prefix sum array

This is O(N)
*/
/*
(3) K = 1
We can follow a similar technique to subtask 2.
Instead of a standard prefix sum array, we can go backwards from M to find the number of points we get if we jump left.
Then we can go forwards from M like a standard prefix array to find the number of points if we jump right.
The code will look something like

pre[M] = A[M];
for (int i = M-1; i >= 0; i--) pre[i] = pre[i+1]+A[i];
for (int i = M+1; i <= N; i++) pre[i] = pre[i-1]+A[i];

Then just find the maximum of pre.

This is O(N)
*/
/*
(4) All A[i] >= 0
The largest number of points we can get is jumping the entire array, so either from the very left to the very right or in the opposite direction.
The best solution will be taking one jump either to the very left or the very right (whichever gives the most points), then continuously jumping the whole array.
If we calculate pre as in subtask 3, the value of jumping to the very left in the first jump is pre[1].
The value of jumping to the very right in the first jump is pre[N].
Then our first jump takes the larger of pre[1] and pre[N].
The rest of the jumps all have the same value, the sum of the entire array.
Just like subtask 1, we can't simulate the jumps, so we need an equation to give us the answer.
Let's call the sum of the entire array S.
The solution is max(pre[1],pre[K])+(K-1)*S

This is O(N)
*/
/*
(5) All A[i] <= 0
The optimal solution here is to continuously jump on one square. Clearly jumping across multiple squares will give less points than jumping on one square, at least for that jump.

However, you can't just keep jumping on the starting square.
Consider N=2, M=1, K=2, A = [-100, -1].
The optimal solution here is to jump to the -1 and jump on itself, which gives -101-1 = -102.
Jumping on the -100 twice gives -200.

We also can't just go to the largest square and jump on it.
Consider N=4, M=2, K=2, A = [-2, -10, -100, -1]
Here it is optimal to jump to the -2 and jump on itself, giving -14 points.
If you jump to the -1 and jump on itself, then you get -112 points.

Q: Well how do we know which square we want to jump to?
A: Just try them all!

If we compute pre like in subtasks 3 and 4, we get the array showing the score we get on the first jump if we jump to that square.
The final answer if we jump to square i and jump on itself repeatedly is pre[i]+(K-1)*A[i].
Let's say solution[i] = pre[i]+(K-1)*A[i].
Then our answer is just the largest value in solution.

This is O(N)
*/
/*
K = 2
Say for our first jump we jump from M to i. For our second jump we should get as many points as possible.
This should be easy to convince yourself of. If we have already jumped from M to i,
then to maximise our total points we just want to maximise our next jump.
Then we should calculate the maximum jump from every such i, as well as the value of the jump from M to i.
The latter is done with the pre array from the previous three subtasks.

The former is done with something called Kadane's algorithm (https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/)
Essentially, the largest contiguous subarray ending at i either contains the largest contiguous subarray ending at i-1, or is just the element itself.
If the largest contiguous subarray ending at i-1 is positive, we take it, otherwise we don't.
The code will look something like

for (int i = 1; i <= N; i++) {
    if (max_end[i-1] > 0) max_end[i] += max_end[i-1];
    max_end[i] += A[i];
}

However, max_end[i] will give the maximum score ONLY for jumping to the left!
How do we account for jumping to the right?
If we apply Kadane's algorithm in reverse, we can get the largest contiguous subarray starting at i.

for (int i = N; i >= 1; i--) {
    if (max_start[i+1] > 0) max_start[i] += max_start[i+1];
    max_start[i] += A[i];
}

Then the largest jump we can make from i is just the largest between max_end[i] and max_start[i].
Then the overall solution is the largest of pre[i]+max(max_end[i],max_start[i]).
For the sake of simplicity we will set max_all[i] = max(max_end[i],max_start[i])

This is O(N)
*/
/*
M = 1
It turns out that the observations we made previously applies to K > 2 too.
That is, we want to jump to a square i, then from i we want to take the largest point jump possible to j.
Then from j we want to jump back to i, then back to j and so on.
The proof is too large to fit in this comment (haha funny math reference).
But really this is a lot more difficult to prove, and you will have to work with some diagrams and try to find counterexamples to convince yourself.

The solution is max(pre[i]+max_all[i]*(K-1)) for all 1 <= i <= N.
Remember we calculated pre and max_all in O(N) each.

This is O(N)
*/
/*
FINAL SOLUTION
So we actually skipped a couple of steps. There are some observations we could have made specifically for having the first jump going to the right,
which would have been for the final subtask. But we generalised the jumps so our solution to the last subtask is also the final solution.
The code will look something like the following.
*/
#include <stdio.h>
#include <limits.h>
int M, N, A[100005], pre[100005], max_end[100005], max_start[100005], max_all[100005];
int main() {
    // Read input
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
    // Set the answer to -infinity, INT_MIN is part of limits.h
    int answer = INT_MIN;
    // Compute score for jumping from M to i
    pre[M] = A[M];
    for (int i = M+1; i <= N; i++) pre[i] = pre[i-1] + A[i];
    for (int i = M-1; i >= 0; i--) pre[i] = pre[i+1] + A[i];
    // Calculate maximum contiguous subarray ending at i
    for (int i = 1; i <= N; i++) {
        if (max_end[i-1] > 0) max_end[i] += max_end[i-1];
        max_end[i] += A[i];
    }
    // Calculate maximum contiguous subarray starting at i
    for (int i = N; i >= 0; i--) {
        if (max_start[i+1] > 0) max_start[i] += max_start[i+1];
        max_start[i] += A[i];
    }
    // Calculate maximum contiguous subarray starting or ending at i
    for (int i = 1; i <= N; i++) {
        if (max_end[i] > max_start[i]) max_all[i] = max_end[i];
        else max_all[i] = max_start[i];
    }
    int curScore;
    // Every possible point for the first jump
    for (int i = 1; i <= N; i++) {
        // Compute the score if we jump from M to i in the first jump, then loop the highest jump from i
        curScore = pre[i]+max_all[i]*(K-1);
        if (curScore > answer) answer = curScore;
    }
    printf("%d\n",answer);
}