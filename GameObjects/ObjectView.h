#ifndef GAMESFML_OBJECTVIEW_H
#define GAMESFML_OBJECTVIEW_H

#include "Entity.h"
#include "Items/Item.h"
#include "vector"
#include "SFML/Graphics.hpp"
#include "string"
#include "typeinfo"

class ObjectView : public sf::Drawable{
private:
    sf::Font font;
    sf::Texture PlayerSprite;
    sf::Texture TurretSprite;
    sf::Texture TrollSprite;
    sf::Texture GoblinTexture;
    sf::Texture HealPotionTexture;
    sf::Texture SwordTexture;
    sf::Texture HyperstoneTexture;
    std::vector<Entity*> *EntitiesList;
    std::vector<Item*> *ItemList;

public:
    ObjectView(std::vector<Entity*> *ListOfObjects, std::vector<Item*>* ListOfItems, const std::string& PathToObjects);
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    void Update();
};


#endif
