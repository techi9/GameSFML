#include "ObjectView.h"
#include "SFML/Graphics.hpp"
#include "iostream"


ObjectView::ObjectView(std::vector<Entity*>* ListOfObjects, const std::string& PathToObjects) { //TODO: draw it somehow

    EntitiesList = ListOfObjects;

    auto* t = new sf::Texture;
    t->loadFromFile(PathToObjects + "\\" + "Player.png");
    PlayerSprite.setTexture(*t);
    PlayerSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

    auto* turretTexture = new sf::Texture;
    turretTexture->loadFromFile(PathToObjects + "\\" + "Turret.png");
    TurretSprite.setTexture(*turretTexture);

    auto* trollTexture = new sf::Texture;
    trollTexture->loadFromFile(PathToObjects + "\\" + "troll.png");
    TrollSprite.setTexture(*trollTexture);

}

void ObjectView::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(PlayerSprite);
    target.draw(TurretSprite);
    target.draw(TrollSprite);
}

void ObjectView::Update() {
    float PlayerX = EntitiesList->at(0)->getPosition().first;
    float PlayerY = EntitiesList->at(0)->getPosition().second;
    TurretSprite.setPosition(EntitiesList->at(1)->getPosition().first, EntitiesList->at(1)->getPosition().second);
    PlayerSprite.setPosition(PlayerX, PlayerY);
    TrollSprite.setPosition(EntitiesList->at(2)->getPosition().first, EntitiesList->at(2)->getPosition().second);
}
