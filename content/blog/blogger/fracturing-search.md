---
title: 'Fracturing Search'
date: 2022-07-16T22:05:00.007-07:00
tags: 
- advanced
author: 'Ryan Ong'
image: 'https://upload.wikimedia.org/wikipedia/commons/6/62/Latitude_and_Longitude_of_the_Earth.svg'
---

Have you ever had that insatiable urge to find the $k$th smallest minimum spanning subtree of a weighted graph? (I know I have.) Well look no further! This post will explore fracturing search and its applications.

<!--more-->  

(No prerequisite knowledge it required to understand the concepts, although it will be helpful graph theory terminology and an algorithm that solves the standard minimum spanning tree problem.)

  

An example - finding the kth smallest value in a heap
=====================================================

  

Fracturing search is a method that partitions your search space, and explores it in a way to get the "kth best" item. Let me illustrate with an example:

  

Lets consider a heap, which is a binary tree where the value of a parent is always strictly smaller than the value of any child (this property is known as the heap invariant). For example, 1 < 2 and 1 < 7, because (1) is the parent of (2) and (7).

  

[![](https://blogger.googleusercontent.com/img/a/AVvXsEjWiGQ5lmOLcVbDBHCxup8KmMRMk1IOsEWjDZ8C9ApqtpVpZ_uLU94YYEdUy5LUO54kQX6MpwUceupb89UtZPxTVhkJKsD8uZqP0Z_kPv_nlAPRaOrGq_QAoha3W3h2AbfIPv4Yhrn7rMPVRc6bIbOBQUfV2OQokyGrZ4nuxuCRCi8JYYJ-OdEKTjRr)](https://blogger.googleusercontent.com/img/a/AVvXsEjWiGQ5lmOLcVbDBHCxup8KmMRMk1IOsEWjDZ8C9ApqtpVpZ_uLU94YYEdUy5LUO54kQX6MpwUceupb89UtZPxTVhkJKsD8uZqP0Z_kPv_nlAPRaOrGq_QAoha3W3h2AbfIPv4Yhrn7rMPVRc6bIbOBQUfV2OQokyGrZ4nuxuCRCi8JYYJ-OdEKTjRr)

  

We want to find the kth smallest value. Now is a good time to pause and think if you want to try it yourself.

  

  

  

Due to our heap invariant, the 1st smallest value is always the root. More generally, the smallest value of a tree is always the root node. I shall depict this idea in blue from now on. (In practice you would implement this as a function that takes a subtree and returns the smallest value - the root).

  

[![](https://blogger.googleusercontent.com/img/a/AVvXsEhh8azlLFr_TkYlJqRYNT1kobvo7BX2JEEsLTFvAvPf-n89YpYErLmpRPX9NT261_0EP-KZAqJY13VXrsYRqK33yCINYWwLguuLe569OgDNyNtxBkEucqt_1QBKtTc3owlhBHdXLvYgufutOvZ6QosnrjMitFUs0OgZc9KJuu0a9imW9ls888jVow_k)](https://blogger.googleusercontent.com/img/a/AVvXsEhh8azlLFr_TkYlJqRYNT1kobvo7BX2JEEsLTFvAvPf-n89YpYErLmpRPX9NT261_0EP-KZAqJY13VXrsYRqK33yCINYWwLguuLe569OgDNyNtxBkEucqt_1QBKtTc3owlhBHdXLvYgufutOvZ6QosnrjMitFUs0OgZc9KJuu0a9imW9ls888jVow_k)

  
Hence we can say that the 2nd smallest value is the smallest value of the left subtree or the smallest value of the right subtree, namely 2 or 7. It is clear that the 2nd smallest value is 2.

  

[![](https://blogger.googleusercontent.com/img/a/AVvXsEjwPWCOoeYWCmk-3Ql6LhMbFx5ojcw5k0nJv2PhxEJ8yQdOrMNZ9Bi-mYHOG2_VrTXWmbtr8ASt2AOOL5cwUTkdF--p1ZeHY9y8DlcYuW8k8kJmyJ2HxIck-jZz4N3ah3xKJrV2k1JJOiRHR-Blpatvyr90fcdT3Ccu2a297FeXSGpRhFH7PezgReGe)](https://blogger.googleusercontent.com/img/a/AVvXsEjwPWCOoeYWCmk-3Ql6LhMbFx5ojcw5k0nJv2PhxEJ8yQdOrMNZ9Bi-mYHOG2_VrTXWmbtr8ASt2AOOL5cwUTkdF--p1ZeHY9y8DlcYuW8k8kJmyJ2HxIck-jZz4N3ah3xKJrV2k1JJOiRHR-Blpatvyr90fcdT3Ccu2a297FeXSGpRhFH7PezgReGe)

  

Then the 3rd smallest value is the smallest value of the remaining subtrees, namely 10, 8 or 7. Hence we conclude the the 3rd smallest value is 7.

  

[![](https://blogger.googleusercontent.com/img/a/AVvXsEitaLqYrIlh35KO0ZXC7pTy-nogA4acfXiylLdoqI6BQcbSRFhZRx4hlTUY09PQWTtpXbmtCk-TSQGdGphsN06wFi-6Cm8kS7v7Nryt4bP4y2G2W0uWxtCVJ2pHl8Fr772mxHb1nt8UxKAUh45BWTgKvj7JbcbImMUCNUKi6EUIDHvwZRla-PjXLxtN)](https://blogger.googleusercontent.com/img/a/AVvXsEitaLqYrIlh35KO0ZXC7pTy-nogA4acfXiylLdoqI6BQcbSRFhZRx4hlTUY09PQWTtpXbmtCk-TSQGdGphsN06wFi-6Cm8kS7v7Nryt4bP4y2G2W0uWxtCVJ2pHl8Fr772mxHb1nt8UxKAUh45BWTgKvj7JbcbImMUCNUKi6EUIDHvwZRla-PjXLxtN)

  
  

This process looks like "fracturing" our tree into smaller trees, hence the name Fracturing Search.

  

Solution - finding the kth smallest value in a heap
===================================================

  

```
#include <bits/stdc++.h>
using namespace std;

int N, K, heap\[1000005\];

struct Subtree {
	// every subtree can be uniquely represented its root node
	// note that the minimum node is the root node, with a value of \`heap\[root\]\`
	int root;
	
	// given another subtree return which one is minimum
	// this is useful for priority queue shenanigans
	bool operator<(Subtree other) const {
		return heap\[root\] \> heap\[other.root\];
	}

	// a partition of a tree returns the left subtree and right subtree
	vector<Subtree> getPartition() {
		vector<Subtree> output;
		// left child
		if (2 \* root <= N) output.push\_back({2 \* root});
		// right child
		if (2 \* root + 1 <= N) output.push\_back({2 \* root + 1});
		return output;
	}
};

signed main() {
	// N = total number of nodes in the tree
	cin \>> N;

	// K = we want the kth minimum node
	cin \>> K;
	assert(1 <= K && K <= N);

	// read in the tree as a standard heap structure
	//  - 1 is the root
	//  - 2\*node is the left child of nod
	//  - 2\*node+1 is the right child of node
	for (int i \= 1; i <= N; ++i) {
		cin \>> heap\[i\];
	}

	priority\_queue<Subtree> pq;
	// initially searching the whole tree, i.e. the tree which has 1 as the root
	pq.push({1});

	for (int ithBest \= 1; ithBest < K; ++ithBest) {
		Subtree curr \= pq.top();
		pq.pop();
		for (Subtree partition : curr.getPartition()) {
			pq.push(partition);
		}
	}
	int ans \= pq.top().root;
	printf("The %dth smallest node is %d, with a value of %d\\n", K, ans, heap\[ans\]);
}

```

  

The illustrated example is equivalent to the input

  

```
6 3
1 2 7 10 8 9

```

  

  

This algorithm can also be applied to most problems which gives you many states, each which a particular value, and asks for the state with the kth smallest value. (given that you can easily find the minimum of a subset of states, and that you can partition a subset of states efficiently).

  

Try it yourself - kth smallest spanning tree
============================================

Try the kth smallest spanning tree problem, here's some starter code.

  

```
int main() {
    // STATEMENT:
    // Given an undirected weighted graph, find the total costs of the minimum 
``````
 // spanning subtree to the kth minimum spanning subtree

    // CONTRAINTS:
    // N, M, K <= 2000
    // K <= number of possible spanning trees
    // 1 <= a\_i, b\_i <= N
    // 0 <= w\_i
    // \\sum\_i w\_i <= INT\_MAX

    // INPUT FORMAT:
    // N M K
    // a\_1 b\_1 w\_1
    // ...
    // a\_M b\_M w\_M
    cin.tie(0); ios::sync\_with\_stdio(0);
    
    cin \>> N \>> M \>> K;
    for (int i \= 0; i < M; ++i) cin \>> edges\[i\].second.first \>> edges\[i\].second.second \>> edges\[i\].first;
    sort(edges, edges + M);

    fracturingSearch();
    //bruteForce();
}

```

  

Solutions - kth smallest spanning tree
======================================

[Here's an unreadable solution that somehow works.](https://usaco.guide/adv/fracturing-search?lang=cpp#solution)

  

[Here's an awesome video which explains fracturing search and a solution to this problem in detail.](https://www.youtube.com/watch?v=EG_HfFMM0lE)

  

And here's my solution in the better language (eww Java 🤢🤮)

```
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <assert.h>
using namespace std;

int N, M, K;
pair<int, pair<int, int\>> edges\[2005\];
int parents\[2005\];

//////////////////////////////////////////////////////////////////////
void clearDSU() {
    for (int node \= 1; node <= N; ++node) parents\[node\] \= node;
}

int getParent(int node) {
    if (parents\[node\] \== node) return node;
    return parents\[node\] \= getParent(parents\[node\]);
}

bool doUnion(int a, int b) {
    int pA \= getParent(a), pB \= getParent(b);
    bool ans \= (pA \== pB);
    parents\[pA\] \= pB;
    return ans;
}

bool doUnion(pair<int, int\> edge) {
    return doUnion(edge.first, edge.second);
}

// find whether all nodes are in the same component
bool isMerged() {
    for (int node \= 1; node <= N; ++node) {
        if (getParent(node) != getParent(1)) return false;
    }
    return true;
}

//////////////////////////////////////////////////////////////////////

struct State {
    int cost \= 0;
    vector<int\> choices;
    vector<bool\> used;

    State(int M) {
        choices.resize(M);
        used.resize(M);
    }

    bool operator<(State o) const {
        return cost \> o.cost;
    }
};
priority\_queue<State> pq;

State initState() {
    State output(M);

    clearDSU();
    for (int i \= 0; i < M; ++i) {
        if (!doUnion(edges\[i\].second)) {
            output.cost += edges\[i\].first;
            output.used\[i\] \= true;
        }
    }
    return output;
}

State findNeighbour(vector<int\> choices) {
    State output(M);
    output.choices \= choices;

    clearDSU();
    for (int i \= 0; i < M; ++i) {
        if (choices\[i\] \== 1) {
            doUnion(edges\[i\].second);
            output.cost += edges\[i\].first;
            output.used\[i\] \= true;
        }
    }
    for (int i \= 0; i < M; ++i) {
        if (choices\[i\] \== 0 && !doUnion(edges\[i\].second)) {
            output.cost += edges\[i\].first;
            output.used\[i\] \= true;
        }
    }
    return output;
}

void fracturingSearch() {
    pq.push(initState());
    for (int rep \= 0; rep < K; ++rep) {
        if (pq.empty()) {
            cout << \-1 << "\\n";
            continue;
        }

        State curr \= pq.top();
        pq.pop();
        cout << curr.cost << "\\n";

        for (int remIndex \= 0; remIndex < M; ++remIndex) {
            // this edge is being used, but it could be swapped out
            if (curr.used\[remIndex\] && curr.choices\[remIndex\] \== 0) {
                vector<int\> newChoices \= curr.choices;
                for (int i \= 0; i < remIndex; ++i) {
                    if (curr.used\[i\]) newChoices\[i\] \= 1;
                }
                newChoices\[remIndex\] \= \-1;

                State neighbour \= findNeighbour(newChoices);
                if (isMerged()) pq.push(neighbour);
            }
        }
    }
}

void bruteForce() {
    vector<int\> ans;
    for (int bits \= 0; bits < (1 << M); ++bits) {
        int cost \= 0;
        bool valid \= true;

        clearDSU();
        for (int i \= 0; i < M; ++i) {
            if (bits & (1 << i)) {
                if (doUnion(edges\[i\].second)) valid \= false;
                cost += edges\[i\].first;
            }
        }
        if (valid && isMerged()) ans.push\_back(cost);
    }

    sort(ans.begin(), ans.end());
    for (int i \= 0; i < K; ++i) cout << (i < ans.size() ? ans\[i\] : \-1) << "\\n";
}


```

  

  

Bonus question!
===============

[Here's an additional question I made.](https://acio-olympiad.github.io/2022/paint.pdf)

  

And here's my solution (though I suggest you only look at this after trying the problem yourself):

  

```
/\* N <= 2e3, K <= 2e3

fracturing search
O(NK log NK)
\*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <assert.h>
using namespace std;
typedef long long ll;

ll N, K, D;
vector<ll> costs\[2005\];

struct State {
    ll numItems \= 0, cost \= 0;
    ll hasChoice;
    ll lastChoice;
    // choices\[i\] <= used\[i\]
    // day is discarded when used\[d\] = choices\[d\] = cost\[d\].size()
    // day has free choice when choices\[d\] = -1

    bool operator<(State o) const {
        if (numItems \== o.numItems) return cost \> o.cost;
        return numItems < o.numItems;
    }
};
priority\_queue<State> pq;

State initState() {
    State output;
    output.numItems \= D;
    for (ll d \= 1; d <= D; ++d) output.cost += costs\[d\]\[0\];
    output.hasChoice \= 1;
    //output.used.resize(D + 1);

    return output;
}

void fracturingSearch() {
    pq.push(initState());

    for (ll rep \= 0; rep < K \- 1; ++rep) {
        State curr \= pq.top();
        pq.pop();

        for (ll d \= curr.hasChoice; d <= D; ++d) {
            //cerr << "d " << d << "\\n";
            //cerr << "PQ size: " << pq.size() << "\\n";
            // option 1: increment the cost
            for (ll itemI \= 1; itemI < (ll)costs\[d\].size(); ++itemI) {
                State neighbour \= curr;
                neighbour.cost += costs\[d\]\[itemI\] \- costs\[d\]\[0\];
                neighbour.hasChoice \= d + 1;
                //neighbour.used\[d\] = itemI;
                pq.push(neighbour);
            }

            // option 2: remove this day
            if (0 != (ll)costs\[d\].size()) {
                State neighbour \= curr;
                neighbour.cost \-= costs\[d\]\[0\];
                neighbour.numItems--;
                neighbour.hasChoice \= d + 1;
                //neighbour.used\[d\] = costs\[d\].size();
                pq.push(neighbour);
            }
        }
    }

    cout << pq.top().numItems << " " << pq.top().cost << "\\n";
}

int main() {
    cin.tie(0); ios::sync\_with\_stdio(0);

    cin \>> N \>> K \>> D;
    for (ll d, w, i \= 0; i < N; ++i) {
        cin \>> d \>> w;
        costs\[d\].push\_back(w);
    }
    for (ll d \= 1; d <= D; ++d) sort(costs\[d\].begin(), costs\[d\].end());

    fracturingSearch();
}

```