#include <iostream>
#include <vector>
#include <random>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <string>

/*
 * BASIC DSA PROJECT IMPLEMENTATIONS
 *
 *
 * ADD:
 * CODE - Insertion Sort Function
 * CODE - Merge Sort Function
 * CODE - Quick Sort Function
 * CODE - ADDITIONAL Sort Function
 *      - 1 additional algorithm not present in class
 *
 *
 * MODIFICATIONS:
 * MOD - Animal library implemented using animal.txt file
 *     - Create other libraries ?
 * MOD - Main.cpp to handle deck class
 *     - Move functions to <deck.cpp>
 *     - Create get_runtime() and print_message() member functions
 *
 *
 * DECK CLASS:
 * <deck.h> <deck.cpp>
 * std::vector<std::string> deck;
 * int deck_size;
 * int initial_sort;
 * float insertion_time;
 * float merge_time;
 * float quick_time;
 * float additional_time;
 * Methods -
 * std::vector<std::string> insertion_sort(std::vector<std::string> deck);
 * std::vector<std::string> merge_sort(std::vector<std::string> deck);
 * std::vector<std::string> quick_sort(std::vector<std::string> deck);
 * std::vector<std::string> additional_sort(std::vector<std::string> deck);
 * int get_correct(float time1, float time2, float time3, float time4);
 * void print_rankings(float time1, float time2, float time3, float time4);
 * float get_runtime(std::vector<std::string> deck, int sort_num);
 * void print_message(int user_selection, int correct);
 *
 *
 * EXTRA:
 * Scoring
 * Return time complexity and number of comparisons for each sort
 * Possible runtime ties
 *
 */



// Insertion sorting function - MOD into deck class method
std::vector<std::string> insertion_sort(std::vector<std::string> deck){

    // CODE: Insertion sort implementation
    int n = deck.size();
    for (int i = 1; i < n; i++) {
        std::string key = deck[i];
        int j = i - 1;
        while (j >= 0 && deck[j] > key) {
            deck[j + 1] = deck[j];
            j--;
        }
        deck[j + 1] = key;
    }

    return deck;
}



// Merge sorting function - MOD into deck class method
void merge(std::vector<std::string>& deck, int left, int center, int right) {
    int n1 = center - left + 1;
    int n2 = right - center;

    std::vector<std::string> L(n1);
    std::vector<std::string> R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = deck[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = deck[center + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            deck[k++] = L[i++];
        } else {
            deck[k++] = R[j++];
        }
    }

    while (i < n1) {
        deck[k++] = L[i++];
    }

    while (j < n2) {
        deck[k++] = R[j++];
    }
}

void merge_sort_alg(std::vector<std::string>& deck, int left, int right) {
    if (left < right) {
        int center = left + (right - left) / 2;
        merge_sort_alg(deck, left, center);
        merge_sort_alg(deck, center + 1, right);
        merge(deck, left, center, right);
    }
}


std::vector<std::string> merge_sort(std::vector<std::string> deck){

    // CODE: Merge sort implementation
    int n = deck.size();
    merge_sort_alg(deck, 0, n - 1);

    return deck;
}



// Quick sorting function - MOD into deck class method
int partition(std::vector<std::string>& deck, int low, int high) {
    std::string pivot = deck[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (deck[j] < pivot) {
            i++;
            std::swap(deck[i], deck[j]);
        }
    }
    std::swap(deck[i + 1], deck[high]);
    return i + 1;
}

void quick_sort_alg(std::vector<std::string>& deck, int low, int high) {
    if (low < high) {
        int x = partition(deck, low, high);
        quick_sort_alg(deck, low, x - 1);
        quick_sort_alg(deck, x + 1, high);
    }
}


std::vector<std::string> quick_sort(std::vector<std::string> deck){

    // CODE: Quick sort implementation
    int n = deck.size();
    quick_sort_alg(deck, 0, n - 1);

    return deck;
}



// Additional sorting function - MOD into deck class method
std::vector<std::string> gnomeSort(std::vector<std::string> deck){
    
    int index = 0;
  
    while (index < deck.size()-1) {
        if (index == 0){
            index++;
        }
        if (deck[index] >= deck[index - 1]){
            index++;
        }else{
            std::swap(deck[index], deck[index - 1]);
            index--;
        }
    }
    return deck;
}



// Getter for fastest sorting algorithm runtime i.e. correct choice - MOD into deck class method
int get_correct(float time1, float time2, float time3, float time4){
    int correct = 1;
    float min = time1;
    std::vector<float> time = {time2, time3, time4};
    for(int i = 2; i <= 4; i++){
        if(time[i] < min){
            min = time[i];
            correct = i;
        } else if(time[i] > min){
            continue;
        } else{
            std::cout << "ERROR - TIE!" << std::endl; // Handling for tied runtimes ?
        }
    }
    return correct;
}


// Print Rankings - MOD into deck class method
void print_rankings(float time1, float time2, float time3, float time4){
    std::vector<float> rankings = {time1, time2, time3, time4};
    std::sort(rankings.begin(), rankings.end());
    std::string sort_str;

    std::cout << "Rank - Sorting Algorithm - Runtime" << std::endl;
    for(int i = 0; i < 4; i++){
        if(rankings[i] == time1){
            sort_str = "Insertion Sort";
        } else if(rankings[i] == time2){
            sort_str = "Merge Sort";
        } else if(rankings[i] == time3){
            sort_str = "Quick Sort";
        } else if(rankings[i] == time4){
            sort_str = "Additional Sort";
        }
        std::cout << i << " - " << sort_str << " - " << rankings[i] << std::endl;
    }
}

void print_graph();

int main() {
    // Animal library for possible cards - MOD into animal.txt input file
    std::vector<std::string> animal = {"alligator", "bird", "cat", "dog", "elephant", "frog", "goat", "hippo", "iguana", "jellyfish", "kangaroo", "lion", "monkey", "narwhal", "octapus", "penguin", "quail", "rabbit", "snake", "tiger", "unicorn", "viper", "walrus", "yak", "zebra"};

    // Set deck size to random int between 5-25
    int dMax = 25;
    int dMin = 5;
    int deck_size = rand() % (dMax - dMin + 1) + dMin;

    // Create deck vector
    std::vector<std::string> deck;
    // Add a pair of each animal to deck
    for(int i = 0; i <= deck_size; i++){
        deck.push_back(animal[i]);
        deck.push_back(animal[i]);
    }

    // Double deck_size to reflect pairs
    int temp = deck_size; // Save num animals
    deck_size *= 2;

    // Set initial deck sort to random state between 1-4 (Fully sorted, Partially sorted, Reversed, or Randomized)
    int sMax = 4;
    int sMin = 1;
    int initial_sort_num = rand() % (sMax - sMin + 1) + sMin;

    std::string initial_sort;
    if(initial_sort_num == 1){
        initial_sort = "fully sorted";

        // deck should already be fully sorted when constructed from library

    } else if(initial_sort_num == 2){
        initial_sort = "partially sorted";

        // CODE: Modify sorted deck to be partially sorted
        // i.e. shuffle deck[0] through deck[temp]
        std::vector<std::string> animalTemp;
        std::initial_sort(deck.begin(), deck.begin() + deck_size, deck.end());

    } else if(initial_sort_num == 3){
        // CODE: modify sorted deck to be in reverse order
        // i.e. reverse entire deck
        initial_sort = "reversed";
        std::vector<std::string> animalTemp;
        for(int x = animal.size();x>0;x--){
            animalTemp.push_back(animal[x]);  
        }
        animal = animalTemp;
        
    } else if(initial_sort_num == 4){
        initial_sort = "randomized";

        // CODE: modify sorted deck to be completely randomized
        // i.e. shuffle entire deck

    }


    /* GET_RUNTIME - - - - - - - - - - - - - - - - - - - - >
     *
     * After implementing deck class - the following runtime calculations will be done in the get_runtime() method
     *
     * insertion_time = get_runtime(deck, 1);
     * merge_time = get_runtime(deck, 2);
     * quick_time = get_runtime(deck, 3);
     * additional_time = get_runtime(deck, 4);
     *
     */

    // Insertion sort runtime calc
    std::vector<std::string> iDeck = deck;
    clock_t iStart, iFinish;
    float insertion_time;
    iStart = clock();
    insertion_sort(iDeck);
    iFinish = clock();
    insertion_time = iFinish - iStart;
    insertion_time /= 100; // ELAPSED TIME

    // Merge sort runtime calc
    std::vector<std::string> mDeck = deck;
    clock_t mStart, mFinish;
    float merge_time;
    mStart = clock();
    merge_sort(deck);
    mFinish = clock();
    merge_time = mFinish - mStart;
    merge_time /= 100; // ELAPSED TIME

    // Quick sort runtime calc
    std::vector<std::string> qDeck = deck;
    clock_t qStart, qFinish;
    float quick_time;
    qStart = clock();
    quick_sort(deck);
    qFinish = clock();
    quick_time = qFinish - qStart;
    quick_time /= 100; // ELAPSED TIME

    // Additional sort runtime calc
    std::vector<std::string> aDeck = deck;
    clock_t aStart, aFinish;
    float additional_time;
    aStart = clock();
    additional_sort(aDeck);
    aFinish = clock();
    additional_time = aFinish - aStart;
    additional_time /= 100; // ELAPSED TIME
    // GET_RUNTIME - - - - - - - - - - - - - - - - - - - - ^


    // Give user starting deck data
    std::cout << "Your Deck Properties:" << std::endl;
    std::cout << "Your deck is " << initial_sort << " and contains " << deck_size << " cards representing " << temp << " animal pairs." << std::endl;

    // Prompt user for sorting algorithm selection
    int user_selection; // 1-4
    std::cout << "Which sorting algorithm will sort your deck the fastest?" << std::endl;
    std::cout << "1 - Insertion Sort" << std::endl;
    std::cout << "2 - Merge Sort" << std::endl;
    std::cout << "3 - Quick Sort" << std::endl;
    std::cout << "4 - Additional Sort" << std::endl;
    std::cout << "Enter a number 1-4: ";
    std::cin >> user_selection;


    /* PRINT_MESSAGE - - - - - - - - - - - - - - - - - - - - >
     *
     * After implementing deck class - the following outputs will be generated using the print_message() method
     *
     * print_message(user_selection, correct);
     *
     */

    int correct = get_correct(insertion_time, merge_time, quick_time, additional_time);
    std::string correct_str;
    std::string user_str;
    float correct_time;
    float user_time;

    if(user_selection == 1){
        user_str = "insertion sort";
        user_time = insertion_time;
    } else if(correct == 2){
        user_str = "merge sort";
        user_time = merge_time;
    } else if(correct == 3){
        user_str = "quick sort";
        user_time = quick_time;
    } else if(correct == 4){
        user_str = "additional sort";
        user_time = additional_time;
    }

    if(correct == 1){
        correct_str = "insertion sort";
        correct_time = insertion_time;
    } else if(correct == 2){
        correct_str = "merge sort";
        correct_time = merge_time;
    } else if(correct == 3){
        correct_str = "quick sort";
        correct_time = quick_time;
    } else if(correct == 4){
        correct_str = "additional sort";
        correct_time = additional_time;
    }

    switch(user_selection){
        case 1:
            // Insertion
            if(correct == 1){
                std::cout << "That is correct! The optimal sorting algorithm for your deck is " << correct_str << " with a runtime of " << correct_time << "units." << std::endl;
            } else{
                std::cout << "That is incorrect. You chose " << user_str << " with a runtime of " << user_time << "units." << std::endl;
                std::cout << "The optimal sorting algorithm for your deck is " << correct_str << " with a runtime of " << correct_time << "units." << std::endl;
                std::cout << std::endl;
                print_rankings(insertion_time, merge_time, quick_time, additional_time);
                std::cout << "Refer to the graph below to see why " << correct_str << " is the optimal sort." << std::endl;
                std::cout << std::endl;
                print_graph();
            }
            break;
        case 2:
            // Merge
            if(correct == 2){
                std::cout << "That is correct! The optimal sorting algorithm for your deck is " << correct_str << " with a runtime of " << correct_time << "units." << std::endl;
            } else{
                std::cout << "That is incorrect. You chose " << user_str << " with a runtime of " << user_time << "units." << std::endl;
                std::cout << "The optimal sorting algorithm for your deck is " << correct_str << " with a runtime of " << correct_time << "units." << std::endl;
                std::cout << std::endl;
                print_rankings(insertion_time, merge_time, quick_time, additional_time);
                std::cout << "Refer to the graph below to see why " << correct_str << " is the optimal sort." << std::endl;
                std::cout << std::endl;
                print_graph();
            }
            break;
        case 3:
            // Quick
            if(correct == 3){
                std::cout << "That is correct! The optimal sorting algorithm for your deck is " << correct_str << " with a runtime of " << correct_time << "units." << std::endl;
            } else{
                std::cout << "That is incorrect. You chose " << user_str << " with a runtime of " << user_time << "units." << std::endl;
                std::cout << "The optimal sorting algorithm for your deck is " << correct_str << " with a runtime of " << correct_time << "units." << std::endl;
                std::cout << std::endl;
                print_rankings(insertion_time, merge_time, quick_time, additional_time);
                std::cout << "Refer to the graph below to see why " << correct_str << " is the optimal sort." << std::endl;
                std::cout << std::endl;
                print_graph();
            }
            break;
        case 4:
            // Additional
            if(correct == 4){
                std::cout << "That is correct! The optimal sorting algorithm for your deck is " << correct_str << " with a runtime of " << correct_time << "units." << std::endl;
            } else{
                std::cout << "That is incorrect. You chose " << user_str << " with a runtime of " << user_time << "units." << std::endl;
                std::cout << "The optimal sorting algorithm for your deck is " << correct_str << " with a runtime of " << correct_time << "units." << std::endl;
                std::cout << std::endl;
                print_rankings(insertion_time, merge_time, quick_time, additional_time);
                std::cout << "Refer to the graph below to see why " << correct_str << " is the optimal sort." << std::endl;
                std::cout << std::endl;
                print_graph();
            }
            break;
        default:

            // CODE

    }
    // PRINT_MESSAGE - - - - - - - - - - - - - - - - - - - - ^

}

// NOTES

/*
 // Lab 2 - Function for timing implementation
void time_func(uint16_t n, const char *name) {

    uint64_t val;
    unsigned long c_start, c_end;

    if (! strcmp(name, "function1")) {
        c_start = std::clock();
        val = function1(n);
        c_end = std::clock();

    }
    else if (! strcmp(name, "function2")) {
        c_start = std::clock();
        val = function2(n);
        c_end = std::clock();

    }
    else{
        std::cout << "Invalid function call" << std::endl;

    }

    float output = 1.0 * (c_end - c_start) / CLOCKS_PER_SEC;
    std::cout << name << " function(" << n << "):\t";
    std::cout << std::fixed << std::setprecision(4) << output << " Output: " << val << std::endl;
}

 // time_func usage in main -
 uint16_t n = (uint16_t) atoi(argv[1]);
 time_func(n, argv[2]);

*/

// Print Graph
void print_graph(){

    // Mockup graph idea for operations (runtime) correlation to deck size (# of elements)

    std::cout << "          1000 |             I                      M      Q       " << std::endl;
    std::cout << "               |                                                   " << std::endl;
    std::cout << "               |                                                   " << std::endl;
    std::cout << "               |                                                   " << std::endl;
    std::cout << "               |                                                   " << std::endl;
    std::cout << "               |           I                                       " << std::endl;
    std::cout << "               |                                                   " << std::endl;
    std::cout << " [Operations]  |                   M                               " << std::endl;
    std::cout << "           500 |                        Q                          " << std::endl;
    std::cout << "               |                                                   " << std::endl;
    std::cout << "               |        I                                          " << std::endl;
    std::cout << "               |           M                                       " << std::endl;
    std::cout << "               |             Q                                     " << std::endl;
    std::cout << "               |   M                                               " << std::endl;
    std::cout << "               | I Q                                               " << std::endl;
    std::cout << "               |_________________________________________________  " << std::endl;
    std::cout << "              0                       25                       50  " << std::endl;
    std::cout << "                                  [Deck Size]                      " << std::endl;
    std::cout << "                                                                   " << std::endl;
    std::cout << "  [KEY]                                                            " << std::endl;
    std::cout << "  I - Insertion Sort                                               " << std::endl;
    std::cout << "  M - Merge Sort                                                   " << std::endl;
    std::cout << "  Q - Quick Sort                                                   " << std::endl;
    std::cout << "  A - Additional Sort                                              " << std::endl;

}
