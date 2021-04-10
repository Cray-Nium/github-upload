#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "FramedSprite.h"


void FramedSprite::align()
{
    float textureScaleFactor;
    Vector2u textureNativeSize = this->baseSprite.getTexture->getSize();
    Vector2f framePosition;
    Vector2f spritePosition;
    
    if (this->mode == PERCENT)
    {
        //Determine absolute frame metrics
    }
    
    if ( (textureNativeSize.x / (float)textureNativeSize.y) > (this->frameSizeAbsolute.x / this->frameSizeAbsolute.y) )
    {
        //X dimension fills frame
        textureScaleFactor = this->frameSizeAbsolute.x / textureNativeSize.x;
        this->baseSprite.
        
        this->baseSprite.setScale(textureScaleFactor, textureScaleFactor);
    }
    else
    {
        //Y dimension fills frame
        textureScaleFactor = this->frameSizeAbsolute.x / albumArtNativeSize.x;
        
        this->baseSprite.setScale(textureScaleFactor, textureScaleFactor);
    }
    
    //albumArtFrameSideLength = windowSize.x * (1 - 2 * albumArtFrameSideMarginPercent);
    //albumArtFrameOrigin.x = windowSize.x * albumArtFrameSideMarginPercent;
    //albumArtFrameOrigin.y = windowSize.y * albumArtFrameTopMarginPercent;
    //albumArtFrame.setOrigin(albumArtFrameOrigin);
    //albumArtFrame.setSize(Vector2f(albumArtFrameSideLength, albumArtFrameSideLength));
    //albumArtSprite.setPosition(albumArtFrame.getOrigin());

    //albumArtFilePath = coreLibrary.tracks.at(primaryPlaylist.entries.at(songNumber).audioTrackKey).artFilePath;
    //albumArtTexture.loadFromFile(albumArtFilePath);
    //albumArtNativeSize = albumArtTexture.getSize();    
    //albumArtTextureScaleFactor = ( albumArtNativeSize.x >= albumArtNativeSize.y 
    //                              ? albumArtFrameSideLength / albumArtNativeSize.x
    //                              : albumArtFrameSideLength / albumArtNativeSize.y);
    //albumArtTexture.setSmooth(false);
    
    //albumArtSprite.setTexture(albumArtTexture);
    //albumArtSprite.setScale(albumArtTextureScaleFactor, albumArtTextureScaleFactor);
    
}
void FramedSprite::setPosition (scaleMode_t mode, float x, float y)
{
    
}
void FramedSprite::setPosition (scaleMode_t mode, const Vector2f &position)
{
    
}
void FramedSprite::setFrameSize (scaleMode_t mode, float x, float y)
{
    
}
void FramedSprite::setFrameSize (scaleMode_t mode, const Vector2f &position)
{
    
}
Sprite& FramedSprite::getSprite()
{
    
}
