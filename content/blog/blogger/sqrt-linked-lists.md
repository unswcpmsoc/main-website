---
title: 'Sqrt linked lists'
date: 2022-06-08T19:50:00.003-07:00
draft: false
tags: 
- advanced
author: 'Ryan Ong'
---

  

  

I present a (novel?) variation of a linked list, which allows for insertion, deletion and querying in worse case O(sqrt(n)).

<!--more-->

If these things interest you, you may like to look at:

*   big O notation, otherwise known as time complexity. This is a useful method to measure how fast things are, rather than looking at the number of "steps" in the worse case. [https://onecore.tech/informatics/5](https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqa1B2SUVvWmVDRDBkQmxRaXdwZWxIRHRmRDNMQXxBQ3Jtc0tsem5FcndSNTlaeWNycjZIMFh1R2VjOTRtUHVWQ3VTSmJFUVJvaXczSU5NNWxod2hST3p4M1RWTGJETTVWMXNaVDB2SDJQU0tYM0h0XzFsa0JVUXJMbEdwcERmUS1mWnY0a3lGb3p0WnFsQl9lM05pcw&q=https%3A%2F%2Fonecore.tech%2Finformatics%2F5&v=7WcmpQ6Qjxk)
*   skip lists, a similar variation with a randomised aspect. It is faster than mine in the average case, but slower in the worse case. [https://en.wikipedia.org/wiki/Skip\_list](https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbElUc3JnNWwwd1NYUWZ2OG10ZVhxQ1o1SXhfZ3xBQ3Jtc0tseVZwVzB4alpOVk80NXZITmdsemNxbzVxeW8tSEJRdlhJcGhsRXY5NmVBc3o0aDRrc3ZUa3NaUUhHXzV2WlUzTkF2dnNOdXlxMkRRSllSQ0hIc1VCSWpLYVFraWxCY0dQNzg0LVZxc3hCQlZjZ1ZxYw&q=https%3A%2F%2Fen.wikipedia.org%2Fwiki%2FSkip_list&v=7WcmpQ6Qjxk)
*   B-trees, which although are not linked lists, are faster than mine in all cases. Not to be confused with binary trees. [https://en.wikipedia.org/wiki/B-tree](https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbUpvVlVUaHo3dDlEdFA2SnJ6dzUtUHRpdlBQUXxBQ3Jtc0trNDhONkVoRmRWUlQyZkhIZ2RTZzREeW80enFQZjVWMUJRQ0Q5M3V6NmducUtabVFYSGNqdzJ4NFVLS0tCdVJYUzdWcVBCVlp4MlpmaGNlQ2lTQ0hRUkhYQ0ozSGM1U016dXlDbUZGekNHWXIzV0h6RQ&q=https%3A%2F%2Fen.wikipedia.org%2Fwiki%2FB-tree&v=7WcmpQ6Qjxk)

  

  

```
// Written by Ryan Ong (z5419383)
// on 14/04/2022

/\*\*
 \* Sqrt Linked List!
 \* I want to answer these queries in about sqrt(n) steps:
 \*    - "insert this value at index i"
 \*    - "remove the value at index i"
 \*    - "what is the value at index i" 
 \*
 \* The main difficulty boils down to finding the node at index "i" quickly. For 
 \* each range of length sqrtn, I would store the number of nodes in the range, 
 \* and also a pointer to the first node in the range.
 \* 
 \* To find an index i would walk the ranges to find the best one, then walk 
 \* through the nodes until index i. Every sqrtn queries, recalculate the ranges,
 \* such that the number of steps never grows too large.
 \*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

#define CMD\_INSERT 'I'
#define CMD\_REMOVE 'R'
#define CMD\_QUERY 'Q'
#define CMD\_PRINT 'P'
#define CMD\_UPDATE\_RANGES 'U'

struct Range;

struct Node {
    int data;
    struct Node \*next;
    struct Range \*range;
};

struct Range {
    int num\_contained; // number of nodes in this range, usually around sqrt(N)
    struct Node \*checkpoint;
    struct Range \*next;
};

struct List {
    int num\_contained; // total number of nodes, otherwise denoted as N
    struct Node \*head;
    struct Range \*range;
};

// initialise a sqrt linked list, given that it contains "first\_val"
// \[0 steps\]
struct List \*init(int first\_val) {
    struct Node \*first\_node \= malloc(sizeof(struct Node));
    first\_node->data \= first\_val;
    first\_node->next \= NULL;
    
    struct Range \*first\_range \= malloc(sizeof(struct Range));
    first\_range->num\_contained \= 1;
    first\_range->next \= NULL;

    first\_range->checkpoint \= first\_node;
    first\_node->range \= first\_range;

    struct List \*list \= malloc(sizeof(struct List));
    list->num\_contained \= 1;
    list->head \= first\_node;
    list->range \= first\_range;
    
    return list;
}

// return the node at that index
// \[2sqrt(N) steps\]
struct Node \*get\_node(struct List \*list, int index) {
    int total \= 0;

    // step through the ranges until you find the range that covers this index
    struct Range \*curr\_range \= list->range;
    while (total + curr\_range->num\_contained < index) {
        total += curr\_range->num\_contained;
        curr\_range \= curr\_range->next;
    }

    // then, step through the nodes in this range until you reach the index
    struct Node \*curr\_node \= curr\_range->checkpoint;
    while (total + 1 <= index) {
        total++;
        curr\_node \= curr\_node->next;
    }

    return curr\_node;
}

// insert val after this index
// note that this function cannot deal with prepending
// \[2sqrt(N) steps\]
void insert(struct List \*list, int index, int val) {
    struct Node \*curr\_node \= get\_node(list, index);
    
    struct Node \*new\_node \= malloc(sizeof(struct Node));
    new\_node->data \= val;
    new\_node->next \= curr\_node->next;
    new\_node->range \= curr\_node->range;
    new\_node->range->num\_contained++;

    curr\_node->next \= new\_node;
}

// remove the node at this index
// \[2sqrt(N) steps\]
void rem(struct List \*list, int index) {
    struct Node \*curr\_node;
    if (index \== 0) {
        curr\_node \= list->head;
        list->head \= curr\_node->next;
    } else {
        curr\_node \= get\_node(list, index);
        get\_node(list, index \- 1)->next \= curr\_node->next;
    }

    curr\_node->range->num\_contained--;
    // edge case: the node to be removed is a checkpoint node, change the 
    // checkpoint to something else
    if (curr\_node \== curr\_node->range->checkpoint) {
        curr\_node->range->checkpoint \= curr\_node->next;
    }
    free(curr\_node);
}

// return the data of the node at this index
// \[2sqrt(N) steps\]
int query(struct List \*list, int index) {
    return get\_node(list, index)->data;
}

// output the data of the entire list
// \[N steps\]
void print(struct List \*list) {
    for (struct Node \*node \= list->head; node != NULL; node \= node->next) {
        printf("%d ", node->data);
    }
    printf("\\n");
}

// clear the linked list of ranges, and create a new one
// this should be called after every sqrt(N) updates
// \[N steps\]
void update\_ranges(struct List \*list) {
    int sqrtn \= sqrt(list->num\_contained);

    list->range \= NULL;
    struct Range \*prev\_range \= NULL;
    struct Node \*curr\_node \= list->head;
    while (curr\_node != NULL) {
        // initialise this\_range
        struct Range \*this\_range \= malloc(sizeof(struct Range));
        this\_range->num\_contained \= 0;
        this\_range->checkpoint \= curr\_node;
        while (curr\_node != NULL && this\_range->num\_contained + 1 <= sqrtn) {
            this\_range->num\_contained++;
            curr\_node \= curr\_node->next;
        }

        // add "this\_range" to the linked list of ranges
        if (list->range \== NULL) {
            list->range \= this\_range;
        } else {
            prev\_range->next \= this\_range;
        }
        prev\_range \= this\_range;
    }
}

// appendix of commands
void print\_help() {
    printf("+-----------------+-------------------------------------------+\\n");
    printf("|Command Name     | How to Use                                |\\n");
    printf("+=================+===========================================+\\n");
    printf("| INSERT          | Enter command: I \[INDEX\] \[VALUE\]          |\\n");
    printf("+-----------------+-------------------------------------------+\\n");
    printf("| REMOVE          | Enter command: R \[INDEX\]                  |\\n");
    printf("+-----------------+-------------------------------------------+\\n");
    printf("| QUERY           | Enter command: Q \[INDEX\]                  |\\n");
    printf("+-----------------+-------------------------------------------+\\n");
    printf("| PRINT           | Enter command: P                          |\\n");
    printf("+-----------------+-------------------------------------------+\\n");
    printf("| UPDATE RANGES   | Enter command: U                          |\\n");
    printf("+-----------------+-------------------------------------------+\\n");
    printf("\\n");
}

int main(void) {
    //printf("What is the initial value in the sqrt linked list: ");
    int val, i;
    scanf("%d", &val);

    struct List \*list \= init(val);

    print\_help();
    //printf("Enter command: ");

    // read in commands and perform them
    char option;
    while (scanf(" %c", &option) \== 1) {
        if (option \== CMD\_INSERT) {
            scanf("%d %d", &i, &val);
            insert(list, i, val);
        } else if (option \== CMD\_REMOVE) {
            scanf("%d", &i);
            rem(list, i);
        } else if (option \== CMD\_QUERY) {
            scanf("%d", &i);
            printf("%d\\n", query(list, i));
        } else if (option \== CMD\_UPDATE\_RANGES) {
            update\_ranges(list);
        } else if (option \== CMD\_PRINT) {
            print(list);
        } else {
            printf("Invalid command\\n");
        }

        //printf("Enter command: ");
    }
    
    printf("\\n");
    return 0;
}

```