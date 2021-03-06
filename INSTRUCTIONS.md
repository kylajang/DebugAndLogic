# CPSC 120-10 - Lab 6 - Instructions

This week we're going to work on controlling the flow of your program's logic using *if* and *else* statements, as well as get started with the very basics of an open source debugging tool called *gdb*.

## Part 0 - GDB

Before we get started with some code, we'll look at the program *gdb*. You can launch *gdb* from the command line like any other command. It should already be installed inside your Tuffix.

Take a moment to quickly browse the topics listed at [Debugging with GDB](http://sourceware.org/gdb/current/onlinedocs/gdb/). This is one of many documentation sources to help you learn *gdb*. You may need to reference it while completing this lab.

## Part 1 - Simple Relational Operators and GDB

We'll first look at some simple statements using relational operators, and use them as an excuse to point around *gdb*.

### Setup For Your Program

Start a new C++ program and corresponding Makefile. As usual, here are some details to use:

* Name the source file *main.cpp*
* Name the Makefile target *lab6-main* and set it as the default target
* Name the executable *lab6-main.bin*

As usual, executing ```make``` without any arguments should both compile and execute your program.

However, now that we're using *gdb*, we need to generate some things called *debug symbols* to help *gdb* understand your program. This means you need to add a new argument to your g++ compilation command:

```bash
-g
```

(that's a dash and a lower case g)

### Start Writing Your Program

1. Declare a boolean variable named *my_bool* in your program.

2. In the next statement, set the boolean variable to *true*.

3. In another statement, assign that boolean variable to the value of the following expression:

    * ```5 == 7```

4. Print the value of your boolean variable to the terminal.

5. Stop for a moment, before you compile+run your program, and ask yourself the following question:

    * *What will be the final value of the boolean variable?*
    * *Why will it have that value?*

### Start Debugging With GDB!

Now we're going to use GDB to inspect your program as it runs.

1. Make sure your program is compiled at this point. Also make sure you used the *-g* flag to compile, or *gdb* won't work.

2. Launch *gdb* on the command line by typing *gdb* and pressing enter (whoa!).

3. Notice that the terminal prompt is slightly different. The current line starts with the string *(gdb)*. You're inside the *gdhttp://sourceware.org/gdb/current/onlinedocs/gdb/Set-Breaks.html#Set-Breaksb* program now, and it's waiting for further commands!

4. Let *gdb* know you'd like to target your executable with the following command: ```file lab6-main.bin```. Notice *gdb* lets you know it's reading *symbols* from your executable. This is because your executable has special debug symbols you generated with the *-g* argument to *g++* earlier.

5. Let *gdb* know you'd like to run your program, with the command ```run```

6. That went by pretty fast, didn't it? Nothing really happened. There should be a message from *gdb* that your process exited normally. Try to find it.

7. Enter the ```run``` command again to make *gdb* run your program one more time. Don't feel lonely. We'll give *gdb* something to do now.

8. Look back to the source code of your program, and find two important line numbers:

    * The line corresponding to the statement where you assigned your boolen value to the result of the expression ```5 == 7```

    * The line where you printed your boolean variable

9. Tell *gdb* you'd like to halt execution when your program reaches either of those lines using the [break](http://sourceware.org/gdb/current/onlinedocs/gdb/Set-Breaks.html#Set-Breaks) command. One format the break command can take is the name of your source file and corresponding line number in a particular pattern. For example, if your source file is named *main.cpp*, and you'd like to break at lines 20 and 21, you would enter the following commands:

    * ```break main.cpp:20```
    * ```break main.cpp:21```

10. Make sure *gdb* printed a confirmation that your breakpoint was set in the correct file, at the correct line.

11. Issue another ```run```. Notice anything different? *Gdb* should halt execution early at your first breakpoint. You may even see the line number itself printed.

12. To inspect all local variables (so far that's just the *my_bool* variable), issue the command ```info locals```. You should see *gdb* print out the value of your *my_bool* variable.

13. Issue the command ```continue``` to tell *gdb* to continue execution of your program, until the next break.

14. *Gdb* should stop again quickly at your next break point. Print our your local variables again. Notice anything different about the *my_bool* variable? Put a new section in your *README.md* file entitled *Inspecting my_bool with break points*, and explain why the two prints showed different values (or not).

15. Enter the command ```continue``` again. Your program should finish executing. Take a screenshot of the results and save it in your repo using the name *debugging_my_bool.png*

16. Enter the command ```help``` to see a list of help topics you can learn about, to use with *gdb*.

17. Enter the command ```help info``` to see all the things the ```info``` command can show you. You may need to hit enter a few times to get through all the pages.

18. Quit *gdb* with the command: ```quit```

Wow, that was a lot! Keep in mind you're barely scratching the surface with *gdb*. *Gdb* is an extremely powerful debugger with many many more features than we'll cover this semester and it can save your life when you take more advanced C++ courses in the future. Keep it in mind and consider learning as much about it as you can.

Many students waste countless hours of frustration on their projects because they don't know how much *gdb* can truly help!

## Part 2 - Shortcut to GDB

Remember all those commands we had to use just to start debugging? You had to start gdb, load a file, run the file, set break points, and more. Wouldn't it be a huge drag to enter all those commands every time you wanted to compile+debug your program?

Well, do you remember we can put *any shell commands* we want inside our Makefile target recipes?

### Makefile Target

Let's create a Makefile target *just to debug* our program!

1. Create a new Makefile target named *debug-lab6-main*

2. Add your main program's executable path as a dependency. This way, executing the new debug target will also ensure your program is built first.

3. In your target's recipe, add a shell command to announce that the debugger is about to launch your program

4. In a second shell command, put the following:

    * ```gdb -x lab6-main-debug-commands.txt lab6-main.bin```

5. Create a new file named *lab6-main-debug-commands.txt* in the root of your repository.

6. Inside the new text file, place the two commands you used to set break points, followed by a ```run``` command.

7. Now launch your new target with ```make debug-lab6-main```, and note what happens.

8. Make a new section in your *README.md* file entitled *Shortcut to GDB* and answer the following questions:

    1. What do you see after executing the new Makefile target?

    2. Why did this happen?

    3. Did the program finish already, or is it currently halted, and why?

    4. How do you think you would proceed, before you could execute this Makefile target again?

9. Proceed until the program has finished, and quit *gdb*.

10. Take a screenshot of your terminal output and save it as the file name *shortcut_to_gdb.png* in your repo.

*Note*: The command in Step 4 doesn't use any Makefile variables, for clarity. However, it's still a good idea to use variables whenever they can help you avoid repeating the same strings, or to make it easier to change configurations. I would recommend using a variable for the *gdb* commands, as well as the text file of *gdb* commands and your executable.

## Part 3 - If/Else Shenanigans

Now let's get back to if/else statements. Add the following to your existing main.cpp program.

1. Ask the user to enter their favorite number, and store it in an integer variable.

2. For the following steps, use *only one* if/else-if/else block, do not nest your *if* statements, and do not use any logical operators. Meaning, there should only be *one* *if* statement, and each expression inside the ```if()``` or ```else if()``` statements should only have 1 logical component.

3. Using an *if* statement: If the user enters a 7, have the program print the following message: *Hey! Cool number!*.

4. Using an *else if* statement as a continuation of the previous statement, have the program print the following message *only if the user entered a number less than 11*: *Well, at least that's small enough to remember.*.

5. Using an *else* statement as a continuation of the previous statement, have the program print the following message *only if the previous two* *if/else* statements evaluated to false: *Sorry, I can't be bothered to count that high right now.*.

6. Repeat steps 3-5 but using only *if* and *else* statements, but not an *else if* statement. You may use nested statements to accomplish this. You may also use logical operators this time. *Hint1*: There are multiple valid ways to accomplish this. *Hint2*: Remember we have an inequality operator ```!=```.

## Part 4 - Short-Circuit Evaluation

Add the following code to the end of your program:

```cpp
if (false && true) {
    std::cout << "This is output from the Short-Circuit Evaluation part." << std::endl;
}
```

Next, create a new section in your *README.md* file entitled *Short Circuit Evaluation* and answer the following questions:

1. Did your program print the message from this section?

2. Why or why not?

3. Explain how you think this concept could help you write more complex if/else blocks.

## Part 5 - An Incredibly Simple Menu

For this part, add the following to the end of your program.

Print a menu out to the user. The menu should look like the following:

```text

Okay, now what do you want to do?

1. See your number again
2. Just quit

Your choice ==> 
```

Receive the user's input at the end of the *Your choice* line. Based on the user's input, respond in one of the following ways, as appropriate:

* Print the favorite number the user had previously entered.
* Do nothing (the program will naturally exit anyway).
* Complain that the user didn't enter a valid choice.

In any case, the program should first acknowledge the user's choice by mentioning it, before proceeding.






