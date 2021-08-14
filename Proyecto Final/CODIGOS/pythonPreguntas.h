#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h> 
#include <unistd.h>     //TECLA
#include <fcntl.h> 
//prototipos de funciones
int cuentaPreparate();  //Cuenta Regresiva preparate para contestar o el juego ya va a comenzar
int kbhit();
//Formulacion de la preguntas al azar
int estructuraPregunta1(); //Formulacion de la  pregunta 1 al azar
int estructuraPregunta2(); //Formulacion de la pregunta 2 al azar
int estructuraPregunta3(); //Formulacion de la pregunta 3 al azar
int estructuraPregunta4(); //Formulacion de la pregunta 4 al azar
int estructuraPregunta5(); //Formulacion de la pregunta 5 al azar
int estructuraPregunta6(); //Formulacion de la pregunta 6 al azar
int estructuraPregunta7(); //Formulacion de la pregunta 7 al azar
int estructuraPregunta8(); //Formulacion de la pregunta 8 al azar
int estructuraPregunta9(); //Formulacion de la pregunta 9 al azar
int estructuraPregunta10(); //Formulacion de la pregunta 10 al azar

//Variables globales y apuntadores para que se ejecuten de manera adecuada las diferntes funciones
char *segmentoDeCadena, *segmentoDeCadena1, *segmentoDeCadena2, *segmentoDeCadena3, *segmentoDeCadena4, *segmentoDeCadena5, *segmentoDeCadena6, *segmentoDeCadena7,*segmentoDeCadena9, *segmentoDeCadena8, *segmentoDeCadena10;
char *structurePregunta;
                    //separadores
char s1[2]=":";     //separdor de preguntas e incisos
char s2[2]="#";     //separa las 10 preguntas del archivo

int res1=0, res2=0, res3=0, res4=0, res5=0, res6=0, res7=0, res8=0, res9=0, res10=0; //Preguntas que tuvimos correctas

int falta=3;

int comodin=0;

int comodin2=0;

int participacion=0;


int imprimirPregunta=0;
int cuentaTiempo=7;            //Duracion de la pregunta


int cuentaPreparate()//funcion que se manda a llamar en pythonPreguntas() que sirve para hacer el conteo regresivo para iniciar el juego
{
    int cuentaInicio=3;
	printf("----PREPARATE :D----");
	sleep(1);
	for(cuentaInicio=3; cuentaInicio>0; cuentaInicio--)
	{
		printf("\n%i ", cuentaInicio);
		sleep(1);
	}
	printf("\nCOMIENZA!!!!");
	return 1;
}


int pythonPreguntas()//funcion que sirve para imprimir las Preguntas de forma aleatoria
{
     int jugarOtraVez=0;
     int ganar=0;
     comodin=0;
     comodin2=0;
    //do while para que en caso de que jugarNuevamente sea igual a uno osea que si quiera jugar de nuevo, se vuelva a ejecutar todo el programa.
    do
    {
       
        char Preguntas[2000];
        FILE *archivo;
        
        int aleatorios[5], indice=0;
    	
    	int A1=0, A2=0, A3=0, A4=0, A5=0, dif=2;
    	
    	res1=0, res2=0, res3=0, res4=0, res5=0, res6=0, res7=0, res8=0, res9=0, res10=0;
    	
    	cuentaPreparate();
    	sleep(1);
    	
    	archivo = fopen ("Python.txt", "r");
    	if(archivo!=NULL)
    	{
    	    //separa las todas las Preguntas del archivo de forma: pregunta:inciso a:incisob:incisoc, y cada pregunta la guarda en un apuntador llamado segmeDeCadena...
    	    fgets(Preguntas, 2000, archivo);
    	    segmentoDeCadena = strtok( Preguntas , s2 );  //EJEMPLO CADENA= "PREGUNTA:INCISO A:INCISO B:INCISO C "
    	    segmentoDeCadena1 = strtok( NULL, s2 );
    	    segmentoDeCadena2 = strtok( NULL, s2 );
    	    segmentoDeCadena3 = strtok( NULL, s2 );
    	    segmentoDeCadena4 = strtok( NULL, s2 );
    	    segmentoDeCadena5 = strtok( NULL, s2 );
    	    segmentoDeCadena6 = strtok( NULL, s2 );
    	    segmentoDeCadena7 = strtok( NULL, s2 );
    	    segmentoDeCadena8 = strtok( NULL, s2 );
    	    segmentoDeCadena9 = strtok( NULL, s2 );
    	    segmentoDeCadena10 = strtok( NULL, s2 );
    	}
    	
    	do
        {
             //generacion del numero de la pregunta de forma aleatoria.
            srand(time(NULL));
            A1 = (rand()%5)+4;
            srand(time(NULL));
            A2 = (rand()%5)+4;
            srand(time(NULL));
            A3 = (rand()%5)+4;
            srand(time(NULL));
            A4 = (rand()%5)+4;
            srand(time(NULL));
            A5 = (rand()%5)+4;
            if((A1 || A2 || A3 || A4 || A5)==0)         //ALEATORIO
            {
                dif=0;
            }
        }while(dif==1);
        A1=A1+1;
        A2=A2-1;
        A3=A3-2;
        A4=A4+2;
        A5=A5-3;
        
        switch(A1)//seleccion de la primer pregunta aleatoria dependiendo A1
        {
            case 1: estructuraPregunta1();
            break;
            case 2: estructuraPregunta2();
            break;
            case 3: estructuraPregunta3();
            break;
            case 4: estructuraPregunta4();
            break;
            case 5: estructuraPregunta5();
            break;
            case 6: estructuraPregunta6();
            break;
            case 7: estructuraPregunta7();
            break;
            case 8: estructuraPregunta8();
            break;
            case 9: estructuraPregunta9();
            break;
            case 10: estructuraPregunta10();
            break;
        }
        switch(A2)//seleccion de la segunda pregunta aleatoria dependiendo A2
        {
            case 1: estructuraPregunta1();
            break;
            case 2: estructuraPregunta2();
            break;
            case 3: estructuraPregunta3();
            break;
            case 4: estructuraPregunta4();
            break;
            case 5: estructuraPregunta5();
            break;
            case 6: estructuraPregunta6();
            break;
            case 7: estructuraPregunta7();
            break;
            case 8: estructuraPregunta8();
            break;
            case 9: estructuraPregunta9();
            break;
            case 10: estructuraPregunta10();
            break;
        }
        switch(A3)//seleccion de la tercera pregunta aleatoria dependiendo A3
        {
            case 1: estructuraPregunta1();
            break;
            case 2: estructuraPregunta2();
            break;
            case 3: estructuraPregunta3();
            break;
            case 4: estructuraPregunta4();
            break;
            case 5: estructuraPregunta5();
            break;
            case 6: estructuraPregunta6();
            break;
            case 7: estructuraPregunta7();
            break;
            case 8: estructuraPregunta8();
            break;
            case 9: estructuraPregunta9();
            break;
            case 10: estructuraPregunta10();
            break;
        }
        switch(A4)//seleccion de la cuarta pregunta aleatoria dependiendo A4
        {
            case 1: estructuraPregunta1();
            break;
            case 2: estructuraPregunta2();
            break;
            case 3: estructuraPregunta3();
            break;
            case 4: estructuraPregunta4();
            break;
            case 5: estructuraPregunta5();
            break;
            case 6: estructuraPregunta6();
            break;
            case 7: estructuraPregunta7();
            break;
            case 8: estructuraPregunta8();
            break;
            case 9: estructuraPregunta9();
            break;
            case 10: estructuraPregunta10();
            break;
        }
        switch(A5)//seleccion de la quinta pregunta aleatoria dependiendo A5
        {
            case 1: estructuraPregunta1();
            break;
            case 2: estructuraPregunta2();
            break;
            case 3: estructuraPregunta3();
            break;
            case 4: estructuraPregunta4();
            break;
            case 5: estructuraPregunta5();
            break;
            case 6: estructuraPregunta6();
            break;
            case 7: estructuraPregunta7();
            break;
            case 8: estructuraPregunta8();
            break;
            case 9: estructuraPregunta9();
            break;
            case 10: estructuraPregunta10();
            break;
        }
        ganar=comodin2+res1+res2+res3+res4+res5+res6+res7+res8+res9+res10;//suma de los puntos de cada pregunta en caso de ser correcta y en caso de tener un comodin.
        if(ganar>=5)//en caso de que la suma de los puntos sea 5 osea conteste todas las preguntas bien se va a imprimir el mensaje.
        {
             printf("\n\nFELICIDADES :D!!!!!!!\nSe te va a transerir $50 mxn a tu cuenta bancaria\n\n");
             sleep(5);
             jugarOtraVez=100;
        }
        else//en caso contrario de que no conteste todas las preguntas bien se va a realizar lo siguiente
        {
           participacion=participacion+1;//Es la suma de las participaciones que lleva
           if(participacion==3)//En caso de que las participaciones sea igual a 3 se va a ejecutar lo siguiente
           {
               comodin=comodin+1;//se suma un comodin 
               printf("\n\nSe te agrego un comodin\n\n");
               sleep(5);
               system ("clear");
               printf("\n¿Te gustaria volver a jugar?\n\t 1.Si    2.Regresar al menú\n\t:");
               scanf("%i", &jugarOtraVez);
               participacion=0;//se va a volver a inicializar las participaciones por que ya se utilizo el comodin si es que no llega a ganar.
            
           }
           else//en caso contrario de que las participaciones no sea igual a 3
           {
               system ("clear");//limpia pantalla
               falta=3-participacion;//es para que vaya leyendo las participaciones que lleva para mencionarle cuantas participaciones le hacen falta para seguir jugando
               printf("\n\nTe falta jugar %i veces para obtener un comodin\n", falta);//menciona cuantas veces le falta para que se le agregue el comodin
               if(participacion==3)
               {
                   falta=3;
               }
               
               printf("\n¿Te gustaria volver a jugar?\n\t1.Si    2.Regresar al menú\n\t:");
               scanf("%i", &jugarOtraVez);
           }
        }

    }while(jugarOtraVez==1);
    return 220;
}



int estructuraPregunta1()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R1=' ';
    cuentaTiempo=7;
    imprimirPregunta=0;
    for(cuentaTiempo=7; cuentaTiempo>0; cuentaTiempo--)
    { 
        sleep(1);
        while(imprimirPregunta==0)     
        {  
            imprimirPregunta=imprimirPregunta+1;
            structurePregunta = strtok(segmentoDeCadena, s1);
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R1=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            
            switch(R1)
            {
                case 'A': printf("---CORRECTO---");
                            res1=1;
                break;
                case 'B': printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                            res1=1;
                break;
                case 'C': printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                break;
                default: printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                break;
            }break;
        }
    }
    return res1;
}

int estructuraPregunta2()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo
{
    char R2=' ';
    cuentaTiempo=7;
    imprimirPregunta=0;
    for(cuentaTiempo=7; cuentaTiempo>0; cuentaTiempo--)
    { 
        sleep(2);
        while(imprimirPregunta==0)     
        {  
            imprimirPregunta=imprimirPregunta+1;
            structurePregunta = strtok(segmentoDeCadena1, s1);
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            
            R2=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R2)
            {
                case 'A': printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                break;
                case 'B': printf("---CORRECTO---");
                            res2=1;
                break;
                case 'C': printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                            res2=1;
                break;
                default: printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                break;
            }break;// Pasar a siguiente pregunta
        }
    }
    return res2;
}


int estructuraPregunta3()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo
{
    char R3=' ';
    cuentaTiempo=7;
    imprimirPregunta=0;
    for(cuentaTiempo=7; cuentaTiempo>0; cuentaTiempo--)
    { 
        sleep(2);
        while(imprimirPregunta==0)     
        {  
            imprimirPregunta=imprimirPregunta+1;
            structurePregunta = strtok(segmentoDeCadena2, s1);
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            
            R3=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R3)
            {
                case 'A': printf("---CORRECTO---");
                            res3=1;
                break;
                case 'B': printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                            res3=1;
                break;
                case 'C': printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                break;
                default: printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                break;
            }break;
        }
    }
    return res3;
}


int estructuraPregunta4()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo
{
    char R4=' ';
    cuentaTiempo=7;
    imprimirPregunta=0;
    for(cuentaTiempo=7; cuentaTiempo>0; cuentaTiempo--)
    { 
        sleep(2);
        while(imprimirPregunta==0)     
        {  
            imprimirPregunta=imprimirPregunta+1;
            structurePregunta = strtok(segmentoDeCadena3, s1);
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            
            R4=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            
            switch(R4)
            {
                case 'A': printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                break;
                case 'B': printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                break;
                case 'C': printf("---CORRECTO---");
                            res4=1;
                break;
                default: printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                break;
            }break;
        }
    }
    return res4;
}

int estructuraPregunta5()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R5=' ';
    cuentaTiempo=7;
    imprimirPregunta=0;
    for(cuentaTiempo=7; cuentaTiempo>0; cuentaTiempo--)
    { 
        sleep(2);
        while(imprimirPregunta==0)     
        {  
            imprimirPregunta=imprimirPregunta+1;
            structurePregunta = strtok(segmentoDeCadena4, s1);
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            
            R5=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R5)
            {
                case 'A': printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                break;
                case 'B': printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                break;
                case 'C': printf("---CORRECTO---");
                            res5=1;
                break;
                default: printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                break;
            }break;
        }
    }
    return res5;
}

int estructuraPregunta6()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R6=' '; //TECLA A LEER
    cuentaTiempo=7; //TIEMPO QUE SE PRESENTARA LA PREGUNTA
    imprimirPregunta=0;
    for(cuentaTiempo=7; cuentaTiempo>0; cuentaTiempo--)
    { 
        sleep(2);
        while(imprimirPregunta==0)     
        {  
            imprimirPregunta=imprimirPregunta+1;
            structurePregunta = strtok(segmentoDeCadena5, s1);
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            
            R6=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R6)
            {
                case 'A': printf("---CORRECTO---");
                            res6=1;
                break;
                case 'B':   printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                break;
                case 'C': printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                break;
                default: printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                break;
            }break;
        }
    }
    return res6;
}

int estructuraPregunta7()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R7=' ';
    cuentaTiempo=7;
    imprimirPregunta=0;
    for(cuentaTiempo=7; cuentaTiempo>0; cuentaTiempo--)
    { 
        sleep(2);
        while(imprimirPregunta==0)     
        {  
            imprimirPregunta=imprimirPregunta+1;
            structurePregunta = strtok(segmentoDeCadena6, s1);
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            
            R7=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R7)
            {
                case 'A': printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                break;
                case 'B': printf("---CORRECTO---");
                            res7=1;
                break;
                case 'C': printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                break;
                default: printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                break;
            }break;
        }
    }
    return res7;
}

int estructuraPregunta8()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R8=' ';
    cuentaTiempo=7;
    imprimirPregunta=0;
    for(cuentaTiempo=7; cuentaTiempo>0; cuentaTiempo--)
    { 
        sleep(2);
        while(imprimirPregunta==0)     
        {  
            imprimirPregunta=imprimirPregunta+1;
            structurePregunta = strtok(segmentoDeCadena7, s1);
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            
            R8=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R8)
            {
                case 'A': printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                break;
                case 'B': printf("---CORRECTO---");
                            res8=1;
                break;
                case 'C': printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                break;
                default: printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                break;
            }break;
        }
    }
    return res8;
}

int estructuraPregunta9()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R9=' ';
    cuentaTiempo=7;
    imprimirPregunta=0;
    for(cuentaTiempo=7; cuentaTiempo>0; cuentaTiempo--)
    { 
        sleep(2);
        while(imprimirPregunta==0)     
        {  
            imprimirPregunta=imprimirPregunta+1;
            structurePregunta = strtok(segmentoDeCadena8, s1);
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            
            R9=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R9)
            {
                case 'A': printf("---CORRECTO---");
                            res9=1;
                break;
                case 'B': printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                break;
                case 'C': printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                break;
                default: printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                break;
            }break;
        }
    }
    return res9;
}

int estructuraPregunta10()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R10=' ';
    cuentaTiempo=7;
    imprimirPregunta=0;
    for(cuentaTiempo=7; cuentaTiempo>0; cuentaTiempo--)
    { 
        sleep(2);
        while(imprimirPregunta==0)     
        {  
            imprimirPregunta=imprimirPregunta+1;
            structurePregunta = strtok(segmentoDeCadena9, s1);
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            structurePregunta = strtok( NULL, s1 );
            printf("\n%s", structurePregunta);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R10=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R10)
            {
                case 'A': printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                break;
                case 'B': printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                break;
                case 'C': printf("---CORRECTO---");
                            res10=1;
                break;
                default: printf("INCORRECTO");
                if(comodin==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodin=comodin-1;
                    comodin2=1;
                }
                break;
            }break;
        }
    }
    return res10;
}