#ifndef GAMESFML_OBJECTVIEW_H
#define GAMESFML_OBJECTVIEW_H

#include "Entity.h"
#include "vector"
#include "SFML/Graphics.hpp"
#include "string"
class ObjectView : public sf::Drawable{
private:
    sf::Sprite PlayerSprite;
    std::vector<Entity*> *EntitiesList;
public:
    ObjectView(std::vector<Entity*> *ListOfObjects, const std::string& PathToObjects);
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    void Update();
};


#endif
