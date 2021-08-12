#limpiar pantalla
import os
os.system("cls")
op='0'
edadto=0
pr=0
h=0
dat=[]
#Menu de opciones
print("BIENVENIDO!!!")
while(op!='3'):
    print("1.Registrarse\n2.Checar semaforo\n3.Salir")
    op=input("Elige la opcion: ")
    #registrando datos
    if op=='1':
        edad=input("Ingrese su edad: ")
        ind=input("Ingrese el indicador de COVID:")
        if ind>='0.8':
            print("Tiene COVID :(\n")
            edadto=int(edadto)+int(edad)
            h=int(h)+1
            pr=int(edadto)/int(h)
            print("La edad promedio con COVID es: "+str(pr))
        else:
            print("No tiene COVID :)\n")
        reg=edad+','+ind+'\n'
        dat.append(reg)
    #Checar el color del semaforo    
    elif op=='2':
        #leer datos del archivo vd.csv
        import pandas as pd
        datos=pd.read_csv('bd.csv' ,header=0)

        #leyendo datos unicamente de una columna y separando los datos que sean mayores o iguales a 0.8
        a=datos['indicador']
        cc=str(len(a[a>=0.8]))
        sc=str(len(a[a<0.8]))
        print("El numero de personas con COVID es: "+str(cc))
        print("El numero de personas sin COVID es: "+str(sc))

        #Determinando el color del semaforo dependiendo la cantidad de personas infectadas
        if cc=='0':
            print("\nEl color del semaforo es verde!!!\n")
        elif cc<='30':
            print("\nEl color del semaforo es amarillo!!!\n")
        elif cc<='70':
            print("\nEl color del semaforo es naranja!!!\n")
        else:
            print("El color del semaforo es ROJO!!!\n")


    else:
        print("Hasta la proxima!!!")

#Guardando los datos del registro
o=open("bd.csv","a")
o.writelines(dat)
o.close()

