#ifndef _CONVERT_H_
#define _CONVERT_H_

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

    class Chord {
        private:
            static const std::unordered_map<std::string, std::vector<int>> chord_formula;
            static const std::unordered_map<int, std::string> note_vals;
            static const std::unordered_map<std::string, int> chromatic_vals;
            std::vector<int> formula;
            std::string chord;
            int octave;
            std::vector<Note> notes;

            std::vector<int> get_note_vals();

        public:
            Chord(std::string cho, int oct);

            std::string get_chord();
            std::vector<int> get_formula();
            std::vector<int> get_notes();
            int get_octave();


            void create_midfile_chord(int track, int start_time, int channel, int velocity, int end_time);
    };
}

#endif