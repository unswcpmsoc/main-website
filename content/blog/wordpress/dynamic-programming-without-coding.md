---
title: '"Dynamic Programming" without coding'
date: Tue, 13 Jun 2023 08:30:00 +0000
draft: false
tags: ['Dynamic Programming', 'Inclusion-exclusion principle', 'Mathematics', 'Problem Solving', 'Uncategorized']
author: 'George Kwong'
image: 'https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/06/picture2.png?w=601'
---

<!--more-->

It is a clickbait. The main focus of this article lies more in the concept of "Divide-and-conquer" rather than "Dynamic Programming". There exist subtle differences between the two. It is worth noting that "Dynamic Programming" involves overlapping sub-problems, while the former does not. However, as far as competition mathematics is concerned, the actual coding is not required, and therefore, this article will not dive any deeper into this topic.

I often find these two terms confusing because in mathematics, discomposing a complex problem into smaller subproblems is never a proper-named technique, which you will use nonetheless. Let's do a very naive example.

> In a classroom, there are 50 people where 26 people with glasses, 16 people with a dress and 14 people without glasses and a dress. How many people are wearing both glasses and with a dress?

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/06/picture1.png?w=634)

Using the figure above, we can know that the number of people inside at least one of two circles is 50 - 14 = 36. Note that the numbers of people in the left and right circles are respectively 26 and 16. But we don't have 26 + 16 = 42 people. We have only 36 people. So the overlapping region has 42 - 36 = 6 people.

It utilises the [inclusion-exclusion principle](https://en.wikipedia.org/wiki/Inclusion%E2%80%93exclusion_principle). But please be honest, isn't dividing the problem into different cases (with glasses, with a dress and with a dress and a pair of glasses)?

Now, let's consider the following problem appearing in Launch Week in Term 2, 2023.

> Colour the following graph G with no adjacent [vertices](https://mathworld.wolfram.com/GraphVertex.html#:~:text=%22Vertex%22%20is%20a%20synonym%20for,80) having the same colour. How many possible colourings when using k colours? How about a similar graph with n triangles?

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/06/picture2.png?w=601)

Note that in this question we consider the same colouring after a series of rotations and reflections as different sets of colours.

We denote $C\_G(k)$ as the number of colourings for the graph $G(n)$ with $n$ triangles and $k$ colours. So we want to find $C\_{G\_5}(k)$.

Of course, it is possible to count it using a small programme. But we don't want to do that as we will notice very soon it is unnecessary. But then it is very tedious even though the graph has only 10 vertices. So we divide the problem into 2 cases. But before this, we consider the less rigid case for the 2 vertices on the red edge so that they can be in the same colour or in different colours. How can we do this?

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/06/picture3-1.png?w=601)

**Case 0 ($C\_0$): The two vertices on the red edge have the same colour or different colours.**

We can delete the edges connecting them, as it will release the different-colour restriction.

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/06/picture5.png?w=601)

**Case 1 ($C\_1$): ****The two vertices on the red edge**** have different colours.**

It is the same as the original question.

**Case 2 ($C\_2$): ****The two vertices on the red edge**** have the same colours.**

But isn't it prohibited? Bear with me first. If they have the same colour, we can merge these two vertices to bring back this case into the region of our problem. Then the graph becomes like this. Note that a double edge on the resultant graph is unnecessary as the adjacent vertices are in different colours already.

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/06/picture6.png?w=1024)

Then we can see that

$C\_0 = C\_1 + C\_2$.

So we can find $C\_{G\_5}(k)$ by $C\_1 = C\_0 - C\_2$. This technique is called the [Deletion–contraction formula](http://Deletion–contraction formula). Again, an example of dividing cases.

Then we can also see that Case 0 differs from Case 2 by a single vertex. Call it $X$. Also, denote the graph in Case 2 as $G'\_4$ (as we have 4 triangles left). The colouring of $X$ has only one restriction - having a different colour from the top-right vertex. Then we have $C\_{G\_5}(k) = C\_0 - C\_2 = (k - 1) C\_{G'\_4}(k) - C\_{G'\_4}(k) = (k - 2) C\_{G'\_4}(k)$. Then we only need to apply the Deletion–contraction formula again on the blue edge of $G'$ and get $C\_{G'\_4}(k) = C\_{G''\_4}(k) - C\_{G\_4}(k)$, where $G''\_n$ is a graph with $n$ triangle chained. The below shows graphs $G''\_4$ and $G\_4$. Note that $G\_4$ is the 4-triangle version of $G\_5$, the original graph.

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/06/picture7.png?w=1024)

$C\_{G''\_n}(k) $ can be found easily. Easy to see that $C\_{G''\_1}(k) = k(k-1)(k-2)$ and $C\_{G''\_2}(k) = k(k-1)(k-2) (k-1)(k-2) = k(k-1)^2(k-2)^2$. You can show (maybe by induction) that $C\_{G''\_n}(k) = k(k-1)^n(k-2)^n$.

Then we have $C\_{G\_5}(k) = (k - 2) C\_{G'\_4}(k) = (k - 2) \[k(k-1)^4(k-2)^4 - C\_{G\_4}(k) \]$. You can reduce the expression further by reducing $C\_{G\_4}(k)$ into $C\_{G\_3}(k)$ and $C\_{G\_2}(k)$. Also, $C\_{G\_2}(k) = k(k-1)(k-2)^2$, which is left as an exercise.

Similarly, we have $C\_{G\_n}(k) = (k - 2) \[k(k-1)^{n-1}(k-2)^{n-1} - C\_{G\_{n-1}}(k) \]$. You can show that by a geometric sum $\\displaystyle C\_{G\_n}(k) = (k - 1) (2 - k)^n + (k - 2)^n (k - 1)^n$. Hence, we have an algorithm in $O(n)$ (or even $O(\\log n)$. Why?). Nice.

It is great to appreciate using a mathematical approach to a programming problem. To do this, try attempting [Problems 3 and 5](https://unswcpmsoc.blog/2023/02/26/oweek-contest-solution-programming/) again so the code looks shorter.