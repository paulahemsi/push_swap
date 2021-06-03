# push_swap
 simple and highly effective algorithm project | école 42

*in process*

* [Introduction](#introduction)
* [Usage](#usage)
* [Step by step](#step_by_step)
* [Study resources](#study_resources)
* [Work Diary](#work_diary)

## introduction

This [project](./study_resources/en.subject.pdf) is about sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed I’ll have to manipulate various types of algorithms and choose the one (of many) most appropriate solution for an optimized data sorting.

Push_swap program needs to calculate and display on the standard output the smallest sequence of instruction that sorts the integer arguments received.

The game is composed of 2 stacks named a and b.

*Stack_a* contains a random number of either positive or negative numbers without any duplicates.

*Stack_b* is empty.

The goal is to sort in ascending order numbers into *stack_a* using the following operations:


command  | action |
---|------|
`sa` | swap a - swap the first 2 elements at the top of *stack_a*					|
`sb` | swap b - swap the first 2 elements at the top of *stack_b*	|
`ss` | sa and sb at the same time |
`pa` | push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty|
`pb` | push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty |
`ra` | rotate a - shift up all elements of *stack_a* by 1. The first element becomes the last one			|
`rb` | rotate b - shift up all elements of *stack_b* by 1. The first element becomes the last one 		|
`rr` | ra and rb at the same time			|
`rra` |  reverse rotate a - shift down all elements of *stack_a* by 1. The last element becomes the first one	|
`rrb` |  reverse rotate b - shift down all elements of *stack_b* by 1. The last element becomes the first one	|
`rrr` | rra and rrb at the same time		|


## usage

## step_by_step

* to better visualize the instructions we have available, I first built the [push_swap_simulator](https://phemsi-a.itch.io/push-swap)

![](./study_resources/simulator.gif)

* error handling

* implementation of functions for each instruction ( *swap*, *push*, *rotate*, *reverse rotate* )

* implementation of my first intuitive sorting algorithm

* studing big O notation and sorting algorithms

* implementation of a sorted array to have as reference


## study_resources

* [how big_O notation works– explained with cake](https://www.freecodecamp.org/news/big-o-notation/)
* [the quicksort sorting algorithm video](https://www.youtube.com/watch?v=uXBnyYuwPe8)
* [quick sort -ptbr](https://joaoarthurbm.github.io/eda/posts/quick-sort/)

## work_diary

<details>
  <summary>Click to expand </summary>

* 22/05: After reading the pdf, I felt that it would be good to have a way of visualizing the set of possible instructions that I have, so I started to make a simulator prototype in Unity

* 23/05: simulator prototype finished 

* 24/05: I made a simple makefile to start, coded handling error functions (non-integer inputs, integer overflow and number duplicates) and initialized stack_a with linked lists.

* 25/05: I was having an issue with `0` passing as argument, so I changed the way I was checking if the args are all integers. Swap, push, rotate and reverse rotate are implemented. I chose to change my linked list to make them a doubly linked list, so I can keep track of the previous and following numbers

* 26/05: Functions to check if stack_a are full and sorted are implemented and working properly

* 27/05: I added a function to check if a stack is reverse sorted, and implemented a logic to sort the numbers:
  * check if stack_a is sorted and if stack_b is reverse sorted, to decide what steps to make
  * define between three numbers (first, second, and last) from stack_a wich one is the smallest and send it to stack_b, placing in the best of three spots (first, second and last)
  * when stack_a is sorted and stack_b is reverse sorted, push numbers from b to a

* 28/05: While trying to find a bug, I discovered a problem in swap function with the previous pointer management and fixed it

* 29/05: The program is being able to sort any amount of numbers without any issues, but it is not optimized, therefore bigger numbers (>100) are taking too many steps

* 30/05: In order to optimize the code, I studied sorting algorithms and started to code a function that makes an ordered array from the number list

* 31/05: I  organized my variables inside structs and implemented a quick sort function to order the array that will be used as reference. The rest of the day was spent trying to make this new sorting try, passing to stack_b the lower half of the numbers

* 02/06: hello ~~darkness~~ procrastination my old friend
