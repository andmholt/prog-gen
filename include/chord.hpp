#ifndef CHORD_HPP
#define CHORD_HPP

#include "note.hpp"
#include <vector>
#include "recipes.hpp"
#include <string>

class Chord {
public:
    //Chord(Key key, RN rn, ChordType chordType);
    virtual ~Chord() = 0;
    virtual void play() const = 0;
    virtual void print() const = 0;
protected:
    std::string rnToString(RN rn) const; // returns RN as a string
    std::string keyToString(Key key) const; // returns key as a string
    //RN getRN() const; // returns RN
};

#endif