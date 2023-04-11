# Term Project - CSC 212 DSA
CSC212 Spring 2023 Term Project

## Summary
### Project Description:
We have created a **<name>** application to <goal of program>. The output will include <output>. The program will evaluate <blank> and provide <blank> based on the user request. 

### Project Structure:
The application utilizes <assigned data structure or algorithm> to perform the neccessary functionality.

<describe program contents and files>

<methodology and algorithmic steps>
  
## Compilation Instructions
<modify to dsa program>
```
**Prefered Method**
```
This program was developed using CLion during compilation and runtime. We recommend CLion for application use.

The arguments you must provide in the program configuration should be input as follows:
<list possible CLA inputs> or <prompted inputs>

You must ensure all target executable files are added to CMakeLists.txt using. In order to add your target executable files, use the CMake add_executable function.
For example - 
add_executable(csc212_gradebook Grades.cpp main.cpp)

Once you have modified the configurations and input all necessary program arguments, press the play button in the upper right hand corner to run the application.
For example - 
Program arguments: "my_grades.txt labs allgrades" would run the program to output all lab grades from my_grades.txt.
```
**Alternative Method**
```
If you are unable to use CLion to run the application you can compile in an alternative IDE such as Visual Studio Code using the "g++" compiler invocation command and "-o" command to generate the target executable file "prog".

This method of compilation is done within the terminal and should be input as follows:
g++ main.cpp Grades.cpp -o prog 
Then, to run the program, the following input will be given in the terminal:
./prog <file name> <type> <command>

For example - 
In terminal: "./prog my_grades.txt labs allgrades" would run the program to output all lab grades from my_grades.txt.
```
<br /> A multi-word CLA ***must*** be written in concatenation and all individual CLAs ***must*** be separated by whitespace.

<!-- Include screenshots to show examples of the program running (SS of how to compile, SS of example input file) -->

### Input File Formatting:
<modify to dsa program>
```
Data contained in file_name.txt

999 999 999 999 999 999 999 999 999 999 999 999
999 999 999 999
999 999
999
```

```
Structure of file_name.txt

LAB1 LAB2 LAB3 LAB4 LAB5 LAB6 LAB7 LAB8 LAB9 LAB10 LAB11 LAB12
ASSIGNMENT1 ASSIGNMENT2 ASSIGNMENT3 ASSIGNMENT4
REVIEWPROJECT FINALPROJECT
EXAM
```

## Planning
### Pseudocode / Flowcharts:
<modify to dsa program>

```
Pseudocode - Main.cpp
    
## Runtime Instruction
<modify to dsa program>
The first command line argument should ***always*** be the input file[^1]. <br />  
**The necessary command line arguments for utilizing the `Individual` class will be input as follows:**  
$ ./prog `file_name.txt`[^1] `INDIVIDUAL`[^2] `CATEGORY_OF_ASSIGNMENT`[^3] `ASSIGNMENT_NAME`[^4]    
    <br /> Valid inputs for `CATEGORY_OF_ASSIGNMENT`:    
    - 'Labs'   
    - 'ASSIGNMENTS'     
    - 'projects'     
    - 'EXAMS'      
    Examples of valid inputs for `ASSIGNMENT_NAME`:     
    - 'LAB1'   
    - 'Assignment3'    
    - 'REVIEWPROJECT'    
    - 'FinalProject'   
    - 'Exam'   
    Important notes:     
    `CATGORY_OF_ASSIGNMENT` ***must*** correspond with `ASSIGNMENT_NAME` <br />
    	- i.e. entering 'LABS' for `CATEGORY_OF_ASSIGNMENT` and 'ASSIGNMENT3' for `ASSIGNMENT_NAME` would result in an incorrect grade being returned.    
    No spaces should be left in input for `ASSIGNMENT_NAME` <br />
    	- i.e. entering 'ASSIGNMENT 3' for `ASSIGNMENT_NAME` would be invalid.
    If input is invalid, the program will break with an assert. <br />


[^1]: The input file (in this case 'file_name.txt') is your own dataset of grades passed in by the first CLA.
  This is the file our gradebook program will be evaluating or updating. 
  
[^2]: This string represents the 'type' variable which identifies the class you will be utilizing to evaluate your grades.

[^3]: This string represents the 'category' variable which identifies the catgeory of assignments within your grades that you wish to evaluate.

[^4]: This string represents the 'command' variable which identifies what data the user would like to return.
  EXCEPTION: When utilizing the Individual class, the 'command' variable represents the assignment name for the individual grade you wish to return.

## Sample Input/Output
<modify to dsa program>
<!-- Include screenshots with brief explanations of the images used →

### Test Cases:
<modify to dsa program>
<!-- Written tests for the application. Examples of how to run these tests. -->

#### Credits:
<modify to dsa program>
**Project created by Brynne Wright, Daniel Huskey, Derrick Roberts, and Nicholas Wainwright.** <br />
<br />
Brynne focused primarily on building <blank>. She developed <blank>. Lastly, she created a **readme** document for the application with all neccessary contents. <br />
<br />
Daniel focused primarily on building <blank>. He implemented <blank>... <br />
<br />
Derrick focused primarily on building <blank>. He implemented <blank>...<br />
<br />
Nicholas focused primarily on building <blank>. He implemented <blank>...<br />
<br />

#### License:
[License](link)
