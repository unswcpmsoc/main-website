---
title: 'Implementation tips for competitive programming'
date: 2021-06-04T07:30:00.000-07:00
draft: false
url: /2021/06/implementation-tips-for-competitive.html
tags: 
- beginner
author: 'Angus Ritossa and Isaiah Iliffe'
---

It’s uncommon for code you write to work properly the first time you run it. And if you’re not careful, you can spend hours debugging and still be left with code that doesn’t work. <!--more--> This is especially problematic in ICPC, when you have only one computer between three people.
  
Below are a few tips on how to improve the implementation and debugging process.

Before you start implementing
-----------------------------

### Proving your solution

Once you have a solution, the first step is to convince yourself it is correct. If you skip this step, you could invest a lot of time into coding only to later realise that your entire idea is incorrect. You don’t need a formal mathematical proof, just enough that you are sure it works. When doing this, try to think about the worst cases which could break your algorithm, and then reason why they do or do not. 

### Planning your code

Once you are sure you have a correct solution, the next step is to plan your code. This is an important step that is often overlooked by beginners who want to jump straight into coding their idea. A few minutes of planning can save many more minutes of debugging. In team contests where you share a computer, you should spend time away from the keyboard planning, so that you minimise your time spent using the keyboard.

  

The amount of planning you should do depends on how confident you are at implementing, and how difficult the problem is to code. When I was starting off, I would write detailed pseudocode before I touched the keyboard. As I have become more experienced, I do less planning – the simpler parts I just think over in my head, and the more complicated parts I blueprint on paper. Nonetheless, some planning is essential to save time debugging. 

### While you are implementing

If your code is long and has several components, write and test them individually throughout. This will make debugging easier, as you are only debugging small sections of your code at a time. For example, if your solution involves a segment tree, you can first implement the solution without the segment tree (using a basic for loop) and then later add the segment tree. This process will also help you identify earlier if your solution is flawed and needs a complete overhaul. 

Debugging
---------

### Debugging with breaking cases

Debugging is a lot easier if you can identify where your code goes wrong. The simplest way to do this is with a breaking case, which is a test case that causes your code to fail. There are a few methods for finding breaking cases:

1.  Try the sample cases given in the problem. These may not be very strong, as their only intention is to help you understand the problem.
    
2.  Come up with cases by hand, and find the answer manually. Compare this with the answer your code gives, and repeat until a test case causes your code to fail. Try to design ‘tricky’ cases, or corner cases, which might break your code.  
    
3.  If the above two techniques aren’t working, you can automate your approach. To do this, you need a brute force solution that works. This could be a wildly inefficient solution, as long as it gets the correct answer. You also need code that randomly generates test cases, which is normally not too difficult to write. Once you have these, you can use a script to make a test case, run your two solutions on that test case, and compare the answers. See below for two examples of how to do this.  
    

Once you have a breaking case, you can add print statements to your code (or use more advanced debugging tools) to determine where it goes wrong, and fix this part of the code. 

#### Python script

This script runs two executables in the same directory, broken and correct, on random inputs. If it finds a case where the outputs are different, it halts and the test case will be in test.in.

```
import random
import subprocess
random.seed(0)
tries = 0
while tries < 1000000:
    tries += 1
    with open("test.in", "w") as f:
        # Replace everything in here to be specific to the problem,
        # this is just an example.
        N = random.randint(3,10)
        f.write(str(N) + "\n")
        A = [str(random.randint(1,10)) for i in range(N)]
        f.write(" ".join(A) + "\n")
        
    result1 = subprocess.check_output("./broken < test.in", shell=True)
    result2 = subprocess.check_output("./correct < test.in", shell=True)
    if result1 != result2:
        print("gg", tries)
        print(result1, result2)
        break 
``` 

#### Bash script 

This script runs three executables in the same directory, broken, correct and generator, and keeps going until they output different results. Make sure that the generator uses a different random seed each time it runs. If using the rand() function in C++, you can use srand(chrono::steady\_clock::now().time\_since\_epoch().count()).

```
while true; do
    ./generator > test.in
    ./correct < test.in > correct.out
    ./broken < test.in > broken.out
    if ! diff correct.out broken.out; then 
        echo "incorrect"
        break
    else
        echo "correct"
    fi
done
```

#### Generator tips

*   Try to generate with small bounds (usually much smaller than the problem bounds) so the breaking case can be worked out by hand so you can find your bug quicker.

*   But if this fails to find a breaking case, test with large bounds.

*   If the generator still doesn’t find a breaking case:

*   Ensure your answer to some minimum cases (e.g. N=0 and N=1 if allowed) and some maximum cases (N=MAX, array values all MAX) is correct. Your random generator might not test these.
*   Make your generator design better cases (e.g. for a graph problem, make it generate some interesting graphs). This is a last resort, as it is quite a time investment, and hopefully your random generator comes up with interesting cases occasionally anyway.

### Useful compile flags

Compiler flags can be your friend when it comes to debugging. A sample makefile with many flags can be found [here](http://orac.amt.edu.au/december/Makefile). I will explain some of the most useful ones here.

#### Warning flags

Warning flags let you know if your code is doing things that are generally considered bad practice, such as declaring a variable and never using it. Often, having warnings is a sign you have made a mistake, and these flags can help you detect errors before you even run your code. Three warning flags are below:

1.  \-Wall – short for “all warnings”. This name is misleading, but it does enable a lot of warnings.
    
2.  \-Wextra – short for “extra warnings”. This supplements the warnings given by Wall and can help detect even more issues.
    
3.  \-Wshadow – warns about [variable shadowing](https://en.wikipedia.org/wiki/Variable_shadowing). Shadowing can lead to bugs that are hard to find, so this flag can save a lot of time.   
    

I recommend using all these flags when compiling your code.

#### Sanity checkers

The flags \-fsanitize=address and \-fsanitize=undefined will stop your code if it attempts to do illegal things, such as accessing an invalid index in an array. This can help detect issues that will sometimes cause your code to crash or produce strange output. These will slow down your code, so remove them if you have finished debugging and need your code to run quickly. 

### Common Issues

#### Integer overflow

This is a common issue and is usually the first thing I consider if my code gets the wrong answer. Recall that a 32-bit signed integer can only store values from -2,147,483,648 to 2,147,483,647. Have a think about the biggest values which may be required in your code, and if they are too big to be stored in a 32-bit integer, you should use a 64-bit integer (such as a long long in C/C++). A signed 64-bit integer can store values from -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807, which is sufficient for almost all problems in competitive programming.  

#### Array bounds too small

If your array bounds are too small, your code will almost certainly crash on big cases. If your code is crashing, double check that all of your arrays are the correct size. Be especially careful if you are using 1-indexing. For example, if you use array indices 1 through to 100000, then your array will need to be of size 100001 (or more).

#### Slow IO

The speed of your input and output can be a bottleneck in problems with a lot of input or output. If your code is getting TLE when you think it should be passing and you are using C++, consider the following:

*   If you are using scanf/printf for your input/output, then your IO speed is generally fine.
*   If you are using cin/cout, you need to be careful. You can achieve similar speeds to scanf/printf by adding the following two lines to the beginning of your main function:

*   ios\_base::sync\_with\_stdio(false);

*   This disables the synchronisation between scanf/printf and cin/cout, which allows cin/cout to work independently of scanf/printf and speeds them up. However, a consequence of this is that if you mix cin/cout and scanf/printf, you could get strange results.

*   cin.tie(NULL);

*   By default, cin is tied to cout. This means that cout will flush before cin is called, which is useful in situations where you are prompting users for input. However, if this behaviour is not necessary, it may slow down your code. This line removes this behaviour.

*   When using cout, do not use std::endl to print newlines, use \\n instead. This is because endl flushes the output, which can slow down your code if you are printing many lines. The exception to this is if you want to flush the output after every line.

#### Initialising and resetting variables

Make sure your variables are initialised as required. For example, local variables can have any value when declared, so if you wish to declare a local variable to count something, be sure to initialise it to 0.

  

In some problems, each test case contains multiple different inputs (for example, in Google Code Jam problems and some Codeforces problems). This often leads to you having to reuse variables. Make sure you reset all variables/arrays for each new case, or you could get some unexpected results.