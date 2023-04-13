#include "deck.h"

// Building deck class

//Constructor
Deck::Deck(){
    this->deck_size = 0;
    this->initial_sort = 0;
    this->insertion_time = 0;
    this->merge_time = 0;
    this->quick_time = 0;
    this->additional_time = 0;
}

Deck::~Deck(){

}

//Methods
std::vector<std::string> Deck::insertion_sort(std::vector<std::string> deck){

}

std::vector<std::string> Deck::merge_sort(std::vector<std::string> deck){

}

std::vector<std::string> Deck::quick_sort(std::vector<std::string> deck){

}

std::vector<std::string> Deck::additional_sort(std::vector<std::string> deck){

}

int Deck::get_correct(float time1, float time2, float time3, float time4){

}

float Deck::get_runtime(std::vector<std::string> deck, int sort_num){

}

void Deck::print_rankings(float time1, float time2, float time3, float time4){

}

void Deck::print_message(int user_selection, int correct){

}
