import os
from src.classes.Persona import Persona
from src.DataStructs.ArbolB.ArbolB import ArbolB
from src.DataStructs.Grafo.ListaAdyacencia import ListaAdyacencia
from src.classes.Vertice import Vertice

def writeFile(contenido: str):
    with open('./reports/arbolb.dot', 'w') as file:
        file.write(contenido);

def generatedReport(content: str):
    writeFile(content);
    
    #path: str = os.path;
    
    result: int = os.system(f"dot -Tpng reports\\arbolb.dot -o reports\\arbolb.png");
    
    if result == 0:
        print("Reporte generado satisfactoriamente...");
    
    os.system("wsl feh reports/arbolb.png");

def main() -> None:
    
    persona = Persona("Elian", 24);
    
    print("Hola Mundo");
    hola = 10;
    print(hola);
    hola = "Adios";
    print(hola);
    print(persona);
    
    arbolB: ArbolB = ArbolB(5);
    
    '''arbolB.insertar_clave(50);
    arbolB.insertar_clave(20);
    arbolB.insertar_clave(70);
    arbolB.insertar_clave(60);
    arbolB.insertar_clave(40);
    arbolB.insertar_clave(80);
    arbolB.insertar_clave(75);
    arbolB.insertar_clave(65);
    arbolB.insertar_clave(30);
    arbolB.insertar_clave(25);
    arbolB.insertar_clave(35);
    arbolB.insertar_clave(45);
    arbolB.insertar_clave(37);
    arbolB.insertar_clave(49);
    arbolB.insertar_clave(55);
    arbolB.insertar_clave(69);
    arbolB.insertar_clave(59);
    arbolB.insertar_clave(5);
    arbolB.insertar_clave(10);
    arbolB.insertar_clave(15);
    arbolB.insertar_clave(0);
    arbolB.insertar_clave(3);
    arbolB.insertar_clave(8);
    arbolB.insertar_clave(39);
    arbolB.insertar_clave(31);
    arbolB.insertar_clave(36);
    arbolB.insertar_clave(1);
    arbolB.insertar_clave(2);
    arbolB.insertar_clave(4);
    arbolB.insertar_clave(6);
    arbolB.insertar_clave(7);
    arbolB.insertar_clave(9);
    arbolB.insertar_clave(11);
    arbolB.insertar_clave(12);
    arbolB.insertar_clave(13);
    arbolB.insertar_clave(16);
    arbolB.insertar_clave(17);
    arbolB.insertar_clave(18);
    arbolB.insertar_clave(19);
    arbolB.insertar_clave(21);
    arbolB.insertar_clave(22);
    arbolB.insertar_clave(23);
    arbolB.insertar_clave(24);
    arbolB.insertar_clave(26);
    arbolB.insertar_clave(27);
    arbolB.insertar_clave(28);
    arbolB.insertar_clave(29);
    arbolB.insertar_clave(32);
    arbolB.insertar_clave(33);
    arbolB.insertar_clave(34);
    arbolB.insertar_clave(41);
    arbolB.insertar_clave(42);
    arbolB.insertar_clave(43);
    arbolB.insertar_clave(44);
    arbolB.insertar_clave(46);
    arbolB.insertar_clave(47);'''
    
    '''while(True):
        valor: int = int(input("Ingrese un valor: "));

        if valor == -1:
            generatedReport(arbolB.imprimir_usuario());
            continue;
            
        if valor == -2:
            break;
            

        arbolB.insertar_valor(valor);'''
    
    lista_adyacencia: ListaAdyacencia = ListaAdyacencia();
    
    lista_adyacencia.insertar(Vertice(1), Vertice(2));
    lista_adyacencia.insertar(Vertice(1), Vertice(3));
    lista_adyacencia.insertar(Vertice(1), Vertice(4));
    lista_adyacencia.insertar(Vertice(2), Vertice(1));
    lista_adyacencia.insertar(Vertice(3), Vertice(2));
    lista_adyacencia.insertar(Vertice(4), Vertice(2));
    
    print(lista_adyacencia.imprimir());
    
if __name__ == '__main__':
    main();