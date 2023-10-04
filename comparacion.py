import matplotlib.pyplot as plt
import numpy as np

class GraficoLineal:

    def __init__(self, nombrearchivo, size_datos):
        self.vector = []
        self.nombrearchivo = nombrearchivo
        self.size_datos = size_datos

    def printmatrix(self):
        print("\nTiempos de ejecucion de los n datos: ", self.size_datos,end="\n\n")
        for i in range(len(self.vector)):
            for j in range(len(self.vector[0])):
                print(self.vector[i][j], end="  ")
            print()

    def leerdatosdelarchivo(self):
        with open(self.nombrearchivo+".txt", 'r') as archivo:
            for linea in archivo:
                elementos = [float(elemento) for elemento in linea.strip().split()]
                self.vector.append(elementos)

    def graficarplot(self):
        plt.figure(figsize=(12, 8))
        # Redondear los elementos del vector a 1 decimal
        vector_de_vectores = [[round(elemento, 3) for elemento in fila] for fila in self.vector]
        algoritmos = ['BubbleSort', 'HeapSort', 'InsertionSort', 'SelectionSort', 'ShellSort', 'MergeSort', 'QuickSort']
        marcadores = ['o']  # Marcadores diferentes para cada línea

        # Graficar el contenido
        for i, columna in enumerate(vector_de_vectores):
            plt.plot(self.size_datos, columna, label=algoritmos[i], marker=marcadores[0])

        # Configurar etiquetas y límites de los ejes
        plt.title('Comparación de tiempos de ejecución de algoritmos de ordenamiento')
        plt.xlabel('Tamaño del conjunto de datos')
        plt.ylabel('Tiempo de ejecución (ms)')
        plt.legend()
        plt.gca().set_facecolor('#222222')  # Color gris claro
        # plt.xticks(tamaños)

        plt.grid(True, linestyle='--', linewidth=0.5, alpha=0.7, color='gray')
        plt.savefig("graficas/"+self.nombrearchivo+".png")
        plt.show() # Mostrar la gráfica


grafico_pocos_datos = GraficoLineal("pocosdatos",[10, 100, 500, 1000, 2500, 5000])
grafico_pocos_datos.leerdatosdelarchivo()
grafico_pocos_datos.printmatrix()
grafico_pocos_datos.graficarplot()

grafico_muchos_datos = GraficoLineal("muchosdatos",[5000,10000,20000,50000,100000])
grafico_muchos_datos.leerdatosdelarchivo()
grafico_muchos_datos.printmatrix()
grafico_muchos_datos.graficarplot()
