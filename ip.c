#include <raylib.h>
#include <stdio.h>

 void Desenharnivel (char cor1[],char cor2[],char cor3[])
 {
     DrawText("Jorge\nNivel 1", 100, 220, 40, cor1);
     DrawText("Carol\nNivel 2", 400, 220, 40, cor2);
     DrawText("Guilherme\nNivel 3", 700, 220, 40, cor3); 
 }
 void IniciarJogo (int level)
 { 
      
      BeginDrawing(); 
            
                ClearBackground(RAYWHITE); //Pra o fundo ficar em branco
                DrawText("Bem-vinda(o)", 300, 400, 40, BLACK); //primeiro número é a possição x, segundo é o y e o terceiro é o tamanho da letra
                DrawCircle(100, 120, 10, DARKBLUE); //mesma lógica da mensagem
                DrawCircle(200, 120, 10, DARKBLUE); 
                DrawCircleLines(150, 120, 80, WHITE); //sem preenchimento
                DrawLine(120, 170, 180, 170, WHITE);
                DrawCircle(400, 120, 10, RED); 
                DrawCircle(500, 120, 10, RED); 
                DrawLine(420, 170, 480, 170, WHITE);
                DrawCircleLines(450, 120, 80, WHITE); 
                DrawCircle(700, 120, 10, LIME); 
                DrawCircle(800, 120, 10, LIME); 
                DrawLine(720, 170, 780, 170, WHITE);
                DrawCircleLines(750, 120, 80, WHITE); 
                DrawLine(300, 450, 550, 450, YELLOW); //(x,y) do ponto de inicio da linha e (x,y) do ponto final
                   
     DrawText("Selecione um nível", 300, 300, 40, WHITE);
     if(level==1)
     {  
        Desenharnivel("WHITE","GRAY","GRAY");       
     }
     else if (level==2)
     {
       Desenharnivel("WHITE","WHITE","GRAY");       
     }
     else if (level>=3)
     {

        Desenharnivel("WHITE","WHITE","WHITE");
     }
     
 }

int main()
{
    
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
                DrawLine(120, 170, 180, 170, WHITE);
                DrawCircle(400, 120, 10, RED); 
                DrawCircle(500, 120, 10, RED); 
                DrawLine(420, 170, 480, 170, WHITE);
                DrawCircleLines(450, 120, 80, WHITE); 
                DrawCircle(700, 120, 10, LIME); 
                DrawCircle(800, 120, 10, LIME); 
                DrawLine(720, 170, 780, 170, WHITE);
                DrawCircleLines(750, 120, 80, WHITE); 
                DrawLine(300, 450, 550, 450, YELLOW); //(x,y) do ponto de inicio da linha e (x,y) do ponto final
                DrawText("Jorge\nNivel 1", 100, 220, 40, GRAY);
                DrawText("Carol\nNivel 2", 400, 220, 40, GRAY);
                DrawText("Guilherme\nNivel 3", 700, 220, 40, GRAY);
                ClearBackground(BLACK); 
                DrawText("Bem-vinda(o)", 300, 400, 40, WHITE); 
                DrawRectangleLines(290,490,300,60,YELLOW); //(x,y,tamanho,altura)
                DrawText("INICIAR JOGO", 300, 500, 40, WHITE); 
                DrawRectangleLines(290,590,350,60,YELLOW);
                DrawText("Um pouco sobre", 300, 600, 40, WHITE); 
                //DrawPixel(700,500,WHITE); 
                //DrawPixel(700,501,WHITE);
                //DrawPixel(700,502,WHITE); //Desenhar pontos
                //const char *GetClipboardTex(void); ?
                //void SetClipboardText(const char *IniciarJogo); ?
                int level = 1;
                if (IsKeyPressed(KEY_A))
                {
                    
                    int x = GetMouseY(); 
                    int y = GetMouseY();
                   // if (x>=290 && x<=300) tentando colocar as dimenssões certas do retângulo 
                    {
                       IniciarJogo(level);  
                    } 
                      
                   
                }
                Image LoadImage(const char *alo); //importando imagem do pc? (n consegui mostrar a imagem)
                //LoadMusicStream(const char *);
                // UnloadMusicStream(Music music); // Unload music stream 
                 //PlayMusicStream(Music music);
                
                
                    
                
            EndDrawing();
                
           
    }
    
    
    return 0;
}
