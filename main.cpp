#include "raylib.h"
#include "raymath.h"

int main() {

    const int window_width{1080};
    const int window_height{800};
    const char *title{"Classy Clash"};
    const int FPS{60};

    InitWindow(window_width,window_height,title);
    SetTargetFPS(FPS);

    Texture2D map{LoadTexture("/home/ashfaque/CLionProjects/C++/GameProgramming/ClassyClash/nature_tileset/OpenWorldMap24x24.png")};
    Vector2 map_position{0.0,0.0};

    const float speed{4.0};

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 direction{};
        if(IsKeyDown(KEY_A)) direction.x-=1.0;
        if(IsKeyDown(KEY_D)) direction.x+=1.0;

        if(IsKeyDown(KEY_W)) direction.y-=1.0;
        if(IsKeyDown(KEY_S)) direction.y+=1.0;

        if(Vector2Length(direction)!=0.0){
            map_position= Vector2Subtract(map_position, Vector2Scale(Vector2Normalize(direction),speed));
        }


        DrawTextureEx(map,map_position,0.0,4.0,WHITE);

        EndDrawing();

    }

    CloseWindow();


    return 0;
}
