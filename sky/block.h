#ifndef BASE_BLOCK
#define BASE_BLOCK

#include <iostream>
#include <string>
#include <vector>
#include "posn.h"

class Block {
    public:
    //protected:
    Posn llc; // llc stands for LowerLeftCorner which is maintained during rotation.
    int rot; // rot can be 1, 2, 3, 4 representing 4 types of position of rotation.
    std::vector<Posn> points; // the size of vector is mostly 4.
    
    public:
    Block( Posn llc, int rot );
    // virtual ~Block();
    virtual void rot_cw() = 0;
    virtual void rot_ccw() = 0;
};

class Iblock : public Block {
    public:
    char type = 'I';
    Iblock( Posn llc, int rot ) : Block{ llc, rot } {};
    void rot_cw() override;
    void rot_ccw() override;
    void print() {
        llc.print();
        std::cout << "Block type " << type << " with rot " << rot << std::endl;
    }
};

class Jblock : public Block {
    public:
    char type = 'J';
    Jblock( Posn llc, int rot ) : Block{ llc, rot } {};
    void rot_cw() override;
    void rot_ccw() override;
    void print() {
        llc.print();
        std::cout << "Block type " << type << " with rot " << rot << std::endl;
    }
};

class Lblock : public Block {
    public:
    char type = 'L';
    Lblock( Posn llc, int rot ) : Block{ llc, rot } {};
    void rot_cw() override;
    void rot_ccw() override;
    void print() {
        llc.print();
        std::cout << "Block type " << type << " with rot " << rot << std::endl;
    }
};

class Oblock : public Block {
    public:
    char type = 'O';
    Oblock( Posn llc, int rot ) : Block{ llc, rot } {};
    void rot_cw() override;
    void rot_ccw() override;
    void print() {
        llc.print();
        std::cout << "Block type " << type << " with rot " << rot << std::endl;
    }
};

class Sblock : public Block {
    public:
    char type = 'S';
    Sblock( Posn llc, int rot ) : Block{ llc, rot } {};
    void rot_cw() override;
    void rot_ccw() override;
    void print() {
        llc.print();
        std::cout << "Block type " << type << " with rot " << rot << std::endl;
    }
};

class Zblock : public Block {
    public:
    char type = 'Z';
    Zblock( Posn llc, int rot ) : Block{ llc, rot } {};
    void rot_cw() override;
    void rot_ccw() override;
    void print() {
        llc.print();
        std::cout << "Block type " << type << " with rot " << rot << std::endl;
    }
};

class Tblock : public Block {
    public:
    char type = 'T';
    Tblock( Posn llc, int rot ) : Block{ llc, rot } {};
    void rot_cw() override;
    void rot_ccw() override;
    void print() {
        llc.print();
        std::cout << "Block type " << type << " with rot " << rot << std::endl;
    }
};

#endif
