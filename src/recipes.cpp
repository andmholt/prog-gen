#include "../include/recipes.hpp"
#include <vector>

const std::vector<const std::pair<const int, const int> > instrumentRanges = {
    {0, 5} // GrandPiano
};

const std::vector<const std::vector<const int> > modeChordRecipes = {
    // church modes
    {0, 4, 7}, // Ionian - R 3 5
    {0, 3, 7}, // Dorian - R b3 5
    {0, 3, 7}, // Phrygian - R b3 5
    {0, 4, 7}, // Lydian - R 3 5
    {0, 4, 7}, // Mixolydian - R 3 5
    {0, 3, 7}, // Aeolian - R b3 5
    {0, 3, 6}, // Locrian - R b3 b5

    // simple types
    {0, 3, 6, 9}, // FullyDiminished R b3 b5 bb7
    {0, 4, 8}, // Augmented R 3 #5
    {0, 4, 7, 10} // Dominant R 3 5 b7
};

const std::vector<const std::vector<const int> > modeAllowedTensions = {
    // church modes
    {11, 2, 9}, // Ionian - 7 9 13
    {10, 2, 5, 9}, // Dorian - b7 9 11 13
    {10, 5}, // Phrygian - b7 11
    {11, 2, 6, 9}, // Lydian - 7 9 #11 13
    {10, 2, 9}, // Mixolydian - b7 9 13
    {10, 2, 5}, // Aeolian - b7 9 11
    {10, 2, 5}, // Locrian - b7 9 11

    // simple types
    {2, 5, 8, 11}, // FullyDiminished - 9 11 b13 7
    {10, 2, 6}, // Augmented - b7 9 #11
    {1, 2, 3, 6, 8, 9} // Dominant - b9 9 #9 #11 b13 13
};