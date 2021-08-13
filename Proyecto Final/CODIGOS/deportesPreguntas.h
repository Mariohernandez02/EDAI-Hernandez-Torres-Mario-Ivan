#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h> 
#include <unistd.h>     //TECLA
#include <fcntl.h> 
#include <unistd.h>
//prototipos de funciones
int cuentPreparat();  //Cuenta Regresiva

//Formulacion de la preguntas al azar
int estructurPregunt1(); 
int estructurPregunt2();
int estructurPregunt3();
int estructurPregunt4();
int estructurPregunt5();
int estructurPregunt6();
int estructurPregunt7();
int estructurPregunt8();
int estructurPregunt9();
int estructurPregunt10();

int ganasDinero();//Al terminar el juego se te enunciara que ganaste o si quieres volver a jugar 

//Variables globales y apuntadores para que se ejecuten de manera adecuada las diferntes funciones
char *segmeDeCadena, *segmeDeCadena1, *segmeDeCadena2, *segmeDeCadena3, *segmeDeCadena4, *segmeDeCadena5, *segmeDeCadena6, *segmeDeCadena7,*segmeDeCadena9, *segmeDeCadena8, *segmeDeCadena10;
char *structurPregunt;
                //separadores
char sm1[2]=":";//separa la pregunta y los incisos.
char sm2[2]="#";//separa todo el texto preguntas con sus respectivas respuestas

int r1=0, r2=0, r3=0, r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0;//Preguntas que tuvimos correctas
int com=0;
int com2=0;
int f=3;
int imprimirPreguntaa=0;
int cuentaTiempoo=7;   //Duracion de la pregunta
int jugarNuevamente=0;

int p=0;//participacion

int cuentPreparat()//funcion que se manda a llamar en deportesPreguntas() que sirve para hacer el conteo regresivo para iniciar el juego
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

int deportesPreguntas()//funcion que sirve para imprimir las Preguntas de forma aleatoria
{
    int jugarNuevamente=0;
    int win=0;
    com=0;
    com2=0;
    //do while para que en caso de que jugarNuevamente sea igual a uno osea que si quiera jugar de nuevo, se vuelva a ejecutar todo el programa.
    do{
        
        char Preguntas[3000];
        FILE *archivo;
        int aleatorios[5], indice=0;
    	int A1=0, A2=0, A3=0, A4=0, A5=0, dif=2;
    	r1=0, r2=0, r3=0, r4=0, r5=0, r6=0, r7=0, r8=0, r9=0, r10=0;

    	cuentPreparat();
    	sleep(1);
    	
    	archivo = fopen ("deportes.txt", "r");
    	if(archivo!=NULL)
    	{
    	    //separa todas las Preguntas del archivo de forma: pregunta:inciso a:incisob:incisoc, y cada pregunta la guarda en un apuntador llamado segmeDeCadena...
    	    fgets(Preguntas, 3000, archivo);
    	    segmeDeCadena = strtok( Preguntas , sm2 );
    	    segmeDeCadena1 = strtok( NULL, sm2 );
    	    segmeDeCadena2 = strtok( NULL, sm2 );
    	    segmeDeCadena3 = strtok( NULL, sm2 );
    	    segmeDeCadena4 = strtok( NULL, sm2 );
    	    segmeDeCadena5 = strtok( NULL, sm2 );
    	    segmeDeCadena6 = strtok( NULL, sm2 );
    	    segmeDeCadena7 = strtok( NULL, sm2 );
    	    segmeDeCadena8 = strtok( NULL, sm2 );
    	    segmeDeCadena9 = strtok( NULL, sm2 );
    	    segmeDeCadena10 = strtok( NULL, sm2 );
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
            if((A1 || A2 || A3 || A4 || A5)==0)
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
            case 1: estructurPregunt1();
            break;
            case 2: estructurPregunt2();
            break;
            case 3: estructurPregunt3();
            break;
            case 4: estructurPregunt4();
            break;
            case 5: estructurPregunt5();
            break;
            case 6: estructurPregunt6();
            break;
            case 7: estructurPregunt7();
            break;
            case 8: estructurPregunt8();
            break;
            case 9: estructurPregunt9();
            break;
            case 10: estructurPregunt10();
            break;
        }
        switch(A2)//seleccion de la segunda pregunta aleatoria dependiendo A2
        {
            case 1: estructurPregunt1();
            break;
            case 2: estructurPregunt2();
            break;
            case 3: estructurPregunt3();
            break;
            case 4: estructurPregunt4();
            break;
            case 5: estructurPregunt5();
            break;
            case 6: estructurPregunt6();
            break;
            case 7: estructurPregunt7();
            break;
            case 8: estructurPregunt8();
            break;
            case 9: estructurPregunt9();
            break;
            case 10: estructurPregunt10();
            break;
        }
        switch(A3)//seleccion de la tercer pregunta aleatoria dependiendo A3
        {
            case 1: estructurPregunt1();
            break;
            case 2: estructurPregunt2();
            break;
            case 3: estructurPregunt3();
            break;
            case 4: estructurPregunt4();
            break;
            case 5: estructurPregunt5();
            break;
            case 6: estructurPregunt6();
            break;
            case 7: estructurPregunt7();
            break;
            case 8: estructurPregunt8();
            break;
            case 9: estructurPregunt9();
            break;
            case 10: estructurPregunt10();
            break;
        }
        switch(A4)//seleccion de la cuarta pregunta aleatoria dependiendo A4
        {
            case 1: estructurPregunt1();
            break;
            case 2: estructurPregunt2();
            break;
            case 3: estructurPregunt3();
            break;
            case 4: estructurPregunt4();
            break;
            case 5: estructurPregunt5();
            break;
            case 6: estructurPregunt6();
            break;
            case 7: estructurPregunt7();
            break;
            case 8: estructurPregunt8();
            break;
            case 9: estructurPregunt9();
            break;
            case 10: estructurPregunt10();
            break;
        }
        switch(A5)//seleccion de la quinta pregunta aleatoria dependiendo A5
        {
            case 1: estructurPregunt1();
            break;
            case 2: estructurPregunt2();
            break;
            case 3: estructurPregunt3();
            break;
            case 4: estructurPregunt4();
            break;
            case 5: estructurPregunt5();
            break;
            case 6: estructurPregunt6();
            break;
            case 7: estructurPregunt7();
            break;
            case 8: estructurPregunt8();
            break;
            case 9: estructurPregunt9();
            break;
            case 10: estructurPregunt10();
            break;
        }
        win=com2+r1+r2+r3+r4+r5+r6+r7+r8+r9+r10;//suma de los puntos de cada pregunta en caso de ser correcta y en caso de tener un comodin.
        if(win>=5)//en caso de que la suma de los puntos sea 5 osea conteste todas las preguntas bien se va a imprimir el mensaje.
        {
             printf("\n\nFELICIDADES :D!!!!!!!\nSe te va a transerir $50 mxn a tu cuenta bancaria\n\n");
             sleep(5);
             jugarNuevamente=100;
        }
        else//en caso contrario de que no conteste todas las preguntas bien se va a realizar lo siguiente
        {
           p=p+1;//Es la suma de las participaciones que lleva
           if(p==3)//En caso de que las participaciones sea igual a 3 se va a ejecutar lo siguiente
           {
               com=com+1;//se suma un comodin 
               printf("\n\n%i",com);
               printf("\n\nSe te agrego un comodin\n\n");
               sleep(5);
               system ("clear");
               printf("\n¿Te gustaria volver a jugar?\n\t 1.Si    2.Regresar al menú\n\t:");
               scanf("%i", &jugarNuevamente);
               p=0;//se va a volver a inicializar las participaciones por que ya se utilizo el comodin si es que no llega a ganar.
            
           }
           else//en caso contrario de que las participaciones no sea igual a 3
           {
               system ("clear");//limpia pantalla
               f=3-p;//es para que vaya leyendo las participaciones que lleva para mencionarle cuantas participaciones le hacen falta para seguir jugando
               printf("\n\nTe falta jugar %i veces para obtener un comodin\n", f);//menciona cuantas veces le falta para que se le agregue el comodin 
               if(p==3)
               {
                   f=3;
               }
               
               printf("\n¿Te gustaria volver a jugar?\n\t1.Si    2.Regresar al menú\n\t:");
               scanf("%i", &jugarNuevamente);
           }
        }

    }while(jugarNuevamente==1);
    return 220;
}



int estructurPregunt1()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R1=' ';
    cuentaTiempoo=7;
    imprimirPreguntaa=0;
    for(cuentaTiempoo=7; cuentaTiempoo>0; cuentaTiempoo--)
    { 
        sleep(1);
        while(imprimirPreguntaa==0)     
        {  
            imprimirPreguntaa=imprimirPreguntaa+1;
            structurPregunt = strtok(segmeDeCadena, sm1);
            printf("\n%s", structurPregunt);
            structurPregunt = strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            structurPregunt = strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            structurPregunt = strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R1=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R1)
            {
                case 'A': printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
                case 'B': printf("---CORRECTO---");
                            r1=1;
                break;
                case 'C': printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
                default: printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
            }break;
        }
    }
    return r1;
}

int estructurPregunt2()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R2=' ';
    cuentaTiempoo=7;
    imprimirPreguntaa=0;
    for(cuentaTiempoo=7; cuentaTiempoo>0; cuentaTiempoo--)
    { 
        sleep(2);
        while(imprimirPreguntaa==0)     
        {  
            imprimirPreguntaa=imprimirPreguntaa+1;
            structurPregunt = strtok(segmeDeCadena1, s1);
            printf("\n%s", structurPregunt);
            structurPregunt = strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            structurPregunt = strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            structurPregunt = strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R2=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R2)
            {
                case 'A': printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
                case 'B': printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
                case 'C': printf("---CORRECTO---");
                            r2=1;
                break;
                default: printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
            }break;
        }
    }
    return r2;
}


int estructurPregunt3()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R3=' ';
    cuentaTiempoo=7;
    imprimirPreguntaa=0;
    for(cuentaTiempoo=7; cuentaTiempoo>0; cuentaTiempoo--)
    { 
        sleep(2);
        while(imprimirPreguntaa==0)     
        {  
            imprimirPreguntaa=imprimirPreguntaa+1;
            structurPregunt= strtok(segmeDeCadena2, sm1);
            printf("\n%s", structurPregunt);
            structurPregunt = strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            structurPregunt = strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            structurPregunt = strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R3=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R3)
            {
                case 'A': printf("---CORRECTO---");
                r3=1;
                break;
                case 'B': printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
                case 'C': printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
                default: printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
            }break;
        }
    }
    return r3;
}


int estructurPregunt4()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R4=' ';
    cuentaTiempoo=7;
    imprimirPreguntaa=0;
    for(cuentaTiempoo=7; cuentaTiempoo>0; cuentaTiempoo--)
    { 
        sleep(2);
        while(imprimirPreguntaa==0)     
        {  
            imprimirPreguntaa=imprimirPreguntaa+1;
            structurPregunt = strtok(segmeDeCadena3, sm1);
            printf("\n%s", structurPregunt);
            structurPregunt = strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            structurPregunt = strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            structurPregunt = strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R4=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R4)
            {
                case 'A': printf("---CORRECTO---");
                            r4=1;
                break;
                case 'B': printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
                case 'C': printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
                default: printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
            }break;
        }
    }
    return r4;
}

int estructurPregunt5()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R5=' ';
    cuentaTiempoo=7;
    imprimirPreguntaa=0;
    for(cuentaTiempoo=7; cuentaTiempoo>0; cuentaTiempoo--)
    { 
        sleep(2);
        while(imprimirPreguntaa==0)     
        {  
            imprimirPreguntaa=imprimirPreguntaa+1;
            structurPregunt = strtok(segmeDeCadena4, sm1);
            printf("\n%s", structurPregunt);
            structurPregunt = strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            structurPregunt = strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            structurPregunt = strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R5=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R5)
            {
                case 'A': printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
                case 'B': printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
                case 'C': printf("---CORRECTO---");
                r5=1;
                break;
                default: printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
            }break;
        }
    }
    return r5;
}

int estructurPregunt6()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R6=' ';
    cuentaTiempoo=7;
    imprimirPreguntaa=0;
    for(cuentaTiempoo=7; cuentaTiempoo>0; cuentaTiempoo--)
    { 
        sleep(2);
        while(imprimirPreguntaa==0)     
        {  
            imprimirPreguntaa=imprimirPreguntaa+1;
            structurPregunt = strtok(segmeDeCadena5, sm1);
            printf("\n%s", structurPregunt);
            structurPregunt = strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            structurPregunt= strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            structurPregunt= strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R6=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R6)
            {
                case 'A':printf("---CORRECTO---");
                            r6 = 1;
                break;
                case 'B':printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
                case 'C': printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
                default: printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
            }break;
        }
    }
    return r6;
}

int estructurPregunt7()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R7=' ';
    cuentaTiempoo=7;
    imprimirPreguntaa=0;
    for(cuentaTiempoo=7; cuentaTiempoo>0; cuentaTiempoo--)
    { 
        sleep(2);
        while(imprimirPreguntaa==0)     
        {  
            imprimirPreguntaa=imprimirPreguntaa + 1;
            structurPregunt = strtok(segmeDeCadena6, sm1);
            printf("\n%s", structurPregunt);
            structurPregunt = strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            structurPregunt = strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            structurPregunt = strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R7=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R7)
            {
                case 'A': printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
                case 'B': printf("---CORRECTO---");
                            r7=1;
                break;
                case 'C': printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
                default: printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
            }break;
        }
    }
    return r7;
}

int estructurPregunt8()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo 
{
    char R8=' ';
    cuentaTiempoo=7;
    imprimirPreguntaa=0;
    for(cuentaTiempoo=7; cuentaTiempoo>0; cuentaTiempoo--)
    { 
        sleep(2);
        while(imprimirPreguntaa==0)     
        {  
            imprimirPreguntaa=imprimirPreguntaa + 1;
            structurPregunt = strtok(segmeDeCadena7, sm1);
            printf("\n%s", structurPregunt);
            structurPregunt = strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            structurPregunt = strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            structurPregunt = strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R8=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R8)
            {
                case 'A': printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
                case 'B': printf("---CORRECTO---");
                            r8=1;
                break;
                case 'C': printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
                default: printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
            }break;
        }
    }
    return r8;
}

int estructurPregunt9()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo
{
    char R9=' ';
    cuentaTiempoo=7;
    imprimirPreguntaa=0;
    for(cuentaTiempoo=7; cuentaTiempoo>0; cuentaTiempoo--)
    { 
        sleep(2);
        while(imprimirPreguntaa==0)     
        {  
            imprimirPreguntaa=imprimirPreguntaa+1;
            structurPregunt = strtok(segmeDeCadena8, sm1);
            printf("\n%s", structurPregunt);
            structurPregunt = strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            structurPregunt = strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            structurPregunt = strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R9=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R9)
            {
                case 'A': printf("---CORRECTO---");
                            r9=1;
                break;
                case 'B': printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
                case 'C': printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
                default: printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
            }break;
        }
    }
    return r9;
}

int estructurPregunt10()// sirve para imprimir la pregunta y los incisos y leer la respuesta si es correcta o incorrecta y en caso de tener un comodin quitartelo
{
    char R10=' ';
    cuentaTiempoo=7;
    imprimirPreguntaa=0;
    for(cuentaTiempoo=7; cuentaTiempoo>0; cuentaTiempoo--)
    { 
        sleep(2);
        while(imprimirPreguntaa==0)     
        {  
            imprimirPreguntaa=imprimirPreguntaa + 1;
            structurPregunt = strtok(segmeDeCadena9, sm1);
            printf("\n%s", structurPregunt);
            structurPregunt = strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            structurPregunt = strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            structurPregunt = strtok( NULL, sm1 );
            printf("\n%s", structurPregunt);
            printf("\t\tRESPUESTA: ");
        }
        setbuf(stdin, NULL);
        if(kbhit())	// Si detecta que se presionó una tecla
        {
            R10=getchar();//getchar() obtiene desde el buffer del teclado la tecla que se ha presionado
            switch(R10)
            {
                case 'A': printf("---CORRECTO---");
                            r10=1;
                break;
                case 'B': printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
                case 'C': printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
                default: printf("INCORRECTO");
                if(com==1)
                {
                    printf("\n\nSe ha aplicado el comodin de preguntas por tematica\n\n");
                    sleep(5);
                    com=com-1;
                    com2=1;
                }
                break;
            }break;
        }
    }
    return r10;
}
