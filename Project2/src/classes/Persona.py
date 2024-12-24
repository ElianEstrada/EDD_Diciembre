class Persona:
    
    # Constructor
    def __init__(self, nombre: str, edad: int):
        self.__nombre = nombre;
        self.__edad = edad;
        
    def get_name(self) -> str:
        return self.__nombre;
    
    def get_edad(self) -> int:
        return self.__edad;
        
    def __str__(self) -> str:
        return f"Nombre: {self.__nombre} Edad: {self.__edad}";