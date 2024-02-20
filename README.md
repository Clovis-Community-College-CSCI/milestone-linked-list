# MILESTONE TWO: Doubly Linked Lists

## Introduction
Welcome to your *second* Milestone project. For this project you will work in
your group to benchmark Doubly Linked Lists using the [Standard Template Library(STL)](https://cppreference.com),
[ChatGPT](chat.openai.com), and one you will make entirely on your own.

This may seem really daunting, but the importance of learning data structures 
is extremely important. Through these Milestone projects, you will be
benchmarking multiple data structures then comparing and contrasting 
how each data structure does with ***insert***, ***search***, and ***delete***;
the main operations of each data structure.

Linked Lists may not be the most widely used data structure, but they are 
excellent at certain tasks. Some software will use linked lists to create
a music player or add redo/undo functionality. It is important to understand
the advantages and disadvantages of these data structures so you can make
software that is responsive to the user. In this milestone, you are to think
about what could be better uses for Linked Lists. Why do Singly Lists exist?
How could you better optimize a Linked List? What do you think a Linked List 
would be good or bad at?

## Project Assignment

As mentioned, you will be benchmarking the [list](https://en.cppreference.com/w/cpp/container/list)
container class in three separate implementations:

+ Standard Template Library (`DoublySTL.h` and `DoublySTL.cc`)
+ ChatGPT (`DoublyGPT.h` and `DoublyGPT.cc`)
+ Your Implementation (`DoublyLL.h` and `DoublyLL.cc`)

The difference in Milestone Two and Milestone One is that there is an interface
you will be operating in. `DoublyLL_Interface.h` is the interface you **MUST**
work in. All functions are within that header file. ***YOU ARE NOT ALLOWED TO
MODIFY DoublyLL_Interface.h AT ALL!*** You are encouraged to look at the
interface and read what each of the functions in the interface do. 

However, just like in Milestone One, you will be responsible for 
benchmarking Insert, Search, and Delete across the three implementations.
This will be your first time working with inheritance so below in the demo
code, is short demo of how a **derived** class and a **parent** class work.
Remember that the **parent** class is the what the **derived** class inherits
from. The standard method of explaining what inheritance is is Through
animals, so the code below would be for an animal class.

This is an example of a file named `Animal.h`:
```cpp
#pragma once // Header Guard

#include <string>

class Animal {
    // Remember that private means only the Animal class can access this variable
    private:
        std::string name; // Accessible only within animal class.
    // Protected means that the Animal and any derived classes are able 
    // to access it.
    protected: 
        int age; // Accessible within Animal class and derived classes
    // Public means main has access to everything inside of public.
    public:
        // Constructor
        Animal(std::string newName, int newAge) : name(newName), age(newAge) {}
        // Functions marked virtual mean that their output is going to change 
        // between derived classes. This allows for the Animal class to create 
        // one function but can be utilized for all derived classes one time!
        // Pretty cool, huh? Check out the Dog class for how we *override* it
        virtual void speak() { std::cout << "This animal speaks!" << std::endl; }
        // Getters
        std::string get_name() const { return name; }
        int get_age() const { return age; }
};

class Dog : public Animal {
    public:
    // Dog's constructor calls the base Animal constructor.
    Dog(std::string newName, int newAge) : Animal(newName, newAge) {}
    // The Dog class has an override on the virtual speak() function.
    // This means that instead of printing "This animal speaks!", it 
    // will print "BARK!" instead. Do not miss the override though 
    // otherwise you're gonna have a bad time.
    void speak() override { std::cout << "BARK!" << std::endl; }
    // Print all info
    void info() { 
        std::cout << "My name is " << get_name() << ". I'm " << get_age() << ." << std::endl; 
    }
};

int main() {
    Dog doggo("Doge", 3); // Make Doggo with Dog Constructor
    doggo.speak(); // Call doggo's speak function in Dog class
    doggo.info(); // Print doggo's stats
}
```

Inheritance is a lot but there are a lot of excellent uses for it. Many 
games utilize inheritance to write their game code. An "Actor" class could 
have a derived class named "Player" and "Enemy" class with functions to 
attack and health. For this Milestone -- and subsequent Milestones -- you 
will need to be comfortable working with an interface like `DoublyLL_Interface.h`.
Remember that all functions marked *virtual*, you will need to implement.

Now for the project, you will need to use *Proper Class Design* to 
implement the all the Linked List classes. This means you will 
have constructors and destructors in your public section of your class. 
You will also implement the following functions from the interface:

+ int front()
+ int back()
+ bool isEmpty()
+ uint64_t get_size()
+ void clear()
+ void insert_at(int pos, int newData)
+ bool contains(int key)
+ void erase(int pos)
+ void push_back(int newData)
+ void pop_back()
+ push_front(int newData)
+ int& at(uint64_t pos)
+ void pop_front()
+ void resize(int newSize)
+ void swap(uint64_t posOne, uint64_t posTwo)
+ void reverse()
+ void make_unique()
+ void merge(DoublyLL &other)
+ void splice(uint64_t pos, DoublyLL &other)
+ void print()

You will need to vet for proper inputs at all times and throw exceptions
if something does not make sense such as a negative value for a position.

## Role Responsibilities

### Project Manager (PM)

The general thought process of the project manager should be to do exactly
that: Manage the project. They are generally responsible for team morale, 
ensuring deadlines are met, and making sure the project is being done within
the budget. We'll be taking some of those principles into this project. 
Project Managers, you are directly responsible for the following:

#### Responsibilities of PM

+ Manage GitHub
+ Write Report
+ Schedule times to work with your group
+ Ensure the group is on the same page
+ Help teammates if they are falling behind
+ Establishing a method of communication from Day One!
+ Testing all changes to the repo to ensure nothing breaks
+ Documenting your progress in this README at the bottom

### STL Implementation (STLI)

The Standard Library Implementor has the easiest job of the group. This 
role is responsible for implementing their class with the [list](https://en.cppreference.com/w/cpp/container/list)
container in the Standard Library. On top of that, they are responsible
for implementing all benchmark files. STLI, you are directly responsible
for the following:

#### Responsibilities of STLI

+ Writing DoublySTL.h and DoublySTL.cc
+ Creating files to benchmark
+ Implementing everything in main.cc
+ Benchmarking the files you created
+ Testing your code and keeping track of how you tested it
+ Providing documentation (comments) in your code

### GPT Implementation (GPTI)

The ChatGPT (or any other LLM) had the second easiest (or hardest) job
of the group. This role is responsible for implementing their class with 
ChatGPT or any other LLM of their choice. Note: If you use a different 
AI, mention it in your report. On top of that, they are responsible for 
aggregating the data and testing everyone's code. GPTI, you are directly
responsible for the following:

#### Responsibilities of GPTI

+ Writing DoublyGPT.h and DoublyGPT.cc
+ Testing groupmates code, along with yours.
+ Making graphs and aggregating data for PM
+ Providing documentation (comments) in your code
+ Keep track of how much GPT got right and relay that in report.

### Your Implementation (YI)

Your implementator has the most difficult job of the group. This role
is responsible for implementing their class without any help from AI or 
the STL List container class. Due to the difficulty of this role, they 
only have to test their code. YI, you are directly responsible for the 
following: 

#### Responsibilities of YI

+ Writing DoublyLL.h and DoublyLL.cc
+ Testing your code and keeping track of how you tested it
+ Providing documentation (comments) in your code.

With these responsibilities defined, you should be able to more easily
determine if your groupmates did their job and relay it when you RAT. If 
there is a ghost, you will need to pick up that groupmates work and notify
Kerney or TA as fast as possible.

## Benchmarking

Benchmarking is the whole point of the project. Testing the main operations
with a vector, recording the times, and gathering information based on that.
Unlike in Milestone One, the sizes jumped considerably. Instead of going
up to 1 Million, you will be going up to 10 million instead. If you can't hit
the max, make sure you explain how many you were able to do and what you 
observed during the process. During the benchmarking stage, you will create 
the following files at these sizes:

+ insertOnly
    + 100
    + 1000
    + 10000
    + 100000
    + 250000
    + 500000
    + 750000
    + 1000000
    + 2500000
    + 5000000
    + 7500000
    + 9999999
+ insertAndSearch
    + 100
    + 1000
    + 10000
    + 100000
    + 250000
    + 500000
    + 750000
    + 1000000
    + 2500000
    + 5000000
    + 7500000
    + 9999999
+ MixTape 
    + 100
    + 1000
    + 10000
    + 100000
    + 250000
    + 500000
    + 750000
    + 1000000
    + 2500000
    + 5000000
    + 7500000
    + 9999999

For insertOnly, you will test how your code handles push_back() and insert.
The only commands in insertOnly should be *PUSH* and *INSERT*. For 
insertAndSearch, it will be the same as insertOnly except, you now have
to include *SEARCH*. You should test SEARCH extensively to make it about
half your commands per file. For MixTape, it will contain PUSH, INSERT, 
SEARCH, and *POP*. POP is the delete and you should call pop_back().

You will benchmark all those files on the STL, Your, and 
ChatGPT's Linked List 5 times each. Now that is a lot of time. 
You're doing over 100 runs total on your data and it'd be a pain to sit 
down all day doing it by hand. Well that is why in your directory, you 
have access to scripts and a program to help you generate your data. We
will go over this in class, but learning how to automate your life is 
an important skill. Don't be like the guy at UCSD's computer lab!

## Report

At the very end of this, you need to write up a report (4 or more pages) 
detailing what you learned from benchmarking the linked lists and explain 
what you found. You must include graphs showing how all three implementations
did across your data. You should also include your approach and you 
**must** answer this question: What was ChatGPT's error rate to your code?

Once you are finished with the report, you need to review and give 
feedback on your group by RATting them out. Once you're done, I will push
out a RAT program and you will give your feedback on each individual in 
your group, including yourself. ***THIS WILL NOT EFFECT YOURS OR YOUR 
GROUP MEMBER'S GRADES!*** Your feedback will help me select teams for the
next round.

## Grading

To get a good grade on this project, you will need to be proactive and 
communicate with your group. Once you have completed the assignment, you
must have pushed all your files to the GitHub classroom by the due date.
Failure to do so will impact your grade. Even if you aren't happy with 
how your project went, I ***highly*** recommend uploading whatever you 
have. The grade breakdown will be as follows:

#### Grading Breakdown: 
1. All Linked Implementations: 24 points
    1. 4 points based off your implementation of the STL Linked List class.
    2. 8 points based off your implementation of the GPT Linked List class.
    3. 12 points based off your implementation of your Linked List class.
2. Benchmark Report: 23 points
   1. 4 points for writing the report (3-5 pages, other requirements, etc.).
   2. 3 points for graphs in report with proper formatting.
   3. 8 points for quality of report (How much you learned, observations, etc.)
   4. 4 points for explaining what you did to debug.
   5. 4 points for a reflection on your group's performance. 
3. RATting out for 3 points.

Total: 50 points

When grading your linked list implementations, I will be looking for how 
well you implemented the functions from earlier in this README. The less
you do, you will get fewer points. The more bugs your code contains, the
fewer points you will get. Your report will be graded simply if you did it,
the quality of the report, graphing your data, and explaining what you did
to debug your code. Your last 3 points will be to ***Review All Teammates (RAT)***.
These points are gimme points for just participating in RATting out. 
**NO ONE'S GRADE WILL BE NEGATIVELY IMPACTED SO BE HONEST**. The only way
you'd lose points is if you just don't RAT, so please RAT!

## Conclusion

At the end of this assignment, you will have a much better understanding
of working in groups, class design, debugging your code, and how linked lists
work. You will also be able to give the time complexity of them based on
your report. This assignment is a small example of what upper-division
is like so take it seriously!

If you have any questions, ask me, Discord channel, or go to the [Tutorial Center](https://www.cloviscollege.edu/student-services/tutorial-center/index.html) for help. 
Good luck, have fun!
