#include "ObjectView.h"
#include "SFML/Graphics.hpp"
#include "iostream"


ObjectView::ObjectView(std::vector<Entity*>* ListOfObjects, const std::string& PathToObjects) { //TODO: draw it somehow

    EntitiesList = ListOfObjects;

    auto* t = new sf::Texture;
    t->loadFromFile(PathToObjects + "\\" + "Player.png");
    PlayerSprite.setTexture(*t);
    PlayerSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

}

void ObjectView::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(PlayerSprite);
}

void ObjectView::Update() {
    float PlayerX = EntitiesList->at(0)->getPosition().first;
    float PlayerY = EntitiesList->at(0)->getPosition().second;
    PlayerSprite.setPosition(PlayerX, PlayerY);
}
