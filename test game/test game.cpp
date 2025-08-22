#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <conio.h>

using namespace std;

constexpr int PLAYABLE_START = 1;
constexpr int PLAYABLE_END = 10; // 10x10 맵
constexpr int BOARD_SIZE = PLAYABLE_END + 2;
constexpr int MAX_SEALED = 10;

enum class Tile {
    Empty,
    Wall,
    Player,
    Sealed,
    Item
};

struct Position {
    int x, y;
    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }
};

struct Game {
    Tile map[BOARD_SIZE][BOARD_SIZE];
    Position player;
    vector<Position> sealedTiles;
    vector<Position> itemTiles;
    int moveCount = 0;
    int score = 0;
    int breakTurns = 0; // 봉쇄 타일 파괴 가능 턴 카운터
    bool gameOver = false;
};

void InitGame(Game& game) {
    for (int y = 0; y < BOARD_SIZE; ++y) {
        for (int x = 0; x < BOARD_SIZE; ++x) {
            if (y == 0 || y == BOARD_SIZE - 1 || x == 0 || x == BOARD_SIZE - 1) {
                game.map[y][x] = Tile::Wall;
            }
            else {
                game.map[y][x] = Tile::Empty;
            }
        }
    }
    game.player = { PLAYABLE_START + (PLAYABLE_END - PLAYABLE_START) / 2,
                    PLAYABLE_START + (PLAYABLE_END - PLAYABLE_START) / 2 };
    game.map[game.player.y][game.player.x] = Tile::Player;

    game.sealedTiles.clear();
    game.itemTiles.clear();
    game.moveCount = 0;
    game.score = 0;
    game.breakTurns = 0;
    game.gameOver = false;
}

void DrawMap(const Game& game) {
    system("cls");
    for (int y = 0; y < BOARD_SIZE; ++y) {
        for (int x = 0; x < BOARD_SIZE; ++x) {
            switch (game.map[y][x]) {
            case Tile::Wall: cout << "#"; break;
            case Tile::Player: cout << "P"; break;
            case Tile::Sealed: cout << "X"; break;
            case Tile::Item: cout << "I"; break;
            default: cout << " "; break;
            }
        }
        cout << "\n";
    }
    cout << "점수: " << game.score << " | 이동 횟수: " << game.moveCount << "\n";
    if (game.breakTurns > 0)
        cout << "봉쇄 타일 파괴 가능 남은 턴: " << game.breakTurns << "\n";
}

bool IsBlocked(const Game& game, int x, int y) {
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) return true;
    Tile t = game.map[y][x];
    return (t == Tile::Wall || t == Tile::Sealed);
}

bool MovePlayer(Game& game, int dx, int dy) {
    if (game.gameOver) return false;

    int nx = game.player.x;
    int ny = game.player.y;

    vector<Position> path; // 플레이어가 지나가는 경로 저장

    while (true) {
        int tx = nx + dx;
        int ty = ny + dy;
        if (IsBlocked(game, tx, ty)) break;
        nx = tx; ny = ty;
        path.push_back({ nx, ny });
    }

    if (nx == game.player.x && ny == game.player.y) return false;

    // 이전 위치 비우기
    game.map[game.player.y][game.player.x] = Tile::Empty;

    // 파괴 가능 턴이 있을 때 경로 상 봉쇄 타일 파괴
    if (game.breakTurns > 0) {
        // 봉쇄 타일 파괴는 파괴 턴 끝날 때까지 계속 가능하므로 breakTurns는 나중에 감소
        // 경로상의 봉쇄 타일 찾기 및 제거
        for (const auto& pos : path) {
            auto it = find(game.sealedTiles.begin(), game.sealedTiles.end(), pos);
            if (it != game.sealedTiles.end()) {
                // 봉쇄 타일 파괴
                game.sealedTiles.erase(it);
                game.map[pos.y][pos.x] = Tile::Empty;
                game.score += 5; // 봉쇄 타일 파괴 점수
            }
        }
    }

    // 플레이어 경로 중 아이템 있으면 먹기 처리
    for (auto& pos : path) {
        auto it = find(game.itemTiles.begin(), game.itemTiles.end(), pos);
        if (it != game.itemTiles.end()) {
            game.breakTurns = 3; // 아이템 먹으면 봉쇄 타일 파괴 가능 턴 부여
            game.itemTiles.erase(it);
            game.score += 10; // 아이템 먹으면 점수 추가
            game.map[pos.y][pos.x] = Tile::Empty;
        }
    }

    // 마지막 위치에 플레이어 위치 설정
    game.player.x = nx;
    game.player.y = ny;
    game.map[ny][nx] = Tile::Player;

    if (game.breakTurns > 0) {
        game.breakTurns--;
    }

    return true;
}

void SealRandomTile(Game& game) {
    vector<Position> candidates;

    for (int y = PLAYABLE_START; y <= PLAYABLE_END; ++y) {
        for (int x = PLAYABLE_START; x <= PLAYABLE_END; ++x) {
            if (game.map[y][x] == Tile::Empty) {
                candidates.push_back({ x, y });
            }
        }
    }

    if (candidates.empty()) return;

    int idx = rand() % candidates.size();
    Position pos = candidates[idx];
    game.map[pos.y][pos.x] = Tile::Sealed;
    game.sealedTiles.push_back(pos);
}

void GameOver(Game& game) {
    game.gameOver = true;
}

bool CanMoveSealedTiles(const Game& game, int dx, int dy) {
    for (const auto& pos : game.sealedTiles) {
        int nx = pos.x + dx;
        int ny = pos.y + dy;

        if (nx < 0 || nx >= BOARD_SIZE || ny < 0 || ny >= BOARD_SIZE)
            return false;

        Tile t = game.map[ny][nx];
        if (t == Tile::Wall || t == Tile::Sealed)
            return false;
    }
    return true;
}

void MoveSealedTiles(Game& game, int dx, int dy) {
    if (game.sealedTiles.empty()) return;

    if (!CanMoveSealedTiles(game, dx, dy)) {
        return;
    }

    // 이동 순서 결정
    if (dx > 0) {
        for (int i = (int)game.sealedTiles.size() - 1; i >= 0; --i) {
            Position pos = game.sealedTiles[i];
            game.map[pos.y][pos.x] = Tile::Empty;

            pos.x += dx;
            pos.y += dy;

            if (pos.x == game.player.x && pos.y == game.player.y)
                GameOver(game);

            // 아이템 겹침 제거
            auto it = find(game.itemTiles.begin(), game.itemTiles.end(), pos);
            if (it != game.itemTiles.end()) {
                game.itemTiles.erase(it);
            }

            game.sealedTiles[i] = pos;
            game.map[pos.y][pos.x] = Tile::Sealed;
        }
    }
    else if (dx < 0) {
        for (size_t i = 0; i < game.sealedTiles.size(); ++i) {
            Position pos = game.sealedTiles[i];
            game.map[pos.y][pos.x] = Tile::Empty;

            pos.x += dx;
            pos.y += dy;

            if (pos.x == game.player.x && pos.y == game.player.y)
                GameOver(game);

            auto it = find(game.itemTiles.begin(), game.itemTiles.end(), pos);
            if (it != game.itemTiles.end()) {
                game.itemTiles.erase(it);
            }

            game.sealedTiles[i] = pos;
            game.map[pos.y][pos.x] = Tile::Sealed;
        }
    }
    else if (dy > 0) {
        for (int i = (int)game.sealedTiles.size() - 1; i >= 0; --i) {
            Position pos = game.sealedTiles[i];
            game.map[pos.y][pos.x] = Tile::Empty;

            pos.x += dx;
            pos.y += dy;

            if (pos.x == game.player.x && pos.y == game.player.y)
                GameOver(game);

            auto it = find(game.itemTiles.begin(), game.itemTiles.end(), pos);
            if (it != game.itemTiles.end()) {
                game.itemTiles.erase(it);
            }

            game.sealedTiles[i] = pos;
            game.map[pos.y][pos.x] = Tile::Sealed;
        }
    }
    else if (dy < 0) {
        for (size_t i = 0; i < game.sealedTiles.size(); ++i) {
            Position pos = game.sealedTiles[i];
            game.map[pos.y][pos.x] = Tile::Empty;

            pos.x += dx;
            pos.y += dy;

            if (pos.x == game.player.x && pos.y == game.player.y)
                GameOver(game);

            auto it = find(game.itemTiles.begin(), game.itemTiles.end(), pos);
            if (it != game.itemTiles.end()) {
                game.itemTiles.erase(it);
            }

            game.sealedTiles[i] = pos;
            game.map[pos.y][pos.x] = Tile::Sealed;
        }
    }
}

void GenerateItem(Game& game) {
    vector<Position> candidates;

    for (int y = PLAYABLE_START; y <= PLAYABLE_END; ++y) {
        for (int x = PLAYABLE_START; x <= PLAYABLE_END; ++x) {
            if (game.map[y][x] == Tile::Empty) {
                candidates.push_back({ x, y });
            }
        }
    }

    if (candidates.empty()) return;

    int idx = rand() % candidates.size();
    Position pos = candidates[idx];
    game.map[pos.y][pos.x] = Tile::Item;
    game.itemTiles.push_back(pos);
}

void ProcessInput(Game& game, char input) {
    if (game.gameOver) return;

    int dx = 0, dy = 0;
    switch (input) {
    case 'w': case 'W': dx = 0; dy = -1; break;
    case 's': case 'S': dx = 0; dy = 1; break;
    case 'a': case 'A': dx = -1; dy = 0; break;
    case 'd': case 'D': dx = 1; dy = 0; break;
    default: return;
    }

    if (MovePlayer(game, dx, dy)) {
        game.moveCount++;
        SealRandomTile(game);

        if ((int)game.sealedTiles.size() > MAX_SEALED) {
            MoveSealedTiles(game, dx, dy);
        }

        if (game.moveCount % 20 == 0) {
            GenerateItem(game);
        }
    }
}

int main() {
    srand((unsigned int)time(nullptr));

    Game game;
    InitGame(game);

    while (!game.gameOver) {
        DrawMap(game);
        cout << "WASD로 이동하세요: ";
        char input = _getch();

        ProcessInput(game, input);
    }

    cout << "게임 오버! 최종 점수: " << game.score << "\n";
    system("pause");
    return 0;
}
/*
* 1. 10*10격자판에서 진행/추후변경 될 수 있음
* 2. player 상하좌우 방향키로 이동
* 3. 이동시 무조건 벽에 닿을 때까지 이동
* 4. player가 이동할때마다 랜덤타일이 봉쇄됨
* 4.1 봉쇄타일은 벽으로 취급된다.
* 5. 봉쇄된 타일이 타일갯수의 10개를 넘기면 player이동이 완전히 이동한 뒤에
*		이동한 방향으로 모든 봉쇄타일이 1칸 이동함
* 6. 이동한 봉쇄타일에 player가 겹쳐질 경우 게임오버
* 7. 유저가 20번 행동할때마다 랜덤 타일에 아이템 생성
*		아이템은 반드시 유저,봉쇄타일에 겹치지 않게 생성된다.
* 8. player가 접근시 다음 3회 이동 동안 충돌하는 봉쇄타일파괴가능
*		파괴된 봉쇄타일은 다시 일반타일이 딘다.
* 9. 봉쇄타일이 아이템과 겹쳐질경우 아이템 소멸
*		아이템은 player가 먹거나 이동한 봉쇄블록이 아이템을 제거할때까지 남아있으며
*		여러개 존재할수 있다.
* 10. 유저의 총이동횟수 1score 파괴한 봉쇄블록5score로 게임오버시 점수계산
* 문제점
* 1. 패턴의 단순함(심각도 높음)
*/