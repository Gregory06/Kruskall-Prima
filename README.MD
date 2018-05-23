# Kruskall-Prima
Алгоритм Крускала реализован с помощью системы неперсекающихся множеств, 
алгоритм Прима реализован с помощью очереди с приоритетом (почти).
Граф передается в виде матрицы смежности через текстовый файл.
Формат входного файла:
n
a[0][0] ... a[0][n]
.
.
.
a[n][0] ... a[n][n]
Здесь n -- количество вершин графа, a[i][j] -- вес ребра между i-м, j-м ребром 
(матрица симметрическая, но ничкаких проверок на это нет -- {a[i][j]| j < i} не используются.

В качестве примера разобран граф из раздела 23.2-23.3 Кормена.
Его изображение можно найти в input_graph.png. Его представление в виде матрицы -- input_graph.txt.

!!!ACHTUNG!!! поменяйте путь к файлу.

PS: в Приме начался говнокод(9(((9.
PSS: может показаться, что он начался раньше((((999((9(.