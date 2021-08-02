#ifndef BASE_BLOCK
#define BASE_BLOCK

#include <iostream>
#include <string>
#include <vector>
#include "posn.h"

class Block {
    public:
    //protected:
    Posn llc  = Posn { 1, 15 }; // llc stands for LowerLeftCorner which is maintained during rotation.
    int rot; // rot can be 1, 2, 3, 4 representing 4 types of position of rotation.
    std::vector<Posn> points; // the size of vector is mostly 4.
    
    public:
    Block(int rot = 1);
    // virtual ~Block();
    void moveLeft();
    void moveRight();
    void moveDown();
    virtual void rot_cw() = 0;
    virtual void rot_ccw() = 0;
};

class Iblock : public Block {
    public:
    char type = 'I';
    Iblock(int rot) : Block{rot} {
        points.emplace_back(Posn{1, 15});
        points.emplace_back(Posn{2, 15});
        points.emplace_back(Posn{3, 15});
        points.emplace_back(Posn{4, 15});
    };
    void rot_cw() override;
    void rot_ccw() override;
    void print() {
        llc.print();
        std::cout << "Block type " << type << " with rot " << rot << std::endl;
        for (auto i : points) {
            i.print();
        }
    }
};

class Jblock : public Block {
    public:
    char type = 'J';
    Jblock(int rot) : Block{rot} {};
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
    Lblock(int rot) : Block{rot} {};
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
    Oblock(int rot) : Block{rot} {};
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
    Sblock(int rot) : Block{rot} {};
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
    Zblock(int rot) : Block{rot} {};
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
    Tblock(int rot) : Block{rot} {};
    void rot_cw() override;
    void rot_ccw() override;
    void print() {
        llc.print();
        std::cout << "Block type " << type << " with rot " << rot << std::endl;
    }
};

#endif
