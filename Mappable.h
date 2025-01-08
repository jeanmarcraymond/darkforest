#ifndef MAPPABLE_H
#define MAPPABLE_H

class Mappable {
public:
    // Virtual destructor to ensure proper cleanup of derived types
    virtual ~Mappable() {}

    // Pure virtual methods to be implemented by derived classes
    virtual int getX() const = 0;
    virtual int getY() const = 0;
    virtual char getSymbol() const = 0;
    virtual void setX(int x) = 0;
    virtual void setY(int y) = 0;


};

#endif // MAPPABLE_H