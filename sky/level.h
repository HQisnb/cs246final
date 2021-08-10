#include <iostream>
#include <memory>

class Block;

class BaseLevel {
    public:
    int currLevel = 0;
    virtual char whatBlock() = 0;
    virtual std::unique_ptr<Block> createBlock() = 0;
};

class Level0 : public BaseLevel {
    public:
    char whatBlock() override;
    std::unique_ptr<Block> createBlock() override;
};

/*class Level1 : public Level {
    char whatBlock() override {
        int blockType = rand() % 12 + 1;
        if (blockType == 1) return 'Z';
        if (blockType == 2) return 'S';
        if (blockType == 3 || blockType == 4) return 'T';
        if (blockType == 5 || blockType == 6) return 'O';
        if (blockType == 7 || blockType == 8) return 'L';
        if (blockType == 9 || blockType == 10) return 'J';
        if (blockType == 11 || blockType == 12) return 'I';
        return '.';
    }
    Block* createBlock(char blockType) override {}
};

class Level2 : public Level {
    char whatBlock() override {
        int blockType = rand() % 7 + 1;
        if (blockType == 1) return 'Z';
        if (blockType == 2) return 'S';
        if (blockType == 3) return 'T';
        if (blockType == 4) return 'O';
        if (blockType == 5) return 'L';
        if (blockType == 6) return 'J';
        if (blockType == 7) return 'I';
        return '.';
    }
    Block* createBlock(char blockType) override {}
};

class Level3 : public Level {
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