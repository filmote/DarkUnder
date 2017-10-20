
#include <WString.h>
#include "Utils.h"

const char BeholderName[] PROGMEM = "A BEHOLDER";
const char SkeletonName[] PROGMEM = "A SKELETON";
const char DisplacerName[] PROGMEM = "A DISPLACER";
const char WraithName[] PROGMEM = "A WRAITH";
const char DragonName[] PROGMEM = "A DRAGON";
const char RatName[] PROGMEM = "A RAT";
const char SlimeName[] PROGMEM = "A SLIME";

const __FlashStringHelper * EnemyNames[] =
{
    FlashString(BeholderName),
    FlashString(SkeletonName),
    FlashString(DisplacerName),
    FlashString(WraithName),
    FlashString(DragonName),
    FlashString(RatName),
    FlashString(SlimeName),    
};