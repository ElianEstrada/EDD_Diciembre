from src.DataStructs.Lista.Lista import Lista
from src.classes.Vertice import Vertice
from src.DataStructs.Lista.Nodo import Nodo

class ListaAdyacencia:
    
    def __init__(self):
        self.vertices: Lista[Vertice] = Lista();
        
    def insertar(self, origen: Vertice, destino: Vertice):
        
        resultado: Nodo[Vertice] = self.vertices.buscar(origen);
        
        if (resultado != None):
            resultado.valor.vecinos.insertar_final(destino);
        else:
            resultado = self.vertices.insertar_final(origen);
            
            resultado.valor.vecinos.insertar_final(destino);
            
    def imprimir(self) -> str:
        dot = 'digraph G {\n\tbgcolor="#1a1a1a"\n\tedge [arrowhead=none fontcolor=white color="#ff5400"];\n\t';
        dot += 'node [shape=circle fixedsize=shape width=0.5 fontsize=7 style=filled fillcolor="#313638" fontcolor=white ';
        dot += 'color=transparent];\n\t';
        
        aux: Nodo[Vertice] = self.vertices.cabeza;
        
        if aux != None:
            dot += str(aux.valor)
            
        dot += "}";
        
        return dot;