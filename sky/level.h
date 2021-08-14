#ifndef LEVEL_H
#define LEVEL_H

#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

class Block;

class BaseLevel {
    public:
    int currLevel = 0;
    virtual char whatBlock() = 0;
    virtual std::unique_ptr<Block> createBlock() = 0;
};

class Level0 : public BaseLevel {
    public:
    int boardNo;
    std::string file;
    std::stringstream iss1;
    std::stringstream iss2;

    Level0(int No) {
        boardNo = No;
        if (boardNo == 1) {
            std::ifstream file1 {file};
            iss1 << file1.rdbuf();
            file1.close();
        } else {
            std::ifstream file2 {file};
            iss2 << file2.rdbuf();
            file2.close();
        }
    }

    void updateFile(std::string fileName) {
        iss1.clear();
        iss2.clear();
        file = fileName;
        if (boardNo == 1) {
            std::ifstream file1 {file};
            iss1 << file1.rdbuf();
            file1.close();
        } else {
            std::ifstream file2 {file};
            iss2 << file2.rdbuf();
            file2.close();
        }
    }

    char whatBlock() override;
    std::unique_ptr<Block> createBlock() override;
};

class Level1 : public BaseLevel {
    public:
    int boardNo;

    Level1(int No) {
        boardNo = No;
    }

    char whatBlock() override;
    std::unique_ptr<Block> createBlock() override;
};

class Level2 : public BaseLevel {
    public:
    int boardNo;

    Level2(int No) {
        boardNo = No;
    }

    char whatBlock() override;
    std::unique_ptr<Block> createBlock() override;
};

class Level3 : public BaseLevel {
    public:
    int boardNo;

    Level3(int No) {
        boardNo = No;
    }

    char whatBlock() override;
    std::unique_ptr<Block> createBlock() override;
};

/*
class Level4 : public Level {
    char whatBlock() override {
        int blockType = rand() % 9 + 1;
        if (blockType == 1 || blockType == 8) return 'Z';
        if (blockType == 2 || blockType == 9) return 'S';
        if (blockType == 3) return 'T';
        if (blockType == 4) return 'O';
        if (blockType == 5) return 'L';
        if (blockType == 6) return 'J';
        if (blockType == 7) return 'I';
        return '.';
    }
    Block* createBlock(char blockType) override {}
};
*/

#endif
