#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define filas 21 //y
#define columnas 21 //x
#define MAXCOLS 31
#define MAXFILAS 20
struct fantasma{
int fx;
int fy;
int dirf;
int c;
int d;
}fantasmas[5];
struct mapA{
char mapa1[filas][columnas];
}mapas[3];
int px=13,py=14,dir, direccion;
int comida;
int vida=3;
using namespace std;
  COORD coord={0,0};
 void gotoxy(int x,int y)
 {coord.X=x; coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
void pintar_mapa(struct mapA e[3]){
 for(int x =0;x<filas;x++){
 for(int y=0;y<columnas;y++){
 if(e[0].mapa1[x][y]=='x'){gotoxy(x,y);cout<<"*";}
 if(e[0].mapa1[x][y]==' '){gotoxy(x,y);cout<<" ";}
 if(e[0].mapa1[x][y]=='o'){gotoxy(x,y);cout<<"$";
   }
  }
 }
}
  void mover_pacman(struct mapA e[3]){
    if(dir==1){if(e[0].mapa1[px+1][py]!='x')px++;else dir=5; }
    if(dir==2){if(e[0].mapa1[px-1][py]!='x')px--;else dir=5; }
    if(dir==3){if(e[0].mapa1[px][py+1]!='x')py++;else dir=5; }
    if(dir==4){if(e[0].mapa1[px][py-1]!='x')py--;else dir=5; }
 }
   void dificultad_mapa(struct mapA e[3],struct fantasma r[5]){
for(int x=0;x<5;x++){
 if(e[0].mapa1[r[x].fx][r[x].fy]=='@'){r[x].dirf=(1 + rand() % 4);}
}
 }
  void choque_pacman(struct fantasma r[5]){
      for(int x=0;x<5;x++){
 if(r[x].fx==px&&r[x].fy==py){
gotoxy(px,py);cout<<" ";
gotoxy(r[x].fx,r[x].fy);cout<<" ";
 px=13,py=14,r[x].fx=4,r[x].fy=12;
 gotoxy(60,23);cout<<"GAME OVER";
  Sleep(1500);
 gotoxy(60,23);cout<<"         ";vida--;
 }
      }
      for(int x=5;x>0;x--){
 if(r[x].fx==px&&r[x].fy==py){
gotoxy(px,py);cout<<" ";
gotoxy(r[x].fx,r[x].fy);cout<<" ";
 px=13,py=14,r[x].fx=4,r[x].fy=12;
 gotoxy(60,23);cout<<"GAME OVER";
  Sleep(1500);
 gotoxy(60,23);cout<<"         ";vida--;
   }
  }
 }
   void comer_pacman(){
 if(mapas[0].mapa1[px][py]=='o'){
    mapas[0].mapa1[px][py]=' ';
 comida++;
 }}
  void mover_fantasmas(struct fantasma r[5],struct mapA e[3]){
     srand(time(NULL));
     for(int x=0;x<5;x++){
if(r[x].dirf==1){if(e[0].mapa1[r[x].fx+1][r[x].fy]!='x') r[x].fx++;
else r[x].dirf=(1 + rand() % 4);}
if(r[x].dirf==2){if(e[0].mapa1[r[x].fx-1][r[x].fy]!='x')r[x].fx--;
else r[x].dirf=(1 + rand() % 4);}
if(r[x].dirf==3){if(e[0].mapa1[r[x].fx][r[x].fy+1]!='x')r[x].fy++;
else r[x].dirf=(1 + rand() % 4);}
if(r[x].dirf==4){if(e[0].mapa1[r[x].fx][r[x].fy-1]!='x')r[x].fy--;
else r[x].dirf=(1 + rand() % 4);}
     }
 }
 void tunel( struct fantasma r[5]){
 if(px==10&&py==0){
     gotoxy(px,py);cout<<" ";
 px=10;py=20;
 }else if(px==10&&py==20){
     gotoxy(px,py);cout<<" ";
 px=10;py=0;
 }
  for(int x=0;x<5;x++){
  if(r[x].fx==10&&r[x].fy==0){
     gotoxy(r[x].fx,r[x].fy);cout<<" ";
 r[x].fx=10;r[x].fy=20;
 }else if(r[x].fx==10&&r[x].fy==20){
     gotoxy(r[x].fx,r[x].fy);cout<<" ";
 r[x].fx=10;r[x].fy=0;
 }
  }
  }
  void reposicion(struct mapA e[3],struct fantasma r[5]){
for(int x=0;x<5;x++){
if(e[0].mapa1[r[x].fx][r[x].fy]=='o'){
r[x].c=r[x].fx;
r[x].d=r[x].fy;
}
  }
  }
  void reposicion_2(struct mapA e[3],struct fantasma r[5]){
      for(int x=0;x<5;x++){
if(e[0].mapa1[r[x].c][r[x].d]=='o'){
gotoxy(r[x].c,r[x].d);cout<<"$";
}
}
  }
void pintar_cuerpos(struct fantasma r[5]){
    gotoxy(px,py);cout<<"C";
    for(int x=0;x<5;x++){
    gotoxy(r[x].fx,r[x].fy);cout<<"F";
    }
}
void borra_cuerpos(struct fantasma r[5]){
gotoxy(px,py);cout<<" ";
for(int x=0;x<5;x++){
gotoxy(r[x].fx,r[x].fy);cout<<" ";
}
}
void direccion_pacman(){
if(kbhit()){
    direccion=getch();
switch(direccion){
case 'd':
dir=1;
break;
case 'a':
dir=2;
break;
case 's':
dir=3;
break;
case 'w':
dir=4;
break;
case 'D':
dir=1;
break;
case 'A':
dir=2;
break;
case 'S':
dir=3;
break;
case 'W':
dir=4;
break;}}
}

int main(){
   mapas[0].mapa1={{'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
                  {'x',' ','o',' ',' ',' ','o',' ',' ','@',' ',' ',' ',' ','o',' ',' ',' ','o',' ','x'},
                  {'x',' ','x','x','x','x',' ','x','x',' ','x','x',' ','x','x','x',' ','x','x',' ','x'},
                  {'x',' ','x','x','x','x',' ','x','x',' ','x','x',' ','x','x','x',' ','x','x',' ','x'},
                  {'x',' ','x','x','x','x',' ','x','x',' ','x','x',' ','x','x','x',' ','x','x',' ','x'},
                  {'x',' ','x','x','x','x',' ','x','x','o','x','x',' ','x','x','x',' ','x','x',' ','x'},
                  {'x','o',' ',' ',' ',' ',' ','x','x',' ','x','x',' ',' ',' ',' ','@',' ',' ','o','x'},
                  {'x',' ','x','x','x','x','x','x','x',' ','x','x','x','x','x','x','x','x','x',' ','x'},
                  {'x',' ','x','x','x','x','@',' ',' ',' ',' ',' ',' ','x','x','x','x','x','x',' ','x'},
                  {'x',' ','x','x','x','x',' ',' ','o','o','o',' ',' ','x','x','x','x','x','x',' ','x'},
                  {' ','@',' ',' ','o',' ',' ',' ','o','@','o',' ',' ',' ','o',' ',' ',' ',' ','@',' '},
                  {'x',' ','x','x',' ','x',' ',' ','o','o','o',' ',' ','x',' ','x','x','x','x',' ','x'},
                  {'x',' ','x','x',' ','x',' ',' ',' ',' ',' ',' ','@','x',' ','x','x','x','x',' ','x'},
                  {'x',' ','x','x',' ','x','x','x','x',' ','x','x','x','x',' ','x','x','x','x',' ','x'},
                  {'x',' ','x','x',' ','x','x','x','x',' ','x','x','x','x',' ','x','x','x','x',' ','x'},
                  {'x',' ','x','x',' ','@',' ',' ',' ','o',' ',' ',' ','@',' ','x','x','x','x',' ','x'},
                  {'x',' ','x','x',' ','x','x','x','x',' ','x','x','x','x',' ','x','x','x','x',' ','x'},
                  {'x',' ','x','x',' ','x','x','x','x',' ','x','x','x','x',' ','x','x','x','x',' ','x'},
                  {'x',' ','x','x','o','x','x','x','x',' ','x','x','x','x','o','x','x','x','x',' ','x'},
                  {'x','o',' ',' ','@',' ',' ',' ','o','@','o',' ',' ',' ','@',' ',' ',' ',' ','o','x'},
                  {'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'}};
/*mapas[1].mapa1={
  {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
  {'X',' ',' ','o',' ','|','o',' ','o',' ','o',' ','X','X','X','X','X',' ','o',' ','o',' ','o','|',' ','o',' ',' ','X'},
  {'X',' ','X','X','X',' ','X','X','X','X','X',' ','X','X','X','X','X',' ','X','X','X','X','X',' ','X','X','X',' ','X'},
  {'X','o','X','X','X',' ','X','X','X','X','X',' ','X','X','X','X','X',' ','X','X','X','X','X',' ','X','X','X','o','X'},
  {'X',' ',' ',' ',' ',' ',' ','o','|','o',' ',' ',' ','o',' ','o',' ',' ',' ','o','|','o',' ',' ',' ',' ',' ',' ','X'},
  {'X','o','X','X','X','o','X','X',' ','X','X','X','X','X','X','X','X','X','X','X',' ','X','X','o','X','X','X','o','X'},
  {'X',' ',' ',' ',' ','|','X','X',' ',' ',' ',' ','|','X','X','X','|',' ',' ',' ',' ','X','X',' ',' ',' ',' ',' ','X'},
  {'X','o','X','X','X','o','X','X','X','X','X','X',' ','X','X','X',' ','X','X','X','X','X','X','o','X','X','X','o','X'},
  {'X',' ','X','X','X','o','X','X',' ','o','o','o','|','o','o','o','|','o','o','o',' ','X','X','o','X','X','X',' ','X'},
  {' ','o',' ',' ',' ','|','X','X',' ','X','X','X','X','X','X','X','X','X','X','X',' ','X','X','|',' ',' ',' ','o',' '},
  {'X',' ','X','X','X','o','X','X',' ','X','X','X','X','X','X','X','X','X','X','X',' ','X','X','o','X','X','X',' ','X'},
  {'X','o','X','X','X','o','X','X',' ','o','o',' ','|','o','o','o','|','o','o','o',' ','X','X','o','X','X','X','o','X'},
  {'X',' ','X','X','X','o','X','X','X','X','X','X',' ','X','X','X',' ','X','X','X','X','X','X','o','X','X','X',' ','X'},
  {'X',' ',' ',' ',' ',' ','X','X',' ',' ',' ',' ',' ','X','X','X',' ',' ',' ',' ',' ','X','X',' ',' ',' ',' ',' ','X'},
  {'X',' ','X','X','X','o','X','X',' ','X','X','X','X','X','X','X','X','X','X','X',' ','X','X','o','X','X','X',' ','X'},
  {'X','o','X','X','X','|',' ','o','|',' ','o',' ','o',' ','o',' ','o',' ','o',' ','|','o',' ','|','X','X','X','o','X'},
  {'X',' ','X','X','X','o','X','X','X','X',' ','X','X','X','X','X','X','X','X',' ','X','X','X',' ','X','X','X',' ','X'},
  {'X','o','X','X','X','o','X','X','X','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X','X','X',' ','X','X','X','o','X'},
  {'X',' ',' ','o',' ','|','o',' ','o',' ',' ','X','X','X','X','X','X','X','X',' ','o',' ','o','|',' ','o',' ',' ','X'},
  {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}};*/
     srand(time(NULL));
    fantasmas[0].fx=4,fantasmas[0].fy=12;
    fantasmas[1].fx=10,fantasmas[1].fy=9;
    fantasmas[2].fx=13,fantasmas[2].fy=6;
    fantasmas[3].fx=6,fantasmas[3].fy=6;
    fantasmas[4].fx=1,fantasmas[4].fy=1;
     fantasmas[0].dirf=2;
     fantasmas[1].dirf=1;
     fantasmas[2].dirf=3;
     fantasmas[3].dirf=4;
     fantasmas[4].dirf=1;
     comida=0;
     int v=1;
     int opc;
     char dec;
          pintar_mapa(mapas);
     while(comida<24&&v==1){
         choque_pacman(fantasmas);
gotoxy(60,15);cout<<"VIDAS= "<<vida;
direccion_pacman();
reposicion(mapas,fantasmas);
borra_cuerpos(fantasmas);
mover_pacman(mapas);
mover_fantasmas(fantasmas,mapas);
dificultad_mapa(mapas,fantasmas);
pintar_cuerpos(fantasmas);
choque_pacman(fantasmas);
comer_pacman();
tunel(fantasmas);
Sleep(160);
choque_pacman(fantasmas);
reposicion_2(mapas,fantasmas);
if(vida==0){vida=3;
v=0;}
if(comida==24){
gotoxy(60,23);cout<<"GANADOR!!!";
Sleep(3000);
gotoxy(60,23);cout<<"         ";
}
 choque_pacman(fantasmas);}
 }
