#include <raylib.h>
#include <stdio.h>
#include <math.h>

void sobrenos(){
    //Musica:
    Music nos = LoadMusicStream("/jogoip/Warriors.ogg");
    PlayMusicStream(nos);
    SetMusicVolume(nos, 0.2);    
          Image Sobre = LoadImage("/jogoip/Sobre.png");
          ImageResize(&Sobre,1005,700);
          Texture2D sobretx = LoadTextureFromImage(Sobre);
    
   while(!WindowShouldClose())
   { 
        //Pra musica tocar:
          UpdateMusicStream(nos);
        //Carregando e redimensionando a imagem:
      
        BeginDrawing();
        ClearBackground(BLACK); 
      //Desenhar textura na tela:
      DrawTexture(sobretx,200,30,RAYWHITE);  
      
      if (IsKeyPressed(KEY_ENTER)){
          menu();
      }
        EndDrawing();
   }
    CloseWindow();
}

typedef struct {
   int raio;
   int x,y;      
}circulo;
void movimentacao(Rectangle* Jorger){
        if (IsKeyDown(KEY_DOWN))
        {
            (Jorger->y)+= 4; //y cresce para baixo.
        }
        else if(IsKeyDown(KEY_UP))
        {
            (Jorger->y) -= 4;
        }
        else if(IsKeyDown(KEY_RIGHT))
        {
            (Jorger->x) +=4;
        }
        else if(IsKeyDown(KEY_LEFT))
        {
            (Jorger->x) -=4;
        }
}
void colisao(Rectangle* Jorger){ 
           if(IsKeyDown(KEY_LEFT))
           {
               (Jorger->x)+=4;
           }
           if(IsKeyDown(KEY_RIGHT))
           {
               (Jorger->x)-=4;
           }
           if(IsKeyDown(KEY_UP))
           {
               (Jorger->y)+=4;
           }
           if(IsKeyDown(KEY_DOWN))
           {
               (Jorger->y)-=4;
           } 
}
void tamanhotela(Rectangle* Jorger, int screenHeight,int screenWidth){
        if(Jorger->x+53>screenWidth)
        {
            Jorger->x = screenWidth-53;
        }
        else if(Jorger->x-8<0) 
        {
            Jorger->x=0+8;
        }
        else if(Jorger->y+52>screenHeight)
        {
            Jorger->y=screenHeight-52;
        }
        else if(Jorger->y-10<0)
        {
            Jorger->y=0+10;
        }
}
void desenharconflito(Texture2D fala){
     
      DrawTexture(fala,0,570,RAYWHITE);
      DrawText("CONFLITO: Ir para a festa de Carla.\nAjude Jorge a deixar seus pensamentos mais funcionais",220,630,20,WHITE);
      DrawText("[PRESS A] Ninguém me quer lá\n[PRESS B] Vai ser divertido!",220,680,20,WHITE);
     
}
void desenharconflito2(Texture2D fala){
     
     DrawTexture(fala,0,570,RAYWHITE);
     DrawText("CONFLITO: Na festa, alguém te chamou para dançar.\n",220,630,20,WHITE);
     DrawText("[PRESS A] Sim. Estou entre amigos, ninguém vai ligar\n[PRESS B] Não. Vou passar vergonha",220,680,20,WHITE);
     
}
void desenharconflito3(Texture2D fala){
     
     DrawTexture(fala,0,570,RAYWHITE);
     DrawText("CONFLITO: Alguém está olhando para você.\n",220,630,20,WHITE);
     DrawText("[PRESS A] Talvez ela queira conversar\n[PRESS B] Há algo de errado comigo",220,680,20,WHITE);
     
}
void desenharconflito4(Texture2D fala){
     
     DrawTexture(fala,0,570,RAYWHITE);
     DrawText("CONFLITO: Apresentar trabalho em público.\nAjude Jorge a deixar seus pensamentos mais funcionais",220,630,20,WHITE);
     DrawText("[PRESS A] Todo mundo já esteve na mesma situação\n[PRESS B] Todos vão estar me julgando",220,680,20,WHITE);
     
}
void desenharconflito5(Texture2D fala){
     
     DrawTexture(fala,0,570,RAYWHITE);
     DrawText("CONFLITO: Um grupo de pessoas está rindo no fundo da sala.\n",220,630,20,WHITE);
     DrawText("[PRESS A] Estão rindo de mim\n[PRESS B] Eles conversam em todas as aulas",220,680,20,WHITE);
}
void desenharconflito6(Texture2D fala){
     
     DrawTexture(fala,0,570,RAYWHITE);
     DrawText("CONFLITO: O professor está escrevendo algo em sua prancheta.\n",220,630,20,WHITE);
     DrawText("[PRESS A] Ele só está tomando notas\n[PRESS B] Eu estou falando tudo errado",220,680,20,WHITE);
     
}
void desenharconflito7(Texture2D fala){
     
     DrawTexture(fala,0,570,RAYWHITE);
     DrawText("CONFLITO: Estar em um elevador cheio.\nAjude Jorge a deixar seus pensamentos mais funcionais",220,630,20,WHITE);
     DrawText("[PRESS A] Vou ficar sem ar!\n[PRESS B] Vai dar tudo certo!",220,680,20,WHITE);
     
}
void desenharconflito8(Texture2D fala){
     
     DrawTexture(fala,0,570,RAYWHITE);
     DrawText("CONFLITO: O lugar está apertado.\n",220,630,20,WHITE);
     DrawText("[PRESS A] Tem mais gente do que o elevador aguenta\n[PRESS B] Só está um pouco cheio",220,680,20,WHITE);
     
}
void desenharconflito9(Texture2D fala){
     
     DrawTexture(fala,0,570,RAYWHITE);
     DrawText("CONFLITO: Você está com medo de ficar preso.",220,630,20,WHITE);
     DrawText("[PRESS A] Vou fazer exercício de respiração\n[PRESS B] Acho que vou morrer!",220,680,20,WHITE);
     
}
void batalhafuncao(int* ruim,int opc, int* batalha){
   if(opc == 1)
   {
       if(IsKeyPressed(KEY_A)) //A=ruim, B=bom;
       {
           (*ruim)++;
           (*batalha)++;
       }
       else if(IsKeyPressed(KEY_B))
       {
           (*ruim)--;
           (*batalha)++;
       }
   }
   else if(opc == 2)
   {
       if(IsKeyPressed(KEY_A)) //A=bom, B=ruim;
       {
           (*ruim)--;
           (*batalha)++;
       }
       else if(IsKeyPressed(KEY_B))
       {
           (*ruim)++;
           (*batalha)++;
       }
       
   }
}
void batalhafuncao2(Texture2D fala,int* ruim, int* batalha,int* falac){
     (*falac)=1;
      if((*batalha)==1)
      {
          desenharconflito(fala);
          batalhafuncao(&(*ruim),1,&(*batalha)); 
          
      }
      else if((*batalha)==2)
      {
          desenharconflito2(fala);
          batalhafuncao(&(*ruim),2,&(*batalha));
          
      }    
      else if((*batalha)==3)
      {
        desenharconflito3(fala);
        batalhafuncao(&(*ruim),2,&(*batalha));
      } 
      else if((*batalha)==4)
      {
        (*batalha)=0;
      }          
        
       
        
}
void batalhafuncao3(Texture2D fala,int* ruim, int* batalha,int* falac){
      (*falac)=1;
      if((*batalha)==1)
      {
          desenharconflito4(fala);
          batalhafuncao(&(*ruim),2,&(*batalha)); 
          
      }
      else if((*batalha)==2)
      {
          desenharconflito5(fala);
          batalhafuncao(&(*ruim),1,&(*batalha));
          
      }    
      else if((*batalha)==3)
      {
        desenharconflito6(fala);
        batalhafuncao(&(*ruim),2,&(*batalha));
      } 
      else if((*batalha)==4)
      {
        (*batalha)=0;
      }              
        
}
void batalhafuncao4(Texture2D fala,int* ruim, int* batalha,int* falac){
      (*falac=1);
      if((*batalha)==1)
      {
          desenharconflito7(fala);
          batalhafuncao(&(*ruim),1,&(*batalha)); 
          
      }
      else if((*batalha)==2)
      {
          desenharconflito8(fala);
          batalhafuncao(&(*ruim),1,&(*batalha));
          
      }    
      else if((*batalha)==3)
      {
        desenharconflito9(fala);
        batalhafuncao(&(*ruim),2,&(*batalha));
      } 
      else if((*batalha)==4)
      {
        (*batalha)=0;
      }                
}
void atualizarestabilidade(int* stress,int* estabilidade){
       if((*stress)>= 10)
    {
        (*estabilidade) = *estabilidade-2;
        (*stress)=5;
    }
    if((*stress) == 0)
    {
        (*estabilidade) = *estabilidade+2;
        (*stress)=5;
    }else
    if((*stress) == -1){
        (*estabilidade) = *estabilidade+2;
        (*stress) = 4;
    }else
    if((*stress) == -2){
        (*estabilidade) = *estabilidade+2;
        (*stress) = 3;
    }else
    if((*stress) == -3){
        (*estabilidade) = *estabilidade+2;
        (*stress) = 2;
    }else
    if((*stress) <= -3){
        (*estabilidade) = *estabilidade+2;
        (*stress) = 2;
    }
    
}
void diversaoaviso(Texture2D fala,int* falac, Rectangle* Jorger, Rectangle falacolisao){
     (*falac)=1;
     /*int contador = 0;
     contador++;
     int segundos = 0;
     if(contador%60 == 0)
     {
         segundos++;
     }*/
     DrawTexture(fala,0,570,RAYWHITE);
     if((Jorger->x >= falacolisao.x) && (Jorger->y >= falacolisao.y))
     {
         Jorger->y = 525;
     }
     DrawText("Está na hora de Jorge se divertir",370,700,20,WHITE);  
     
}
void terapiaaviso(Texture2D fala,int* falac, Rectangle* Jorger, Rectangle falacolisao){
     (*falac)=1;
     
     DrawTexture(fala,0,570,RAYWHITE);
     if((Jorger->x >= falacolisao.x) && (Jorger->y >= falacolisao.y))
     {
         Jorger->y = 525;
     }
     DrawText("Está na hora de Jorge ir à terapia",210,660,20,WHITE);
     
}
void tudoDoJorge(){
    
    int screenWidth = 1366; //dimensão da minha tela
    int screenHeight = 768;
    
    int contadordetempo = 0;
    
    //Carregando imagem e transformando em textura:
    //Image:
        Image Quarto = LoadImage("/jogoip/Quarto002.png"); //diretorio apartir do C: com as \ invertidas (/);
        Image Jorgeim = LoadImage("/jogoip/Jorge01.png");
        Image memoriasim = LoadImage("/jogoip/memorias.png");
        Image monstro = LoadImage("/jogoip/monstro2.png");
        Image fala = LoadImage("/jogoip/fala.png");
        Image tutorialim = LoadImage("/jogoip/tutorial.png");
        Image info1 = LoadImage("/jogoip/panico.png");
     //Image Resize:
        ImageResize (&Jorgeim,144,104); //144,104,(108,78) - Aumentando a imagem original
        ImageResize (&Quarto,1366,788); //passar o endereço pq ele modifica a imagem original.
        ImageResize (&fala,1366,300);
        ImageResize (&monstro,1300,678);
        ImageResize (&tutorialim,1366,788);
     //Texture2D:
        Texture2D Quartotx = LoadTextureFromImage(Quarto);
        Texture2D Jorgetx = LoadTextureFromImage(Jorgeim);
        Texture2D memoriastx = LoadTextureFromImage(memoriasim);
        Texture2D falatx = LoadTextureFromImage(fala);
        Texture2D monstrotx = LoadTextureFromImage(monstro);
        Texture2D estabilidadetx = LoadTexture("/jogoip/estabilidade.png");
        Texture2D estressetx = LoadTexture("/jogoip/estresse.png");
        Texture2D tutorialtx = LoadTextureFromImage(tutorialim);
        Texture2D info1tx = LoadTextureFromImage(info1);
     //Rectengles:
        Rectangle Jorgerec = {0,0,53,102};// testando o tamanho do boneco no mapa (pegando só esse retângulo)
        //Rectangle Karolrec = {0,0,55,102}; // Esta ok
        //Rectangle Guilhermerec = {0,0,55,102}; //se desejar aumentar manter a proporção para os 3 bonecos (usar multiplo)
       //Retângulo de movimentação:
        Rectangle Jorger = {17,400,53,51}; //um retângulo de colisão que representa Jorge (metade da altura para colidir com o pé)
       //criando colisão
        Rectangle estante = {330,116,979,180}; //colisão para a estante
        Rectangle memoria1 = {500,325,20,3};
        Rectangle memoria2 = {600,325,20,3};
        Rectangle memoria3 = {600,525,20,5};
        Rectangle memoria4 = {965,340,20,3};
        Rectangle memoria5 = {1025,560,30,5};
        Rectangle memoria6 = {130,520,30,5}; 
        Rectangle memoria7 = {700,325,20,3};
        Rectangle memoria8 = {400,500,20,3};
        Rectangle memoria9 = {1050,450,20,3};
        Rectangle memoria10 = {1025,443,20,3};
        Rectangle memoria11 = {1000,443,20,3};
        Rectangle memoriasad1 = {800,600,20,5};
        Rectangle memoriasad2 = {255,380,20,5};
        Rectangle memoriasad3 = {1270,540,20,5};
        Rectangle memoriasad4 = {400,440,20,5};
        Rectangle memoriasad5 = {1125,400,20,5};
        Rectangle conflito = {930,300,70,80};
        Rectangle conflito2 = {995,400,70,80};
        Rectangle conflito3 = {1030,400,70,80};
        Rectangle mesa = {525,405,305,100};
        Rectangle pe1= {570,515,20,15};
        Rectangle pe2= {790,515,20,15};
        Rectangle lixo = {1070,304,113,20};
        Rectangle parede1 = {0,0,190,340};
        Rectangle parede2 = {1166,0,190,340};
        Rectangle parede3 = {221,304,55,20};
        Rectangle parede4 = {0,669,190,340};
        Rectangle parede5 = {1166,669,190,340};
        Rectangle latInfEsq = {0,672,230,768};
        Rectangle latInfEsq2 ={0,700,300,768};
        Rectangle latInfDir ={1060,678,1366,768}; 
        //Rectangle p1 = {};
        //Rectangle p2 = {};
        //Rectangle p3 = {};
        Rectangle falacolisao = {0,630,1300,300};
        Rectangle refletirec = {640,400,60,15};
        
        
        //recorte de imagem:
        Rectangle memoriasrec = {0,0,30,20}; //ok!
        Rectangle memoriassadrec = {30,20,30,20}; //ok!
        Rectangle conflitorec = {60,40,35,20};
        Rectangle monstrorec = {0,0,90,90};
        
       
        
        
       //posição das memórias:
        Vector2 memoriasp = {500,325}; //ferias com a família
        Vector2 memoriasp2 = {600,325}; //ganhou um ps4
        Vector2 memoriasp3 = {600,525}; //passou de ano
        Vector2 memoriasp5 = {130,520}; //conseguiu vencer algum medo 
        Vector2 memoriasp6 = {1025,560}; //fez uma nova amizade
        Vector2 memoriaspsad1 = {800,600}; //perdeu contato com um amigo querido
        Vector2 memoriasp4 = {965,340};
        Vector2 memoriap10 = {1025,443};
        Vector2 memoriap11 = {1000,443};
        Vector2 memoriaspsad2 = {255,380}; //morte de um familiar
        Vector2 memoriaspsad3 = {1270,540}; //teve uma crise de pânico em público 
        Vector2 conflitop = {900,300};
        Vector2 conflitop2 = {965,400};
        Vector2 conflitop3 = {1000,400};
        Vector2 memoriaspsad4 = {400,440};
        Vector2 memoriaspsad5 = {1125,400};
        Vector2 memoriasp7 = {700,325};
        Vector2 memoriasp8 = {395,500};
        Vector2 memoriasp9 = {1045,450};
        
         
        
    //variáveis :
    int memoria = 0;
    int stress = 5; //chegando a 0 aumenta estabilidade, chegando a 10 diminui.
    int estabilidade = 10; //chegando a 30 (exemplo) passa de nível, chegando a 0 perde
    int sad = 0; 
    int desafio = 0;
    int batalha = -1;
    int batalha2= -1;
    int batalha3= -1;
    int ruim = 0;
    int ruim2=0;
    int ruim3=0;
    int desenhar = 1;
    int diversao = 0;
    int terapia = 0;
    int falac=0;
    int checkpoint = 0;
    int refletir=0;
    checkpoint = qual_level(0);
    int desenharmemoria[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    //Musica do jogo:
    Music ewof = LoadMusicStream("/jogoip/Ewof.ogg");
    PlayMusicStream(ewof);
    SetMusicVolume(ewof, 0.2);
    
    while (!WindowShouldClose())   
    { 
       UpdateMusicStream(ewof); 
    
        //CONDIÇÃO PARA SUBIR DE NIVEL
        if(estabilidade >= 30){
            subiu_de_level();
            menu();
        }
        //Condição do game over
        if(estabilidade <= 0 ){
            menu();
        }
        
         contadordetempo++;
         Vector2 Jorgep = {Jorger.x,Jorger.y-51}; //posição do Jorge (menos 51 para a colisão ficar no pé)
         //Posição do mouse na tela
         int x = GetMouseX();
         int y = GetMouseY();
        //colisão especifica 
          /*circulo jogador;
          circulo parede6;
          circulo parede7;
          jogador.raio= 25;
          jogador.x=Jorger.x;
          jogador.y=Jorger.y;
          parede6.raio=35;
          parede7.raio=35;
          parede6.x= 35;
          parede6.y=705; */
        //função de movimentação do jorge:
        if(desafio==0)
        {
            movimentacao(&Jorger);
        }
         
        //Checando se saiu do mapa:
        tamanhotela(&Jorger,screenHeight,screenWidth);
        //atualizando estabilidade:
        atualizarestabilidade(&stress,&estabilidade);
        
        //checando colisão:
       //int distancia = sqrt(((jogador.x - parede6.x)^2) + ((jogador.y - parede6.y)^2)); 
        
       // if(parede6.raio + jogador.raio < distancia)
        {
            //colisao(&Jorger);
        }
        if(CheckCollisionRecs(Jorger,estante)==1)
        {
            Jorger.y+=4;
            if(memoria==1 && IsKeyPressed(KEY_ENTER)==1)
            {
                if(sad==0)
                {
                    stress = stress-2;
                }
                else
                {
                    stress = stress+2;
                    sad=0;
                }
                
                memoria=0;
            }
        }
        
        else if(CheckCollisionRecs(Jorger,mesa)==1 ||CheckCollisionRecs(Jorger,pe1)==1|| CheckCollisionRecs(Jorger,pe2)==1)
        {
            colisao(&Jorger);
        }
        else if(CheckCollisionRecs(Jorger,parede1)==1) 
        {
            colisao(&Jorger);
            if(diversao==1)
            {
                
                desenhar=0;
                stress = stress - 5;
                diversao=0;
            }
            
        }else if(CheckCollisionRecs(Jorger,latInfEsq)==1 || CheckCollisionRecs(Jorger,latInfEsq2)==1|| CheckCollisionRecs(Jorger,latInfDir)==1){
            colisao(&Jorger);
        }
        else if(CheckCollisionRecs(Jorger,parede2)==1)
        {
            colisao(&Jorger);
            if(terapia==1)
            {
                desenhar=0;
                estabilidade = estabilidade + 5;
                terapia=0;
            }
            
        }
        else if(CheckCollisionRecs(Jorger,parede3))
        {
            colisao(&Jorger); 
        }
        else if(CheckCollisionRecs(Jorger,falacolisao))
        {
            if(falac==1)
            {
                colisao(&Jorger); 
                falac=0;
            }
               
        }
        else if(CheckCollisionRecs(Jorger,parede4)) 
        {
            colisao(&Jorger);  
        }
        else if(CheckCollisionRecs(Jorger,parede5))
        {
           colisao(&Jorger);  
        }
        else if(CheckCollisionRecs(Jorger,memoria1)==1)
        {
            if(IsKeyPressed(KEY_ENTER)==1 && memoria==0)
            {
                 desenharmemoria[0]=0;
                 memoria=1;
                 memoria1.x=0;
                 memoria1.y=0;
            }
            
            colisao(&Jorger);
        }
        else if(CheckCollisionRecs(Jorger,memoria2)==1)
        {
            if(IsKeyPressed(KEY_ENTER)==1 && memoria==0)
            {
                 desenharmemoria[1]=0;
                 memoria=1;
                 memoria2.x=0;
                 memoria2.y=0;
            }
            colisao(&Jorger);
        }
        else if(CheckCollisionRecs(Jorger,memoria3))
        {
            if(IsKeyDown(KEY_ENTER)==1 && memoria==0)
            {
                 desenharmemoria[2]=0;
                 memoria=1;
                 memoria3.x=0;
                 memoria3.y=0;
            }
            colisao(&Jorger);
        }
        else if(CheckCollisionRecs(Jorger,memoria4) && contadordetempo>=3600)
        {
            if(IsKeyDown(KEY_ENTER)==1 && memoria==0)
            {
                 desenharmemoria[5]=0;
                 if(ruim>0)
                 {
                     memoria=1;
                     sad=1;
                     //criou um memória ruim:
                     stress = stress+3;
                     
                 }
                 else
                 {
                     memoria=1;
                     //recompensa por ter dado certo:
                     stress = stress-3;
                 }
                 
                 memoria4.x=0;
                 memoria4.y=0;
            }
            colisao(&Jorger);
        }
        else if(CheckCollisionRecs(Jorger,memoria10) && contadordetempo>=3600*3)
        {
            if(IsKeyDown(KEY_ENTER)==1 && memoria==0)
            {
                 desenharmemoria[11]=0;
                 if(ruim2>0)
                 {
                     memoria=1;
                     sad=1;
                     //criou um memória ruim:
                     stress = stress+3;
                     
                 }
                 else
                 {
                     memoria=1;
                     //recompensa por ter dado certo:
                     stress = stress-3;
                 }
                 
                 memoria10.x=0;
                 memoria10.y=0;
            }
            colisao(&Jorger);
        }
        else if(CheckCollisionRecs(Jorger,memoria11) && contadordetempo>=3600*5)
        {
            if(IsKeyDown(KEY_ENTER)==1 && memoria==0)
            {
                 desenharmemoria[13]=0;
                 if(ruim3>0)
                 {
                     memoria=1;
                     sad=1;
                     //criou um memória ruim:
                     stress = stress+3;
                     
                 }
                 else
                 {
                     memoria=1;
                     //recompensa por ter dado certo:
                     stress = stress-3;
                 }
                 
                 memoria11.x=0;
                 memoria11.y=0;
            }
            colisao(&Jorger);
        }
        else if(CheckCollisionRecs(Jorger,conflito)==1 && contadordetempo>=3600)
        {
            if(IsKeyDown(KEY_ENTER))
            {
                 
                 batalha=1;
                 desafio=1;
                 
                
            }
            colisao(&Jorger);
        }
        else if(CheckCollisionRecs(Jorger,conflito2)==1 && contadordetempo>=3600*3)
        {
            if(IsKeyDown(KEY_ENTER))
            {
                 
                 batalha2=1;
                 desafio=2;  
                
            }
            colisao(&Jorger);
        }
        else if(CheckCollisionRecs(Jorger,conflito3)==1 && contadordetempo>=3600*5)
        {
            if(IsKeyDown(KEY_ENTER))
            {
                 
                 batalha3=1;
                 desafio=3;  
                
            }
            colisao(&Jorger);
        }
        else if(CheckCollisionRecs(Jorger,memoriasad1))
        {
            if(IsKeyDown(KEY_ENTER)==1 && memoria==0)
            {
                 desenharmemoria[3]=0;
                 memoria=1;
                 sad=1;
                 memoriasad1.x=0;
                 memoriasad1.y=0;
            }
            colisao(&Jorger);
        }
        else if(CheckCollisionRecs(Jorger,memoriasad2))
        {
            if(IsKeyDown(KEY_ENTER)==1 && memoria==0)
            {
                 desenharmemoria[7]=0;
                 memoria=1;
                 sad=1;
                 memoriasad2.x=0;
                 memoriasad2.y=0;
            }
            colisao(&Jorger);
        }
        else if(CheckCollisionRecs(Jorger,memoriasad3))
        {
            if(IsKeyDown(KEY_ENTER)==1 && memoria==0)
            {
                 desenharmemoria[8]=0;
                 memoria=1;
                 sad=1;
                 memoriasad3.x=0;
                 memoriasad3.y=0;
            }
            colisao(&Jorger);
        }
        else if(CheckCollisionRecs(Jorger,memoria5))
        {
            if(IsKeyDown(KEY_ENTER)==1 && memoria==0)
            {
                 desenharmemoria[9]=0;
                 memoria=1;
                 memoria5.x=0;
                 memoria5.y=0;
            }
            colisao(&Jorger);
        }
        else if(CheckCollisionRecs(Jorger,memoria6))
        {
            if(IsKeyDown(KEY_ENTER)==1 && memoria==0)
            {
                 desenharmemoria[6]=0;
                 memoria=1;
                 memoria6.x=0;
                 memoria6.y=0;
            }
            colisao(&Jorger);
        }
        else if(CheckCollisionRecs(Jorger,memoria7))
        {
            if(IsKeyDown(KEY_ENTER)==1 && memoria==0)
            {
                 desenharmemoria[15]=0;
                 memoria=1;
                 memoria7.x=0;
                 memoria7.y=0;
            }
            colisao(&Jorger);
        }
        else if(CheckCollisionRecs(Jorger,memoria8))
        {
            if(IsKeyDown(KEY_ENTER)==1 && memoria==0)
            {
                 desenharmemoria[16]=0;
                 memoria=1;
                 memoria8.x=0;
                 memoria8.y=0;
            }
            colisao(&Jorger);
        }
        else if(CheckCollisionRecs(Jorger,memoria9))
        {
            if(IsKeyDown(KEY_ENTER)==1 && memoria==0)
            {
                 desenharmemoria[17]=0;
                 memoria=1;
                 memoria9.x=0;
                 memoria9.y=0;
            }
            colisao(&Jorger);
        }
        else if(CheckCollisionRecs(Jorger,memoriasad4))
        {
            if(IsKeyDown(KEY_ENTER)==1 && memoria==0)
            {
                 desenharmemoria[18]=0;
                 memoria=1;
                 sad=1;
                 memoriasad4.x=0;
                 memoriasad4.y=0;
            }
            colisao(&Jorger);
        }
        else if(CheckCollisionRecs(Jorger,memoriasad5))
        {
            if(IsKeyDown(KEY_ENTER)==1 && memoria==0)
            {
                 desenharmemoria[19]=0;
                 memoria=1;
                 sad=1;
                 memoriasad5.x=0;
                 memoriasad5.y=0;
            }
            colisao(&Jorger);
        }
        else if (CheckCollisionRecs(Jorger,lixo))
        {
           colisao(&Jorger);
           if(IsKeyPressed(KEY_ENTER)==1 && memoria==1)
            {
                if(sad==1)
                {
                    stress--;
                    sad=0;
                }
                else
                {
                    stress = stress+3;
                }
                 memoria=0;
            }
            colisao(&Jorger); 
        }
        else if(CheckCollisionRecs(Jorger,refletirec)==1)
        {
           colisao(&Jorger);
           if(refletir == 1)
            {
               
                if(IsKeyPressed(KEY_ENTER)==1 && memoria==1)
                {                
                    if(sad==1)
                    {
                        stress-=2;
                        memoria=0;
                        sad=0;
                        refletir=0;
                    }
                    else
                    {
                        estabilidade+=1;
                        memoria=0;
                        refletir=0;
                    }
                }
            }
        }

        
            int minutos = 3600;
            if(contadordetempo==2*minutos)
            {
                diversao=1;
                
            }
            if(contadordetempo==4*minutos)
            {
                terapia=1;
                refletir=1;
            }
            if(contadordetempo==6*minutos)
            {
                diversao=1;
                
            }
            if(contadordetempo==8*minutos)
            {
                terapia=1;
                refletir=1;
               
            }
            if(contadordetempo==10*minutos)
            {
                diversao=1;
                
            }
        
        //parte gráfica:
        BeginDrawing();
           ClearBackground(WHITE);
           DrawTexture(Quartotx,0,0,RAYWHITE);
           //DrawTexture(circulo1.posicaox,circulo1.posicaoy,RAYWHITE);
           //DrawTextureRec(Texture2D texture, Rectangle sourceRec, Vector2 position, Color tint); 
           DrawText(TextFormat("x: %i y: %i",x,y),605,15,40,RED);
           if(memoria==1 && sad==1){
                DrawCircle(175,695,12,BLUE);
           }else
               if(memoria == 1 && sad == 0){
                DrawCircle(175,695,12,YELLOW);   
               }
           if(refletir==1){
               DrawCircle(175,728,12,GREEN);
           }
           DrawText(TextFormat("Memoria: "),15,680,35,BLACK);
           DrawTexture(estabilidadetx, 35, 8, WHITE);
           DrawTexture(estressetx, 35, estabilidadetx.height + 16, WHITE);
           DrawRectangleGradientH(39, 36,((estabilidade*0.1)/3)*325, 26, SKYBLUE, DARKBLUE);
           DrawRectangleGradientH(39, 104,(stress*0.1)*325, 25, RED, (Color){123, 20, 34, 255});
           DrawText(TextFormat("Refletir:"),15,710,35,BLACK);
           DrawText(TextFormat("Fase 1"),629,94,35,BLACK);
           DrawText(TextFormat("Tempo: %0.1f", (float)(contadordetempo/100)),1150,42,30,BLACK);
           DrawText(TextFormat("T - Tutorial"),1173,720,24,BLACK);
           DrawText(TextFormat("I - Info"),1173,690,24,BLACK);
           
           //DrawTextureRec(Karoltx,Karolrec,Karolp,RAYWHITE);
           //DrawTextureRec(Guilhermetx,Guilhermerec,Guilhermep,RAYWHITE);
           
           // desenhando memórias:
           if(desenharmemoria[0]==1)
           {
              DrawTextureRec(memoriastx,memoriasrec,memoriasp,RAYWHITE); 
           }
           if(desenharmemoria[1]==1)
           {
              DrawTextureRec(memoriastx,memoriasrec,memoriasp2,RAYWHITE);
           }
           if(desenharmemoria[2]==1)
           {
              DrawTextureRec(memoriastx,memoriasrec,memoriasp3,RAYWHITE);
           }
           if(desenharmemoria[3]==1)
           {
              DrawTextureRec(memoriastx,memoriassadrec,memoriaspsad1,RAYWHITE);
           }
           if(desenharmemoria[4]==1 && contadordetempo >= 3600)
           {
              DrawTextureRec(monstrotx,monstrorec,conflitop,RAYWHITE);
           }
           if(desenharmemoria [9] == 1)
           {
               DrawTextureRec(memoriastx,memoriasrec,memoriasp6,RAYWHITE);
           }
           if(desenharmemoria[6] == 1)
           {
               DrawTextureRec(memoriastx,memoriasrec,memoriasp5,RAYWHITE);
           }
           if(desenharmemoria[7] == 1)
           {
               DrawTextureRec(memoriastx,memoriassadrec,memoriaspsad2,RAYWHITE);
           }
           if(desenharmemoria[8] == 1)
           {
               DrawTextureRec(memoriastx,memoriassadrec,memoriaspsad3,RAYWHITE);
           }
           if(desenharmemoria[10] == 1 && contadordetempo >= 3600*3)
           {
               DrawTextureRec(monstrotx,monstrorec,conflitop2,RAYWHITE);
           }
           if(desenharmemoria[12] == 1 && contadordetempo >= 3600*5)
           {
               DrawTextureRec(monstrotx,monstrorec,conflitop3,RAYWHITE);
           }
           if(desenharmemoria[15] == 1)
           {
               DrawTextureRec(memoriastx,memoriasrec,memoriasp7,RAYWHITE);
           }
           if(desenharmemoria[16] == 1)
           {
               DrawTextureRec(memoriastx,memoriasrec,memoriasp8,RAYWHITE);
           }
           if(desenharmemoria[17] == 1)
           {
               DrawTextureRec(memoriastx,memoriasrec,memoriasp9,RAYWHITE);
           }
           if(desenharmemoria[18] == 1)
           {
               DrawTextureRec(memoriastx,memoriassadrec,memoriaspsad4,RAYWHITE);
           }
           if(desenharmemoria[19] == 1)
           {
               DrawTextureRec(memoriastx,memoriassadrec,memoriaspsad5,RAYWHITE);
           }
           //desenhando desafio:
           if(desafio==1)
           {
               
               if(batalha>=1)
               {
                   batalhafuncao2(falatx,&ruim,&batalha,&falac);
                   
               }
               if(batalha==0)
               {
                   desenharmemoria[4]=0;
                   desafio=0;
                   conflito.x=0;
                   conflito.y=0;
                   
               }
               
               
           }
           if(batalha==0 && ruim<0)
            {
                   if(desenharmemoria[5]==1)
                   {
                      DrawTextureRec(memoriastx,memoriasrec,memoriasp4,RAYWHITE); 
                   }
                  
                 
            }    
            else if(batalha==0 && ruim>0)
            {
                   if(desenharmemoria[5]==1)
                   {
                      DrawTextureRec(memoriastx,memoriassadrec,memoriasp4,RAYWHITE);
                   }
                   
            }
            if(desafio==2)
           {
               
               if(batalha2>=1)
               {
                   batalhafuncao3(falatx,&ruim2,&batalha2,&falac);
                   
               }
               if(batalha2==0)
               {
                   desenharmemoria[10]=0;
                   desafio=0;
                   conflito2.x=0;
                   conflito2.y=0;
                   
               }
               
               
           }
           if(batalha2==0 && ruim2<0)
            {
                   if(desenharmemoria[11]==1)
                   {
                      DrawTextureRec(memoriastx,memoriasrec,memoriap10,RAYWHITE); 
                   }
                  
                 
            }    
            else if(batalha2==0 && ruim2>0)
            {
                   if(desenharmemoria[11]==1)
                   {
                      DrawTextureRec(memoriastx,memoriassadrec,memoriap10,RAYWHITE);
                   }
                   
            }
            if(desafio==3)
           {
               
               if(batalha3>=1)
               {
                   batalhafuncao4(falatx,&ruim3,&batalha3,&falac);
                   
               }
               if(batalha3==0)
               {
                   desenharmemoria[12]=0;
                   desafio=0;
                   conflito3.x=0;
                   conflito3.y=0;
                   
               }
               
               
           }
           if(batalha3==0 && ruim3<0)
            {
                   if(desenharmemoria[13]==1)
                   {
                      DrawTextureRec(memoriastx,memoriasrec,memoriap11,RAYWHITE); 
                   }
                  
                 
            }    
            else if(batalha3==0 && ruim3>0)
            {
                   if(desenharmemoria[13]==1)
                   {
                      DrawTextureRec(memoriastx,memoriassadrec,memoriap11,RAYWHITE);
                   }
                   
            }
           //diversao e terapia:
           if(diversao==1 && desafio==0)
           {
               diversaoaviso(falatx, &falac, &Jorger, falacolisao);
           }
           if(terapia==1 && desafio==0)
           {
               terapiaaviso(falatx, &falac, &Jorger, falacolisao);
           }
           int espera = 1000; //modificar essa variável para reduzir o tempo de espera
           if(contadordetempo>=(2*minutos)+espera && contadordetempo<(4*minutos)) 
           {
               desenhar=1;
           }
           if(contadordetempo>=(4*minutos)+espera && contadordetempo<(6*minutos))
           {
               desenhar=1;
           }
           if(contadordetempo>=(6*minutos)+espera && contadordetempo<(8*minutos))
           {
               desenhar=1;
           }
           if(contadordetempo>=(8*minutos)+espera && contadordetempo<(10*minutos))
           {
               desenhar=1;
           }
           if(contadordetempo>=(10*minutos)+espera)
           {
               desenhar=1;
           }
           if(desenhar==1)
           {
               DrawTextureRec(Jorgetx,Jorgerec,Jorgep,RAYWHITE);
           }
           if(estabilidade >= 30)
           {
               subiu_de_level();
           }

           if (IsKeyDown(KEY_T)){
               DrawTexture(tutorialtx,0,0,RAYWHITE);
           }
           
           if(IsKeyDown(KEY_I))
           {
               DrawTexture(info1tx,340,256,RAYWHITE); 
           }
        EndDrawing();
    }
    CloseWindow();
}

//FASE 2

void movimentacaoK(Rectangle* Karolr){
        if (IsKeyDown(KEY_DOWN))
        {
            (Karolr->y)+= 4; //y cresce para baixo.
        }
        else if(IsKeyDown(KEY_UP))
        {
            (Karolr->y) -= 4;
        }
        else if(IsKeyDown(KEY_RIGHT))
        {
            (Karolr->x) +=4;
        }
        else if(IsKeyDown(KEY_LEFT))
        {
            (Karolr->x) -=4;
        }
            
    
}
void colisaoK(Rectangle* Karolr){ 
           if(IsKeyDown(KEY_LEFT))
           
           {
               (Karolr->x)+=4;
               
           }
           if(IsKeyDown(KEY_RIGHT))
           {
               (Karolr->x)-=4;
               
           }
           if(IsKeyDown(KEY_UP))
           {
               (Karolr->y)+=4;
           }
           if(IsKeyDown(KEY_DOWN))
           {
               (Karolr->y)-=4;
               
           } 
    
}
void tamanhotelaK(Rectangle* Karolr, int screenHeight,int screenWidth){
        if(Karolr->x+53>screenWidth)
        {
            Karolr->x = screenWidth-53;
        }
        else if(Karolr->x-8<0) 
        {
            Karolr->x=0+8;
        }
        else if(Karolr->y+52>screenHeight)
        {
            Karolr->y=screenHeight-52;
        }
        else if(Karolr->y-10<0)
        {
           Karolr->y=0+10;
        }
}
void diversaoavisoK(Texture2D fala,int* falac, Rectangle* Karolr, Rectangle falacolisao){
     (*falac)=1;
     DrawTexture(fala,237,650,RAYWHITE);
     if((Karolr->x >= falacolisao.x) && (Karolr->y >= falacolisao.y))
     {
         Karolr->y = 525;
     }
     DrawText("Está na hora de Karol se divertir",450,720,20,WHITE);  
     
}
void terapiaavisoK(Texture2D fala,int* falac, Rectangle* Karolr, Rectangle falacolisao){
     (*falac)=1;
     DrawTexture(fala,237,650,RAYWHITE);
     if((Karolr->x >= falacolisao.x) && (Karolr->y >= falacolisao.y))
     {
         Karolr->y = 525;
     }
     DrawText("Está na hora de Karol ir para a terapia",450,720,20,WHITE);  
     
}
void remedioavisoK(Texture2D fala,int* falac, Rectangle* Karolr, Rectangle falacolisao){
     (*falac)=1;
     DrawTexture(fala,237,650,RAYWHITE);
     if((Karolr->x >= falacolisao.x) && (Karolr->y >= falacolisao.y))
     {
         Karolr->y = 525;
     }
     DrawText("Está na hora de Karol tomar seu remedio",450,720,20,WHITE);  
     
}
void desafiofuncaoK(Texture2D fala, int* ruim,int* falac,int opc){
    (*falac)=1;
    if((*ruim)==1)
    {
        if(opc==1)
        {
            DrawTexture(fala,237,650,RAYWHITE);
            DrawText("Você tem certeza que esse dia foi bom?",450,720,20,RED);  
        }
        else if(opc==2)
        {
           DrawTexture(fala,237,650,RAYWHITE);
           DrawText("Você acha que essa nota foi merecida?",450,720,20,RED);   
        }
        else if(opc==3)
        {
            DrawTexture(fala,237,650,RAYWHITE);
            DrawText("Você não deveria ter saido de casa",450,720,20,RED); 
        }
        else if(opc>=4)
        {
            DrawTexture(fala,237,650,RAYWHITE);
            DrawText("Não tente fazer nada!",450,720,20,RED); 
        }
        
    }
    if((*ruim)==2)
    {
        if(opc==1)
        {
            DrawTexture(fala,237,650,RAYWHITE);
            DrawText("Tem certeza que não fez nada de errado?",450,720,20,RED); 
        }
        else if(opc==2)
        {
            DrawTexture(fala,237,650,RAYWHITE);
            DrawText("Você teve sorte",450,720,20,RED); 
        }
        else if(opc==3)
        {
            DrawTexture(fala,237,650,RAYWHITE);
            DrawText("Só atrapalhou o dia de todo mundo",450,720,20,RED);  
        }
        else if(opc>=4)
        {
            DrawTexture(fala,237,650,RAYWHITE);
            DrawText("Pare!",450,720,20,RED); 
        }
         
    }
    if((*ruim)==3)
    {
        if(opc==1)
        {
            DrawTexture(fala,237,650,RAYWHITE);
            DrawText("Pense de novo",450,720,20,RED); 
        }
        else if(opc==2)
        {
            DrawTexture(fala,237,650,RAYWHITE);
            DrawText("Tudo que conseguiu foi por sorte",450,720,20,RED); 
        }
        else if(opc==3)
        {
            DrawTexture(fala,237,650,RAYWHITE);
            DrawText("Você sempre atrapalha tudo",450,720,20,RED);  
        }
        else if(opc>=4)
        {
            DrawTexture(fala,237,650,RAYWHITE);
            DrawText("Pense nas vezes que deu errado!",450,720,20,RED); 
        }
    }
    if((*ruim)==4)
    {
        if(opc==1)
        {
            DrawTexture(fala,237,650,RAYWHITE);
            DrawText("Você sempre faz algo de errado",450,720,20,RED);
        }
        else if(opc==2)
        {
            DrawTexture(fala,237,650,RAYWHITE);
            DrawText("Se tentar de novo não vai conseguir",450,720,20,RED); 
        }
        else if(opc==3)
        {
            DrawTexture(fala,237,650,RAYWHITE);
            DrawText("Eles não queriam você lá",450,720,20,RED);  
        }
        else if(opc>=4)
        {
            DrawTexture(fala,237,650,RAYWHITE);
            DrawText("Vai dar errado!",450,720,20,RED); 
        }
        
    }
    if((*ruim)==5)
    {
        DrawTexture(fala,237,650,RAYWHITE);
        DrawText("Você sempre estraga tudo",450,720,20,RED);
    }
    if((*ruim)==6)
    {
        if(opc==1)
        {
            DrawTexture(fala,237,650,RAYWHITE);
            DrawText("Pense! Pense!",500,720,20,RED);
        }
        else if(opc==2)
        {
            DrawTexture(fala,237,650,RAYWHITE);
            DrawText("Esse aperto no peito não vai embora",450,720,20,RED); 
        }
        else if(opc==3)
        {
            DrawTexture(fala,237,650,RAYWHITE);
            DrawText("Algo de ruim vai acontecer",450,720,20,RED);  
        }
        else if(opc>=4)
        {
            DrawTexture(fala,237,650,RAYWHITE);
            DrawText("Não tente! Você vai falhar",450,720,20,RED); 
        }
        
    }
    if((*ruim)==7)
    {
       if(opc==1)
        {
            DrawTexture(fala,237,650,RAYWHITE);
            DrawText("Há algo que você não está lembrando",450,720,20,RED);
        }
        else if(opc==2)
        {
            DrawTexture(fala,237,650,RAYWHITE);
            DrawText("Você não consegue se controlar!",450,720,20,RED); 
        }
        else if(opc==3)
        {
            DrawTexture(fala,237,650,RAYWHITE);
            DrawText("Você deveria sumir",450,720,20,RED);  
        }
        else if(opc>=4)
        {
            DrawTexture(fala,237,650,RAYWHITE);
            DrawText("Pense nisso!Pense de novo!",450,720,20,RED); 
        }
        
    }
           
}
void tudoDaKarol(){
    
    int screenWidth = 1366; //dimenssão da minha tela
    int screenHeight = 768;
    
    int contadordetempo = 0;
    
    //Carregando imagem e transformando em textura:
    //Image:
        Image Quarto = LoadImage("/jogoip/Quarto002.png"); //diretorio apartir do C: com as \ invertidas (/);
        Image Jorgeim = LoadImage("/jogoip/Jorge01.png");
        Image memoriasim = LoadImage("/jogoip/memorias.png");
        Image monstro = LoadImage("/jogoip/monstro2.png");
        Image fala = LoadImage("/jogoip/fala.png");
        Image Karolim = LoadImage("/jogoip/Karol01.png");
        Image desafioim = LoadImage("/jogoip/aviao.png");
        Image info2 = LoadImage("/jogoip/ansiedade.png");

     //Image Resize:
        //ImageResize (&Jorgeim,144,104); //144,104,(108,78) - Aumentando a imagem original
        ImageResize (&Karolim,144,104);
        ImageResize (&Quarto,1366,788); //passar o endereço pq ele modifica a imagem original.
        ImageResize (&fala,900,200);
        ImageResize (&monstro,1300,678);
        ImageResize (&desafioim,96,102);
     //Texture2D:
        Texture2D Quartotx = LoadTextureFromImage(Quarto);
        //Texture2D Jorgetx = LoadTextureFromImage(Jorgeim);
        Texture2D Karoltx = LoadTextureFromImage(Karolim);
        Texture2D memoriastx = LoadTextureFromImage(memoriasim);
        Texture2D falatx = LoadTextureFromImage(fala);
        Texture2D desafiotx = LoadTextureFromImage(desafioim);
        Texture2D estabilidadetx = LoadTexture("/jogoip/estabilidade.png");
        Texture2D estressetx = LoadTexture("/jogoip/estresse.png");
        Image Remedio = LoadImage("/jogoip/Remedio.png");
        Texture2D remediotx = LoadTextureFromImage(Remedio);
        Texture2D info2tx = LoadTextureFromImage(info2);
        //Tutorial:
        Image tutorialim = LoadImage("/jogoip/tutorial.png");
        ImageResize (&tutorialim,1366,788);
        Texture2D tutorialtx = LoadTextureFromImage(tutorialim);

     //Rectengles:
        //Rectangle Jorgerec = {0,0,53,102};// testando o tamanho do boneco no mapa (pegando só esse retângulo)
        Rectangle Karolrec = {0,0,55,102}; // Esta ok
        //Rectangle Guilhermerec = {0,0,55,102}; //se desejar aumentar manter a proporção para os 3 bonecos (usar multiplo)
       //Retângulo de movimentação:
        //Rectangle Jorger = {17,400,53,51}; //um retângulo de colisão que representa Jorge (metade da altura para colidir com o pé)
         Rectangle Karolr = {17,400,55,51};
       //criando colisão
        Rectangle estante = {330,116,979,180}; //colisão para a estante
        Rectangle memoria1 = {290,400,10,3};
        Rectangle memoria2 = {440,670,10,3};
        Rectangle memoria3 = {1176,525,10,3};
        Rectangle memoria4 = {1075,400,10,3};
        Rectangle memoria5 = {300,350,10,3};
        Rectangle memoria6 = {600,350,10,3};
        Rectangle memoria7 = {1075,650,10,3};
        Rectangle memoriasad1 = {810,600,10,3};
        Rectangle memoriasad2 = {850,380,10,3};
        Rectangle memoriasad3 = {115,590,10,3};
        
        //colis[0] impar
        Rectangle conflito = {940,330,20,10};
        Rectangle conflito2 = {940,530,20,10};
        Rectangle conflito3 = {240,530,20,10};
        Rectangle conflito4 = {440,330,20,10};
        Rectangle conflito5 = {830,625,20,10};
        Rectangle conflito6 = {340,530,20,10};
        Rectangle conflito7 = {640,590,20,10};
        //colis[0] par
        Rectangle conflito1par = {990,380,20,10};
        Rectangle conflito2par = {365,450,20,10};
        Rectangle conflito3par = {260,410,20,10};
        Rectangle conflito4par = {1310,560,20,10};
        Rectangle conflito5par = {950,580,20,10};
        Rectangle conflito6par = {780,600,20,10};
        Rectangle conflito7par = {640,590,20,10};        
        
        Rectangle mesa = {525,405,305,100};
        Rectangle pe1= {570,515,20,15};
        Rectangle pe2= {790,515,20,15};
        Rectangle lixo = {1070,304,113,20};
        Rectangle parede1 = {0,0,190,340};
        Rectangle parede2 = {1166,0,190,340};
        Rectangle parede3 = {221,304,55,20};
        Rectangle parede4 = {0,669,190,340};
        Rectangle parede5 = {1166,669,190,340};
        Rectangle falacolisao = {330,695,800,150};
        //Rec do conflito do remedio
        Rectangle remedior = {750,401,5,5};
        //Rec do conflito do refletir
        Rectangle refletirec = {639,401,60,15};
         
        Rectangle memoriasrec = {0,0,30,20}; //ok!
        Rectangle memoriassadrec = {30,20,30,20}; //ok!
        
       //posição das memórias:
        Vector2 memoriasp = {288,400}; //ferias com a família
        Vector2 memoriasp2 = {430,670}; //ganhou um ps4
        Vector2 memoriasp3 = {1166,525}; //passou de ano
        Vector2 memoriasp4 = {1065,400};
        Vector2 memoriasp5 = {300,350};
        Vector2 memoriasp6 = {600,350};
        Vector2 memoriasp7 = {1075,650};
        Vector2 memoriaspsad1 = {800,600}; //perdeu contato com um amigo querido
        Vector2 memoriaspsad2 = {850,380};
        Vector2 memoriaspsad3 = {115,590};
        Rectangle latInfEsq = {0,672,230,768};
        Rectangle latInfEsq2 ={0,700,300,768};
        Rectangle latInfDir ={1060,678,1366,768}; 
       
        
    //variáveis :
    int memoria = 0;
    int stress = 5; //chegando a 0 aumenta estabilidade, chegando a 10 diminui.
    int estabilidade = 10; //chegando a 30 (exemplo) passa de nível, chegando a 0 perde
    int sad = 0; 
    int desafio = 0;
    int batalha = -1;
    int ruim = 0;
    int desenhar = 1;
    int diversao = 0;
    int terapia = 0;
    int refletir=0;
    int remedio=0;
    int falac=0;
    float contar=0.0;
    int desenharmemoria[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int colis[8] = {1,0,0,0,0,0,0,0};
    int checkpoint = 0;
    checkpoint = qual_level(0);
    //Musica da fase:
    Music memory = LoadMusicStream("/jogoip/Memory.ogg");
    PlayMusicStream(memory);
    refletir = 1;
    while (!WindowShouldClose())   
    { 
        UpdateMusicStream (memory); 
        
        if(estabilidade >= 30){
            subiu_de_level();
            menu();
        }
        
        if(estabilidade <= 0){
            main();
        }
        
         contadordetempo++;
         //Vector2 Jorgep = {Jorger.x,Jorger.y-51}; //posição do Jorge (menos 51 para a colisão ficar no pé)
         Vector2 Karolp = {Karolr.x,Karolr.y-51};
         //Posição do mouse na tela
         int x = GetMouseX();
         int y = GetMouseY();
        
        //função de movimentação do jorge:
         movimentacaoK(&Karolr);
        //Checando se saiu do mapa:
        tamanhotelaK(&Karolr,screenHeight,screenWidth);
        //atualizando estabilidade:
        atualizarestabilidade(&stress,&estabilidade);
        
        //checando colisão:
        if(CheckCollisionRecs(Karolr,estante)==1)
        {
            Karolr.y+=4;
            
            if(memoria==1 && IsKeyPressed(KEY_ENTER)==1)
            {
                if(ruim>=3)
                {
                  sad=1;
                }
                if(sad==0)
                {
                    stress = stress-2;
                }
                else
                {
                    stress = stress+2;
                    sad=0;
                }
                
                memoria=0;
                ruim=0;
                for(int i=1;i<8;i++)
                {
                    colis[i]=0;
                }
                colis[0]= colis[0]+1;
            }
        }else 
            if(CheckCollisionRecs(Karolr,mesa)==1 ||CheckCollisionRecs(Karolr,pe1)==1|| CheckCollisionRecs(Karolr,pe2)==1)
            {
                colisaoK(&Karolr);
                
            }else
                if(CheckCollisionRecs(Karolr,latInfEsq)==1 || CheckCollisionRecs(Karolr,latInfEsq2)==1|| CheckCollisionRecs(Karolr,latInfDir)==1)
                {
                    colisaoK(&Karolr);
                }else 
                    if(CheckCollisionRecs(Karolr,parede1)==1) 
                    {
                        colisaoK(&Karolr);
                        if(diversao==1)
                        {
                            
                            desenhar=0;
                            stress = stress - 5;
                            diversao=0;
                        }
            
                    }else 
                        if(CheckCollisionRecs(Karolr,parede2)==1)
                        {
                            colisaoK(&Karolr);
                            if(terapia==1)
                            {
                                desenhar=0;
                                estabilidade = estabilidade + 5;
                                terapia=0;
                            }                    
                        }else 
                            if(CheckCollisionRecs(Karolr,remedior)==1)
                            {
                                colisaoK(&Karolr);
                                if(remedio==1)
                                {
                                    //desenhar=2;
                                    estabilidade = estabilidade + 5;
                                    remedio=0;
                                }
                                
                            }else 
                                if(CheckCollisionRecs(Karolr,parede3))
                                {
                                    colisaoK(&Karolr); 
                                }else 
                                    if(CheckCollisionRecs(Karolr,parede4) || CheckCollisionRecs(Karolr,parede5))
                                    {
                                        colisaoK(&Karolr); 
                                    }else 
                                        if(CheckCollisionRecs(Karolr,memoria1)==1)
                                        {
                                            if(IsKeyPressed(KEY_ENTER)==1 && memoria==0)
                                            {
                                                 desenharmemoria[0]=0;
                                                 memoria=1;
                                                 memoria1.x=0;
                                                 memoria1.y=0;
                                            }
                                            
                                            colisaoK(&Karolr);
                                        }else
                                            if(CheckCollisionRecs(Karolr,memoria2)==1)
                                            {
                                                if(IsKeyPressed(KEY_ENTER)==1 && memoria==0)
                                                {
                                                    desenharmemoria[1]=0;
                                                    memoria=1;
                                                    memoria2.x=0;
                                                    memoria2.y=0;
                                                }
                                                    colisaoK(&Karolr);
                                            }else 
                                                if(CheckCollisionRecs(Karolr,memoria3))
                                                {
                                                    if(IsKeyDown(KEY_ENTER)==1 && memoria==0)
                                                    {
                                                         desenharmemoria[2]=0;
                                                         memoria=1;
                                                         memoria3.x=0;
                                                         memoria3.y=0;
                                                    }
                                                    colisaoK(&Karolr);
                                                }else 
                                                    if(CheckCollisionRecs(Karolr,memoria4))
                                                    {
                                                        
                                                        if(IsKeyDown(KEY_ENTER)==1 && memoria==0)
                                                        {
                                                             desenharmemoria[5]=0;
                                                             memoria=1;
                                                             memoria4.x=0;
                                                             memoria4.y=0;
                                                        }
                                                        colisaoK(&Karolr);
                                                    }else 
                                                        if(CheckCollisionRecs(Karolr,memoria5))
                                                        {
                                                            
                                                            if(IsKeyDown(KEY_ENTER)==1 && memoria==0)
                                                            {
                                                                 desenharmemoria[9]=0;
                                                                 memoria=1;
                                                                 memoria5.x=0;
                                                                 memoria5.y=0;
                                                            }
                                                            colisaoK(&Karolr);
                                                        }else 
                                                            if(CheckCollisionRecs(Karolr,memoria6))
                                                            {
                                                                
                                                                if(IsKeyDown(KEY_ENTER)==1 && memoria==0)
                                                                {
                                                                     desenharmemoria[10]=0;
                                                                     memoria=1;
                                                                     memoria6.x=0;
                                                                     memoria6.y=0;
                                                                }
                                                                colisaoK(&Karolr);
                                                            }else 
                                                                if(CheckCollisionRecs(Karolr,memoria7))
                                                                {
                                                                    
                                                                    if(IsKeyDown(KEY_ENTER)==1 && memoria==0)
                                                                    {
                                                                         desenharmemoria[11]=0;
                                                                         memoria=1;
                                                                         memoria7.x=0;
                                                                         memoria7.y=0;
                                                                    }
                                                                    colisaoK(&Karolr);
                                                                }else 
                                                                    if(CheckCollisionRecs(Karolr,memoriasad1))
                                                                        {
                                                                            if(IsKeyDown(KEY_ENTER)==1 && memoria==0)
                                                                                {
                                                                                    desenharmemoria[3]=0;
                                                                                    memoria=1;
                                                                                    sad=1;
                                                                                    memoriasad1.x=0;
                                                                                    memoriasad1.y=0;
                                                                                }
                                                                            colisaoK(&Karolr);
                                                                        }else 
                                                                            if(CheckCollisionRecs(Karolr,memoriasad2))
                                                                                {
                                                                                    if(IsKeyDown(KEY_ENTER)==1 && memoria==0)
                                                                                       {
                                                                                            desenharmemoria[6]=0;
                                                                                            memoria=1;
                                                                                            sad=1;
                                                                                            memoriasad2.x=0;
                                                                                            memoriasad2.y=0;
                                                                                        }
                                                                                            colisaoK(&Karolr);
                                                                                }else 
                                                                                    if(CheckCollisionRecs(Karolr,memoriasad3))
                                                                                        {
                                                                                            if(IsKeyDown(KEY_ENTER)==1 && memoria==0)
                                                                                                {
                                                                                                     desenharmemoria[7]=0;
                                                                                                     memoria=1;
                                                                                                     sad=1;
                                                                                                     memoriasad3.x=0;
                                                                                                     memoriasad3.y=0;
                                                                                                }
                                                                                                colisaoK(&Karolr);
                                                                                        }else 
                                                                                            if (CheckCollisionRecs(Karolr,lixo))
                                                                                                {
                                                                                                    if(IsKeyPressed(KEY_ENTER)==1 && memoria==1)
                                                                                                        {
                                                                                                            if(ruim>=3)
                                                                                                                {
                                                                                                                    sad=1;
                                                                                                                }
                                                                                                            if(sad==1)
                                                                                                                {
                                                                                                                    stress=stress - 3;
                                                                                                                    sad=0;
                                                                                                                }else
                                                                                                                    {
                                                                                                                        stress = stress+3;
                                                                                                                    }
                                                                                                            memoria=0;
                                                                                                            ruim=0;
                                                                                                        }
                                                                                                    for(int i=1;i<8;i++)
                                                                                                        {
                                                                                                            colis[i]=0;
                                                                                                        }
                                                                                                    colis[0]= colis[0]+1;
                                                                                                    colisaoK(&Karolr); 
                                                                                                }else 
                                                                                                    if(CheckCollisionRecs(Karolr,refletirec)==1)
                                                                                                        {
                                                                                                            colisaoK(&Karolr); 
                                                                                                            if(refletir==1)
                                                                                                                {
                                                                                                                    if(IsKeyPressed(KEY_ENTER)==1 && memoria==1)
                                                                                                                        {                
                                                                                                                            if(sad==1)
                                                                                                                                {
                                                                                                                                    stress-=2;
                                                                                                                                    memoria=0;
                                                                                                                                    sad=0;
                                                                                                                                    refletir=0;
                                                                                                                                }else
                                                                                                                                    {
                                                                                                                                        estabilidade+=1;
                                                                                                                                        memoria=0;
                                                                                                                                        refletir=0;
                                                                                                                                    }
                                                                                                                        }
                                                                                                                }else 
                                                                                                                    if(CheckCollisionRecs(Karolr,falacolisao))
                                                                                                                        {
                                                                                                                            if(falac==1 && ruim>=1)
                                                                                                                                {
                                                                                                                                    colisaoK(&Karolr);  
                                                                                                                                    falac=0;
                                                                                                                                }
                                                                                                                                                                    
                                                                                                                         }  
                                                                                                        } 

if(colis[0]==1||colis[0]==3||colis[0]==5||colis[0]==7||colis[0]==9)
{
    if(CheckCollisionRecs(Karolr,conflito)==1 && memoria==1 && sad==0)
    {
        if(colis[1]==0)
        {
            ruim++;
        }
        colis[1]=1;
        colisaoK(&Karolr);
    }else
        if(CheckCollisionRecs(Karolr,conflito2)==1 && memoria==1 && sad==0)
            {
                if(colis[2]==0)
                    {
                        ruim++;
                    }
                colis[2]=1;
                colisaoK(&Karolr);
            }else
                if(CheckCollisionRecs(Karolr,conflito3)==1 && memoria==1 && sad==0)
                    {
                        if(colis[3]==0)
                            {
                                ruim++;
                            }
                        colis[3]=1;
                        colisaoK(&Karolr);
                    }else
                        if(CheckCollisionRecs(Karolr,conflito4)==1 && memoria==1 && sad==0)
                            {
                                if(colis[4]==0)
                                    {
                                        ruim++;
                                    }
                                colis[4]=1;
                                colisaoK(&Karolr);
                            }else 
                                if(CheckCollisionRecs(Karolr,conflito5)==1 && memoria==1 && sad==0)
                                    {
                                        if(colis[5]==0)
                                            {
                                                ruim++;
                                            }
                                        colis[5]=1;
                                        colisaoK(&Karolr);
                                    }else 
                                        if(CheckCollisionRecs(Karolr,conflito6)==1 && memoria==1 && sad==0)
                                            {
                                                if(colis[6]==0)
                                                    {
                                                    ruim++;
                                                    }
                                                colis[6]=1;
                                                colisaoK(&Karolr);
                                            }else
                                                if(CheckCollisionRecs(Karolr,conflito7)==1 && memoria==1 && sad==0)
                                                    {
                                                        if(colis[7]==0)
                                                            {
                                                            ruim++;
                                                            }
                                                        colis[7]=1; 
                                                        colisaoK(&Karolr);
                                                    }
}
if(colis[0]==2||colis[0]==4||colis[0]==6||colis[0]==8||colis[0]==10)
{
    if(CheckCollisionRecs(Karolr,conflito1par)==1 && memoria==1 && sad==0)
        {
        if(colis[1]==0)
        {
        ruim++;
        }
    colis[1]=1;
    colisaoK(&Karolr);
    }else 
    if(CheckCollisionRecs(Karolr,conflito2par)==1 && memoria==1 && sad==0)
    {
        if(colis[2]==0)
            {
            ruim++;
            }
        colis[2]=1;
        colisaoK(&Karolr);
    }else 
        if(CheckCollisionRecs(Karolr,conflito3par)==1 && memoria==1 && sad==0)
        {
            if(colis[3]==0)
                {
                ruim++;
                }
            colis[3]=1;
            colisaoK(&Karolr);
        }else
            if(CheckCollisionRecs(Karolr,conflito4par)==1 && memoria==1 && sad==0)
                {
                if(colis[4]==0)
                    {
                    ruim++;
                    }
                colis[4]=1;
                colisaoK(&Karolr);
                }else 
                    if(CheckCollisionRecs(Karolr,conflito5par)==1 && memoria==1 && sad==0)
                        {
                            if(colis[5]==0)
                                {
                                ruim++;
                                }
                            colis[5]=1;
                            colisaoK(&Karolr);
                        }else
                            if(CheckCollisionRecs(Karolr,conflito6par)==1 && memoria==1 && sad==0)
                                {
                                    if(colis[6]==0)
                                        {
                                        ruim++;
                                        }
                                    colis[6]=1;
                                    colisaoK(&Karolr);
                                }else
                                    if(CheckCollisionRecs(Karolr,conflito7par)==1 && memoria==1 && sad==0)
                                        {
                                            if(colis[7]==0)
                                                {
                                                ruim++;
                                                }
                                            colis[7]=1; 
                                            colisaoK(&Karolr);
                                        }
}

        if(ruim>=1)   
        {
            contar= contar + 0.017; 
            if(contar>=10)
            {
                stress++;
                contar=0;
            }
        }
        
        
            int minutos = 3600;
            if(contadordetempo==2*minutos)
            {
                diversao=1;
                
            }
            if(contadordetempo==4*minutos)
            {
                terapia=1;
                refletir=1;
                remedio=1;
                
               
            }
            if(contadordetempo==6*minutos)
            {
                diversao=1;
                
            }
            if(contadordetempo==8*minutos)
            {
                terapia=1;
                refletir=1;
                remedio=1;
               
            }
            if(contadordetempo==10*minutos)
            {
                diversao=1;
                
            }
            
        //parte gráfica:
        BeginDrawing();
           ClearBackground(WHITE);
           DrawTexture(Quartotx,0,0,RAYWHITE);
           //DrawTexture(circulo1.posicaox,circulo1.posicaoy,RAYWHITE);
           //DrawTextureRec(Texture2D texture, Rectangle sourceRec, Vector2 position, Color tint); 
           //Memoria e Refletir
           if(memoria==1 && sad==1){
                DrawCircle(175,695,12,BLUE);
           }else
               if(memoria == 1 && sad == 0){
                DrawCircle(175,695,12,YELLOW);   
               }
           if(refletir==1){
               DrawCircle(175,728,12,GREEN);
           }
           DrawText(TextFormat("x: %i y: %i",x,y),605,15,40,RED);
           DrawText(TextFormat("Memoria: "),15,680,35,BLACK);
           DrawTexture(estabilidadetx, 35, 8, WHITE);
           DrawTexture(estressetx, 35, estabilidadetx.height + 16, WHITE);
           DrawRectangleGradientH(39, 36,((estabilidade*0.1)/3)*325, 26, SKYBLUE, DARKBLUE);
           DrawRectangleGradientH(39, 104,(stress*0.1)*325, 25, RED, (Color){123, 20, 34, 255});
           DrawText(TextFormat("Refletir: "),15,710,35,BLACK);
           DrawText(TextFormat("Fase 2"),629,94,35,BLACK);
           DrawText(TextFormat("Tempo: %0.1f", (float)(contadordetempo/100)),1150,42,30,BLACK);
           DrawText(TextFormat("T - Tutorial"),1173,720,24,BLACK);
           DrawText(TextFormat("I - Info"),1173,690,24,BLACK);
           //DrawTextureRec(Karoltx,Karolrec,Karolp,RAYWHITE);
           //DrawTextureRec(Guilhermetx,Guilhermerec,Guilhermep,RAYWHITE);
           
           // desenhando memórias:
           if(desenharmemoria[0]==1)
           {
              DrawTextureRec(memoriastx,memoriasrec,memoriasp,RAYWHITE); 
           }
           if(desenharmemoria[1]==1)
           {
              DrawTextureRec(memoriastx,memoriasrec,memoriasp2,RAYWHITE);
           }
           if(desenharmemoria[2]==1)
           {
              DrawTextureRec(memoriastx,memoriasrec,memoriasp3,RAYWHITE);
           }
           if(desenharmemoria[3]==1)
           {
              DrawTextureRec(memoriastx,memoriassadrec,memoriaspsad1,RAYWHITE);
           }
           if(desenharmemoria[6]==1)
           {
              DrawTextureRec(memoriastx,memoriassadrec,memoriaspsad2,RAYWHITE);
           }
           if(desenharmemoria[7]==1)
           {
              DrawTextureRec(memoriastx,memoriassadrec,memoriaspsad3,RAYWHITE);
           }
           if(desenharmemoria[5]==1)
           {
              DrawTextureRec(memoriastx,memoriasrec,memoriasp4,RAYWHITE);
           }
           if(desenharmemoria[9]==1)
           {
              DrawTextureRec(memoriastx,memoriasrec,memoriasp5,RAYWHITE);
           }
           if(desenharmemoria[10]==1)
           {
              DrawTextureRec(memoriastx,memoriasrec,memoriasp6,RAYWHITE);
           }
           if(desenharmemoria[11]==1)
           {
              DrawTextureRec(memoriastx,memoriasrec,memoriasp7,RAYWHITE);
           }
           if(desenharmemoria[4]==1 && memoria==1 && sad==0)
            {
               if(colis[0]==1||colis[0]==3||colis[0]==5||colis[0]==7||colis[0]==9){
                    DrawTexture(desafiotx,900,300,RAYWHITE);
                    DrawTexture(desafiotx,900,500,RAYWHITE);
                    DrawTexture(desafiotx,200,500,RAYWHITE);
                    DrawTexture(desafiotx,400,300,RAYWHITE);
                    DrawTexture(desafiotx,790,595,RAYWHITE);
                    DrawTexture(desafiotx,300,500,RAYWHITE);
                    DrawTexture(desafiotx,600,560,RAYWHITE);
                }else 
                    if (colis[0]==2||colis[0]==4||colis[0]==6||colis[0]==8||colis[0]==10){
                    DrawTexture(desafiotx,950,350,RAYWHITE);
                    DrawTexture(desafiotx,325,420,RAYWHITE);
                    DrawTexture(desafiotx,220,380,RAYWHITE);
                    DrawTexture(desafiotx,1270,530,RAYWHITE);
                    DrawTexture(desafiotx,910,550,RAYWHITE);
                    DrawTexture(desafiotx,740,570,RAYWHITE);
                    DrawTexture(desafiotx,600,560,RAYWHITE);
                }
            }
           if(desenharmemoria[5]==1)
           {
              DrawTextureRec(memoriastx,memoriasrec,memoriasp4,RAYWHITE);  
           }
           //desenhando desafio:
           if(memoria==1)
           {
               
                desafiofuncaoK(falatx,&ruim,&falac,colis[0]);

           }
           //diversao e terapia:
           if(diversao==1)
           {
               diversaoavisoK(falatx, &falac, &Karolr, falacolisao);
           }
           if(terapia==1)
           {
               terapiaavisoK(falatx, &falac, &Karolr, falacolisao);
           }
           if(remedio==1)
           {
               remedioavisoK(falatx, &falac, &Karolr, falacolisao);
           }
           int espera = 1000; //modificar essa variável para reduzir o tempo de espera
           if(contadordetempo>=(2*minutos)+espera && contadordetempo<(4*minutos)) 
           {
               desenhar=1;
           }
           if(contadordetempo>=(4*minutos)+espera && contadordetempo<(6*minutos))
           {
               desenhar=1;
           }
           if(contadordetempo>=(6*minutos)+espera && contadordetempo<(8*minutos))
           {
               desenhar=1;
           }
           if(contadordetempo>=(8*minutos)+espera && contadordetempo<(10*minutos))
           {
               desenhar=1;
           }
           if(contadordetempo>=(10*minutos)+espera)
           {
               desenhar=1;
           }
           DrawTexture(remediotx,755,410,RAYWHITE);
           //Condição para ganhar ou perder o jogo
           if(estabilidade >= 30)
           {
               subiu_de_level();
           }
           if(estabilidade<=0){
               menu();
           }
           //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
           if(desenhar==1)
           {
               DrawTextureRec(Karoltx,Karolrec,Karolp,RAYWHITE);
           }
           
           if (IsKeyDown(KEY_T)){
               DrawTexture(tutorialtx,0,0,RAYWHITE);
           }
           if(IsKeyDown(KEY_I))
           {
               DrawTexture(info2tx,340,256,RAYWHITE); 
           }
        EndDrawing();
    }
    CloseWindow();
    
}

//FASE 3

void desenharconflitoG1(Texture2D fala){
     
     DrawTexture(fala,237,630,RAYWHITE);
     DrawText("CONFLITO: Ajude Guilherme a retomar o foco.",450,690,20,WHITE);
     DrawText("[PRESS A]",450,720,20,WHITE);
     
}
void desenharconflitoG2(Texture2D fala){
     
     DrawTexture(fala,237,630,RAYWHITE);
     DrawText("CONFLITO: Ajude Guilherme a retomar o foco.",450,690,20,WHITE);
     DrawText("[PRESS T]",450,720,20,WHITE);
     
}
void desenharconflitoG3(Texture2D fala){
     
     DrawTexture(fala,237,630,RAYWHITE);
     DrawText("CONFLITO: Ajude Guilherme a retomar o foco.",450,690,20,WHITE);
     DrawText("[PRESS E]",450,720,20,WHITE);
     
}
void desenharconflitoG4(Texture2D fala){
     
     DrawTexture(fala,237,630,RAYWHITE);
     DrawText("CONFLITO: Ajude Guilherme a retomar o foco.",450,690,20,WHITE);
     DrawText("[PRESS N]",450,720,20,WHITE);
     
}
void desenharconflitoG5(Texture2D fala){
     
     DrawTexture(fala,237,630,RAYWHITE);
     DrawText("CONFLITO: Ajude Guilherme a retomar o foco.",450,690,20,WHITE);
     DrawText("[PRESS C]",450,720,20,WHITE);
     
}
void desenharconflitoG6(Texture2D fala){
     
     DrawTexture(fala,237,630,RAYWHITE);
     DrawText("CONFLITO: Ajude Guilherme a retomar o foco.",450,690,20,WHITE);
     DrawText("[PRESS A]",450,720,20,WHITE);
     
}
void desenharconflitoG7(Texture2D fala){
     
     DrawTexture(fala,237,630,RAYWHITE);
     DrawText("CONFLITO: Ajude Guilherme a retomar o foco.",450,690,20,WHITE);
     DrawText("[PRESS O]",450,720,20,WHITE);
     
}
void batalhafuncaoG(int* ruim,int opc, int* batalha){
   if(opc == 1)
   {
       
       if(GetKeyPressed()<=0)
       {
           
       }
       else 
       {
          if(IsKeyDown('A')) 
           {
               (*ruim)--;
               (*batalha)++;
           }
           else 
           {
               (*ruim)++;
               (*batalha)++;
           } 
       }
   }
   else if(opc == 2)
   {
      if(GetKeyPressed()<=0)
       {
           
       }
       else 
       {
          if(IsKeyDown('T')) 
           {
               (*ruim)--;
               (*batalha)++;
           }
           else 
           {
               (*ruim)++;
               (*batalha)++;
           } 
       }
       
   }
   else if(opc == 3)
   {
       if(GetKeyPressed()<=0)
       {
           
       }
       else 
       {
          if(IsKeyDown('E')) 
           {
               (*ruim)--;
               (*batalha)++;
           }
           else 
           {
               (*ruim)++;
               (*batalha)++;
           } 
       }
       
   }
   else if(opc == 4)
   {
     if(GetKeyPressed()<=0)
       {
           
       }
       else 
       {
          if(IsKeyDown('N')) 
           {
               (*ruim)--;
               (*batalha)++;
           }
           else 
           {
               (*ruim)++;
               (*batalha)++;
           } 
       }
       
   }
   else if(opc == 5)
   {
       if(GetKeyPressed()<=0)
       {
           
       }
       else 
       {
          if(IsKeyDown('C')) 
           {
               (*ruim)--;
               (*batalha)++;
           }
           else 
           {
               (*ruim)++;
               (*batalha)++;
           } 
       }
       
   }
   else if(opc == 6)
   {
       if(GetKeyPressed()<=0)
       {
           
       }
       else 
       {
          if(IsKeyDown('A')) 
           {
               (*ruim)--;
               (*batalha)++;
           }
           else 
           {
               (*ruim)++;
               (*batalha)++;
           } 
       }
       
       
   }
   else if(opc == 7)
   {
       if(GetKeyPressed()<=0)
       {
           
       }
       else 
       {
          if(IsKeyDown('O')) 
           {
               (*ruim)--;
               (*batalha)++;
           }
           else 
           {
               (*ruim)++;
               (*batalha)++;
           } 
       }
       
   }
}
void desafiofuncaoG(Texture2D fala,int* ruim, int* batalha,int* falac){
      (*falac)=1;
      if((*batalha)==1)
      {
          desenharconflitoG2(fala);
          batalhafuncaoG(&(*ruim),2,&(*batalha)); 
          
      }
      else if((*batalha)==2)
      {
          desenharconflitoG1(fala);
          batalhafuncaoG(&(*ruim),1,&(*batalha));
          
      }    
      else if((*batalha)==3)
      {
        desenharconflitoG5(fala);
        batalhafuncaoG(&(*ruim),5,&(*batalha));
      } 
      else if((*batalha)==4)
      {
        desenharconflitoG3(fala);
        batalhafuncaoG(&(*ruim),3,&(*batalha));
      } 
      else if((*batalha)==5)
      {
        desenharconflitoG7(fala);
        batalhafuncaoG(&(*ruim),7,&(*batalha));
      } 
      else if((*batalha)==6)
      {
        desenharconflitoG4(fala);
        batalhafuncaoG(&(*ruim),4,&(*batalha));
      } 
      else if((*batalha)==7)
      {
        desenharconflitoG6(fala);
        batalhafuncaoG(&(*ruim),6,&(*batalha));
      } 
      else if((*batalha)==8)
      {
        (*batalha)=0;
      }              
        
}
void diversaoavisoG(Texture2D fala,int* falac, Rectangle* Guilhermer, Rectangle falacolisao){
     (*falac)=1;
     DrawTexture(fala,237,650,RAYWHITE);
     if((Guilhermer->x >= falacolisao.x) && (Guilhermer->y >= falacolisao.y))
     {
         Guilhermer->y = 525;
     }
     DrawText("Está na hora de Guilherme se divertir",450,720,20,WHITE);  
     
}
void terapiaavisoG(Texture2D fala,int* falac, Rectangle* Guilhermer, Rectangle falacolisao){
     (*falac)=1;
     DrawTexture(fala,237,650,RAYWHITE);
     if((Guilhermer->x >= falacolisao.x) && (Guilhermer->y >= falacolisao.y))
     {
         Guilhermer->y = 525;
     }
     DrawText("Está na hora de Guilherme ir para a terapia",450,720,20,WHITE);  
     
}
void remedioavisoG(Texture2D fala,int* falac, Rectangle* Guilhermer, Rectangle falacolisao){
     (*falac)=1;
     DrawTexture(fala,237,650,RAYWHITE);
     if((Guilhermer->x >= falacolisao.x) && (Guilhermer->y >= falacolisao.y))
     {
         Guilhermer->y = 525;
     }
     DrawText("Está na hora de Guilherme tomar seu remedio",450,720,20,WHITE);  
     
}
void perdeumemoria(Texture2D fala,int* falac, Rectangle* Guilhermer, Rectangle falacolisao){
     (*falac)=1;
     DrawTexture(fala,237,650,RAYWHITE);
     if((Guilhermer->x >= falacolisao.x) && (Guilhermer->y >= falacolisao.y))
     {
         Guilhermer->y = 525;
     }
     DrawText("Guilherme se esqueceu da memória que tentava guardar",450,720,20,WHITE);  
     
}
void tudoDoGuilherme() {
    int screenWidth = 1366; //dimenssão da minha tela
    int screenHeight = 768;
    
    int contadordetempo = 0;
    
    //Carregando imagem e transformando em textura:
    //Image:
        Image Quarto = LoadImage("/jogoip/Quarto002.png"); //diretorio apartir do C: com as \ invertidas (/);
        Image Guilhermeim = LoadImage("/jogoip/Guilherme01.png");
        Image memoriasim = LoadImage("/jogoip/memorias.png");
        Image monstro = LoadImage("/jogoip/monstro2.png");
        Image fala = LoadImage("/jogoip/fala.png");
        Image bolaim = LoadImage("/jogoip/bola.png");
        Image supim = LoadImage("/jogoip/filme1.png");
        Image capim = LoadImage("/jogoip/filme2.png");
        Image loveim = LoadImage("/jogoip/crush.png");
        Image jogoim = LoadImage("/jogoip/jogo.png");
     //Image Resize:
        ImageResize (&Guilhermeim,144,104); //144,104,(108,78) - Aumentando a imagem original
        ImageResize (&Quarto,1366,788); //passar o endereço pq ele modifica a imagem original.
        ImageResize (&fala,900,200);
        ImageResize (&bolaim,96,52);
        ImageResize (&supim,96,52);
        ImageResize (&capim,96,52);
        ImageResize (&loveim,96,52);
        ImageResize (&jogoim,96,52);
     //Texture2D:
        Texture2D Quartotx = LoadTextureFromImage(Quarto);
        Texture2D Guilhermetx = LoadTextureFromImage(Guilhermeim);
        Texture2D memoriastx = LoadTextureFromImage(memoriasim);
        Texture2D falatx = LoadTextureFromImage(fala);
        Texture2D bolatx = LoadTextureFromImage(bolaim);
        Texture2D suptx = LoadTextureFromImage(supim);
        Texture2D captx = LoadTextureFromImage(capim);
        Texture2D jogotx = LoadTextureFromImage(jogoim);
        Texture2D lovetx = LoadTextureFromImage(loveim);
        Texture2D estabilidadetx = LoadTexture("/jogoip/estabilidade.png");
        Texture2D estressetx = LoadTexture("/jogoip/estresse.png");
     //Rectengles:
        Rectangle Guilhermerec = {0,0,55,102};// testando o tamanho do boneco no mapa (pegando só esse retângulo)
        //Rectangle Karolrec = {0,0,55,102}; // Esta ok
        //Rectangle Guilhermerec = {0,0,55,102}; //se desejar aumentar manter a proporção para os 3 bonecos (usar multiplo)
       //Retângulo de movimentação:
        Rectangle Guilhermer = {17,400,53,51}; //um retângulo de colisão que representa Jorge (metade da altura para colidir com o pé)
       //criando colisão
        Rectangle estante = {330,116,979,180}; //colisão para a estante
        Rectangle memoria1 = {500,325,20,3};
        Rectangle memoria2 = {600,325,20,3};
        Rectangle memoria3 = {600,525,20,5};
        Rectangle memoria4 = {965,340,20,3};
        Rectangle memoria5 = {1025,560,30,5};
        Rectangle memoria6 = {130,520,30,5}; 
        Rectangle memoria10 = {995,400,30,3};
        Rectangle memoria11 = {1030,400,30,3};
        Rectangle memoriasad1 = {800,600,20,5};
        Rectangle memoriasad2 = {255,380,20,5};
        Rectangle memoriasad3 = {1270,540,30,5};
        Rectangle conflito = {900,394,70,50};
        Rectangle conflito2 = {331,363,70,50};
        Rectangle conflito3 = {200,520,70,50};
        Rectangle conflito4 = {530,670,70,50};
        Rectangle conflito5 = {790,666,70,50};
        Rectangle mesa = {525,405,305,100};
        Rectangle pe1= {570,515,20,15};
        Rectangle pe2= {790,515,20,15};
        Rectangle lixo = {1070,304,113,20};
        Rectangle parede1 = {0,0,190,340};
        Rectangle parede2 = {1166,0,190,340};
        Rectangle parede3 = {221,304,55,20};
        Rectangle parede4 = {0,669,190,340};
        Rectangle parede5 = {1166,669,190,340};
        //Rectangle p1 = {};
        //Rectangle p2 = {};
        //Rectangle p3 = {};
        Rectangle falacolisao = {330,685,1300,300};
        Rectangle refletirec = {636,390,20,20};
        
        //recorte de imagem:
        Rectangle memoriasrec = {0,0,30,20}; //ok!
        Rectangle memoriassadrec = {30,20,30,20}; //ok!
        //Rectangle conflitorec = {60,40,35,20};
        
        
       
        
        
       //posição das memórias:
        Vector2 memoriasp = {500,325}; //ferias com a família
        Vector2 memoriasp2 = {600,325}; //ganhou um ps4
        Vector2 memoriasp3 = {600,525}; //passou de ano
        Vector2 memoriasp5 = {130,520}; //conseguiu vencer algum medo 
        Vector2 memoriasp6 = {1025,560}; //fez uma nova amizade
        Vector2 memoriaspsad1 = {800,600}; //perdeu contato com um amigo querido
        Vector2 memoriasp4 = {965,340};
        Vector2 memoriap10 = {1025,443};
        Vector2 memoriap11 = {1000,443};
        Vector2 memoriaspsad2 = {255,380}; //morte de um familiar
        Vector2 memoriaspsad3 = {1270,540}; //teve uma crise de pânico em público 
        
        
    //variáveis :
    int memoria = 0;
    int stress = 5; //chegando a 0 aumenta estabilidade, chegando a 10 diminui.
    int estabilidade = 10; //chegando a 30 (exemplo) passa de nível, chegando a 0 perde
    int sad = 0; 
    int desafio = 0;
    int batalha = -1;
    //int batalha2= -1;
    //int batalha3= -1;
    int ruim = 0;
    int desenhar = 1;
    int diversao = 0;
    int terapia = 0;
    int remedio=0;
    int falac=0;
    int checkpoint = 0;
    int refletir=0;
    int contador=0;
    checkpoint = qual_level(0);
    int colis[10]={1,0,0,0,0,0,0,0,0,0};
    int desenharmemoria[15] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    
    //Trilha Sonora:
    Music space = LoadMusicStream("/jogoip/Space.ogg");
    PlayMusicStream(space);
    //Tutorial:
    Image tutorialim = LoadImage("/jogoip/tutorial.png");
    ImageResize (&tutorialim,1366,788);
    Texture2D tutorialtx = LoadTextureFromImage(tutorialim);
    //Informarções:
    Image info3 = LoadImage("/jogoip/TDA.png");
    Texture2D info3tx = LoadTextureFromImage(info3);
        
        
    while (!WindowShouldClose())
    {
            UpdateMusicStream (space);
            if(estabilidade >= 30)
           {
            subiu_de_level();
            menu();
           }
 
         contadordetempo++;
         //Vector2 Jorgep = {Jorger.x,Jorger.y-51}; //posição do Jorge (menos 51 para a colisão ficar no pé)
         Vector2 Guilhermep = {Guilhermer.x,Guilhermer.y-51};
         //Posição do mouse na tela
         int x = GetMouseX();
         int y = GetMouseY();
        
        //função de movimentação do jorge:
        if(desafio==0)
        {
           movimentacaoK(&Guilhermer); 
        }
         
        //Checando se saiu do mapa:
        tamanhotelaK(&Guilhermer,screenHeight,screenWidth);
        //atualizando estabilidade:
        atualizarestabilidade(&stress,&estabilidade);
        
        //checando colisão:
        if(CheckCollisionRecs(Guilhermer,estante)==1)
        {
            Guilhermer.y+=4;
            if(memoria==1 && IsKeyPressed(KEY_ENTER)==1)
            {
                if(sad==0)
                {
                    stress = stress-2;
                }
                else
                {
                    stress = stress+2;
                    sad=0;
                }
                
                memoria=0;
                
                for(int i=1;i<8;i++)
                {
                    colis[i]=0;
                }
                colis[0]= colis[0]+1;
                ruim=0;
            }
            
        }
        else if(CheckCollisionRecs(Guilhermer,mesa)==1 ||CheckCollisionRecs(Guilhermer,pe1)==1|| CheckCollisionRecs(Guilhermer,pe2)==1)
        {
            colisaoK(&Guilhermer);
        }
        else if(CheckCollisionRecs(Guilhermer,parede1)==1) 
        {
            colisaoK(&Guilhermer);
            if(diversao==1)
            {
                
                desenhar=0;
                stress = stress - 5;
                diversao=0;
            }
            
        }
        else if(CheckCollisionRecs(Guilhermer,parede2)==1)
        {
            colisaoK(&Guilhermer);
            if(terapia==1)
            {
                desenhar=0;
                estabilidade = estabilidade + 5;
                terapia=0;
            }
            
        }
        else if(CheckCollisionRecs(Guilhermer,parede3))
        {
            colisaoK(&Guilhermer); 
        }
        else if(CheckCollisionRecs(Guilhermer,parede4) || CheckCollisionRecs(Guilhermer,parede5))
        {
            colisaoK(&Guilhermer); 
        }
        else if(CheckCollisionRecs(Guilhermer,memoria1)==1)
        {
            if(IsKeyPressed(KEY_ENTER)==1 && memoria==0)
            {
                 desenharmemoria[0]=0;
                 memoria=1;
                 memoria1.x=0;
                 memoria1.y=0;
            }
            
            colisaoK(&Guilhermer);
        }
        else if(CheckCollisionRecs(Guilhermer,memoria2)==1)
        {
            if(IsKeyPressed(KEY_ENTER)==1 && memoria==0)
            {
                 desenharmemoria[1]=0;
                 memoria=1;
                 memoria2.x=0;
                 memoria2.y=0;
            }
            colisaoK(&Guilhermer);
        }
        else if(CheckCollisionRecs(Guilhermer,memoria3))
        {
            if(IsKeyDown(KEY_ENTER)==1 && memoria==0)
            {
                 desenharmemoria[2]=0;
                 memoria=1;
                 memoria3.x=0;
                 memoria3.y=0;
            }
            colisaoK(&Guilhermer);
        }
        
        else if(CheckCollisionRecs(Guilhermer,conflito)==1 && memoria==1)
        {
            if(colis[1]==0)
            {
                stress = stress +2;
                colis[1]=1;
                desafio=1; 
                batalha=1;
            }
            
            colisaoK(&Guilhermer);
        }
        else if(CheckCollisionRecs(Guilhermer,conflito2)==1 && memoria==1)
        {
            if(colis[2]==0)
            {
                stress = stress +2;
                colis[2]=1;
                desafio=1; 
                batalha=1;
            }
            
            colisaoK(&Guilhermer);
        }
        else if(CheckCollisionRecs(Guilhermer,conflito3)==1 && memoria==1)
        {
            if(colis[3]==0)
            {
                stress = stress +2;
                colis[3]=1;
                desafio=1; 
                batalha=1;
            }
            
            colisaoK(&Guilhermer);
        }
        else if(CheckCollisionRecs(Guilhermer,conflito4)==1 && memoria==1)
        {
            if(colis[4]==0)
            {
                stress = stress +2;
                colis[4]=1;
                desafio=1; 
                batalha=1;
            }
            
            colisaoK(&Guilhermer);
        }
        else if(CheckCollisionRecs(Guilhermer,conflito5)==1 && memoria==1)
        {
            if(colis[5]==0)
            {
                stress = stress +2;
                colis[5]=1;
                desafio=1; 
                batalha=1;
            }
           
            colisaoK(&Guilhermer);
        }
        else if(CheckCollisionRecs(Guilhermer,memoriasad1))
        {
            if(IsKeyDown(KEY_ENTER)==1 && memoria==0)
            {
                 desenharmemoria[3]=0;
                 memoria=1;
                 sad=1;
                 memoriasad1.x=0;
                 memoriasad1.y=0;
            }
            colisaoK(&Guilhermer);
        }
        else if (CheckCollisionRecs(Guilhermer,lixo))
        {
           if(IsKeyPressed(KEY_ENTER)==1 && memoria==1)
            {
                if(sad==1)
                {
                    stress--;
                    sad=0;
                }
                else
                {
                    stress = stress+3;
                }
                 memoria=0;
                for(int i=1;i<8;i++)
                {
                    colis[i]=0;
                }
                colis[0]= colis[0]+1;
                ruim=0;
            }
            colisaoK(&Guilhermer); 
            
        }  
        else if(CheckCollisionRecs(Guilhermer,falacolisao))
        {
           if(falac==1 && ruim>=1)
           {
              colisaoK(&Guilhermer);  
              falac=0;
           }
            
        }        
            int minutos = 3600;
            if(contadordetempo==2*minutos)
            {
                diversao=1;
                
            }
            if(contadordetempo==4*minutos)
            {
                terapia=1;
                refletir=1;
                remedio=1;
                
               
            }
            if(contadordetempo==6*minutos)
            {
                diversao=1;
                
            }
            if(contadordetempo==8*minutos)
            {
                terapia=1;
                refletir=1;
                remedio=1;
               
            }
            if(contadordetempo==10*minutos)
            {
                diversao=1;
                
            }
            
        //parte gráfica:
        BeginDrawing();
           ClearBackground(WHITE);
           DrawTexture(Quartotx,0,0,RAYWHITE);
           //DrawTexture(circulo1.posicaox,circulo1.posicaoy,RAYWHITE);
           //DrawTextureRec(Texture2D texture, Rectangle sourceRec, Vector2 position, Color tint); 
           DrawText(TextFormat("x: %i y: %i",x,y),605,15,40,RED);
           DrawText(TextFormat("Memoria: "),15,680,35,BLACK);
           if(memoria==1 && sad==1){
                DrawCircle(175,695,12,BLUE);
           }else
               if(memoria == 1 && sad == 0){
                DrawCircle(175,695,12,YELLOW);   
               }
           if(refletir==1){
               DrawCircle(175,728,12,GREEN);
           }
           DrawTexture(estabilidadetx, 35, 8, WHITE);
           DrawTexture(estressetx, 35, estabilidadetx.height + 16, WHITE);
           DrawRectangleGradientH(39, 36,((estabilidade*0.1)/3)*325, 26, SKYBLUE, DARKBLUE);
           DrawRectangleGradientH(39, 104,(stress*0.1)*325, 25, RED, (Color){123, 20, 34, 255});
           //DrawText(TextFormat("Refletir: %i",refletir),15,710,35,BLACK); 
           DrawText(TextFormat("Fase 3"),629,94,35,BLACK);
           DrawText(TextFormat("Tempo: %0.1f", (float)(contadordetempo/100)),1150,42,30,BLACK);
           DrawText(TextFormat("T - Tutorial"),1173,720,24,BLACK);
           DrawText(TextFormat("I - Info"),1173,690,24,BLACK);
           //DrawTextureRec(Karoltx,Karolrec,Karolp,RAYWHITE);
           //DrawTextureRec(Guilhermetx,Guilhermerec,Guilhermep,RAYWHITE);
           
           // desenhando memórias:
           if(desenharmemoria[0]==1)
           {
              DrawTextureRec(memoriastx,memoriasrec,memoriasp,RAYWHITE); 
           }
           if(desenharmemoria[1]==1)
           {
              DrawTextureRec(memoriastx,memoriasrec,memoriasp2,RAYWHITE);
           }
           if(desenharmemoria[2]==1)
           {
              DrawTextureRec(memoriastx,memoriasrec,memoriasp3,RAYWHITE);
           }
           if(desenharmemoria[3]==1)
           {
              DrawTextureRec(memoriastx,memoriassadrec,memoriaspsad1,RAYWHITE);
           }
           if(desenharmemoria[4]==1 && memoria==1)
           {
              DrawTexture(lovetx,900,394,RAYWHITE);
              DrawTexture(jogotx,331,363,RAYWHITE);
              DrawTexture(suptx,200,520,RAYWHITE);
              DrawTexture(captx,530,670,RAYWHITE);
              DrawTexture(bolatx,790,666,RAYWHITE);
           }
           //desenhando desafio:
          
           //diversao e terapia:
           if(diversao==1)
           {
               diversaoavisoG(falatx, &falac, &Guilhermer, falacolisao);
           }
           if(terapia==1)
           {
               terapiaavisoG(falatx, &falac, &Guilhermer, falacolisao);
           }
           if(remedio==1)
           {
               //remedioavisoG(falatx, &falac, &Guilhermer, falacolisao);
           }
            if(desafio==1)
           {
               
               if(batalha>=1)
               {
                    desafiofuncaoG(falatx,&ruim,&batalha,&falac);
                   
               }
               if(batalha==0)
               {
                   desafio=0;
               }
           }
           if(batalha==0 && memoria==1 && ruim<=-3 && ruim!=0)
           {
                //deu bom               
                   
           }
           else if(batalha==0 && memoria==1 && ruim>-3 && ruim!=0)
           {
               
               if(memoria==1)
               {
                   perdeumemoria(falatx, &falac, &Guilhermer, falacolisao);
                   memoria=0; 
                                     
               }
                 for(int i=1;i<8;i++)
                {
                    colis[i]=0;
                }
                colis[0]= colis[0]+1;
                 ruim=0;
               
               
           }        
           int espera = 1000; //modificar essa variável para reduzir o tempo de espera
          if(contadordetempo>=(2*minutos)+espera && contadordetempo<(4*minutos)) 
           {
               desenhar=1;
           }
           if(contadordetempo>=(4*minutos)+espera && contadordetempo<(6*minutos))
           {
               desenhar=1;
           }
           if(contadordetempo>=(6*minutos)+espera && contadordetempo<(8*minutos))
           {
               desenhar=1;
           }
           if(contadordetempo>=(8*minutos)+espera && contadordetempo<(10*minutos))
           {
               desenhar=1;
           }
           if(contadordetempo>=(10*minutos)+espera)
           {
               desenhar=1;
           }
           
           if(estabilidade >= 30)
           {
               subiu_de_level();
           }
           if(desenhar==1)
           {
               DrawTextureRec(Guilhermetx,Guilhermerec,Guilhermep,RAYWHITE);
           }
           
           //Tutorial:
           if (IsKeyDown(KEY_T)){
               DrawTexture(tutorialtx,0,0,RAYWHITE);
           }
           //Informações:
           if(IsKeyDown(KEY_I))
           {
               DrawTexture(info3tx,340,256,RAYWHITE); 
           }
           
        EndDrawing();
    }
    CloseWindow();
    }//SXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void move_circ(int* posic){
    if(IsKeyPressed(KEY_UP))
    {
        if((*posic) > 470)
        {
            (*posic) -= 50;
        }
    }
    if(IsKeyPressed(KEY_DOWN))
    {
        if((*posic) < 600)
        {
            (*posic) += 50;
        }
    }
}
void menu(){
        
        int posic_circ = 470;
        Image Menu = LoadImage("/jogoip/menu.png");
        ImageResize (&Menu,1366,788);
        Texture2D Menutx = LoadTextureFromImage(Menu);
        
        Music maya = LoadMusicStream("/jogoip/Maya.ogg");
        PlayMusicStream(maya);
while(!WindowShouldClose()){
        UpdateMusicStream(maya);
        
        BeginDrawing();
               ClearBackground(RAYWHITE);
               DrawTexture(Menutx,0,0,RAYWHITE);
               int x = GetMouseX();
               int y = GetMouseY();
               DrawText(TextFormat("x: %i y: %i",x,y),10,15,40,RED);
               DrawText("Fase 1",600,450,50,BLACK);
               DrawText("Fase 2",600,500,50,BLACK);
               DrawText("Fase 3",600,550,50,BLACK);
               DrawText("Sobre nós",600,600,50,BLACK);
               DrawCircle(580,posic_circ,10,RED);
               move_circ(&posic_circ);
               
        int opcMenu = 0;
        
        int checkpoint = qual_level(0);
        
        
        
        if (posic_circ == 470 && IsKeyPressed(KEY_ENTER)){
            opcMenu = 1;
        }else if ((posic_circ == 520 && IsKeyPressed(KEY_ENTER)) && checkpoint >= 2){
            opcMenu = 2;
        }else if ((posic_circ == 570 && IsKeyPressed(KEY_ENTER)) && checkpoint >= 3){
            opcMenu = 3;
        }else if (posic_circ == 620 && IsKeyPressed(KEY_ENTER)){
            opcMenu = 4;
        }
        EndDrawing();
        switch(opcMenu){
            case 1 : 
                tudoDoJorge();
                break;
            //end case 1
            case 2 : 
                tudoDaKarol();
                break;
            //end case 2
            case 3 : 
                tudoDoGuilherme();
                break;
            //end case 3
            case 4 : 
                sobrenos();
                break;
            //end case 4
        }//end switch
    }//end window should close
}// end função menu 
int qual_level(int checkpoint){
     //PARA O ARMAZENAMENTO (LER)
    FILE *level;
    level = fopen("checkpoint.txt" , "r");
    //Variavel aonde estará armazenado em qual fase ele está
    int levelum = 0, leveldois = 0, leveltres = 0;
    //Função que escreve do arquivo (.txt) e passa para as variaveis levelum, leveldois, leveltres
    fscanf(level, "%i %i %i", &levelum, &leveldois, &leveltres);
    //Função para parar de ler o arquivo
    fclose(level);
    //Caso o jogador só tenha o primeiro level desbloqueado
    int check = levelum + leveldois + leveltres;
    if(check == 1){
        return 1;
    }else
    if(check == 2){
        return 2;
    }else
    if(check == 3){
        return 3;
    }
    return 1;
}// end of non-void function
void subiu_de_level (){
    //ESCREVENDO NO ARQUIVO (checkpoint.txt)
    FILE *level;
    level = fopen("checkpoint.txt" , "w");
    //Variaveis criadas no escopo dessa função
    int check = qual_level(0);
    //Se a função for chamada quando o checkpoint = 1; será escrito no arquivo checkpoint.txt 1 1 0
    if(check == 1){
        int  a = 1, b = 1, c = 0;
        fprintf(level , "%i %i %i", a, b, c);
    }
    //Se a função for chamada quando o checkpoint = 2; será escrito no arquivo checkpoint.txt 1 1 1
    if(check == 2){   
        int  a = 1 , b = 1, c = 1;
        fprintf(level , "%i %i %i", a, b, c);
    }
    fclose(level);
}//end subiu     
int main(void){
    const int screenWidth = 1366; 
    const int screenHeight = 768;
     
    InitWindow(screenWidth, screenHeight, " Pixelmind ");
    InitAudioDevice();
    SetTargetFPS(60);    
    
    menu();
    
    return 0;
}
