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
    const std::unordered_map<int, std::vector<std::string> > Chord::note_vals = {
        {0, {"C"}},
        {1, {"C#", "Db"}},
        {2, {"D"}},
        {3, {"D#", "Eb"}},
        {4, {"E"}},
        {5, {"F"}},
        {6, {"F#", "Gb"}},
        {7, {"G"}},
        {8, {"G#", "Ab"}},
        {9, {"A"}},
        {10, {"A#", "Bb"}},
        {11, {"B"}}
    };

    // chord formula map
    const std::unordered_map<std::string, std::vector<int> > Chord::chord_formula = {
        {"Major", {0, 4, 7}},
    };

    Chord::Chord(){
        root = "C";
        chord_type = "Major";
        formula = chord_formula.at(chord_type);

        octave = 4;
        notes = this->get_note_vals();
    }

    Chord::Chord(std::string cho, int oct){
        std::string type(cho, cho.find_first_of(" ") + 1, cho.size() - cho.find_first_of(" "));
        chord_type = type;
        formula = chord_formula.at(chord_type);
        std::string r(cho, 0, cho.find_first_of(" "));
        root = r;
        octave = oct;

        notes = this->get_note_vals();
    }

    std::vector<Note> Chord::get_note_vals(){
        std::vector<Note> notes;
        int chrom_val = Chord::chromatic_vals.at(this->root);
        int prev_chrom = chrom_val;
        int note_oct = this->octave;
        bool is_flat = false;

        if(this->root.find_first_of("b") != std::string::npos){
            is_flat = true;
        }

        for(auto it = formula.begin(); it != formula.end(); ++it){
            if ((chrom_val + *it) % 12 < prev_chrom){
                note_oct += 1;
            }
            prev_chrom = (chrom_val + *it) % 12;
            std::string note_val = Chord::note_vals.at(prev_chrom)[0];
            if(is_flat && Chord::note_vals.at(prev_chrom).size() > 1){
                note_val = Chord::note_vals.at(prev_chrom)[1];
            }
            Note note = Note(note_val, note_oct);
            notes.push_back(note);
            
        }

        return notes;
    }

    std::string Chord::get_chord_type(){
        return this->chord_type;
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