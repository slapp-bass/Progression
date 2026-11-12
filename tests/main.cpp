#include "Note.h"
#include "Chord.h"

#include <iostream>
#include <string>
#include <vector>

int main(){
    std::string sampleN = "G";
    std::string sampleC = "C Major";

    // std::vector<std::string> notes = {"C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab", "A", "Bb", "B"};

    // cnv::Note temp = cnv::Note();
    // std::cout << temp.get_output() << std::endl;

    // cnv::Note note = cnv::Note("A", 3);
    // std::cout << note.get_output() << std::endl;
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
    
    cnv::Chord chord = cnv::Chord("Bb Major", 4);
    std::vector<cnv::Note> notes = chord.get_notes();
    for(auto it = notes.begin(); it != notes.end(); ++it){
        std::cout << it->get_output() << std::endl;
    }
    std::cout<< "next chord" << std::endl;
    cnv::Chord chord2 = cnv::Chord("G# Major", 2);
    std::vector<cnv::Note> notes2 = chord2.get_notes();
    for(auto it = notes2.begin(); it != notes2.end(); ++it){
        std::cout << it->get_output() << std::endl;
    }
    std::cout<< "next chord" << std::endl;
    cnv::Chord chord3 = cnv::Chord("F# Major", 5);
    std::vector<cnv::Note> notes3 = chord3.get_notes();
    for(auto it = notes3.begin(); it != notes3.end(); ++it){
        std::cout << it->get_output() << std::endl;
    }
    std::cout<< "next chord" << std::endl;
    cnv::Chord chord4 = cnv::Chord("Gb Major", 5);
    std::vector<cnv::Note> notes4 = chord4.get_notes();
    for(auto it = notes4.begin(); it != notes4.end(); ++it){
        std::cout << it->get_output() << std::endl;
    }
    return 0;
}