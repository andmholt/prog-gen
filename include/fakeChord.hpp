#ifndef FAKECHORD_HPP
#define FAKECHORD_HPP

#include "chord.hpp"
#include "recipes.hpp"
#include "note.hpp"

class FakeChord : public Chord {
public:
    FakeChord();
    FakeChord(int bassOct, int octRange, int numNotes, Key key, RN rn, Instrument instrument);
    FakeChord(int bassOct, int octRange, int numNotes, Key key, RN rn, Mode mode, Instrument instrument);
    virtual ~FakeChord();
    virtual void play() const override;
    virtual void print() const override;
protected:
    std::vector<Note*> notes;
    std::vector<std::pair<int, int> > possibleNotes; // pair<oct, note>
    Instrument instrument;
    Mode mode;
    Key key;
    RN rn;
    int rootNote;
    int bassOct;
    int numNotes;
    int octRange;
    int recipeNum;
private:
    int getRootNote(Key key, RN rn) const;
    void create(); // actually creates the chord. Called only by the constructor
    void checkOctRange(); // makes sure octave range is not out of bounds given the instrument
    bool noteExists(int note, int octave) const;
    int getRandOct(int note) const;
    int getRandNote() const;
    int convertNoteByKey(int note) const;
    void newNote(int octave, int note); // creates new note and adds to notes
};

#endif