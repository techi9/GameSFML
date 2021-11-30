#include "ObjectView.h"
#include "SFML/Graphics.hpp"
#include "iostream"
#include "string"


ObjectView::ObjectView(std::vector<Entity*>* ListOfObjects, const std::string& PathToObjects) { //TODO: draw it somehow
    if(!font.loadFromFile("../Roboto-Black.ttf")){
        cerr<<"ERROR LOADING FONT\n";
    }
    EntitiesList = ListOfObjects;


    PlayerSprite.loadFromFile(PathToObjects + "\\" + "Player.png");
    TurretSprite.loadFromFile(PathToObjects + "\\" + "Turret.png");
    TrollSprite.loadFromFile(PathToObjects + "\\" + "troll.png");
    GoblinTexture.loadFromFile(PathToObjects + "\\" + "Goblin.png");



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
}

void ObjectView::Update() {

}
