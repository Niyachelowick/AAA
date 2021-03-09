#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
// esconde el cursor, util para dar mejor aspecto a animasiones ASCII
void HideCursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);// tomamos control de la consola
   CONSOLE_CURSOR_INFO info;// establecemos parametros de consola
   info.dwSize = 100;
   info.bVisible = FALSE;// este es el atributo que nos interesa cambiar
   SetConsoleCursorInfo(consoleHandle, &info);
}

//deja ver el cursor si este fue ocultado anteriormente 
void ViewCursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = TRUE;// lo mismo que la de arriba :v
   SetConsoleCursorInfo(consoleHandle, &info);
}
 void gotoxy(int x,int y){  
      HANDLE hcon;//identificador hcon dado por tradicion.adquier el control de la consola activa
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  //get std handele ; recupera el identificador comoun parametro para la salida standard:
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  //este pone el cursor en un punto de la consola
 }  
 
 void Color(int Background, int Text); // Prototipo de función          
void Color(int Background, int Text){ // Función para cambiar el color del fondo y/o pantalla

 HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.

 // Para cambiar el color, se utilizan números desde el 0 hasta el 255.
 // Pero, para convertir los colores a un valor adecuado, se realiza el siguiente cálculo.
 int    New_Color= Text + (Background * 16);

 SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola.

}

enum Colors { // Listado de colores (La letra "L" al inicio, indica que es un color más claro que su antecesor).
 BLACK = 0,
 BLUE = 1,
 GREEN = 2,
 CYAN = 3,
 RED = 4,
 MAGENTA = 5,
 BROWN = 6,
 LGREY = 7,
 DGREY = 8,
 LBLUE = 9,
 LGREEN = 10,
 LCYAN = 11,
 LRED = 12,
 LMAGENTA = 13,
 YELLOW = 14,
 WHITE = 15
};


int recuadroTitulo(char texto[]){// Genera un cuadro de titulo
	int i;
	printf("\t%c",201); for(i=0;i<strlen(texto);i++){printf("%c",205);} printf("%c",187);
	printf("\n\t%c",186); printf("%s",texto); printf("%c",186);
	printf("\n\t%c",200); for(i=0;i<strlen(texto);i++){printf("%c",205);} printf("%c\n",188);
}

int GenMarc(int larg, int alt,int x,int y){//genera un marco de doble linea en una poscicion especifica
	int i,j;
	gotoxy(x,y);
	printf("%c",201);
		for(i=0;i<larg;i++){
			printf("%c",205);
		}
	printf("%c",187);
	for(i=1;i<alt;i++){
	gotoxy(x,y+i);
	printf("%c",186); for(j=0;j<larg;j++){printf(" ");} printf("%c",186);	
	}
	gotoxy(x,y+alt);	printf("%c",200); for(i=0;i<larg;i++){printf("%c",205);} printf("%c",188);

}

int MsgAnimado(char text[]){ //es un printf que muestra caracter por caracter
	int i;
	for(i=0;i<strlen(text);i++){
		printf("%c",text[i]);
		Sleep(50);
	}
}

int MsgAnimadoP(char text[],int time){// es un printf que muestra caracter por caracter en tiempos personalizales
	int i;
	for(i=0;i<strlen(text);i++){
		printf("%c",text[i]);
		Sleep(time);
	}
}

//helloworld genera un texto colorido que dice hello world con un marco rectangular
void HelloWorld(){
    system("cls");
	HideCursor();
    GenMarc(18,3,6,3);
    gotoxy(7,4);
    Color(BLACK,YELLOW);   printf("H"); Sleep(50);
    Color(BLACK,GREEN);    printf("E"); Sleep(50);
    Color(BLACK,CYAN);     printf("L"); Sleep(50);
    Color(BLACK,MAGENTA);  printf("L"); Sleep(50);
    Color(BLACK,LRED);     printf("o"); Sleep(50);
    Color(BLACK,LGREY);    printf("W"); Sleep(50);
    Color(BLACK,BLUE);     printf("o"); Sleep(50);
    Color(BLACK,DGREY);    printf("r"); Sleep(50);
    Color(BLACK,WHITE);    printf("l"); Sleep(50);
    Color(BLACK,LMAGENTA); printf("d"); Sleep(50);
gotoxy(0,10);
ViewCursor();
}

//genera una barra animada de progreso
int BarraDProgreso(int x,int y,int progreso){
	int i;
	HideCursor();
	gotoxy(x,y);
	for(i=0;i<=progreso;i++){
		
		printf("%c",219);
	}
}