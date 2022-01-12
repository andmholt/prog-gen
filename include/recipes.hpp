#ifndef RECIPES_HPP
#define RECIPES_HPP

#include <vector>

enum Alteration {
    Sus2 = 0,
    Sus4 = 1,
    Sus = 1
};

enum Instrument {
    GrandPiano
};

extern const std::vector<const std::pair<const int, const int> > instrumentRanges;

enum Interval {
    Root,
    MinSec,
    MajSec,
    MinThird,
    MajThird,
    Fourth,
    Fifth,
    MinSix,
    MajSix,
    MinSev,
    MajSev
};

enum Key {
    C,
    Db,
    D,
    Eb,
    E,
    F,
    Gb,
    G,
    Ab,
    A,
    Bb,
    B
};

enum Mode {
    // church modes
    Ionian = 0,
    Dorian = 1,
    Phrygian = 2,
    Lydian = 3,
    Mixolydian = 4,
    Aeolian = 5,
    Locrian = 6,

    // simple types
    Major = 0,
    Minor = 5,
    Minor7b5 = 6,
    FullyDiminished = 7,
    Augmented = 8,
    Dominant = 9,
    //MinorMajor

    // other modes
    NaturalMinor = 5,
    HarmonicMinor = 10,
    MelodicMinor = 11
};

extern const std::vector<const std::vector<const int> > modeAllowedTensions;

extern const std::vector<const std::vector<const int> > modeChordRecipes;

enum RN {
    // standard
    I = 0,
    i = 0,
    N = 1,
    bII = 1,
    ii = 2,
    II = 2,
    biii = 3,
    bIII = 3,
    iii = 4,
    III = 4,
    IV = 5,
    iv = 5,
    bv = 6,
    V = 7,
    v = 7,
    bVI = 8,
    vi = 9,
    VI = 9,
    bVII = 10,
    viidim = 11,
    VII = 11,

    // secondary dominants
    Vofi = 7,
    VofN = 8,
    VofbII = 8,
    Vofii = 9,
    VofII = 9,
    Vofbiii = 10,
    VofbIII = 10,
    Vofiii = 11,
    VofIII = 11,
    VofIV = 0,
    Vofiv = 0,
    Vofbv = 1,
    VofV = 2,
    VofbVI = 3,
    Vofvi = 4,
    VofVI = 4,
    VofbVII = 5,
    Vofviidim = 6,
    VofVII = 11,

    // secondary diminished
    viidimofi = 11,
    viidimofN = 0,
    viidimofbII = 0,
    viidimofii = 1,
    viidimofII = 1,
    viidimofbiii = 2,
    viidimofbIII = 2,
    viidimofiii = 3,
    viidimofIII = 3,
    viidimofIV = 4,
    viidimofiv = 4,
    viidimofbv = 5,
    viidimofV = 6,
    viidimofbVI = 7,
    viidimofvi = 8,
    viidimofVI = 8,
    viidimofbVII = 9,
    viidimofviidim = 10,
    viidimofVII = 10,
};

enum Tension {
    b7,
    _7,
    b9,
    _9,
    s9,
    b11,
    _11,
    s11,
    b13,
    _13,
    s13
};

#endif