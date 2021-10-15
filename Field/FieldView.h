#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include "Field.h"
#include "string"
using namespace std;

class FieldView: public sf::Drawable {
    string BorderCadification[9]{"tl", "t", "tr", "l", "c", "r", "bl", "b", "br"};
    bool InitTextures();
    std::map<string, sf::Texture*> LoadTextures(const string& TextureFileName, bool versatile = false);
    Field *field;
    std::map<enum Tile::type, std::map<string, sf::Texture*>> textures; //['Tile::type'][BorderCadification] = Texture
    string pathToTilemap;
public:
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    FieldView(Field* field, string pathToTilemap);
    void DrawField();

};
