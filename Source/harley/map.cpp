#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "map.h"
#include "constants.h"

//Event callbacks
void redraw_map(possum::Entity& entity, possum::Scene& scene, possum::Game& game, void* data){
    sf::RenderWindow& window = *(sf::RenderWindow*)(data);
    game.state["mapWidth"] = entity.state["width"];
    game.state["mapHeight"] = entity.state["height"];
    int tile_width = (game.state["width"] + TILE_SIZE - 1)/TILE_SIZE/SCALE;
    int tile_height = (game.state["height"] + TILE_SIZE - 1)/TILE_SIZE/SCALE;
    int startX = std::max(0, (game.state["tileX"]/TILE_SIZE)-(tile_width+1)/2);
    int startY = std::max(0, (game.state["tileY"]/TILE_SIZE)-(tile_height+1)/2);
    int endX = std::min(entity.state["width"], startX+tile_width);
    int endY = std::min(entity.state["height"], startY+tile_height);
    startX = endX - tile_width;
    startY = endY - tile_height;
    // std::cout << startX << ", " << startY << ", " << endX << ", " << endY << ", " << game.state.get("tileX") / TILE_SIZE << ", " << game.state.get("tileY") / TILE_SIZE << std::endl;
    for (int i = startX; i <= endX; i++) {
        for (int j = startY; j <= endY; j++) {
            std::stringstream location;
            location << j << " " << i;
            int tile = entity.state[location.str()];
            int tx = tile % entity.state["tilesetWidth"];
            int ty = tile / entity.state["tilesetWidth"];
            entity.sprite.setTextureRect(sf::IntRect(tx*TILE_SIZE, ty*TILE_SIZE, TILE_SIZE, TILE_SIZE));
            entity.sprite.setPosition((TILE_SIZE*i)*SCALE, (TILE_SIZE*j)*SCALE);

            window.draw(entity.sprite);
        }
    }
}

void keydown_map(possum::Entity& entity, possum::Scene& scene, possum::Game& game, void* data){
    sf::Event::KeyEvent& event = *(sf::Event::KeyEvent*)(data);
    if (event.code == sf::Keyboard::Escape){
        game.quit();
    }
}

namespace Harley
{

    void Map::load_chunks(possum::Scene& scene, sf::Texture& tileset, std::string name, int width, int height, int chunk_width, int chunk_height)
    {
        std::string line;
        int chunk_x_offset = 0;
        int chunk_y_offset = 0;
        int chunk_x_increment = width / chunk_width;
        int chunk_y_increment = height / chunk_height;
        possum::Entity& entity = scene.create(MAP, 0, 0, 0, tileset);
        entity.sprite.setScale(SCALE, SCALE);
        entity.sprite.setOrigin(0, 0);
        for (int chunk_x = 1; chunk_x <= chunk_width; chunk_x++){
            chunk_y_offset = 0;
            for (int chunk_y = 1; chunk_y <= chunk_height; chunk_y++){
                std::stringstream file;
                file << name << "_" << chunk_x << "_" << chunk_y << ".csv";
                std::ifstream content(file.str().c_str());
                int y = 0;
                int x;
                while (std::getline(content, line)){
                    std::istringstream data(line);
                    x = 0;
                    int i;
                    char c;
                    while (data >> i){
                        std::stringstream location;
                        location << chunk_y_offset + y << " " << chunk_x_offset + x;
                        entity.state[location.str()] = i;
                        if (i > BEGIN_OBSTACLE){
                            scene.create(OBSTACLE, chunk_x_offset+x+TILE_SIZE/2, chunk_y_offset+y+TILE_SIZE/2, TILE_SIZE/2, tileset);
                        }
                        x++;
                        data >> c;
                    }
                    y++;
                }
                chunk_y_offset += chunk_y_increment;
            }
            chunk_x_offset += chunk_x_increment;
        }
        entity.state["width"] = width;
        entity.state["height"] = height;
        entity.state["tilesetWidth"] = entity.texture.getSize().x/TILE_SIZE;
        entity.register_event(possum::REDRAW, redraw_map);
        entity.register_event(possum::KEY_DOWN, keydown_map);
    }

    void Map::load(possum::Entity& entity, std::string name){
        entity.sprite.setScale(SCALE, SCALE);
        entity.sprite.setOrigin(0, 0);
        std::ifstream content(("Resources/" + name + ".csv").c_str());
        std::string line;
        int y = 0;
        int x = 0;
        while (std::getline(content, line)){
            std::istringstream data(line);
            x = 0;
            int i;
            char c;
            while (data >> i){
                std::stringstream location;
                location << y << " " << x;
                entity.state[location.str()] = i;
                x++;
                data >> c;
            }
            y++;
        }
        entity.state["width"] = x-1;
        entity.state["height"] = y-1;
        entity.state["tilesetWidth"] = entity.texture.getSize().x/TILE_SIZE;
        entity.register_event(possum::REDRAW, redraw_map);
        entity.register_event(possum::KEY_DOWN, keydown_map);
    }

}

