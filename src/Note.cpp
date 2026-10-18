#include "Note.h"

#include <string>
#include <vector>
#include <unordered_map>

namespace cnv {
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


    Note::Note(std::string no, int oct){
        note = no;
        value = midi_vals[note];
        octave = oct;

        int difference = octave - 4;
        value = value + (difference * 12);
    }

    std::string Note::get_note(){
        return this.note;
    }

    int Note::get_value(){
        return this.value;
    }
}