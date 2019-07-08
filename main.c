#include "raylib.h"
#include <stdio.h>
#include <stdlib.h

//Verificar qual level a pessoa está e atribuir a um int check
int qual_level(int checkpoint){
     //PARA O ARMAZENAMENTO (LER)
    FILE *level;
    level = fopen("checkpoint.txt" , "r");
    //Variavel aonde estará armazenado em qual fase ele está
    int levelum, leveldois, leveltres;
    //Função que escreve do arquivo (.txt) e passa para as variaveis levelum, leveldois, leveltres
    fscanf(level, "%i %i %i", &levelum, &leveldois, &leveltres);
    //Função para parar de ler o arquivo
    fclose(level);
    //Caso o jogador só tenha o primeiro level desbloqueado
    if(levelum+leveldois+leveltres == 1){
        return checkpoint = 1;
    }
    //Caso o jogador tenha os dois primeiros level desbloqueado
    if(levelum+leveldois+leveltres == 2){
        return checkpoint = 2;
    }
    //Caso o jogador tenha os três primeiros level desbloqueado
    if(levelum+leveldois+leveltres == 3){
        return checkpoint = 3;
    }
}//end qual_level()

int subiu_de_level(int checkpoint){
    //ESCREVENDO NO ARQUIVO (checkpoint.txt)
    FILE *level;
    level = fopen("checkpoint.txt" , "w");
    //Variaveis criadas no escopo dessa função
    int levelum = 0, leveldois = 0, leveltres = 0;
    //Se a função for chamada quando o checkpoint = 1; será escrito no arquivo checkpoint.txt 1 1 0
    if(checkpoint == 1){
        fprintf("checkpoint.txt" , "1 1 0");
    }
    //Se a função for chamada quando o checkpoint = 2; será escrito no arquivo checkpoint.txt 1 1 1
    if(checkpoint == 2){
        fprintf("checkpoint.txt" , "1 1 1");
    }
    //Por precaução se a função for chamada quando o checkpoint = 3; será escrito no arquivo checkpoint.txt 1 1 1
    if(checkpoint == 3){
        fprintf("checkpoint.txt" , "1 1 1");
    }
}//end subiu_de_level()

int main(void){
    int check ;
    check = qual_level(0);
    int levelAtual = check;
    //Se o cara subir de level: check = subiu_de_level(levelAtual);
    
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
