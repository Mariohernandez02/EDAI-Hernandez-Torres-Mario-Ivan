#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h> 
#include <unistd.h>     //TECLA
#include <fcntl.h> 

int cuentaPreparat();  //Cuenta Regresiva preparate para contestar o el juego ya va a comenzar

//Formulacion de la preguntas al azar
int estructuraPregunt1(); //Formulacion de la  pregunta 1 al azar
int estructuraPregunt2(); //Formulacion de la pregunta 2 al azar
int estructuraPregunt3(); //Formulacion de la pregunta 3 al azar
int estructuraPregunt4(); //Formulacion de la pregunta 4 al azar
int estructuraPregunt5(); //Formulacion de la pregunta 5 al azar
int estructuraPregunt6(); //Formulacion de la pregunta 6 al azar
int estructuraPregunt7(); //Formulacion de la pregunta 7 al azar
int estructuraPregunt8(); //Formulacion de la pregunta 8 al azar
int estructuraPregunt9(); //Formulacion de la pregunta 9 al azar
int estructuraPregunt10(); //Formulacion de la pregunta 10 al azar

char *segmentoDeCaden, *segmentoDeCaden1, *segmentoDeCaden2, *segmentoDeCaden3, *segmentoDeCaden4, *segmentoDeCaden5, *segmentoDeCaden6, *segmentoDeCaden7,*segmentoDeCaden9, *segmentoDeCaden8, *segmentoDeCaden10;
char *structurPregunta;
char sl1[2]=":";     //separdor de preguntas e incisos
char sl2[2]="#";     //separa las 10 preguntas del archivo

int resp1=0, resp2=0, resp3=0, resp4=0, resp5=0, resp6=0, resp7=0, resp8=0, resp9=0, resp10=0; //Preguntas que tuvimos correctas

int falt=3;
int comodi=0;
int comodi2=0;
int partic=0;
int imprimirPregunt=0;
int cuentaTiemp=7;      //Duracion de la pregunta

int cuentaPreparat()//funcion que se manda a llamar en edaPreguntas() que sirve para hacer el conteo regresivo para iniciar el juego
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

int edaPreguntas()//funcion que sirve para imprimir las Preguntas de forma aleatoria
{
    int jugarOtraVe=0;
    int gan = 0;
    comodi=0;
    comodi2=0;
    //do while para que en caso de que jugarNuevamente sea igual a uno osea que si quiera jugar de nuevo, se vuelva a ejecutar todo el programa.
    do{
        
        char Preguntas[3000];
        FILE *archivo;
        
        int aleatorios[5], indice=0;
    	
    	int A1=0, A2=0, A3=0, A4=0, A5=0, dif=2;
    	
    	resp1=0, resp2=0, resp3=0, resp4=0, resp5=0, resp6=0, resp7=0, resp8=0, resp9=0, resp10=0;
    	
    	cuentaPreparate();
    	sleep(1);
    	
    	archivo = fopen ("eda.txt", "r");
    	if(archivo!=NULL)
    	{
    	    //separa las todas las Preguntas del archivo de forma: pregunta:inciso a:incisob:incisoc, y cada pregunta la guarda en un apuntador llamado segmeDeCadena...
    	    fgets(Preguntas, 3000, archivo);
    	    segmentoDeCaden = strtok( Preguntas , s2 );  //EJEMPLO CADENA= "PREGUNTA:INCISO A:INCISO B:INCISO C "
    	    segmentoDeCaden1 = strtok( NULL, sl2 );
    	    segmentoDeCaden2 = strtok( NULL, sl2 );
    	    segmentoDeCaden3 = strtok( NULL, sl2 );
    	    segmentoDeCaden4 = strtok( NULL, sl2 );
    	    segmentoDeCaden5 = strtok( NULL, sl2 );
    	    segmentoDeCaden6 = strtok( NULL, sl2 );
    	    segmentoDeCaden7 = strtok( NULL, sl2 );
    	    segmentoDeCaden8 = strtok( NULL, sl2 );
    	    segmentoDeCaden9 = strtok( NULL, sl2 );
    	    segmentoDeCaden10 = strtok( NULL, sl2 );
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
            case 1: estructuraPregunt1();
            break;
            case 2: estructuraPregunt2();
            break;
            case 3: estructuraPregunt3();
            break;
            case 4: estructuraPregunt4();
            break;
            case 5: estructuraPregunt5();
            break;
            case 6: estructuraPregunt6();
            break;
            case 7: estructuraPregunt7();
            break;
            case 8: estructuraPregunt8();
            break;
            case 9: estructuraPregunt9();
            break;
            case 10: estructuraPregunt10();
            break;
        }
        switch(A2)//seleccion de la segunda pregunta aleatoria dependiendo A2
        {
            case 1: estructuraPregunt1();
            break;
            case 2: estructuraPregunt2();
            break;
            case 3: estructuraPregunt3();
            break;
            case 4: estructuraPregunt4();
            break;
            case 5: estructuraPregunt5();
            break;
            case 6: estructuraPregunt6();
            break;
            case 7: estructuraPregunt7();
            break;
            case 8: estructuraPregunt8();
            break;
            case 9: estructuraPregunt9();
            break;
            case 10: estructuraPregunt10();
            break;
        }
        switch(A3)//seleccion de la tercer pregunta aleatoria dependiendo A3
        {
            case 1: estructuraPregunt1();
            break;
            case 2: estructuraPregunt2();
            break;
            case 3: estructuraPregunt3();
            break;
            case 4: estructuraPregunt4();
            break;
            case 5: estructuraPregunt5();
            break;
            case 6: estructuraPregunt6();
            break;
            case 7: estructuraPregunt7();
            break;
            case 8: estructuraPregunt8();
            break;
            case 9: estructuraPregunt9();
            break;
            case 10: estructuraPregunt10();
            break;
        }
        switch(A4)//seleccion de la cuarta pregunta aleatoria dependiendo A4
        {
            case 1: estructuraPregunt1();
            break;
            case 2: estructuraPregunt2();
            break;
            case 3: estructuraPregunt3();
            break;
            case 4: estructuraPregunt4();
            break;
            case 5: estructuraPregunt5();
            break;
            case 6: estructuraPregunt6();
            break;
            case 7: estructuraPregunt7();
            break;
            case 8: estructuraPregunt8();
            break;
            case 9: estructuraPregunt9();
            break;
            case 10: estructuraPregunt10();
            break;
        }
        switch(A5)//seleccion de la quinta pregunta aleatoria dependiendo A5
        {
            case 1: estructuraPregunt1();
            break;
            case 2: estructuraPregunt2();
            break;
            case 3: estructuraPregunt3();
            break;
            case 4: estructuraPregunt4();
            break;
            case 5: estructuraPregunt5();
            break;
            case 6: estructuraPregunt6();
            break;
            case 7: estructuraPregunt7();
            break;
            case 8: estructuraPregunt8();
            break;
            case 9: estructuraPregunt9();
            break;
            case 10: estructuraPregunt10();
            break;
        }
        gan= comodi2+resp1+resp2+resp3+resp4+resp5+resp6+resp7+resp8+resp9+resp10;//suma de los puntos de cada pregunta en caso de ser correcta y en caso de tener un comodin.
        
        if(gan >= 5)//en caso de que la suma de los puntos sea 5 osea conteste todas las preguntas bien se va a imprimir el mensaje.
        {
            printf("\n\nFELICIDADES :D!!!!!!!\nSe te va a transerir $50 mxn a tu cuenta bancaria");
            sleep(5);
            jugarOtraVe =10;
        }
        else//en caso contrario de que no conteste todas las preguntas bien se va a realizar lo siguiente
        {
           partic=partic+1;//Es la suma de las participaciones que lleva
               if(partic==3)//En caso de que las participaciones sea igual a 3 se va a ejecutar lo siguiente
               {
                   comodi=comodi + 1;//se suma un comodin 
                   printf("\n\nSe te agrego un comodin\n\n");
                   sleep(5);
                   system ("clear");
                   printf("\n¿Te gustaria volver a jugar?\n\t 1.Si    2.Regresar al menú\n\t:");
                   scanf("%i", &jugarOtraVe);
                   partic=0;//se va a volver a inicializar las participaciones por que ya se utilizo el comodin si es que no llega a ganar.
               }
               else//en caso contrario de que las participaciones no sea igual a 3
               {
                   system ("clear");//limpia pantalla
                   falt= 3 - partic;//es para que vaya leyendo las participaciones que lleva para mencionarle cuantas participaciones le hacen falta para seguir jugando
                   printf("\n\nTe falta jugar %i veces para obtener un comodin\n", falt);
                   if(partic==3)
                   {
                       falt=3;
                   }
                   
                   printf("\n¿Te gustaria volver a jugar?\n\t1.Si    2.Regresar al menú\n\t:");
                   scanf("%i", &jugarOtraVe);
               }
            }
        
    }while(jugarOtraVe==1);
    return 220;
}

int estructuraPregunt1()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R1=' ';
    cuentaTiemp=7;
    imprimirPregunt=0;
    for(cuentaTiemp=7; cuentaTiemp>0; cuentaTiemp--)
    { 
        sleep(1);
        while(imprimirPregunt==0)     
        {  
            imprimirPregunt=imprimirPregunt+1;
            structurPregunta = strtok(segmentoDeCaden, sl1);
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R1=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R1)
            {
                case 'A': printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
                case 'B': printf("---CORRECTO---");
                            resp1=1;
                break;
                case 'C': printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
                default: printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
            }break;
        }
    }
    return resp1;
}

int estructuraPregunt2()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R2=' ';
    cuentaTiemp=7;
    imprimirPregunt=0;
    for(cuentaTiemp=7; cuentaTiemp>0; cuentaTiemp--)
    { 
        sleep(2);
        while(imprimirPregunt==0)     
        {  
            imprimirPregunt=imprimirPregunt+1;
            structurPregunta = strtok(segmentoDeCaden1, sl1);
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R2=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R2)
            {
                case 'A': printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
                case 'B': printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
                case 'C': printf("---CORRECTO---");
                            resp2=1;
                break;
                default: printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
            }break;// Pasar a siguiente pregunta
        }
    }
    return resp2;
}

int estructuraPregunt3()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R3=' ';
    cuentaTiemp=7;
    imprimirPregunt=0;
    for(cuentaTiemp=7; cuentaTiemp>0; cuentaTiemp--)
    { 
        sleep(2);
        while(imprimirPregunt==0)     
        {  
            imprimirPregunt=imprimirPregunt+1;
            structurPregunta = strtok(segmentoDeCaden2, sl1);
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R3=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R3)
            {
                case 'A': printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
                case 'B': printf("---CORRECTO---");
                            resp3=1;
                break;
                case 'C': printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
                default: printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
            }break;
        }
    }
    return resp3;
}

int estructuraPregunt4()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R4=' ';
    cuentaTiemp=7;
    imprimirPregunt=0;
    for(cuentaTiemp=7; cuentaTiemp>0; cuentaTiemp--)
    { 
        sleep(2);
        while(imprimirPregunt==0)     
        {  
            imprimirPregunt=imprimirPregunt+1;
            structurPregunta = strtok(segmentoDeCaden3, sl1);
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R4=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R4)
            {
                case 'A': printf("---CORRECTO---");
                            resp4=1;
                break;
                case 'B': printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
                case 'C': printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
                default: printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
            }break;
        }
    }
    return resp4;
}

int estructuraPregunt5()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R5=' ';
    cuentaTiemp=7;
    imprimirPregunt=0;
    for(cuentaTiemp=7; cuentaTiemp>0; cuentaTiemp--)
    { 
        sleep(2);
        while(imprimirPregunt==0)     
        {  
            imprimirPregunt=imprimirPregunt+1;
            structurPregunta = strtok(segmentoDeCaden4, sl1);
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R5=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R5)
            {
                case 'A': printf("---CORRECTO---");
                            resp5=1;
                break;
                case 'B': printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
                case 'C': printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
                default: printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
            }break;
        }
    }
    return resp5;
}

int estructuraPregunt6()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R6=' '; //TECLA A LEER
    cuentaTiemp=7; //TIEMPO QUE SE PRESENTARA LA PREGUNTA
    imprimirPregunt=0;
    for(cuentaTiemp=7; cuentaTiemp>0; cuentaTiemp--)
    { 
        sleep(2);
        while(imprimirPregunt==0)     
        {  
            imprimirPregunt=imprimirPregunt+1;
            structurPregunta = strtok(segmentoDeCaden5, sl1);
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R6=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R6)
            {
                case 'A':  printf("---CORRECTO---");
                            resp6=1;
                break;
                case 'B':printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
                case 'C': printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
                default: printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
            }break;
        }
    }
    return resp6;
}

int estructuraPregunt7()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R7=' ';
    cuentaTiemp=7;
    imprimirPregunt=0;
    for(cuentaTiemp=7; cuentaTiemp>0; cuentaTiemp--)
    { 
        sleep(2);
        while(imprimirPregunt==0)     
        {  
            imprimirPregunt=imprimirPregunt+1;
            structurPregunta = strtok(segmentoDeCaden6, sl1);
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R7=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R7)
            {
                case 'A': printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
                case 'B': printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
                case 'C': printf("---CORRECTO---");
                            resp7=1;
                break;
                default: printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
            }break;
        }
    }
    return resp7;
}

int estructuraPregunt8()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R8=' ';
    cuentaTiemp=7;
    imprimirPregunt=0;
    for(cuentaTiemp=7; cuentaTiemp>0; cuentaTiemp--)
    { 
        sleep(2);
        while(imprimirPregunt==0)     
        {  
            imprimirPregunt=imprimirPregunt+1;
            structurPregunta = strtok(segmentoDeCaden7, sl1);
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R8=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R8)
            {
                case 'A': printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
                case 'B': printf("---CORRECTO---");
                            resp8=1;
                break;
                case 'C': printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
                default: printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
            }break;
        }
    }
    return resp8;
}

int estructuraPregunt9()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R9=' ';
    cuentaTiemp=7;
    imprimirPregunt=0;
    for(cuentaTiemp=7; cuentaTiemp>0; cuentaTiemp--)
    { 
        sleep(2);
        while(imprimirPregunt==0)     
        {  
            imprimirPregunt=imprimirPregunt+1;
            structurPregunta = strtok(segmentoDeCaden8, sl1);
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R9=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R9)
            {
                case 'A': printf("---CORRECTO---");
                            resp9=1;
                break;
                case 'B': printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
                case 'C': printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
                default: printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
            }break;
        }
    }
    return resp9;
}

int estructuraPregunt10()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo
{
    char R10=' ';
    cuentaTiemp=7;
    imprimirPregunt=0;
    for(cuentaTiemp=7; cuentaTiemp>0; cuentaTiemp--)
    { 
        sleep(2);
        while(imprimirPregunt==0)     
        {  
            imprimirPregunt=imprimirPregunt+1;
            structurPregunta = strtok(segmentoDeCaden9, sl1);
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            structurPregunta = strtok( NULL, sl1 );
            printf("\n%s", structurPregunta);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R10=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R10)
            {
                case 'A': printf("---CORRECTO---");
                            resp10=1;
                break;
                case 'B': printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
                case 'C': printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
                default: printf("INCORRECTO");
                if(comodi==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comodi = comodi - 1;
                    comodi2 = 1;
                }
                break;
            }break;
        }
    }
    return resp10;
}