---
title: 'O-Week Quiz 2023 Solutions (Mathematics)'
date: Sun, 12 Feb 2023 07:04:59 +0000
draft: false
tags: ['Game Theory', 'Mathematics', 'O-Week', 'Plane Geometry', 'Uncategorized']
author: 'George Kwong'
image: 'https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/02/picture1.png?w=835'
---

Question 1:

You and Ryan are playing a game on a triangular board with 9 empty cells. <!--more--> The cells at the corner lie on both edges. You take turns filling in an integer from 1 to 9 to a blank cell. Every integer can be used once only. The first gets an edge with a sum of 20 wins. Ryan is so polite, so he lets you have the second-mover advantage and go second. How can you win the game?

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/02/picture1.png?w=835)

This is a trick question because the second player cannot win. The secret lie between (1,9), (2,8), (3,7) and (4,6) all pair up to 10 and any two pairs sum to 20, which makes "5" left behind.

Suppose Ryan fills "5" at the top. Then no matter where and what you fill (says _n_), Ryan can fill 10 – _n_ into the same line (avoid the corners when he is not yet near winning). In such case, Ryan can always get a sum of 20 at the bottom line.

Question 2:

On a large paper, let _A_ be a point 15 cm below and 8 cm on the left of the top-right corner. Fold the paper so that the top right corner covers _A_. What is the area of the triangle folded into the paper?

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/02/picture2.png?w=1024)

We redraw the figure as follows.

![](https://unswcpmsoc.wordpress.com/wp-content/uploads/2023/02/picture3-2.png?w=975)

Note that _BR_ = 8 cm, _AB_ = 15 cm and _CD_ is the crease created when _R_ is folded onto _A_. Folding implies that _CD_ is the perpendicular bisector of _AR_, so _M_ is the midpoint of _AR_. By Pythagorean theorem and [Inverse Pythagorean theorem](https://en.wikipedia.org/wiki/Inverse_Pythagorean_theorem) (you can also use similar triangles), we have (all lengths are in cm)

$RM = \\frac 1 2 \\sqrt{AB^2 + BR^2}= \\frac {17}2$  
$\\frac 1 {BE^2} = \\frac 1 {AB^2} + \\frac 1{BR^2} = \\frac {289} {14400} \\Leftrightarrow BE = \\frac {120} {17}$

By the property of similar triangles, we have the ratio of areas of △_CRD_ to △_ABR_ is $\\frac {RM^2}{BE^2} = \\frac {83521}{57600}$.  
So the required area is $(\\frac {83521}{57600})(\\frac {(15)(8)}{2} = \\frac {83521}{960}$.