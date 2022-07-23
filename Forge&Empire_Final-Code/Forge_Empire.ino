//ALUNOS:: EMILIO, BOUSHRA, BRUNA, GUSTAVO E HOMAM. 17/06/2022 hora; 18:10

#include <Adafruit_GFX.h>     // Core graphics library
#include <Adafruit_ST7789.h>  // Hardware-specific library for ST7789
#include <SPI.h>              // Arduino SPI library
#include <EEPROM.h>

// ST7789 TFT module connections
#define TFT_CS 10
#define TFT_RST 8  // define reset pin, or set to -1 and connect to Arduino RESET pin
#define TFT_DC 9   // define data/command pin

int a = 0, preencheA = 0, preencheB = 0;

unsigned long comeco = 900000;
unsigned long fim = 0;

unsigned long comeco2 = 900000;
unsigned long fim2 = 0;

unsigned long  m = 1;
unsigned long  m2 = 1;

int minutos = 1;
int segundos = 20;

int minutos2 = 4;
int segundos2 = 60;

int jogadorSelecionado = -1;
int pontos_jogador =0;;



// Initialize Adafruit ST7789 TFT library
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

typedef struct {
  char nome[4];
  int pontos;
} Ranking;

Ranking rank[3] = { { "EMI", 90 }, { "GUS", 12 }, { "BOU", 20 } };

int option = 0;

void moldura() {
  tft.drawRect(0, 0, 240, 240, ST77XX_WHITE);
  tft.drawRect(1, 1, 240, 240, ST77XX_WHITE);
}

void ranking() {

  tft.fillScreen(ST77XX_BLACK);
  moldura();
  int a = 0, i, y;
  Ranking aux;


  for (i = 0; i < 3; i++) {
    for (y = i + 1; y < 3; y++) {
      if (rank[i].pontos < rank[y].pontos) {

        aux = rank[i];
        rank[i] = rank[y];
        rank[y] = aux;
      }
    }
  }


  for (int i = 0; i < 3; i++) {
    if (strlen(rank[i].nome) != 0) {
      tft.setTextColor(ST77XX_WHITE);
      tft.setCursor(27, 110 + a);
      tft.println(rank[i].nome);
      tft.setTextColor(ST77XX_RED);
      tft.setCursor(26, 114 + a);
      tft.println("____");

      tft.setTextColor(ST77XX_WHITE);
      tft.setCursor(150, 140 + a);
      tft.println(rank[i].pontos);
      tft.setTextColor(ST77XX_RED);
      tft.setCursor(132, 144 + a);
      tft.println("_______/");
      tft.setCursor(227, 133 + a);
      tft.println("/");

      tft.setCursor(2, 114 + a);
      tft.println("\\_");
      tft.setCursor(73, 124 + a);
      tft.println("\\__");
      tft.setCursor(109, 134 + a);
      tft.println("\\");
      tft.setCursor(120, 145 + a);
      tft.println("\\");

      a += 30;

      tft.setCursor(40, 110 + a);
    }
  }

  while (digitalRead(3) != 0) {
    tft.setTextWrap(true);

    tft.setTextSize(3);
    tft.setTextColor(ST77XX_RED);
    tft.setCursor(30, 60);
    tft.println("NOME");
    tft.setTextColor(ST77XX_RED);
    tft.setCursor(120, 100);
    tft.println("PONTOS");
    tft.setTextColor(ST77XX_WHITE);
    tft.setCursor(33, 63);
    tft.println("NOME");
    tft.setTextColor(ST77XX_WHITE);
    tft.setCursor(123, 103);
    tft.println("PONTOS");
  }
}


void menuDisplay() {

  moldura();
  while (preencheA != 210) {

    tft.setTextSize(5);

    tft.setCursor(45, 20);
    tft.setTextColor(ST77XX_RED);
    tft.println("FORGE");

    tft.setCursor(107, 65);
    tft.setTextColor(ST77XX_RED);
    tft.println("&");

    tft.setCursor(35, 110);
    tft.setTextColor(ST77XX_RED);
    tft.println("EMPIRE");


    tft.setCursor(48, 23);
    tft.setTextColor(ST77XX_WHITE);
    tft.println("FORGE");

    tft.setCursor(110, 67);
    tft.setTextColor(ST77XX_WHITE);
    tft.println("&");

    tft.setCursor(38, 113);
    tft.setTextColor(ST77XX_WHITE);
    tft.println("EMPIRE");

    tft.drawRect(20, 170, 200, 20, ST77XX_RED);
    tft.drawRect(20, 200, 200, 20, ST77XX_RED);

    tft.drawRect(19, 169, 201, 20, ST77XX_RED);
    tft.drawRect(19, 201, 201, 20, ST77XX_RED);

    tft.fillRect(21, 171, preencheA, 18, ST77XX_WHITE);
    tft.fillRect(21, 201, preencheB, 18, ST77XX_WHITE);

    preencheA += 10;
    preencheB += 18;
    delay(500);

    if (preencheB >= 198) {
      preencheB = 197;
    }
    if (preencheA >= 210) {
      tft.fillScreen(ST77XX_BLACK);
      delay(500);
    }

  }
  //--------------------------------------------

  tft.setTextSize(4);

  tft.setCursor(60, 20);
  tft.setTextColor(ST77XX_RED);
  tft.println("FORGE");

  tft.setCursor(110, 55);
  tft.setTextColor(ST77XX_RED);
  tft.println("&");

  tft.setCursor(50, 90);
  tft.setTextColor(ST77XX_RED);
  tft.println("EMPIRE");


  tft.setCursor(63, 23);
  tft.setTextColor(ST77XX_WHITE);
  tft.println("FORGE");

  tft.setCursor(113, 57);
  tft.setTextColor(ST77XX_WHITE);
  tft.println("&");

  tft.setCursor(53, 93);
  tft.setTextColor(ST77XX_WHITE);
  tft.println("EMPIRE");

  tft.setTextSize(2);

  tft.setCursor(70, 140);
  tft.setTextColor(ST77XX_WHITE);
  tft.println("NOVO JOGO");

  tft.setCursor(80, 160);
  tft.setTextColor(ST77XX_WHITE);
  tft.println("RANKING");

  tft.setCursor(75, 180);
  tft.setTextColor(ST77XX_WHITE);
  tft.println("CREDITOS");

  tft.setCursor(100, 200);
  tft.setTextColor(ST77XX_WHITE);
  tft.println("SAIR");

  a = 1;
}

void cursorMenu(int teste, int teste2, int teste3) {

  if (digitalRead(2) == LOW) {

    tft.setTextSize(2);
    tft.setCursor(19, teste + option);
    tft.setTextColor(ST77XX_BLACK);
    tft.print("--");
    tft.setCursor(12, teste2 + option);
    tft.print("\t");
    tft.setTextSize(3);
    tft.setCursor(30, teste3 + option);
    tft.print(">");

    if (option != 0) {
      option -= 20;
    } else {
      option = 60;
    }

    tft.setTextSize(2);
    tft.setCursor(19, teste + option);
    tft.setTextColor(ST77XX_RED);
    tft.print("--");
    tft.setCursor(12, teste2 + option);
    tft.print("\t");
    tft.setTextSize(3);
    tft.setCursor(30, teste3 + option);
    tft.print(">");
  }

  if (digitalRead(5) == LOW) {

    tft.setTextSize(2);
    tft.setCursor(19, teste + option);
    tft.setTextColor(ST77XX_BLACK);
    tft.print("--");
    tft.setCursor(12, teste2 + option);
    tft.print("\t");
    tft.setTextSize(3);
    tft.setCursor(30, teste3 + option);
    tft.print(">");

    if (option != 60) {
      option += 20;
    } else {
      option = 0;
    }

    tft.setTextSize(2);
    tft.setCursor(19, teste + option);
    tft.setTextColor(ST77XX_RED);
    tft.print("--");
    tft.setCursor(12, teste2 + option);
    tft.print("\t");
    tft.setTextSize(3);
    tft.setCursor(30, teste3 + option);
    tft.print(">");
  }
}

void creditos() {

  tft.fillScreen(ST77XX_BLACK);
  moldura();
  tft.setTextWrap(true);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);

  tft.setCursor(91, 79);
  tft.println("Bruna");
  tft.setCursor(91, 109);
  tft.println("Homam");
  tft.setCursor(87, 139);
  tft.println("Emilio");
  tft.setCursor(80, 169);
  tft.println("Bouchra");
  tft.setCursor(80, 199);
  tft.println("Gustavo");
  delay(5000);
}

void opcoes() {

  if (digitalRead(4) == LOW) {
    delay(20);

    switch (option) {
      case 0:
        tft.fillScreen(ST77XX_BLACK);
        moldura();

        while (digitalRead(3) != LOW) {
          delay(50);
          tft.setTextColor(ST77XX_WHITE);
          tft.setCursor(65, 15);
          tft.println("Selecione");
          tft.setCursor(110, 37);
          tft.println("o");
          tft.setCursor(70, 57);
          tft.println("Joogador");
          tft.setTextColor(ST77XX_RED);
          tft.setCursor(65, 19);
          tft.println("_________");
          tft.setCursor(111, 41);
          tft.println("_");
          tft.setCursor(70, 61);
          tft.println("________");

          cursorMenu(110, 109, 107);

          tft.setTextWrap(true);
          tft.setTextSize(2);
          tft.setTextColor(ST77XX_WHITE);
          int b = 0;
          tft.setCursor(50, 110);
          tft.println("Novo Jogador");

          for (int a = 0; a < 3; a++) {
            if (strlen(rank[a].nome) != 0) {
              tft.setCursor(60, 130 + b);
              tft.println(rank[a].nome);
              b += 20;
            }
          }

          if (digitalRead(4) == 0) {
            switch (option) {
              case 0:
                {
                  char nome_jogador[4] = "AAA";
                  int i = 0, x = 0;
                  tft.fillScreen(ST77XX_BLACK);
                  moldura();

                  while (digitalRead(3) != LOW) {
                    tft.setCursor(50, 90);
                    tft.println("DIGITE SEU NOME");
                    tft.setTextColor(ST77XX_WHITE);
                    tft.setCursor(30 + x, 120);
                    tft.println(nome_jogador[i]);

                    if (digitalRead(2) == 0) {
                      tft.setTextColor(ST77XX_BLACK);
                      tft.setCursor(30 + x, 120);
                      tft.println(nome_jogador[i]);

                      if (nome_jogador[i] < 'Z') {
                        nome_jogador[i]++;
                      } else {
                        nome_jogador[i] -= 25;
                      }
                    }

                    if (digitalRead(5) == 0) {
                      tft.setTextColor(ST77XX_BLACK);
                      tft.setCursor(30 + x, 120);
                      tft.println(nome_jogador[i]);

                      if (nome_jogador[i] > 'A') {
                        nome_jogador[i]--;
                      } else {
                        nome_jogador[i] += 25;
                      }
                    }

                    if (digitalRead(4) == 0) {
                      if (i < 2) {
                        i++;
                        x += 15;
                      } else {

                      

                        x = -1;

                        for (i = 0; i < 3; i++) {
                          if (strcmp(rank[i].nome, nome_jogador) == 0) {
                            Serial.println("TEM NOME IGUAL");
                            tft.setCursor(30, 100);
                            tft.println("NOME EXISTENTE");

                            delay(1500);
                            x = i;
                            tft.fillScreen(ST77XX_BLACK);
                          }
                        }

                        if (x == -1) {
                          if (b != 0)
                          {
                            b /= 20;
                            if (b == 3) {
                              b = 2;
                            }
                          }
                          strcpy(rank[b].nome, nome_jogador);
                        }
                        for (i = 0; i < 3; i++) {
                          Serial.println(rank[i].nome);
                        }
                        break;
                      }
                    }
                    delay(100);
                  }

                  tft.fillScreen(ST77XX_BLACK);

                  moldura();
                  break;
                }

              case 20:
                {
                  tft.fillScreen(ST77XX_BLACK);
                  
                  jogadorSelecionado = 0;
                  jogoTeste1();
                  break;
                }

              case 40:
                {
                  Serial.println(option);
                  jogadorSelecionado = 1;
      tft.fillScreen(ST77XX_BLACK);
                  jogoTeste1();

                  break;
                }

              case 60:
                {
                  Serial.println(option);
                  jogadorSelecionado = 2;
      tft.fillScreen(ST77XX_BLACK);
                  jogoTeste1();

                  break;
                }
            }
          }
        }
        tft.fillScreen(ST77XX_BLACK);
        break;
      case 20:
        tft.fillScreen(ST77XX_BLACK);

        ranking();
        delay(1500);

        tft.fillScreen(ST77XX_BLACK);
        break;

      case 40:
        tft.fillScreen(ST77XX_BLACK);

        creditos();
        delay(1500);

        tft.fillScreen(ST77XX_BLACK);
        break;

      case 60:
        tft.fillScreen(ST77XX_BLACK);

        tft.setTextSize(2);
        tft.setCursor(70, 110);
        tft.setTextColor(ST77XX_WHITE);
        tft.println("ATE LOGO");
        delay(15000);
        tft.fillScreen(ST77XX_BLACK);
        delay(15000);
        break;
    }
  }
}



void jogoTeste1()
{
  //VARIAVEIS DE MOVIMENTAÇÃO E CONTROLE
  int selecionaMinerio = 1;
  int selecionaMinerio2 = 1;
  int selecionaMinerio3 = 1;
  int funcionaForja = 1;
  
 //variaveis para while 
 int SelecBronze = 1, SelecFerro = 1, SelecOuro = 1;
 int dentroBronze = 0, dentroFerro = 0, dentroOuro = 0;
 
 //armazenamento dos itens
  int bronze = 0, ferro = 0, ouro = 0;

  int espadaB = 0, escudoB = 0, armaduraB = 0;
  int espadaF = 0, escudoF = 0, armaduraF = 0;
  int espadaO = 0, escudoO = 0, armaduraO = 0;
  
//saida e condição de loop
  int sair = 0, forja = 0;
  int AreaMinerios = 1;

  minutos = 1;
  segundos = 60;
  m = 1;

  minutos2 = 2;
  segundos2 = 60;
  m2 = 1;



  #define ST77XX_BRONZE 0xEC62 
  #define ST77XX_FERRO 0xAD55

  while (digitalRead(3) != LOW){
    fim = millis();

    int sobe = digitalRead(2);
    int desce = digitalRead(5);

    if (fim < (comeco + 1))
    {
      if ((fim) > ((m * 1000)) && AreaMinerios == 1 )
      {
        tft.setCursor(150, 180);
        tft.println(minutos);
        tft.fillRect(180, 180, 50, 30, ST77XX_BLACK);
        tft.setCursor(180, 180);
        tft.println((segundos -= 1));
        m++;
        if (segundos == 0)
        {
          tft.setCursor(150, 180);
          tft.fillRect(150, 180, 30, 30, ST77XX_BLACK);
          tft.println(minutos -= 1 );
          segundos = 60;
        }
      }
      if (minutos == 0 && segundos == 1 || minutos == 0 && segundos == 0) {
        fim2 = millis();
        ///////////////////////////////////////////////////////////////////////////
        /////////////////////começo do segundo relogio////////////////////////////

        if (fim2 < (comeco2 + 1))
        {
          if ((fim2) > ((m2 * 1000)))
          {
            tft.setCursor(150, 180);
            tft.println(minutos2);
            tft.fillRect(180, 180, 50, 30, ST77XX_BLACK);
            tft.setCursor(180, 180);
            tft.println((segundos2 -= 1));
            m2++;
            
            if (segundos2 == 0)
            {
              tft.setCursor(150, 180);
              tft.fillRect(150, 180, 30, 30, ST77XX_BLACK);
              tft.println(minutos2 -= 1 );
              segundos2 = 60;
            }
            if(segundos2 == 1 && minutos2 == 0){

              int i, y;
              Ranking aux;

             for (i = 0; i < 3; i++) {
             for (y = i + 1; y < 3; y++) {
             if (rank[i].pontos < rank[y].pontos) {

             aux = rank[i];
             rank[i] = rank[y];
             rank[y] = aux;
             }
            }
           }
              int address = 0;

              EEPROM.put(address,rank);
              
            }//fim min segundos
            if (AreaMinerios == 1) {
              tft.fillRect(10, 10, 220, 110, ST77XX_BLACK);
            }
/////////////////////////SELECIONA FORJA///////////////////////////////////// 
          if(funcionaForja == 1){        
            if (sobe == 0)
            {
              Serial.println("teste1.1");
              delay(100);
              selecionaMinerio2 -= 1;
              if (selecionaMinerio2 <= 0) {
                selecionaMinerio2 = 4;
              }
            }

            if (desce == 0)
            {
              Serial.println("teste2.1");
              delay(100);
              selecionaMinerio2 += 1;
              if (selecionaMinerio2 >= 5) {
                selecionaMinerio2 = 1;
              }
            }
          }
                     
            tft.setTextSize(2);
            tft.setTextColor(ST77XX_WHITE);


//deixa a forja seleciona com amarelo
if (selecionaMinerio2 == 1) {

        tft.drawRect(30, 20, 40, 90, ST77XX_YELLOW);
        delay(200);

      } else if (selecionaMinerio2 == 2) {

        tft.drawRect(100, 20, 40, 90, ST77XX_YELLOW);
        delay(200);

      } else if (selecionaMinerio2 == 3) {

        tft.drawRect(170, 20, 40, 90, ST77XX_YELLOW);
        delay(200);

      } else if (selecionaMinerio2 == 4) {

        tft.drawRect(120, 130, 110, 35, ST77XX_YELLOW);
        delay(200);

      }
      sair = 0;
 //ENTRA NAS FORJAS
      if(digitalRead(4) == LOW){
       
         //while(sair == 0){

        switch(selecionaMinerio2){

            case 1: //CASE DO BRONZE
            tft.fillRect(10, 10, 220, 110, ST77XX_BLACK);
            tft.setCursor(200, 20);
            tft.println(espadaB);
            tft.setCursor(200, 50);
            tft.println(escudoB);
            tft.setCursor(200, 95);
            tft.println(armaduraB);
            
              while(sair == 0){

            if(digitalRead(3) == LOW){
                  tft.fillRect(10, 10, 220, 110, ST77XX_BLACK);
              int i, y;
              Ranking aux;

             for (i = 0; i < 3; i++) {
             for (y = i + 1; y < 3; y++) {
             if (rank[i].pontos < rank[y].pontos) {

             aux = rank[i];
             rank[i] = rank[y];
             rank[y] = aux;
             }
            }
           }
              int address = 0;

              EEPROM.put(address,rank);
                  
                  sair = 1;                  
             }
                  
                
            tft.setTextColor(ST77XX_BRONZE);
            funcionaForja = 1;
            

            tft.drawRect(25, 15, 190, 30, ST77XX_BRONZE);
            tft.drawRect(25, 50, 190, 30, ST77XX_BRONZE);
            tft.drawRect(25, 85, 190, 30, ST77XX_BRONZE);

            tft.setTextSize(2);
            tft.setTextColor(ST77XX_BRONZE);

             tft.setCursor(30, 20);
             tft.println("Espada  B");
             tft.setCursor(200, 20);
             tft.println(espadaB);
            
             tft.setCursor(30, 55);
             tft.println("Escudo  B");
             tft.setCursor(200, 55);
             tft.println(escudoB);
           
             tft.setCursor(30, 90);
             tft.println("Armadura  B");
             tft.setCursor(200, 90);
             tft.println(armaduraB);

             
////////////NAVEGA ENTRE OS ITENS DE BRONZE////////////////////
            Serial.println("desce");
            Serial.println(desce);
            Serial.println("sobe");
            Serial.println(sobe);
            sobe = digitalRead(2);
            desce = digitalRead(5);
            
            if (sobe == 0)
            {
              Serial.println("teste1.2 SOBE");
              delay(100);
              selecionaMinerio3 -= 1;
              if (selecionaMinerio3 <= 0) {
                selecionaMinerio3 = 4;
              }
            }

            if (desce == 0)
            {
              Serial.println("teste2.2 DESCE");
              delay(100);
              selecionaMinerio3 += 1;
              if (selecionaMinerio3 >= 5) {
                selecionaMinerio3 = 1;
              }
            } 

            if (selecionaMinerio3 == 1) {///espada
                tft.drawRect(25, 15, 190, 30, ST77XX_WHITE);
                delay(100);
                
                if(digitalRead(4) == LOW){
                   if(bronze >= 3){
                   espadaB += 1;
                   bronze -= 3;
                   Serial.println(espadaB);
                   Serial.println(bronze);
                   //printa os novos valores de bronze
                   tft.fillRect(70,140,30,20, ST77XX_BLACK);
                   tft.setTextColor(ST77XX_RED);
                   tft.setCursor(72, 140);
                   tft.println(bronze);
                   
                   //printa os novos valores de espadaB
                   tft.fillRect(170,20,40,20, ST77XX_BLACK);
                   tft.setTextColor(ST77XX_BRONZE);
                   tft.setCursor(200, 20);
                   tft.println(espadaB);
                   }//FIM IF SE FOR BRONZE >=3                  
                }//FIM SELEC EQUIPAMENTO
             
            } else if (selecionaMinerio3 == 2) {///escudo
                tft.drawRect(25, 50, 190, 30, ST77XX_WHITE);
                delay(100);

                if(digitalRead(4) == LOW){
                  if(bronze >=3){
                   escudoB += 1;
                   bronze -= 3;
                   Serial.println(escudoB);
                   Serial.println(bronze);
                   tft.fillRect(70,140,30,20, ST77XX_BLACK);
                   tft.setTextColor(ST77XX_RED);
                   tft.setCursor(72, 140);
                   tft.println(bronze);

                   tft.fillRect(170,55,40,20, ST77XX_BLACK);
                   tft.setTextColor(ST77XX_BRONZE);
                   tft.setCursor(200, 55);
                   tft.println(escudoB);
                  }
                }
                
            } else if (selecionaMinerio3 == 3) {///armadura
                tft.drawRect(25, 85, 190, 30, ST77XX_WHITE);
                delay(100);

                if(digitalRead(4) == LOW){
                  if(bronze >=3){
                   armaduraB += 1;
                   bronze -= 3;
                   Serial.println(armaduraB);
                   Serial.println(bronze);
                   tft.fillRect(70,140,30,20, ST77XX_BLACK);
                   tft.setTextColor(ST77XX_RED);
                   tft.setCursor(72, 140);
                   tft.println(bronze);

                   tft.fillRect(170,90,40,20, ST77XX_BLACK);
                   tft.setTextColor(ST77XX_BRONZE);
                   tft.setCursor(200, 90);
                   tft.println(armaduraB);
                  }
                }
                
            } else if (selecionaMinerio3 == 4) {//pedidos
                tft.drawRect(120, 130, 110, 35, ST77XX_YELLOW);
                //////////pedidos.
                if(digitalRead(4) == LOW){
                SelecBronze = 0;

                 tft.fillRect(10, 10, 220, 110, ST77XX_BLACK);
                 
                if(digitalRead(4) == LOW){//ENTRAR            
                while(SelecBronze == 0){//LOOPAR

                 tft.setTextColor(ST77XX_BRONZE);
                 tft.drawRect(25, 15, 190, 30, ST77XX_BRONZE);
                 tft.setCursor(30, 20);
                 tft.println(" 3=espa  2=escu");
                 
                 tft.drawRect(25, 50, 190, 30, ST77XX_BRONZE);
                 tft.setCursor(30, 55);
                 tft.println(" 3=escu  3=arma");
                 
                 tft.drawRect(25, 85, 190, 30, ST77XX_BRONZE);
                 tft.setCursor(30, 90);
                 tft.println(" 5=espa  3=arma");

                  if(digitalRead(3) == LOW){
                    tft.fillRect(10, 10, 220, 110, ST77XX_BLACK);
                    SelecBronze =1;
                  }//SAIR
                  sobe = digitalRead(2);
                  desce = digitalRead(5);

             if (sobe == 0)
            {
              Serial.println("teste1.2 SOBE");
              delay(100);
              dentroBronze -= 1;
              if (dentroBronze <= 0) {
                dentroBronze = 3;
              }
            }

            if (desce == 0)
            {
              Serial.println("teste2.2 DESCE");
              delay(100);
              dentroBronze += 1;
              if (dentroBronze >= 4) {
                dentroBronze = 1;
              }
            }//fim desce 

            if(dentroBronze == 1){//PEDIDO 1, 3 espadas, 2 escudos
              delay(100);
              tft.drawRect(25, 15, 190, 30, ST77XX_WHITE);
              
              if(espadaB >=3 && escudoB >=2){
                if(digitalRead(4) == LOW){
                  espadaB -=3;
                  escudoB -=2;
                  
                  pontos_jogador += 10;
                                 
                  rank[jogadorSelecionado].pontos = pontos_jogador;

                  tft.fillRect(138,210,80,20, ST77XX_BLACK);
                  tft.setCursor(140, 210);
                  tft.println(pontos_jogador);
                  
                  Serial.println("FOI CARALHOOOOOO");
                  tft.fillRect(70,140,30,20, ST77XX_BLACK);
                  tft.setTextColor(ST77XX_RED);
                  tft.setCursor(72, 140);
                  tft.println(bronze);                
                }//fim LOW 4               
              }//fim >=
              
            }else if(dentroBronze == 2){//PEDIDO 2, 3 escudos, 2 armaduras
              delay(100);
              tft.drawRect(25, 50, 190, 30, ST77XX_WHITE);
              
              if(escudoB >=3 && armaduraB >=2){
                if(digitalRead(4) == LOW){
                  escudoB -=3;
                  armaduraB -=2;
                  
                  pontos_jogador += 20;                  
                  rank[jogadorSelecionado].pontos = pontos_jogador;

                  tft.fillRect(138,210,80,20, ST77XX_BLACK);
                  tft.setCursor(140, 210);
                  tft.println(pontos_jogador);
                  
                  Serial.println("FOI CARALHOOOOOO2222");
                  tft.fillRect(70,140,30,20, ST77XX_BLACK);
                  tft.setTextColor(ST77XX_RED);
                  tft.setCursor(72, 140);
                  tft.println(bronze);                
                }//fim LOW 4               
              }//fim >=
                           
            }else if(dentroBronze == 3){//PEDIDO 3, 5espadas, 3armaduras
              delay(100);
              tft.drawRect(25, 85, 190, 30, ST77XX_WHITE);

              if(espadaB >=5 && armaduraB >=3){
                if(digitalRead(4) == LOW){
                  espadaB -=5;
                  armaduraB -=3;
                  
                  pontos_jogador += 30;
                  rank[jogadorSelecionado].pontos = pontos_jogador;

                  tft.fillRect(138,210,80,20, ST77XX_BLACK);
                  tft.setCursor(140, 210);
                  tft.println(pontos_jogador);
                  
                  Serial.println("FOI CARALHOOOOOO33333333");
                  tft.fillRect(70,140,30,20, ST77XX_BLACK);
                  tft.setTextColor(ST77XX_RED);
                  tft.setCursor(72, 140);
                  tft.println(bronze);                
                }//fim LOW 4               
              }//fim >=                         
            }//FIM ELSE IF                         
                }//FIM WHILE.
                }//FIM ENTRAR
                }//FIM ENTRAR PEDIDO                                
            }//FIM PEDIDOS
                }
                tft.fillRect(10, 10, 220, 110, ST77XX_BLACK);
            break;
/////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
            case 2://equipamento ferro

            tft.fillRect(10, 10, 220, 110, ST77XX_BLACK);
            tft.setCursor(200, 20);
            tft.println(espadaF);
            tft.setCursor(200, 50);
            tft.println(escudoF);
            tft.setCursor(200, 95);
            tft.println(armaduraF);
            
              while(sair == 0){

            if(digitalRead(3) == LOW){
                  tft.fillRect(10, 10, 220, 110, ST77XX_BLACK);
                  sair = 1;                  
             }
                  
                
            tft.setTextColor(ST77XX_FERRO);
            funcionaForja = 1;
            

            tft.drawRect(25, 15, 190, 30, ST77XX_FERRO);
            tft.drawRect(25, 50, 190, 30, ST77XX_FERRO);
            tft.drawRect(25, 85, 190, 30, ST77XX_FERRO);

            tft.setTextSize(2);
            tft.setTextColor(ST77XX_FERRO);

             tft.setCursor(30, 20);
             tft.println("Espada  F");
             tft.setCursor(200, 20);
             tft.println(espadaF);
            
             tft.setCursor(30, 55);
             tft.println("Escudo  F");
             tft.setCursor(200, 55);
             tft.println(escudoF);
           
             tft.setCursor(30, 90);
             tft.println("Armadura  F");
             tft.setCursor(200, 90);
             tft.println(armaduraF);

             
////////////NAVEGA ENTRE OS ITENS DE BRONZE////////////////////
            Serial.println("desce");
            Serial.println(desce);
            Serial.println("sobe");
            Serial.println(sobe);
            sobe = digitalRead(2);
            desce = digitalRead(5);
            
            if (sobe == 0)
            {
              Serial.println("teste1.2 SOBE");
              delay(100);
              selecionaMinerio3 -= 1;
              if (selecionaMinerio3 <= 0) {
                selecionaMinerio3 = 4;
              }
            }

            if (desce == 0)
            {
              Serial.println("teste2.2 DESCE");
              delay(100);
              selecionaMinerio3 += 1;
              if (selecionaMinerio3 >= 5) {
                selecionaMinerio3 = 1;
              }
            } 

            if (selecionaMinerio3 == 1) {///espada
                tft.drawRect(25, 15, 190, 30, ST77XX_WHITE);
                delay(100);
                
                if(digitalRead(4) == LOW){
                   if(ferro >= 3){
                   espadaF += 1;
                   ferro -= 3;
                   
                   Serial.println(espadaF);
                   Serial.println(ferro);
                   //printa os novos valores de ferro
                   tft.fillRect(70,170,40,20, ST77XX_BLACK);
                   tft.setTextColor(ST77XX_RED);
                   tft.setCursor(72, 170);
                   tft.println(ferro);
                   
                   //printa os novos valores de espadaB
                   tft.fillRect(170,20,40,20, ST77XX_BLACK);
                   tft.setTextColor(ST77XX_FERRO);
                   tft.setCursor(200, 20);
                   tft.println(espadaF);
                   }//FIM IF SE FOR FERRO >=3                  
                }//FIM SELEC EQUIPAMENTO
             
            } else if (selecionaMinerio3 == 2) {///escudo
                tft.drawRect(25, 50, 190, 30, ST77XX_WHITE);
                delay(100);

                if(digitalRead(4) == LOW){
                  if(ferro >=3){
                   escudoF += 1;
                   ferro -= 3;
                   Serial.println(escudoF);
                   Serial.println(ferro);
                   tft.fillRect(70,170,40,20, ST77XX_BLACK);
                   tft.setTextColor(ST77XX_RED);
                   tft.setCursor(72, 170);
                   tft.println(ferro);

                   tft.fillRect(170,55,40,20, ST77XX_BLACK);
                   tft.setTextColor(ST77XX_FERRO);
                   tft.setCursor(200, 55);
                   tft.println(escudoF);
                  }
                }
                
            } else if (selecionaMinerio3 == 3) {///armadura
                tft.drawRect(25, 85, 190, 30, ST77XX_WHITE);
                delay(100);

                if(digitalRead(4) == LOW){
                  if(ferro >=3){
                   armaduraF += 1;
                   ferro -= 3;
                   Serial.println(armaduraF);
                   Serial.println(ferro);
                   tft.fillRect(70,170,40,20, ST77XX_BLACK);
                   tft.setTextColor(ST77XX_RED);
                   tft.setCursor(72, 170);
                   tft.println(ferro);

                   tft.fillRect(170,90,40,20, ST77XX_BLACK);
                   tft.setTextColor(ST77XX_FERRO);
                   tft.setCursor(200, 90);
                   tft.println(armaduraF);
                  }
                }
///////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////                
            } else if (selecionaMinerio3 == 4) {//pedidos
              tft.drawRect(120, 130, 110, 35, ST77XX_YELLOW);
              //////////pedidos.
              if(digitalRead(4) == LOW){
                SelecFerro = 0;
                tft.fillRect(10, 10, 220, 110, ST77XX_BLACK);
                if(digitalRead(4) == LOW){
                  while(SelecFerro == 0){

                 tft.setTextColor(ST77XX_FERRO);
                 tft.drawRect(25, 15, 190, 30, ST77XX_FERRO);
                 tft.setCursor(30, 20);
                 tft.println(" 3=espa  2=escu");
                 
                 tft.drawRect(25, 50, 190, 30, ST77XX_FERRO);
                 tft.setCursor(30, 55);
                 tft.println(" 3=escu  3=arma");
                 
                 tft.drawRect(25, 85, 190, 30, ST77XX_FERRO);
                 tft.setCursor(30, 90);
                 tft.println(" 5=espa  3=arma");

                 if(digitalRead(3) == LOW){
                    tft.fillRect(10, 10, 220, 110, ST77XX_BLACK);
                    SelecFerro =1;
                  }//SAIR

                  sobe = digitalRead(2);
                  desce = digitalRead(5);

                  if (sobe == 0)
            {
              Serial.println("teste1.2 SOBE");
              delay(100);
              dentroFerro -= 1;
              if (dentroFerro <= 0) {
                dentroFerro = 3;
              }
            }

            if (desce == 0)
            {
              Serial.println("teste2.2 DESCE");
              delay(100);
              dentroFerro += 1;
              if (dentroFerro >= 4) {
                dentroFerro = 1;
              }
            }//fim desce

            if(dentroFerro == 1){//PEDIDO 1, 3 espadas, 2 escudos
              delay(200);
              tft.drawRect(25, 15, 190, 30, ST77XX_WHITE);
              
              if(espadaF >=3 && escudoF >=2){
                if(digitalRead(4) == LOW){
                  espadaF -=3;
                  escudoF -=2;

                  pontos_jogador += 10;
                                 
                  rank[jogadorSelecionado].pontos = pontos_jogador;

                  tft.fillRect(138,210,80,20, ST77XX_BLACK);
                  tft.setCursor(140, 210);
                  tft.println(pontos_jogador);
                  
                  Serial.println("FOI CARALHOOOOOO");
                  tft.fillRect(70,140,30,20, ST77XX_BLACK);
                  tft.setTextColor(ST77XX_RED);
                  tft.setCursor(72, 140);
                  tft.println(ferro);                
                }//fim LOW 4               
              }//fim >=
            }else if(dentroFerro == 2){//PEDIDO 2, 3 escudos, 2 armaduras
              delay(200);
              tft.drawRect(25, 50, 190, 30, ST77XX_WHITE);
              
              if(escudoF >=3 && armaduraF >=2){
                if(digitalRead(4) == LOW){
                  escudoF -=3;
                  armaduraF -=2;

                  pontos_jogador += 20;
                                 
                  rank[jogadorSelecionado].pontos = pontos_jogador;

                  tft.fillRect(138,210,80,20, ST77XX_BLACK);
                  tft.setCursor(140, 210);
                  tft.println(pontos_jogador);
                  
                  Serial.println("FOI CARALHOOOOOO2222");
                  tft.fillRect(70,140,30,20, ST77XX_BLACK);
                  tft.setTextColor(ST77XX_RED);
                  tft.setCursor(72, 140);
                  tft.println(ferro);                
                }//fim LOW 4               
              }//fim >=
                           
            }else if(dentroFerro == 3){//PEDIDO 3, 5espadas, 3armaduras
              delay(200);
              tft.drawRect(25, 85, 190, 30, ST77XX_WHITE);

              if(espadaF >=5 && armaduraF >=3){
                if(digitalRead(4) == LOW){
                  espadaF -=5;
                  armaduraF -=3;

                  pontos_jogador += 10;
                                 
                  rank[jogadorSelecionado].pontos = pontos_jogador;

                  tft.fillRect(138,210,80,20, ST77XX_BLACK);
                  tft.setCursor(140, 210);
                  tft.println(pontos_jogador);
                  
                  Serial.println("FOI CARALHOOOOOO33333333");
                  tft.fillRect(70,140,30,20, ST77XX_BLACK);
                  tft.setTextColor(ST77XX_RED);
                  tft.setCursor(72, 140);
                  tft.println(ferro);                
                }//fim LOW 4               
              }//fim >=                         
            }//FIM ELSE IF                                            
                  }//FIM WHILE                  
                }//FIM FOR SELCIONA                              
              }//FIM ENTRAR NO PEDIDO FERRO                               
            }//FIM ELSE IF
////////////////////////////////////////////////////////////////////////////////////////////////////
                }//FIM WHILE SAIR
                tft.fillRect(10, 10, 220, 110, ST77XX_BLACK);

            break;

            case 3://equipamento ouro

            tft.fillRect(10, 10, 220, 110, ST77XX_BLACK);
            tft.setCursor(200, 20);
            tft.println(espadaO);
            tft.setCursor(200, 50);
            tft.println(escudoO);
            tft.setCursor(200, 95);
            tft.println(armaduraO);
            
              while(sair == 0){

            if(digitalRead(3) == LOW){
                  tft.fillRect(10, 10, 220, 110, ST77XX_BLACK);
                  sair = 1;                  
             }
                  
                
            tft.setTextColor(ST77XX_YELLOW);
            funcionaForja = 1;
            

            tft.drawRect(25, 15, 190, 30, ST77XX_YELLOW);
            tft.drawRect(25, 50, 190, 30, ST77XX_YELLOW);
            tft.drawRect(25, 85, 190, 30, ST77XX_YELLOW);

            tft.setTextSize(2);
            tft.setTextColor(ST77XX_YELLOW);

             tft.setCursor(30, 20);
             tft.println("Espada  O");
             tft.setCursor(200, 20);
             tft.println(espadaO);
            
             tft.setCursor(30, 55);
             tft.println("Escudo  O");
             tft.setCursor(200, 55);
             tft.println(escudoO);
           
             tft.setCursor(30, 90);
             tft.println("Armadura  O");
             tft.setCursor(200, 90);
             tft.println(armaduraO);

             
////////////NAVEGA ENTRE OS ITENS DE BRONZE////////////////////
            Serial.println("desce");
            Serial.println(desce);
            Serial.println("sobe");
            Serial.println(sobe);
            sobe = digitalRead(2);
            desce = digitalRead(5);
            
            if (sobe == 0)
            {
              Serial.println("teste1.2 SOBE");
              delay(100);
              selecionaMinerio3 -= 1;
              if (selecionaMinerio3 <= 0) {
                selecionaMinerio3 = 4;
              }
            }

            if (desce == 0)
            {
              Serial.println("teste2.2 DESCE");
              delay(100);
              selecionaMinerio3 += 1;
              if (selecionaMinerio3 >= 5) {
                selecionaMinerio3 = 1;
              }
            } 

            if (selecionaMinerio3 == 1) {///espada
                tft.drawRect(25, 15, 190, 30, ST77XX_WHITE);
                delay(100);
                
                if(digitalRead(4) == LOW){
                   if(ouro >= 3){
                   espadaO += 1;
                   ouro -= 3;
                   Serial.println(espadaO);
                   Serial.println(ouro);
                   //printa os novos valores de ferro
                   tft.fillRect(70,200,40,20, ST77XX_BLACK);
                   tft.setTextColor(ST77XX_RED);
                   tft.setCursor(72, 200);
                   tft.println(ouro);
                   
                   //printa os novos valores de espadaB
                   tft.fillRect(170,20,40,20, ST77XX_BLACK);
                   tft.setTextColor(ST77XX_YELLOW);
                   tft.setCursor(200, 20);
                   tft.println(espadaO);
                   }//FIM IF SE FOR OURO >=3                  
                }//FIM SELEC EQUIPAMENTO
             
            } else if (selecionaMinerio3 == 2) {///escudo
                tft.drawRect(25, 50, 190, 30, ST77XX_WHITE);
                delay(100);

                if(digitalRead(4) == LOW){
                  if(ouro >=3){
                   escudoO += 1;
                   ouro -= 3;
                   Serial.println(escudoO);
                   Serial.println(ouro);
                   tft.fillRect(70,200,40,20, ST77XX_BLACK);
                   tft.setTextColor(ST77XX_RED);
                   tft.setCursor(72, 200);
                   tft.println(ouro);

                   tft.fillRect(170,55,40,20, ST77XX_BLACK);
                   tft.setTextColor(ST77XX_FERRO);
                   tft.setCursor(200, 55);
                   tft.println(escudoO);
                  }
                }
                
            } else if (selecionaMinerio3 == 3) {///armadura
                tft.drawRect(25, 85, 190, 30, ST77XX_WHITE);
                delay(100);

                if(digitalRead(4) == LOW){
                  if(ouro >=3){
                   armaduraO += 1;
                   ouro -= 3;
                   Serial.println(armaduraO);
                   Serial.println(ouro);
                   tft.fillRect(70,200,40,20, ST77XX_BLACK);
                   tft.setTextColor(ST77XX_RED);
                   tft.setCursor(72, 200);
                   tft.println(ouro);

                   tft.fillRect(170,90,40,20, ST77XX_BLACK);
                   tft.setTextColor(ST77XX_YELLOW);
                   tft.setCursor(200, 90);
                   tft.println(armaduraO);
                  }
                }
                
            } else if (selecionaMinerio3 == 4) {//pedidos
                tft.drawRect(120, 130, 110, 35, ST77XX_YELLOW);
                //////////pedidos.
                if(digitalRead(4) == LOW){
                  SelecOuro = 0;
                  tft.fillRect(10, 10, 220, 110, ST77XX_BLACK);
                   if(digitalRead(4) == LOW){
                    while(SelecOuro == 0){
                      tft.setTextColor(ST77XX_YELLOW);
                      tft.drawRect(25, 15, 190, 30, ST77XX_YELLOW);
                      tft.setCursor(30, 20);
                      tft.println(" 3=espa  2=escu");
                 
                      tft.drawRect(25, 50, 190, 30, ST77XX_YELLOW);
                      tft.setCursor(30, 55);
                      tft.println(" 3=escu  3=arma");
                 
                      tft.drawRect(25, 85, 190, 30, ST77XX_YELLOW);
                      tft.setCursor(30, 90);
                      tft.println(" 5=espa  3=arma");
                      
                      if(digitalRead(3) == LOW){
                    tft.fillRect(10, 10, 220, 110, ST77XX_BLACK);
                    SelecOuro =1;
                  }//SAIR
                  sobe = digitalRead(2);
                  desce = digitalRead(5);

                  if (sobe == 0)
            {
              Serial.println("teste1.2 SOBE");
              delay(100);
              dentroOuro -= 1;
              if (dentroOuro <= 0) {
                dentroOuro = 3;
              }
            }

            if (desce == 0)
            {
              Serial.println("teste2.2 DESCE");
              delay(100);
              dentroOuro += 1;
              if (dentroOuro >= 4) {
                dentroOuro = 1;
              }
            }//fim desce 

             if(dentroFerro == 1){//PEDIDO 1, 3 espadas, 2 escudos
              delay(200);
              tft.drawRect(25, 15, 190, 30, ST77XX_WHITE);
              
              if(espadaO >=3 && escudoO >=2){
                if(digitalRead(4) == LOW){
                  espadaO -=3;
                  escudoO -=2;

                  pontos_jogador += 10;
                                 
                  rank[jogadorSelecionado].pontos = pontos_jogador;

                  tft.fillRect(138,210,80,20, ST77XX_BLACK);
                  tft.setCursor(140, 210);
                  tft.println(pontos_jogador);
                 
                  Serial.println("FOI CARALHOOOOOO");
                  tft.fillRect(70,140,30,20, ST77XX_BLACK);
                  tft.setTextColor(ST77XX_RED);
                  tft.setCursor(72, 140);
                  tft.println(ouro);                
                }//fim LOW 4               
              }//fim >=             
             }else if(dentroOuro == 2){//PEDIDO 2, 3 escudos, 2 armaduras
              delay(200);
              tft.drawRect(25, 50, 190, 30, ST77XX_WHITE);
              
              if(escudoF >=3 && armaduraF >=2){
                if(digitalRead(4) == LOW){
                  escudoO -=3;
                  armaduraO -=2;

                  pontos_jogador += 10;
                                 
                  rank[jogadorSelecionado].pontos = pontos_jogador;

                  tft.fillRect(138,210,80,20, ST77XX_BLACK);
                  tft.setCursor(140, 210);
                  tft.println(pontos_jogador);
                  
                  Serial.println("FOI CARALHOOOOOO2222");
                  tft.fillRect(70,140,30,20, ST77XX_BLACK);
                  tft.setTextColor(ST77XX_RED);
                  tft.setCursor(72, 140);
                  tft.println(ouro);                
                }//fim LOW 4               
              }//fim >=
                           
            }else if(dentroOuro == 3){//PEDIDO 3, 5espadas, 3armaduras
              delay(200);
              tft.drawRect(25, 85, 190, 30, ST77XX_WHITE);

              if(espadaO >=5 && armaduraO >=3){
                if(digitalRead(4) == LOW){
                  espadaO -=5;
                  armaduraO -=3;

                  pontos_jogador += 10;
                                 
                  rank[jogadorSelecionado].pontos = pontos_jogador;

                  tft.fillRect(138,210,80,20, ST77XX_BLACK);
                  tft.setCursor(140, 210);
                  tft.println(pontos_jogador);
                  
                  Serial.println("FOI CARALHOOOOOO33333333");
                  tft.fillRect(70,140,30,20, ST77XX_BLACK);
                  tft.setTextColor(ST77XX_RED);
                  tft.setCursor(72, 140);
                  tft.println(ouro);                
                }//fim LOW 4               
              }//fim >=                         
            }//FIM ELSE IF               
                    }//FIM WHILE SELEC OURO                   
                   }//FIM FOR ENTRAR                  
                }//FIM ENTRAR PEDIDOS
                
            }//else pedidos
                }//while sair
                tft.fillRect(10, 10, 220, 110, ST77XX_BLACK);

            break;
           
            case 4://pedidos

            break;

            if(digitalRead(2) == LOW && digitalRead(5) == LOW){
              sair = 1;
            }


         }//fim switch
        //}//fim loop while sair == 0
      }//fim Entra na forja

        
            AreaMinerios = 2;
            tft.drawRect(10, 10, 220, 110, ST77XX_WHITE);
            
            ///////////////////////////////
            /////////JOGO PARTE FORJA//////
            ///////////////////////////////
            //borda
            tft.drawRect(0, 0, 240, 240, ST77XX_WHITE);

            //grande retangulo
            tft.drawRect(10, 10, 220, 110, ST77XX_WHITE);

            //retangulo dos mierios
            tft.drawRect(30, 20, 40, 90, ST77XX_RED);
            tft.drawRect(100, 20, 40, 90, ST77XX_RED);
            tft.drawRect(170, 20, 40, 90, ST77XX_RED);

            //TEXTOS DOS MINERIOS

            tft.setTextSize(2);
            tft.setTextColor(ST77XX_WHITE);

            tft.setCursor(45, 25);
            tft.println("B");
            tft.setCursor(45, 42);
            tft.println("R");
            tft.setCursor(45, 59);
            tft.println("N");
            tft.setCursor(45, 74);
            tft.println("Z");
            tft.setCursor(45, 89);
            tft.println("E");

            tft.setCursor(115, 25);
            tft.println("F");
            tft.setCursor(115, 42);
            tft.println("E");
            tft.setCursor(115, 59);
            tft.println("R");
            tft.setCursor(115, 74);
            tft.println("R");
            tft.setCursor(115, 89);
            tft.println("O");

            tft.setCursor(185, 25);
            tft.println("O");
            tft.setCursor(185, 45);
            tft.println("U");
            tft.setCursor(185, 65);
            tft.println("R");
            tft.setCursor(185, 85);
            tft.println("O");
////////////////////////////////////////////////////////////////////////////////////            
///////////////////////////////////////////////////////////////////////////////////
              
          }//fim verifica 1s 2
        }//fim relogio2
      }//fim if min && seg
    }//fim verifica 1s
    //fim relogio

    //Condição para continuar na Area de Minerios
    if (AreaMinerios == 1) {
      ///////////////////////////////////////////////////////
      ////////andar pelos minerios///////////////////////////
      if (sobe == 0)
      {
        Serial.println("teste1");
        delay(100);
        selecionaMinerio -= 1;
        if (selecionaMinerio <= 0) {
          selecionaMinerio = 4;
        }
      }

      if (desce == 0)
      {
        Serial.println("teste2");
        delay(100);
        selecionaMinerio += 1;
        if (selecionaMinerio >= 5) {
          selecionaMinerio = 1;
        }
      }
      /////////////////////////////////////////////////////////////
      /////////////////////////////////////////////////////////////
      tft.setTextSize(2);
      tft.setTextColor(ST77XX_WHITE);

      if (selecionaMinerio == 1) {

        tft.drawRect(30, 40, 40, 50, ST77XX_YELLOW);
        delay(200);
        tft.setCursor(45, 55);
        tft.println("B");

      } else if (selecionaMinerio == 2) {

        tft.drawRect(100, 40, 40, 50, ST77XX_YELLOW);
        delay(200);
        tft.setCursor(115, 55);
        tft.println("F");

      } else if (selecionaMinerio == 3) {

        tft.drawRect(170, 40, 40, 50, ST77XX_YELLOW);
        delay(200);
        tft.setCursor(185, 55);
        tft.println("O");

      } else if (selecionaMinerio == 4) {

        tft.drawRect(120, 130, 110, 35, ST77XX_YELLOW);
        delay(200);

      }

      ////////////////////////////////////////////////////
      ///////SELECIONAR OS MINERIOS////////////////////////
      if (digitalRead(4) == LOW) {

        switch (selecionaMinerio) {

          case 1://minerio de bronze coleta
            delay(100);
            tft.setTextColor(ST77XX_RED);
            tft.setCursor(20, 140);
            tft.println("B =");
            tft.setTextColor(ST77XX_BLACK);
            tft.setCursor(72, 140);
            tft.println(bronze);
            bronze += 1;
            break;

          case 2://minerio de ferro coleta
            delay(100);
            tft.setTextColor(ST77XX_RED);
            tft.setCursor(20, 170);
            tft.println("F =");
            tft.setTextColor(ST77XX_BLACK);
            tft.setCursor(72, 170);
            tft.println(ferro);
            ferro += 1;
            break;

          case 3://minerio de ouro coelta
            delay(100);
            tft.setTextColor(ST77XX_RED);
            tft.setCursor(20, 200);
            tft.println("O =");
            tft.setTextColor(ST77XX_BLACK);
            tft.setCursor(72, 200);
            tft.println(ouro);
            ouro += 1;
            break;

          case 4://area de pedidos.
            delay(40);

            break;
        }//fim switch Minerios
      }//fim seleciona

      //Minerios
      tft.drawRect(10, 10, 220, 110, ST77XX_WHITE);
      tft.drawRect(30, 40, 40, 50, ST77XX_RED);
      tft.setCursor(45, 55);
      tft.println("B");
      tft.drawRect(100, 40, 40, 50, ST77XX_RED);
      tft.setCursor(115, 55);
      tft.println("F");
      tft.drawRect(170, 40, 40, 50, ST77XX_RED);
      tft.setCursor(185, 55);
      tft.println("O");

    }//fim area de minerios

    //Caixa de armazenamento
    tft.drawRect(10, 130, 100, 100, ST77XX_WHITE);
    tft.setCursor(20, 140);
    tft.println("B =");
    tft.setCursor(20, 170);
    tft.println("F =");
    tft.setCursor(20, 200);
    tft.println("O =");

    tft.setTextColor(ST77XX_RED);
    tft.setCursor(72, 140);
    tft.println(bronze);
    tft.setCursor(72, 170);
    tft.println(ferro);
    tft.setCursor(72, 200);
    tft.println(ouro);

    tft.drawRect(120, 130, 110, 35, ST77XX_WHITE);
    tft.setTextColor(ST77XX_WHITE);
    tft.setCursor(132, 140);
    tft.println("PEDIDOS");
    tft.setCursor(140, 210);
    tft.println(pontos_jogador);

    //teste selecionado

  }//fim while != LOW loop
}//fim void JogoTeste1


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  //----- BOTOES -----
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);

  // if the display has CS pin try with SPI_MODE0
  tft.init(240, 240, SPI_MODE2);  // Init ST7789 display 240x240 pixel
  // if the screen is flipped, remove this command
  tft.setRotation(2);
  Serial.println(F("Initialized"));
  uint16_t time = millis();
  tft.fillScreen(ST77XX_BLACK);
  time = millis() - time;
  delay(500);
  // put your main code here, to run repeatedly:
  
  /*
  for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, 0);
  }
  */

  int address = 0;

  EEPROM.get(address,rank);
  
}

void loop() {
  cursorMenu(140, 139, 137);
  menuDisplay();
  delay(90);
  opcoes();
}
