# Term Project - CSC 212 DSA
CSC212 Spring 2023 Final Project

## Summary
### Project Description:

We have created an educational card sorting application to compare four different sorting algorithms strengths and weaknesses on varying datasets or “decks”. The application has been developed to resemble an informative learning game which engages the user to decide which algorithm will perform most efficiently on their unique deck. We are using quick sort, gnome sort, insertion sort, and merge sort to perform the 4 different sorting operations throughout our program. This program is intended to be used as an interactive study tool to aid learning about time complexity and sorting algorithms. 
The application works by first taking in a text file of data representing different distinctions for “cards” and generating a presorted vector of strings holding all possible card elements. In order to create unique properties for the given deck each time the application is run, the size of the deck and the initial state of the cards within the deck are completely randomized. The idea of our game mimics a matching game in which the player’s goal is to correctly line up matching pairs of cards – Therefore, a pair of each card is present in their constructed “deck”. A random number is generated to determine the amount of pairs that will be pulled from the library and given to the user to be sorted. Another random number between 1 and 4 is generated to determine the initial state of the cards within the deck, at this stage one of four things can happen: The deck may remain the same leaving all cards in fully sorted order. The deck may be shuffled to be in reverse order. The deck may be slightly shuffled to be in partially sorted order. Or lastly, the deck may be fully shuffled with all cards in a completely randomized order. One of these processes is performed so that in each game, a unique case (deck) is represented and all of the sorting algorithms' strengths and weaknesses can be shown to the user for educational purposes. Understanding when certain sorting algorithms are best suited is an extremely valuable skill. 

### Project Structure:
The functionality of our program is housed within one main cpp file which contains all necessary implementations for the four different sorting algorithms recognized in our application. To perform the necessary processes for the merge sort we have developed three functions – A primary “merge_sort” function which will be called in main and a “merge” and “merge_sort_alg” helper function to recursively perform the merge sorting process. To perform the necessary processes for quick sort we have developed another three functions – A primary “quick_sort” function called in main, as well as two helper functions called “partition” and “quick_sort_alg”, which carry out the recursive quick sorting processes. We have also developed an “insertion_sort” function and “gnomesort” function to carry out those unique sorting implementations as well. Another key function implemented throughout our program is the “get_runtime” function which records the time allocated to performing each individual sorting algorithm on the original state of the user’s deck. Amongst these are other functions such as “print_rankings” and “print_key” which provide the user with appropriate feedback on their selection and extra information on the use cases for whichever sorting algorithm has been chosen. 
The main function carries out all of these processes upon runtime and handles the flow of execution for user input and output. After the creation of a unique deck, the user’s deck properties will be displayed. This will inform the user of the initial state of their cards (sorted, partially sorted, randomized, or reversed) as well as the size of their given deck. Considering this information, the user is asked to select the sorting algorithm which they believe will perform more efficiently in this unique case. After making their selection, the user will be given feedback on whether they made the correct or incorrect choice and provided with the runtimes and rankings of all four sorting algorithms. They will also be given data on the time complexity of their selected algorithm as well as a few points describing tendencies in best and worst use cases. The user is encouraged to run the application multiple times to gain a better understanding of the performance of each algorithm in relation to different properties in data (decks).

NOTE: All of the sorting algorithms are performed on their own preconditioned version of the initial deck. This way since we are individually running and recording runtimes for all four algorithms we can ensure that the unique properties of the user’s deck do not change for each sort. It is important to ensure that the correct runtime is recorded precisely on each sorting process so as not to interfere with the user's learning.

### Methods
The primary focus of our project was on the uses of three classic sorting algorithms accompanied by a fourth sorting algorithm we have learned outside of the course. Our group chose the “gnome” sorting algorithm as our fourth sorting type for the program. The sorting algorithms implemented were utilized to perform the calculations necessary to create the educational game we have developed, and fit the overall goal of our project.

**Insertion Sort:**
<br /> Insertion sort is a sorting algorithm where the code iterates through each element of the array and places it in the correct spot by shifting all of the larger elements to the right. The function takes the specified vector of strings as input, in this case the user’s deck, and returns the sorted version of the vector using the insertion sorting strategies. At first, the function gets the size of the input vector and iterates over each element of the vector. Starting at each index, it compares the current element to the previous elements. The function is constantly checking the value of the previous element with the current element until it finds the correct position for the value.  

**Merge Sort:**
<br /> The merge sort function takes a vector of strings as an input and returns a sorted vector. It calls the merge sort algorithm function that takes the vector, lowest index, and highest index as inputs. The merge sort algorithm function uses recursion to divide the vector into halves until the vector is sorted. The merge function is utilized to merge the sorted halves into one vector and then compares each element of the two sub-arrays from the original array. It then adds the smaller element to the original array.

**Quick Sort:**
<br /> The quick sort algorithm works by selecting an element from the array and partitioning the other elements into two sub-arrays if they are less than or greater than the pivot. The sub-arrays are sorted with recursion by applying a similar process until the sub-arrays are of size 1. This particular function takes a vector of specified strings as input and returns a new sorted vector using the specified quick sort algorithm. The function gets the size of the input vector and then calls the quick sort helper function, which takes the vector, lowest index, and highest index as inputs. The quick sort helper function uses recursion to partition the vector until it is sorted. 

**Gnome Sort:**
<br /> Gnome Sort in this program takes in an unsorted vector of strings and returns a new vector. Gnome Sort is a kind of variation of insertion sort that works without the need for a nested for loop.  This index can be both increased as well as decreased depending on where the value is placed. After getting this index, the algorithm takes the value at that index and compares the value to the left index and checks to see if that value is greater than the value being moved. If it is not then the index is moved back until it finds this point. Once it finds this point where the left is no longer greater than the current value then the algorithm moves the value to that position.


<describe program contents and files>

<methodology and algorithmic steps>
  
## Compilation Instructions
### Prefered Method
This program was developed using CLion during compilation and runtime. We recommend CLion for application use.

The argument you must provide in the program configurations should be input as follows:
<file name>
For example -
Program Arguments: "words.txt"

You must ensure all target executable files are added to CMakeLists.txt using. In order to add your target executable files, use the CMake add_executable function.
For example - 
add_executable(main.cpp)

Once you have modified the configurations and input all necessary program arguments, press the play button in the upper right hand corner to run the application.

### Alternative Method
If you are unable to use CLion to run the application you can compile in an alternative IDE such as Visual Studio Code using the "g++" compiler invocation command and "-o" command to generate the target executable file "prog".

This method of compilation is done within the terminal and should be input as follows:
g++ main.cpp -o prog 
Then, to run the program, the following input will be given in the terminal:
./prog <file name>

For example - 
In terminal: "./prog words.txt" would run the application.

### Input File Formatting:
Sample files have been provided in the repository for use.  
Data contained in file_name.txt is expected as follows:

string <br />
string <br />
string <br />
string <br />
... <br />
    
## Runtime Instruction
Each time you run the program you are presented with a different deck. It is important to consider how these properties might influence runtime when performing each sorting algorithm to order your pairs. You are prompted to select the option you believe will return the quickest runtime. You should do so by making your numerical selection and pressing “enter”. From there, the runtimes for all four sorting algorithms will be recorded, stored, and reported back. These calculations will be displayed to you in ranked order from most efficient to least efficient runtime.

The application will then tell you if your response was correct or incorrect and display the runtimes for 4 algorithms in comparison! By comparing these values, you may find some distinct differences in the way each algorithm performed. Finally, the program will restate the properties of your deck and provide you with further information on the time complexities and best/worst use case tendencies for the algorithm you have selected. Use this information to better understand why your selection performed accordingly and play the game again to keep practicing!

[^1]: The input file (in this case 'file_name.txt') is a large dataset of elements passed in by the first CLA.
  This is the file our program will be using to create your uniqie deck or cards.

#### Credits:
<modify to dsa program>
Project created by Brynne Wright, Daniel Huskey, Derrick Roberts, and Nicholas Wainwright. <br />
<br />
Brynne 
<br /> 
Developed implementations for the necessary processes of our program and designed the structure for application code. Performed testing and finalized working functions to create the functioning main.cpp. Wrote the project summary, overview, and implementation sections in the final project report. Wrote examples of correct and incorrect runtime cases in our final project report with sample I/O. Provided comprehensive compilation instructions in both our final project report and readme document. Created a readme document for the application with all neccessary contents. Created the powerpoint presentation. <br />
<br />
Daniel 
<br />
Added the Gnome sort function algorithm and assisted in deck shuffling implementations. Wrote about Gnome sort implementations in the final project report. Helped develop the readme file in GitHub. Helped Brynne resolve issues with recording runtimes and adjusting other necessary implementations. Updated file handling implementations and test files. Helped write the project summary in the final project report as well as other sections like planning and runtime. <br />
<br />
Derrick 
<br />
Added handling for file input in main. Worked on project planning. Wrote about troubleshooting and conclusions in the final project report. <br />
<br />
Nicholas 
<br />
Added the Quick sort and Merge sort algorithms and assisted in deck shuffling implementations. Wrote about sorting implementations and methods in the final project report. <br />
<br />

#### License:
[License](link)
