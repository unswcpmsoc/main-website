# Distancing (Python)
# Solution by Jonathan
N = int(input())
A = list(map(int, input().split()))
if (N == 1):
  print("1")
else:
  print(sum(A) + max(A) - min(A))

// Honeycomb (C++)
#include <cstdio>
int main(){
  int a, b, c, d, e, f;
  scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
  printf("%d\n", (f+a+b-2)*(f+a+b-1)/2
  -(f-1)*f/2
  -(b-1)*b/2
  -(d-1)*d/2
  );
}

# Pear Pairs (Python)
# Solution by Tunan
N, K = [int(x) for x in input().split()]
pears = [int(x) for x in input().split()]
# Store whether we've seen a number
seen = [False for _ in range(K+1)]
# Store the number of distinct values seen so far
seen_so_far = [0 for _ in range(N)]
ans = 0
for j in range(N-1, -1, -1):
  if j < N-1:
    seen_so_far[j] = seen_so_far[j+1]
    if not seen[pears[j]]:
      seen[pears[j]] = True
      seen_so_far[j] = seen_so_far[j] + 1
seen = [False for _ in range(K+1)]
for i in range(N-1):
  if not seen[pears[i]]:
    seen[pears[i]] = True
    ans = ans + seen_so_far[i+1]
print(ans)

# Restrictions (Python)
N, R = map(int, input().split())
X = list(map(int, input().split()))
Y = list(map(int, input().split())) # input

pre = [0] # pre[x] = how many houses built before or at space x
for i in range(1,N+1):
  flag = False
  pre.append(pre[-1])
  for j in range(R):
    x, y = X[j], Y[j]
    if pre[i] - pre[max(0, i - x)] >= y: # if placing will violate a restriction
      flag = True
  if not flag:
    pre[-1] += 1
    print("H", end='') # build house and update prefix sum
  else:
    print("_", end='') # don't build
print()

# Mexican Wave (Python)
# Solution by Tunan
N, K = [int(x) for x in input().split()]
e = [int(x) for x in input().split()]

# Array to keep track of how many times we have seen something in our current range
# We want at least one value to be seen to count number of invalid ranges.
freq = [0 for _ in range(K+1)]
# Number of values that have zero occurrences in our range. Will be updated on our walk.
num_zeroes = K
ans = 0

leftpointer = 0
for rightpointer in range(N):
  # Add the new element
  if e[rightpointer] <= K:
    if freq[e[rightpointer]] == 0:
      num_zeroes -= 1
    freq[e[rightpointer]] += 1
  # Remove elements until num_zeroes positive
  while num_zeroes == 0:
    if e[leftpointer] <= K:
      freq[e[leftpointer]] -= 1
      if freq[e[leftpointer]] == 0:
        num_zeroes += 1
    leftpointer += 1

  # Anywhere before the left pointer must be a valid starting position
  ans += leftpointer

print(ans)