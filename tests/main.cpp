#include "Convert.h"

#include <iostream>
#include <string>
#include <vector>

int main(){
    std::string sampleN = "C";
    std::string sampleC = "C Major";

    cnv::Note note = cnv::Note(sampleN, 4);
    std::cout << note.get_value() << std::endl;

    // cnv::Chord chord = cnv::Chord(sampleC, 4);
    // std::vector<int> formula = chord.get_formula();
    // for(int i = 0; i < formula.size(); i++){
    //     std::cout << formula[i] << std::endl;
    // }
    return 0;
}