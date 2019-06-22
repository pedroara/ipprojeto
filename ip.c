#include <raylib.h>

int main(){
    
    const int WindoWidth = 1280; // Largura da janela
    const int WindowHeight = 720; // Altura da janela
    
    InitWindow(WindoWidth, WindowHeight, "Jogo de IP1 - Titulo indefinido"); // titulo indefinido por enquanto
    
    SetTargetFPS(40); //É a velocidade dos frames por segundo (quando menor o número mais lento fica a mudança de imagens)
    
    while(!WindowShouldClose())
    { // Até a janela ser fechada o jogo roda
            BeginDrawing(); 
            
                ClearBackground(RAYWHITE); //Pra o fundo ficar em branco
                DrawText("Bem-vinda(o)", 300, 400, 40, BLACK); //primeiro número é a possição x, segundo é o y e o terceiro é o tamanho da letra
                DrawCircle(100, 120, 10, DARKBLUE); //mesma lógica da mensagem
                DrawCircle(200, 120, 10, DARKBLUE); 
                DrawCircleLines(150, 120, 80, WHITE); //sem preenchimento
                DrawLine(300, 450, 550, 450, YELLOW); //(x,y) do ponto de inicio da linha e (x,y) do ponto final
     
                ClearBackground(BLACK); 
                DrawText("Bem-vinda(o)", 300, 400, 40, WHITE); 
            EndDrawing();
           
    }
    
    
    return 0;
}