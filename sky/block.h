#ifndef BASE_BLOCK
#define BASE_BLOCK

#include <iostream>
#include <string>
#include <vector>
#include "posn.h"

class Board;

class Block {
    public:
    //protected:
    Posn llc  = Posn { 1, 4 }; // llc stands for LowerLeftCorner which is maintained during rotation.
    int curStatus = 0; // curStatus can be 0, 1, 2, 3 representing 4 types of position of rotation.
    std::vector<Posn> points; // the size of vector is mostly 4.
    
    public:
    Block();
    virtual ~Block();
    void moveLeft();
    void moveRight();
    void moveDown();
    virtual std::vector<Posn> rot_cw() = 0;
    virtual void rot_ccw() = 0;
    virtual char getType() = 0;
    virtual void print() = 0;
    void blockPointsSort();
    int minX();
    int maxX();
    int maxY();

    
};

class Iblock : public Block {
    public:
    char type = 'I';
    Iblock(): Block{} {
        points.emplace_back(Posn{1, 4});
        points.emplace_back(Posn{2, 4});
        points.emplace_back(Posn{3, 4});
        points.emplace_back(Posn{4, 4});
        this->blockPointsSort();
    };
    ~Iblock();
    std::vector<Posn> rot_cw() override;
    void rot_ccw() override;
    char getType() override;
    void print() {
        llc.print();
        std::cout << "Block type " << type << " with rot " << curStatus << std::endl;
        for (auto i : points) {
            i.print();
        }
    }
};

class Jblock : public Block {
    public:
    char type = 'J';
    Jblock(): Block{} {
        points.emplace_back(Posn{1, 3});
        points.emplace_back(Posn{1, 4});
        points.emplace_back(Posn{2, 4});
        points.emplace_back(Posn{3, 4});
        this->blockPointsSort();
    };
    ~Jblock();
    std::vector<Posn> rot_cw() override;
    void rot_ccw() override;
    char getType() override;
    void print() {
        llc.print();
        std::cout << "Block type " << type << " with rot " << curStatus << std::endl;
        for (auto i : points) {
            i.print();
        }
    }
};

class Lblock : public Block {
    public:
    char type = 'L';
    Lblock(): Block{} {
        points.emplace_back(Posn{1, 4});
        points.emplace_back(Posn{2, 4});
        points.emplace_back(Posn{3, 4});
        points.emplace_back(Posn{3, 3});
        this->blockPointsSort();
    };
    ~Lblock();
    std::vector<Posn> rot_cw() override;
    void rot_ccw() override;
    char getType() override;
    void print() {
        llc.print();
        std::cout << "Block type " << type << " with rot " << curStatus << std::endl;
        for (auto i : points) {
            i.print();
        }
    }
};

class Oblock : public Block {
    public:
    char type = 'O';
    Oblock(): Block{} {
        points.emplace_back(Posn{1, 4});
        points.emplace_back(Posn{2, 4});
        points.emplace_back(Posn{1, 3});
        points.emplace_back(Posn{2, 3});
        this->blockPointsSort();
    };
    ~Oblock();
    std::vector<Posn> rot_cw() override;
    void rot_ccw() override;
    char getType() override;
    void print() {
        llc.print();
        std::cout << "Block type " << type << " with rot " << curStatus << std::endl;
        for (auto i : points) {
            i.print();
        }
    }
};

class Sblock : public Block {
    public:
    char type = 'S';
    Sblock(): Block{} {
        points.emplace_back(Posn{1, 4});
        points.emplace_back(Posn{2, 4});
        points.emplace_back(Posn{2, 3});
        points.emplace_back(Posn{3, 3});
        this->blockPointsSort();
    };
    ~Sblock();
    std::vector<Posn> rot_cw() override;
    void rot_ccw() override;
    char getType() override;
    void print() {
        llc.print();
        std::cout << "Block type " << type << " with rot " << curStatus << std::endl;
        for (auto i : points) {
            i.print();
        }
    }
};

class Zblock : public Block {
    public:
    char type = 'Z';
    Zblock(): Block{} {
        points.emplace_back(Posn{1, 3});
        points.emplace_back(Posn{2, 3});
        points.emplace_back(Posn{2, 4});
        points.emplace_back(Posn{3, 4});
        this->blockPointsSort();
    };
    ~Zblock();
    std::vector<Posn> rot_cw() override;
    void rot_ccw() override;
    char getType() override;
    void print() {
        llc.print();
        std::cout << "Block type " << type << " with rot " << curStatus << std::endl;
        for (auto i : points) {
            i.print();
        }
    }
};

class Tblock : public Block {
    public:
    char type = 'T';
    Tblock(): Block{} {
        points.emplace_back(Posn{1, 3});
        points.emplace_back(Posn{2, 3});
        points.emplace_back(Posn{3, 3});
        points.emplace_back(Posn{2, 4});
        this->blockPointsSort();
    };
    ~Tblock();
    std::vector<Posn> rot_cw() override;
    void rot_ccw() override;
    char getType() override;
    void print() {
        llc.print();
        std::cout << "Block type " << type << " with rot " << curStatus << std::endl;
        for (auto i : points) {
            i.print();
        }
    }
};

#endif
