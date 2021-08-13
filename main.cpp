#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <termios.h> 
#include <unistd.h>     //TECLA
#include <fcntl.h> 
#include<time.h>

#include "pythonPreguntas.h" //Declaracion de funcion de tematica de pythonPreguntas
#include "edaPreguntas.h"
#include "deportesPreguntas.h"
#include "todasPreguntas.h"

int opcionRegistro();   //Registro en el Sistema
int accesoSistema();    //Corroborando nickName y contraseña y que coincidan con las del usuario

char nickName[50];
char contrasena[50];

int todasPreguntas2();

int menu();     //Menu ya inicada la sesion

int puntos=0;     //Variable Global

int kbhit();        //TECLA 

int jugarxtematica();  //Opcion c del menu de juegos
int pythonPreguntas();   //Opcion Peliculas

int consultarSaldo(); //Funcion para consultarSaldo
int main()//funcion principal en la que estan anidadas las funciones opcionRegistro, la funcion accesoSistema y la funcion menu.
{
    int op=0;
    printf("----Bienvenido----");
    printf("\n\t1.Registro de Jugadores\n\t2.Acceso al Sistema\nEscoje el número de tu opción:");
    scanf("%i", &op);
    setbuf(stdin, NULL);
    switch(op)
    {
        case 1:
        opcionRegistro();//llamamos a funcion opcionRegistro en caso de seleccionar la opcion 1
        break;
        case 2:
        accesoSistema();//llamamos a funcion accesoSistema en caso de seleccionar la opcion 2
        menu();//se llama a la funcion menu cuando nickName coincide en la funcion de accesoSistema
        break;
    }
    
    return 0;
}

int opcionRegistro()//funcion que sirve para preguntar datos corroborarlos e imprimirlos/guardarlos en el archivo registro.txt
{
    FILE* archivo;
    char nombre[50]=" ", aPaterno[50]=" ", aMaterno[50]=" ", nickName[50]=" ", contrasena[50]=" ", contrasena2[50]=" ", correo[50]=" ";
    int r=0;
    do
    {
        printf("\nIngresa tu nombre(s):");
        gets(nombre);
        printf("\nIngresa tu apellido paterno:");
        gets(aPaterno);
        printf("\nIngresa tu apellido materno:");
        gets(aMaterno);
        printf("\nIngresa tu nickname:");
        gets(nickName);
        do
        {
            printf("\nIngresa tu contraseña:");
            gets(contrasena);
            printf("\nReafirma tu contraseña:");
            gets(contrasena2);
            if(strcmp(contrasena, contrasena2) != 0)
            {
                printf("\nNo coinciden las contraseñas");
            }
        }while(strcmp(contrasena, contrasena2) != 0);
        printf("\nIngresa un correo asociado a sitema de pagos:");
        gets(correo);
        printf("\n¿Son correctos los datos ingresados?\n\tNombre(s):%s\n\tApellidos:%s %s\n\tNickname:%s\n\tContraseña:%s\n\tE-mail:%s", nombre, aPaterno, aMaterno, nickName, contrasena, correo);
        printf("\n\t1.Si\n\t2.No\n\t:");
        scanf("%i", &r);
        setbuf(stdin,NULL);
    }while(r == 2);
    
    archivo = fopen("Registro.txt", "a+");
    if(archivo != NULL)
    {
        fprintf(archivo, "%s:%s:%s:%s:%s:%s", nickName, contrasena, nombre, aPaterno, aMaterno, correo);
        fprintf(archivo,"\n");
        if(fclose(archivo)==0)
            {
                
                printf("\n\nExito en el registro del usuario\n\n");
        
            }
            else 
            {
                printf("\nHubo un problem al registrar el usuario, intentelo otro día\n\n");   
            }
    }
    else
    {
        printf("\nErroR al ABRIR el archivo. \n\n");
    }
    return 120;
    }
    

int accesoSistema()//La funcion evalua que los datos de nickName y contrasena y que coincidan con los datos del Registro.txt si no son correctos se pregunta si Estas
                   //registrado y si esta registado nos indica que los datos son incorrectos y vuelve a preguntar datos y contrasena
{
    FILE* archivo;
    char s1[1000]=" ";
    char *nickSystem;
    char *contraSystem;
    char separador[2]=":";
    char contrasena[20]=" ", nickname[20]=" "; 
    
    int nickcorrect=0, contracorrect=0, usuarioexistente=0, contCode=0;
    
    archivo = fopen ("Registro.txt", "r");
    do
    {
        printf("Ingresa tu nickname: ");
        setbuf(stdin,NULL);
        gets(nickname);
        printf("Ingresa tu contraseña: ");
        setbuf(stdin,NULL);
        gets(contrasena);
        if(archivo != NULL)
        {
            do
            {
                fscanf(archivo, "%s", s1);
                nickSystem = strtok(s1, separador);
                if(strcmp(nickname , nickSystem)==0)
                {
                    nickcorrect=2;
                    while(contCode==0)
                    {
                        contraSystem = strtok(NULL , separador);
                        contCode= contCode+1;
                    }
                    do
                    {
                        printf("----Bienvenido %s----", nickname);
                        if(strcmp(contrasena, contraSystem)==0)
                        {
                            contracorrect=2;
                        }
                        else
                        {
                            printf("\nContraseña Incorrecta!!!\nIngresa nuevamente tu contraseña, %s\n\t:", nickname);
                            gets(contrasena);
                        }
                    }while(contracorrect!=2);

                    break;
                }
                else
                {
                    printf("Espere un momento por favor...\n");
                }
            }while(feof(archivo)==0);
            
            if(nickcorrect==0)
            {
                printf("\n¿Estas registrado?\n\t1.Si\n\t2.No");
                setbuf(stdin,NULL);
                scanf("%i", &usuarioexistente);
                if(usuarioexistente==1)
                {
                    printf("Tu nickname es incorrecto\nVuelve a ingresarlo\n");
                    rewind(archivo);
                }
                else
                {
                    printf("Registrate");
                    setbuf(stdin,NULL);
                    opcionRegistro();
                    break;
                }
            }
        }
        else
        {
        printf("\nErroR al ABRIR el archivo. \n\n");
        }
    }while(nickcorrect==0);
    return 100;
}


int kbhit()//Es una funcion que se incluye para que se lea una tecla del teclado
{
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}



int menu()//Muestra el menu de juegos y manda a llamar a diferentes funciones
{
    char menuop=' ';
    
    char tecla=' ';
    
    int teclamenu=0, totalDeLaCompra=0, contCompPuntos=0;
    
    do// se va a ejecutar el do while en caso de que teclamenu==2
    {
        system("clear");
        printf("\n----MENÚ PRINCIPAL----\n\t\nA. Conseguir puntos para jugar.\nB. Consultar saldo de puntos.\nC. Jugar a preguntas por tematica.\nD. Jugar a preguntas de temas combinados.\nE. Cerrar sesión.\n\t:");
        setbuf(stdin,NULL);
        scanf("%c", &menuop); //> <
        switch(menuop)
        {
            case 'A'://Caso de switch para Conseguir puntos
            system("clear");
            printf("\n---Conseguir puntos para jugar---\n");
            printf("¿Cuantos puntos desea comprar?\nRECUERDA: Para jugar a preguntas por tematica necesita invertir dos puntos y para jugar a preguntas combinadas necesitara invertir 4 puntos\nCada punto vale $5MXN\nComprar\t:");
            scanf("%i", &puntos);
            totalDeLaCompra=puntos*5;
            
            for(contCompPuntos=0; contCompPuntos<4; contCompPuntos++)
            {
                system("clear");
                printf("\nEl total de la compra de los puntos sera de %i$, el cargo se ha hecho al sistema de pago asociado a su correo.  \n---SUERTE!!!---", totalDeLaCompra);
            }
            teclamenu=2;
            sleep(6);
            system("clear");
            break;
            
            case 'B'://Caso B de switch para mandar a consultarSaldo
            setbuf(stdin,NULL);
            
            consultarSaldo();
            teclamenu=2;
            break;
            
            case 'C'://Caso C para mandar a llamar a jugarxtematica en caso de tener 2 o mas puntos 
            system("clear");
            if(puntos>=2)
            {
                jugarxtematica();
                printf("\nPLAY");
            }
            else
            {
                char tecla=' ';
                printf("No tienes sufucientes puntos para jugar --Presiona la tecla (M) para ir al menú-- ");
                do
                {   
                    if(kbhit())	// Si detecta que se presionó una tecla
                    {
            	        tecla=getchar();	//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            	        if(tecla=='M')
            	        {
            	            teclamenu=2;
            	            system("clear");
            	            
            	        }
            	        else
            	        {
            	            teclamenu=1;
            	        }
                    }
                }while(tecla!='M');
            }
            break;
            case 'D':// Caso para mandar a llamar a la funcion de todasPreguntas2 en caso de tener 3 o mas puntos.
            system("clear");
            if(puntos>=3)
            {
                todasPreguntas2();
                printf("\nPLAY");
                
            }
            else
            {
                char tecla=' ';
                printf("No tienes sufucientes puntos para jugar --Presiona la tecla (M) para ir al menú-- ");
                do
                {   
                    if(kbhit())	// Si detecta que se presionó una tecla
                    {
            	        tecla=getchar();	//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            	        if(tecla=='M')
            	        {
            	            teclamenu=2;
            	            system("clear");
            	            
            	        }
            	        else
            	        {
            	            teclamenu=1;
            	        }
                    }
                }while(tecla!='M');
            }
            break;
            case 'E':
            printf("Cerrando sesion\n");
            sleep(2);
            main();
            break;
        }
    }while(teclamenu==2);
    return 200;
}

int consultarSaldo()// Funcion para consultar el saldo disponible
{
 char tecla= ' ';
 int teclaMenu=0;
 printf("Tu saldo en puntos es: %i", puntos);
             printf("\nPresiona cualquier tecla %c\n", tecla);
            setbuf(stdin,NULL);
            while(1)
            {
                if(kbhit())	// Si detecta que se presionó una tecla
                {    	
                    tecla = getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
                 	break;
                }
                teclaMenu=2;
            }
sleep(2);
	return 0;
}


int jugarxtematica()//Funcion para mandar a llamar a la funcion de las diferentes librerias disponibles para diferente tema
{
    int ptos=0;     //Variable donde guardamos resta de puntos totales        
    
    ptos=puntos-2;   //Le descuenta 2 puntos al entrar a esta funcion
    
    int opTematica=0;
    
    printf("---Seleccione un tema---\n\t1. Python\n\t2. EDA I\n\t3. Deportes\n\t");
    scanf("%i", &opTematica);
    switch(opTematica)
    {
        case 1://Caso 1manda a llamar la funcion pelisPreguntas de la librerias pythonPreguntas.h
        pythonPreguntas();
        menu();
        break;
        case 2://Caso 2  manda a llamar a la funcion musicaPreguntas de la libreria edaPreguntas.h
        edaPreguntas();
        menu();
        break;
        case 3://Caso 3  manda a llamar a la funcion deportesPreguntas de la libreria deportesPreguntas.h
        deportesPreguntas();
        menu();
        break;
    }
    
    return ptos;
}

int todasPreguntas2()// La función todasPreguntas2 que manda a llamar a la función todasPreguntas que se encuentra en la librería todasPreguntas.h
{
    int ptos=0;
    ptos=puntos-3;//Le descuenta 2 puntos al entrar a esta funcion
    printf("Preguntas Aleatorias\n");
    
    todasPreguntas();
    menu();

    return 0;
}


    
   