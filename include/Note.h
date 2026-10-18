#ifndef _NOTE_H_
#define _NOTE_H_

#include <string>
#include <vector>
#include <unordered_map>

namespace cnv {
    class Note {
        private: 
            static const std::unordered_map<std::string, int> midi_vals;
            std::string note;
            int value;
            int octave;
        
        public:
            Note(std::string no, int oct);

            std::string get_note();
            int get_value();
            int get_octave();
    };
}

#endif