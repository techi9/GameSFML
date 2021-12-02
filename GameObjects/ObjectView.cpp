#include "ObjectView.h"
#include "SFML/Graphics.hpp"
#include "iostream"
#include "string"


ObjectView::ObjectView(std::vector<Entity*>* ListOfObjects, std::vector<Item*>* ListOfItems, const std::string& PathToObjects) { //TODO: draw it somehow
    if(!font.loadFromFile("../Roboto-Black.ttf")){
        cerr<<"ERROR LOADING FONT\n";
    }
    EntitiesList = ListOfObjects;
    this->ItemList = ListOfItems;

    PlayerSprite.loadFromFile(PathToObjects + "\\" + "Player.png");
    TurretSprite.loadFromFile(PathToObjects + "\\" + "Turret.png");
    TrollSprite.loadFromFile(PathToObjects + "\\" + "troll.png");
    GoblinTexture.loadFromFile(PathToObjects + "\\" + "Goblin.png");
    HyperstoneTexture.loadFromFile(PathToObjects + "\\" + "Hyperstone.png");
    HealPotionTexture.loadFromFile(PathToObjects + "\\" + "Sword.png");
    SwordTexture.loadFromFile(PathToObjects + "\\" + "HealPotion.png");



}

void ObjectView::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    for (auto &ent : *EntitiesList){
        sf::Sprite t;
        string typ = typeid(*ent).name();
        if (typ.compare("5Troll") == 0){
            t.setTexture(TrollSprite);
        }
        else if(typ.compare("6Goblin") == 0){
            t.setTexture(GoblinTexture);
        }
        else if(typ.compare("6Turret") == 0){
            t.setTexture(TurretSprite);
        }
        else if(typ.compare("6Player") == 0){
            t.setTexture(PlayerSprite);
        }
        else return;

        sf::Text text;
        text.setFont(font);
        text.setString(std::to_string(ent->getHealth()));
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Black);
        text.setPosition(ent->getPosition().first, ent->getPosition().second - 30);


        t.setPosition(ent->getPosition().first, ent->getPosition().second);

        target.draw(text);
        target.draw(t);

    }
    for (auto &item : *ItemList){
        sf::Sprite t;
        string typ = typeid(*item).name();

        if (typ.compare("5Troll") == 0){
            t.setTexture(TrollSprite);
        }
        else if(typ.compare("5Sword") == 0){
            t.setTexture(SwordTexture);
        }
        else if(typ.compare("10HealPotion") == 0){
            t.setTexture(HealPotionTexture);
        }
        else if(typ.compare("10Hyperstone") == 0){
            t.setTexture(HyperstoneTexture);
        }
        else throw "No texture found to draw obj";

        t.setPosition(item->getPosition().first, item->getPosition().second);


        target.draw(t);

    }
}

void ObjectView::Update() {

}
