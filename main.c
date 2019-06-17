#include <raylib.h>

int main(){
    
    const int WindoWidth = 1280; // Largura da janela
    const int WindowHeight = 720; // Altura da janela
    
    InitWindow(WindoWidth, WindowHeight, "Jogo de IP1 - Titulo indefinido"); // titulo indefinido por enquanto
    
    SetTargetFPS(60); //Não entendi muito bem , mas parece que é a velocidade dos frames
    
    while(!WindowShouldClose()){ // Até a janela ser fechada o jogo rola
            BeginDrawing(); 
            
                ClearBackground(RAYWHITE); //Pra o fundo ficar em branco
            
            
            EndDrawing();
    }
    
    
    return 0;
}