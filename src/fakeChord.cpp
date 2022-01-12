#include "../include/fakeChord.hpp"
#include <iostream>
#include <array>
#include <algorithm>
#include <random>

FakeChord::FakeChord() {

}

FakeChord::FakeChord(int bassOct, int octRange, int numNotes, Key key, RN rn, Instrument instrument) {
    this->instrument = instrument;
    this->rootNote = getRootNote(key, rn);
    this->bassOct = bassOct;
    this->octRange = octRange;
    this->numNotes = numNotes;
    this->key = key;
    this->recipeNum = (int)mode;
    this->rn = rn;

    // find mode given rn
    switch (rn) {
        case (I) : mode = Ionian;
            break;
        case (ii) : mode = Dorian;
            break;
        case (iii) : mode = Phrygian;
            break;
        case (IV) : mode = Lydian;
            break;
        case (V) : mode = Mixolydian;
            break;
        case (vi) : mode = Aeolian;
            break;
        case (viidim) : mode = Locrian;
            break;
        default : mode = Major;
            throw std::string("Could not determine correct mode given RN; defaulting to Major.");
    }

    checkOctRange();
    create();
}

FakeChord::FakeChord(int bassOct, int octRange, int numNotes, Key key, RN rn, Mode mode, Instrument instrument) {
    this->instrument = instrument;
    this->rootNote = getRootNote(key, rn);
    this->bassOct = bassOct;
    this->octRange = octRange;
    this->mode = mode;
    this->numNotes = numNotes;
    this->key = key;
    this->recipeNum = (int)mode;
    this->rn = rn;

    checkOctRange();
    create();
}

FakeChord::~FakeChord() {
    // dealloc
    for (int i=0; i<numNotes; ++i)
        delete notes[i];
}

// create chord by its corresponding recipe type.
// Called only by the constructor
void FakeChord::create() {
    // create chord by its corresponding recipe type
    const std::vector<const int> chordRecipe = modeChordRecipes[recipeNum];

    // first, create necessary notes
    int numNecessaryNotes = chordRecipe.size();
    int numExtraNotes = numNotes - numNecessaryNotes;
    int numAdditionalNotes = 0;

    if (numNotes < numNecessaryNotes) {
        numAdditionalNotes = numNecessaryNotes - numNotes;
        numExtraNotes = 0;
        throw std::string("Not enough notes for chord. Added " + std::to_string(numAdditionalNotes) + " more.");
    }

    for (int i=0; i<numNecessaryNotes; ++i) {
        int newNoteCode = convertNoteByKey(chordRecipe[i]);
        // get octave, if first note then use bass octave
        int octave;
        if (i == 0)
            octave = this->bassOct;
        else
            octave = getRandOct(chordRecipe[i]);
        
        newNote(octave, newNoteCode);
    }

    // find all possible extra notes
    if (numExtraNotes > 0) {
        int currOct = this->bassOct;
        bool octWasChanged = false;

        for (int i=0; i<this->octRange; ++i) {

            for (int j=0; j<numNecessaryNotes; ++j) {
                int _note = convertNoteByKey(chordRecipe[j]);
                std::pair<int, int> nextNote(currOct, _note);

                // if next note should be new octave, and octave was not already
                // refreshed this round
                if (rootNote + (chordRecipe[j+1]) > 11 && !octWasChanged) {
                    // increase currOct by one and set octwasChanged flag to true
                    ++currOct;
                    octWasChanged = true;
                }

                // if note doesn't already exist, add it to vec of possible notes
                if (!noteExists(nextNote.second, nextNote.first))
                    possibleNotes.push_back(nextNote);
            }
            // if octave was never changed, change it. Else, reset the flag
            if (!octWasChanged)
                ++currOct;
            octWasChanged = false;
        }
    }

    // shuffle possible extra notes
    auto rd = std::random_device {}; 
    auto rng = std::default_random_engine { rd() };
    std::shuffle(std::begin(possibleNotes), std::end(possibleNotes), rng);

    // check that there are enough possible notes for extraNotes
    if (possibleNotes.size() > numExtraNotes)
        numExtraNotes = possibleNotes.size();

    // next, create all remaining extra notes
    for (int i=0; i<numExtraNotes; ++i) {
        newNote(possibleNotes[i].first, possibleNotes[i].second);
    }
}

// makes sure the octave range is not out of bounds given the instrument.
// Always called by the constructor, before createChord() is called
void FakeChord::checkOctRange() {
    // check octave range, make corrections as necessary
    std::pair<const int, const int> instrumentRange = instrumentRanges[(int)instrument];

    // if bass oct too low, raise bass oct and lower oct range if necessary
    if (this->bassOct < instrumentRange.first) {
        this->bassOct = instrumentRange.first;
        if (this->bassOct + this->octRange-1 > instrumentRange.second)
            this->octRange = instrumentRange.second;
    }
    // if oct range too high, lower oct range and try to lower bass oct
    if ((this->bassOct + this->octRange - 1) > instrumentRange.second) {
        int adjustment = this->bassOct + this->octRange - 1 - instrumentRange.second;
        for (int i=0; i<adjustment; ++i)
            if (this->bassOct-1 >= instrumentRange.first)
                this->bassOct -= 1;
        this->octRange = instrumentRange.second - this->bassOct + 1;
    }
}

bool FakeChord::noteExists(int note, int octave) const {
    int currNumNotes = notes.size();
    for (int j=0; j<currNumNotes; ++j) {
        if (notes[j]->getNoteCode() == note && notes[j]->getOctave() == octave)
            return true;
    }
    return false;
}

// print the chord's info
void FakeChord::print() const {
    std::cout << this->rnToString(rn) << " in " << this->keyToString(key) << ':' << std::endl;
    for (int i=0; i<numNotes; ++i)
        std::cout << "\tOct: " << notes[i]->getOctave() << " | Note: " << notes[i]->getNote() << std::endl;
}

// get random note given the recipe
int FakeChord::getRandNote() const {
    const std::vector<const int> chordRecipe = modeChordRecipes[recipeNum];
    int recipeSize = chordRecipe.size();

    int range = recipeSize - 1;
    int randNoteIndex = rand() % range + 0;

    return convertNoteByKey(chordRecipe[randNoteIndex]);
}

// convert the given note in the key to its corresponding note code 0-11
int FakeChord::convertNoteByKey(int note) const {
    // adjust given the RN
    note = (note + (int)rn) % 12;
    int keyCode = (int)key;
    // adjust for key code
    return (keyCode + note) % 12;
}

// plays all notes in the chord
// will throw a string if one of the notes could not be played
void FakeChord::play() const {
    for (int i=0; i<numNotes; ++i)
        try {
            notes[i]->play();
        }
        catch(std::string &message) {
            // note not loaded
            throw std::string("Could not load note with file name " + notes[i]->getFileName());
        }
}

// find and return the root note of the chord given the key and
// Roman Numeral
int FakeChord::getRootNote(Key key, RN rn) const {
    int semUp = (int)rn;
    int keyInSem = (int)key;
    int correctNote = (key + rn) % 12;

    return correctNote;
}

// returns random octave within bounds, staying above the bass octave
int FakeChord::getRandOct(int note) const {

    int correction = 0;
    int octLow = bassOct;
    int octHigh = octLow + octRange - 1;

    // adjust octave range according to configuration of new note
    // against root note
    if (note <= rootNote) {
        octLow += 1;
        octHigh += 1;
    }

    // if only one octave possible, return octave
    if (octLow - octHigh == 0)
        return octHigh;

    if (octLow < 0)
        correction = octLow * -1;

    int range = octHigh - octLow + 1;
    int randNum = rand() % range + octLow + correction;
    randNum -= correction;

    return randNum;
}

// creates new note and adds it to notes
void FakeChord::newNote(int octave, int note) {
    Note* newNote = new Note(octave, note, instrument);
    notes.push_back(newNote);
}