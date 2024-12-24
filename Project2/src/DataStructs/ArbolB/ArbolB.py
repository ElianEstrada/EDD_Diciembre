from .NodoArbolB import NodoArbolB

class ArbolB:
    #constructor
    def __init__(self, orden: int):
        self.raiz: NodoArbolB = NodoArbolB(True);
        self.orden: int = orden;
        
    def insertar_valor(self, valor: int):
            raiz: NodoArbolB = self.raiz;
            
            self.insertar_valor_no_completo(raiz, valor);
            if len(raiz.claves) > self.orden - 1:
                nodo: NodoArbolB = NodoArbolB();
                self.raiz = nodo;
                nodo.hijos.insert(0, raiz);
                self.dividir_pagina(nodo, 0);
            
    def insertar_valor_no_completo(self, raiz: NodoArbolB, valor: int):
        posicion: int = len(raiz.claves) - 1;
        
        if (raiz.hoja):
            #[5, 6];
            raiz.claves.append(None);
            #[5, 6, None];
            
            while posicion >= 0 and valor < raiz.claves[posicion]:
                raiz.claves[posicion + 1] = raiz.claves[posicion];
                #[5, 5, 6];
                posicion -= 1;
            raiz.claves[posicion + 1] = valor; #[4, 5, 6];
                
        else:
            
            while posicion >= 0 and valor < raiz.claves[posicion]:
                posicion -= 1;
                
            posicion += 1;
            
            self.insertar_valor_no_completo(raiz.hijos[posicion], valor);
            if len(raiz.hijos[posicion].claves) > self.orden - 1:
                self.dividir_pagina(raiz, posicion);
    
    def dividir_pagina(self, raiz: NodoArbolB, posicion: int):
        posicion_media: int = int((self.orden - 1) / 2);
        
        hijo: NodoArbolB = raiz.hijos[posicion];
        nodo: NodoArbolB = NodoArbolB(hijo.hoja);
        
        raiz.hijos.insert(posicion + 1, nodo);
        
        raiz.claves.insert(posicion, hijo.claves[posicion_media]);
        
        nodo.claves = hijo.claves[posicion_media + 1:posicion_media * 2 + 1];
        hijo.claves = hijo.claves[0:posicion_media];
        
        if not hijo.hoja:
            nodo.hijos = hijo.hijos[posicion_media + 1:posicion_media * 2 + 2];
            hijo.hijos = hijo.hijos[0:posicion_media + 1];
            
    def imprimir_usuario(self) -> str:
        
        dot: str = 'digraph G {\n\tbgcolor="#1A1A1A";\n\t';
        dot += "fontcolor=white;\n\tnodesep=0.5;\n\tsplines=false\n\t";
        dot += 'node [shape=record width=1.2 style=filled fillcolor="#313638"';
        dot += "fontcolor=white color=transparent];\n\t";
        dot += 'edge [fontcolor=white color="#0070C9"];\n\t';
        
        dot += self.imprimir(self.raiz);
        
        dot += "\n}";
        
        return dot;
            
    def imprimir(self, nodo: NodoArbolB, id: list[int] = [0]) -> str:
        raiz:NodoArbolB = nodo;
        
        arbol = f'n{id[0]}[label="';
        contador: int = 0;
        for item in raiz.claves:
            if (contador == len(raiz.claves) - 1):
                arbol += f"<f{contador}>|{item}|<f{contador + 1}>";
                break;
            arbol += f"<f{contador}>|{item}|";
            
            contador += 1;
        
        arbol += "\"];\n\t";
        
        contador: int = 0;
        id_padre = id[0];
        for item in raiz.hijos:
            '''if contador == len(raiz.hijos) - 1:
                arbol += f'n{id_padre}:f{contador} -> n{id[0] + 1};\n\t';
            else: '''
            
            arbol += f'n{id_padre}:f{contador} -> n{id[0] + 1};\n\t';
            
            id[0] += 1;
            arbol += self.imprimir(item, id);
            
            contador += 1;
            
        return arbol;
        
    def __str__(self):
        return f"{self.root}";