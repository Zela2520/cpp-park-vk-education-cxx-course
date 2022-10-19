<!-- [![Build Status](https://travis-ci.org/DaniilZelenko/Deep_CPP.svg?branch=matrix-hw)](https://travis-ci.org/DaniilZelenko/Deep_CPP) [![codecov](https://codecov.io/gh/DaniilZelenko/Deep_CPP/branch/matrix-hw/graph/badge.svg)](https://codecov.io/gh/DaniilZelenko/Deep_CPP) -->
Status of last deploy:<br>
<img src="https://github.com/Zela2520/Deep_CPP/workflows/matrix/badge.svg?branch=matrix-hw"><br>

Copyleft by MRGaTeAM 2022
# TechnoPark-DeepCee


### Домашнее задание №2

<h2>Описание ДЗ</h2>

<ol>
<h3>Необходимо разработать классы для работы с вещественными числами, векторами (строками размерности 1xN и столбцами размерности Nx1) и матрицами размерности MxN и реализовать операции над ними:</h3>


<li> обращение по индексам к элементам, извлечение диагонали, строки или столбца - 1б (после модификации исходной матрицы извлечённые элементы меняться не должны);</li>
<li> возможность создания матрицы из векторов или чисел, вектора из чисел - 1б;</li>
<li> поэлементное сложение/вычитание/умножение объектов одинаковой размерности - 1б;</li>
<li> умножение числа на матрицу, вектора на матрицу, матрицы на вектор и матрицы на матрицу - 1б;</li>
<li> суммирование/вычитание числа и вектора/матрицы, матрицы и вектора (с возможностью выбора - по строкам/по столбцам) - 1б;</li>
<li> получение транспонированной и обратной матриц - 1б;</li>
<li> подсчёт определителя матрицы - 1б.</li>
<ol>

Все основные операции должны быть реализованы через перегрузку операторов (операторы могут быть модифицирующие (+= и др.) и немодифицирующие (+ и др.)).

Доп. баллы:
- поддержка "слайсов, как в питоне" (на уровне методов, т.к. операторы такой синтаксис не поддерживают). В качестве примерного интерфейса можно опираться на то, как это сделано в " аналоге numpy на C++" https://github.com/dpilger26/NumCpp -1б;
- размерность матриц может задаваться с помощью шаблонных параметров -2б;

Для сдачи необходимо развернуть базовый CI, в котором будут осуществляться автоматическая сборка и тестирование проекта (хотя бы один интеграционный тест, показывающий работоспособность всех реализованных пунктов). Без покрытия тестами каждый пункт оценивается в 50% стоимости.
