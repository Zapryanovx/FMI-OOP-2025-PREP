## Задача 1:
Дефинирайте клас **ArithmeticProgression**, описващ аритметична прогресия. 
Реализирайте:
- Конструктор по подразбиране, инициализиращ прогресията като съвпадаща с множеството на естествените числа. 
- Конструктор, който приема първи член и разлика
- Оператор за събиране на прогресии. Под сума на прогресии разбираме прогресия, представляваща тяхната поелементна сума. Да се реализира и съответния оператор +=. 
- Оператор за изваждане на прогресии. Под разлика на прогресии разбираме прогресия, представляваща тяхната поелементна разлика. Да се реализира и съответния оператор -=. 
- Оператор за добавяне на цяло число без знак към прогресия, който създава прогресия, получена от началната с прескачане на дадения брой елементи от началото (т.е. да се измества началото).
- Оператор [], който връща на n-тия член
- Оператор (), който връща сумата на първите n члена в редицата 

## Задача 2:
Дефинирайте клас Матрица с произволни размери. Реализирайте:
- конструктор с параметри - 2 числа, които да определят размера на матрицата
- конструктор по подразбиране (по default размерите са 2х2)

Оператори:
- оператор+= - за събиране на матрици
- оператор+
- оператор-= - за изваждане на матрици
- оператор-
- оператор*= - за умножаване на матрици (стига да е възможно)
- оператор*
- оператор*= - за умножаване на матрица с число
- оператор*
- оператор== - 2 матрици са равни, ако всичките им елементи са равни
- оператор!=
- оператор[] - връща реда от матрицата на съответния индекс (за константен и неконстантен достъп)
- operator bool - връща false, ако матрицата е нулевата. В противен случай връща true. Помислете за оптимизация на този оператор. Hint: mutable

## Задача 3:
Да се дефинира клас Webpage, който има следните член-данни:
- адрес (пример: "https://github.com/KristianIvanov24")
- IP адрес (пример: 52.43.12.8)
Да се дефинират следните оператори:
- оператор<< и оператор >>

Да се дефинира клас Browser, който съдържа 
- отворени уеб страници (не повече от 30)
- брой отворени страници

Да се дефинират следните методи:
- методи за добавяне и премахване на страница
- оператор+= за отваряне на страница
- оператор-= за затваряне на страница (по индекс)
- принтиране на отворените страници

Да се напише главна програма, която реализира следните тестове:
- Създава три страници – две от тях са въведени от потребителя от клавиатурата, а трета, е дефинира в кода, като принтира информацията за всяка от тях.
- Добавя трите страници към Browser обект.
- Прави копие на този Browser обект и след това премахва втората страница.
