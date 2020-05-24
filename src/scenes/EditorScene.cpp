#include "scenes/EditorScene.h"

EditorScene::EditorScene(SDL_Window* window) {
    world = new World();
    world->registerSystem(new RenderSystem(window, SNES_RESOLUTION_WIDTH, SNES_RESOLUTION_HEIGHT));
    world->registerSystem(new EditorSystem());
    world->registerSystem(new TileSystem());
    world->registerSystem(new PhysicsSystem());


    //FIRST COLUMN (left aligned)
    auto title = world->create();
    title->assign<TextComponent>("MAP EDITOR MODE");
    title->assign<TransformComponent>(10, 10, 60, 8);

    auto instructions1 = world->create();
    instructions1->assign<TextComponent>("up down keys change tiles");
    instructions1->assign<TransformComponent>(10, 20, 80, 5);

    auto instructions2 = world->create();
    instructions2->assign<TextComponent>("press keys a and d to pan camera");
    instructions2->assign<TransformComponent>(10, 26, 90, 5);

    auto instructions3 = world->create();
    instructions3->assign<TextComponent>("press s to save the map to disk");
    instructions3->assign<TransformComponent>(10, 32, 86, 5);

    auto instructions4 = world->create();
    instructions4->assign<TextComponent>("click to add and remove tiles");
    instructions4->assign<TransformComponent>(10, 38, 80, 5);

    auto instructions5 = world->create();
    instructions5->assign<TextComponent>("press e to exit the editor");
    instructions5->assign<TransformComponent>(10, 44, 80, 5);
}

void EditorScene::update() {
    Scene::update();
    world->tick();
}

