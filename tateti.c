#include <stdio.h> 
#include <stdlib.h> //rand
#include <time.h> //srand


/*
   Requisitos
   + Mostrar info del juego al principio
   + Mostrar el tablero 
   + juego es por turno
        + verifique el movimiento
        + diferenciar jugadores
        + informacion  actual de cada turno
   + Recibir nombres
   + Verificar si algunos logro el 3 en linea o empate
      + Informar situacion final
        + gano x o 0
        + Empate     
      + Verificar a partir del 5 turno inclusive
      + En caso de empate
      (EXTRA) Deberia iniciar otra ronda
      (EXTRA) deberia definirse al ganador con otro juego (Piedra-Papel-Tijera)
   + Comienza inicialmente con X o 0
   + Informar errores
   + crear un bot como segundo jugador (el jugador 1 es el usuario)
   
*/ 




// nombre del juego
#define NOMBRE_JUEGO "TA.TE.TI"  

#define MAX_NOMBRE 100

#define NOMBRE_DEF_JUG_A "def nombre A"
#define NOMBRE_DEF_JUG_B "def nombre B"
#define NOMBRE_DEF_JUG_ACT "def jugador actual"

/* Lo ideal seria utilizar lectura de archivo*/
#define INFO_INICIAL_JUEGO_PART1 "\t\t juego de tablero de 9 casillas \n\t\tCada jugador alterna movimientos para formar 3 en linea\n\n"
#define INFO_INICIAL_JUEGO_PART2 "t\tSe debe tratar de realizar una linea recta o diagonal por simbolo.\t\t"

#define MAX_FILA 3
#define MAX_COLUM 3
#define MAX_TURNOS MAX_FILA*MAX_COLUM
const int MAX_VERIF_DIAG = 2;
const int TURNO_EMPEZAR_VERIF = 5;

const int FILA_DEF = -1;
const int COL_DEF = -1;

const char SIMB_JUGADOR_A = 'X';
const char SIMB_JUGADOR_B = '0';
#define SIMB_VACIO ''
const char SIMB_JUGADOR_INICIAL_DEF = SIMB_JUGADOR_A;
const int NUM_CARACTER_VACIO = 0;

const int MOVIMIENTO_INVALIDO = 0;
const int MOVIMIENTO_VALIDO = 1;


const int NO_GANO = 0;
const int SI_GANO = 1;

/* 
Descripcion: Recibir los nombres de los jugadores
Pre:"nombreJugadoresA" y "nombreJugadoresB" Correctamente definidos y asignados
Post: Asigna los nuevos nombres a "nombreJugadorA" y "nombreJugadorB"
*/
void recibirNombresJugadores(char nombreJugadorA[MAX_NOMBRE], char nombreJugadorB[MAX_NOMBRE]){
	printf("Ingrese nombre de jugador A\n");
	scanf("%s", nombreJugadorA);
	printf("Ingrese nombre de Jugador B\n");
	scanf("%s", nombreJugadorB);
	printf("Nombres asignados....\n");
}


/* Descripcion: Muestra la presentacion del juego
    pre: "nombreJugadorA" y "nombreJugadorB" correctamente definidos y asignados con los nombres de los jugadores actuales

    post: Muestra NOMBRE_JUEGO, informacion del juego y los nombres de los jugadores actuales
*/

void presentarJuego(char nombreJugadorA[MAX_NOMBRE], char nombreJugadorB[MAX_NOMBRE]){
	 printf("\n\n\t\t****%s****\n\n",NOMBRE_JUEGO);
	 //INFO DEL JUEGO
    printf("\tinfo del juego:\n");
	 printf("%s\n",INFO_INICIAL_JUEGO_PART1);
	 printf("%s\n\n",INFO_INICIAL_JUEGO_PART2);

	 printf("jugadores: %s y %s\n",nombreJugadorA, nombreJugadorB );
}
/*
    Descripcion: muestra el tablero actualizado
     Pre:"TABLERO" CORRECTAMENTE DEFINIDO Y ASIGNADO CON VALORES ACTUALES CORRESPONDIENTES
     Post: muestra el tablero con los valores actuales
*/
void mostrarTablero(char tablero[MAX_FILA][MAX_COLUM]){
   for (int fila = 0; fila<MAX_FILA; fila++){
      printf("\t\t");
      for(int col = 0; col<MAX_COLUM; col++){
         printf("[%c]" , tablero[fila][col]);
      }
      printf("\n\n");

   
}
/* 
   Descripcion solicitamos el movimiento del usuario.jugador
   Pre: "fila"y "col" correctamente definidos y asignados
   Post: recibe nuevos valores para "fila"y "col"
*/
void RecibirMovimientoUsuario(int *fila, int *col){ 
    printf("ingrese fila\n");
    scanf("%i", fila);
    printf("ingrese columna\n");
    scanf("%i", col);
    }

/*
    Descripcion recibimos el movimiento del Bot
    pre: "fila"y "col" correctamente definidos y asignados
    post: se genera posiciones aleatorias para "fila" y "col"
*/
void RecibirMovimientoBot(int *fila, int *col){
    //generar un numero aleatorio para fila y columna
    //rand()
    //int numeroAleatorio = rand ()% 11; // me da un numero aleatorio entre 0 y 10
    *fila = rand () % MAX_FILA; // 0 Y 2
    *col = rand () % MAX_COLUM; // 0 y 2
 }

/* 
   Descripcion: Verica si el movimiento es MOVIMIENTO_INVALIDO
                Es valido si:
                 - La posicion esta dentro del "tablero"
                 - La posicion NO contiene un valor SIMB_JUGADOR_A y SIMB_JUGADOR_B"
   Pre: "fila" y "col" corresponde al movimiento ingresado por el jugador 
         "tablero"correctamente definido y actualizado
   Post: Verifica si el movimiento es valido 
         Si el movimiento es valido devuelvo el valor de "MOVIMIENTO_VALIDO", caso   
         contrario devuelvo "MOVIMIENTO_INVALIDO"
*/                           
int validacionMovimiento(int *fila, int*col, char tablero[MAX_FILA][MAX_COLUM]){
    int validacionMovimiento = MOVIMIENTO_INVALIDO;
    if( (*fila>= 0 && *fila <MAX_FILA) && (*col >= 0 && *col < MAX_COLUM) ) {//verificar que este adentro del juego
         if (tablero[*fila] [*col]==NUM_CARACTER_VACIO){//VERIFICO SI ESTA LIBRE EL JUGAR
             ValidacionMovimiento = MOVIMIENTO_VALIDO;
        }      
      } 
   return validacionMovimiento;
   }   


/*  
   Descripcion: Solicitamos el movimiento del jugador actual
   Pre: "fila" y "col" correctamente asignados
   Post: Solicita y asigna el movimiento del jugador en "fila" y "col"
*/
void RecibirMovimiento(char simbActual, int*fila, int*col, char tablero[MAX_FILA] [MAX_COLUM]){
    do{
      if(simbActual==SIMB_JUGADOR_A){
          RecibirMovimientoUsuario(fila, col); //no se usa el & por que fila y col ya tienen la direccion
      }else{
          RecibirMovimientoUsuario(fila, col);
      }
    }while(!verificarMovimiento(fila, col, tablero));
}


/*
   Descripcion: cambia de simbolo al correspondiente del siguiente jugador
   pre: "simbActual" debe corresponder al simbolo del jugador actual en el juego 
   Post: devuelve el simbActual del siguiente jugador

char alternarTurno(char simboActual){
   if(simbActual == SIMB_JUGADOR_A){
      simbActual == SIMB_JUGADOR_B;
   }else{
       simbActual == SIMB_JUGADOR_A;
   }
   return simbActual;
}    

/*
    Descripcion: muestra la informacion del turnos
    pre:"turnoActual"y simbActual"correctamente asignados
    post: muestra mediante consola la informacion del turno actual
*/
void mostrarInfoTurno(int turnoActual, char simbActual){
   printf("\n\tTurno numero:%i\n", turnoActual+1);
   printf("\tnombreJugadorActual: %s [%c]\n\n", nombJugadorActual, simbActual);
}


/*
    Descripcion: Seleccionar el nombre del jugador actual
    Pre: "SimbActual", "nombreJugadorAct", "nombreJugadorA" Y "nombreJugadorB" correctamente asignados 
    Post: copia el nombre del jugador actual en el turno actual a "nombreJugadorAct"
*/
void seleccNombreJugadorAct(char simbActual, char nombJugadorAct[MAX_NOMBRE], char nombreJugadorA[MAX_NOMBRE]);
   if(simbActual == SIMB_JUGADOR_A){
     strcpy (nombJugadorAct, nombreJugadorA);//nombrejugadorAct= nombreJugadorA;
}else{
     strcpy (nombJugadorAct, nombreJugadorB); //nombrejugadorAct= nombreJugadorB; 
     }     


/* 
    Descripcion: Verifica el 3 en linea horizontal
    Pre: "Tablero" y "simbActual" correctamente definidos y actualizados
    Post: devuelve "SI_GANO" si se logro 3 en linea horizontal, en caso contrario "NO_"GANO"
*/
int verificacionHorizontal (char tablero[MAX_FILA][MAX_COLUM], char simbActual){
   int estadoGano = NO_GANO;
   for(int verifHor = 0; verifHor< MAX_FILA; verifHor++){
       if(tablero[verifHor][0]) == simbActual && tablero [verifHor][1]==simbActual && tablero [verifHor][2]==simbActual
       estadoGano=SI_GANO;
       verifHor=MAX_FILA; 
   }
}     
return estadoGano;


/*
Descripcion: Verifica el 3 en linea vertical
    Pre: "Tablero" y "simbActual" correctamente definidos y actualizados
    Post: devuelve "SI_GANO" si se logro 3 en linea vertical, en caso contrario "NO_"GANO"
*/
int verificacionVertical (char tablero[MAX_FILA][MAX_COLUM], char simbActual){
   int estadoGano = NO_GANO;
   for(int verifVert = 0; verifVert< MAX_COLUM; verifVert++){
       if(tablero[verifVert][0])== simbActual && tablero [verifVert][1]==simbActual && tablero [verifVert][2]==simbActual
       estadoGano=SI_GANO;
       verifVert=MAX_COLUM; 
   }
}     
return estadoGano;




/*
  Descripcion: Verifica el 3 en linea Diagonal
    Pre: "Tablero" y "simbActual" correctamente definidos y actualizados
    Post: devuelve "SI_GANO" si se logro 3 en linea Diagonal, en caso contrario "NO_"GANO"
*/
int verificacionDiagonal (char tablero[MAX_FILA][MAX_COLUM], char simbActual, int *estadoGano){
   for(int verifDiag = 0; verifDiag< MAX_VERIF_DIAG; verifDiag+=2){// verifDiag=verifDiag + 2;
       if(tablero[verifDiag][0])== simbActual && tablero [verifHor][1]==simbActual && tablero [verifDiag][2]==simbActual
       *estadoGano=SI_GANO;
       verifDiag=MAX_VERIF_DIAG; 
   }
}     
return estadoGano;




/*
   Descripcion: Verifica si algun jugador gano/realizo 3 en linea.
    Pre: "Tablero" y "simbActual" correctamente definidos y actualizados
    Post: devuelve "SI_GANO" si se logra verificar 3 en linea, en caso contrario "NO_"GANO"
          actualiza el "estadoGanoJuego" con el valor de "estadoGano"
*/

int verificarGanoJugador (char tablero[MAX_FILA][MAX_COLUM], char simbActual, int *estadoGanoJuego){
   int estadoGano = NO_GANO;

   estadoGano=verificacionHorizontal(tablero,simbActual);
if (!estadoGano){//estadoGano==NO_GANO=0 y SI_GANO=1
     estadoGano=verificacionVertical(tablero,simbActual);
}
if (!estadoGano){
     verificacionDiagonal(tablero,simbActual, &estadoGano);  
}

*estadoGanoJuego=estadoGano;
   
return estadoGano;


/*
  Descripcion: informa situacion final del juego
*/
void informarSituacionFinal(char nombJugadorAct[MAX_NOMBRE],char tablero[MAX_COLUM], int estadoGanoJuego);
     if (estadoGanoJuego){
       printf("JUGADOR %s GANO!\n", seleccNombreJugadorAct);
     }else{
       printf(" EMPATE!!!!\n");
  }  
     mostrarTablero(tablero);
     printf("GRACIAS POR JUGAR\n");
}


/*
    Descripcion: Inicia el juego hasta que
     se obtiene un final
*/
void iniciarJuego(char tablero[MAX_FILA][MAX_COLUM], char nombreJugadorA[MAX_NOMBRE],char nombreJugadorB [MAX_NOMBRE]);
   char simbActual = SIMB_JUGADOR_INICIAL_DEF;
   int fila = FILA_DEF;
   int col = COL_DEF;
   char nombJugadorAct[MAX_NOMBRE]= NOMBRE_DEF_JUG_ACT;
   int estadoGanoJuego=NO_GANO;

   for(int turnoActual = 0; turnoActual < MAX_TURNOS; turnoActual++){
      seleccNombreJugadorAct(simbActual, nombreJugadorAct, nombreJugadorA, nombreJugadorB);
      mostrarInfoTurno(turnoActual, simbActual, nombreJugadorAct); 
      mostrarTablero(tablero);
      RecibirMovimiento(simbActual, &fila, &col, tablero);
      tablero[fila][col]=simbActual; //agrego el movimiento al tablero//verificar estado gano o empate//alternar turno

      if (((turnoActual+1)>=TURNO_EMPEZAR_VERIF)&& verificarGanoJugador(tablero, simbActual, &estadoGanoJuego));
            turnoActual=MAX_TURNOS; //CORTE INTERNO
         }else{
             simbActual=alternarTurno(simbActual);
    }
        informarSituacionFinal(nombJugadorAct, tablero, estadoGanoJuego);   



int main(){
  
   srand (time(NULL)); // Alteramos la semilla para que el numero aleatorio sea... mas aleatorio
   
   char tablero[MAX_FILA][MAX_COLUM]={}; //nombre.de.recibirNombresJugadores 
   
   char nombreJugadorA[MAX_NOMBRE]=NOMBRE_DEF_JUG_A;
   char nombreJugadorB[MAX_NOMBRE]=NOMBRE_DEF_JUG_B;

   recibirNombresJugadores(nombreJugadorA,nombreJugadorB);
   presentarJuego(nombreJugadorA,nombreJugadorB);
   //mostrarTablero
   iniciarJuego(tablero);//tablero se envia como aegumento
   return 0;
}


























   	