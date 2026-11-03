#ifndef _NOTE_H_
#define _NOTE_H_

#include <string>
#include <unordered_map>

namespace cnv {
    class Note {
        private: 
            // midi value conversion sheet
            static const std::unordered_map<std::string, int> midi_vals;

            //instance variables
            std::string note;
            int value;
            int octave;

            std::string output;
        
        public:
            // non-parameterized constructor
            Note();
            // parameterized constructor
            Note(std::string no, int oct);

            // getters
            std::string get_note();
            int get_value();
            int get_octave();

            // c++ verstion of toString()/str/repr. have to call in order to see
            std::string get_output();
    };
}

#endif