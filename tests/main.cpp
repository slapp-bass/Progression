#include "Note.h"
#include "Chord.h"

#include <iostream>
#include <string>
#include <vector>

int main(){
    std::string sampleN = "G";
    std::string sampleC = "C Major";

    std::vector<std::string> notes = {"C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab", "A", "Bb", "B"};

    // cnv::Note temp = cnv::Note();
    // std::cout << temp.get_note() << std::endl;
    // std::cout << temp.get_value() << std::endl;
    // std::cout << temp.get_octave() << std::endl;

    // std::cout<< std::endl;
    // for(int i = 0; i < 10; i++){
    //     for(auto it = notes.begin(); it != notes.end(); ++it){
    //         cnv::Note note = cnv::Note(*it, i);
    //         std::cout << note.get_value() << std::endl;
    //         std::cout << note.get_note() << std::endl;
    //         std::cout << note.get_octave() << std::endl;
    //     }
    // }
    
    cnv::Chord chord = cnv::Chord(sampleC, 4);
    std::vector<int> formula = chord.get_formula();
    for(auto it = formula.begin(); it != formula.end(); ++it){
        std::cout << *it << std::endl;
    }
    return 0;
}