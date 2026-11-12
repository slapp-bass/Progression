#ifndef _MIDICONVERT_h_
#define _MIDICONVERT_h_

#include "midifile.h"
#include "string"
#include "Chord.h"
#include "Note.h"

namespace cnv{
    class MidiConvert {
        private:
        smf::MidiFile midifile;
        int timePos;

        public:
        MidiConvert();
        MidiConvert(int tpq, int tempoInit);

        void makeChord(cnv::Chord chord, int quarterNotes);
        void makeNote(cnv::Note note, int quarterNotes);
    };
}


#endif