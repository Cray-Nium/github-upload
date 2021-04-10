#ifndef FRAMEDSPRITE_H
#define FRAMEDSPRITE_H

using namespace sf;

typedef enum {
    PERCENT,
    ABSOLUTE
} scaleMode_t;
typedef enum {
    TOP,
    CENTER,
    BOTTOM
} verticalAlignment_t;
typedef enum {
    LEFT,
    CENTER,
    RIGHT
} horizontalAlignment_t;

class FramedSprite
{
private:
    Vector2u windowSize;
    Sprite baseSprite;
    Vector2f frameSizeAbsolute;
    Vector2f framePositionAbsolute;
    Vector2f frameSizePercent;
    Vector2f framePositionPercent;
    scaleMode_t mode;
    verticalAlignment_t verticalAlignment;
    horizontalAlignment_t horizontalAlignment;
    
public:
    FramedSprite(Vector2u windowSize) {this->windowSize = windowSize;}
    void setTexture (const Texture &texture) {this->baseSprite.setTexture(texture);}
    void align();
    void setMode (scaleMode_t mode);
    void setPosition (scaleMode_t mode, float x, float y);
    void setPosition (scaleMode_t mode, const Vector2f &position);
    void setFrameSize (scaleMode_t mode, float x, float y);
    void setFrameSize (scaleMode_t mode, const Vector2f &position);
    Sprite& getSprite();
};

#endif /* FRAMEDSPRITE_H */

