# Sorting algorithms

1. **Bubble Sort:**
   - *Características Principales:*
     - Es uno de los algoritmos más sencillos.
     - Itera sobre la lista varias veces, comparando elementos adyacentes y realizando intercambios si es necesario.
     - Tiene una complejidad de tiempo cuadrática O(n^2) en el peor caso.
     - No es eficiente para listas grandes.

2. **Heap Sort:**
   - *Características Principales:*
     - Utiliza una estructura de datos llamada heap (montículo) para organizar los elementos.
     - Es más eficiente que Bubble Sort y tiene una complejidad de tiempo O(n log n).
     - No requiere memoria adicional ya que trabaja directamente sobre la lista existente.
     - Es inestable, lo que significa que no preserva el orden relativo de elementos iguales.

3. **Insertion Sort:**
   - *Características Principales:*
     - Es eficiente para listas pequeñas o parcialmente ordenadas.
     - Construye la lista ordenada uno a uno, insertando elementos en su posición correcta.
     - Tiene una complejidad de tiempo O(n^2) en el peor caso.
     - Puede ser más eficiente que otros algoritmos para listas pequeñas debido a su baja sobrecarga.

4. **Selection Sort:**
   - *Características Principales:*
     - Encuentra el elemento mínimo en cada iteración y lo intercambia con el primer elemento no ordenado.
     - Es simple pero ineficiente para listas grandes.
     - Tiene una complejidad de tiempo O(n^2) en el peor caso.
     - No es estable.

5. **Shell Sort:**
   - *Características Principales:*
     - Mejora el rendimiento de Insertion Sort al comparar y intercambiar elementos a intervalos más grandes.
     - Utiliza una secuencia de brechas para determinar los intervalos.
     - Tiene una complejidad de tiempo que depende de la secuencia de brechas utilizada, pero en el peor caso es O(n log n).

6. **Merge Sort:**
   - *Características Principales:*
     - Utiliza el enfoque de dividir y conquistar.
     - Divide la lista en mitades, ordena cada mitad y luego fusiona las mitades ordenadas.
     - Es eficiente y tiene una complejidad de tiempo O(n log n) en todos los casos.
     - Requiere memoria adicional para almacenar las mitades temporales.

7. **Quick Sort:**
   - *Características Principales:*
     - También utiliza el enfoque de dividir y conquistar.
     - Elige un elemento pivote, coloca los elementos menores a la izquierda y los mayores a la derecha.
     - Recursivamente ordena las dos sub-listas.
     - Tiene una complejidad de tiempo O(n log n) en el promedio, pero puede degradarse a O(n^2) en el peor caso (siempre que se elija un pivote desfavorable).
