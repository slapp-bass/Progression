#ifndef _MIDICONVERT_H_
#define _MIDICONVERT_H_

#include "midifile.h"
#include "Chord.h"
#include "Note.h"
#include <vector>
#include "Instruments.h"
#include <string>

namespace cnv{
    class MidiConvert {
        private:
        smf::MidiFile midifile;
        int timePos;
        int tpq;
        int metatrack;
        double tempo;
        std::vector<cnv::Instruments> instrument_tracks;

        public:
        MidiConvert();
        MidiConvert(int tpq, double tempoInit);

        void addInstrument(std::string instrument);
        void addInstrument(std::string instrument, int vel);

        void makeChord(cnv::Chord chord, int quarterNotes);
        void makeNote(cnv::Note note, int quarterNotes);
    };
}


#endif