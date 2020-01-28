# sort_stack

The Push_swap project is a very simple and highly effective algorithm project: data will
need to be sorted. You have at your disposal a set of int values, 2 stacks and a set of
instructions to manipulate both stacks.

Your goal ? Write 2 programs in C:

• The first, named checker which takes integer arguments and reads instructions on
the standard output. Once read, checker executes them and displays OK if integers
are sorted. Otherwise, it will display KO.

• The second one called push_swap which calculates and displays on the standard
output the smallest progam using Push_swap instruction language that sorts integer arguments received.

Easy?
We’ll see about that...

The goal is to sort in ascending order numbers into stack a.
To do this you have the following operations at your disposal:

sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements).

sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements).

ss : sa and sb at the same time.

pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.

pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.

ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.

rb : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.

rr : ra and rb at the same time.

rra : reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one.

rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one.

rrr : rra and rrb at the same time.


General Instructions

• This project will only be corrected by actual human beings. You are therefore free
to organize and name your files as you wish, although you need to respect some
requirements listed below.
• The firts executable file must be named checker and the second push_swap.
• You must submit a Makefile. That Makefile needs to compile the project and
must contain the usual rules. It can only recompile the program if necessary.
• If you are clever, you will use your library for this project, submit also your folder
libft including its own Makefile at the root of your repository. Your Makefile
will have to compile the library, and then compile your project.
• Global variables are forbidden.
• Your project must be written in C in accordance with the Norm.
• You have to handle errors in a sensitive manner. In no way can your program quit
in an unexpected manner (Segmentation fault, bus error, double free, etc).
• Neither program can have any memory leaks.
• You’ll have to submit at the root of your folder, a file called author containing your
username followed by a ’\n’
$>cat -e author
xlogin$
• Within your mandatory part you are allowed to use the following functions:
◦ write
◦ read
◦ malloc
◦ free
◦ exit
• You can ask questions on the forum & Slack...
