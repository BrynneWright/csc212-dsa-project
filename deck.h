#ifndef INC_212DSAPROJECT_DECK_H
#define INC_212DSAPROJECT_DECK_H

#include <iostream>
#include <vector>
#include <random>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <algorithm>

class Deck {
private:
    std::vector<std::string> deck;
    int deck_size;
    int initial_sort;
    float insertion_time;
    float merge_time;
    float quick_time;
    float additional_time;

public:
    Deck();
    ~Deck();
    std::vector<std::string> insertion_sort(std::vector<std::string> deck);
    std::vector<std::string> merge_sort(std::vector<std::string> deck);
    std::vector<std::string> quick_sort(std::vector<std::string> deck);
    std::vector<std::string> additional_sort(std::vector<std::string> deck);
    int get_correct(float time1, float time2, float time3, float time4);
    void print_rankings(float time1, float time2, float time3, float time4);
    float get_runtime(std::vector<std::string> deck, int sort_num);
    void print_message(int user_selection, int correct);

};


#endif // INC_212DSAPROJECT_DECK_H
