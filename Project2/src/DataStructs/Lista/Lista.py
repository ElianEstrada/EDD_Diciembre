from .Nodo import Nodo

class Lista:
    
    def __init__(self):
        self.cabeza: Nodo = None;
        
    def insertar_final(self, valor) -> Nodo:
        
        aux: Nodo = self.cabeza;
        
        if aux == None:
            aux = Nodo(valor);
            self.cabeza = aux
            return self.cabeza;
        
        while aux.sig != None:
            aux = aux.sig;
            
        aux.sig = Nodo(valor);
        
        return aux.sig;
        
    def buscar(self, valor: Nodo) -> Nodo:
        aux: Nodo = self.cabeza;
        
        if aux == None:
            return None;
        
        while aux != None:
            
            if aux.valor.valor == valor.valor:
                return aux
            
            aux = aux.sig;
            
        return None;