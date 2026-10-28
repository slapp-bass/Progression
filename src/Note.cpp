#include "Note.h"

#include <string>
#include <unordered_map>

namespace cnv {
    // note conversions at the 4th octave (C4 is middle C, 60)
    const std::unordered_map<std::string, int> Note::midi_vals = { 
        {"C", 60},
        {"C#", 61},
        {"Db", 61},
        {"D", 62},
        {"D#", 63},
        {"Eb", 63},
        {"E", 64},
        {"F", 65},
        {"F#", 66},
        {"Gb", 66},
        {"G", 67},
        {"G#", 68},
        {"Ab", 68},
        {"A", 69},
        {"A#", 70},
        {"Bb", 70},
        {"B", 71}
    };

    /*
    Non-parameterized Constructor

    cnv::Note note = Note();
    std::cout << note.get_note() << std::endl;
    -> C
    std::cout << note.get_value() << std::endl;
    -> 60
    */
    Note::Note(){
        note = "C";
        value = midi_vals.at(note);
        octave = 4;
    }

    /*
    Parameterized Constructor

    cnv::Note note = Note("A", 3);
    std::cout << note.get_note() << std::endl;
    -> A
    std::cout << note.get_value() << std::endl;
    -> 57
    */
    Note::Note(std::string no, int oct){
        note = no;
        value = midi_vals.at(note);
        octave = oct;

        int difference = octave - 4;
        value = value + (difference * 12);
    }

    /*
    Getters

    cnv::Note note = Note("Bb", 2);
    std::cout << note.get_note() << std::endl;
    -> Bb
    std::cout << note.get_value() << std::endl;
    -> 46
    std::cout << note.get_octave() << std::endl;
    -> 2
    */
    std::string Note::get_note(){
        return this->note;
    }

    int Note::get_value(){
        return this->value;
    }

    int Note::get_octave(){
        return this->octave;
    }
}