---
title: 'The Art of Making Programming Problems'
date: 2022-08-08T05:40:00.002-07:00
draft: false
author: 'Isaiah Iliffe'
image: 'https://lh5.googleusercontent.com/9iGpfhdr7NJAtzmmF7FPG9e_wM0hWWgU2noGEALSnrA9dmCZtmxuoXnP7aR4h0ogqJ2KGIdFO9B8Vq8EMHOH_NLe2nsGFdoArs6DyLqFxr613xmslWrMcJHxM6xsHzJ8oBK_XwgtdYi5v0gAEwX0Fto'
---

Hello! Today we’ll explore the wonderful world of creating problems for programming contests. This article could be used as a sort of guide if you’re interested in writing problems yourself, but it’s intended for anyone interested in the process or philosophy behind making problems.

<!--more-->

The scope of the article is quite broad, and in its four parts, we will discuss (1) why to make programming problems, (2) how to invent problems, (3) how to plan a contest, and (4) how to prepare problems. Do feel free to skip around if any of these topics tickle your fancy, or if you’re up for it, I invite you to read the article through from top to bottom.

  

A lot of the thoughts presented here are based on my own modest experience with problem setting, mainly for university contests, informatics olympiads and miscellaneous educational purposes. Keep in mind that nothing I say is meant to prescribe a correct way to do things, just to describe what I’ve personally found effective for the work I’ve done.

  

![](https://lh5.googleusercontent.com/9iGpfhdr7NJAtzmmF7FPG9e_wM0hWWgU2noGEALSnrA9dmCZtmxuoXnP7aR4h0ogqJ2KGIdFO9B8Vq8EMHOH_NLe2nsGFdoArs6DyLqFxr613xmslWrMcJHxM6xsHzJ8oBK_XwgtdYi5v0gAEwX0Fto)

Some people doing a programming contest

  

Part 1: Why to make programming problems

In this first part, we’ll discuss some reasons for creating problems, and some goals to keep in mind when designing contests. This is to provide some motivation for the more instructional parts to come later in the article, but if instead you want to get straight to examples and practical advice, feel free to skip to Part 2.

  

The purpose of a programming contest

Different programming contests serve different purposes, for example: 

*   To let enthusiastic competitive programmers challenge themselves and have fun. This is often the case for more serious or more advanced contests.
    
*   To enhance a diverse audience’s enjoyment and appreciation of problem solving. For example, a contest run by a university society often attracts contestants of a wide range of skill levels and backgrounds.
    
*   To assess the participants’ understanding of content, like a typical assessment or exam.
    

  

In any case, if you’re working on a contest, like working on any type of project, it’s worth identifying its purpose as early as possible, and referring back to it regularly. In later parts, especially Part 3, we’ll cover more specifics of how considering purpose can inform how we put together a contest.

  

The purpose of a problem

The purpose of a problem in a contest is simply to serve the contest’s purpose, whatever that may be. With that said, it’s still worth considering the general properties of most good programming problems, which for me are the following:

*   Understanding what the problem is asking should be straightforward.
    
*   After reading the problem, the reader should feel excited to look for a solution.
    
*   The process of solving the problem should be fun. This can be achieved in various ways, such as requiring interesting observations, or requiring the pleasant application of techniques.
    
*   It should require some effort to arrive at a solution, but it should also be hard to get completely stuck. Of course, this depends on the experience and skill of the contestant.
    
*   The process of implementing the solution should be rewarding.
    

  

You don’t need to require that your problems perfectly fulfil each of these criteria – in fact, perfectly fulfilling each of these criteria is near impossible. The bottom line is that a good programming problem, in my opinion, is one that people read, think about, solve, and then think “that was nice”. The properties above try to reflect this overall goal of evoking satisfaction and appreciation within your contestants.

  

Achieving this goal is difficult, especially those new to problem setting, but after enough experimenting, and likely failure, you will develop an intuitive grasp of how to make a nice problem. We’ll discuss this in more detail in Part 2.

  

Part 2: How to invent problems

The most important piece of advice for new problem inventors is that you should just try it, be prepared to explore lots of ideas that don’t work out, and gradually figure out what you enjoy and what works for you. If you like being curious and asking questions which you don’t know whether there’s an answer to, the brainstorming process should be fun, relaxing and, at least every now and then, productive.[1](#fn1b)

  

One small but effective thing I like to do is keep a personal list of problem ideas, however undeveloped or seemingly awful they might be. This allows me to brainstorm in a somewhat structured way without the pressure of others judging my work, and also allows me to refer back to old ideas whenever I need some inspiration.

  

With that general advice out of the way, here are a few more specific methods for inventing problems, which vary in effectiveness from person to person:

*   Thinking about random things and investigating them to see if they lead to a problem.
    
*   Looking at an existing problem and modifying or generalising it into a new problem.
    
*   Starting from known algorithmic ideas and building a problem off of them.
    

We’ll discuss these methods in more depth using specific problems as examples.

  

Thinking about random things

The technique of thinking about random things naturally involves more creativity than the others, often resulting in relatively novel and elegant problems. The beauty of this method is that it can happen spontaneously, and it can happen anywhere, such as at your desk, in the shower, or while you go for a walk – all good places to let your mind wander.

  

Case study: [Ingredients Label](https://www.hackerrank.com/contests/csesoc-x-cpmsoc-programming-contest-2021/challenges/ingredients-label)

Despite the situation in the problem perhaps seeming a bit contrived, it is almost precisely a question I asked myself when looking at ingredients labels on food packaging (what could be the values of the percentages they omit?). After thinking about it for a bit, there turned out to be a fairly elegant solution with some accessible algorithmic ideas behind it, so I formed an ad-hoc competitive programming problem out of it.

  

![](https://lh3.googleusercontent.com/fsAOtWaoG2v2rBr5GQdfjQjQaOCnadVdH6FdVLDrhYVcZEZyDaPRvCyV6B1DalU07_MMtJTLPk9oilAN0av-hL8icfzu_KjFgMbgd9qkMANncK9uaxiiOUGabGHKPDshJpluUBkTYmezg3aKm_4p9VQ)

The ingredients label of a cereal box in my pantry

  

Case study: [IMC Banner I](https://www.hackerrank.com/contests/imc-x-csesoc-x-cpmsoc-coding-competition-division-a/challenges/imc21-a4)

I was thinking of problems to set for a contest which was sponsored by the company IMC, so at some point my mind must have ended up playing around with the letters I, M and C, giving rise to a simple string problem. Apparently this concept was thought-provoking enough to result in two more problems inspired by the same idea, [IMC Banner II](https://www.hackerrank.com/contests/imc-x-csesoc-x-cpmsoc-coding-competition-division-b/challenges/imc21-b8) and [IMC Banner III](https://www.hackerrank.com/contests/imc-x-csesoc-x-cpmsoc-coding-competition-2022-division-b/challenges/imc-banner-iii).

  

Adapting existing problems

Studying existing problems is naturally beneficial when trying to come up with your own, and sometimes playing around with what a problem is asking can result in new interesting problems.

  

Case study: [Vases](https://orac2.info/problem/aio19vases/)

In Vases, you have N flowers and are asked to assign them to three vases so each vase contains a distinct, positive number of flowers. An obvious question to ask is: what would happen if three were replaced by an arbitrary integer K? Some other questions might be: what happens if each vase has a maximum flower capacity, or a minimum flower requirement? What if you were asked to count the number of solutions, not just provide one solution? Hopefully this roughly illustrates what I mean by playing around with a problem and trying to generalise it. 

  

Case study: [Advertising](https://www.unswcpmsoc.com/assets/competitions/o-week-22t1/TaskStatements.pdf#page=13)

This problem came about as a result of exploring what made an existing problem, [Gradient](https://www.hackerrank.com/contests/csesoc-x-cpmsoc-programming-contest-2021/challenges/gradient), interesting. Gradient is very simple to state, and is a nice problem in its own right: given a set of up to 200 000 points in the plane, find the largest gradient of any line segment between two distinct points. In other words, given a list of x-coordinates x1, …, xn and y-coordinates y1, …, yn, choose distinct i and j such that (yi - yj) / (xi - xj) is maximised. I considered replacing (yi - yj) / (xi - xj) with (yi - yj) × (xi - xj), and the solution I came up with was nice enough that the simple modification directly resulted in a new problem, Advertising.

  

Starting from an algorithm

As a computer scientist, you’ll likely end up diving deep into studying known algorithms, and occasionally the questions you ask during this learning journey can give rise to a problem.

  

Case study: Max Flow Queries

This problem isn’t hosted anywhere, so here is the statement: given a flow network, and polynomial time for precomputation, answer online queries of the following form in constant time: if an edge from vertex u to vertex v with capacity w were added to the original graph, what would the new maximum flow be? As you can imagine, this problem arose from thinking about how I could extend maximum flow algorithms to answer simple queries. It ended up being a fairly interesting problem to test people’s intuition and understanding of flows.

  

Case study: [Trading at IMC II](https://www.hackerrank.com/contests/imc-x-csesoc-x-cpmsoc-coding-competition-division-b/challenges/imc21-b12)

This is a problem I don’t really like. It came about from thinking about square root queries, and ended up being a pretty straightforward application of this relatively obscure technique. It is a decent example of how starting with an algorithm can help create problems, but the reason I don’t like the problem is that for most people, the level of knowledge required would exceed the amount of problem solving required. Thus the problem doesn’t do much more than assess whether someone already knows a specific technique, and so I think it generally failed to be rewarding to contestants, regardless of whether they solved the problem.

  

Further reading

Here are some more resources (created by people far more qualified than me) on inventing problems:

*   [This blog post](https://www.topcoder.com/blog/how-to-come-up-with-problem-ideas/) details many general approaches to inventing problems, with plenty of examples.
    
*   [This journal article](https://ioinformatics.org/journal/INFOL031.pdf) quite comprehensively discusses a range of techniques for coming up with and developing ideas for problems.
    
*   Each problem in [this contest](https://codeforces.com/contest/472) demonstrates a specific technique for creating problems. Most of these techniques are more mechanical than other ones we’ve discussed, so they might be more readily applied.
    

  

Part 3: Planning a contest

In this part we’ll walk through a process for planning contests which has worked well for what I’ve been involved in.[2](#fn2b) First there is a phase, typically lasting a few weeks, where people can propose problem ideas onto a spreadsheet. Some time before the contest, there is a meeting, usually lasting a couple of hours, to decide on the problems which would make the best set for the contest. Finally, the chosen problems are prepared, a step which we’ll discuss later in Part 4.

  

Proposal phase

During the problem proposal phase, people can brainstorm ideas in their own time, perhaps following the principles we set out in Part 2, and put whatever they come up with onto a shared spreadsheet. These proposals generally don't require test cases, full statements or anything like that to be made – all this is more appropriate to make only when/if the problem is selected for the contest. All that is required is a minimal, likely unflavoured statement, and perhaps a brief solution in English so others can check their understanding of the problem. The reason I encourage this minimality in the proposal phase is to avoid wasting time, and to avoid getting overly attached to a problem early in the process.

  

![](https://lh3.googleusercontent.com/a2cdZ_3ApFhY42ym-ZaecBkq_CUyqSGoZbAcZt3Xj58LyMipd4iA0MWXJ0bhW_0wHTnVHs9bmGwlcHdBoIYKjffHh3StL4TrnIVqEiecYrjRGAF00nBIoUNCg4GBrna6GEaWNE28CGa8JByq-iS1P8s)

A sample problem setting spreadsheet

  

Depending on the purpose of the contest, it may be worth investigating tasks of a unique nature, in order to provide a refreshing experience to contestants – for example, the IOI committee “are particularly interested in tasks that go beyond the typical format in which a program collects input, performs some computation, and returns output.”

  

Case study: [Modern Art](https://www.hackerrank.com/contests/imc-x-csesoc-x-cpmsoc-coding-competition-2022-division-b/challenges/modern-art-painting)

This problem was included in a university competition, and is unique in the following way: there is one public input case which counts for the task, and contestants submit their output only and are judged on a sliding scale based on the “quality” of their solution. There were two goals behind including this problem: one was simply to include a novel and refreshing task which people enjoyed, and the other was to have an interesting tiebreaker to separate top contestants, without the need to have multiple difficult problems at the end which would lower everyone’s relative scores.

  

Problem selection meeting

How a problem selection meeting works is simple – the people present can go through all the proposed problems, discuss each problem’s merits and drawbacks, perhaps vote on the problems, then compose a final (or near-final) problem set for the contest. Note that a vote can be useful to quickly gauge which problems are liked and which are disliked, but the final set will almost never just be the highest voted problems – the goal is to pick the best problem set holistically, based on the desired overall feel and difficulty of the contest, not based on individual problem quality. Also, when discussing problems, like in any discussion, do your best to keep an open mind, and avoid getting attached to the problems you proposed – I mention this because I often seem to forget it myself.

  

This meeting is the most consequential point of the whole contest preparation process. Because of this, the purpose of the contest should be clear to everyone present. For example, if you’re running a contest for hundreds of uni students, a fraction of whom have any competitive programming experience to speak of, you’ll generally want to make a significant portion, say a third to a half, of the problems very accessible, before the difficulty starts ramping up. This is so, after the contest, there are as many people as possible feeling like they got value out of it, rather than feeling demoralised. Judging the difficulty of a contest and of problems is intrinsically hard – for some indication of this, see how the [IOI medal cutoffs](http://stats.ioinformatics.org/olympiads/2021) can vary a lot from year to year – so you can only do your best by keeping in mind the big picture of trying to make most people react well to your set of problems.

  

Part 4: Preparing problems

Once the problems are selected, we move on to the stage of preparing individual problems, by making statements, test cases and solutions. This process is somewhat mechanical, but can be quite satisfying, and there are a few opportunities to be creative. A lot of this stuff is best picked up from experience, and covering every small detail would be a waste of our time, so we’ll mainly focus on tips which might be harder to come across naturally.

  

Writing problem statements

By far the most important goal of a statement is to communicate to the reader what the problem is asking as quickly and accurately as possible. Perhaps this sounds obvious, but it is not rare to find problems where the author seems to have been caught up in crafting elaborate flavour text, neglecting the reader’s ability to easily understand the problem – I have fallen into this trap a few times. That said, some amount of flavour text can make the situation easier to understand quickly, and creative flavour text, although less important than clarity, can improve the audience’s experience.

  

Speaking of clarity of writing, deliberate proofreading by yourself and others is usually necessary to minimise the chance that a reader misinterprets you. Having thought about the problem already, it is easy to think that you’ve set up the problem in a clear and unambiguous way, even if there might be a clearer order to present information to your reader, or a way to simplify the wording to make it more digestible the first time. It may be worth repeating an important aspect of the problem, or explaining something in two ways, or rewording sentences to state the key points explicitly and less important points implicitly, rather than the other way around.

  

Case study: [Melody](https://orac2.info/problem/aio21melody/)

This is a statement I consider good, for the following reasons:

*   The key definition of “nice” is explained succinctly, and because of its importance, the author makes it as clear as possible by taking the time to go through examples.
    
*   The flavour text contributes to the problem by creating a context which may help a reader understand it quickly, but adds no clunkiness to the statement.
    
*   Information is presented in a natural order, and correct grammar and appropriate sentence structure is used to make the problem relatively effortless to read.
    

  

Case study: [Chessboard](https://codeforces.com/gym/103466/problem/B)

Fortunately, all of the bad draft statements I’ve written myself have been noticed by someone else and fixed up before being published. Instead, as an example of a bad statement, I’m forced to pick on someone else’s problem. The amount of effort required to understand the statement is probably largely due to translation issues, but this should still illustrate how verbiage, unnecessary flavour text and dubious wording of key points can result in a pretty painful experience for contestants.

  

Creating test cases

The goal of writing test cases is to precisely distinguish between programs which fully meet every requirement set out in the statement, and those which do not.[3](#fn3b) Usually it will be suitable to have some handmade test cases, and some test cases generated by a program.

  

Handmade cases include public sample cases, whose only purpose should generally be to complement the statement in making sure that the reader understands the problem quickly and accurately. In particular, it is fine, and perhaps good, if many buggy solutions pass the sample cases. Hidden handmade cases can include all the small edge cases and exhaust all the bugs you can think of, and since these cases are small, you can easily check that they’re serving their intended purpose by running incorrect solutions on them.

  

The point of generating test cases with a program is to check that their program is fast enough on large cases, and to test for subtle bugs beyond what you can predict with handmade cases. The way to do this effectively varies a lot from problem to problem and is often hard – coming up with data for a problem can feel a bit like solving a whole other problem. A general approach can be to analyse what makes the problem difficult, and come up with ways to generate interesting cases by making the computation which a correct solution must perform as sophisticated as possible. That was vague, so let’s try to clarify it a bit with the following example.

  

Case study: [Train Network](https://www.hackerrank.com/contests/csesoc-x-cpmsoc-programming-contest-2021/challenges/train-network)

You can view the files used to generate cases for this problem [here](https://drive.google.com/drive/folders/1z4kszmRhDbC1DNPGwBok-Sqnb9LOSxfz?usp=sharing). The solution roughly involved considering the minimum spanning tree, and for each edge, considering the best path going through it. Thus the general approach for generating data was to create a spanning tree, then assign weights so that the best paths through each edge were similar, then add more edges which don’t affect the MST. Some quick things to note:

*   The vertex labels and edge order is shuffled at the end just before printing the case, to avoid any biases in how the graph was generated.
    
*   A “tallness” argument is passed into the generator program, which allows the general shape of the graph to be modified, in order to increase the coverage of test cases.
    
*   The testlib.h library is handy when writing C++ generators, mainly because it implements RNG in a way that is consistent across machines and compilers.
    

  

Always remember to test each potential edge case, whether with a handmade or generated case. To give you a rough idea of what to keep in mind, consider creating:

*   Cases where all the variables are minimised under the given constraints, or all maximised, or some mixture of both.
    
*   If applicable, cases where all the variables are nearly minimised or maximised, but the answer is hard to guess or hardcode.
    
*   Cases where the answer is maximised or minimised or zero or negative or empty or very long or weird in some other way.
    
*   Every single case where N is sufficiently small, if it’s reasonable to exhaustively include all of them.
    
*   Other pathological cases specific to the problem, for example, where all the ranges overlap, or where none of the ranges overlap, or where the graph is a line graph or a star graph or a complete graph or an empty graph.
    

  

Case study: [Firefly Rectangles](https://www.hackerrank.com/contests/imc-x-csesoc-x-cpmsoc-coding-competition-2022-division-a/challenges/firefly-rectangles)

This is an example of where my test cases fell short. Because it didn’t cross my mind, I didn’t consider including a case where the answer was maximised or nearly maximised. Since the answer involved counting the number of valid rectangles, at least one solution with the wrong time complexity got accepted by using early loop breaking.

  

As a sanity check, it’s often worth writing a validator, which is simply a script which goes through all the test cases for the problem and makes sure they respect all the constraints described in the statement. Validators are usually very easy to write, and can catch a surprisingly high number of mistakes.

  

Writing solutions and testing

Coding up solutions to problems is essential to ensure that the data is correct and that the problems will work correctly during the contest itself. Wherever possible, at least two correct solutions should be written by at least two different people independently from each other, and it should be made sure that these solutions agree on every case. Also, if contestants can submit in multiple languages, it’s a good idea to prepare solutions written in different languages.

  

Incorrect or slow solutions are also generally worth writing, to make sure they fail as intended. If you can think of any broken algorithms or potential bugs, it’s worth quickly coding them up to make sure they fail on the test cases, and in the case that they do not (which should be unlikely), add more test cases so they do fail.

  

The final steps before the contest begins include to configure the contest, and to upload all the problems – this process depends on how the contest is being hosted, which is outside the scope of this article. As a final check, submit all your correct and incorrect solutions to the contest website to make sure they behave as intended. 

  

Concluding remarks

Well, we’ve just about reached the end. All the problems are prepared and ready to go, and all that’s left to do is sit back, wait until the contest starts, and enjoy watching the submissions roll in. It’s a pretty nice feeling knowing that tens or hundreds of people are toiling away at what you’ve prepared for them, and that all your effort is going a long way by giving participants a rewarding contest experience.

  

To conclude, I hope you’ve gotten something out of reading this, whether that be specific advice for making problems, or inspiration to get more involved in competitive programming or problem setting, or – most importantly of all – an appreciation of the fact that programming problems, if some care is put into them, have the power to make people happier.

  

  

* * *

[1](#fn1a) I find it very difficult to be consistently productive. Sometimes I’ve sat down and tried to think of problems for a couple of hours, only to come up with nothing. If you end up in the same boat, that’s completely fine – like any creative process, it’s unreasonable to expect that you’ll strike gold every time, but in the long run it will usually work out.

[2](#fn2a) This process can take a bit of time and effort, but is probably the best way to go about things if you’re writing original problems (which should always be the case for a contest with prizes) and want to create a quality set of problems which the contestants maximally appreciate. If you're less fussy about this or are in a rush, a few people could just independently create their own problems, and chuck them all into a contest at the end.

[3](#fn3a) This is impossible most of the time, where the number of possible inputs is large, since, for example, a program could get wrongfully accepted by having every test case hard coded in, or by failing only on a very small number of inputs which the test case creator could not reasonably have predicted. But the aim of testing programs as rigorously as practically possible still stands.