#include <iostream>
#include <vector>
#include <random>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <string>

// - - - - - - - - - - DSA PROJECT - - - - - - - - - -
// - - - Sorting algorithms - - -

// Insertion sort
std::vector<std::string> insertion_sort(std::vector<std::string> deck);
// Merge sort
void merge(std::vector<std::string>& deck, int left, int center, int right);
void merge_sort_alg(std::vector<std::string>& deck, int left, int right);
std::vector<std::string> merge_sort(std::vector<std::string>& deck);
// Quick sort
int partition(std::vector<std::string>& deck, int low, int high);
void quick_sort_alg(std::vector<std::string>& deck, int low, int high);
std::vector<std::string> quick_sort(std::vector<std::string> deck);
// Gnome sort
std::vector<std::string> gnomeSort(std::vector<std::string> deck);

int get_correct(float time1, float time2, float time3, float time4);
float get_runtime(std::vector<std::string> deck, int sort_num);

void print_rankings(float time1, float time2, float time3, float time4);
void print_message(int user_selection, int correct);

// Global variables?
float insertion_time;
float merge_time;
float quick_time;
float gnome_time;

// - - - MAIN - - -
int main() {
    // Animal library for possible cards - MOD into animal.txt input file
    std::vector<std::string> animal = {"alligator", "bird", "cat", "dog", "elephant", "frog", "goat", "hippo", "iguana", "jellyfish", "kangaroo", "lion", "monkey", "narwhal", "octopus", "penguin", "quail", "rabbit", "snake", "tiger", "unicorn", "viper", "walrus", "yak", "zebra"};

    // Set deck size to random int between 5-25
    std::default_random_engine rand_size;
    std::uniform_int_distribution<int> distribution1(5,25);
    int deck_size = distribution1(rand_size); // generates random integer in the range 5 - 25

    // int dMax = 25;
    // int dMin = 5;
    // int deck_size = rand() % (dMax - dMin + 1) + dMin;

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
    std::default_random_engine rand_initial_sort;
    std::uniform_int_distribution<int> distribution2(1,4);
    int initial_sort_num = distribution2(rand_initial_sort); // generates random integer in the range 1 - 4

    // int sMax = 4;
    // int sMin = 1;
    // int initial_sort_num = rand() % (sMax - sMin + 1) + sMin;

    std::string initial_sort;
    if(initial_sort_num == 1){
        initial_sort = "fully sorted";

        // deck should already be fully sorted when constructed from library

    } else if(initial_sort_num == 2){
        initial_sort = "partially sorted";

        // CODE: Modify sorted deck to be partially sorted
        // i.e. shuffle deck[0] through deck[temp]
        std::vector<std::string> tempDeck;
        // std::initial_sort(deck.begin(), deck.begin() + deck_size, deck.end()); // Why "std::initial_sort" ?

    } else if(initial_sort_num == 3){
        initial_sort = "reversed";

        // CODE: modify sorted deck to be in reverse order
        // i.e. reverse entire deck
        std::vector<std::string> tempDeck;
        // Deck tempDeck;
        for(auto x = deck.size(); x > 0; x--){
            tempDeck.push_back(deck[x]);
        }
        deck = tempDeck;

    } else if(initial_sort_num == 4){
        initial_sort = "randomized";

        // CODE: modify sorted deck to be completely randomized
        // i.e. shuffle entire deck
        std::shuffle(std::begin(animal), std::end(animal), std::default_random_engine());

    }

    // Give user starting deck data
    std::cout << "Your Deck Properties:" << std::endl;
    std::cout << "Your deck is " << initial_sort << " and contains " << deck_size << " cards representing " << temp << " animal pairs." << std::endl;

    // Prompt user for sorting algorithm selection
    std::cout << "Which sorting algorithm will sort your deck the fastest?" << std::endl;
    std::cout << "1 - Insertion Sort" << std::endl;
    std::cout << "2 - Merge Sort" << std::endl;
    std::cout << "3 - Quick Sort" << std::endl;
    std::cout << "4 - Additional Sort" << std::endl;
    int user; // 1-4
    std::cout << "Enter a number 1-4: ";
    std::cin >> user;
    std::cout << "You chose: " << user << std::endl;

    insertion_time = get_runtime(deck, 1);
    merge_time = get_runtime(deck, 2);
    quick_time = get_runtime(deck, 3);
    gnome_time = get_runtime(deck, 4);

    int corr = get_correct(insertion_time, merge_time, quick_time, gnome_time);

    // print_rankings(insertion_time, merge_time, quick_time, gnome_time);

    print_message(user, corr);
}


// - - - Sorting function implementations - - -

// Insertion sort
std::vector<std::string> insertion_sort(std::vector<std::string> deck){

    // CODE: Insertion sort implementation
    auto n = deck.size();
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

// Merge sort
void merge(std::vector<std::string>& deck, int left, int center, int right){

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

void merge_sort_alg(std::vector<std::string>& deck, int left, int right){

    if (left < right) {
        int center = left + (right - left) / 2;
        merge_sort_alg(deck, left, center);
        merge_sort_alg(deck, center + 1, right);
        merge(deck, left, center, right);
    }

}

std::vector<std::string> merge_sort(std::vector<std::string>& deck){

    // CODE: Merge sort implementation
    int n = deck.size();
    merge_sort_alg(deck, 0, n - 1);

    return deck;

}

// Quick sort
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

// Gnome sort
std::vector<std::string> gnomeSort(std::vector<std::string> deck){

    // CODE: Additional sort implementation
    // i.e. 1 additional algorithm not present in class
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


// - - - Correct answer and runtime function implementations - - -

int get_correct(float time1, float time2, float time3, float time4){ // FIX

    int correct = 1;
    float min = time1;
    std::vector<float> time = {time2, time3, time4};
    for(int i = 0; i < 3; i++){
        if(time[i] < min){
            min = time[i];

            switch(i){
                case 0:
                    correct = 2;
                    break;
                case 1:
                    correct = 3;
                    break;
                case 2:
                    correct = 4;
                    break;
                default:
                    correct = 1;
                    break;
            }

        } else if(time[i] > min){
            continue;
        } else{
            std::cout << "ERROR - TIE!" << std::endl; // Handling for tied runtimes ?
            break;
        }
    }
    return correct;

}

float get_runtime(std::vector<std::string> deck, int sort_num){ // FIX

    // Runtime calc
    std::vector<std::string> newDeck = deck; // Save original deck
    clock_t start, finish;
    float runtime;
    // start = clock();

    switch(sort_num){
        case 1:
            // Insertion sort
            start = clock();
            insertion_sort(deck);
            finish = clock();
            break;
        case 2:
            // Merge sort
            start = clock();
            merge_sort(deck);
            finish = clock();
            break;
        case 3:
            // Quick sort
            start = clock();
            quick_sort(deck);
            finish = clock();
            break;
        case 4:
            // Gnome sort
            start = clock();
            gnomeSort(deck);
            finish = clock();
            break;
        default:
            // CODE
            start = clock();
            finish = clock();
            break;
    }

    // finish = clock();
    runtime = finish - start;
    // runtime /= 100; // ELAPSED TIME

    deck = newDeck; // Restore original deck

    return runtime;

}


// - - - Print function implementations - - -

void print_rankings(float time1, float time2, float time3, float time4){ // FIX - Prints consecutive sorting types

    std::vector<float> rankings = {time1, time2, time3, time4};
    std::sort(rankings.begin(), rankings.end());
    std::string sort_str;

    std::vector<float> sorted_rankings;
    int r = rankings.size();

    // SORT RANKINGS VECT (array)

    std::cout << "Rank - Sorting Algorithm - Runtime" << std::endl;
    for(int i = 0; i < 4; i++){
        if(rankings[i] == time1){
            sort_str = "Insertion Sort";
        }
        if(rankings[i] == time2){
            sort_str = "Merge Sort";
        }
        if(rankings[i] == time3){
            sort_str = "Quick Sort";
        }
        if(rankings[i] == time4){
            sort_str = "Gnome Sort";
        }
        std::cout << i << " - " << sort_str << " - " << rankings[i] << std::endl;
    }

}

void print_message(int user_selection, int correct){

    // int correct = get_correct(insertion_time, merge_time, quick_time, gnome_time);
    std::string correct_str;
    std::string user_str;
    float correct_time;
    float user_time;

    // MOD to switch ?
    if(user_selection == 1){
        user_str = "insertion sort";
        user_time = insertion_time;
    }
    if(user_selection == 2){
        user_str = "merge sort";
        user_time = merge_time;
    }
    if(user_selection == 3){
        user_str = "quick sort";
        user_time = quick_time;
    }
    if(user_selection == 4){
        user_str = "gnome sort";
        user_time = gnome_time;
    }

    // MOD to switch ?
    if(correct == 1){
        correct_str = "insertion sort";
        correct_time = insertion_time;
    }
    if(correct == 2){
        correct_str = "merge sort";
        correct_time = merge_time;
    }
    if(correct == 3){
        correct_str = "quick sort";
        correct_time = quick_time;
    }
    if(correct == 4){
        correct_str = "gnome sort";
        correct_time = gnome_time;
    }

    // Does not need to be switch ! ! !
    switch(user_selection){
        case 1:
            // Insertion
            if(correct == 1){
                std::cout << "That is correct! The optimal sorting algorithm for your deck is " << correct_str << " with a runtime of " << correct_time << " units." << std::endl;
            } else{
                std::cout << "That is incorrect. You chose " << user_str << " with a runtime of " << user_time << " units." << std::endl;
                std::cout << "The optimal sorting algorithm for your deck is " << correct_str << " with a runtime of " << correct_time << " units." << std::endl;
                std::cout << std::endl;
                print_rankings(insertion_time, merge_time, quick_time, gnome_time);
                std::cout << "Refer to the graph below to see why " << correct_str << " is the optimal sort." << std::endl;
                std::cout << std::endl;
                // print_graph();
            }
            break;
        case 2:
            // Merge
            if(correct == 2){
                std::cout << "That is correct! The optimal sorting algorithm for your deck is " << correct_str << " with a runtime of " << correct_time << " units." << std::endl;
            } else{
                std::cout << "That is incorrect. You chose " << user_str << " with a runtime of " << user_time << " units." << std::endl;
                std::cout << "The optimal sorting algorithm for your deck is " << correct_str << " with a runtime of " << correct_time << " units." << std::endl;
                std::cout << std::endl;
                print_rankings(insertion_time, merge_time, quick_time, gnome_time);
                std::cout << "Refer to the graph below to see why " << correct_str << " is the optimal sort." << std::endl;
                std::cout << std::endl;
                // print_graph();
            }
            break;
        case 3:
            // Quick
            if(correct == 3){
                std::cout << "That is correct! The optimal sorting algorithm for your deck is " << correct_str << " with a runtime of " << correct_time << " units." << std::endl;
            } else{
                std::cout << "That is incorrect. You chose " << user_str << " with a runtime of " << user_time << " units." << std::endl;
                std::cout << "The optimal sorting algorithm for your deck is " << correct_str << " with a runtime of " << correct_time << " units." << std::endl;
                std::cout << std::endl;
                print_rankings(insertion_time, merge_time, quick_time, gnome_time);
                std::cout << "Refer to the graph below to see why " << correct_str << " is the optimal sort." << std::endl;
                std::cout << std::endl;
                // print_graph();
            }
            break;
        case 4:
            // Additional
            if(correct == 4){
                std::cout << "That is correct! The optimal sorting algorithm for your deck is " << correct_str << " with a runtime of " << correct_time << " units." << std::endl;
            } else{
                std::cout << "That is incorrect. You chose " << user_str << " with a runtime of " << user_time << " units." << std::endl;
                std::cout << "The optimal sorting algorithm for your deck is " << correct_str << " with a runtime of " << correct_time << " units." << std::endl;
                std::cout << std::endl;
                print_rankings(insertion_time, merge_time, quick_time, gnome_time);
                std::cout << "Refer to the graph below to see why " << correct_str << " is the optimal sort." << std::endl;
                std::cout << std::endl;
                // print_graph();
            }
            break;
        default:
            // CODE ?
            break;
    }

}
