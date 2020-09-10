Simple calculator. Just practice.

The program consits of data, parser, calculator and communicator classes. Data is just for data storage and error handling.
Communicator handles input and output, therefore neither parser, nor calculator does not know anything about the source of their input.
Parser class just parser the input string. It breaks it up into numbers, operations and parentheses. 

Calculator class handles all the calculations. The algorithm for that is messy, but, unfortunately I didn;t come up with something better.
I handle parentheses with a map that has keys "(" and ")". These keys correspond to a vector of numbers of operations before the corresponding parenthesis.
