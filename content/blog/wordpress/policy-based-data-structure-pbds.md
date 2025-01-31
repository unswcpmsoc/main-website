---
title: 'Policy Based Data Structures (PBDS)'
date: Sun, 05 Mar 2023 05:22:58 +0000
draft: false
tags: ['Data Structure', 'Programming', 'Uncategorized']
author: 'David Zhou'
---

Supposed that we are tasked with designing a **SORTracker system** that can stores collection of `name` and attractive `score`. The attrativeness score of a location will determine it's ranking in the system, if two location have same score, then will compare lexicographical order to determine the order. The system support two operation.

<!--more-->

```
**1. Adding**: scenic locations, one at a time.
**2. Quering** the _ith_ best locaion of **all locations already added**
```

In order to effciently implement the above class, we may need a **data structure** that store scenic data, and with a way for ranking the existing data also support with **dynamically add** new location, then lastly, it needed to be effciently **looked** up as well.

We may examine the existing tools we had in C++ library,

1.  **vector**, a dynamic array. Clearly we unable to use due to linear complexity for inserting new element.
2.  **set**, a balanced tree. Support **adding**, while c++ do not support look up indexed element in **set**
3.  **unordered\_set**, hash map. Unordered, not able to provide a rank for each element.
4.  **priority\_queue**, heap. Support O(1) adding but also do not support look up indeded element.
5.  **queue, stack**, not so much useful neither.

As we can see from the above analysis, none of the C++ native container can fulfill the requirement of this system. While there do exist more advanced data structure that is able to accompoish the same task, the implementation time would be a significant concern, would be a deal breaker for a competitive programmer in a contest.

We can observe the native container, suppose that we have implemented a **balanced tree** our own, it should be an easy task for us to quering the **ith** element. This is where **policy-based data structure** come in handy, they are powerful tool that can customize the existing behaviour of standard container in c++. One of such example is the "**ordered set**" that while keeps the **unique** elements in sorted state, additionally suipport two **log(n)** operation as below

1.  **order\_of\_key**(k): number of element strictly smaller than k
2.  **find\_by\_order**(k): the kth element in a set.

In order to use **Policy Based Data Strcuture**, we first include the necessary header

```
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
```

The `assoc_container` adds more flexibility and customization to native class such as **set** and **map**, while `tree_policy` define policies for customizing behaviour of tree-based container. For example, "whether to allow duplicates, and nodes count stored in tree node". The namespace is just requirement by pbds.

The policy for ordered\_set is **tree\_order\_statistics\_node\_\_update**. The detail of implementation isn't so important to understand, as we only interest in the above two index looking functions. In short, this can be achieve by storing the children nodes countf as node's attribute in a balanced tree, is will enable fast looking up for the **k-th** element, (log(n) time). It would very simple binary search operation and left for reader to think about how to do so given the node count.

```
typedef tree<
  int ,
  null_type,   
  less<int>,   // Customizable
  rb_tree_tag, // Red-black tree used in underlying implementation
  tree_order_statistics_node_update
> ordered_set;
```

And a possible use scenrio would be like

```
ordered_set Set;
set.insert(3);
set.insert(5);
set.insert(1);

// order_of_key(x) returns the number of items in a set that are strictly smaller than x; or equivlently, the index of the first item greater or equal to x
Set.order_of_key(nums[i]);

// find_by_order(k) returns an iterator to the k-th largest element (counting from zero), 
Set.find_by_order(nums[i]);
```

As the end, if you are python coder, then there is **ordered\_set**. (Yea you prob dont need to read this article).

Here are some useful link, if want investigate more

*   The official documentation: [https://gcc.gnu.org/onlinedocs/libstdc++/ext/pb\_ds/](https://gcc.gnu.org/onlinedocs/libstdc++/ext/pb_ds/)
*   A tutorial on Codeforces: [https://codeforces.com/blog/entry/11080](https://codeforces.com/blog/entry/11080)