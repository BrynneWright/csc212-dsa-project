// INCLUDE
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // rand() and srand()
#include <ctime> // Random and Runtime
#include <algorithm> // Shuffle
#include <random>
#include <iomanip> // Runtime
#include <utility> // Pairs
#include <fstream> // File input

// Functions
float get_runtime(std::vector<std::string> &deck, int sort_num);
void print_rankings(std::vector<std::pair<std::string, float>> &rankings);
void print_key(std::string shuffle, int num_cards, int choice);

// Insertion sort
std::vector<std::string> insertion_sort(std::vector<std::string> &deck);
// Merge sort
void merge(std::vector<std::string> &deck, int left, int center, int right);
void merge_sort_alg(std::vector<std::string> &deck, int left, int right);
std::vector<std::string> merge_sort(std::vector<std::string> &deck);
// Quick sort
int partition(std::vector<std::string> &deck, int low, int high);
void quick_sort_alg(std::vector<std::string> &deck, int low, int high);
std::vector<std::string> quick_sort(std::vector<std::string> &deck);
// Gnome sort
std::vector<std::string> gnomeSort(std::vector<std::string> &deck);

// MAIN
int main(int argc, char* argv[]){

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::ifstream input_file(filename);
    if (!input_file) {
        std::cerr << "Error: could not open file \"" << filename << "\"" << std::endl;
        return 1;
    }

    std::vector<std::string> file_library;

    std::string line;
    while (std::getline(input_file, line)) {
        file_library.push_back(line);
    }

    input_file.close();

    // Get random size for unique elements
    srand(time(nullptr)); // Initialize random seed based on current time
    int deck_size = (file_library.size() - 100) + rand() % 100;
    // Deck vector
    std::vector<std::string> deck;

    // Add a pair of each element to the deck as cards
    for(int i = 0; i <= deck_size; i++){
        deck.push_back(file_library[i]);
        deck.push_back(file_library[i]);
    }

    // Deck size x 2
    int num_animals = deck_size; // Save # elements
    deck_size *= 2;

    // Get random shuffle for deck (fully, partially, reversed, randomized)
    int initial_sort = rand() % 4 + 1; // Generates random # between 1 and 4 (inclusive)

    // Shuffle the deck accordingly
    std::string initial_sort_str;
    if(initial_sort == 1){
        initial_sort_str = "FULLY sorted";
        // deck should already be fully sorted when constructed from file elements
    } else if(initial_sort == 2){
        initial_sort_str = "PARTIALLY sorted";
        // Mod sorted deck to be partially sorted
        for (int x  = deck.size()/2 - 0 - 1; x > 0; --x){
            std::swap(deck[x], deck[std::rand() % (x + 1)]);
        }
    } else if(initial_sort == 3){
        initial_sort_str = "REVERSED";
        // Mod sorted deck to be reversed
        std::vector<std::string> tempDeck;
        // Deck tempDeck;
        for(auto x = deck.size(); x > 0; x--){
            tempDeck.push_back(deck[x]);
        }
        deck = tempDeck;
    } else if(initial_sort == 4){
        initial_sort_str = "RANDOMIZED";
        // Modify sorted deck to be randomized
        for (int x  = deck.size() - 0 - 1; x > 0; --x){
            std::swap(deck[x], deck[std::rand() % (x + 1)]);
        }
    }

    // Output starting deck properties to user
    std::cout << std::endl;
    std::cout << "About Your Deck:" << std::endl;
    std::cout << "Your deck is " << initial_sort_str << " and contains " << deck_size << " cards representing " << num_animals << " pairs!" << std::endl;
    std::cout << std::endl;

    // Prompt user for sorting algorithm selection
    std::cout << "Given these properties, which sorting algorithm will sort your deck the fastest?" << std::endl;
    std::cout << "1 - Insertion Sort" << std::endl;
    std::cout << "2 - Merge Sort" << std::endl;
    std::cout << "3 - Quick Sort" << std::endl;
    std::cout << "4 - Gnome Sort" << std::endl;
    int selected; // 1-4
    std::cout << "Enter a number 1-4: ";
    std::cin >> selected;
    std::cout << "You chose: " << selected << std::endl;

    std::cout << std::endl;
    selected -= 1; // Subtract 1 from user selection to set back to 0-3 range for index

    // Create data vector of pairs <std::string name, float time> to store algorithm name and runtime in selection order (insertion, merge, quick, gnome)
    std::vector<std::pair<std::string, float>> data;

    // Create deck copies to perform each sort
    std::vector<std::string> deck1 = deck;
    std::vector<std::string> deck2 = deck;
    std::vector<std::string> deck3 = deck;
    std::vector<std::string> deck4 = deck;

    // Get runtimes for each and push pairs to data vector
    std::pair<std::string, float> data_pair1("Insertion sort", get_runtime(deck1, 1));
    data.push_back(data_pair1);

    std::pair<std::string, float> data_pair2("Merge sort", get_runtime(deck2, 2));
    data.push_back(data_pair2);

    std::pair<std::string, float> data_pair3("Quick sort", get_runtime(deck3, 3));
    data.push_back(data_pair3);

    std::pair<std::string, float> data_pair4("Gnome sort", get_runtime(deck4, 4));
    data.push_back(data_pair4);

    // Create rankings vector of pairs <std::string name, float time> to store algorithm name and runtime in ascending order (fastest -> slowest)
    std::vector<std::pair<std::string, float>> rankings = data;

    // Sort rankings vector by runtime in ascending order
    std::sort(rankings.begin(), rankings.end(), [](const std::pair<std::string, float> &a, const std::pair<std::string, float> &b){
        return a.second < b.second;
    });

    /*
    // Print to check for testing only
    std::cout << "DATA:" << std::endl;
    for(const auto &i : data){
        std::cout << i.first << " - " << std::fixed << std::setprecision(4) << i.second << std::endl;
    }
    std::cout << std::endl;

    // Print to check for testing only
    std::cout << "RANKINGS:" << std::endl;
    for(const auto &it : rankings){
        std::cout << it.first << " - " << std::fixed << std::setprecision(4) << it.second << std::endl;
    }
    std::cout << std::endl;
    */

    // Set correct answer to fastest sorting algorithm name and runtime to correct variables
    std::string correct_name = rankings[0].first;
    float correct_time = rankings[0].second;

    // Set selected sorting algorithm name and runtime to selected variables
    std::string selected_name = data[selected].first;
    float selected_time = data[selected].second;

    // Output message if correct / incorrect
    if(correct_name == selected_name){
        std::cout << "That is correct! The optimal sorting algorithm for your deck is " << correct_name << " with a runtime of " << correct_time << " units." << std::endl;
        std::cout << std::endl;
        std::cout << "Here are the recorded runtimes for all 4 sorting algorithms:" << std::endl;
    } else if(correct_time == selected_time){ // TIE
        std::cout << "That is correct! The optimal sorting algorithm for your deck is " << selected_name << " with a runtime of " << selected_time << " units." << std::endl;
        std::cout << std::endl;
        std::cout << "Here are the recorded runtimes for all 4 sorting algorithms:" << std::endl;
    } else{
        std::cout << "That is incorrect. You chose " << selected_name << " with a runtime of " << selected_time << " units." << std::endl;
        std::cout << "The optimal sorting algorithm for your deck is " << correct_name << " with a runtime of " << correct_time << " units." << std::endl;
        std::cout << "Refer to the runtime rankings and time complexity data below to understand why " << selected_name << " was not a good fit." << std::endl;
        std::cout << std::endl;
    }

    // Print rankings for runtimes
    print_rankings(rankings);

    // Print key for feedback on time complexity logic and reasoning
    print_key(initial_sort_str, deck_size, selected);

}

void print_key(std::string shuffle, int num_cards, int choice){ // Modify to print user selected and correct only

    std::cout << "Your deck was made up of " << num_cards << " " << shuffle << " cards representing " << num_cards / 2 << " pairs." << std::endl;
    std::cout << "The information below provides further insight into why the sorting algorithm you selected performed as recorded." << std::endl;
    std::cout << std::endl;

    switch(choice){
        case 0:
            std::cout << "Insertion Sort" << std::endl;
            std::cout << "BEST CASE: O(n)" << std::endl;
            std::cout << "AVERAGE CASE: O(n^2)" << std::endl;
            std::cout << "WORST CASE: O(n^2)" << std::endl;
            std::cout << " - Best for small decks" << std::endl;
            std::cout << " - Best for partially or fully sorted decks" << std::endl;
            std::cout << " - Inefficient for large decks due to multiple iterations" << std::endl;
            std::cout << " - Worst case for randomized decks" << std::endl;
            std::cout << std::endl;
            break;
        case 1:
            std::cout << "Merge Sort" << std::endl;
            std::cout << "BEST CASE: O(n log n)" << std::endl;
            std::cout << "AVERAGE CASE: O(n log n)" << std::endl;
            std::cout << "WORST CASE: O(n log n)" << std::endl;
            std::cout << " - Best for reversed or partially sorted decks" << std::endl;
            std::cout << " - Efficient for large decks but may find limitations due to merging" << std::endl;
            std::cout << " - Inefficient for large randomized decks due to merging" << std::endl;
            std::cout << std::endl;
            break;
        case 2:
            std::cout << "Quick Sort" << std::endl;
            std::cout << "BEST CASE: O(n log n)" << std::endl;
            std::cout << "AVERAGE CASE: O(n log n)" << std::endl;
            std::cout << "WORST CASE: O(n^2)" << std::endl;
            std::cout << " - Best for large decks" << std::endl;
            std::cout << " - Efficient for randomized decks due to partitioning" << std::endl;
            std::cout << " - Inefficient for partially sorted or reversed decks" << std::endl;
            std::cout << " - Fastest for small sorted decks but slowest for larger sorted decks" << std::endl;
            std::cout << std::endl;
            break;
        case 3:
            std::cout << "Gnome Sort" << std::endl;
            std::cout << "BEST CASE: O(n)" << std::endl;
            std::cout << "AVERAGE CASE: O(n^2)" << std::endl;
            std::cout << "WORST CASE: O(n^2)" << std::endl;
            std::cout << " - Best for small decks" << std::endl;
            std::cout << " - Best for partially or fully sorted decks" << std::endl;
            std::cout << " - Worst case for randomized decks" << std::endl;
            std::cout << " - Oftentimes less efficient than insertion sort due to backward steps and swaps" << std::endl;
            break;
        default:
            std::cout << "Invalid Key Choice" << std::endl;

    }
}

void print_rankings(std::vector<std::pair<std::string, float>> &rankings){
    std::cout << "Rank - Sorting Algorithm - Runtime" << std::endl;
    for(int i = 0; i < 4; i++){
        std::cout << i + 1 << " - " << rankings[i].first << " - ";
        std::cout << std::fixed << std::setprecision(4) << rankings[i].second << std::endl;
    }
    std::cout << std::endl;
}

float get_runtime(std::vector<std::string> &deck, int sort_num){

    clock_t start, finish;

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
            std::cout << "Invalid Sorting Algorithm. Please provide a value between 1-4." << std::endl;
            return -1.0;
    }
    float runtime = ((float)(finish - start)) / CLOCKS_PER_SEC;

    return runtime;
}

// Insertion sort
std::vector<std::string> insertion_sort(std::vector<std::string> &deck){

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
void merge(std::vector<std::string> &deck, int left, int center, int right){

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

void merge_sort_alg(std::vector<std::string> &deck, int left, int right){

    if (left < right) {
        int center = left + (right - left) / 2;
        merge_sort_alg(deck, left, center);
        merge_sort_alg(deck, center + 1, right);
        merge(deck, left, center, right);
    }

}

std::vector<std::string> merge_sort(std::vector<std::string> &deck){

    // CODE: Merge sort implementation
    int n = deck.size();
    merge_sort_alg(deck, 0, n - 1);

    return deck;

}

// Quick sort
int partition(std::vector<std::string> &deck, int low, int high) {
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

void quick_sort_alg(std::vector<std::string> &deck, int low, int high) {
    if (low < high) {
        int x = partition(deck, low, high);
        quick_sort_alg(deck, low, x - 1);
        quick_sort_alg(deck, x + 1, high);
    }
}

std::vector<std::string> quick_sort(std::vector<std::string> &deck){

    // CODE: Quick sort implementation
    int n = deck.size();
    quick_sort_alg(deck, 0, n - 1);

    return deck;

}

// Gnome sort
std::vector<std::string> gnomeSort(std::vector<std::string> &deck){

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
