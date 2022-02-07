# IMPLEMENTATION OF SORT COMMAND

## ABOUT

***SORT*** command is used to sort a file, arranging the records in a particular order. By default, the sort command sorts file assuming the contents are ASCII. Using options, the SORT command can also be used to sort numerically. 

***SORT*** command sorts the contents of a text file, line by line.
***SORT*** is a standard command-line program that prints the lines of its input or concatenation of all files listed in its argument list in sorted order.
The sort command is a command-line utility for sorting lines of text files. It supports sorting alphabetically, in reverse order, by number,by ignoring case sensitivity , and can also remove duplicates.

***External Sorting*** : Sorts the contents of the file externally if size of file is greater than the RAM. We divide the file into chunks that will fit inside the RAM and sort them individually and then merge it into a final output file using a modified heap.

## MADE WITH 

<img width="50" height="50" alt="help"  src="https://user-images.githubusercontent.com/82633814/152695427-d723c262-6f47-4ca0-968f-280325a1e66f.jpg">


## USAGE
./sort  [OPTION]  [FILE]

For merging two files:
Usage: ./sort  [OPTION] [FILE1] [FILE2]

For writing output to another file
Usage: ./sort -o [OUTPUT_FILE_NAME] [OPTION] [FILE]

The help command -h lists down all the available options along with their usage that can be used to sort a file accordingly.

<img width="500" height="400" alt="help" src="https://user-images.githubusercontent.com/82633814/152696362-1d74e521-8fff-46ff-810e-0d549ca4250b.png">

For example, If we want to sort a file numerically in desending order ,here's how we will execute it:-

<img  width="600" height="200" alt="number_sort" src="https://user-images.githubusercontent.com/82633814/152696415-25d0a40b-8b37-41e0-845c-c880b7fac189.png">



## CONTRIBUTORS
<a href="https://github.com/Vedanshi-Shah">VEDANSHI SHAH </a>

<a href="https://github.com/sneha-0723">SNEHA VENKATESWARAN </a>



