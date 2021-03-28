#include <map>
#include <string>
#include <utility>
#include "AudioTrack.h"
#include "AudioLibrary.h"

using namespace std;

audioLibraryReturnPair AudioLibrary::addTrack(const string& filepath)
{
    audioLibraryReturnPair retVal;
    unsigned int startKey = this->nextKey;
    while (this->tracks.count(this->nextKey))
    {
        this->nextKey++;
        if (this->nextKey == startKey)
        {
            retVal.second = false;
        }
    }
    retVal.first = this->nextKey;
    retVal.second = (this->tracks.emplace(this->nextKey, filepath)).second;
    return retVal;
}