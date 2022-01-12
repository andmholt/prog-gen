#ifndef PROGRESSION_HPP
#define PROGRESSION_HPP

#include "recipes.hpp"
#include "chord.hpp"

class Progression {
public:
    Progression(int bassOct, int octRange, int notesPerChord, Key key, std::vector<RN> rns, Instrument instrument);
    ~Progression();
    virtual void play() const;
    virtual void print() const;
protected:
    Instrument instrument;
    std::vector<Chord*> chords;
    int numChords;
    Key key;
    Mode rnToMode(RN rn) const;
    std::string keyToString() const; // returns key as a string
    std::string rnToString(RN rn) const; // returns rn as a string
};

#endif