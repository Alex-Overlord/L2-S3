#include "window.h"
#include "raquette.h"
using namespace std;

void initGame(){
	int h, w, y = 2, x = 2;
	getmaxyx(stdscr, h, w);
	Window plateau(h, w, y, x);


  int ch; // événement

  // Plateau
  //int h = 50, w = 50, x = 0, y = 0;
  //char c = '+';
  //Window plateau(h,w,x,y,c);
  plateau.setCouleurBordure(BBLUE);

  string s = "Raquette";
  Color col = BGREEN;
  
      mvprintw(5,10,"yasmeen: Fuck l'écologie !");
    while((ch = getch()) != 'q') {
    switch (ch) {
    case '1':
      col = BMAGENTA;
      break;
    case '2':
      col = WCYAN;
      break;
    case 'c':
      plateau.clear();
      break;
    case KEY_UP:
      mvprintw(10,5,"hello");
      plateau.print(x,y,' ');
      plateau.print(x,--y,s,col);
      break;
    case KEY_DOWN:
      //mvwprintw(,5,5,"COUCOU");
      plateau.print(x,y,' ');
      plateau.print(x,++y,s,col);
      break;
    case KEY_LEFT:
      if (x == 0) {}
      else {
	     plateau.print(x,y,' ');
	     plateau.print(x+7,y,' ');
	     plateau.print(--x,y,s,col);
      } 
      break;
    case KEY_RIGHT:
      if (x == w-5) {}
      else {
	     plateau.print(x,y,' ');
	     plateau.print(++x,y,s,col);
      }
      break;
    case '\n':
      plateau.print(x,y,' ');
      plateau.print(x+1,y,' ');
      plateau.print(x+2,y,' ');
      plateau.print(x+3,y,' ');
      plateau.print(x+4,y,' ');
      plateau.print(x,y,s,col);
      break;
    case '\t':/*
      Color tmp= menu.getCouleurBordure();
      menu.setCouleurBordure(plateau.getCouleurBordure());
      plateau.setCouleurBordure(tmp);*/
      break;
    }
  }
}

void myProgram2() {
  int ch; // événement
  
  // Plateau
  int hp = 17, wp = 62; // dimension du plateau
  Window plateau(hp,wp,1,6);
  plateau.setCouleurBordure(BGREEN);

  // Raquette
  int xr = wp/2, yr = hp-2;
  string sr = "Raquette";
  Color colr = BGREEN;
  plateau.print(xr,yr,sr,colr);

  while((ch = getch()) != 'q') {
    switch (ch) {
    case '1':
      colr = BMAGENTA;
      break;
    case '2':
      colr = WCYAN;
      break;
    case 'c':
      plateau.clear();
      break;
    case KEY_UP:
      mvprintw(0,0,"hello");
      //plateau.print(x,y,' ');
      //plateau.print(x,--y,p,col);
      break;
    case KEY_DOWN:
      printw(0,0,"COUCOU");
      //plateau.print(x,y,' ');
      //plateau.print(x,++y,p,col);
      break;
    case KEY_LEFT:
      if (xr == 0) {}
      else {
	plateau.print(xr,yr,' ');
	plateau.print(xr+7,yr,' ');
	plateau.print(--xr,yr,sr,colr);
      }
      break;
    case KEY_RIGHT:
      if (xr == wp-5) {}
      else {
	plateau.print(xr,yr,' ');
	plateau.print(++xr,yr,sr,colr);
      }
      break;
    case '\n':
      plateau.print(xr,yr,' ');
      plateau.print(xr+1,yr,' ');
      plateau.print(xr+2,yr,' ');
      plateau.print(xr+3,yr,' ');
      plateau.print(xr+4,yr,' ');
      xr=wp/2,yr=hp-2;
      plateau.print(xr,yr,sr,colr);
      break;
    case '\t':/*
      Color tmp= menu.getCouleurBordure();
      menu.setCouleurBordure(plateau.getCouleurBordure());
      plateau.setCouleurBordure(tmp);*/
      break;
    }
  }
}
void myProgram(){
  int ch;
  int h=17,w=62;
  Window menu(22,30,70,1); // (hauteur, largeur, x, y)
  Window plateau(h,w,1,6);
  menu.setCouleurBordure(BYELLOW);
  plateau.setCouleurBordure(BGREEN);
  
  menu.print(1,1,"Tapez Q pour quitter.",BYELLOW);
  
  int x=w/2,y=h-2;
  string p="Raque";
  Color col=BGREEN;
  plateau.print(x,y,p,col);
  
  while((ch = getch()) != 'q') {
    switch (ch) {
    case '1':
      col=BMAGENTA;
      break;
    case '2':
      col=WCYAN;
      break;
    case 'c':
      plateau.clear();
      break;
    case KEY_UP:
      mvprintw(0,0,"hello");
      //plateau.print(x,y,' ');
      //plateau.print(x,--y,p,col);
      break;
    case KEY_DOWN:
      printw(0,0,"COUCOU");
      //plateau.print(x,y,' ');
      //plateau.print(x,++y,p,col);
      break;
    case KEY_LEFT:
      if (x == 0) {}
      else {
	plateau.print(x,y,' ');
	plateau.print(x+4,y,' ');
	plateau.print(--x,y,p,col);
      }
      break;
    case KEY_RIGHT:
      if (x == w-5) {}
      else {
	plateau.print(x,y,' ');
	plateau.print(++x,y,p,col);
      }
      break;
    case '\n':
      plateau.print(x,y,' ');
      plateau.print(x+1,y,' ');
      plateau.print(x+2,y,' ');
      plateau.print(x+3,y,' ');
      plateau.print(x+4,y,' ');
      x=w/2,y=h-2;
      plateau.print(x,y,p,col);
      break;
    case '\t':
      Color tmp= menu.getCouleurBordure();
      menu.setCouleurBordure(plateau.getCouleurBordure());
      plateau.setCouleurBordure(tmp);
      break;
    }
  }
}

int main(int argc, char** argv){
  startProgramX();
  initGame();
  stopProgramX();

  return 0;
}
