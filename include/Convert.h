#ifndef _CONVERT_H_INCLUDED
#define _CONVERT_H_INCLUDED

#include <string>
#include "midifile.h"
#include <vector>
#include <unordered_map>

namespace cnv {
    Class Note {
        private: 
            static std::unordered_map<std::string, int> midivals;
            std::string note;
            int value;
            int octave;
        
        public:
            void Note(std::string note, int octave);
    };

    Class Chord {
        private:
            static std::unordered_map<std::string, std::vector<int>> chordFormula;
            std::vector<int> formula;
            std::string chord;
            int octave;
            std::vector<int> note_vals;

            std::vector<int> get_note_vals();

        public:
            void Chord(std::string chord, int octave);

            void create_midfile_chord(int track, int start_time, int channel, int velocity, int end_time);
    };
}

#endif