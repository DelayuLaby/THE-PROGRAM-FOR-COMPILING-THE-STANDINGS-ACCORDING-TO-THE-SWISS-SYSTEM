#ifndef GAME_H
#define GAME_H

class Game {
private:
    int enemyId;
    double result;

public:
    explicit Game(int enemyId = 0, double result = 0.0) : enemyId(enemyId), result(result) {}

    int getEnemyId() { return enemyId; }
    void setEnemyId(int enemyId) { this->enemyId = enemyId; }
    double getResult() { return result; }
    void setResult(double result) { this->result = result; }
};

#endif // GAME_H
