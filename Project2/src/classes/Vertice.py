from src.DataStructs.Lista.Lista import Lista

'''import src.DataStructs.Lista.Lista as Vecinos

lista = Vecinos.Lista'''

class Vertice:
    
    def __init__(self, valor: int):
        self.valor:int = valor;
        self.vecinos: Lista[Vertice] = Lista();
        self.peso: int = 0;
        
    def __str__(self) -> str:
        aux = self.vecinos.cabeza;
        
        dot: str = ""
        
        while aux != None:
            dot += f'edge[label={aux.valor.peso} fontsize=5];\n\t{self.valor} -> {aux.valor.valor};\n\t';
            
            aux = aux.sig;
            
        return dot;