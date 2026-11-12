#ifndef _CHORD_H_
#define _CHORD_H_

#include "Note.h"
#include <string>
#include <vector>
#include <unordered_map>

namespace cnv{
class Chord {
        private:
            // conversion maps for chords and notes
            static const std::unordered_map<std::string, std::vector<int>> chord_formula;
            static const std::unordered_map<int, std::vector<std::string>> note_vals;
            static const std::unordered_map<std::string, int> chromatic_vals;

            // instance variables
            std::string chord_type;
            std::vector<int> formula;
            std::string root;
            int octave;
            std::vector<Note> notes;

            // private method
            std::vector<Note> get_note_vals();

        public:
            // non-parameterized constructor
            Chord();
            // parameterized constructor
            Chord(std::string cho, int oct);

            // getters
            std::string get_chord_type();
            std::vector<int> get_formula();
            std::vector<Note> get_notes();
            int get_octave();

            // create a midi track 
            void create_midfile_chord(int track, int start_time, int channel, int velocity, int end_time);
};
}

#endif