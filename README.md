# Lab Week 6 Submission

My submission for CPSC 120-10, Lab Week 6

# My Information

* Name: Kyla Jang
* CWID: 888078243
* Email: kylajang@csu.fullerton.edu

# Inspecting my_bool with break points

The two prints showed different values because we initially set the variable to true, then at the break point at line 11, we reassigned it to false.

# Shortcut to GDB

1. I see the same thing as I would if I had manually gone into GDB and ran all of the commands separately. My file broke at the same points I assigned them to break at and got the same exact results.
2. This happened because when we wrote -x in our command line under the target debug-lab6-main, it read all the commands we placed in the .txt file.
3. It halted because of my break point at line 11.
4.  I would proceed by typing the command "continue".

# Short Circuit Evaluation

1. No, the program did not print the message.
2. It didn't print because in conditions of the if statement, we wrote (false && true). Both sides of the condition would have to be true in order for the message to print. However, one side of the condition was false, therefore, the message did not print.
3. 
