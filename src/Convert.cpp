#include "Convert.h"

#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

namespace cnv{
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
        value = midivals[note];
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

    const std::unordered_map<std::string, int> Chord::chromatic_vals = {
        {"C", 0},
        {"C#", 1},
        {"Db", 1},
        {"D", 2},
        {"D#", 3},
        {"Eb", 3},
        {"E", 4},
        {"F", 5},
        {"F#", 6},
        {"Gb", 6},
        {"G", 7},
        {"G#", 8},
        {"Ab", 8},
        {"A", 9},
        {"A#", 10},
        {"Bb", 10},
        {"B", 11}
    };
    
    const std::unordered_map<int, std::string> Chord::note_vals = {
        {0, "C"},
        {1, "C#"},
        {1, "Db"},
        {2, "D"},
        {3, "D#"},
        {3, "Eb"},
        {4, "E"},
        {5, "F"}
        {6, "F#"},
        {6, "Gb"},
        {7, "G"},
        {8, "G#"},
        {8, "Ab"},
        {9, "A"},
        {10, "A#"},
        {10, "Bb"},
        {11, "B"}
    };

    Chord::chord_formula = {
        {"Major", {0, 4, 7}}
    };

    Chord::Chord(std::string cho, int oct){
        formula = chordFormula[oct];
        chord = cho;
        octave = oct;

        notes = this.get_note_vals();
    }

    std::vector<Note> Chord::get_note_vals(){
        std::vector<int> notes;
        std::string root(this.chord, 0, this.chord.std::find_first_of(" "));
        int chrom_val = Chord::chromatic_vals[root];
        for(int i = 0; i < formula.size(); i++){
            Note note = Note(Chord::note_vals[(chrom_val + formula[i]) % 12], this.octave);
            notes.push_back(note);
        }

        return notes;
    }

    std::string Chord::get_chord(){
        return this.chord;
    }

    std::vector<int> Chord::get_formula(){
        return this.formula;
    }

    std::vector<int> Chord::get_notes(){
        return this.notes;
    }

    int Chord::get_octave(){
        return this.octave;
    }

}