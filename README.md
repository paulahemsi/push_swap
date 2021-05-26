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

* to better visualize the instructions we have available, I firts built the [push_swap_simulator](https://phemsi-a.itch.io/push-swap)

![](./study_resources/simulator.gif)

* error handling

* implementation of functions for each instruction ( *swap*, *push*, *rotate*, *reverse rotate* )

## study_resources

## work_diary

<details>
  <summary>Click to expand </summary>

* 22/05: After reading the pdf, I felt that will be god to have a way of visualizing the set of possible instructions I have, so I start to make a simulator prototype in Unity

* 23/05: finished simulator prototype

* 24/05: I made a simple makefile to start, coded handling error functions (non-integers inputs, integer overflow and numbers duplicates) and initialized stack_a with linked lists.

* 25/05: I was having a issue with `0` passing as argument, so I changed the way I was checking if the args are all integers. Swap, push, rotate and reverse rotate are implemented. I choose to change my linked list to make then doubly linked list, so I can keep track of the previous and next numbers
