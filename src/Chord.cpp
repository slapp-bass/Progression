#include "Chord.h"

#include <string>
#include <vector>
#include <unordered_map>

namespace cnv{

    // chromatic values for each note
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
    
    // opposite of the chromatic value map, int to string
    const std::unordered_map<int, std::string> Chord::note_vals = {
        {0, "C"},
        {1, "C#"},
        {1, "Db"},
        {2, "D"},
        {3, "D#"},
        {3, "Eb"},
        {4, "E"},
        {5, "F"},
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

    // chord formula map
    const std::unordered_map<std::string, std::vector<int> > Chord::chord_formula = {
        {"Major", {0, 4, 7}}
    };

    Chord::Chord(std::string cho, int oct){
        formula = chord_formula.at(cho);
        chord = cho;
        octave = oct;

        notes = this->get_note_vals();
    }

    std::vector<Note> Chord::get_note_vals(){
        std::vector<Note> notes;
        std::string root(this->chord, 0, this->chord.find_first_of(" "));
        int chrom_val = Chord::chromatic_vals.at(root);
        for(auto it = formula.begin(); it != formula.end(); ++it){
            Note note = Note(Chord::note_vals.at((chrom_val + *it) % 12), this->octave);
            notes.push_back(note);
        }

        return notes;
    }

    std::string Chord::get_chord(){
        return this->chord;
    }

    std::vector<int> Chord::get_formula(){
        return this->formula;
    }

    std::vector<Note> Chord::get_notes(){
        return this->notes;
    }

    int Chord::get_octave(){
        return this->octave;
    }

}