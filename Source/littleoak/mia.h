#ifndef LITTLEOAK_MIA_H
#define LITTLEOAK_MIA_H

#include "harley/sfml.h"
#include "possum/possum.h"

void redrawMia(possum::Entity& entity, possum::Scene& scene, possum::Game& game, void* data);

void walkDown(possum::Entity&, possum::Scene&, possum::Game&, void*);
void walkUp(possum::Entity&, possum::Scene&, possum::Game&, void*);
void walkLeft(possum::Entity&, possum::Scene&, possum::Game&, void*);
void walkRight(possum::Entity&, possum::Scene&, possum::Game&, void*);

void update(possum::Entity& entity);

void redrawMiaDialogue1(possum::Entity& entity, possum::Scene& scene, possum::Game& game, void* data);
void updateMiaDialogue1(possum::Entity& entity, possum::Scene& scene, possum::Game& game, void* data);

void redrawMiaDialogue2(possum::Entity& entity, possum::Scene& scene, possum::Game& game, void* data);
void updateMiaDialogue2(possum::Entity& entity, possum::Scene& scene, possum::Game& game, void* data);

void keyPress(possum::Entity& entity, possum::Scene& scene, possum::Game& game, void* data);

void collisionMia(possum::Entity& entity, possum::Scene& scene, possum::Game& game, void* data);

void createMia(sf::Texture& mia_texture, possum::Scene& scene);

#endif // LITTLEOAK_MIA_H
