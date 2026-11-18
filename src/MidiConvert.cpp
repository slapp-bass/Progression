#include "MidiCovnert.h"

#include "midifile.h"
#include "Chord.h"
#include "Note.h"
#include <vector>
#include "Instruments.h"
#include <string>

namespace cnv{
    MidiConvert::MidiConvert(){
        smf::MidiFile midifile;
        tpq = 480;
        timePos = 0;
        metatrack = 0;
        tempo = 120.0;

        midifile.setTicksPerQuarterNote(tpq);
        midifile.addTempo(metatrack, 0, tempo);
    }

    MidiConvert::MidiConvert(int tpq, double tempoInit){
        smf::MidiFile midifile;
        this->tpq = tpq;
        timePos = 0;
        metatrack = 0;
        tempo = tempoInit;

        midifile.setTicksPerQuarterNote(tpq);
        midifile.addTempo(metatrack, 0, tempo);
    }

    void MidiConvert::addInstrument(std::string instrument){
        Instruments inst = new Instruments::Instruments(instrument, 90, static_cast<int>(instrument_tracks.size()))
        instrument_tracks.push_back(inst);
    }
}