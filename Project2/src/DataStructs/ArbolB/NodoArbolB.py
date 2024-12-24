class NodoArbolB:
    #constructor
    def __init__(self, hoja: bool = False):
        self.hoja: bool = hoja;
        self.claves: list[int] = [] # orden del árbol - 1 (m - 1);
        self.hijos: list[NodoArbolB] = [] # orden del árbol (m)        
        
    def __str__(self):
        return f"Hoja: {self.hoja} - Claves: {self.claves} - Hijos: {self.hijos}";
        
