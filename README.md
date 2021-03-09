# AAA
ASCII Art Asisitant

this is a self made library that i usually use to give a better look to a console project using simple functions that everyone can understand and use.

HideCursor();  // esconde el cursor, util para dar mejor aspecto a animasiones ASCII

ViewCursor();  //deja ver el cursor si este fue ocultado anteriormente 

gotoxy(int x,int y); // esta es bastante comun de encontrar en otros lados, la usas para re posicionarte en un lugar especifico de la consola

Color(int Background, int Text); // Función para cambiar el color del fondo y/o pantalla, utiliza la siguiente lista de colores, ya listados en la libreira.
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
 
 recuadroTitulo(char texto[]);  // Genera un cuadro de titulo
 
 GenMarc(int larg, int alt,int x,int y); //genera un marco de doble linea en una poscicion especifica
 
 MsgAnimado(char text[]); //es un printf que muestra caracter por caracter
 
 MsgAnimadoP(char text[],int time); // es un printf que muestra caracter por caracter en tiempos personalizales
 
 
HelloWorld(); //helloworld genera un texto colorido que dice hello world con un marco rectangular


BarraDProgreso(int x,int y,int progreso); //genera una barra animada de progreso
