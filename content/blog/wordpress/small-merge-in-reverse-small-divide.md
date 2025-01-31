---
title: 'Small Merge in Reverse (Small Divide?)'
date: Tue, 04 Jul 2023 01:26:28 +0000
draft: false
tags: ['Data Structure', 'Graph Theory', 'Programming', 'Uncategorized']
author: 'Angus Ritossa'
image: 'https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/06/eg-1.png?w=888'
---

Here, I present an interesting application of small merge that (to my knowledge) is not very well known.

<!--more-->

**Introduction to Small Merge**

Small Merge, or Small-To-Large, is a technique used to merge sets together quickly. In its most simple form, it can be used to solve the following problem:

There are _N_ objects, numbered from _0_ to _N-1_, each initially in their own sets. You must support _Q_ operations, each of the following type:

1.  Update: Given two integers _i_ and _j_, merge the set containing object _i_ with the set containing object _j_.
2.  Query: Given two integers _i_ and _j_, answer the following question: are objects _i_ and _j_ in the same set?

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/06/eg-1.png?w=888)

An example with N = 5. Objects in the same set have the same colour.

To simplify the time complexity analysis, we assume that _Q = O(N)_, which is usually a reasonable approximation to make in competitive programming.

This problem can be solved using a _union find_ data structure (also known as _disjoint-set_ or _DSU_) in _O(N log N)_ time (we can actually do slightly better than this, but that is beyond the scope of this blog).

If you are already familiar with union find, then you can skip to the next section. Otherwise, I recommend reading the following before you read the next section.

Click here to read about Union Find with Small Merge

For each object, we store which set it is in (using an array), and for each set, we store a list of the objects that are in this set. We can then perform the operations as follows:

1.  Update: Let _a_ be the set containing _i_ and let _b_ be the set containing _j_. If _a_ = _b_, then we do nothing since _i_ and _j_ are already in the same set. Otherwise, we iterate through the objects in set _b_, and move them into set _a_.
2.  Query: We simply check if the two objects are in the same set, using our array.

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/07/union-find-example.gif)

An example of the above algorithm

Let’s analyse the worst-case time complexity of this algorithm. Clearly, the query operation is constant time, so we restrict our analysis to the update operation only. Consider the following case: We have _N-1_ updates, where the _i_\-th update (starting from 1) merges the set containing object _i_ with the set containing object 0. Then, in this update, our algorithm will move objects 0, …, _i-1_ into the set containing object _i_. Hence, the overall time taken for all the updates is O(1 + 2 + … + _N-1_) = _O(N2)_. This represents the worst-case time complexity, since a single update cannot take more than _O(N)_ time.

Click here to see a visual demonstration of the _O(N2)_ case

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/07/small-merge-blog.gif)

Example of the _O(N2)_ case with N = 6

We can improve this algorithm with a simple change. When doing an update, we always merge the smaller set (i.e. the set with less elements, with ties broken arbitrarily if they have equal size) into the bigger set. Then, the time taken to do a single update is proportional to the size of the smaller set. While this may only seem like a constant factor improvement, we can actually prove that this is asymptotically better.

The key idea of the proof is the following: when we merge the smaller set into the larger set, the cardinality (i.e. the size) of the resulting set is at least double the cardinality of the smaller set prior to the update. Now, consider the movement of some object _i_ across all the updates. Each time we move object _i_ into a new set, the cardinality of this new set must be at least double the cardinality of the old set. Hence, if object _i_ changes sets _k_ times, then the cardinality of the set containing _i_ after all the updates have concluded must be at least _2k_. Hence, object _i_ can only change sets at most log2(N) times: otherwise, the set containing _i_ would have cardinality greater than 2log2N = N, which is impossible. By summing this value across all objects, we see that the total number of times we move objects between sets across all updates is at most _N_ log_2(N)_. It follows that the overall time complexity is _O(N_ log_(N))_.

This approach is called small merge or small-to-large merge.

**Applying Small Merge**

We now turn our attention to a different problem.

You are given a tree with _N_ vertices and _N-1_ edges. You must support _Q_ operations, each of the following type:

1.  Update: Given an edge _(u, v)_, delete it from the graph.
2.  Query: Given two vertices _u_ and _v_, is there a path from _u_ to _v_?

Again, we assume _Q = O(N)_ for simplicity. Our goal is to find an _O(N log N)_ solution.

If the operations are _offline_, meaning that we are told all the operations at the start, then the problem can be solved using union find (this is left as an exercise to the reader). However, if the operations are _online_, meaning that queries must be answered before future operations are given, then we need a different approach. There is an advanced data structure called a link-cut tree which can be employed, however this is unnecessary.

Observe that at any point in time, the graph will consist of several connected components. We can try a similar solution to the previous problem, by keeping track of which component each vertex is in. In particular, we assign each connected component a unique id, and each vertex stores the id of its component. We then perform operations as follows:  

1.  Update: We delete the edge _(u, v)_ from our graph and create a new id. We then DFS (or BFS), starting at vertex _u_, and mark all of the visited vertices with the new id. Hence, the vertices in the component of _u_ receive a new id, while the vertices in the component of _v_ retain the old id.
2.  Query: We simply check if the two vertices are in components with the same id.

Unfortunately, this suffers from the same issue as our original solution to the merging problem: in the worst case, we will be DFSing a large component each time, and so the worst-case time complexity is O(N2).

Click here to see a visual demonstration of the _O(N2)_ case

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/07/dfs-worst-case.gif)

Example of the _O(N2)_ case with N = 6

However, imagine if we magically knew the smaller of the two new components during each update. Then, rather than always DFSing into the connected component of _u_, we could DFS into the smaller of the two connected components. We can apply a similar time complexity analysis to union find: if a vertex is relabelled, then the size of its connected component has at least halved. Hence, a vertex will be relabelled at most log2_(N)_ times, and so we would have an overall time complexity of _O(N_ log _N)_.

Unfortunately, we don't have magic. However, we can still find the smaller component! We run two DFSs (or BFSs) simultaneously, one starting from _u_ and one starting from _v._ We interleave these DFSs, so that the amount of work done by each DFS never differs by more than a constant. Then, once one of these two traversals has terminated, we have identified the smaller component and we can stop the other traversal. This time taken to do this is proportional to the size of the smaller component, and so incorporating this into our solution maintains the _O(N_ log _N)_ time complexity.

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/06/small-merge-1.gif)

A simultaneous DFS to identify the smaller component after deleting an edge

We can also implement this procedure using multithreading: we create two threads, one to DFS each component. The first thread to finish marks its component as the smaller one, and kills the other thread.