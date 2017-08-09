#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "map.h"
#include "constants.h"

//Event callbacks
void redraw_map(possum::Entity& entity, possum::State& gameState, void* data){
    sf::RenderWindow& window = *(sf::RenderWindow*)(data);
    gameState.set("mapWidth", entity.state.get("width"));
    gameState.set("mapHeight", entity.state.get("height"));
    int startX = std::max(0, (gameState.get("tileX")/TILE_SIZE)-(TILE_WIDTH+1)/2);
    int startY = std::max(0, (gameState.get("tileY")/TILE_SIZE)-(TILE_HEIGHT+1)/2);
    int endX = std::min(entity.state.get("width"), startX+TILE_WIDTH);
    int endY = std::min(entity.state.get("height"), startY+TILE_HEIGHT);
    startX = endX - TILE_WIDTH;
    startY = endY - TILE_HEIGHT;
    int centerX = std::max(std::min(gameState.get("tileX"), entity.state.get("width")*TILE_SIZE-SCREEN_WIDTH/2), SCREEN_WIDTH/2);
    int centerY = std::max(std::min(gameState.get("tileY"), entity.state.get("height")*TILE_SIZE-SCREEN_HEIGHT/2), SCREEN_HEIGHT/2);
    // std::cout << endX << ", " << endY << ", " << gameState.get("tileX") / TILE_SIZE << ", " << gameState.get("tileY") / TILE_SIZE << std::endl;
    for (int i = startX; i <= endX; i++) {
        for (int j = startY; j <= endY; j++) {
            std::stringstream location;
            location << j << " " << i;
            int tile = entity.state.get(location.str());
            int tx = tile % entity.state.get("tilesetWidth");
            int ty = tile / entity.state.get("tilesetWidth");
            entity.sprite.setTextureRect(sf::IntRect(tx*TILE_SIZE, ty*TILE_SIZE, TILE_SIZE, TILE_SIZE));
            entity.sprite.setPosition(((TILE_SIZE*i)-centerX + SCREEN_WIDTH/2)*SCALE, ((TILE_SIZE*j)-centerY+SCREEN_HEIGHT/2)*SCALE);

            window.draw(entity.sprite);
        }
    }
}

namespace Harley
{

	void Map::load_chunks(possum::Entity& entity, std::string name, int width, int height, int chunk_width, int chunk_height)
    {
        std::string line;
        int chunk_x_offset = 0;
        int chunk_y_offset = 0;
        int chunk_x_increment = width / chunk_width;
        int chunk_y_increment = height / chunk_height;
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
                        entity.state.set(location.str(), i);
                        x++;
                        data >> c;
                    }
                    y++;
                }
                chunk_y_offset += chunk_y_increment;
            }
            chunk_x_offset += chunk_x_increment;
        }
        entity.state.set("width", width);
        entity.state.set("height", height);
        entity.state.set("tilesetWidth", entity.texture.getSize().x/TILE_SIZE);
        entity.register_event(possum::REDRAW, redraw_map);
    }

    void Map::load(possum::Entity& entity, std::string name){
        std::ifstream content(("Resources/" + name + ".csv").c_str());
        std::string line;
        int y = 0;
        int x;
        while (std::getline(content, line)){
            std::istringstream data(line);
            x = 0;
            int i;
            char c;
            while (data >> i){
                std::stringstream location;
                location << y << " " << x;
                entity.state.set(location.str(), i);
                x++;
                data >> c;
            }
            y++;
        }
        entity.state.set("width", x-1);
        entity.state.set("height", y-1);
        entity.state.set("tilesetWidth", entity.texture.getSize().x/TILE_SIZE);
        entity.register_event(possum::REDRAW, redraw_map);
    }

}

