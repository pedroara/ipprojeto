#include "raylib.h"


void move_circ(int* posic)
{
    if(IsKeyPressed('W'))
    {
        if((*posic)>400)
        {
            (*posic) -= 30;
        }
    }
    if(IsKeyPressed('S'))
    {
        if((*posic)<490)
        {
            (*posic) += 30;
        }
    }
}
int main(void)
{
    int Largura_Tela = 1000;
    int Altura_Tela = 1000;
    int posic_circ = 400;
    InitWindow(Largura_Tela,Altura_Tela,"Starlight Drift");
    
    SetTargetFPS(60);
    while(!WindowShouldClose())
    {
        //Começando a desenhar e chamando as funções
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Maely",300,400,20,LIGHTGRAY);
        DrawText("Lucas",300,430,20,LIGHTGRAY);
        DrawText("Fernando",300,460,20,LIGHTGRAY);
        DrawText("Sabrina",300,490,20,LIGHTGRAY);
        DrawCircle(280,posic_circ,15,RED);
        move_circ(&posic_circ);
        
        EndDrawing();
    }
}