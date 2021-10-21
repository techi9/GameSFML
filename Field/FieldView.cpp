#include "FieldView.h"
#include "iostream"
#include <utility>

bool FieldView::InitTextures() {
    this->textures.emplace(Tile::TERRAIN,  LoadTextures("grass", true));
    this->textures.emplace(Tile::WATER,  LoadTextures("water"));
    return true; //TODO: add check
}

FieldView::FieldView(Field* field, string pathToTilemap){
    this->field = field;
    this->pathToTilemap = std::move(pathToTilemap);
    InitTextures();
}


map<string, sf::Texture *> FieldView::LoadTextures(const string& TextureFileName, bool versatile) { //TODO:requires destructor
    map<string, sf::Texture *> m;
    sf::Texture *texture[9];
    if(versatile)
    {
        for(int i = 0; i<9;i++) {
            texture[i] = new sf::Texture;
            texture[i]->loadFromFile(pathToTilemap + "/" + TextureFileName + "_" + BorderCadification[i]+".png");
            m.emplace(BorderCadification[i], texture[i]);
        }

    }
    else
    {
        auto* t = new sf::Texture;
        t->loadFromFile(pathToTilemap + "\\" + TextureFileName+".png");
        for(const string& i : BorderCadification) {
            m.emplace(i, t);
        }
    }
    return m;
}

void FieldView::DrawField(){
    for(int j = 0; j < field->height; j++)
    {
        for(int i = 0; i < field->width; i++)
        {
            if (field->Tiles[i][j]->content)
                std::cout << field->Tiles[i][j]->content->ObjType();
            else
                std::cout << ((field->Tiles[i][j]->GetType() == Tile::TERRAIN) ? "# " : "~ ");
        }
        std::cout<<std::endl;
    }
}

void FieldView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (int i=0; i<this->field->height; i++)
    {
        for (int j=0; j<this->field->width; j++)
        {
            //TODO: create logic for drawing sides
            sf::Texture t  = *(this->textures.at(field->Tiles[j][i]->GetType()).at("c"));
            sf::Sprite sprite;
            sprite.setTexture(t, false);
            sprite.move(j*sprite.getLocalBounds().width, i*sprite.getLocalBounds().height);
            target.draw(sprite);

        }
    }
}

FieldView::~FieldView(){
    map<string, sf::Texture *> m;
    for (auto tex : textures){
        m = std::move(tex.second);
        if(m[BorderCadification[0]] == m[BorderCadification[1]])
        {
            delete m[BorderCadification[0]];
            m[BorderCadification[0]] = nullptr;
        }
        else
            for (const auto& borders : BorderCadification) {
                if (m[borders])
                {
                    delete m[borders];
                    m[borders] = nullptr;
                }
            }
    }
}

