# cpp-graphing-calculator

This is a graphing calculator written entirely in C++ that takes user-specified polynomials (user-specified degree/constants) and displays the resultant graph in ASCII.

The code to visualize the function iterates a 100x100 2-D array of "tiles"-- each tile having a cartesian (X,Y) coordinate-- and if the plugged in X and Y values equate, the tile gets filled in with an ASCII character. The result prints a rudimentary graph of the function, and the equation of the polynomial underneath.

The calculator also visualizes trigonometric functions (using C++ library definitions for them, because typing out MacLaurin expansions is just what the library definitions are), but some functions (such as tan, arctan, and arccos) must be compressed to be visible on the graph. Thus, the calculator is more of a tool for visualization rather than a practical way to evaluate zeroes of functions/determine precise behavior.

Development is ongoing. Some current bugs:

Non-integer constants prints a blank screen

No error handling for type mismatch


