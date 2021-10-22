#include <SFML/Graphics/RenderWindow.hpp>
#include "../Field/Field.h"
#include "../Field/FieldView.h"
#include "CollsionMap.h"
#include "../GameObjects/Entity.h"
#include "../GameObjects/ObjectView.h"
#include "../GameObjects/Player/ControllerKeyboard.h"

class Game {
public:
    void CreateEntity(Entity *ent);
    void CreateObj(GameObj obj);
    ~Game();
    static void Init(int w, int h);
    static const Field* getField();
private:
    Game();
    Game(int w, int h);
    static Game game;
    int w, h;
    Field *field;
    FieldView *fview;
    CollsionMap *colMap;
    vector<Entity*> EntitiesList;
    ObjectView *objectView;
    void UpdateEntities();
    ControllerKeyboard* playerController;
    void RunLoop();
    sf::RenderWindow* window;
};

