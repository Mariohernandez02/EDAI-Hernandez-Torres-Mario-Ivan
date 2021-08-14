#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h> 
#include <unistd.h>     //TECLA
#include <fcntl.h> 

int cuentaPreparate();  //Cuenta Regresiva preparate para contestar o el juego ya va a comenzar

int estructuraP1(); //Formulacion de la  pregunta 1 al azar
int estructuraP2(); //Formulacion de la pregunta 2 al azar
int estructuraP3(); //Formulacion de la pregunta 3 al azar
int estructuraP4(); //Formulacion de la pregunta 4 al azar
int estructuraP5(); //Formulacion de la pregunta 5 al azar
int estructuraP6(); //Formulacion de la pregunta 6 al azar
int estructuraP7(); //Formulacion de la pregunta 7 al azar
int estructuraP8(); //Formulacion de la pregunta 8 al azar
int estructuraP9(); //Formulacion de la pregunta 9 al azar
int estructuraP10(); //Formulacion de la pregunta 10 al azar

char *segmentDeCaden, *segmentDeCaden1, *segmentDeCaden2, *segmentDeCaden3, *segmentDeCaden4, *segmentDeCaden5, *segmentDeCaden6, *segmentDeCaden7,*segmentDeCaden9, *segmentDeCaden8, *segmentDeCaden10;
char *structurePreguntaaa;
char sz1[2]=":";     //separdor de preguntas e incisos
char sz2[2]="#";     //separa las 10 preguntas del archivo

int respu1=0, respu2=0, respu3=0, respu4=0, respu5=0, respu6=0, respu7=0, respu8=0, respu9=0, respu10=0; //Preguntas que tuvimos correctas
int comod=0;
int comod2=0;
int faltaaa=3;
int participacionnn=0;

int ganastDiner(); //Ganaste 100 pesos o perdiste en el juego

int mprimirPregunt=0;
int cuentTiemp=7;            //Duracion de la pregunta

int jugarOtraV=0;  //Evaluar pregunta de quieres jugar de nuevo? 

int cuentaPreparateee()//funcion que se manda a llamar en deportesPreguntas() que sirve para hacer el conteo regresivo para iniciar el juego
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

int todasPreguntas()//funcion que sirve para imprimir las Preguntas de forma aleatoria
{
    int jugarOtraV=0;
    int ganarrrr=0;
    comod=0;
    comod2=0;
    //do while para que en caso de que jugarNuevamente sea igual a uno osea que si quiera jugar de nuevo, se vuelva a ejecutar todo el programa.
    do{
        char Preguntas[4000];
        FILE *archivo;
        
        int aleatorios[5], indice=0;
    	
    	int A1=0, A2=0, A3=0, A4=0, A5=0, dif=2;
    	
    	respu1=0, respu2=0, respu3=0, respu4=0, respu5=0, respu6=0, respu7=0, respu8=0, respu9=0, respu10=0;
    	
    	cuentaPreparate();
    	sleep(1);
    	
    	archivo = fopen ("Campechaneado.txt", "r");
    	if(archivo!=NULL)
    	{
    	    //separa las todas las Preguntas del archivo de forma: pregunta:inciso a:incisob:incisoc, y cada pregunta la guarda en un apuntador llamado segmeDeCadena...
    	    fgets(Preguntas, 4000, archivo);
    	    segmentDeCaden = strtok( Preguntas , sz2 );//EJEMPLO CADENA= "PREGUNTA:INCISO A:INCISO B:INCISO C "
    	    segmentDeCaden1 = strtok( NULL, sz2 );  
    	    segmentDeCaden2 = strtok( NULL, sz2 );
    	    segmentDeCaden3 = strtok( NULL, sz2 );
    	    segmentDeCaden4 = strtok( NULL, sz2 );
    	    segmentDeCaden5 = strtok( NULL, sz2 );
    	    segmentDeCaden6 = strtok( NULL, sz2 );
    	    segmentDeCaden7 = strtok( NULL, sz2 );
    	    segmentDeCaden8 = strtok( NULL, sz2 );
    	    segmentDeCaden9 = strtok( NULL, sz2 );
    	    segmentDeCaden10 = strtok( NULL, sz2 );
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
            case 1: estructuraP1();
            break;
            case 2: estructuraP2();
            break;
            case 3: estructuraP3();
            break;
            case 4: estructuraP4();
            break;
            case 5: estructuraP5();
            break;
            case 6: estructuraP6();
            break;
            case 7: estructuraP7();
            break;
            case 8: estructuraP8();
            break;
            case 9: estructuraP9();
            break;
            case 10: estructuraP10();
            break;
        }
        switch(A2)//seleccion de la segunda pregunta aleatoria dependiendo A2
        {
            case 1: estructuraP1();
            break;
            case 2: estructuraP2();
            break;
            case 3: estructuraP3();
            break;
            case 4: estructuraP4();
            break;
            case 5: estructuraP5();
            break;
            case 6: estructuraP6();
            break;
            case 7: estructuraP7();
            break;
            case 8: estructuraP8();
            break;
            case 9: estructuraP9();
            break;
            case 10: estructuraP10();
            break;
        }
        switch(A3)//seleccion de la tercer pregunta aleatoria dependiendo A3
        {
            case 1: estructuraP1();
            break;
            case 2: estructuraP2();
            break;
            case 3: estructuraP3();
            break;
            case 4: estructuraP4();
            break;
            case 5: estructuraP5();
            break;
            case 6: estructuraP6();
            break;
            case 7: estructuraP7();
            break;
            case 8: estructuraP8();
            break;
            case 9: estructuraP9();
            break;
            case 10: estructuraP10();
            break;
        }
        switch(A4)//seleccion de la cuarta pregunta aleatoria dependiendo A4
        {
            case 1: estructuraP1();
            break;
            case 2: estructuraP2();
            break;
            case 3: estructuraP3();
            break;
            case 4: estructuraP4();
            break;
            case 5: estructuraP5();
            break;
            case 6: estructuraP6();
            break;
            case 7: estructuraP7();
            break;
            case 8: estructuraP8();
            break;
            case 9: estructuraP9();
            break;
            case 10: estructuraP10();
            break;
        }
        switch(A5)//seleccion de la quinta pregunta aleatoria dependiendo A5
        {
            case 1: estructuraP1();
            break;
            case 2: estructuraP2();
            break;
            case 3: estructuraP3();
            break;
            case 4: estructuraP4();
            break;
            case 5: estructuraP5();
            break;
            case 6: estructuraP6();
            break;
            case 7: estructuraP7();
            break;
            case 8: estructuraP8();
            break;
            case 9: estructuraP9();
            break;
            case 10: estructuraP10();
            break;
        }
        ganarrrr=comod2+respu1+respu2+respu3+respu4+respu5+respu6+respu7+respu8+respu9+respu10;//suma de los puntos de cada pregunta en caso de ser correcta y en caso de tener un comodin.
        if(ganarrrr>=5)//en caso de que la suma de los puntos sea 5 osea conteste todas las preguntas bien se va a imprimir el mensaje.
        {
            printf("\n\nFELICIDADES :D!!!!!!!\nSe te va a transerir $300 mxn a tu cuenta bancaria\n\n");
             sleep(5);
             jugarOtraV=100;
        }
        else//en caso contrario de que no conteste todas las preguntas bien se va a realizar lo siguiente
        {
            participacionnn=participacionnn+1;
           if(participacionnn==3)//En caso de que las participaciones sea igual a 3 se va a ejecutar lo siguiente
           {
               comod=comod+1;//Es la suma de las participaciones que lleva
               printf("\n\nSe te agrego un comodin\n\n");
               sleep(5);
               system ("clear");
               printf("\n¿Te gustaria volver a jugar?\n\t 1.Si    2.Regresar al menú\n\t:");
               scanf("%i", &jugarOtraV);
               participacionnn=0;
            
           }
           else//en caso contrario de que las participaciones no sea igual a 3
           {
               system ("clear");//limpia pantalla
               faltaaa=3-participacionnn;//es para que vaya leyendo las participaciones que lleva para mencionarle cuantas participaciones le hacen falta para seguir jugando
               printf("\n\nTe falta jugar %i veces para obtener un comodin\n", faltaaa);//menciona cuantas veces le falta para que se le agregue el comodin
               if(participacionnn==3)
               {
                   faltaaa=3;
               }
               
               printf("\n¿Te gustaria volver a jugar?\n\t1.Si    2.Regresar al menú\n\t:");
               scanf("%i", &jugarOtraV);
           }
        }
    }while(jugarOtraV==1);
    return 220;
}

int estructuraP1()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R1=' ';
    cuentTiemp=7;
    mprimirPregunt=0;
    for(cuentTiemp=7; cuentTiemp>0; cuentTiemp--)
    { 
        sleep(1);
        while(mprimirPregunt==0)     
        {  
            mprimirPregunt=mprimirPregunt+1;
            structurePreguntaaa = strtok(segmentDeCaden, sz1);
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R1=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R1)
            {
                case 'A': printf("INCORRECTO");
                if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
                break;
                case 'B': printf("---CORRECTO---");
                            respu1=1;
                break;
                case 'C': printf("INCORRECTO");
                if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
                break;
            }break;
            printf("INCORRECTO");
            if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
        }
    }
    return respu1;
}

int estructuraP2()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R2=' ';
    cuentTiemp=7;
    mprimirPregunt=0;
    for(cuentTiemp=7; cuentTiemp>0; cuentTiemp--)
    { 
        sleep(2);
        while(mprimirPregunt==0)     
        {  
            mprimirPregunt=mprimirPregunt+1;
            structurePreguntaaa = strtok(segmentDeCaden1, sz1);
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R2=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R2)
            {
                case 'A': printf("INCORRECTO");
                if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
                break;
                case 'B': printf("INCORRECTO");
                if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
                break;
                case 'C': printf("---CORRECTO---");
                            respu2=1;
                break;
                default: printf("INCORRECTO");
                if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
                break;
            }break;// Pasar a siguiente pregunta
        }
    }
    return respu2;
}


int estructuraP3()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R3=' ';
    cuentTiemp=7;
    mprimirPregunt=0;
    for(cuentTiemp=7; cuentTiemp>0; cuentTiemp--)
    { 
        sleep(2);
        while(mprimirPregunt==0)     
        {  
            mprimirPregunt=mprimirPregunt+1;
            structurePreguntaaa = strtok(segmentDeCaden2, sz1);
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R3=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R3)
            {
                case 'A': printf("---CORRECTO---");
                            respu3=1;
                break;
                case 'B': printf("INCORRECTO");
                if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
                break;
                case 'C': printf("INCORRECTO");
                if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
                break;
                default: printf("INCORRECTO");
                if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
                break;
            }break;
        }
    }
    return respu3;
}


int estructuraP4()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R4=' ';
    cuentTiemp=7;
    mprimirPregunt=0;
    for(cuentTiemp=7; cuentTiemp>0; cuentTiemp--)
    { 
        sleep(2);
        while(mprimirPregunt==0)     
        {  
            mprimirPregunt=mprimirPregunt+1;
            structurePreguntaaa = strtok(segmentDeCaden3, sz1);
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R4=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R4)
            {
                case 'A': printf("---CORRECTO---");
                            respu4=1;
                break;
                case 'B': printf("INCORRECTO");
                if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
                break;
                case 'C': printf("INCORRECTO");
                if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
                break;
                default: printf("INCORRECTO");
                if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
                break;
            }break;
        }
    }
    return respu4;
}

int estructuraP5()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R5=' ';
    cuentaTiempo=7;
    mprimirPregunt=0;
    for(cuentTiemp=7; cuentTiemp>0; cuentTiemp--)
    { 
        sleep(2);
        while(mprimirPregunt==0)     
        {  
            mprimirPregunt=mprimirPregunt+1;
            structurePreguntaaa = strtok(segmentDeCaden4, sz1);
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R5=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R5)
            {
                case 'A': printf("INCORRECTO");
                if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
                break;
                case 'B': printf("INCORRECTO");
                if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
                break;
                case 'C': printf("---CORRECTO---");
                            respu5=1;
                break;
                default: printf("INCORRECTO");
                if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
                break;
            }break;
        }
    }
    return respu5;
}

int estructuraP6()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R6=' '; //TECLA A LEER
    cuentTiemp=7; //TIEMPO QUE SE PRESENTARA LA PREGUNTA
    mprimirPregunt=0;
    for(cuentTiemp=7; cuentTiemp>0; cuentTiemp--)
    { 
        sleep(2);
        while(mprimirPregunt==0)     
        {  
            mprimirPregunt=mprimirPregunt+1;
            structurePreguntaaa = strtok(segmentDeCaden5, sz1);
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R6=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R6)
            {
                case 'A': printf("---CORRECTO---");
                            respu6=1;
                break;
                case 'B':printf("INCORRECTO");
                if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
                break;
                case 'C': printf("INCORRECTO");
                if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
                break;
                default: printf("INCORRECTO");
                if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
                break;
            }break;
        }
    }
    return respu6;
}

int estructuraP7()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R7=' ';
    cuentTiemp=7;
    mprimirPregunt=0;
    for(cuentTiemp=7; cuentTiemp>0; cuentTiemp--)
    { 
        sleep(2);
        while(mprimirPregunt==0)     
        {  
            mprimirPregunt=mprimirPregunt+1;
            structurePreguntaaa = strtok(segmentDeCaden6, sz1);
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R7=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R7)
            {
                case 'A': printf("INCORRECTO");
                if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
                break;
                case 'B': printf("INCORRECTO");
                if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
                break;
                case 'C': printf("---CORRECTO---");
                            respu7=1;
                break;
                default: printf("INCORRECTO");
                if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
                break;
            }break;
        }
    }
    return respu7;
}

int estructuraP8()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R8=' ';
    cuentTiemp=7;
    mprimirPregunt=0;
    for(cuentTiemp=7; cuentTiemp>0; cuentTiemp--)
    { 
        sleep(2);
        while(mprimirPregunt==0)     
        {  
            mprimirPregunt=mprimirPregunt+1;
            structurePreguntaaa = strtok(segmentDeCaden7, sz1);
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R8=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R8)
            {
                case 'A': printf("INCORRECTO");
                if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
                break;
                case 'B': printf("INCORRECTO");
                if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
                break;
                case 'C': printf("---CORRECTO---");
                            respu8=1;
                break;
                default: printf("INCORRECTO");
                if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
                break;
            }break;
        }
    }
    return respu8;
}

int estructuraP9()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R9=' ';
    cuentTiemp=7;
    mprimirPregunt=0;
    for(cuentTiemp=7; cuentTiemp>0; cuentTiemp--)
    { 
        sleep(2);
        while(mprimirPregunt==0)     
        {  
            mprimirPregunt=mprimirPregunt+1;
            structurePreguntaaa = strtok(segmentDeCaden8, sz1);
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R9=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R9)
            {
                case 'A': printf("INCORRECTO");
                if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
                break;
                case 'B': printf("---CORRECTO---");
                            respu9=1;
                break;
                case 'C': printf("INCORRECTO");
                if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
                break;
                default: printf("INCORRECTO");
                if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
                break;
            }break;
        }
    }
    return respu9;
}

int estructuraP10()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R10=' ';
    cuentTiemp=7;
    mprimirPregunt=0;
    for(cuentTiemp=7; cuentTiemp>0; cuentTiemp--)
    { 
        sleep(2);
        while(mprimirPregunt==0)     
        {  
            mprimirPregunt=mprimirPregunt+1;
            structurePreguntaaa = strtok(segmentDeCaden9, sz1);
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            structurePreguntaaa = strtok( NULL, sz1 );
            printf("\n%s", structurePreguntaaa);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R10=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R10)
            {
                case 'A': printf("INCORRECTO");
                if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
                break;
                case 'B': printf("---CORRECTO---");
                            respu10=1;
                break;
                case 'C': printf("INCORRECTO");
                if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
                break;
                default: printf("INCORRECTO");
                if(comod==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    comod=comod-1;
                    comod2=1;
                }
                break;
            }break;
        }
    }
    return respu10;
}
