---
title: 'Interactive Tasks'
date: 2022-07-28T19:25:00.005-07:00
draft: false
author: 'Angus Ritossa'
---

Interactive tasks are tasks where your code interacts with another program, often called a _grader_, rather than simply reading input and printing output. Due to this novel format, people are often scared off and avoid attempting these problems. My goal in this blog is to remove your fear towards interactive tasks.

<!--more-->

Example
-------

Let's start with a basic example, **Guess the Number**, which you can view in more detail [here](https://codeforces.com/gym/101021/problem/1).

  

There is some hidden number and you have to interactively guess it. The hidden number is always an integer from 1 to 1000000. 

  

You can make queries to the grader. Each query is an integer from 1 to 1000000. There are two different responses the grader can provide:

*   "<" (without quotes), if the hidden number is less than the integer in your query,
*   ">=" (without quotes), if the hidden number is greater than or equal to the integer in your query.

When your program wants to guess the hidden number, print "! x" (without quotes), where x is the answer.

  

Your program is allowed to make at most 25 queries (not including printing the answer)

  

This is a classic problem which can be solved using binary search (which you can read about [here](https://www.khanacademy.org/computing/computer-science/algorithms/binary-search/a/binary-search) if you're not familiar). Here is some C code which solves the problem. 

### 

```


#include <stdio.h>

  

int main() {

    // Binary search

  

    int start = 1;

    int end = 1000000;

    while (start != end) {

        int mid = (start+end+1)/2;

  

        printf("%d\\n", mid);  // Guess mid

        fflush(stdout);       // Flush stdout - more on this below

  

        char result\[3\];

        scanf(" %s", result); // Read the result from the grader

  

        if (result\[0\] == '<') {

            end = mid-1;

        } else {

            start = mid;

        }

    }

  

    int answer = start;

  

    printf("! %d\\n", answer);

    fflush(stdout);    

}




```  

You may notice that after each printf I have fflush(stdout). This is necessary in interactive tasks because of something called IO Buffering. Basically, when your program prints, this print isn't always done immediately. Instead, your code may wait until more has been printed (or your program terminates) and then print many things together. This is done automatically to speed up your code and is usually helpful, but in interactive tasks we need the print to happen immediately so that the grader can respond to our query. That's what fflush(stdout)does - it _flushes_ the output which means your query is printed immediately. In python, this can be done using sys.stdout.flush() or by adding flush=True as a second argument to print(). In C++, this can be done with std::cout << std::flush if you're using iostream.

Testing and Debugging Interactive Tasks
---------------------------------------

One difficultly of interactive tasks is testing. The most obvious way to test your code is for you to act as the grader, and manually answer queries via the command line. This is usually sufficient for basic testing but can be slow and tiresome for debugging. Fortunately, many contests (for example, google code jam) provide a grader which you can use to run and test your code! Unfortunately however, many contests (for example, CodeForces rounds) do not typically provide a grader. If you need to do lots of debugging, it may be worthwhile to write one yourself. There are two ways to do this - you can write a separate grader, or build one into your solution. Here we'll show how to do both of these options.

  

### Writing and Using a Separate Grader

### 

To do this, you need to write a separate program which acts as the grader. This grader should read queries and print responses to those queries. The grader also needs to know the correct answer - in the grader below, it reads the answer from the file "grader.in". Here is the grader I wrote for Guess the Number.

### 

```


#include <stdio.h>

int main() {

    FILE\* in = fopen("grader.in", "r");

    int answer;

    fscanf(in, "%d", &answer);

  

    int numGuesses = 0, guess;

  

    while (scanf("%d", &guess)) {

        numGuesses++;

        if (answer < guess) {

            printf("<\\n");

        } else {

            printf(">=\\n");

        }

        fflush(stdout);

    }

  

    scanf("! %d", &guess);

  

    if (guess == answer) {

        fprintf(stderr, "Correct\\n");

    } else {

        fprintf(stderr, "Incorrect (guessed %d, correct answer is %d)\\n", guess, answer);

    }

    fprintf(stderr, "Used %d guesses\\n", numGuesses);

}








```Again, it is important that we flush after printing. Additionally, notice that I have used stderr (standard error, which by default prints to the terminal similar to stdout) to print debugging messages, so that they are not confused with responses to queries. 

  

But how do we link this up with our solution? Well, we can use the _Interactive Runner_ from Google Code Jam, which is available [here](https://storage.googleapis.com/coding-competitions.appspot.com/interactive_runner.py). I recommend reading the comments to understand how to use it. The interactive runner links the output of the grader to the input of the solution, and the input of the solution to the output of the grader. Anything printed to stderr (from the grader or the solution) is still printed to the terminal, and so we will see our debugging output.

  

In this case, we would run our code with the grader by doing the following:

  

\# First, compile the solution

gcc -o solution solution.c

  

\# Then, compile the grader

gcc -o grader grader.c

  

\# Run the solution with the grader using the interactive runner

python3 interactive\_runner.py ./grader -- ./solution

  

### Building a Grader Into Your Solution

### 

If you do not wish to use the interactive runner, you can instead build the grader into your solution. However, it's annoying to edit the solution every time you submit, so we need a method which avoids this. In C or C++, this can be achieved by using #ifdef, which allows for conditional compiling. Let's take a look at the code. 

#include <stdio.h>

#include <string.h>

  

#ifdef DEBUG

int answer;

int numGuesses;

#endif

  

void doGuess(int guess, char\* result) {

#ifdef DEBUG

// When we run our code locally, we answer the query without printing

if (answer < guess) {

sprintf(result, "<");

} else {

sprintf(result, ">=");

}

numGuesses++;

#else

// When we submit our code, we print the query and scan in the answer

printf("%d\\n", guess);

fflush(stdout);

scanf(" %s", result);

#endif

}

  

void provideAnswer(int guess) {

#ifdef DEBUG

if (guess == answer) {

printf("Correct\\n");

} else {

printf("Incorrect (guessed %d, correct answer is %d)\\n", guess, answer);

}

printf("Used %d guesses\\n", numGuesses);

#else

printf("! %d\\n", guess);

fflush(stdout);

#endif

}

  

int main() {

#ifdef DEBUG

// Scan in the correct answer from stdin

scanf("%d", &answer);

#endif

  

// Binary search

  

int start = 1;

int end = 1000000;

while (start != end) {

int mid = (start+end+1)/2;

  

char result\[3\];

doGuess(mid, result);

  

if (result\[0\] == '<') {

end = mid-1;

} else {

start = mid;

}

}

  

provideAnswer(start);

}

If you compile the code with the compile flag -DDEBUG (e.g. using gcc -o solution solution.c -DDEBUG), then the code within the #ifdef DEBUG blocks is read by the compiler and all the code within the #else blocks is ignored. If we then run the code, it will read the correct answer from stdin and all queries are answered within the code. If the code is compiled without that compile flag (e.g. when the code is judged), then code within the#ifdef DEBUG blocks is ignored and code within the #else blocks is compiled. If we run the code now, queries are printed to stdout just like our original solution did.

Adaptive Graders

In the grader that we wrote, the correct answer was predetermined. However, this will not always be the case when your code is judged! Sometimes, the grader is _adaptive_ and will make up an answer as it goes along, trying to get your code to use as many queries as possible. Often, but not always, the problem statement will specify whether or not the grader is adaptive. When an adaptive grader is used, many solutions which use randomisation will fail because the grader will make your algorithm exhibit its worst case. 

Another Example - Guess the Array

This problem is also from codeforces, and you can see it in more detail [here](https://codeforces.com/contest/727/problem/C). 

In this problem you should guess an array _a_ which is unknown to you. The only information you have initially is the length _n_ of the array _a_. 

  

You can perform a query by giving two different indices _i_and _j_, and the grader will tell you _a\[i__\] + a\[j\]._

You must find the array _a_using at most _n_ queries.

  

3 ≤ _n_ ≤ 5000.

I recommend spending some time thinking about how to solve this problem - it may be useful to use pen and paper. I have included some hints below if you would like them.

Hint 1:

Try solving for n = 3.

Solution to hint 1:

Do three queries. Let the results of these be x = a\[1\] + a\[2\], y = a\[1\] + a\[3\] and z = a\[2\] + a\[3\]. Notice that x + y - z = a\[1\] + a\[2\] + a\[1\] + a\[3\] - a\[2\] - a\[3\] = 2a\[1\], so a\[1\] = (x+y-z)/2. Once we have a\[1\], we can easily find a\[2\] and a\[3\] (a\[2\] = x-a\[1\], a\[3\] = y-a\[1\]).

Hint 2:

Using hint 1, how can we solve the full problem?

Solution to hint 2:

First, use the solution to n = 3 to find a\[1\], a\[2\] and a\[3\]. We can then find a\[4\], a\[5\], ..., a\[n\] each in one query. 

More Examples

Here are many more interactive tasks which you may find interesting:

  

[Railway System, from Codeforces](https://codeforces.com/contest/1687/problem/B)

[Omkar and the Meaning of Life, from Codeforces](https://codeforces.com/problemset/problem/1583/D)

[Dat Bae, from Google Code Jam Qualification Round 2019](https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/00000000000881de#problem)

[Combo, from IOI 2018](https://ioinformatics.org/files/ioi2018problem1.pdf)

[Counting Mushrooms, from IOI 2020](https://ioinformatics.org/files/ioi2020problem5.pdf)

[Highway Tolls, from IOI 2018](https://ioinformatics.org/files/ioi2018problem5.pdf)

  

  

  

  

  

###